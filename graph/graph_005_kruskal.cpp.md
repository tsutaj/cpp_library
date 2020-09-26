---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_005_kruskal.cpp\"\n// \u30AF\u30E9\u30B9\u30AB\
    \u30EB\u6CD5 (\u6700\u5C0F\u5168\u57DF\u6728\u554F\u984C)\r\n// Edge\u306B\u306F\
    \ from, to, cost \u306E\u60C5\u5831\u304C\u5FC5\u9808\u3002\u8A08\u7B97\u91CF\
    ( |E| log|V| )\r\n// Union-find\u6728\u3092\u4F7F\u3046\u306E\u3067\u3001\u305D\
    \u308C\u3082\u5FD8\u308C\u305A\u306B\u7D44\u307F\u8FBC\u3080\u3053\u3068\u3002\
    \r\n\r\ntemplate <typename T>\r\nT kruskal(vector< vector< Edge<T> > > &G) {\r\
    \n    int V = G.size();\r\n    vector< Edge<T> > es;\r\n    for(size_t i=0; i<V;\
    \ i++) {\r\n        for(size_t j=0; j<G[i].size(); j++) {\r\n            es.push_back(G[i][j]);\r\
    \n        }\r\n    }\r\n    int E = es.size();\r\n    sort(es.begin(), es.end());\r\
    \n    UnionFind uf(V);\r\n    T res = 0;\r\n    for(int i=0; i<E; i++) {\r\n \
    \       Edge<T> e = es[i];\r\n        if(!uf.same(e.from, e.to)) {\r\n       \
    \     uf.unite(e.from, e.to);\r\n            res += e.cost;\r\n        }\r\n \
    \   }\r\n    return res;\r\n}\r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728\
    \ (\u6709\u5411\u30B0\u30E9\u30D5)\r\n"
  code: "// \u30AF\u30E9\u30B9\u30AB\u30EB\u6CD5 (\u6700\u5C0F\u5168\u57DF\u6728\u554F\
    \u984C)\r\n// Edge\u306B\u306F from, to, cost \u306E\u60C5\u5831\u304C\u5FC5\u9808\
    \u3002\u8A08\u7B97\u91CF( |E| log|V| )\r\n// Union-find\u6728\u3092\u4F7F\u3046\
    \u306E\u3067\u3001\u305D\u308C\u3082\u5FD8\u308C\u305A\u306B\u7D44\u307F\u8FBC\
    \u3080\u3053\u3068\u3002\r\n\r\ntemplate <typename T>\r\nT kruskal(vector< vector<\
    \ Edge<T> > > &G) {\r\n    int V = G.size();\r\n    vector< Edge<T> > es;\r\n\
    \    for(size_t i=0; i<V; i++) {\r\n        for(size_t j=0; j<G[i].size(); j++)\
    \ {\r\n            es.push_back(G[i][j]);\r\n        }\r\n    }\r\n    int E =\
    \ es.size();\r\n    sort(es.begin(), es.end());\r\n    UnionFind uf(V);\r\n  \
    \  T res = 0;\r\n    for(int i=0; i<E; i++) {\r\n        Edge<T> e = es[i];\r\n\
    \        if(!uf.same(e.from, e.to)) {\r\n            uf.unite(e.from, e.to);\r\
    \n            res += e.cost;\r\n        }\r\n    }\r\n    return res;\r\n}\r\n\
    \r\n// \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728 (\u6709\u5411\u30B0\u30E9\u30D5\
    )\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_005_kruskal.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_005_kruskal.cpp
layout: document
redirect_from:
- /library/graph/graph_005_kruskal.cpp
- /library/graph/graph_005_kruskal.cpp.html
title: graph/graph_005_kruskal.cpp
---
