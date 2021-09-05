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
  bundledCode: "#line 1 \"graph/graph_003_warshall.cpp\"\n// \u30EF\u30FC\u30B7\u30E3\
    \u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5 (\u5168\u70B9\u5BFE\u6700\u77ED\u8DEF\u554F\
    \u984C)\r\n// \u8A08\u7B97\u91CF O(|V|^3 )\r\n// \u8CA0\u306E\u9589\u8DEF\u304C\
    \u3042\u308B\u304B\u3069\u3046\u304B\u306F\u3001d[i][i]\u304C\u8CA0\u306B\u306A\
    \u308B\u9802\u70B9 i \u304C\u3042\u308B\u304B\u3069\u3046\u304B\u3067\u5224\u5B9A\
    \u53EF\u80FD\r\n\r\ntemplate <typename T>\r\nvector< vector<T> > warshall(vector<\
    \ vector< Edge<T> > > &G) {\r\n    int V = G.size();\r\n    vector< vector<T>\
    \ > d(V);\r\n    for(size_t i=0; i<V; i++) {\r\n        for(size_t j=0; j<V; j++)\
    \ { {\r\n                if(i == j) d[i].push_back(0);\r\n                else\
    \ d[i].push_back(numeric_limits<T>::max());\r\n            }\r\n        }\r\n\
    \    }\r\n\r\n    for(size_t i=0; i<V; i++) {\r\n        for(size_t j=0; j<G[i].size();\
    \ j++) {\r\n            Edge<T> e = G[i][j];\r\n            d[i][e.to] = e.cost;\r\
    \n        }\r\n    }\r\n\r\n    for(size_t k=0; k<V; k++) {\r\n        for(size_t\
    \ i=0; i<V; i++) {\r\n            for(size_t j=0; j<V; j++) {\r\n            \
    \    if(d[i][k] != numeric_limits<T>::max() && d[k][j] != numeric_limits<T>::max())\r\
    \n                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);\r\n         \
    \   }\r\n        }\r\n    }\r\n    return d;\r\n}\r\n\r\n// (\u8CA0\u306E\u9589\
    \u8DEF\u304C\u3042\u3063\u305F\u3089 true \u306B\u306A\u308B bool minus)\r\nbool\
    \ minus = false;\r\nvector< vector<Edge<T> > > G;\r\nvector< vector<T> > d = warshall(G);\r\
    \nfor(size_t i=0; i<G.size(); i++) if(d[i][i] < 0) minus = true;\r\n"
  code: "// \u30EF\u30FC\u30B7\u30E3\u30EB\u30D5\u30ED\u30A4\u30C9\u6CD5 (\u5168\u70B9\
    \u5BFE\u6700\u77ED\u8DEF\u554F\u984C)\r\n// \u8A08\u7B97\u91CF O(|V|^3 )\r\n//\
    \ \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u304B\u3069\u3046\u304B\u306F\u3001\
    d[i][i]\u304C\u8CA0\u306B\u306A\u308B\u9802\u70B9 i \u304C\u3042\u308B\u304B\u3069\
    \u3046\u304B\u3067\u5224\u5B9A\u53EF\u80FD\r\n\r\ntemplate <typename T>\r\nvector<\
    \ vector<T> > warshall(vector< vector< Edge<T> > > &G) {\r\n    int V = G.size();\r\
    \n    vector< vector<T> > d(V);\r\n    for(size_t i=0; i<V; i++) {\r\n       \
    \ for(size_t j=0; j<V; j++) { {\r\n                if(i == j) d[i].push_back(0);\r\
    \n                else d[i].push_back(numeric_limits<T>::max());\r\n         \
    \   }\r\n        }\r\n    }\r\n\r\n    for(size_t i=0; i<V; i++) {\r\n       \
    \ for(size_t j=0; j<G[i].size(); j++) {\r\n            Edge<T> e = G[i][j];\r\n\
    \            d[i][e.to] = e.cost;\r\n        }\r\n    }\r\n\r\n    for(size_t\
    \ k=0; k<V; k++) {\r\n        for(size_t i=0; i<V; i++) {\r\n            for(size_t\
    \ j=0; j<V; j++) {\r\n                if(d[i][k] != numeric_limits<T>::max() &&\
    \ d[k][j] != numeric_limits<T>::max())\r\n                    d[i][j] = min(d[i][j],\
    \ d[i][k] + d[k][j]);\r\n            }\r\n        }\r\n    }\r\n    return d;\r\
    \n}\r\n\r\n// (\u8CA0\u306E\u9589\u8DEF\u304C\u3042\u3063\u305F\u3089 true \u306B\
    \u306A\u308B bool minus)\r\nbool minus = false;\r\nvector< vector<Edge<T> > >\
    \ G;\r\nvector< vector<T> > d = warshall(G);\r\nfor(size_t i=0; i<G.size(); i++)\
    \ if(d[i][i] < 0) minus = true;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_003_warshall.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_003_warshall.cpp
layout: document
redirect_from:
- /library/graph/graph_003_warshall.cpp
- /library/graph/graph_003_warshall.cpp.html
title: graph/graph_003_warshall.cpp
---
