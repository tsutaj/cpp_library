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
  bundledCode: "#line 1 \"graph/graph_002_dijkstra.cpp\"\n// \u30C0\u30A4\u30AF\u30B9\
    \u30C8\u30E9\u6CD5 (priority_queue\u3092\u7528\u3044\u3066\u3001 O(|E| log|V|)\
    \ )\r\n// \u6CE8\u610F: \u8CA0\u306E\u8FBA\u304C\u5B58\u5728\u3059\u308B\u5834\
    \u5408\u3001\u3053\u306E\u65B9\u6CD5\u306F\u4F7F\u3048\u306A\u3044\u3088\uFF01\
    \uFF01\uFF01\uFF01\r\n\r\ntemplate <typename T>\r\nvector<T> dijkstra(vector<\
    \ vector< Edge<T> > > &G, int s) {\r\n    int V = G.size();\r\n    vector<T> d(V);\
    \ fill(d.begin(), d.end(), numeric_limits<T>::max());\r\n    priority_queue<pair<T,\
    \ int> , vector< pair<T, int> >, greater< pair<T, int> > > que;\r\n    d[s] =\
    \ 0;\r\n    que.push(make_pair(0,s));\r\n\r\n    while(!que.empty()) {\r\n   \
    \     pair<T, int> p = que.top(); que.pop();\r\n        int v = p.second;\r\n\
    \        if(d[v] < p.first) continue;\r\n        for(int i=0; i<G[v].size(); i++)\
    \ {\r\n            Edge<T> e = G[v][i];\r\n            if(d[e.to] > d[v] + e.cost)\
    \ {\r\n                d[e.to] = d[v] + e.cost;\r\n                que.push(make_pair(d[e.to],\
    \ e.to));\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}\n"
  code: "// \u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5 (priority_queue\u3092\u7528\
    \u3044\u3066\u3001 O(|E| log|V|) )\r\n// \u6CE8\u610F: \u8CA0\u306E\u8FBA\u304C\
    \u5B58\u5728\u3059\u308B\u5834\u5408\u3001\u3053\u306E\u65B9\u6CD5\u306F\u4F7F\
    \u3048\u306A\u3044\u3088\uFF01\uFF01\uFF01\uFF01\r\n\r\ntemplate <typename T>\r\
    \nvector<T> dijkstra(vector< vector< Edge<T> > > &G, int s) {\r\n    int V = G.size();\r\
    \n    vector<T> d(V); fill(d.begin(), d.end(), numeric_limits<T>::max());\r\n\
    \    priority_queue<pair<T, int> , vector< pair<T, int> >, greater< pair<T, int>\
    \ > > que;\r\n    d[s] = 0;\r\n    que.push(make_pair(0,s));\r\n\r\n    while(!que.empty())\
    \ {\r\n        pair<T, int> p = que.top(); que.pop();\r\n        int v = p.second;\r\
    \n        if(d[v] < p.first) continue;\r\n        for(int i=0; i<G[v].size();\
    \ i++) {\r\n            Edge<T> e = G[v][i];\r\n            if(d[e.to] > d[v]\
    \ + e.cost) {\r\n                d[e.to] = d[v] + e.cost;\r\n                que.push(make_pair(d[e.to],\
    \ e.to));\r\n            }\r\n        }\r\n    }\r\n    return d;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_002_dijkstra.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_002_dijkstra.cpp
layout: document
redirect_from:
- /library/graph/graph_002_dijkstra.cpp
- /library/graph/graph_002_dijkstra.cpp.html
title: graph/graph_002_dijkstra.cpp
---
