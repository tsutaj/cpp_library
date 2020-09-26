---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/verify/verify_str_010_z_algorithm.cpp
    title: string/verify/verify_str_010_z_algorithm.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_010_z_algorithm.cpp\"\n// Z-algorithm\n// \u5404\
    \ Suffix \u3068\u5143\u306E\u6587\u5B57\u5217\u3068\u306E LCP \u3092\u6C42\u3081\
    \u308B\ntemplate <typename ArrayType>\nstruct Z_algorithm {\n    ArrayType v;\n\
    \    vector<int> Z;\n\n    void build() {\n        int N = v.size(), i, j;\n \
    \       Z = vector<int>(N);\n\n        for(i=1,j=0; i<N; i++) {\n            int\
    \ l = i - j;\n            if(i + Z[l] < j + Z[j]) {\n                Z[i] = Z[l];\n\
    \            }\n            else {\n                int k = max(0, j + Z[j] -\
    \ i);\n                while(i + k < N and v[k] == v[i+k]) k++;\n            \
    \    Z[i] = k;\n                j = i;\n            }\n        }\n        Z[0]\
    \ = N;\n    }\n\n    Z_algorithm(ArrayType v_) : v(v_) {\n        build();\n \
    \   }\n\n    // idx \u304B\u3089\u5207\u308A\u51FA\u3057\u305F Suffix \u3068\u6587\
    \u5B57\u5217\u5168\u4F53\u3068\u306E LCP\n    int get_lcp(int idx) {\n       \
    \ return Z[idx];\n    }\n};\n"
  code: "// Z-algorithm\n// \u5404 Suffix \u3068\u5143\u306E\u6587\u5B57\u5217\u3068\
    \u306E LCP \u3092\u6C42\u3081\u308B\ntemplate <typename ArrayType>\nstruct Z_algorithm\
    \ {\n    ArrayType v;\n    vector<int> Z;\n\n    void build() {\n        int N\
    \ = v.size(), i, j;\n        Z = vector<int>(N);\n\n        for(i=1,j=0; i<N;\
    \ i++) {\n            int l = i - j;\n            if(i + Z[l] < j + Z[j]) {\n\
    \                Z[i] = Z[l];\n            }\n            else {\n           \
    \     int k = max(0, j + Z[j] - i);\n                while(i + k < N and v[k]\
    \ == v[i+k]) k++;\n                Z[i] = k;\n                j = i;\n       \
    \     }\n        }\n        Z[0] = N;\n    }\n\n    Z_algorithm(ArrayType v_)\
    \ : v(v_) {\n        build();\n    }\n\n    // idx \u304B\u3089\u5207\u308A\u51FA\
    \u3057\u305F Suffix \u3068\u6587\u5B57\u5217\u5168\u4F53\u3068\u306E LCP\n   \
    \ int get_lcp(int idx) {\n        return Z[idx];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_010_z_algorithm.cpp
  requiredBy:
  - string/verify/verify_str_010_z_algorithm.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_010_z_algorithm.cpp
layout: document
redirect_from:
- /library/string/str_010_z_algorithm.cpp
- /library/string/str_010_z_algorithm.cpp.html
title: string/str_010_z_algorithm.cpp
---
