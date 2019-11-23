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
        proc = subprocess.run(['bash check_verified.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE )
        proc_result = proc.stdout.decode("UTF-8")[:-1]
        mark = ':heavy_check_mark:' if proc_result == "1" else ':x:'
        f = f.replace('_', '\_')
        print('*', mark, f)
    print()
        
def main():
        
    desc_1 = '''\
# tsutaj の競技プログラミング用 C++ ライブラリ置き場

[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* 自己責任で使ってね
* CI は試験運用中です

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
