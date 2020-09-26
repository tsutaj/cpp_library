---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_011_weighted_unionfind.cpp\"\n// \u91CD\u307F\
    \u4ED8\u304D UnionFind - \u30DE\u30FC\u30B8\u30C6\u30AF (QuickFind) \u3092\u4F7F\
    \u7528\u3057\u305F\u5B9F\u88C5\n// merge \u306E\u8A08\u7B97\u91CF\u306F\u306A\u3089\
    \u3057 O(log N)\n// Verified: Never Wait for Weights (AOJ 1330)\n\nstruct QuickFind\
    \ {\n    int N;\n    vector<int> i2g;\n    vector< vector<int> > g2i;\n    vector<long\
    \ long int> weight;\n \n    QuickFind(int N_) {\n        N = N_;\n        i2g.resize(N);\n\
    \        g2i.resize(N);\n        weight.resize(N);\n \n        for(int i=0; i<N;\
    \ i++) {\n            i2g[i] = i;\n            g2i[i] = vector<int>{i};\n    \
    \    }\n    }\n \n    bool same(int u, int v) {\n        return i2g[u] == i2g[v];\n\
    \    }\n \n    // v \u306E\u65B9\u304C w \u3060\u3051\u5927\u304D\u3044\n    void\
    \ unite(int u, int v, int w) {\n        int ru = i2g[u], rv = i2g[v];\n      \
    \  if(ru == rv) return;\n \n        // \u30DE\u30FC\u30B8\u3059\u308B\u5BFE\u8C61\
    \u3092\u5909\u66F4\u3059\u308B\u5834\u5408\u306F swap \u3059\u308B\n        if(g2i[rv].size()\
    \ > g2i[ru].size()) {\n            swap(ru, rv);\n            swap(u, v);\n  \
    \          w = -w;\n        }\n \n        long long int prev = weight[v];\n  \
    \      weight[v] = weight[u] + w;\n \n        for(auto e : g2i[rv]) {\n      \
    \      i2g[e] = ru;\n            long long int diff = weight[e] - prev;\n    \
    \        // v \u81EA\u8EAB\u306F\u66F4\u65B0\u6E08\u307F\u306A\u306E\u3067\u30B9\
    \u30AD\u30C3\u30D7 (\u91CD\u8981)\n            if(e != v) weight[e] = weight[v]\
    \ + diff;\n        }\n \n        // rv \u306E\u4E2D\u8EAB\u3092\u5168\u90E8 ru\
    \ \u306B\u79FB\u3059\n        for(auto e : g2i[rv]) {\n            g2i[ru].push_back(e);\n\
    \        }\n        g2i[rv].clear();\n    }\n \n    long long int query(int u,\
    \ int v) {\n        assert(same(u, v));\n        return weight[v] - weight[u];\n\
    \    }\n};\n"
  code: "// \u91CD\u307F\u4ED8\u304D UnionFind - \u30DE\u30FC\u30B8\u30C6\u30AF (QuickFind)\
    \ \u3092\u4F7F\u7528\u3057\u305F\u5B9F\u88C5\n// merge \u306E\u8A08\u7B97\u91CF\
    \u306F\u306A\u3089\u3057 O(log N)\n// Verified: Never Wait for Weights (AOJ 1330)\n\
    \nstruct QuickFind {\n    int N;\n    vector<int> i2g;\n    vector< vector<int>\
    \ > g2i;\n    vector<long long int> weight;\n \n    QuickFind(int N_) {\n    \
    \    N = N_;\n        i2g.resize(N);\n        g2i.resize(N);\n        weight.resize(N);\n\
    \ \n        for(int i=0; i<N; i++) {\n            i2g[i] = i;\n            g2i[i]\
    \ = vector<int>{i};\n        }\n    }\n \n    bool same(int u, int v) {\n    \
    \    return i2g[u] == i2g[v];\n    }\n \n    // v \u306E\u65B9\u304C w \u3060\u3051\
    \u5927\u304D\u3044\n    void unite(int u, int v, int w) {\n        int ru = i2g[u],\
    \ rv = i2g[v];\n        if(ru == rv) return;\n \n        // \u30DE\u30FC\u30B8\
    \u3059\u308B\u5BFE\u8C61\u3092\u5909\u66F4\u3059\u308B\u5834\u5408\u306F swap\
    \ \u3059\u308B\n        if(g2i[rv].size() > g2i[ru].size()) {\n            swap(ru,\
    \ rv);\n            swap(u, v);\n            w = -w;\n        }\n \n        long\
    \ long int prev = weight[v];\n        weight[v] = weight[u] + w;\n \n        for(auto\
    \ e : g2i[rv]) {\n            i2g[e] = ru;\n            long long int diff = weight[e]\
    \ - prev;\n            // v \u81EA\u8EAB\u306F\u66F4\u65B0\u6E08\u307F\u306A\u306E\
    \u3067\u30B9\u30AD\u30C3\u30D7 (\u91CD\u8981)\n            if(e != v) weight[e]\
    \ = weight[v] + diff;\n        }\n \n        // rv \u306E\u4E2D\u8EAB\u3092\u5168\
    \u90E8 ru \u306B\u79FB\u3059\n        for(auto e : g2i[rv]) {\n            g2i[ru].push_back(e);\n\
    \        }\n        g2i[rv].clear();\n    }\n \n    long long int query(int u,\
    \ int v) {\n        assert(same(u, v));\n        return weight[v] - weight[u];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_011_weighted_unionfind.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_011_weighted_unionfind.cpp
layout: document
redirect_from:
- /library/structure/strc_011_weighted_unionfind.cpp
- /library/structure/strc_011_weighted_unionfind.cpp.html
title: structure/strc_011_weighted_unionfind.cpp
---
