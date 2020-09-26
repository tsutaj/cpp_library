---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_001_bellman.cpp\"\n/***** \u30D9\u30EB\u30DE\
    \u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 *****/\r\n// \u8A08\u7B97\u91CF O(|V| |E|)\r\
    \n// \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\u554F\u984C\u3092\u89E3\u304F\u3002\
    \u5404\u8FBA\u306E\u91CD\u307F\u306F\u8CA0\u6570\u3067\u3082\u3088\u3044\r\n//\
    \ \u901A\u5E38 |V| - 1 \u56DE\u5B9F\u884C\u3057\u3066\u30EB\u30FC\u30D7\u3092\u629C\
    \u3051\u308B\u304C\u3001\u8CA0\u306E\u30B3\u30B9\u30C8\u306E\u9589\u8DEF\u304C\
    \u5B58\u5728\u3059\u308B\u5834\u5408\u306F\r\n// V \u56DE\u76EE\u3067\u3082\u66F4\
    \u65B0\u304C\u767A\u751F\u3059\u308B \u2192 \u8CA0\u306E\u9589\u8DEF\u306E\u691C\
    \u51FA\u306B\u3082\u4F7F\u3048\u308B\r\n\r\n// \u30B0\u30E9\u30D5\u306B\u3001\
    s \u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\u8CA0\u306E\u9589\u8DEF\u304C\u3042\
    \u308B\u304B\u3069\u3046\u304B\u3092\u691C\u51FA\u3059\u308B\r\ntemplate <typename\
    \ T>\r\nbool find_negative_loop(vector< vector< Edge<T> > > &G, int s) {\r\n \
    \   int V = G.size();\r\n    vector<T> d(V);\r\n    for(int i=0; i<V; i++) d[i]\
    \ = numeric_limits<T>::max(); d[s] = 0;\r\n    for(int i=0; i<V; i++) {\r\n  \
    \      for(int j=0; j<V; j++) {\r\n            for(int k=0; k<G[j].size(); k++)\
    \ {\r\n                Edge<T> e = G[j][k];\r\n                if(d[j] != numeric_limits<T>::max()\
    \ && d[e.to] > d[j] + e.cost) {\r\n                    d[e.to] = d[j] + e.cost;\r\
    \n\r\n                    // n \u56DE\u76EE\u306B\u3082\u66F4\u65B0\u304C\u3042\
    \u308B\u306A\u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\r\n \
    \                   if(i == V - 1) return true;\r\n                }\r\n     \
    \       }\r\n        }\r\n    }\r\n    return false;\r\n}\r\n\r\n// \u30B0\u30E9\
    \u30D5\u5168\u4F53\u3092\u898B\u3066\u3001\u8CA0\u306E\u9589\u8DEF\u304C\u3042\
    \u308B\u304B\u3069\u3046\u304B\u3092\u691C\u51FA\u3059\u308B\r\ntemplate <typename\
    \ T>\r\nbool find_negative_loop_whole(vector< vector< Edge<T> > > &G) {\r\n  \
    \  int V = G.size();\r\n    vector<T> d(V);\r\n    fill(d.begin(), d.end(), 0);\r\
    \n    for(int i=0; i<V; i++) {\r\n        for(int j=0; j<V; j++) {\r\n       \
    \     for(int k=0; k<G[j].size(); k++) {\r\n                Edge<T> e = G[j][k];\r\
    \n                if(d[e.to] > d[j] + e.cost) {\r\n                    d[e.to]\
    \ = d[j] + e.cost;\r\n\r\n                    // n \u56DE\u76EE\u306B\u3082\u66F4\
    \u65B0\u304C\u3042\u308B\u306A\u3089\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\
    \u3059\u308B\r\n                    if(i == V - 1) return true;\r\n          \
    \      }\r\n            }\r\n        }\r\n    }\r\n    return false;\r\n}\r\n\r\
    \n// \u9802\u70B9\u306E\u6570V, \u8FBA\u306E\u6570E\u306E\u30B0\u30E9\u30D5\u306B\
    \u304A\u3044\u3066\u3001 s \u756A\u76EE\u306E\u9802\u70B9\u304B\u3089\u5404\u9802\
    \u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\r\ntemplate\
    \ <typename T>\r\nvector<T> bellman(vector< vector< Edge<T> > > &G, int s) {\r\
    \n    // \u9802\u70B9\u306E\u6570\u3068\u8FBA\u306E\u6570\u3092\u6570\u3048\u308B\
    \r\n    int V = G.size();\r\n    vector<T> d(V);\r\n    for(int i=0; i<V; i++)\
    \ d[i] = numeric_limits<T>::max();\r\n    d[s] = 0;\r\n\r\n    while(true) {\r\
    \n        bool update = false;\r\n        for(int i=0; i<V; i++) {\r\n       \
    \     for(int j=0; j<G[i].size(); j++) {\r\n                Edge<T> e = G[i][j];\r\
    \n                if(d[i] != numeric_limits<T>::max() && d[e.to] > d[i] + e.cost)\
    \ {\r\n                    d[e.to] = d[i] + e.cost;\r\n                    update\
    \ = true;\r\n                }\r\n            }\r\n        }\r\n        if(!update)\
    \ break;\r\n    }\r\n    return d;\r\n}\n"
  code: "/***** \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u6CD5 *****/\r\n\
    // \u8A08\u7B97\u91CF O(|V| |E|)\r\n// \u5358\u4E00\u59CB\u70B9\u6700\u77ED\u8DEF\
    \u554F\u984C\u3092\u89E3\u304F\u3002\u5404\u8FBA\u306E\u91CD\u307F\u306F\u8CA0\
    \u6570\u3067\u3082\u3088\u3044\r\n// \u901A\u5E38 |V| - 1 \u56DE\u5B9F\u884C\u3057\
    \u3066\u30EB\u30FC\u30D7\u3092\u629C\u3051\u308B\u304C\u3001\u8CA0\u306E\u30B3\
    \u30B9\u30C8\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\u5834\u5408\u306F\
    \r\n// V \u56DE\u76EE\u3067\u3082\u66F4\u65B0\u304C\u767A\u751F\u3059\u308B \u2192\
    \ \u8CA0\u306E\u9589\u8DEF\u306E\u691C\u51FA\u306B\u3082\u4F7F\u3048\u308B\r\n\
    \r\n// \u30B0\u30E9\u30D5\u306B\u3001s \u304B\u3089\u5230\u9054\u53EF\u80FD\u306A\
    \u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u691C\
    \u51FA\u3059\u308B\r\ntemplate <typename T>\r\nbool find_negative_loop(vector<\
    \ vector< Edge<T> > > &G, int s) {\r\n    int V = G.size();\r\n    vector<T> d(V);\r\
    \n    for(int i=0; i<V; i++) d[i] = numeric_limits<T>::max(); d[s] = 0;\r\n  \
    \  for(int i=0; i<V; i++) {\r\n        for(int j=0; j<V; j++) {\r\n          \
    \  for(int k=0; k<G[j].size(); k++) {\r\n                Edge<T> e = G[j][k];\r\
    \n                if(d[j] != numeric_limits<T>::max() && d[e.to] > d[j] + e.cost)\
    \ {\r\n                    d[e.to] = d[j] + e.cost;\r\n\r\n                  \
    \  // n \u56DE\u76EE\u306B\u3082\u66F4\u65B0\u304C\u3042\u308B\u306A\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\r\n                    if(i ==\
    \ V - 1) return true;\r\n                }\r\n            }\r\n        }\r\n \
    \   }\r\n    return false;\r\n}\r\n\r\n// \u30B0\u30E9\u30D5\u5168\u4F53\u3092\
    \u898B\u3066\u3001\u8CA0\u306E\u9589\u8DEF\u304C\u3042\u308B\u304B\u3069\u3046\
    \u304B\u3092\u691C\u51FA\u3059\u308B\r\ntemplate <typename T>\r\nbool find_negative_loop_whole(vector<\
    \ vector< Edge<T> > > &G) {\r\n    int V = G.size();\r\n    vector<T> d(V);\r\n\
    \    fill(d.begin(), d.end(), 0);\r\n    for(int i=0; i<V; i++) {\r\n        for(int\
    \ j=0; j<V; j++) {\r\n            for(int k=0; k<G[j].size(); k++) {\r\n     \
    \           Edge<T> e = G[j][k];\r\n                if(d[e.to] > d[j] + e.cost)\
    \ {\r\n                    d[e.to] = d[j] + e.cost;\r\n\r\n                  \
    \  // n \u56DE\u76EE\u306B\u3082\u66F4\u65B0\u304C\u3042\u308B\u306A\u3089\u8CA0\
    \u306E\u9589\u8DEF\u304C\u5B58\u5728\u3059\u308B\r\n                    if(i ==\
    \ V - 1) return true;\r\n                }\r\n            }\r\n        }\r\n \
    \   }\r\n    return false;\r\n}\r\n\r\n// \u9802\u70B9\u306E\u6570V, \u8FBA\u306E\
    \u6570E\u306E\u30B0\u30E9\u30D5\u306B\u304A\u3044\u3066\u3001 s \u756A\u76EE\u306E\
    \u9802\u70B9\u304B\u3089\u5404\u9802\u70B9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B\r\ntemplate <typename T>\r\nvector<T> bellman(vector<\
    \ vector< Edge<T> > > &G, int s) {\r\n    // \u9802\u70B9\u306E\u6570\u3068\u8FBA\
    \u306E\u6570\u3092\u6570\u3048\u308B\r\n    int V = G.size();\r\n    vector<T>\
    \ d(V);\r\n    for(int i=0; i<V; i++) d[i] = numeric_limits<T>::max();\r\n   \
    \ d[s] = 0;\r\n\r\n    while(true) {\r\n        bool update = false;\r\n     \
    \   for(int i=0; i<V; i++) {\r\n            for(int j=0; j<G[i].size(); j++) {\r\
    \n                Edge<T> e = G[i][j];\r\n                if(d[i] != numeric_limits<T>::max()\
    \ && d[e.to] > d[i] + e.cost) {\r\n                    d[e.to] = d[i] + e.cost;\r\
    \n                    update = true;\r\n                }\r\n            }\r\n\
    \        }\r\n        if(!update) break;\r\n    }\r\n    return d;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_001_bellman.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_001_bellman.cpp
layout: document
redirect_from:
- /library/graph/graph_001_bellman.cpp
- /library/graph/graph_001_bellman.cpp.html
title: graph/graph_001_bellman.cpp
---
