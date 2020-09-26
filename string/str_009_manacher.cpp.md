---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/verify/verify_str_009_manacher.cpp
    title: string/verify/verify_str_009_manacher.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_009_manacher.cpp\"\n// Manacher \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\n// \u5404\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\u3064\
    \u3044\u3066\u56DE\u6587\u534A\u5F84\u3092\u7DDA\u5F62\u6642\u9593\u3067\u6C42\
    \u3081\u308B\n// \u30C0\u30DF\u30FC\u6587\u5B57\u3092\u631F\u3080\u3053\u3068\u306B\
    \u3088\u308A\u5076\u6570\u9577\u56DE\u6587\u306B\u3082\u5BFE\u5FDC\ntemplate <typename\
    \ ArrayType, typename ElemType>\nstruct Manacher {\n    ArrayType v;\n    ElemType\
    \ dummy;\n    vector<int> rad;\n\n    ArrayType insert_dummy_elem(ArrayType vec,\
    \ ElemType dummy) {\n        int N = vec.size();\n        ArrayType res(2*N -\
    \ 1, dummy);\n        for(int i=0; i<N; i++) res[2*i] = vec[i];\n        return\
    \ res;\n    }\n\n    void build() {\n        int N = v.size(), i, j;\n       \
    \ rad = vector<int>(N);\n        for(i=j=0; i<N; ) {\n            while(i-j >=\
    \ 0 and i+j < N and v[i-j] == v[i+j]) j++;\n            rad[i] = j;\n\n      \
    \      int k;\n            for(k=1; i-k >= 0 and rad[i]-k > rad[i-k]; k++) rad[i+k]\
    \ = rad[i-k];\n\n            i += k;\n            j = max(0, j-k);\n        }\n\
    \    }\n\n    Manacher(ArrayType v_, ElemType dummy_) :\n        v(v_), dummy(dummy_)\
    \ {\n        v = insert_dummy_elem(v, dummy);\n        build();\n    }\n\n   \
    \ // idx \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u534A\u5F84 (0-indexed)\n\
    \    int get_rad(int idx) {\n        return (rad[2*idx] + 1) / 2;\n    }\n\n \
    \   // \u90E8\u5206\u6587\u5B57\u5217 [l, r) \u304C\u56DE\u6587\u304B\u3069\u3046\
    \u304B (0-indexed) \n    bool is_palindrome(int l, int r) {\n        if(l == r)\
    \ return true;\n        int idx = l + r - 1, len = r - l;\n        return rad[idx]\
    \ >= len;\n    }\n};\n"
  code: "// Manacher \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n// \u5404\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9\u306B\u3064\u3044\u3066\u56DE\u6587\u534A\u5F84\u3092\
    \u7DDA\u5F62\u6642\u9593\u3067\u6C42\u3081\u308B\n// \u30C0\u30DF\u30FC\u6587\u5B57\
    \u3092\u631F\u3080\u3053\u3068\u306B\u3088\u308A\u5076\u6570\u9577\u56DE\u6587\
    \u306B\u3082\u5BFE\u5FDC\ntemplate <typename ArrayType, typename ElemType>\nstruct\
    \ Manacher {\n    ArrayType v;\n    ElemType dummy;\n    vector<int> rad;\n\n\
    \    ArrayType insert_dummy_elem(ArrayType vec, ElemType dummy) {\n        int\
    \ N = vec.size();\n        ArrayType res(2*N - 1, dummy);\n        for(int i=0;\
    \ i<N; i++) res[2*i] = vec[i];\n        return res;\n    }\n\n    void build()\
    \ {\n        int N = v.size(), i, j;\n        rad = vector<int>(N);\n        for(i=j=0;\
    \ i<N; ) {\n            while(i-j >= 0 and i+j < N and v[i-j] == v[i+j]) j++;\n\
    \            rad[i] = j;\n\n            int k;\n            for(k=1; i-k >= 0\
    \ and rad[i]-k > rad[i-k]; k++) rad[i+k] = rad[i-k];\n\n            i += k;\n\
    \            j = max(0, j-k);\n        }\n    }\n\n    Manacher(ArrayType v_,\
    \ ElemType dummy_) :\n        v(v_), dummy(dummy_) {\n        v = insert_dummy_elem(v,\
    \ dummy);\n        build();\n    }\n\n    // idx \u3092\u4E2D\u5FC3\u3068\u3059\
    \u308B\u56DE\u6587\u534A\u5F84 (0-indexed)\n    int get_rad(int idx) {\n     \
    \   return (rad[2*idx] + 1) / 2;\n    }\n\n    // \u90E8\u5206\u6587\u5B57\u5217\
    \ [l, r) \u304C\u56DE\u6587\u304B\u3069\u3046\u304B (0-indexed) \n    bool is_palindrome(int\
    \ l, int r) {\n        if(l == r) return true;\n        int idx = l + r - 1, len\
    \ = r - l;\n        return rad[idx] >= len;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_009_manacher.cpp
  requiredBy:
  - string/verify/verify_str_009_manacher.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_009_manacher.cpp
layout: document
redirect_from:
- /library/string/str_009_manacher.cpp
- /library/string/str_009_manacher.cpp.html
title: string/str_009_manacher.cpp
---
