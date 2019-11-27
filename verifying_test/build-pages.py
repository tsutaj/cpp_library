# -*- coding: utf-8 -*-
import sys, os, glob, re, urllib

class FileParser:
    # ファイルパスをもらって、行ごとに分ける
    def __init__(self, file_path):
        if not os.path.exists(file_path):
            raise FileNotFoundError('{} does not exist'.format(file_path))
        with open(file_path) as f:
            self.lines = [line.strip() for line in f.readlines()]
            
    # タグをもらって、コンテンツの配列を出す
    def get_contents_by_tag(self, tag_name):
        tag_name = re.escape(tag_name)
        reg1 = r'^.*' + tag_name + r'.*$'
        matches = [line for line in self.lines if re.match(reg1, line)]
        reg2 = r'^.*' + tag_name + r'(.*).*$'
        results = [re.sub(reg2, r'\1', line).strip() for line in matches]
        return results
        
# 現状は C++ のみのサポートを考える
class CppFile:        
    def __init__(self, file_path):
        self.file_path = file_path
        self.parser = FileParser(file_path)

        # file 指定が空なら、ファイルパスをタイトルにする
        self.title = self.parser.get_contents_by_tag(r'@file')
        if self.title == []:
            self.title = self.file_path
        else:
            # 複数あるなら最後を採用？？
            self.title = self.title[-1]

        self.brief = self.parser.get_contents_by_tag(r'@brief')
        self.see = self.parser.get_contents_by_tag(r'@see')
        self.docs = self.parser.get_contents_by_tag(r'@docs')
        self.depends = self.parser.get_contents_by_tag(r'@depends')

    def inspect(self):
        print(self.brief)
        print(self.see)
        print(self.docs)
        print(self.depends)

class PagesBuilder:
    def get_files(self, folder_path, extension):
        path = folder_path + r'/**/*' + extension
        results = glob.glob(path, recursive=True)
        return [CppFile(matched_file) for matched_file in results]

    # title の重複があったらナンバリング付与
    def map_title2path(self):
        title_cnt, title_num, result = {}, {}, {}
        for cpp_file in list(self.library_files + self.verify_files):
            title_cnt.setdefault(cpp_file.title, 0)
            title_cnt[cpp_file.title] += 1

        for cpp_file in list(self.library_files + self.verify_files):
            title = cpp_file.title
            if title_cnt[title] >= 2:
                title_num.setdefault(title, 0);
                title_num[title] += 1
                title += '{02:}'.format(title_num[title])
            result[title] = cpp_file.file_path
        return result        
        
    def map_path2title(self):
        result = {}
        for cpp_file in list(self.library_files + self.verify_files):
            result[cpp_file.file_path] = cpp_file.title
        return result

    def build_verify_files(self):
        raise NotImplementedError('verify のためのファイルをビルドする')

    def build_library_files(self):
        raise NotImplementedError('library のためのファイルをビルドする')
    
    def __init__(self, folder_path):
        self.library_files = self.get_files(folder_path, r'.cpp')
        self.verify_files = self.get_files(folder_path, r'.test.cpp')
        print([library_file.title for library_file in self.library_files])
        self.title_to_path = self.map_title2path()
        self.path_to_title = self.map_path2title()
        self.build_verify_files()
        self.build_library_files()
        
def main():
    s = input()
    builder = PagesBuilder(s)
    
if __name__ == '__main__':
    main()
