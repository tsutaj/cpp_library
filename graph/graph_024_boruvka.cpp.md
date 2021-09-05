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
  bundledCode: "#line 1 \"graph/graph_024_boruvka.cpp\"\n// Boruvka's algorithm (\u6700\
    \u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B)\n// \u305D\u306E\u6642\u70B9\
    \u3067\u5B58\u5728\u3059\u308B\u305D\u308C\u305E\u308C\u306E\u6728\u306B\u3064\
    \u3044\u3066\u3001\u305D\u308C\u306B\u63A5\u7D9A\u3057\u3066\u3044\u308B\u8FBA\
    \u3067\u91CD\u307F\u6700\u5C0F\u306E\u3082\u306E\u3092\u63A2\u3059\u95A2\u6570\
    \u304C\u5FC5\u8981\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\u30E9\u30EA: UnionFind\n\
    \ntemplate <typename T, typename F>\nT boruvka(int N, F f) {\n    UnionFind uf(N);\n\
    \    vector<int> group(N), rev(N);\n    T ans(0);\n\n    while(uf.size() > 1)\
    \ {\n        // \u5404\u9802\u70B9\u304C\u4F55\u756A\u76EE\u306E\u9023\u7D50\u6210\
    \u5206\u306B\u5C5E\u3059\u308B\u304B\uFF1F\n        // \u3042\u308B\u9023\u7D50\
    \u6210\u5206\u306B\u3064\u3044\u3066\u4EE3\u8868\u5143\u306F\u306A\u306B\u304B\
    \uFF1F\n        int ptr = 0;\n        for(int i=0; i<N; i++) {\n            if(uf.find(i)\
    \ == i) {\n                group[i] = ptr++;\n                rev[ group[i] ]\
    \ = i;\n            }\n        }\n        for(int i=0; i<N; i++) group[i] = group[\
    \ uf.find(i) ];\n\n        // \u7570\u306A\u308B\u9023\u7D50\u6210\u5206\u540C\
    \u58EB\u3092\u7D50\u3093\u3067\u3044\u308B\u8FBA\u306E\u5019\u88DC\u3092\u3082\
    \u3063\u3066\u304F\u308B\n        // \u5404\u9023\u7D50\u6210\u5206\u306B\u5BFE\
    \u3057\u3066 (\u6700\u5C0F\u30B3\u30B9\u30C8\u30FB\u7E4B\u3052\u308B\u5148 (\u306A\
    \u3044\u306A\u3089 -1))\n        auto edges = f(ptr, group);\n\n        bool changed\
    \ = false;\n        for(int u=0; u<ptr; u++) {\n            T cost; int v; tie(cost,\
    \ v) = edges[u];\n            if(v >= 0 and uf.unite(rev[u], rev[v])) {\n    \
    \            ans += cost;\n                changed = true;\n            }\n  \
    \      }\n\n        if(!changed) return false;\n    }\n\n    return ans;\n}\n"
  code: "// Boruvka's algorithm (\u6700\u5C0F\u5168\u57DF\u6728\u3092\u6C42\u3081\u308B\
    )\n// \u305D\u306E\u6642\u70B9\u3067\u5B58\u5728\u3059\u308B\u305D\u308C\u305E\
    \u308C\u306E\u6728\u306B\u3064\u3044\u3066\u3001\u305D\u308C\u306B\u63A5\u7D9A\
    \u3057\u3066\u3044\u308B\u8FBA\u3067\u91CD\u307F\u6700\u5C0F\u306E\u3082\u306E\
    \u3092\u63A2\u3059\u95A2\u6570\u304C\u5FC5\u8981\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\
    \u30E9\u30EA: UnionFind\n\ntemplate <typename T, typename F>\nT boruvka(int N,\
    \ F f) {\n    UnionFind uf(N);\n    vector<int> group(N), rev(N);\n    T ans(0);\n\
    \n    while(uf.size() > 1) {\n        // \u5404\u9802\u70B9\u304C\u4F55\u756A\u76EE\
    \u306E\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3059\u308B\u304B\uFF1F\n        //\
    \ \u3042\u308B\u9023\u7D50\u6210\u5206\u306B\u3064\u3044\u3066\u4EE3\u8868\u5143\
    \u306F\u306A\u306B\u304B\uFF1F\n        int ptr = 0;\n        for(int i=0; i<N;\
    \ i++) {\n            if(uf.find(i) == i) {\n                group[i] = ptr++;\n\
    \                rev[ group[i] ] = i;\n            }\n        }\n        for(int\
    \ i=0; i<N; i++) group[i] = group[ uf.find(i) ];\n\n        // \u7570\u306A\u308B\
    \u9023\u7D50\u6210\u5206\u540C\u58EB\u3092\u7D50\u3093\u3067\u3044\u308B\u8FBA\
    \u306E\u5019\u88DC\u3092\u3082\u3063\u3066\u304F\u308B\n        // \u5404\u9023\
    \u7D50\u6210\u5206\u306B\u5BFE\u3057\u3066 (\u6700\u5C0F\u30B3\u30B9\u30C8\u30FB\
    \u7E4B\u3052\u308B\u5148 (\u306A\u3044\u306A\u3089 -1))\n        auto edges =\
    \ f(ptr, group);\n\n        bool changed = false;\n        for(int u=0; u<ptr;\
    \ u++) {\n            T cost; int v; tie(cost, v) = edges[u];\n            if(v\
    \ >= 0 and uf.unite(rev[u], rev[v])) {\n                ans += cost;\n       \
    \         changed = true;\n            }\n        }\n\n        if(!changed) return\
    \ false;\n    }\n\n    return ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_024_boruvka.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_024_boruvka.cpp
layout: document
redirect_from:
- /library/graph/graph_024_boruvka.cpp
- /library/graph/graph_024_boruvka.cpp.html
title: graph/graph_024_boruvka.cpp
---
