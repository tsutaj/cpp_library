---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/DSL_1_A/union_find.test.cpp
    title: verifying_test/AOJ/DSL_1_A/union_find.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/data_structure/unionfind/union_find.test.cpp
    title: verifying_test/yosupo/data_structure/unionfind/union_find.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: ./docs/union_find.md
    document_title: Union-Find
    links: []
  bundledCode: "#line 2 \"structure/union_find.cpp\"\n\r\n/**\r\n * @brief Union-Find\r\
    \n * @docs ./docs/union_find.md\r\n */\r\n\r\n#include <algorithm>\r\n#include\
    \ <vector>\r\n\r\nstruct UnionFind {\r\nprivate:\r\n    const int n;\r\n    int\
    \ size_;\r\n    vector<int> uf;\r\npublic:\r\n    // \u521D\u671F\u5316 UnionFind\
    \ uni(n) \u306E\u3088\u3046\u306B\u5BA3\u8A00\u3059\u308C\u3070\u826F\u3044\r\n\
    \    UnionFind(int _n) : n(_n), size_(_n), uf(_n, -1) {}\r\n    void reset() {\r\
    \n        size_ = n;\r\n        fill(uf.begin(), uf.end(), -1);\r\n    }\r\n \
    \   // find (\u6728\u306E\u6839\u3092\u6C42\u3081\u308B)\r\n    int find(int x)\
    \ {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}\r\n    // x \u3068 y \u304C\u540C\
    \u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\u3046\u304B\r\n    bool\
    \ same(int x, int y) {return find(x) == find(y);}\r\n    // x \u304C\u5C5E\u3059\
    \u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\r\n    int size(int x) {return -uf[find(x)];}\r\
    \n    // \u96C6\u5408\u306F\u3044\u304F\u3064\u3042\u308B\u304B\r\n    int size()\
    \      {return size_;}\r\n    // x \u3068 y \u306E\u5C5E\u3059\u308B\u96C6\u5408\
    \u3092\u4F75\u5408\r\n    bool unite(int x, int y) {\r\n        x = find(x); y\
    \ = find(y);\r\n        if(x == y) return false;\r\n        size_--;\r\n     \
    \   if(-uf[x] < -uf[y]) swap(x, y);\r\n        uf[x] += uf[y]; uf[y] = x;\r\n\
    \        return true;\r\n    }\r\n};\r\n"
  code: "#pragma once\r\n\r\n/**\r\n * @brief Union-Find\r\n * @docs ./docs/union_find.md\r\
    \n */\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nstruct UnionFind\
    \ {\r\nprivate:\r\n    const int n;\r\n    int size_;\r\n    vector<int> uf;\r\
    \npublic:\r\n    // \u521D\u671F\u5316 UnionFind uni(n) \u306E\u3088\u3046\u306B\
    \u5BA3\u8A00\u3059\u308C\u3070\u826F\u3044\r\n    UnionFind(int _n) : n(_n), size_(_n),\
    \ uf(_n, -1) {}\r\n    void reset() {\r\n        size_ = n;\r\n        fill(uf.begin(),\
    \ uf.end(), -1);\r\n    }\r\n    // find (\u6728\u306E\u6839\u3092\u6C42\u3081\
    \u308B)\r\n    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}\r\
    \n    // x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\
    \u3069\u3046\u304B\r\n    bool same(int x, int y) {return find(x) == find(y);}\r\
    \n    // x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\r\n  \
    \  int size(int x) {return -uf[find(x)];}\r\n    // \u96C6\u5408\u306F\u3044\u304F\
    \u3064\u3042\u308B\u304B\r\n    int size()      {return size_;}\r\n    // x \u3068\
    \ y \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\r\n    bool unite(int\
    \ x, int y) {\r\n        x = find(x); y = find(y);\r\n        if(x == y) return\
    \ false;\r\n        size_--;\r\n        if(-uf[x] < -uf[y]) swap(x, y);\r\n  \
    \      uf[x] += uf[y]; uf[y] = x;\r\n        return true;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/union_find.cpp
  requiredBy: []
  timestamp: '2021-09-22 10:52:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/yosupo/data_structure/unionfind/union_find.test.cpp
  - verifying_test/AOJ/DSL_1_A/union_find.test.cpp
documentation_of: structure/union_find.cpp
layout: document
redirect_from:
- /library/structure/union_find.cpp
- /library/structure/union_find.cpp.html
title: Union-Find
---
