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
  bundledCode: "#line 1 \"structure/old/strc_003_segment_rmq_sec.cpp\"\n// \u6B21\u306E\
    2\u3064\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308BRMQ\n// \u30FB[a,\
    \ b) \u306E\u8981\u7D20\u5168\u3066\u306B x \u3092\u52A0\u3048\u308B\u30AF\u30A8\
    \u30EA\n// \u30FB[a, b) \u306E\u548C\u3092\u8A08\u7B97\u3059\u308B\u30AF\u30A8\
    \u30EA\n// (strc_006_bit_sec.cpp \u306B BIT \u7248\u304C\u3042\u308A\u3001\u305D\
    \u3061\u3089\u306E\u65B9\u304C\u901F\u3044\u3067\u3059)\n// Verify: \u306A\u3057\
    \ (POJ \u306E\u554F\u984C\u304C TLE \u3057\u305F)\n\ntemplate <typename T>\nclass\
    \ rmq_sec {\npublic:\n    vector<T> data, datb;\n    rmq_sec(int n_) {\n     \
    \   int m = 1; while(m < n_) m *= 2;\n        data.resize(2*m-1);\n        datb.resize(2*m-1);\n\
    \    }\n\n    void add(int a, int b, int x, int k, int l, int r) {\n        if(a\
    \ <= l && r <= b) {\n            data[k] += x;\n        }\n        else if(l <\
    \ b && a < r) {\n            datb[k] += (min(b, r) - max(a, l)) * x;\n       \
    \     add(a, b, x, k*2 + 1, l, (l + r) / 2);\n            add(a, b, x, k*2 + 2,\
    \ (l + r) / 2, r);\n        }\n    }\n\n    ll sum(int a, int b, int k, int l,\
    \ int r) {\n        if(b <= l || r <= a) {\n            return 0;\n        }\n\
    \        else if(a <= l && r <= b) {\n            return data[k] * (r - l) + datb[k];\n\
    \        }\n        else {\n            ll res = (min(b, r) - max(a, l)) * data[k];\n\
    \            res += sum(a, b, k*2 + 1, l, (l + r) / 2);\n            res += sum(a,\
    \ b, k*2 + 2, (l + r) / 2, r);\n            return res;\n        }\n    }\n};\n"
  code: "// \u6B21\u306E2\u3064\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\
    RMQ\n// \u30FB[a, b) \u306E\u8981\u7D20\u5168\u3066\u306B x \u3092\u52A0\u3048\
    \u308B\u30AF\u30A8\u30EA\n// \u30FB[a, b) \u306E\u548C\u3092\u8A08\u7B97\u3059\
    \u308B\u30AF\u30A8\u30EA\n// (strc_006_bit_sec.cpp \u306B BIT \u7248\u304C\u3042\
    \u308A\u3001\u305D\u3061\u3089\u306E\u65B9\u304C\u901F\u3044\u3067\u3059)\n//\
    \ Verify: \u306A\u3057 (POJ \u306E\u554F\u984C\u304C TLE \u3057\u305F)\n\ntemplate\
    \ <typename T>\nclass rmq_sec {\npublic:\n    vector<T> data, datb;\n    rmq_sec(int\
    \ n_) {\n        int m = 1; while(m < n_) m *= 2;\n        data.resize(2*m-1);\n\
    \        datb.resize(2*m-1);\n    }\n\n    void add(int a, int b, int x, int k,\
    \ int l, int r) {\n        if(a <= l && r <= b) {\n            data[k] += x;\n\
    \        }\n        else if(l < b && a < r) {\n            datb[k] += (min(b,\
    \ r) - max(a, l)) * x;\n            add(a, b, x, k*2 + 1, l, (l + r) / 2);\n \
    \           add(a, b, x, k*2 + 2, (l + r) / 2, r);\n        }\n    }\n\n    ll\
    \ sum(int a, int b, int k, int l, int r) {\n        if(b <= l || r <= a) {\n \
    \           return 0;\n        }\n        else if(a <= l && r <= b) {\n      \
    \      return data[k] * (r - l) + datb[k];\n        }\n        else {\n      \
    \      ll res = (min(b, r) - max(a, l)) * data[k];\n            res += sum(a,\
    \ b, k*2 + 1, l, (l + r) / 2);\n            res += sum(a, b, k*2 + 2, (l + r)\
    \ / 2, r);\n            return res;\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/old/strc_003_segment_rmq_sec.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/old/strc_003_segment_rmq_sec.cpp
layout: document
redirect_from:
- /library/structure/old/strc_003_segment_rmq_sec.cpp
- /library/structure/old/strc_003_segment_rmq_sec.cpp.html
title: structure/old/strc_003_segment_rmq_sec.cpp
---
