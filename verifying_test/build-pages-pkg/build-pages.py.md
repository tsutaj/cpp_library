---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: py
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://github.com/tsutaj/cpp_library)',
    - https://travis-ci.com/tsutaj/cpp_library.svg?branch=master)](https://travis-ci.com/tsutaj/cpp_library)\n\n*
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.6/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# -*- coding: utf-8 -*-\nimport sys, os, glob, re, urllib, shutil, markdown\n\
    import collections\n\nclass FileParser:\n    # \u30D5\u30A1\u30A4\u30EB\u30D1\u30B9\
    \u3092\u3082\u3089\u3063\u3066\u3001\u884C\u3054\u3068\u306B\u5206\u3051\u308B\
    \n    def __init__(self, file_path):\n        if not os.path.exists(file_path):\n\
    \            raise FileNotFoundError('{} does not exist'.format(file_path))\n\
    \        with open(file_path) as f:\n            self.lines = [line.strip() for\
    \ line in f.readlines()]\n            \n    # \u30BF\u30B0\u3092\u3082\u3089\u3063\
    \u3066\u3001\u30B3\u30F3\u30C6\u30F3\u30C4\u306E\u914D\u5217\u3092\u51FA\u3059\
    \n    def get_contents_by_tag(self, tag_name, l_pat='', r_pat=''):\n        tag_name\
    \ = re.escape(tag_name)\n        l_pat, r_pat = re.escape(l_pat), re.escape(r_pat)\n\
    \n        reg1, reg2 = r'^.*' + tag_name, r'^.*' + tag_name\n        if l_pat\
    \ != '':\n            reg1 += r'.*' + l_pat\n            reg2 += r'.*' + l_pat\n\
    \        reg1 += r'.*'\n        reg2 += r'(.*)'\n        if r_pat != '':\n   \
    \         reg1 += r_pat + r'.*'\n            reg2 += r_pat + r'.*'\n        reg1\
    \ += r'$'\n        reg2 += r'$'\n\n        matches = [line for line in self.lines\
    \ if re.match(reg1, line)]\n        results = [re.sub(reg2, r'\\1', line).strip()\
    \ for line in matches]\n        return results\n\n    def get_implicit_dependencies(self):\n\
    \        reg1 = r'^#include[ ]*\".*\".*$'\n        matches = [line for line in\
    \ self.lines if re.match(reg1, line)]\n        reg2 = r'^#include[ ]*\"(.*)\"\
    .*$'\n        results = [re.sub(reg2, r'\\1', line).strip() for line in matches]\n\
    \        return results\n        \n# \u73FE\u72B6\u306F C++ \u306E\u307F\u306E\
    \u30B5\u30DD\u30FC\u30C8\u3092\u8003\u3048\u308B\nclass CppFile:        \n   \
    \ def __init__(self, file_path, source_path):\n        self.file_path = os.path.normpath(file_path)\n\
    \        self.source_path = source_path\n        self.parser = FileParser(file_path)\n\
    \n        # file \u6307\u5B9A\u304C\u7A7A\u306A\u3089\u3001\u30D5\u30A1\u30A4\u30EB\
    \u30D1\u30B9\u3092\u30BF\u30A4\u30C8\u30EB\u306B\u3059\u308B\n        self.title\
    \ = self.parser.get_contents_by_tag(r'@file')\n        if self.title == []:\n\
    \            self.title = self.file_path\n        else:\n            # @title\
    \ \u304C\u8907\u6570\u3042\u308B\u306A\u3089\u6700\u5F8C\u3092\u63A1\u7528\uFF1F\
    \uFF1F\n            self.title = self.title[-1]\n\n        self.brief = self.parser.get_contents_by_tag(r'@brief')\n\
    \        self.brief.extend(self.parser.get_contents_by_tag(r'#define DESCRIPTION',\
    \ r'\"', r'\"'))\n\n        # category \u6307\u5B9A\u304C\u7A7A\u306A\u3089\u3001\
    \u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u540D\u3092\u30AB\u30C6\u30B4\u30EA\u306B\
    \u3059\u308B\n        self.category = self.parser.get_contents_by_tag(r'@category')\n\
    \        self.category.extend(self.parser.get_contents_by_tag(r'#define CATEGORY',\
    \ r'\"', r'\"'))\n        if self.category == []:\n            self.category =\
    \ os.path.dirname(self.file_path)\n        else:\n            self.category =\
    \ self.category[-1]\n        \n        self.see = self.parser.get_contents_by_tag(r'@see')\n\
    \        self.see.extend(self.parser.get_contents_by_tag(r'#define PROBLEM', r'\"\
    ', r'\"'))\n                          \n        self.docs = self.parser.get_contents_by_tag(r'@docs')\n\
    \        self.docs.extend(self.parser.get_contents_by_tag(r'#define DOCS', r'\"\
    ', r'\"'))\n        \n        self.depends = self.parser.get_contents_by_tag(r'@depends')\n\
    \        self.depends.extend(self.parser.get_implicit_dependencies())\n      \
    \  self.depends.extend(self.parser.get_contents_by_tag(r'#define REQUIRES', r'\"\
    ', r'\"'))\n        self.depends = self.to_source_relpath(self.depends)\n    \
    \    \n        self.required = []\n        self.is_verified = self.get_verification_status()\n\
    \n    def get_verification_status(self):\n        return False # [TODO]\n    \
    \    \n    def to_source_relpath(self, item_list):\n        result, file_dir =\
    \ [], os.path.dirname(self.file_path)\n        for item in item_list:\n      \
    \      relpath_from_source = os.path.join(file_dir, item)\n            result.append(os.path.normpath(relpath_from_source))\n\
    \        return result\n\n    def set_required(self, required_list):\n       \
    \ self.required = required_list\n\nclass MarkdownPage:\n    # requires: self.cpp_source_path,\
    \ self.md_destination_path, self.destination\n    def get_mark(self, cond):\n\
    \        if cond:\n            return ':heavy_check_mark:'\n        else:\n  \
    \          return ':warning:'\n\n    def get_destination(self, file_path, file_type=''):\n\
    \        dst_file_dir, file_name = os.path.split(file_path)\n        dst_file_dir\
    \ = os.path.relpath(dst_file_dir, self.cpp_source_path)\n        md_file_dir =\
    \ os.path.normpath(os.path.join(self.md_destination_path, file_type, dst_file_dir))\n\
    \        return os.path.join(md_file_dir, file_name)\n\n    def get_link(self,\
    \ link_href):\n        return os.path.normpath(os.path.relpath(link_href, os.path.dirname(self.destination)))\
    \ + '.html'\n\n    def make_directory(self):\n        dir_name, file_name = os.path.split(self.destination)\n\
    \        os.makedirs(dir_name, exist_ok=True)\n\n    def include_js(self, file_object,\
    \ js_file_name):\n        js_file_name = os.path.relpath(js_file_name, os.path.dirname(self.destination))\n\
    \        html = '<script type=\"text/javascript\" src=\"{}\"></script>\\n'.format(js_file_name)\n\
    \        file_object.write(html)\n        \n    def include_css(self, file_object,\
    \ css_file_name):\n        css_file_name = os.path.relpath(css_file_name, os.path.dirname(self.destination))\n\
    \        html = '<link rel=\"stylesheet\" href=\"{}\" />\\n'.format(css_file_name)\n\
    \        file_object.write(html)\n\n    def convert_to_html(self):\n        md_destination\
    \ = self.destination + '.md'\n        html_destination = self.destination + '.html'\n\
    \        data = markdown.markdownFromFile(input=md_destination,\n            \
    \                             output=html_destination,\n                     \
    \                    encoding=\"utf-8\",\n                                   \
    \      extensions=['fenced_code', 'tables'])\n        \nclass MarkdownArticle(MarkdownPage):\n\
    \    def __init__(self, file_class, file_type, cpp_source_path, md_destination_path):\n\
    \        self.file_class = file_class\n        self.md_destination_path = md_destination_path\n\
    \        self.cpp_source_path = cpp_source_path\n        self.destination = self.get_destination(self.file_class.file_path,\
    \ file_type)\n        self.mark = self.get_mark(self.file_class.is_verified)\n\
    \            \n    # include (mathjax, js, css)\n    def write_header(self, file_object):\n\
    \        with open('./assets/site-header.txt') as f:\n            file_object.write(f.read())\n\
    \        self.include_js(file_object, os.path.join(self.md_destination_path, './assets/js/balloons.js'))\n\
    \        self.include_js(file_object, os.path.join(self.md_destination_path, './assets/js/copy-button.js'))\n\
    \        self.include_css(file_object, os.path.join(self.md_destination_path,\
    \ './assets/css/copy-button.css'))\n        file_object.write('\\n\\n')\n    \
    \        \n    def write_title(self, file_object, category, categorize):\n   \
    \     file_object.write('# {} {}\\n'.format(self.mark, self.file_class.title))\n\
    \        if categorize: file_object.write('* category: {}\\n'.format(category))\n\
    \        file_object.write('\\n\\n')\n        \n    def write_contents(self, file_object,\
    \ path_to_title, path_to_verification):\n        back_to_top_link = os.path.relpath(os.path.join(self.md_destination_path,\
    \ 'index.html'), os.path.dirname(self.destination))\n\n        file_object.write('[Back\
    \ to top page]({})\\n\\n'.format(back_to_top_link))\n\n        # brief, see, docs\n\
    \        for brief in self.file_class.brief:\n            file_object.write('*\
    \ {}\\n'.format(brief))\n        for see in self.file_class.see:\n           \
    \ file_object.write('* see: [{}]({})\\n'.format(see, see))\n        for docs in\
    \ self.file_class.docs:\n            docs = os.path.join(os.path.dirname(self.file_class.file_path),\
    \ docs)\n            with open(docs) as f:\n                file_object.write(f.read())\n\
    \        file_object.write('\\n\\n')\n\n        # cpp => cpp\n        self.file_class.depends\
    \ = sorted(list(set(self.file_class.depends)))\n        if self.file_class.depends\
    \ != []:\n            file_object.write('## Dependencies\\n')\n            for\
    \ depends in self.file_class.depends:\n                mark = self.get_mark(path_to_verification[depends])\n\
    \                title = path_to_title[depends]\n                link = self.get_link(self.get_destination(depends,\
    \ 'library'))\n                file_object.write('* {} [{}]({})\\n'.format(mark,\
    \ title, link))\n            file_object.write('\\n\\n')\n                \n \
    \       # cpp <= cpp\n        required_file_list = [f for f in self.file_class.required\
    \ if not re.match(r'^.*\\.test\\.(cpp|hpp|cc)$', f)]\n        required_file_list\
    \ = sorted(list(set(required_file_list)))\n        if required_file_list != []:\n\
    \            file_object.write('## Required\\n')\n            for required in\
    \ required_file_list:\n                mark = self.get_mark(path_to_verification[required])\n\
    \                title = path_to_title[required]\n                file_type =\
    \ 'verify' if re.match(r'^.*\\.test\\.(cpp|hpp|cc)$', required) else 'library'\n\
    \                link = self.get_link(self.get_destination(required, file_type))\n\
    \                file_object.write('* {} [{}]({})\\n'.format(mark, title, link))\n\
    \            file_object.write('\\n\\n')\n                \n        # cpp => test.cpp\n\
    \        verified_file_list = [f for f in self.file_class.required if re.match(r'^.*\\\
    .test\\.(cpp|hpp|cc)$', f)]\n        verified_file_list = sorted(list(set(verified_file_list)))\n\
    \        if verified_file_list != []:\n            file_object.write('## Verified\\\
    n')\n            for verified in verified_file_list:\n                mark = self.get_mark(path_to_verification[verified])\n\
    \                title = path_to_title[verified]\n                link = self.get_link(self.get_destination(verified,\
    \ 'verify'))\n                file_object.write('* {} [{}]({})\\n'.format(mark,\
    \ title, link))\n            file_object.write('\\n\\n')\n\n        # source code\n\
    \        file_object.write('## Code\\n')\n        file_object.write('```cpp\\\
    n')\n        with open(self.file_class.file_path) as f:\n            file_object.write(f.read())\n\
    \        file_object.write('\\n```\\n\\n')\n\n        # back to top\n        file_object.write('[Back\
    \ to top page]({})\\n\\n'.format(back_to_top_link))\n        \n    def build(self,\
    \ path_to_title, path_to_verification, category, categorize):\n        self.make_directory()\n\
    \        with open(self.destination + '.md', mode=\"w\") as file_object:\n   \
    \         self.write_header(file_object)\n            self.write_title(file_object,\
    \ category, categorize)\n            self.write_contents(file_object, path_to_title,\
    \ path_to_verification)\n\nclass MarkdownTopPage(MarkdownPage):\n    def __init__(self,\
    \ cpp_source_path, md_destination_path, config):\n        self.cpp_source_path\
    \ = cpp_source_path\n        self.md_destination_path = md_destination_path\n\
    \        self.destination = os.path.join(md_destination_path, 'index')\n     \
    \   self.config = config\n\n    def write_header(self, file_object):\n       \
    \ with open('./assets/site-header.txt') as f:\n            file_object.write(f.read())\n\
    \        self.include_js(file_object, os.path.join(self.md_destination_path, './assets/js/balloons.js'))\n\
    \        self.include_js(file_object, os.path.join(self.md_destination_path, './assets/js/copy-button.js'))\n\
    \        self.include_css(file_object, os.path.join(self.md_destination_path,\
    \ './assets/css/copy-button.css'))\n        file_object.write('\\n\\n')      \
    \  \n        \n    def write_title(self, file_object):\n        title = self.config.setdefault('title',\
    \ 'C++ Competitive Programming Library')\n        file_object.write('# {}\\n\\\
    n'.format(title))\n        description = self.config.setdefault('description',\
    \ '')\n        if description != '': file_object.write('{}\\n\\n'.format(description))\n\
    \        toc = self.config.setdefault('toc', False)\n        if toc:\n       \
    \     file_object.write('* this unordered seed list will be replaced by toc as\
    \ unordered list\\n')\n            file_object.write('{:toc}\\n\\n')\n       \
    \ \n    def write_contents(self, file_object,\n                       verify_files,\
    \ library_files,\n                       verify_category_to_path,\n          \
    \             library_category_to_path,\n                       path_to_title,\
    \ path_to_verification,\n                       categorize_verify, categorize_library):\n\
    \        if categorize_library:\n            if library_files != {}:\n       \
    \         file_object.write('## Library Files\\n')\n                for category,\
    \ library_list in library_category_to_path.items():\n                    file_object.write('###\
    \ {}\\n'.format(category))\n                    for library_file in library_list:\n\
    \                        mark = self.get_mark(path_to_verification[library_file])\n\
    \                        title = path_to_title[library_file]\n               \
    \         link = self.get_link(self.get_destination(library_file, 'library'))\n\
    \                        file_object.write('* {} [{}]({})\\n'.format(mark, title,\
    \ link))\n                    file_object.write('\\n\\n')\n        else:\n   \
    \         if library_files != {}:\n                file_object.write('## Library\
    \ Files\\n')\n                for library_file in library_files.keys():\n    \
    \                mark = self.get_mark(path_to_verification[library_file])\n  \
    \                  title = path_to_title[library_file]\n                    link\
    \ = self.get_link(self.get_destination(library_file, 'library'))\n           \
    \         file_object.write('* {} [{}]({})\\n'.format(mark, title, link))\n  \
    \              file_object.write('\\n\\n')\n\n        if categorize_verify:\n\
    \            if verify_files != {}:\n                file_object.write('## Verify\
    \ Files\\n')\n                for category, verify_list in verify_category_to_path.items():\n\
    \                    file_object.write('### {}\\n'.format(category))\n       \
    \             for verify_file in verify_list:\n                        mark =\
    \ self.get_mark(path_to_verification[verify_file])\n                        title\
    \ = path_to_title[verify_file]\n                        link = self.get_link(self.get_destination(verify_file,\
    \ 'verify'))\n                        file_object.write('* {} [{}]({})\\n'.format(mark,\
    \ title, link))\n                    file_object.write('\\n\\n')\n        else:\n\
    \            if verify_files != {}:\n                file_object.write('## Verify\
    \ Files\\n')\n                for verify_file in verify_files.keys():\n      \
    \              mark = self.get_mark(path_to_verification[verify_file])\n     \
    \               title = path_to_title[verify_file]\n                    link =\
    \ self.get_link(self.get_destination(verify_file, 'verify'))\n               \
    \     file_object.write('* {} [{}]({})\\n'.format(mark, title, link))\n      \
    \          file_object.write('\\n\\n')\n                \n    def build(self,\
    \ verify_files, library_files,\n              verify_category_to_path,\n     \
    \         library_category_to_path,\n              path_to_title, path_to_verification,\n\
    \              categorize_verify, categorize_library):\n        self.make_directory()\n\
    \        with open(self.destination + '.md', mode=\"w\") as file_object:\n   \
    \         self.write_header(file_object)\n            self.write_title(file_object)\n\
    \            self.write_contents(file_object,\n                              \
    \  verify_files, library_files,\n                                verify_category_to_path,\n\
    \                                library_category_to_path,\n                 \
    \               path_to_title, path_to_verification,\n                       \
    \         categorize_verify, categorize_library)\n            \nclass PagesBuilder:\n\
    \    def __init__(self, cpp_source_path, md_destination_path='./md-output', config={}):\n\
    \        self.verify_files = self.get_files(cpp_source_path, r'^.*\\.test\\.(cpp|hpp|cc)$')\n\
    \        self.library_files = self.get_files(cpp_source_path, r'^.*\\.(cpp|hpp|cc)$',\
    \ self.verify_files)\n        self.title_to_path = self.map_title2path()\n   \
    \     self.path_to_title = self.map_path2title()\n        self.verify_category_to_path,\
    \ self.library_category_to_path = self.map_category2path()\n        self.config\
    \ = config\n        self.get_required()\n        self.path_to_verification = self.map_path2verification()\n\
    \        self.build_verify_files(cpp_source_path, md_destination_path)\n     \
    \   self.build_library_files(cpp_source_path, md_destination_path)\n        self.build_top_page(cpp_source_path,\
    \ md_destination_path)\n        self.build_assets(md_destination_path)\n\n   \
    \ # ignore \u304C\u4ED8\u3044\u3066\u3044\u308B\u304B\uFF1F\n    def is_ignored(self,\
    \ file_path):\n        parser = FileParser(file_path)\n        ignore = []\n \
    \       ignore.extend(parser.get_contents_by_tag(r'@ignore'))\n        ignore.extend(parser.get_contents_by_tag(r'#define\
    \ IGNORE'))\n        return ignore != []\n\n    def get_files(self, source_path,\
    \ extension, ignored_files={}):\n        path = source_path + r'/**/*'\n     \
    \   match_result = [p for p in glob.glob(path, recursive=True) if re.search(extension,\
    \ p)]\n        files = {}\n        for matched_file in match_result:\n       \
    \     if not self.is_ignored(matched_file) and matched_file not in ignored_files:\n\
    \                matched_file = os.path.normpath(matched_file)\n             \
    \   files[matched_file] = CppFile(matched_file, source_path)\n        files =\
    \ collections.OrderedDict(sorted(files.items(), key=lambda x: x[0]))\n       \
    \ return files\n\n    # title \u306E\u91CD\u8907\u304C\u3042\u3063\u305F\u3089\
    \u30CA\u30F3\u30D0\u30EA\u30F3\u30B0\u4ED8\u4E0E\n    def map_title2path(self):\n\
    \        title_cnt, title_num, result = {}, {}, {}\n        for cpp_class in dict(**self.library_files,\
    \ **self.verify_files).values():\n            title_cnt.setdefault(cpp_class.title,\
    \ 0)\n            title_cnt[cpp_class.title] += 1\n\n        for cpp_class in\
    \ dict(**self.library_files, **self.verify_files).values():\n            title\
    \ = cpp_class.title\n            if title_cnt[title] >= 2:\n                title_num.setdefault(title,\
    \ 0);\n                title_num[title] += 1\n                title += '{:02}'.format(title_num[title])\n\
    \            result[title] = cpp_class.file_path\n        result = collections.OrderedDict(sorted(result.items(),\
    \ key=lambda x: x[0]))\n        return result    \n        \n    def map_path2title(self):\n\
    \        result = {}\n        for cpp_class in dict(**self.library_files, **self.verify_files).values():\n\
    \            result[cpp_class.file_path] = cpp_class.title\n        result = collections.OrderedDict(sorted(result.items(),\
    \ key=lambda x: x[0]))            \n        return result\n\n    def map_category2path(self):\n\
    \        verify_result, library_result = {}, {}\n        for cpp_class in self.verify_files.values():\n\
    \            verify_result.setdefault(cpp_class.category, [])\n            verify_result[cpp_class.category].append(cpp_class.file_path)\n\
    \        for file_path_list in verify_result.values():\n            file_path_list.sort()\n\
    \        verify_result = collections.OrderedDict(sorted(verify_result.items(),\
    \ key=lambda x: x[0]))\n            \n        for cpp_class in self.library_files.values():\n\
    \            library_result.setdefault(cpp_class.category, [])\n            library_result[cpp_class.category].append(cpp_class.file_path)\n\
    \        for file_path_list in library_result.values():\n            file_path_list.sort()\n\
    \        library_result = collections.OrderedDict(sorted(library_result.items(),\
    \ key=lambda x: x[0]))\n        return verify_result, library_result\n       \
    \     \n    def get_required(self):\n        map_required = {}\n        for cpp_class\
    \ in dict(**self.library_files, **self.verify_files).values():\n            for\
    \ depends in cpp_class.depends:\n                map_required.setdefault(depends,\
    \ [])\n                map_required[depends].append(cpp_class.file_path)\n\n \
    \       for cpp_file in self.library_files.keys():\n            map_required.setdefault(cpp_file,\
    \ [])\n            self.library_files[cpp_file].set_required(map_required[cpp_file])\n\
    \            \n        for cpp_file in self.verify_files.keys():\n           \
    \ map_required.setdefault(cpp_file, [])\n            self.verify_files[cpp_file].set_required(map_required[cpp_file])\n\
    \        \n    def map_path2verification(self):\n        result = {}\n       \
    \ # .test.cpp \u306E verify \u72B6\u6CC1\u78BA\u8A8D\n        for cpp_file, cpp_class\
    \ in self.verify_files.items():\n            result[cpp_file] = cpp_class.is_verified\n\
    \n        # .cpp \u306F\u3001\u305D\u308C\u3092\u5FC5\u8981\u3068\u3057\u3066\u3044\
    \u308B .test.cpp \u304C\u5C11\u306A\u304F\u3068\u3082 1 \u3064\u5B58\u5728\u3057\
    \n        # \u5168\u3066\u306E .test.cpp \u304C verify \u6E08\u307F\u306A\u3089\
    \ OK\n        for cpp_file, cpp_class in self.library_files.items():\n       \
    \     verify_file_cnt, cond = 0, True\n            for verify in cpp_class.required:\n\
    \                if re.match(r'^.*\\.test\\.(cpp|hpp|cc)$', verify):\n       \
    \             verify_file_cnt += 1\n                    cond &= result[verify]\n\
    \            result[cpp_file] = (verify_file_cnt > 0 and cond)\n        return\
    \ result\n            \n    def build_verify_files(self, cpp_source_path, md_destination_path):\n\
    \        for category, verify_path_list in self.verify_category_to_path.items():\n\
    \            for matched_file_path in verify_path_list:\n                verify_file_class\
    \ = self.verify_files[matched_file_path]\n                page = MarkdownArticle(verify_file_class,\
    \ 'verify', cpp_source_path, md_destination_path)\n                html_cond =\
    \ self.config.setdefault('html', False)\n                categorize_verify_cond\
    \ = self.config.setdefault('categorize_verify', False)\n                page.build(self.path_to_title,\
    \ self.path_to_verification, category, categorize_verify_cond)\n             \
    \   if html_cond: page.convert_to_html()\n\n    def build_library_files(self,\
    \ cpp_source_path, md_destination_path):\n        for category, library_path_list\
    \ in self.library_category_to_path.items():\n            for matched_file_path\
    \ in library_path_list:\n                library_file_class = self.library_files[matched_file_path]\n\
    \                page = MarkdownArticle(library_file_class, 'library', cpp_source_path,\
    \ md_destination_path)\n                html_cond = self.config.setdefault('html',\
    \ False)\n                categorize_library_cond = self.config.setdefault('categorize_library',\
    \ True)\n                page.build(self.path_to_title, self.path_to_verification,\
    \ category, categorize_library_cond)\n                if html_cond: page.convert_to_html()\n\
    \            \n    def build_top_page(self, cpp_source_path, md_destination_path):\n\
    \        page = MarkdownTopPage(cpp_source_path, md_destination_path, self.config)\n\
    \        html_cond = self.config.setdefault('html', False)\n        categorize_verify_cond\
    \ = self.config.setdefault('categorize_verify', False)\n        categorize_library_cond\
    \ = self.config.setdefault('categorize_library', True)\n        page.build(self.verify_files,\
    \ self.library_files,\n                   self.verify_category_to_path,\n    \
    \               self.library_category_to_path,\n                   self.path_to_title,\
    \ self.path_to_verification,\n                   categorize_verify_cond, categorize_library_cond)\n\
    \        if html_cond: page.convert_to_html()\n        \n    def build_assets(self,\
    \ md_destination_path):\n        destination = os.path.join(md_destination_path,\
    \ './assets/')\n        if os.path.exists(destination): shutil.rmtree(destination)\n\
    \        shutil.copytree('./assets/', destination)\n            \ndef main():\n\
    \    # \u5B9F\u884C\u30C6\u30B9\u30C8\n    config = {\n        'title': 'tsutaj\
    \ \u306E\u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\u30DF\u30F3\u30B0\u7528\u30E9\u30A4\
    \u30D6\u30E9\u30EA', # title of top page\n        'description': '[![Build Status](https://travis-ci.com/tsutaj/cpp_library.svg?branch=master)](https://travis-ci.com/tsutaj/cpp_library)\\\
    n\\n* [\u30EA\u30DD\u30B8\u30C8\u30EA\u3078\u306E\u30EA\u30F3\u30AF](https://github.com/tsutaj/cpp_library)',\
    \ # description of top page\n        'toc': True, # table of contents (default:\
    \ False)\n        'html': False, # generate HTML as well as Markdown (default:\
    \ False)\n        'categorize_library': True, # show library files with categorizing\
    \ (default: True)\n        'categorize_verify': False, # show verify files with\
    \ categorizing (default: False)\n    }\n    builder = PagesBuilder(cpp_source_path='../../',\
    \ config=config)\n    \nif __name__ == '__main__':\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: verifying_test/build-pages-pkg/build-pages.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verifying_test/build-pages-pkg/build-pages.py
layout: document
redirect_from:
- /library/verifying_test/build-pages-pkg/build-pages.py
- /library/verifying_test/build-pages-pkg/build-pages.py.html
title: verifying_test/build-pages-pkg/build-pages.py
---
