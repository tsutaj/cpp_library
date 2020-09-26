---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_015_partial_persistent_unionfind.cpp\"\n\
    // \u90E8\u5206\u6C38\u7D9A UnionFind\n// \u30D0\u30FC\u30B8\u30E7\u30F3\u3092\
    \u6307\u5B9A\u3057\u3066\u95A2\u6570\u3092\u52D5\u304B\u3059\u3053\u3068\u3067\
    \u3001\u305D\u306E\u6642\u70B9\u3067\u306E\u9023\u7D50\u60C5\u5831\u304C\u5F97\
    \u3089\u308C\u308B\n\nstruct PartialPersistentUnionFind {\n    vector<int> node,\
    \ last;\n    vector< vector< pair<int, int> > > history;\n    PartialPersistentUnionFind(int\
    \ size_) : node(size_, -1), last(size_, 1e9), history(size_) {\n        for(auto\
    \ &vec : history) vec.emplace_back(-1, -1);\n    }\n    bool unite(int t, int\
    \ x, int y) {\n        x = find(t, x);\n        y = find(t, y);\n        if(x\
    \ == y) return false;\n        if(node[x] > node[y]) swap(x, y);\n        node[x]\
    \ += node[y];\n        history[x].emplace_back(t, node[x]);\n        node[y] =\
    \ x; last[y] = t;\n        return true;\n    }\n    bool same(int t, int x, int\
    \ y) {\n        return find(t, x) == find(t, y);\n    }\n    int find(int t, int\
    \ x) {\n        if(t < last[x]) return x;\n        return find(t, node[x]);\n\
    \    }\n    int size(int t, int x) {\n        x = find(t, x);\n        return\
    \ -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, (int)0)))->second;\n\
    \    }\n};\n"
  code: "// \u90E8\u5206\u6C38\u7D9A UnionFind\n// \u30D0\u30FC\u30B8\u30E7\u30F3\u3092\
    \u6307\u5B9A\u3057\u3066\u95A2\u6570\u3092\u52D5\u304B\u3059\u3053\u3068\u3067\
    \u3001\u305D\u306E\u6642\u70B9\u3067\u306E\u9023\u7D50\u60C5\u5831\u304C\u5F97\
    \u3089\u308C\u308B\n\nstruct PartialPersistentUnionFind {\n    vector<int> node,\
    \ last;\n    vector< vector< pair<int, int> > > history;\n    PartialPersistentUnionFind(int\
    \ size_) : node(size_, -1), last(size_, 1e9), history(size_) {\n        for(auto\
    \ &vec : history) vec.emplace_back(-1, -1);\n    }\n    bool unite(int t, int\
    \ x, int y) {\n        x = find(t, x);\n        y = find(t, y);\n        if(x\
    \ == y) return false;\n        if(node[x] > node[y]) swap(x, y);\n        node[x]\
    \ += node[y];\n        history[x].emplace_back(t, node[x]);\n        node[y] =\
    \ x; last[y] = t;\n        return true;\n    }\n    bool same(int t, int x, int\
    \ y) {\n        return find(t, x) == find(t, y);\n    }\n    int find(int t, int\
    \ x) {\n        if(t < last[x]) return x;\n        return find(t, node[x]);\n\
    \    }\n    int size(int t, int x) {\n        x = find(t, x);\n        return\
    \ -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, (int)0)))->second;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_015_partial_persistent_unionfind.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_015_partial_persistent_unionfind.cpp
layout: document
redirect_from:
- /library/structure/strc_015_partial_persistent_unionfind.cpp
- /library/structure/strc_015_partial_persistent_unionfind.cpp.html
title: structure/strc_015_partial_persistent_unionfind.cpp
---
