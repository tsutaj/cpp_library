# -*- coding: utf-8 -*-
import sys, os, glob, re, subprocess

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
def convert_lib_to_md(dir_name, lib_file_list):
    print('###', dir_name)
    for f in lib_file_list:
        f = f.replace('_', '\_')
        print('*', f)
    print()

def convert_test_to_md(dir_name, test_file_list):
    for f in test_file_list:
        proc = subprocess.run(['bash ./lib/check_verification.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1]
        mark = ':heavy_check_mark:' if proc_result == "1" else ':x:'
        f_ = f.replace('_', '\_')
        print('*', mark, f_)

        proc = subprocess.run(['bash ./lib/check_url.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1]
        if len(proc_result) > 0:
            print('    - URL:', proc_result)

        proc = subprocess.run(['bash ./lib/check_description.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1]
        if len(proc_result) > 0:
            print('        +', proc_result)

        proc = subprocess.run(['bash ./lib/check_dependencies.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1].splitlines()
        if len(proc_result) > 0:
            print('    - Dependencies')
            for d in proc_result:
                if os.path.samefile(f, d): continue
                print('        + {}'.format(os.path.normpath(d).replace('_', '\_')))
    print()
        
def main():
        
    desc_1 = '''\
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    tex2jax: {
      inlineMath: [['$','$'], ['\\(','\\)']],
      processEscapes: true
    },
    CommonHTML: { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em",
    TeX: {
      equationNumbers: { autoNumber: "AMS" },
    }
  });
</script>
<script async src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.6/MathJax.js?config=TeX-AMS_CHTML"></script>

# tsutaj の競技プログラミング用 C++ ライブラリ置き場

[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* 自己責任で使ってね
* CI は試験運用中です (そのうち HTML 生成機能をつける予定)

## ライブラリ一覧
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
        convert_lib_to_md(d, cpp_file_list)

    desc_2 = '''\
## Verify ファイル一覧

:heavy_check_mark: は Verify 正常終了、:x: は異常終了
'''
    # パスに 'test.cpp' が付いているなら拾う
    test_path = './'
    test_cond = re.compile(r'^(?=.*test.cpp).*$')
    ignore_test_list = []

    print(desc_2)
    test_dir_list = get_matched_directory_list(test_path, test_cond, ignore_test_list)
    for d in test_dir_list:
        test_cpp_file_list = get_matched_file_list(os.path.join(test_path, d), test_cond)
        
        convert_test_to_md(d, test_cpp_file_list)
    
if __name__ == '__main__':
    main()
