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
  bundledCode: "#line 1 \"structure/strc_005_bit_zero_indexed.cpp\"\n// 0-indexed\
    \ Binary Indexed Tree (BIT)\n// Verified: AOJ DSL_2_B: Range Sum Query (int\u306E\
    \u307F)\n\ntemplate <typename T>\nstruct zeroIndexedBIT{\nprivate:\n    vector<T>\
    \ array;\n    int n;\n\npublic:\n    // \u521D\u671F\u5316 (\u9069\u5F53)\n  \
    \  zeroIndexedBIT() : array(10, 0), n(10) {}\n    zeroIndexedBIT(int _n) : array(_n,\
    \ 0), n(_n) {}\n\n    // \u4ED6\u306E\u30AF\u30E9\u30B9\u3067 BIT \u3092\u547C\
    \u3073\u51FA\u3059\u3068\u304D\u306B\u4FBF\u5229\u306A\u306E\u3067\u4F5C\u3063\
    \u305F\n    void resize(int _n) {\n        array.resize(_n);\n        n = _n;\n\
    \    }\n\n    // 0\u756A\u76EE\u304B\u3089 i\u756A\u76EE\u307E\u3067\u306E\u7D2F\
    \u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int i) {\n        T s = 0;\n \
    \       for(int k=i; k>=0; k = (k&(k+1)) - 1) s += array[k];\n        return s;\n\
    \    }\n\n    // [i, j] \u306E\u8981\u7D20\u306E\u7DCF\u548C\n    T sum(int i,\
    \ int j) {\n        T ret_i = sum(i-1);\n        T ret_j = sum(j);\n        return\
    \ ret_j - ret_i;\n    }\n\n    // i \u756A\u76EE\u306B \u8981\u7D20 x \u3092\u8FFD\
    \u52A0\n    void add(int i, T x) {\n        for(int k=i; k<n; k |= k+1) array[k]\
    \ += x;\n    }\n};\n"
  code: "// 0-indexed Binary Indexed Tree (BIT)\n// Verified: AOJ DSL_2_B: Range Sum\
    \ Query (int\u306E\u307F)\n\ntemplate <typename T>\nstruct zeroIndexedBIT{\nprivate:\n\
    \    vector<T> array;\n    int n;\n\npublic:\n    // \u521D\u671F\u5316 (\u9069\
    \u5F53)\n    zeroIndexedBIT() : array(10, 0), n(10) {}\n    zeroIndexedBIT(int\
    \ _n) : array(_n, 0), n(_n) {}\n\n    // \u4ED6\u306E\u30AF\u30E9\u30B9\u3067\
    \ BIT \u3092\u547C\u3073\u51FA\u3059\u3068\u304D\u306B\u4FBF\u5229\u306A\u306E\
    \u3067\u4F5C\u3063\u305F\n    void resize(int _n) {\n        array.resize(_n);\n\
    \        n = _n;\n    }\n\n    // 0\u756A\u76EE\u304B\u3089 i\u756A\u76EE\u307E\
    \u3067\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int i) {\n \
    \       T s = 0;\n        for(int k=i; k>=0; k = (k&(k+1)) - 1) s += array[k];\n\
    \        return s;\n    }\n\n    // [i, j] \u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \n    T sum(int i, int j) {\n        T ret_i = sum(i-1);\n        T ret_j = sum(j);\n\
    \        return ret_j - ret_i;\n    }\n\n    // i \u756A\u76EE\u306B \u8981\u7D20\
    \ x \u3092\u8FFD\u52A0\n    void add(int i, T x) {\n        for(int k=i; k<n;\
    \ k |= k+1) array[k] += x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_005_bit_zero_indexed.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_005_bit_zero_indexed.cpp
layout: document
redirect_from:
- /library/structure/strc_005_bit_zero_indexed.cpp
- /library/structure/strc_005_bit_zero_indexed.cpp.html
title: structure/strc_005_bit_zero_indexed.cpp
---
