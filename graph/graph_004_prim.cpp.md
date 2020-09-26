---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_004_prim.cpp\"\n// \u30D7\u30EA\u30E0\u6CD5\
    \ (\u6700\u5C0F\u5168\u57DF\u6728\u554F\u984C)\r\n// Edge\u306B\u306F from, to,\
    \ cost \u306E\u60C5\u5831\u304C\u5FC5\u9808\u3002\u8A08\u7B97\u91CF O( |V|^2 )\r\
    \n// \u2192 priority_queue\u3092\u7528\u3044\u3066\u3001O( |E| log|V| )\uFF01\r\
    \n// \u3053\u3053\u306B\u66F8\u3044\u3066\u3042\u308B\u306E\u306F\u52FF\u8AD6\u30AA\
    \u30FC\u30C0\u30FC\u5C0F\u3055\u3044\u65B9\u306E\u5B9F\u88C5\u3067\u3059\u3002\
    \r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6728(\u7121\u5411)\r\n// Verified: AOJ GRL_2_A:\
    \ Minimum Spanning Tree\r\ntemplate <typename T>\r\nT prim(vector< vector< Edge<T>\
    \ > > &G) {\r\n    int V = G.size(); T ans = 0;\r\n    vector<bool> used(V, false);\r\
    \n    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;\r\n\
    \    q.push(Edge<T>(0, 0, 0));\r\n    while(!q.empty()) {\r\n        Edge<T> temp\
    \ = q.top(); q.pop();\r\n        if(used[temp.to]) continue;\r\n        used[temp.to]\
    \ = true;\r\n        ans += temp.cost;\r\n        for(size_t i=0; i<G[temp.to].size();\
    \ i++) q.push(G[temp.to][i]);\r\n    }\r\n    return ans;\r\n}\r\n\r\n// \u6700\
    \u5C0F\u5168\u57DF\u6728(\u7121\u5411) \u91CD\u307F\u3068\u8FBA\u96C6\u5408\u306E\
    \u30DA\u30A2\u3067\u8FD4\u3059\u3088\uFF01\r\ntemplate <typename T>\r\npair<int,\
    \ vector< Edge<T> > > prim(vector< vector< Edge<T> > > &G) {\r\n    int V = G.size();\
    \ T ans = 0;\r\n    vector< Edge<T> > ans_e;\r\n    vector<bool> used(V, false);\r\
    \n    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;\r\n\
    \    q.push(Edge<T>(-1, 0, 0));\r\n    while(!q.empty()) {\r\n        Edge<T>\
    \ temp = q.top(); q.pop();\r\n        if(used[temp.to]) continue;\r\n        used[temp.to]\
    \ = true;\r\n        ans += temp.cost; if(temp.from >= 0) ans_e.push_back(temp);\r\
    \n        for(size_t i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);\r\n\
    \    }\r\n    // \u5168\u57DF\u6728\u4F5C\u308C\u306A\u3044\u306A\u3089\u7B54\u3048\
    \u3092 INF \u306B\u3059\u308B\r\n    for(int i=0; i<V; i++) if(!used[i]) ans =\
    \ numeric_limits<T>::max();\r\n    return pair<int, vector< Edge<T> > >(ans, ans_e);\r\
    \n}\r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6709\u5411\u6728 (\u6709\u5411)\r\n//\
    \ (Under construction)\r\n"
  code: "// \u30D7\u30EA\u30E0\u6CD5 (\u6700\u5C0F\u5168\u57DF\u6728\u554F\u984C)\r\
    \n// Edge\u306B\u306F from, to, cost \u306E\u60C5\u5831\u304C\u5FC5\u9808\u3002\
    \u8A08\u7B97\u91CF O( |V|^2 )\r\n// \u2192 priority_queue\u3092\u7528\u3044\u3066\
    \u3001O( |E| log|V| )\uFF01\r\n// \u3053\u3053\u306B\u66F8\u3044\u3066\u3042\u308B\
    \u306E\u306F\u52FF\u8AD6\u30AA\u30FC\u30C0\u30FC\u5C0F\u3055\u3044\u65B9\u306E\
    \u5B9F\u88C5\u3067\u3059\u3002\r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6728(\u7121\
    \u5411)\r\n// Verified: AOJ GRL_2_A: Minimum Spanning Tree\r\ntemplate <typename\
    \ T>\r\nT prim(vector< vector< Edge<T> > > &G) {\r\n    int V = G.size(); T ans\
    \ = 0;\r\n    vector<bool> used(V, false);\r\n    priority_queue< Edge<T>, vector<\
    \ Edge<T> >, greater< Edge<T> > > q;\r\n    q.push(Edge<T>(0, 0, 0));\r\n    while(!q.empty())\
    \ {\r\n        Edge<T> temp = q.top(); q.pop();\r\n        if(used[temp.to]) continue;\r\
    \n        used[temp.to] = true;\r\n        ans += temp.cost;\r\n        for(size_t\
    \ i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);\r\n    }\r\n    return\
    \ ans;\r\n}\r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6728(\u7121\u5411) \u91CD\u307F\
    \u3068\u8FBA\u96C6\u5408\u306E\u30DA\u30A2\u3067\u8FD4\u3059\u3088\uFF01\r\ntemplate\
    \ <typename T>\r\npair<int, vector< Edge<T> > > prim(vector< vector< Edge<T> >\
    \ > &G) {\r\n    int V = G.size(); T ans = 0;\r\n    vector< Edge<T> > ans_e;\r\
    \n    vector<bool> used(V, false);\r\n    priority_queue< Edge<T>, vector< Edge<T>\
    \ >, greater< Edge<T> > > q;\r\n    q.push(Edge<T>(-1, 0, 0));\r\n    while(!q.empty())\
    \ {\r\n        Edge<T> temp = q.top(); q.pop();\r\n        if(used[temp.to]) continue;\r\
    \n        used[temp.to] = true;\r\n        ans += temp.cost; if(temp.from >= 0)\
    \ ans_e.push_back(temp);\r\n        for(size_t i=0; i<G[temp.to].size(); i++)\
    \ q.push(G[temp.to][i]);\r\n    }\r\n    // \u5168\u57DF\u6728\u4F5C\u308C\u306A\
    \u3044\u306A\u3089\u7B54\u3048\u3092 INF \u306B\u3059\u308B\r\n    for(int i=0;\
    \ i<V; i++) if(!used[i]) ans = numeric_limits<T>::max();\r\n    return pair<int,\
    \ vector< Edge<T> > >(ans, ans_e);\r\n}\r\n\r\n// \u6700\u5C0F\u5168\u57DF\u6709\
    \u5411\u6728 (\u6709\u5411)\r\n// (Under construction)\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_004_prim.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_004_prim.cpp
layout: document
redirect_from:
- /library/graph/graph_004_prim.cpp
- /library/graph/graph_004_prim.cpp.html
title: graph/graph_004_prim.cpp
---
