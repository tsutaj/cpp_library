# -*- coding: utf-8 -*-
import sys, os, glob, re, subprocess

class Problem:
    def __init__(self, url, description, dependencies):
        self.url = url
        self.description = description
        self.dependencies = dependencies

class LibFile:
    def __init__(self, lib_filename, dependencies):
        self.lib_filename = lib_filename
        self.dependencies = dependencies
        self.is_verified = False
        self.testfiles = []

    def add_testfile(self, testfile):
        self.testfiles.append(testfile)
        self.is_verified |= testfile.is_verified
        
class TestFile:
    def __init__(self, testfile_name, is_verified, problem):
        self.testfile_name = testfile_name
        self.is_verified = is_verified
        self.problem = problem

# ディレクトリ一覧
def get_directory_list(path):
    files = os.listdir(path)
    return sorted([d for d in files if os.path.isdir(os.path.join(path, d))])

# 条件 cond にマッチするファイルが含まれているディレクトリ一覧
def get_matched_directory_list(path, cond, ignore_list):
    dir_list = get_directory_list(path)
    matched_dir_list = [d for d in dir_list if len(get_matched_file_list(os.path.join(path, d), cond)) > 0 and not d in ignore_list]
    return sorted(matched_dir_list)

# ディレクトリのパスを指定すると、ディレクトリ内にある .cpp ファイルを返す
# パスのまま返すため適宜整形する
def get_matched_file_list(path, cond):
    files_list = [f for f in glob.glob(path + '/**/*.cpp', recursive=True) if cond.match(f) != None]
    return sorted(files_list)

# Markdown 形式で出力 (アンダースコアはそのまま使うとあれなので置換する)
def convert_lib_to_md(dir_name, lib_file_list, lib_dependencies):
    print('##', dir_name)
    for f in lib_file_list:
        print('###', f.replace('_', '\_'))
        if f in lib_dependencies: print('    #### Dependencies')
        for d in lib_dependencies.setdefault(f, []):
            print('        *', d)
        print()

def convert_test_to_md(testfile):
    mark = ':heavy_check_mark:' if testfile.is_verified else ':x:'
    print('###', mark, testfile.testfile_name.replace('_', '\_'))
    if len(testfile.problem.url) > 0: print('* URL: [{}]({})'.format(testfile.problem.url, testfile.problem.url))
    if len(testfile.problem.description) > 0: print('*', testfile.problem.description)
    if len(testfile.problem.dependencies) > 0: print('    #### Dependencies')
    for d in testfile.problem.dependencies:
        print('        *', os.path.basename(d).replace('_', '\_'))

    print()
        
def get_test_dict(dir_name, test_file_list):
    test_files, lib_dependencies = [], {}
    for f in test_file_list:
        testfile_name = f
        
        proc = subprocess.run(['bash ./lib/check_verification.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1]
        is_verified = (proc_result == "1")

        proc = subprocess.run(['bash ./lib/check_url.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        url = proc.stdout.decode("UTF-8")[:-1]

        proc = subprocess.run(['bash ./lib/check_description.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        description = proc.stdout.decode("UTF-8")[:-1]

        proc = subprocess.run(['bash ./lib/check_dependencies.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        dependencies = [os.path.basename(d) for d in proc.stdout.decode("UTF-8")[:-1].splitlines()]
        
        problem = Problem(url, description, dependencies)
        test_files.append(TestFile(testfile_name, is_verified, problem))

        for d in dependencies:
            lib_dependencies.setdefault(d, []).append(f)
    return test_files, lib_dependencies
    
def main():
    desc_0 = '''\
<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>

[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* tsutaj が使用している競技プログラミング用ライブラリです。自己責任で使ってね
* CI は試験運用中です (そのうち HTML 生成機能をつける予定)

# 目次

* this unordered seed list will be replaced by toc as unordered list
{:toc}
'''
    print(desc_0)
    
    # パスに 'test.cpp' が付いているなら拾う
    test_path = './'
    test_cond = re.compile(r'^(?=.*test.cpp).*$')
    ignore_test_list = []

    test_dir_list = get_matched_directory_list(test_path, test_cond, ignore_test_list)
    for d in test_dir_list:
        test_cpp_file_list = get_matched_file_list(os.path.join(test_path, d), test_cond)
        # convert_test_to_md(d, test_cpp_file_list)
        test_files, lib_dependencies = get_test_dict(os.path.join(test_path, d), test_cpp_file_list)

    desc_1 = '''\
# ライブラリ一覧
'''    
    # パスに 'verify' が付いているファイルは拾わない
    # パスに 'test.cpp' が付いているファイルも拾わない
    lib_path = '../'
    lib_cond = re.compile(r'^(?!.*verify)(?!.*test.cpp).*$')
    ignore_lib_list = []
    
    print(desc_1)
    lib_dir_list = get_matched_directory_list(lib_path, lib_cond, ignore_lib_list)
    for d in lib_dir_list:
        cpp_file_list = [os.path.basename(f) for f in get_matched_file_list(os.path.join(lib_path, d), lib_cond)]
        convert_lib_to_md(d, cpp_file_list, lib_dependencies)

    desc_2 = '''\
# Verify ファイル一覧
'''
    print(desc_2)
    for t in test_files:
        convert_test_to_md(t)
        
if __name__ == '__main__':
    main()
