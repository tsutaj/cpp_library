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
  bundledCode: "#line 1 \"structure/old/strc_002_segment_rmq.cpp\"\n// Range Minimum\
    \ Query (\u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\u3001RMQ)\n// Verified: AOJ\
    \ DSL_2_A: Range Minimum Query (int\u578B\u306E\u307F)\n\ntemplate <typename T>\n\
    class rmq {\npublic:\n    int n;\n    vector<T> dat;\n\n    // \u8981\u7D20\u6570\
    \ m \u306E RMQ \u3092\u4F5C\u308B\n    rmq(int m) {\n        n = 1;\n        while(n\
    \ < m) n *= 2;\n        dat.resize(2*n-1);\n        rep(i,0,2*n-1) dat[i] = INT_MAX;\n\
    \    }\n\n    // k\u756A\u76EE (0-indexed) \u306E\u5024\u3092 a \u306B\u66F4\u65B0\
    \n    void update(int k, T a) {\n        k += n - 1;\n        dat[k] = a;\n  \
    \      while(k > 0) {\n            k = (k - 1) / 2;\n            dat[k] = min(dat[k*2+1],\
    \ dat[k*2+2]);\n        }\n    }\n\n    // [a, b) \u306E\u6700\u5C0F\u5024\u3092\
    \u8FD4\u3059\n    // \u6700\u521D\u306B\u547C\u3073\u51FA\u3059\u3068\u304D\u306F\
    \ XX.query(a, b, 0, 0, -1) \u3068\u3059\u308B\n    T query(int a, int b, int k,\
    \ int l, int r) {\n        if(r == -1) r = n;\n        if(r <= a || b <= l) return\
    \ INT_MAX;\n        if(a <= l && r <= b) return dat[k];\n        else {\n    \
    \        T vl = query(a, b, k*2+1, l, (l+r)/2);\n            T vr = query(a, b,\
    \ k*2+2, (l+r)/2, r);\n            return min(vl, vr);\n        }\n    }\n};\n"
  code: "// Range Minimum Query (\u533A\u9593\u6700\u5C0F\u30AF\u30A8\u30EA\u3001\
    RMQ)\n// Verified: AOJ DSL_2_A: Range Minimum Query (int\u578B\u306E\u307F)\n\n\
    template <typename T>\nclass rmq {\npublic:\n    int n;\n    vector<T> dat;\n\n\
    \    // \u8981\u7D20\u6570 m \u306E RMQ \u3092\u4F5C\u308B\n    rmq(int m) {\n\
    \        n = 1;\n        while(n < m) n *= 2;\n        dat.resize(2*n-1);\n  \
    \      rep(i,0,2*n-1) dat[i] = INT_MAX;\n    }\n\n    // k\u756A\u76EE (0-indexed)\
    \ \u306E\u5024\u3092 a \u306B\u66F4\u65B0\n    void update(int k, T a) {\n   \
    \     k += n - 1;\n        dat[k] = a;\n        while(k > 0) {\n            k\
    \ = (k - 1) / 2;\n            dat[k] = min(dat[k*2+1], dat[k*2+2]);\n        }\n\
    \    }\n\n    // [a, b) \u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059\n    // \u6700\
    \u521D\u306B\u547C\u3073\u51FA\u3059\u3068\u304D\u306F XX.query(a, b, 0, 0, -1)\
    \ \u3068\u3059\u308B\n    T query(int a, int b, int k, int l, int r) {\n     \
    \   if(r == -1) r = n;\n        if(r <= a || b <= l) return INT_MAX;\n       \
    \ if(a <= l && r <= b) return dat[k];\n        else {\n            T vl = query(a,\
    \ b, k*2+1, l, (l+r)/2);\n            T vr = query(a, b, k*2+2, (l+r)/2, r);\n\
    \            return min(vl, vr);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/old/strc_002_segment_rmq.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/old/strc_002_segment_rmq.cpp
layout: document
redirect_from:
- /library/structure/old/strc_002_segment_rmq.cpp
- /library/structure/old/strc_002_segment_rmq.cpp.html
title: structure/old/strc_002_segment_rmq.cpp
---
