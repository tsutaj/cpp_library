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
  bundledCode: "#line 1 \"math/math_003_digit.cpp\"\n// \u6574\u6570\u306E\u6841\u6570\
    \u3092\u8ABF\u3079\u308B (10\u9032\u6570)\ntemplate <typename T_digit>\nint digit(T_digit\
    \ n) {\n    int ans = 0;\n    while(n != 0) {n /= 10; ans++;}\n    return ans;\n\
    }\n\n// \u6574\u6570\u306E\u6841\u6570\u3092\u8ABF\u3079\u308B (k\u9032\u6570\
    )\ntemplate <typename T_digit>\ntemplate <typename U_digit>\nint digit(T_digit\
    \ n, U_digit k) {\n    int ans = 0;\n    while(n != 0) {n /= k; ans++;}\n    return\
    \ ans;\n}\n\n// \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (10\u9032\u6570)\ntemplate\
    \ <typename T_numIndex>\nint numIndex(T_numIndex n, int k) {\n    rep(i,0,k) n\
    \ /= 10;\n    return n % 10;\n}\n"
  code: "// \u6574\u6570\u306E\u6841\u6570\u3092\u8ABF\u3079\u308B (10\u9032\u6570\
    )\ntemplate <typename T_digit>\nint digit(T_digit n) {\n    int ans = 0;\n   \
    \ while(n != 0) {n /= 10; ans++;}\n    return ans;\n}\n\n// \u6574\u6570\u306E\
    \u6841\u6570\u3092\u8ABF\u3079\u308B (k\u9032\u6570)\ntemplate <typename T_digit>\n\
    template <typename U_digit>\nint digit(T_digit n, U_digit k) {\n    int ans =\
    \ 0;\n    while(n != 0) {n /= k; ans++;}\n    return ans;\n}\n\n// \u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9 (10\u9032\u6570)\ntemplate <typename T_numIndex>\nint\
    \ numIndex(T_numIndex n, int k) {\n    rep(i,0,k) n /= 10;\n    return n % 10;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: math/math_003_digit.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_003_digit.cpp
layout: document
redirect_from:
- /library/math/math_003_digit.cpp
- /library/math/math_003_digit.cpp.html
title: math/math_003_digit.cpp
---
