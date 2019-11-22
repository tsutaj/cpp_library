# -*- coding: utf-8 -*-
import sys, os, glob, re

# ディレクトリ一覧
def get_directory_list(path):
    files = os.listdir(path)
    return sorted([d for d in files if os.path.isdir(os.path.join(path, d))])

# .cpp ファイルが含まれているディレクトリ一覧
def get_cpp_contained_directory_list(path, ignore_list):
    dir_list = get_directory_list(path)
    cpp_dir_list = [d for d in dir_list if len(get_cpp_file_list(os.path.join(path, d))) > 0 and not d in ignore_list]
    return sorted(cpp_dir_list)

# ディレクトリのパスを指定すると、ディレクトリ内にある .cpp ファイルを返す
# 頭に 'verify' が付いているファイルは拾わない
def get_cpp_file_list(path):
    cond = re.compile(r'^(?!verify).*$')
    files_list = [os.path.basename(f) for f in glob.glob(path + '/*.cpp', recursive=True) if cond.match(f) != None]
    return sorted(files_list)

# Markdown 形式で出力 (アンダースコアはそのまま使うとあれなので置換する)
def convert_to_md(dir_name, cpp_file_list):
    print('###', dir_name)
    for f in cpp_file_list:
        f = f.replace('_', '\_')
        print('*', f)
    print()
    
def main():
    path = './'
    ignore_list = ['marathon']
    description = '''\
# tsutaj の競技プログラミング用 C++ ライブラリ置き場

* 自己責任で使ってね

## ここにあるものの一覧
'''

    print(description)
    dir_list = get_cpp_contained_directory_list(path, ignore_list)
    for d in dir_list:
        cpp_file_list = get_cpp_file_list(os.path.join(path, d))
        convert_to_md(d, cpp_file_list)

if __name__ == '__main__':
    main()
