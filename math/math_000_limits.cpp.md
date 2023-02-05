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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 289, in update\n    uncommented_lines = get_uncommented_code(path, iquotes=self.iquotes,\
    \ compiler=self.compiler).splitlines(keepends=True)\n                        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 195, in get_uncommented_code\n    code = _get_uncommented_code(path.resolve(),\
    \ iquotes_options=tuple(iquotes_options), compiler=compiler)\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 188, in _get_uncommented_code\n    return subprocess.check_output(command)\n\
    \           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/subprocess.py\"\
    , line 466, in check_output\n    return run(*popenargs, stdout=PIPE, timeout=timeout,\
    \ check=True,\n           ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/subprocess.py\"\
    , line 571, in run\n    raise CalledProcessError(retcode, process.args,\nsubprocess.CalledProcessError:\
    \ Command '['g++', '-x', 'c++', '-I', '/home/runner/work/cpp_library/cpp_library',\
    \ '-fpreprocessed', '-dD', '-E', '/home/runner/work/cpp_library/cpp_library/math/math_000_limits.cpp']'\
    \ returned non-zero exit status 1.\n"
  code: "#include <climits>\r\n#include <cfloat>\r\n\r\n[int]\r\nINT_MIN \uFF5E INT_MAX\r\
    \n-2^31 \uFF5E 2^31 - 1\r\n-2147483648 \uFF5E 2147483647\r\n\r\n[unsigned int]\r\
    \n0 \uFF5E UINT_MAX\r\n0 \uFF5E 2^32 - 1\r\n0 \uFF5E 4294967295\r\n\r\n[long long]\r\
    \nLLONG_MIN \uFF5E LLONG_MAX\r\n-2^63 \uFF5E 2^63 - 1\r\n-9223372036854775808\
    \ \uFF5E 9223372036854775807\r\n\r\n[unsigned long long]\r\n0 \uFF5E ULONG_MAX\r\
    \n0 \uFF5E 2^64 - 1\r\n0 \uFF5E 18446744073709551615\r\n\r\n[float] \u203B \u5358\
    \u7CBE\u5EA6\r\nFLT_MIN \uFF5E FLT_MAX\r\n1.175494351e-38F \uFF5E 3.402823466e+38F\r\
    \n\r\n[double] \u203B \u500D\u7CBE\u5EA6\r\nDBL_MIN \uFF5E DBL_MAX\r\n2.2250738585072014e-308\
    \ \uFF5E 1.7976931348623158e+308\r\n\r\n[long double]\r\nLDBL_MIN \uFF5E LDBL_MAX\r\
    \n\u74B0\u5883\u306B\u3088\u3063\u3066\u5909\u5316\u3059\u308B\u304C\u3001double\u578B\
    \u3088\u308A\u3082\u7CBE\u5EA6\u304C\u826F\u3044\u5834\u5408\u304C\u307B\u3068\
    \u3093\u3069\u3002"
  dependsOn: []
  isVerificationFile: false
  path: math/math_000_limits.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_000_limits.cpp
layout: document
redirect_from:
- /library/math/math_000_limits.cpp
- /library/math/math_000_limits.cpp.html
title: math/math_000_limits.cpp
---
