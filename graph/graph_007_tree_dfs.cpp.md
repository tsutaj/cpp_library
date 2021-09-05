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
  bundledCode: "#line 1 \"graph/graph_007_tree_dfs.cpp\"\n// \u6728\u306B\u5BFE\u3059\
    \u308BDFS (\u5BFE\u8C61\u3068\u306A\u308B\u9802\u70B9\u304B\u3089\u6700\u3082\u9060\
    \u3044\u9802\u70B9\u306E\u60C5\u5831\u3092\u8FD4\u3059)\n// n := (\u9802\u70B9\
    \u756A\u53F7, \u305D\u306E\u9802\u70B9\u307E\u3067\u306E\u30B3\u30B9\u30C8)\n\
    // Verified: AtCoder Regular Contest 022 C (\u30ED\u30DF\u30AA\u3068\u30B8\u30E5\
    \u30EA\u30A8\u30C3\u30C8)\n\n\n// \u6728\u306E\u4E2D\u5FC3\u3092\u6C42\u3081\u308B\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 O(|V|)\n// \u30FB\u307E\u305A\u306F\u3001\
    \u6728\u306E\u6700\u9060\u70B9\u5BFE\u3068\u3001\u3053\u306E 2 \u70B9\u304B\u3089\
    \u4EFB\u610F\u306E\u70B9\u3068\u306E\u8DDD\u96E2\u3092\u305D\u308C\u305E\u308C\
    \u6C42\u3081\u308B\n// \u30FB\u6728\u306E\u4E2D\u5FC3\u3068\u306F\u3001\u9802\u70B9\
    \ u \u304B\u3089\u4EFB\u610F\u306E\u9802\u70B9 x \u307E\u3067\u306E\u6700\u77ED\
    \u8DDD\u96E2\u306E\u6700\u5927\u5024\u3092\u6700\u5C0F\u5316\u3059\u308B\u9802\
    \u70B9 u \u3067\u3042\u308B\n//   -> \u3053\u308C\u306F\u3001\u6728\u306E\u76F4\
    \u5F84\u306E\u771F\u3093\u4E2D\u306E\u70B9\u306B\u5F53\u305F\u308B\u306E\u3067\
    \u3001\u8A72\u5F53\u3059\u308B\u70B9\u3092 vector \u306B\u8FFD\u52A0\u3059\u308B\
    \n// \u30FB\u6728\u306E\u4E2D\u5FC3\u306F\u9AD8\u3005 2 \u500B\u3067\u3042\u308B\
    \n\ntemplate <typename T>\nvoid dfs(int p, vector< vector< Edge<T> > > &G, vector<T>\
    \ &dist) {\n    if(dist[p] == -1) dist[p] = 0;\n    int cur = dist[p];\n    for(size_t\
    \ i=0; i<G[p].size(); i++) {\n        int to = G[p][i].to; T cost = G[p][i].cost;\n\
    \        if(dist[to] != -1) continue;\n        dist[to] = cur + cost;\n      \
    \  dfs(to, G, dist);\n    }\n}\n\ntemplate <typename T>\nvector<int> getCenters(vector<\
    \ vector< Edge<T> > > &G) {\n    int n = (int)G.size();\n    vector<T> d0(n, -1),\
    \ d1(n, -1), d2(n, -1);\n    dfs(0, G, d0);\n    int p1 = max_element(d0.begin(),\
    \ d0.end()) - d0.begin();\n    dfs(p1, G, d1);\n    int p2 = max_element(d1.begin(),\
    \ d1.end()) - d1.begin();\n    dfs(p2, G, d2);\n\n    vector<int> ret;\n    T\
    \ diameter = d2[p1];\n    for(int i=0; i<n; i++) {\n        bool b1 = (d1[i] +\
    \ d2[i] == diameter);\n        bool b2 = (d1[i] == diameter / 2 || d2[i] == diameter\
    \ / 2);\n        if(b1 && b2) ret.push_back(i);\n    }\n    return ret;\n}\n\n\
    // \u6728\u306E\u76F4\u5F84\u306E\u7AEF\u70B9\u3092\u6C42\u3081\u308B\ntemplate\
    \ <typename T>\ntuple<int, int, T> diameter(vector< vector< Edge<T> > > &G) {\n\
    \    int n = (int)G.size();\n    vector<T> d0(n, -1), d1(n, -1);\n    dfs(0, G,\
    \ d0);\n    int p1 = max_element(d0.begin(), d0.end()) - d0.begin();\n    dfs(p1,\
    \ G, d1);\n    int p2 = max_element(d1.begin(), d1.end()) - d1.begin();\n    T\
    \ d = *max_element(d1.begin(), d1.end());\n    return make_tuple(p1, p2, d);\n\
    }\n"
  code: "// \u6728\u306B\u5BFE\u3059\u308BDFS (\u5BFE\u8C61\u3068\u306A\u308B\u9802\
    \u70B9\u304B\u3089\u6700\u3082\u9060\u3044\u9802\u70B9\u306E\u60C5\u5831\u3092\
    \u8FD4\u3059)\n// n := (\u9802\u70B9\u756A\u53F7, \u305D\u306E\u9802\u70B9\u307E\
    \u3067\u306E\u30B3\u30B9\u30C8)\n// Verified: AtCoder Regular Contest 022 C (\u30ED\
    \u30DF\u30AA\u3068\u30B8\u30E5\u30EA\u30A8\u30C3\u30C8)\n\n\n// \u6728\u306E\u4E2D\
    \u5FC3\u3092\u6C42\u3081\u308B\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 O(|V|)\n//\
    \ \u30FB\u307E\u305A\u306F\u3001\u6728\u306E\u6700\u9060\u70B9\u5BFE\u3068\u3001\
    \u3053\u306E 2 \u70B9\u304B\u3089\u4EFB\u610F\u306E\u70B9\u3068\u306E\u8DDD\u96E2\
    \u3092\u305D\u308C\u305E\u308C\u6C42\u3081\u308B\n// \u30FB\u6728\u306E\u4E2D\u5FC3\
    \u3068\u306F\u3001\u9802\u70B9 u \u304B\u3089\u4EFB\u610F\u306E\u9802\u70B9 x\
    \ \u307E\u3067\u306E\u6700\u77ED\u8DDD\u96E2\u306E\u6700\u5927\u5024\u3092\u6700\
    \u5C0F\u5316\u3059\u308B\u9802\u70B9 u \u3067\u3042\u308B\n//   -> \u3053\u308C\
    \u306F\u3001\u6728\u306E\u76F4\u5F84\u306E\u771F\u3093\u4E2D\u306E\u70B9\u306B\
    \u5F53\u305F\u308B\u306E\u3067\u3001\u8A72\u5F53\u3059\u308B\u70B9\u3092 vector\
    \ \u306B\u8FFD\u52A0\u3059\u308B\n// \u30FB\u6728\u306E\u4E2D\u5FC3\u306F\u9AD8\
    \u3005 2 \u500B\u3067\u3042\u308B\n\ntemplate <typename T>\nvoid dfs(int p, vector<\
    \ vector< Edge<T> > > &G, vector<T> &dist) {\n    if(dist[p] == -1) dist[p] =\
    \ 0;\n    int cur = dist[p];\n    for(size_t i=0; i<G[p].size(); i++) {\n    \
    \    int to = G[p][i].to; T cost = G[p][i].cost;\n        if(dist[to] != -1) continue;\n\
    \        dist[to] = cur + cost;\n        dfs(to, G, dist);\n    }\n}\n\ntemplate\
    \ <typename T>\nvector<int> getCenters(vector< vector< Edge<T> > > &G) {\n   \
    \ int n = (int)G.size();\n    vector<T> d0(n, -1), d1(n, -1), d2(n, -1);\n   \
    \ dfs(0, G, d0);\n    int p1 = max_element(d0.begin(), d0.end()) - d0.begin();\n\
    \    dfs(p1, G, d1);\n    int p2 = max_element(d1.begin(), d1.end()) - d1.begin();\n\
    \    dfs(p2, G, d2);\n\n    vector<int> ret;\n    T diameter = d2[p1];\n    for(int\
    \ i=0; i<n; i++) {\n        bool b1 = (d1[i] + d2[i] == diameter);\n        bool\
    \ b2 = (d1[i] == diameter / 2 || d2[i] == diameter / 2);\n        if(b1 && b2)\
    \ ret.push_back(i);\n    }\n    return ret;\n}\n\n// \u6728\u306E\u76F4\u5F84\u306E\
    \u7AEF\u70B9\u3092\u6C42\u3081\u308B\ntemplate <typename T>\ntuple<int, int, T>\
    \ diameter(vector< vector< Edge<T> > > &G) {\n    int n = (int)G.size();\n   \
    \ vector<T> d0(n, -1), d1(n, -1);\n    dfs(0, G, d0);\n    int p1 = max_element(d0.begin(),\
    \ d0.end()) - d0.begin();\n    dfs(p1, G, d1);\n    int p2 = max_element(d1.begin(),\
    \ d1.end()) - d1.begin();\n    T d = *max_element(d1.begin(), d1.end());\n   \
    \ return make_tuple(p1, p2, d);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_007_tree_dfs.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_007_tree_dfs.cpp
layout: document
redirect_from:
- /library/graph/graph_007_tree_dfs.cpp
- /library/graph/graph_007_tree_dfs.cpp.html
title: graph/graph_007_tree_dfs.cpp
---
