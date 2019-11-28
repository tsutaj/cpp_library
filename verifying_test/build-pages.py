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
        self.required = []
        self.is_verified = False
        self.get_implicit_dependencies()
        
    def get_implicit_dependencies(self):
        # [TODO]
        return 0

    def inspect(self):
        print(self.brief)
        print(self.see)
        print(self.docs)
        print(self.depends)

class MarkdownPage:
    def __init__(self, file_class, file_type, cpp_folder_path, md_folder_path):
        self.file_class = file_class
        self.md_folder_path = md_folder_path
        self.cpp_folder_path = cpp_folder_path
        self.destination = self.get_destination(file_type, self.file_class.file_path)
        print(self.destination)
        
    def get_destination(self, file_type, file_path):
        cpp_file_dir, file_name = os.path.split(file_path)
        cpp_file_dir = os.path.relpath(cpp_file_dir, self.cpp_folder_path)
        file_name += '.html'
        print(self.md_folder_path, file_type, cpp_file_dir)
        md_file_dir = os.path.normpath(os.path.join(self.md_folder_path, file_type, cpp_file_dir))
        return os.path.join(md_file_dir, file_name)

    def make_directory(self):
        dir_name, file_name = os.path.split(self.destination)
        os.makedirs(dir_name, exist_ok=True)
    
    # include (mathjax, js, css)
    def write_header(self, file_object):
        with open('./assets/site-header.html') as f:
            file_object.write(f.read())
        file_object.write('\n\n')
        
    def write_title(self, file_object):
        # [TODO] is_verified
        file_object.write('# {}\n'.format(self.file_class.title))
        file_object.write('\n\n')
        
    def write_contents(self, file_object, path_to_title):
        # brief, see, docs
        for brief in self.file_class.brief:
            file_object.write('* {}\n'.format(brief))
        for see in self.file_class.see:
            file_object.write('* see: [{}]({})\n'.format(see, see))
        for docs in self.file_class.docs:
            with open(docs) as f:
                file_object.write(f.read())
        file_object.write('\n\n')

        # cpp => cpp
        depends_file_list = [f for f in self.file_class.required if f[-7:] != 'test.cpp']
        if depends_file_list != []:
            file_object.write('## Dependencies\n')
            for depends in depends_file_list:
                title = path_to_title(depends)
                link = self.get_destination(depends)
                file_object.write('* [{}]({})\n'.format(title, link))
            file_object.write('\n\n')
                
        # cpp <= cpp
        if self.file_class.required != []:
            file_object.write('## Required\n')
            for required in self.file_class.required:
                title = path_to_title(required)
                link = self.get_destination(required)
                file_object.write('* [{}]({})\n'.format(title, link))
            file_object.write('\n\n')
                
        # cpp => test.cpp
        verified_file_list = [f for f in self.file_class.required if f[-7:] == 'test.cpp']
        if verified_file_list != []:
            file_object.write('## Verified\n')
            for verified in verified_file_list:
                title = path_to_title(verified)
                link = self.get_destination('verify', verified)
                file_object.write('* [{}]({})\n'.format(title, link))
            file_object.write('\n\n')

        # source code
        file_object.write('## Code\n')
        file_object.write('```cpp\n')
        with open(self.file_class.file_path) as f:
            file_object.write(f.read())
        file_object.write('\n```\n')
        
    def build(self, path_to_title):
        self.make_directory()
        with open(self.destination, mode="w") as file_object:
            self.write_header(file_object)
            self.write_title(file_object)
            self.write_contents(file_object, path_to_title)
        
class PagesBuilder:
    # ignore が付いているか？
    def is_ignored(self, file_path):
        parser = FileParser(file_path)
        ignore = parser.get_contents_by_tag(r'@ignore')        
        return ignore != []

    def get_files(self, folder_path, extension, ignored_files={}):
        path = folder_path + r'/**/*' + extension
        match_result = glob.glob(path, recursive=True)
        files = {}
        for matched_file in match_result:
            if not self.is_ignored(matched_file) and matched_file not in ignored_files:
                files[matched_file] = CppFile(matched_file)
        return files

    # title の重複があったらナンバリング付与
    def map_title2path(self):
        title_cnt, title_num, result = {}, {}, {}
        for cpp_file in dict(**self.library_files, **self.verify_files).values():
            title_cnt.setdefault(cpp_file.title, 0)
            title_cnt[cpp_file.title] += 1

        for cpp_file in dict(**self.library_files, **self.verify_files).values():
            title = cpp_file.title
            if title_cnt[title] >= 2:
                title_num.setdefault(title, 0);
                title_num[title] += 1
                title += '{:02}'.format(title_num[title])
            result[title] = cpp_file.file_path
        return result    
        
    def map_path2title(self):
        result = {}
        for cpp_file in dict(**self.library_files, **self.verify_files).values():
            result[cpp_file.file_path] = cpp_file.title
        return result

    def get_requires(self):
        self.map_requires = {}
        for cpp_file in dict(**self.library_files, **self.verify_files).values():
            for depends in cpp_file.depends:
                map_requires.setdefault(depends, [])
                map_requires[depends].append(cpp_file.file_path)
        
    def get_verification_status(self):
        # [TODO]
        return 0
            
    def build_verify_files(self, cpp_folder_path, md_folder_path):
        for verify_file in self.verify_files.values():
            page = MarkdownPage(verify_file,'verify', cpp_folder_path, md_folder_path)
            page.build(self.path_to_title)

    def build_library_files(self, cpp_folder_path, md_folder_path):
        for library_file in self.library_files.values():
            page = MarkdownPage(library_file, 'library', cpp_folder_path, md_folder_path)
            page.build(self.path_to_title)
    
    def __init__(self, cpp_folder_path='../', md_folder_path='./md-output'):
        self.is_verified = {}
        self.verify_files = self.get_files(cpp_folder_path, r'.test.cpp')
        self.library_files = self.get_files(cpp_folder_path, r'.cpp', self.verify_files)
        self.title_to_path = self.map_title2path()
        self.path_to_title = self.map_path2title()
        self.get_requires()
        self.get_verification_status()
        self.build_verify_files(cpp_folder_path, md_folder_path)
        self.build_library_files(cpp_folder_path, md_folder_path)
        
def main():
    builder = PagesBuilder()
    
if __name__ == '__main__':
    main()
