---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/subprocess.py\"\
    , line 420, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/subprocess.py\"\
    , line 524, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/cpp_library/cpp_library',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/cpp_library/cpp_library/oj-prepare-template.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "<%!\n    import json\n    import os\n    import platform\n    import shutil\n\
    \    from logging import getLogger\n\n    import onlinejudge_template.generator.cplusplus\
    \ as cplusplus\n    import onlinejudge_template.generator.topcoder as topcoder\n\
    \    import onlinejudge_template.generator.about as about\n    import onlinejudge_template.generator.hook\
    \ as hook\n%>\\\n<%\n    data['config']['scanner'] = 'scanf'\n    data['config']['printer']\
    \ = 'printf'\n\n    logger = getLogger(__name__)\n    # if not shutil.which(\"\
    clang-format\"):\n    #     logger.warning(\"clang-format is not installed. If\
    \ you want to generate well-formatted code, please install it. If you use Ubuntu,\
    \ you can run $ sudo apt install clang-format\")\n    # else:\n    #     format_config\
    \ = {\n    #         \"BasedOnStyle\": \"Google\",\n    #         \"IndentWidth\"\
    : 4,\n    #         \"ColumnLimit\": 9999,\n    #         \"ForEachMacros\": [\"\
    ALL\"],\n    #     }\n    #     hook.register_filter_command([\"clang-format\"\
    , \"--style\", json.dumps(format_config)], data=data)\n%>\\\n// #define _GLIBCXX_DEBUG\
    \ // for STL debug (optional)\n#include <iostream>\n#include <iomanip>\n#include\
    \ <cstdio>\n#include <string>\n#include <cstring>\n#include <deque>\n#include\
    \ <list>\n#include <queue>\n#include <stack>\n#include <vector>\n#include <utility>\n\
    #include <algorithm>\n#include <map>\n#include <set>\n#include <complex>\n#include\
    \ <cmath>\n#include <limits>\n#include <cfloat>\n#include <climits>\n#include\
    \ <ctime>\n#include <cassert>\n#include <numeric>\n#include <fstream>\n#include\
    \ <functional>\n#include <bitset>\n\nusing namespace std;\nusing ll = long long\
    \ int;\nusing int64 = long long int;\n\n#define ALL(v) (v).begin(), (v).end()\n\
    template<typename T> void chmax(T &a, T b) {a = max(a, b);}\ntemplate<typename\
    \ T> void chmin(T &a, T b) {a = min(a, b);}\ntemplate<typename T> void chadd(T\
    \ &a, T b) {a = a + b;}\n \nint dx[] = {0, 0, 1, -1};\nint dy[] = {1, -1, 0, 0};\n\
    const int INF = 1LL << 29;\nconst ll LONGINF = 1LL << 60;\nconst ll MOD_1000000007\
    \ = 1000000007LL;\nconst ll MOD_998244353 = 998244353LL;\n\n// generated by ${about.title}\
    \ ${about.version} (${about.url})\n${cplusplus.declare_constants(data)}\n% if\
    \ topcoder.is_topcoder(data):\n<% solve_function = topcoder.class_name(data) +\
    \ \"().\" + topcoder.method_name(data) %>\\\nclass ${topcoder.class_name(data)}\
    \ {\npublic:\n\n};\n% else:\nint main() {\n\n    return 0;\n}\n% endif"
  dependsOn: []
  isVerificationFile: false
  path: oj-prepare-template.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: oj-prepare-template.cpp
layout: document
redirect_from:
- /library/oj-prepare-template.cpp
- /library/oj-prepare-template.cpp.html
title: oj-prepare-template.cpp
---