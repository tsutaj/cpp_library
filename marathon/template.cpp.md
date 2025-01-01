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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.8/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: /home/tsutaj/Documents/compro/cpp_library/marathon/timer.cpp:\
    \ line -1: no such header\n"
  code: "\n#ifndef DEBUG\n#pragma GCC target(\"avx2\")\n#pragma GCC optimize(\"O3\"\
    )\n#pragma GCC optimize(\"unroll-loops\")\n#endif\n\n#include <cstdio>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstring>\n#include <string>\n#include\
    \ <functional>\n#include <stack>\n#include <utility>\n#include <queue>\n#include\
    \ <algorithm>\n#include <execinfo.h>\n#include <iostream>\n#include <set>\n#include\
    \ <numeric>\n#include <map>\nusing namespace std;\nusing ll = long long int;\n\
    \n#ifdef DEBUG\n#define STDERR(...) fprintf(stderr, __VA_ARGS__);\n#define ASSERT_OVERLOAD(e1,e2,NAME,...)\
    \ NAME\n#define ASSERT_1(x) assert_with_backtrace((x))\n#define ASSERT_2(x, y)\
    \ assert_with_backtrace((x), (y))\n#define ASSERT(...) ASSERT_OVERLOAD(__VA_ARGS__,\
    \ ASSERT_2, ASSERT_1)(__VA_ARGS__)\n#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__),\
    \ printf(__VA_ARGS__)\n#else\n#define STDERR(...)\n#define ASSERT(...)\n#define\
    \ DEBUG_PRINT(...)\n#endif\n\n// assert \u3067\u843D\u3061\u305F\u3068\u304D\u306B\
    \u30D0\u30C3\u30AF\u30C8\u30EC\u30FC\u30B9\u3059\u308B (`-g -rdynamic` \u304C\u5FC5\
    \u8981)\n// \u30C7\u30D0\u30C3\u30B0\u30E2\u30FC\u30C9\u3067\u306E\u307F\u6709\
    \u52B9\nvoid assert_with_backtrace(bool condition, std::string error_msg=\"\"\
    ) {\n    if(!condition) {\n        void* callstack[256];\n        int i, frames\
    \ = backtrace(callstack, 256);\n        char** strs = backtrace_symbols(callstack,\
    \ frames);\n        for (i = 0; i < frames; ++i) {\n            fprintf(stderr,\
    \ \"%s\\n\", strs[i]);\n        }\n        free(strs);\n        fprintf(stderr,\
    \ \"%s\\n\", error_msg.c_str());\n        ASSERT(false);\n    }\n}\n\ntemplate\
    \ <typename Tp>\nbool chmin(Tp& a, const Tp& b) {\n    if(a > b) {\n        a\
    \ = b;\n        return true;\n    } else {\n        return false;\n    }\n}\n\
    template <typename Tp>\nbool chmax(Tp& a, const Tp& b) {\n    if(a < b) {\n  \
    \      a = b;\n        return true;\n    } else {\n        return false;\n   \
    \ }\n}\n\n#include \"/home/tsutaj/Documents/compro/cpp_library/marathon/timer.cpp\"\
    \n#include \"/home/tsutaj/Documents/compro/cpp_library/marathon/rand.cpp\"\nRand\
    \ rnd(35023503980LL);\nTimer timer;\n\nint main() {\n    timer.setStart();\n\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/template.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/template.cpp
layout: document
redirect_from:
- /library/marathon/template.cpp
- /library/marathon/template.cpp.html
title: marathon/template.cpp
---
