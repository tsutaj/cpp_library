# -*- coding: utf-8 -*-
import sys, os, glob, re, subprocess

import_static_js_text = '''\
<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
'''

def import_js_css(filename):
    dirpath = os.path.dirname(filename)
    result_text = ""

    copy_button_css_path = os.path.normpath(os.path.relpath("./css/copy-button.css", dirpath))
    result_text += '<link rel="stylesheet" href="{}" />\n'.format(copy_button_css_path)

    ballons_js_path = os.path.normpath(os.path.relpath("./js/balloons.js", dirpath))
    result_text += '<script type="text/javascript" src="{}"></script>\n'.format(ballons_js_path)

    copy_button_js_path = os.path.normpath(os.path.relpath("./js/copy-button.js", dirpath))
    result_text += '<script type="text/javascript" src="{}"></script>\n\n'.format(copy_button_js_path)
    
    return result_text

class Problem:
    def __init__(self, url, description, dependencies):
        self.url = url
        self.description = description
        self.dependencies = dependencies

class LibFile:
    def __init__(self, libfile_name, description, testfiles, is_verified):
        self.libfile_name = libfile_name
        self.description = description
        self.testfiles = testfiles
        self.is_verified = is_verified
        self.requires = get_requires(libfile_name)
        self.docs_text = get_docs(libfile_name)
        
class TestFile:
    def __init__(self, testfile_name, is_verified, problem):
        self.testfile_name = testfile_name
        self.is_verified = is_verified
        self.problem = problem
        self.docs_text = get_docs(testfile_name)

# Verify 済みかどうかのマーク
def get_mark(cond, strict = True):
    if cond:
        return ':heavy_check_mark:'
    elif strict:
        return ':x:'
    else:
        return ':warning:'

# Docs データを得る
def get_docs(file_path):
    proc = subprocess.run(['bash ./lib/check_docs.sh {}'.format(file_path)], shell = True, stdout = subprocess.PIPE )
    docs_path = os.path.join(os.path.dirname(file_path), proc.stdout.decode("UTF-8")[:-1])
    if (not os.path.exists(docs_path)) or (os.path.isdir(docs_path)): return ""

    docs_text = ""
    if len(docs_path) > 0:
        with open(docs_path) as f:
            lines = f.readlines()
            for line in lines: docs_text += line
    return docs_text

# Requires データを得る
def get_requires(file_path):
    proc = subprocess.run(['bash ./lib/check_requires_items.sh {}'.format(file_path)], shell = True, stdout = subprocess.PIPE )
    requires = proc.stdout.decode("UTF-8")[:-1].splitlines()
    requires = list(filter(lambda f: len(f) > 0, requires)) # avoid empty string
    return requires

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
lib_path = './library/'
test_path = './verified/'

def generate_lib_page(md_filename, lib_class):
    with open(md_filename, mode='w') as md_file:
        md_file.write(import_static_js_text)
        md_file.write(import_js_css(md_filename))
        md_file.write('\n\n')

        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path, lib_path), 'index.html'))
        md_file.write('[トップページに戻る]({})\n\n'.format(top_url))

        mark = get_mark(lib_class.is_verified, False)
        md_file.write('# {} {}\n\n'.format(mark, os.path.basename(lib_class.libfile_name).replace('_', '\_')))

        if len(lib_class.description) > 0: md_file.write('* {}\n\n'.format(lib_class.description))
        if len(lib_class.docs_text) > 0: md_file.write('{}\n\n'.format(lib_class.docs_text))

        if len(lib_class.requires) > 0:
            md_file.write('## Requires\n')
            for d in lib_class.requires:
                path = os.path.basename(d) + '.html'
                md_file.write('* [{}]({})\n'.format(os.path.basename(d).replace('_', '\_'), path))
            md_file.write('\n')
        
        if len(lib_class.testfiles) > 0:
            md_file.write('## Verify Files\n')
            for d in lib_class.testfiles:
                path = os.path.normpath(os.path.join(os.path.relpath(test_path, lib_path), d)) + '.html'
                md_file.write('* [{}]({})\n'.format(d.replace('_', '\_'), path))
            md_file.write('\n')

        md_file.write('## Code\n\n')
        md_file.write('```cpp\n')
        with open(lib_class.libfile_name) as lib_file:
            lines = lib_file.readlines()
            for line in lines: md_file.write(line)

        md_file.write('\n```\n\n')
        md_file.write('[トップページに戻る]({})\n'.format(top_url))
                
