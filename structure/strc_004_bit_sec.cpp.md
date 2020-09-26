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
  bundledCode: "#line 1 \"structure/strc_004_bit_sec.cpp\"\n// \u6B21\u306E2\u3064\
    \u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308BBIT\n// \u30FB[a, b) \u306E\
    \u8981\u7D20\u5168\u3066\u306B x \u3092\u52A0\u3048\u308B\u30AF\u30A8\u30EA\n\
    // \u30FB[a, b) \u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u30AF\u30A8\u30EA\n\
    // Verified: POJ 3468 (A Simple Problem with Integers)\n\ntemplate <typename U>\n\
    class BIT_sec {\npublic:\n    int n;\n    BIT<U> bit0, bit1;\n    BIT_sec(int\
    \ n_) {\n        n = n_;\n        bit0 = BIT<U>(n);\n        bit1 = BIT<U>(n);\n\
    \    }\n\n    // \u6700\u521D\u306B\u8981\u7D20\u3092\u8FFD\u52A0\u3059\u308B\u3068\
    \u304D\u306F\u3053\u3063\u3061\n    void add(int i, int x) {\n        bit0.add(i,\
    \ x);\n    }\n\n    // [l, r] \u306E\u5168\u8981\u7D20\u306B x \u3092\u52A0\u3048\
    \u308B\n    void add(int l, int r, U x) {\n        bit0.add(l, -x * (l-1));\n\
    \        bit1.add(l, x);\n        bit0.add(r+1, x*r);\n        bit1.add(r+1, -x);\n\
    \    }\n\n    U sum(int l, int r) {\n        U res = 0;\n        res += bit0.sum(r)\
    \ + bit1.sum(r) * r;\n        res -= bit0.sum(l-1) + bit1.sum(l-1) * (l-1);\n\
    \        return res;\n    }\n};\n"
  code: "// \u6B21\u306E2\u3064\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\
    BIT\n// \u30FB[a, b) \u306E\u8981\u7D20\u5168\u3066\u306B x \u3092\u52A0\u3048\
    \u308B\u30AF\u30A8\u30EA\n// \u30FB[a, b) \u306E\u548C\u3092\u8A08\u7B97\u3059\
    \u308B\u30AF\u30A8\u30EA\n// Verified: POJ 3468 (A Simple Problem with Integers)\n\
    \ntemplate <typename U>\nclass BIT_sec {\npublic:\n    int n;\n    BIT<U> bit0,\
    \ bit1;\n    BIT_sec(int n_) {\n        n = n_;\n        bit0 = BIT<U>(n);\n \
    \       bit1 = BIT<U>(n);\n    }\n\n    // \u6700\u521D\u306B\u8981\u7D20\u3092\
    \u8FFD\u52A0\u3059\u308B\u3068\u304D\u306F\u3053\u3063\u3061\n    void add(int\
    \ i, int x) {\n        bit0.add(i, x);\n    }\n\n    // [l, r] \u306E\u5168\u8981\
    \u7D20\u306B x \u3092\u52A0\u3048\u308B\n    void add(int l, int r, U x) {\n \
    \       bit0.add(l, -x * (l-1));\n        bit1.add(l, x);\n        bit0.add(r+1,\
    \ x*r);\n        bit1.add(r+1, -x);\n    }\n\n    U sum(int l, int r) {\n    \
    \    U res = 0;\n        res += bit0.sum(r) + bit1.sum(r) * r;\n        res -=\
    \ bit0.sum(l-1) + bit1.sum(l-1) * (l-1);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_004_bit_sec.cpp
  requiredBy:
  - structure/verify/verify_strc_004_bit_sec.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_004_bit_sec.cpp
layout: document
redirect_from:
- /library/structure/strc_004_bit_sec.cpp
- /library/structure/strc_004_bit_sec.cpp.html
title: structure/strc_004_bit_sec.cpp
---
