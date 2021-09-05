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
  bundledCode: "#line 1 \"graph/graph_015_forest2trees.cpp\"\n// \u68EE\u3092\u6728\
    \u306E vector \u306B\u5206\u89E3\u3059\u308B (\u7121\u5411) O(|V|)\n// \u30FB\u307E\
    \u3060\u30C1\u30A7\u30C3\u30AF\u3057\u3066\u3044\u306A\u3044\u9802\u70B9\u306B\
    \u95A2\u3057\u3066\u3001\u305D\u306E\u9802\u70B9\u304B\u3089 BFS \u3092\u884C\u3046\
    \n// \u30FB\u9802\u70B9\u756A\u53F7\u3092\u632F\u308A\u76F4\u3057\u306A\u304C\u3089\
    \u8FBA\u3092\u5F35\u3063\u3066\u3044\u304F\n\ntemplate <typename T>\nusing Graph\
    \ = vector< vector< Edge<T> > >;\n\ntemplate <typename T>\nGraph<T> Forest2Trees(Graph<T>\
    \ &G) {\n    int n = (int)G.size();\n    vector<int> vtxid(n, -1);\n\n    vector<\
    \ Graph<T> > ret;\n    for(int i=0; i<n; i++) {\n        if(vtxid[i] >= 0) continue;\n\
    \        Graph<T> Tree(1);\n        int cur = 0;\n        vtxid[i] = cur++;\n\n\
    \        queue<int> q; q.push(i);\n        while(!q.empty()) {\n            int\
    \ k = q.front(); q.pop();\n            for(size_t x=0; x<G[k].size(); x++) {\n\
    \                int to = G[k][x].to; T cost = G[k][x].cost;\n               \
    \ if(vtxid[to] >= 0) continue;\n                vtxid[to] = cur++;\n         \
    \       Tree.push_back(vector< Edge<T> >());\n                Tree[ vtxid[k ]\
    \ ].push_back( Edge<T>(vtxid[to], cost) );\n                Tree[ vtxid[to] ].push_back(\
    \ Edge<T>(vtxid[k ], cost) );\n                q.push(to);\n            }\n  \
    \      }\n        ret.push_back(Tree);\n    }\n    return ret;\n}\n"
  code: "// \u68EE\u3092\u6728\u306E vector \u306B\u5206\u89E3\u3059\u308B (\u7121\
    \u5411) O(|V|)\n// \u30FB\u307E\u3060\u30C1\u30A7\u30C3\u30AF\u3057\u3066\u3044\
    \u306A\u3044\u9802\u70B9\u306B\u95A2\u3057\u3066\u3001\u305D\u306E\u9802\u70B9\
    \u304B\u3089 BFS \u3092\u884C\u3046\n// \u30FB\u9802\u70B9\u756A\u53F7\u3092\u632F\
    \u308A\u76F4\u3057\u306A\u304C\u3089\u8FBA\u3092\u5F35\u3063\u3066\u3044\u304F\
    \n\ntemplate <typename T>\nusing Graph = vector< vector< Edge<T> > >;\n\ntemplate\
    \ <typename T>\nGraph<T> Forest2Trees(Graph<T> &G) {\n    int n = (int)G.size();\n\
    \    vector<int> vtxid(n, -1);\n\n    vector< Graph<T> > ret;\n    for(int i=0;\
    \ i<n; i++) {\n        if(vtxid[i] >= 0) continue;\n        Graph<T> Tree(1);\n\
    \        int cur = 0;\n        vtxid[i] = cur++;\n\n        queue<int> q; q.push(i);\n\
    \        while(!q.empty()) {\n            int k = q.front(); q.pop();\n      \
    \      for(size_t x=0; x<G[k].size(); x++) {\n                int to = G[k][x].to;\
    \ T cost = G[k][x].cost;\n                if(vtxid[to] >= 0) continue;\n     \
    \           vtxid[to] = cur++;\n                Tree.push_back(vector< Edge<T>\
    \ >());\n                Tree[ vtxid[k ] ].push_back( Edge<T>(vtxid[to], cost)\
    \ );\n                Tree[ vtxid[to] ].push_back( Edge<T>(vtxid[k ], cost) );\n\
    \                q.push(to);\n            }\n        }\n        ret.push_back(Tree);\n\
    \    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_015_forest2trees.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_015_forest2trees.cpp
layout: document
redirect_from:
- /library/graph/graph_015_forest2trees.cpp
- /library/graph/graph_015_forest2trees.cpp.html
title: graph/graph_015_forest2trees.cpp
---
