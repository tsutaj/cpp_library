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

top_path = './'
lib_path = './lib/'
test_path = './verified/'

def generate_lib_page(md_filename, lib_filepath, lib_dependencies):
    with open(md_filename, mode='w') as md_file:
        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path, lib_path), 'index.html'))
        md_file.write('[トップページに戻る]({})\n\n'.format(top_url))

        md_file.write('# {}\n'.format(os.path.basename(lib_filepath).replace('_', '\_')))
        md_file.write('---\n\n')

        if len(lib_dependencies) > 0:
            md_file.write('## Verify Files\n')
            for d in lib_dependencies:
                path = os.path.normpath(os.path.join(os.path.relpath(test_path, lib_path), d))
                md_file.write('* [{}]({})\n'.format(os.path.basename(d).replace('_', '\_'), path))
            md_file.write('\n')

        md_file.write('## Code\n\n')
        md_file.write('```cpp\n')
        with open(lib_filepath) as lib_file:
            lines = lib_file.readlines()
            for line in lines: md_file.write(line)

        md_file.write('```\n\n')
        md_file.write('[トップページに戻る]({})\n'.format(top_url))

                
def generate_test_page(md_filename, testfile):
    with open(md_filename, mode='w') as md_file:
        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path, os.path.dirname(md_filename)), 'index.html'))
        md_file.write('[トップページに戻る]({})\n\n'.format(top_url))

        mark = ':heavy_check_mark:' if testfile.is_verified else ':x:'
        md_file.write('# {} {}\n'.format(mark, testfile.testfile_name.replace('_', '\_')))
        md_file.write('---\n\n')

        if len(testfile.problem.url) > 0: md_file.write('* URL: [{}]({})\n'.format(testfile.problem.url, testfile.problem.url))
        if len(testfile.problem.description) > 0: md_file.write('* {}\n\n'.format(testfile.problem.description))

        if len(testfile.problem.dependencies) > 0:
            md_file.write('## Dependencies\n')
            for d in testfile.problem.dependencies:
                if os.path.samefile(d, testfile.testfile_name): continue
                path = os.path.normpath(os.path.join(os.path.relpath(lib_path, os.path.dirname(md_filename)), os.path.basename(d))) + '.html'
                md_file.write('* [{}]({})\n'.format(os.path.basename(d).replace('_', '\_'), path))
            md_file.write('\n')

        md_file.write('## Code\n\n')
        md_file.write('```cpp\n')
        with open(testfile.testfile_name) as test_file:
            lines = test_file.readlines()
            for line in lines: md_file.write(line)
        
        md_file.write('```\n\n')
        md_file.write('[トップページに戻る]({})\n'.format(top_url))
                
# Markdown 形式で出力 (アンダースコアはそのまま使うとあれなので置換する)
def convert_lib_to_md(dir_name, lib_file_list, lib_dependencies):
    subprocess.run( 'mkdir -p {}'.format(lib_path), shell = True )
    
    print('##', dir_name)
    for f in lib_file_list:
        md_filename = os.path.join(lib_path, os.path.basename(f)) + '.md'
        html_filename = os.path.join(lib_path, os.path.basename(f)) + '.html'
        generate_lib_page(md_filename, f, lib_dependencies)
        print('* [{}]({})'.format(os.path.basename(f).replace('_', '\_'), html_filename))
    print()
        
def convert_test_to_md(testfile):
    subprocess.run( 'mkdir -p {}'.format(test_path), shell = True )
    dirname = os.path.dirname(os.path.join(test_path, testfile.testfile_name))
    subprocess.run( 'mkdir -p {}'.format(dirname), shell = True )
    
    md_filename = os.path.normpath(os.path.join(test_path, testfile.testfile_name)) + '.md'
    html_filename = os.path.normpath(os.path.join(test_path, testfile.testfile_name)) + '.html'
    generate_test_page(md_filename, testfile)
    mark = ':heavy_check_mark:' if testfile.is_verified else ':x:'
    print('* {} [{}]({})'.format(mark, testfile.testfile_name.replace('_', '\_'), html_filename))
        
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
        dependencies = proc.stdout.decode("UTF-8")[:-1].splitlines()
        
        problem = Problem(url, description, dependencies)
        test_files.append(TestFile(testfile_name, is_verified, problem))

        for d in dependencies:
            lib_dependencies.setdefault(os.path.basename(d), []).append(f)
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
        cpp_file_list = get_matched_file_list(os.path.join(lib_path, d), lib_cond)
        convert_lib_to_md(d, cpp_file_list, lib_dependencies)

    desc_2 = '''\
# Verify ファイル一覧
'''
    print(desc_2)
    for t in test_files:
        convert_test_to_md(t)
        
if __name__ == '__main__':
    main()
