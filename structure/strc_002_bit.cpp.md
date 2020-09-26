---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_004_bit_sec.cpp
    title: structure/verify/verify_strc_004_bit_sec.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_002_bit.cpp\"\n// Binary Indexed Tree (BIT)\n\
    // Verified: AOJ DSL_2_B: Range Sum Query (int\u306E\u307F)\n\ntemplate <typename\
    \ T>\nstruct BIT{\nprivate:\n    vector<T> array;\n    int n;\n\npublic:\n   \
    \ // \u521D\u671F\u5316\n    BIT() {}\n    BIT(int _n) : array(_n + 1, 0), n(_n)\
    \ {}\n\n    // 1\u756A\u76EE\u304B\u3089 i\u756A\u76EE\u307E\u3067\u306E\u7D2F\
    \u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int i) {\n        T s = 0;\n \
    \       while(i > 0) {\n            s += array[i];\n            i -= i & -i; \
    \     // LSB \u6E1B\u7B97\n        }\n        return s;\n    }\n\n    // [i, j]\
    \ \u306E\u8981\u7D20\u306E\u7DCF\u548C\n    T sum(int i, int j) {\n        T ret_i\
    \ = sum(i-1);\n        T ret_j = sum(j);\n        return ret_j - ret_i;\n    }\n\
    \n    // i \u756A\u76EE\u306B \u8981\u7D20 x \u3092\u8FFD\u52A0\n    void add(int\
    \ i, T x) {\n        while(i <= n) {\n            array[i] += x;\n           \
    \ i += i & -i;      // LSB \u52A0\u7B97\n        }\n    }\n};\n"
  code: "// Binary Indexed Tree (BIT)\n// Verified: AOJ DSL_2_B: Range Sum Query (int\u306E\
    \u307F)\n\ntemplate <typename T>\nstruct BIT{\nprivate:\n    vector<T> array;\n\
    \    int n;\n\npublic:\n    // \u521D\u671F\u5316\n    BIT() {}\n    BIT(int _n)\
    \ : array(_n + 1, 0), n(_n) {}\n\n    // 1\u756A\u76EE\u304B\u3089 i\u756A\u76EE\
    \u307E\u3067\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int i)\
    \ {\n        T s = 0;\n        while(i > 0) {\n            s += array[i];\n  \
    \          i -= i & -i;      // LSB \u6E1B\u7B97\n        }\n        return s;\n\
    \    }\n\n    // [i, j] \u306E\u8981\u7D20\u306E\u7DCF\u548C\n    T sum(int i,\
    \ int j) {\n        T ret_i = sum(i-1);\n        T ret_j = sum(j);\n        return\
    \ ret_j - ret_i;\n    }\n\n    // i \u756A\u76EE\u306B \u8981\u7D20 x \u3092\u8FFD\
    \u52A0\n    void add(int i, T x) {\n        while(i <= n) {\n            array[i]\
    \ += x;\n            i += i & -i;      // LSB \u52A0\u7B97\n        }\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_002_bit.cpp
  requiredBy:
  - structure/verify/verify_strc_004_bit_sec.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_002_bit.cpp
layout: document
redirect_from:
- /library/structure/strc_002_bit.cpp
- /library/structure/strc_002_bit.cpp.html
title: structure/strc_002_bit.cpp
---
