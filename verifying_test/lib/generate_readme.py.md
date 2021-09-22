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
    - https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js
    - https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML
    - https://github.com/Tsutajiro/cpp_library)
    - https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.7/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/python.py\"\
    , line 96, in bundle\n    raise NotImplementedError\nNotImplementedError\n"
  code: "# -*- coding: utf-8 -*-\nimport sys, os, glob, re, subprocess\n\nimport_static_js_text\
    \ = '''\\\n<!-- mathjax config similar to math.stackexchange -->\n<script type=\"\
    text/javascript\" async\n  src=\"https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML\"\
    >\n</script>\n<script type=\"text/x-mathjax-config\">\n  MathJax.Hub.Config({\n\
    \    TeX: { equationNumbers: { autoNumber: \"AMS\" }},\n    tex2jax: {\n     \
    \ inlineMath: [ ['$','$'] ],\n      processEscapes: true\n    },\n    \"HTML-CSS\"\
    : { matchFontHeight: false },\n    displayAlign: \"left\",\n    displayIndent:\
    \ \"2em\"\n  });\n</script>\n\n<script type=\"text/javascript\" src=\"https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js\"\
    ></script>\n'''\n\ndef import_js_css(filename):\n    dirpath = os.path.dirname(filename)\n\
    \    result_text = \"\"\n\n    copy_button_css_path = os.path.normpath(os.path.relpath(\"\
    ./css/copy-button.css\", dirpath))\n    result_text += '<link rel=\"stylesheet\"\
    \ href=\"{}\" />\\n'.format(copy_button_css_path)\n\n    ballons_js_path = os.path.normpath(os.path.relpath(\"\
    ./js/balloons.js\", dirpath))\n    result_text += '<script type=\"text/javascript\"\
    \ src=\"{}\"></script>\\n'.format(ballons_js_path)\n\n    copy_button_js_path\
    \ = os.path.normpath(os.path.relpath(\"./js/copy-button.js\", dirpath))\n    result_text\
    \ += '<script type=\"text/javascript\" src=\"{}\"></script>\\n\\n'.format(copy_button_js_path)\n\
    \    \n    return result_text\n\nclass Problem:\n    def __init__(self, url, description,\
    \ dependencies):\n        self.url = url\n        self.description = description\n\
    \        self.dependencies = dependencies\n\nclass LibFile:\n    def __init__(self,\
    \ libfile_name, description, testfiles, is_verified):\n        self.libfile_name\
    \ = libfile_name\n        self.description = description\n        self.testfiles\
    \ = testfiles\n        self.is_verified = is_verified\n        self.requires =\
    \ get_requires(libfile_name)\n        self.docs_text = get_docs(libfile_name)\n\
    \        \nclass TestFile:\n    def __init__(self, testfile_name, is_verified,\
    \ problem):\n        self.testfile_name = testfile_name\n        self.is_verified\
    \ = is_verified\n        self.problem = problem\n        self.docs_text = get_docs(testfile_name)\n\
    \n# Verify \u6E08\u307F\u304B\u3069\u3046\u304B\u306E\u30DE\u30FC\u30AF\ndef get_mark(cond,\
    \ strict = True):\n    if cond:\n        return ':heavy_check_mark:'\n    elif\
    \ strict:\n        return ':x:'\n    else:\n        return ':warning:'\n\n# Docs\
    \ \u30C7\u30FC\u30BF\u3092\u5F97\u308B\ndef get_docs(file_path):\n    proc = subprocess.run(['bash\
    \ ./lib/check_docs.sh {}'.format(file_path)], shell = True, stdout = subprocess.PIPE\
    \ )\n    docs_path = os.path.join(os.path.dirname(file_path), proc.stdout.decode(\"\
    UTF-8\")[:-1])\n    if (not os.path.exists(docs_path)) or (os.path.isdir(docs_path)):\
    \ return \"\"\n\n    docs_text = \"\"\n    if len(docs_path) > 0:\n        with\
    \ open(docs_path) as f:\n            lines = f.readlines()\n            for line\
    \ in lines: docs_text += line\n    return docs_text\n\n# Requires \u30C7\u30FC\
    \u30BF\u3092\u5F97\u308B\ndef get_requires(file_path):\n    proc = subprocess.run(['bash\
    \ ./lib/check_requires_items.sh {}'.format(file_path)], shell = True, stdout =\
    \ subprocess.PIPE )\n    requires = proc.stdout.decode(\"UTF-8\")[:-1].splitlines()\n\
    \    requires = list(filter(lambda f: len(f) > 0, requires)) # avoid empty string\n\
    \    return requires\n\n# \u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u4E00\u89A7\ndef\
    \ get_directory_list(path):\n    files = os.listdir(path)\n    return sorted([d\
    \ for d in files if os.path.isdir(os.path.join(path, d))])\n\n# \u6761\u4EF6 cond\
    \ \u306B\u30DE\u30C3\u30C1\u3059\u308B\u30D5\u30A1\u30A4\u30EB\u304C\u542B\u307E\
    \u308C\u3066\u3044\u308B\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u4E00\u89A7\ndef\
    \ get_matched_directory_list(path, cond, ignore_list):\n    dir_list = get_directory_list(path)\n\
    \    matched_dir_list = [d for d in dir_list if len(get_matched_file_list(os.path.join(path,\
    \ d), cond)) > 0 and not d in ignore_list]\n    return sorted(matched_dir_list)\n\
    \n# \u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u306E\u30D1\u30B9\u3092\u6307\u5B9A\u3059\
    \u308B\u3068\u3001\u30C7\u30A3\u30EC\u30AF\u30C8\u30EA\u5185\u306B\u3042\u308B\
    \ .cpp \u30D5\u30A1\u30A4\u30EB\u3092\u8FD4\u3059\n# \u30D1\u30B9\u306E\u307E\u307E\
    \u8FD4\u3059\u305F\u3081\u9069\u5B9C\u6574\u5F62\u3059\u308B\ndef get_matched_file_list(path,\
    \ cond):\n    files_list = [f for f in glob.glob(path + '/**/*.cpp', recursive=True)\
    \ if cond.match(f) != None]\n    return sorted(files_list)\n\ntop_path = './'\n\
    lib_path = './library/'\ntest_path = './verified/'\n\ndef generate_lib_page(md_filename,\
    \ lib_class):\n    with open(md_filename, mode='w') as md_file:\n        md_file.write(import_static_js_text)\n\
    \        md_file.write(import_js_css(md_filename))\n        md_file.write('\\\
    n\\n')\n\n        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path,\
    \ lib_path), 'index.html'))\n        md_file.write('[\u30C8\u30C3\u30D7\u30DA\u30FC\
    \u30B8\u306B\u623B\u308B]({})\\n\\n'.format(top_url))\n\n        mark = get_mark(lib_class.is_verified,\
    \ False)\n        md_file.write('# {} {}\\n\\n'.format(mark, os.path.basename(lib_class.libfile_name).replace('_',\
    \ '\\_')))\n\n        if len(lib_class.description) > 0: md_file.write('* {}\\\
    n\\n'.format(lib_class.description))\n        if len(lib_class.docs_text) > 0:\
    \ md_file.write('{}\\n\\n'.format(lib_class.docs_text))\n\n        if len(lib_class.requires)\
    \ > 0:\n            md_file.write('## Requires\\n')\n            for d in lib_class.requires:\n\
    \                path = os.path.basename(d) + '.html'\n                md_file.write('*\
    \ [{}]({})\\n'.format(os.path.basename(d).replace('_', '\\_'), path))\n      \
    \      md_file.write('\\n')\n        \n        if len(lib_class.testfiles) > 0:\n\
    \            md_file.write('## Verify Files\\n')\n            for d in lib_class.testfiles:\n\
    \                path = os.path.normpath(os.path.join(os.path.relpath(test_path,\
    \ lib_path), d)) + '.html'\n                md_file.write('* [{}]({})\\n'.format(d.replace('_',\
    \ '\\_'), path))\n            md_file.write('\\n')\n\n        md_file.write('##\
    \ Code\\n\\n')\n        md_file.write('```cpp\\n')\n        with open(lib_class.libfile_name)\
    \ as lib_file:\n            lines = lib_file.readlines()\n            for line\
    \ in lines: md_file.write(line)\n\n        md_file.write('\\n```\\n\\n')\n   \
    \     md_file.write('[\u30C8\u30C3\u30D7\u30DA\u30FC\u30B8\u306B\u623B\u308B]({})\\\
    n'.format(top_url))\n                \ndef generate_test_page(md_filename, testfile):\n\
    \    with open(md_filename, mode='w') as md_file:\n        md_file.write(import_static_js_text)\n\
    \        md_file.write(import_js_css(md_filename))\n        md_file.write('\\\
    n\\n')\n        \n        top_url = os.path.normpath(os.path.join(os.path.relpath(top_path,\
    \ os.path.dirname(md_filename)), 'index.html'))\n        md_file.write('[\u30C8\
    \u30C3\u30D7\u30DA\u30FC\u30B8\u306B\u623B\u308B]({})\\n\\n'.format(top_url))\n\
    \n        mark = get_mark(testfile.is_verified)\n        md_file.write('# {} {}\\\
    n\\n'.format(mark, testfile.testfile_name.replace('_', '\\_')))\n\n        if\
    \ len(testfile.problem.url) > 0: md_file.write('* URL: [{}]({})\\n'.format(testfile.problem.url,\
    \ testfile.problem.url))\n        if len(testfile.problem.description) > 0: md_file.write('*\
    \ {}\\n\\n'.format(testfile.problem.description))\n\n        if len(testfile.problem.dependencies)\
    \ > 1:\n            md_file.write('## Dependencies\\n')\n            for d in\
    \ testfile.problem.dependencies:\n                if os.path.samefile(d, testfile.testfile_name):\
    \ continue\n                path = os.path.normpath(os.path.join(os.path.relpath(lib_path,\
    \ os.path.dirname(md_filename)), os.path.basename(d))) + '.html'\n           \
    \     md_file.write('* [{}]({})\\n'.format(os.path.basename(d).replace('_', '\\\
    _'), path))\n            md_file.write('\\n')\n\n        md_file.write('## Code\\\
    n\\n')\n        md_file.write('```cpp\\n')\n        with open(testfile.testfile_name)\
    \ as test_file:\n            lines = test_file.readlines()\n            for line\
    \ in lines: md_file.write(line)\n        \n        md_file.write('\\n```\\n\\\
    n')\n        md_file.write('[\u30C8\u30C3\u30D7\u30DA\u30FC\u30B8\u306B\u623B\u308B\
    ]({})\\n'.format(top_url))\n                \n# Markdown \u5F62\u5F0F\u3067\u51FA\
    \u529B (\u30A2\u30F3\u30C0\u30FC\u30B9\u30B3\u30A2\u306F\u305D\u306E\u307E\u307E\
    \u4F7F\u3046\u3068\u3042\u308C\u306A\u306E\u3067\u7F6E\u63DB\u3059\u308B)\ndef\
    \ convert_lib_to_md(dir_name, lib_classes):\n    subprocess.run( 'mkdir -p {}'.format(lib_path),\
    \ shell = True )\n    \n    print('##', dir_name)\n    for c in lib_classes.values():\n\
    \        md_filename = os.path.join(lib_path, os.path.basename(c.libfile_name))\
    \ + '.md'\n        html_filename = os.path.join(lib_path, os.path.basename(c.libfile_name))\
    \ + '.html'\n        generate_lib_page(md_filename, c)\n        print('* {} [{}]({})'.format(get_mark(c.is_verified,\
    \ False), os.path.basename(c.libfile_name).replace('_', '\\_'), html_filename))\n\
    \    print()\n        \ndef convert_test_to_md(testfile):\n    subprocess.run(\
    \ 'mkdir -p {}'.format(test_path), shell = True )\n    dirname = os.path.dirname(os.path.join(test_path,\
    \ testfile.testfile_name))\n    subprocess.run( 'mkdir -p {}'.format(dirname),\
    \ shell = True )\n    \n    md_filename = os.path.normpath(os.path.join(test_path,\
    \ testfile.testfile_name)) + '.md'\n    html_filename = os.path.normpath(os.path.join(test_path,\
    \ testfile.testfile_name)) + '.html'\n    generate_test_page(md_filename, testfile)\n\
    \    mark = get_mark(testfile.is_verified)\n    print('* {} [{}]({})'.format(mark,\
    \ testfile.testfile_name.replace('_', '\\_'), html_filename))\n\ndef get_lib_class(dir_name,\
    \ lib_file_list, lib_verify_files, lib_verified):\n    lib_class = {}\n    for\
    \ f in lib_file_list:\n        libfile_name = f\n\n        proc = subprocess.run(['bash\
    \ ./lib/check_description.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE\
    \ )\n        description = proc.stdout.decode(\"UTF-8\")[:-1]\n\n        if os.path.basename(f)\
    \ in lib_verify_files:\n            testfiles = lib_verify_files[os.path.basename(f)]\n\
    \            is_verified = lib_verified[os.path.basename(f)]\n        else:\n\
    \            testfiles = []\n            is_verified = False\n        lib_class[os.path.basename(libfile_name)]\
    \ = LibFile(libfile_name, description, testfiles, is_verified)\n    return lib_class\n\
    \        \ndef get_test_class(dir_name, test_file_list):\n    test_files, lib_verify_files,\
    \ lib_verified = [], {}, {}\n    for f in test_file_list:\n        testfile_name\
    \ = f\n        \n        proc = subprocess.run(['bash ./lib/check_verification.sh\
    \ {}'.format(f)], shell = True, stdout = subprocess.PIPE )\n        proc_result\
    \ = proc.stdout.decode(\"UTF-8\")[:-1]\n        is_verified = (proc_result ==\
    \ \"1\")\n\n        proc = subprocess.run(['bash ./lib/check_url.sh {}'.format(f)],\
    \ shell = True, stdout = subprocess.PIPE )\n        url = proc.stdout.decode(\"\
    UTF-8\")[:-1]\n\n        proc = subprocess.run(['bash ./lib/check_description.sh\
    \ {}'.format(f)], shell = True, stdout = subprocess.PIPE )\n        description\
    \ = proc.stdout.decode(\"UTF-8\")[:-1]\n\n        proc = subprocess.run(['bash\
    \ ./lib/check_dependencies.sh {}'.format(f)], shell = True, stdout = subprocess.PIPE\
    \ )\n        dependencies = proc.stdout.decode(\"UTF-8\")[:-1].splitlines()\n\
    \        \n        problem = Problem(url, description, dependencies)\n       \
    \ test_files.append(TestFile(testfile_name, is_verified, problem))\n\n       \
    \ for d in dependencies:\n            lib_verify_files.setdefault(os.path.basename(d),\
    \ []).append(f)\n            lib_verified.setdefault(os.path.basename(d), is_verified)\n\
    \            lib_verified[os.path.basename(d)] |= is_verified\n            \n\
    \    return test_files, lib_verify_files, lib_verified\n    \ndef main():\n  \
    \  print(import_static_js_text)\n    print(import_js_css('./index.html'))\n  \
    \  desc_0 = '''\\\n[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)\n\
    \n* [\u30EA\u30DD\u30B8\u30C8\u30EA\u3078\u306E\u30EA\u30F3\u30AF](https://github.com/Tsutajiro/cpp_library)\n\
    * tsutaj \u304C\u4F7F\u7528\u3057\u3066\u3044\u308B\u7AF6\u6280\u30D7\u30ED\u30B0\
    \u30E9\u30DF\u30F3\u30B0\u7528\u30E9\u30A4\u30D6\u30E9\u30EA\u3067\u3059\u3002\
    \u81EA\u5DF1\u8CAC\u4EFB\u3067\u4F7F\u3063\u3066\u306D\n* CI \u306F\u8A66\u9A13\
    \u904B\u7528\u4E2D\u3067\u3059\n\n# \u76EE\u6B21\n\n* this unordered seed list\
    \ will be replaced by toc as unordered list\n{:toc}\n'''\n    print(desc_0)\n\
    \    \n    # \u30D1\u30B9\u306B 'test.cpp' \u304C\u4ED8\u3044\u3066\u3044\u308B\
    \u306A\u3089\u62FE\u3046\n    test_path = './'\n    test_cond = re.compile(r'^(?=.*test.cpp).*$')\n\
    \    ignore_test_list = []\n\n    test_dir_list = get_matched_directory_list(test_path,\
    \ test_cond, ignore_test_list)\n    for d in test_dir_list:\n        test_cpp_file_list\
    \ = get_matched_file_list(os.path.join(test_path, d), test_cond)\n        # convert_test_to_md(d,\
    \ test_cpp_file_list)\n        test_classes, lib_verify_files, lib_verified =\
    \ get_test_class(os.path.join(test_path, d), test_cpp_file_list)\n\n    desc_1\
    \ = '''\\\n# \u30E9\u30A4\u30D6\u30E9\u30EA\u4E00\u89A7\n'''    \n    # \u30D1\
    \u30B9\u306B 'verify' \u304C\u4ED8\u3044\u3066\u3044\u308B\u30D5\u30A1\u30A4\u30EB\
    \u306F\u62FE\u308F\u306A\u3044\n    # \u30D1\u30B9\u306B 'test.cpp' \u304C\u4ED8\
    \u3044\u3066\u3044\u308B\u30D5\u30A1\u30A4\u30EB\u3082\u62FE\u308F\u306A\u3044\
    \n    lib_path = '../'\n    lib_cond = re.compile(r'^(?!.*verify)(?!.*test.cpp).*$')\n\
    \    ignore_lib_list = []\n    \n    print(desc_1)\n    lib_dir_list = get_matched_directory_list(lib_path,\
    \ lib_cond, ignore_lib_list)\n    for d in lib_dir_list:\n        cpp_file_list\
    \ = get_matched_file_list(os.path.join(lib_path, d), lib_cond)\n        lib_classes\
    \ = get_lib_class(os.path.join(test_path, d), cpp_file_list, lib_verify_files,\
    \ lib_verified)\n        convert_lib_to_md(d, lib_classes)\n\n    desc_2 = '''\\\
    \n# Verify \u30D5\u30A1\u30A4\u30EB\u4E00\u89A7\n'''\n    print(desc_2)\n    for\
    \ t in test_classes:\n        convert_test_to_md(t)\n        \nif __name__ ==\
    \ '__main__':\n    main()\n"
  dependsOn: []
  isVerificationFile: false
  path: verifying_test/lib/generate_readme.py
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: verifying_test/lib/generate_readme.py
layout: document
redirect_from:
- /library/verifying_test/lib/generate_readme.py
- /library/verifying_test/lib/generate_readme.py.html
title: verifying_test/lib/generate_readme.py
---