def generate_test_page(md_filename, testfile):
    with open(md_filename, mode='w') as md_file:
        md_file.write(import_static_js_text)
        md_file.write(import_js_css(md_filename))
        md_file.write('\n\n')
        
        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path, os.path.dirname(md_filename)), 'index.html'))
        md_file.write('[トップページに戻る]({})\n\n'.format(top_url))

        mark = get_mark(testfile.is_verified)
        md_file.write('# {} {}\n\n'.format(mark, testfile.testfile_name.replace('_', '\_')))

        if len(testfile.problem.url) > 0: md_file.write('* URL: [{}]({})\n'.format(testfile.problem.url, testfile.problem.url))
        if len(testfile.problem.description) > 0: md_file.write('* {}\n\n'.format(testfile.problem.description))

        if len(testfile.problem.dependencies) > 1:
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
        
        md_file.write('\n```\n\n')
        md_file.write('[トップページに戻る]({})\n'.format(top_url))
                
# Markdown 形式で出力 (アンダースコアはそのまま使うとあれなので置換する)
def convert_lib_to_md(dir_name, lib_classes):
    subprocess.run( 'mkdir -p {}'.format(lib_path), shell = True )
    
    print('##', dir_name)
    for c in lib_classes.values():
        md_filename = os.path.join(lib_path, os.path.basename(c.libfile_name)) + '.md'
        html_filename = os.path.join(lib_path, os.path.basename(c.libfile_name)) + '.html'
        generate_lib_page(md_filename, c)
        print('* {} [{}]({})'.format(get_mark(c.is_verified, False), os.path.basename(c.libfile_name).replace('_', '\_'), html_filename))
    print()
        
def convert_test_to_md(testfile):
    subprocess.run( 'mkdir -p {}'.format(test_path), shell = True )
    dirname = os.path.dirname(os.path.join(test_path, testfile.testfile_name))
    subprocess.run( 'mkdir -p {}'.format(dirname), shell = True )
    
    md_filename = os.path.normpath(os.path.join(test_path, testfile.testfile_name)) + '.md'
    html_filename = os.path.normpath(os.path.join(test_path, testfile.testfile_name)) + '.html'
    generate_test_page(md_filename, testfile)
    mark = get_mark(testfile.is_verified)
    print('* {} [{}]({})'.format(mark, testfile.testfile_name.replace('_', '\_'), html_filename))

def get_lib_class(dir_name, lib_file_list, lib_verify_files, lib_verified):
    lib_class = {}
    for f in lib_file_list:
        libfile_name = f

        proc = subprocess.run(['bash ./lib/check_description.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        description = proc.stdout.decode("UTF-8")[:-1]

        if os.path.basename(f) in lib_verify_files:
            testfiles = lib_verify_files[os.path.basename(f)]
            is_verified = lib_verified[os.path.basename(f)]
        else:
            testfiles = []
            is_verified = False
        lib_class[os.path.basename(libfile_name)] = LibFile(libfile_name, description, testfiles, is_verified)
    return lib_class
        
def get_test_class(dir_name, test_file_list):
    test_files, lib_verify_files, lib_verified = [], {}, {}
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
            lib_verify_files.setdefault(os.path.basename(d), []).append(f)
            lib_verified.setdefault(os.path.basename(d), is_verified)
            lib_verified[os.path.basename(d)] |= is_verified
            
    return test_files, lib_verify_files, lib_verified
    
def main():
    print(import_static_js_text)
    print(import_js_css('./index.html'))
    desc_0 = '''\
[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* [リポジトリへのリンク](https://github.com/Tsutajiro/cpp_library)
* tsutaj が使用している競技プログラミング用ライブラリです。自己責任で使ってね
* CI は試験運用中です

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
        test_classes, lib_verify_files, lib_verified = get_test_class(os.path.join(test_path, d), test_cpp_file_list)

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
        lib_classes = get_lib_class(os.path.join(test_path, d), cpp_file_list, lib_verify_files, lib_verified)
        convert_lib_to_md(d, lib_classes)

    desc_2 = '''\
# Verify ファイル一覧
'''
    print(desc_2)
    for t in test_classes:
        convert_test_to_md(t)
        
if __name__ == '__main__':
    main()
