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
  bundledCode: "#line 1 \"graph/graph_023_offline_lca.cpp\"\n// Tarjan's off-line\
    \ LCA algorithm\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\u30E9\u30EA\n// \u30FB\u30B0\
    \u30E9\u30D5\u8FBA\u69CB\u9020\u4F53 (graph_000_basic.cpp)\n\nstruct OfflineLCA\
    \ {\n    Graph<> G;\n    vector<int> node, anc, color, answers;\n    vector< vector<\
    \ pair<int, int> > > queries;\n    int find(int k) { return node[k] < 0 ? k :\
    \ find(node[k]); }\n    int size(int k) { return -node[find(k)]; }\n    void unite(int\
    \ u, int v) {\n        u = find(u), v = find(v);\n        if(u == v) return;\n\
    \        if(size(u) < size(v)) swap(u, v);\n        node[u] += node[v];\n    \
    \    node[v] = u;\n    }\n\n    void build(int cur, int par=-1) {\n        anc[cur]\
    \ = cur;\n        for(auto e : G[cur]) {\n            if(e.to == par) continue;\n\
    \            build(e.to, cur);\n            unite(e.to, cur);\n            anc[find(cur)]\
    \ = cur;\n        }\n        color[cur] = 1;\n        for(auto q : queries[cur])\
    \ {\n            int to, idx; tie(to, idx) = q;\n            if(color[to] == 1)\
    \ {\n                int lca = anc[find(to)];\n                answers[idx] =\
    \ lca;\n            }\n        }\n    }\n    \n    OfflineLCA(Graph<> G, vector<\
    \ pair<int, int> > Q, int root=0) : G(G) {\n        size_t N = G.size(), M = Q.size();\n\
    \        node = anc = color = vector<int>(N);\n        fill(node.begin(), node.end(),\
    \ -1);\n\n        queries.resize(N); answers.resize(M);\n        for(size_t i=0;\
    \ i<M; i++) {\n            int u, v; tie(u, v) = Q[i];\n            queries[u].emplace_back(v,\
    \ i);\n            queries[v].emplace_back(u, i);\n        }\n        build(root);\n\
    \    }\n\n    int& operator[] (int k) { return answers[k]; }\n};\n"
  code: "// Tarjan's off-line LCA algorithm\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\u30E9\
    \u30EA\n// \u30FB\u30B0\u30E9\u30D5\u8FBA\u69CB\u9020\u4F53 (graph_000_basic.cpp)\n\
    \nstruct OfflineLCA {\n    Graph<> G;\n    vector<int> node, anc, color, answers;\n\
    \    vector< vector< pair<int, int> > > queries;\n    int find(int k) { return\
    \ node[k] < 0 ? k : find(node[k]); }\n    int size(int k) { return -node[find(k)];\
    \ }\n    void unite(int u, int v) {\n        u = find(u), v = find(v);\n     \
    \   if(u == v) return;\n        if(size(u) < size(v)) swap(u, v);\n        node[u]\
    \ += node[v];\n        node[v] = u;\n    }\n\n    void build(int cur, int par=-1)\
    \ {\n        anc[cur] = cur;\n        for(auto e : G[cur]) {\n            if(e.to\
    \ == par) continue;\n            build(e.to, cur);\n            unite(e.to, cur);\n\
    \            anc[find(cur)] = cur;\n        }\n        color[cur] = 1;\n     \
    \   for(auto q : queries[cur]) {\n            int to, idx; tie(to, idx) = q;\n\
    \            if(color[to] == 1) {\n                int lca = anc[find(to)];\n\
    \                answers[idx] = lca;\n            }\n        }\n    }\n    \n\
    \    OfflineLCA(Graph<> G, vector< pair<int, int> > Q, int root=0) : G(G) {\n\
    \        size_t N = G.size(), M = Q.size();\n        node = anc = color = vector<int>(N);\n\
    \        fill(node.begin(), node.end(), -1);\n\n        queries.resize(N); answers.resize(M);\n\
    \        for(size_t i=0; i<M; i++) {\n            int u, v; tie(u, v) = Q[i];\n\
    \            queries[u].emplace_back(v, i);\n            queries[v].emplace_back(u,\
    \ i);\n        }\n        build(root);\n    }\n\n    int& operator[] (int k) {\
    \ return answers[k]; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_023_offline_lca.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_023_offline_lca.cpp
layout: document
redirect_from:
- /library/graph/graph_023_offline_lca.cpp
- /library/graph/graph_023_offline_lca.cpp.html
title: graph/graph_023_offline_lca.cpp
---
