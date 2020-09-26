---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/old/strc_011_lazysegtree.cpp\"\n// Lazy Segment\
    \ Tree (\u9045\u5EF6\u8A55\u4FA1\u4ED8\u304D\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
    )\n// \u7DCF\u548C\u30D0\u30FC\u30B8\u30E7\u30F3 (0-indexed, \u533A\u9593 add,\
    \ \u533A\u9593 sum)\n// Verified: AOJ DSL_2_E: Range Add Query (RAQ)\n\n// \u6700\
    \u4E0B\u6BB5\u306E\u30B5\u30A4\u30BA (\u5143\u914D\u5217\u306E\u30B5\u30A4\u30BA\
    \u3088\u308A\u5927\u304D\u3044 2 \u30D9\u30AD)\nconstexpr ll SIZE = 1LL << 17;\n\
    \ntemplate <typename T>\nstruct LazySegtree {\n    T node[2*SIZE], lazy[2*SIZE];\n\
    \n    // \u521D\u671F\u5316\n    LazySegtree() {}\n    LazySegtree(vector<T> v)\
    \ {\n        for(size_t i=0; i<v.size(); ++i) {\n            node[SIZE-1+i] =\
    \ v[i];\n        }\n        for(int i=SIZE-2; i>=0; i--) {\n            node[i]\
    \ = node[2*i+1] + node[2*i+2];\n        }\n    }\n\n    // \u9045\u5EF6\u8A55\u4FA1\
    \n    void lazyUpdate(int a, int b, int k) {\n        int rng = b - a;\n     \
    \   node[k] += lazy[k] * rng;\n        if(rng > 1) {\n            lazy[2*k+1]\
    \ += lazy[k];\n            lazy[2*k+2] += lazy[k];\n        }\n        lazy[k]\
    \ = 0;\n    }\n\n    // \u7BC4\u56F2 [a, b) \u306B x \u3092\u8DB3\u3059\n    void\
    \ add(int a, int b, T x, int l=0, int r=SIZE, int k=0) {\n        lazyUpdate(l,\
    \ r, k);\n        if(b <= l || r <= a) return;\n        if(a <= l && r <= b) {\n\
    \            lazy[k] += x;\n            lazyUpdate(l, r, k);\n        }\n    \
    \    else {\n            int mid = (l + r) / 2;\n            add(a, b, x, l, mid,\
    \ 2*k+1);\n            add(a, b, x, mid, r, 2*k+2);\n            node[k] = node[2*k+1]\
    \ + node[2*k+2];\n        }\n    }\n\n    // \u7BC4\u56F2 [a, b) \u306E\u7DCF\u548C\
    \n    T sum(int a, int b, int l=0, int r=SIZE, int k=0) {\n        lazyUpdate(l,\
    \ r, k);\n        if(b <= l || r <= a) return 0;\n        if(a <= l && r <= b)\
    \ return node[k];\n        int mid = (l + r) / 2;\n        T vl = sum(a, b, l,\
    \ mid, 2*k+1);\n        T vr = sum(a, b, mid, r, 2*k+2);\n        return vl +\
    \ vr;\n    }\n};\n"
  code: "// Lazy Segment Tree (\u9045\u5EF6\u8A55\u4FA1\u4ED8\u304D\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728)\n// \u7DCF\u548C\u30D0\u30FC\u30B8\u30E7\u30F3 (0-indexed,\
    \ \u533A\u9593 add, \u533A\u9593 sum)\n// Verified: AOJ DSL_2_E: Range Add Query\
    \ (RAQ)\n\n// \u6700\u4E0B\u6BB5\u306E\u30B5\u30A4\u30BA (\u5143\u914D\u5217\u306E\
    \u30B5\u30A4\u30BA\u3088\u308A\u5927\u304D\u3044 2 \u30D9\u30AD)\nconstexpr ll\
    \ SIZE = 1LL << 17;\n\ntemplate <typename T>\nstruct LazySegtree {\n    T node[2*SIZE],\
    \ lazy[2*SIZE];\n\n    // \u521D\u671F\u5316\n    LazySegtree() {}\n    LazySegtree(vector<T>\
    \ v) {\n        for(size_t i=0; i<v.size(); ++i) {\n            node[SIZE-1+i]\
    \ = v[i];\n        }\n        for(int i=SIZE-2; i>=0; i--) {\n            node[i]\
    \ = node[2*i+1] + node[2*i+2];\n        }\n    }\n\n    // \u9045\u5EF6\u8A55\u4FA1\
    \n    void lazyUpdate(int a, int b, int k) {\n        int rng = b - a;\n     \
    \   node[k] += lazy[k] * rng;\n        if(rng > 1) {\n            lazy[2*k+1]\
    \ += lazy[k];\n            lazy[2*k+2] += lazy[k];\n        }\n        lazy[k]\
    \ = 0;\n    }\n\n    // \u7BC4\u56F2 [a, b) \u306B x \u3092\u8DB3\u3059\n    void\
    \ add(int a, int b, T x, int l=0, int r=SIZE, int k=0) {\n        lazyUpdate(l,\
    \ r, k);\n        if(b <= l || r <= a) return;\n        if(a <= l && r <= b) {\n\
    \            lazy[k] += x;\n            lazyUpdate(l, r, k);\n        }\n    \
    \    else {\n            int mid = (l + r) / 2;\n            add(a, b, x, l, mid,\
    \ 2*k+1);\n            add(a, b, x, mid, r, 2*k+2);\n            node[k] = node[2*k+1]\
    \ + node[2*k+2];\n        }\n    }\n\n    // \u7BC4\u56F2 [a, b) \u306E\u7DCF\u548C\
    \n    T sum(int a, int b, int l=0, int r=SIZE, int k=0) {\n        lazyUpdate(l,\
    \ r, k);\n        if(b <= l || r <= a) return 0;\n        if(a <= l && r <= b)\
    \ return node[k];\n        int mid = (l + r) / 2;\n        T vl = sum(a, b, l,\
    \ mid, 2*k+1);\n        T vr = sum(a, b, mid, r, 2*k+2);\n        return vl +\
    \ vr;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/old/strc_011_lazysegtree.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/old/strc_011_lazysegtree.cpp
layout: document
redirect_from:
- /library/structure/old/strc_011_lazysegtree.cpp
- /library/structure/old/strc_011_lazysegtree.cpp.html
title: structure/old/strc_011_lazysegtree.cpp
---
