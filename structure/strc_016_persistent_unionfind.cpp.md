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
  bundledCode: "#line 1 \"structure/strc_016_persistent_unionfind.cpp\"\n// \u5B8C\
    \u5168\u6C38\u7D9A UnionFind\n// PersistentArray \u304C\u306A\u3044\u3068\u52D5\
    \u304D\u307E\u305B\u3093\n\nstruct PersistentUnionFind {\n    PersistentArray<int,\
    \ 3> data;\n    PersistentUnionFind() {}\n    PersistentUnionFind(int size_) {\n\
    \        data.build(vector<int>(size_, -1));\n    }\n\n    int find(int k) {\n\
    \        int p = data.get(k);\n        return p >= 0 ? find(p) : k;\n    }\n\n\
    \    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n\n\
    \    int size(int k) {\n        return (-data.get(find(k)));\n    }\n    \n  \
    \  PersistentUnionFind unite(int x, int y) {\n        x = find(x);\n        y\
    \ = find(y);\n        if(x == y) return *this;\n        auto u = data.get(x);\n\
    \        auto v = data.get(y);\n        if(u > v) swap(u, v), swap(x, y);\n\n\
    \        auto a = data.mutable_get(x);\n        *a += v;\n        auto b = data.mutable_get(y);\n\
    \        *b = x;\n        return *this;\n    }\n};\n"
  code: "// \u5B8C\u5168\u6C38\u7D9A UnionFind\n// PersistentArray \u304C\u306A\u3044\
    \u3068\u52D5\u304D\u307E\u305B\u3093\n\nstruct PersistentUnionFind {\n    PersistentArray<int,\
    \ 3> data;\n    PersistentUnionFind() {}\n    PersistentUnionFind(int size_) {\n\
    \        data.build(vector<int>(size_, -1));\n    }\n\n    int find(int k) {\n\
    \        int p = data.get(k);\n        return p >= 0 ? find(p) : k;\n    }\n\n\
    \    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n\n\
    \    int size(int k) {\n        return (-data.get(find(k)));\n    }\n    \n  \
    \  PersistentUnionFind unite(int x, int y) {\n        x = find(x);\n        y\
    \ = find(y);\n        if(x == y) return *this;\n        auto u = data.get(x);\n\
    \        auto v = data.get(y);\n        if(u > v) swap(u, v), swap(x, y);\n\n\
    \        auto a = data.mutable_get(x);\n        *a += v;\n        auto b = data.mutable_get(y);\n\
    \        *b = x;\n        return *this;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_016_persistent_unionfind.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_016_persistent_unionfind.cpp
layout: document
redirect_from:
- /library/structure/strc_016_persistent_unionfind.cpp
- /library/structure/strc_016_persistent_unionfind.cpp.html
title: structure/strc_016_persistent_unionfind.cpp
---
