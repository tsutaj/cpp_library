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
  bundledCode: "#line 1 \"graph/graph_011_lca.cpp\"\n// \u6700\u5C0F\u5171\u901A\u5148\
    \u7956 (Lowest Common Ancestor, LCA) \u3092\u6C42\u3081\u308B\n// Verified: AOJ\
    \ GRL_5_C (Lowest Common Ancestor)\n\ntemplate <typename T>\nstruct TreeLCA {\n\
    public:\n    int const MAX_LOG_V;\n    vector< vector< Edge<T> > > G;\n    int\
    \ root, vn;\n    vector< vector<int> > parent;\n    vector<int> depth;\n\n   \
    \ // constructor (Graph, root)\n    TreeLCA(vector< vector< Edge<T> > > &_G, int\
    \ _r) : \n        MAX_LOG_V(35), G(_G), root(_r), vn(G.size()), \n        parent(MAX_LOG_V,\
    \ vector<int>(vn, 0)), depth(vn, -1)\n        { depth[root] = 0; init(vn); }\n\
    \n    void dfs(int v, int p, int d) {\n        parent[0][v] = p;\n        depth[v]\
    \ = d;\n        for(int i=0; i<G[v].size(); i++) {\n            if(depth[ G[v][i].to\
    \ ] >= 0) continue;\n            if(G[v][i].to != p) dfs(G[v][i].to, v, d+1);\n\
    \        }\n    }\n\n    void init(int V) {\n        dfs(root, -1, 0);\n     \
    \   for(int k=0; k+1 < MAX_LOG_V; k++) {\n            for(int v=0; v < V; v++)\
    \ {\n                if(parent[k][v] < 0) parent[k+1][v] = -1;\n             \
    \   else parent[k+1][v] = parent[k][parent[k][v]];\n            }\n        }\n\
    \    }\n\n    // u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\u7956\u5148\n    int\
    \ lca(int u, int v) {\n        if(depth[u] > depth[v]) swap(u, v);\n        for(int\
    \ k=0; k < MAX_LOG_V; k++) {\n            if((depth[v] - depth[u]) >> k & 1) {\n\
    \                v = parent[k][v];\n            }\n        }\n        if(u ==\
    \ v) return u;\n        for(int k=MAX_LOG_V - 1; k>=0; k--) {\n            if(parent[k][u]\
    \ != parent[k][v]) {\n                u = parent[k][u];\n                v = parent[k][v];\n\
    \            }\n        }\n        return parent[0][u];\n    }\n\n    // u \u3068\
    \ v \u306E\u30D1\u30B9\u306E\u9577\u3055 (LCA \u3092\u4F7F\u3063\u3066\u8A08\u7B97\
    )\n    int dist(int u, int v) {\n        int anc = lca(u, v);\n        return\
    \ depth[u] + depth[v] - 2 * depth[anc];\n    }\n};\n"
  code: "// \u6700\u5C0F\u5171\u901A\u5148\u7956 (Lowest Common Ancestor, LCA) \u3092\
    \u6C42\u3081\u308B\n// Verified: AOJ GRL_5_C (Lowest Common Ancestor)\n\ntemplate\
    \ <typename T>\nstruct TreeLCA {\npublic:\n    int const MAX_LOG_V;\n    vector<\
    \ vector< Edge<T> > > G;\n    int root, vn;\n    vector< vector<int> > parent;\n\
    \    vector<int> depth;\n\n    // constructor (Graph, root)\n    TreeLCA(vector<\
    \ vector< Edge<T> > > &_G, int _r) : \n        MAX_LOG_V(35), G(_G), root(_r),\
    \ vn(G.size()), \n        parent(MAX_LOG_V, vector<int>(vn, 0)), depth(vn, -1)\n\
    \        { depth[root] = 0; init(vn); }\n\n    void dfs(int v, int p, int d) {\n\
    \        parent[0][v] = p;\n        depth[v] = d;\n        for(int i=0; i<G[v].size();\
    \ i++) {\n            if(depth[ G[v][i].to ] >= 0) continue;\n            if(G[v][i].to\
    \ != p) dfs(G[v][i].to, v, d+1);\n        }\n    }\n\n    void init(int V) {\n\
    \        dfs(root, -1, 0);\n        for(int k=0; k+1 < MAX_LOG_V; k++) {\n   \
    \         for(int v=0; v < V; v++) {\n                if(parent[k][v] < 0) parent[k+1][v]\
    \ = -1;\n                else parent[k+1][v] = parent[k][parent[k][v]];\n    \
    \        }\n        }\n    }\n\n    // u \u3068 v \u306E\u6700\u5C0F\u5171\u901A\
    \u7956\u5148\n    int lca(int u, int v) {\n        if(depth[u] > depth[v]) swap(u,\
    \ v);\n        for(int k=0; k < MAX_LOG_V; k++) {\n            if((depth[v] -\
    \ depth[u]) >> k & 1) {\n                v = parent[k][v];\n            }\n  \
    \      }\n        if(u == v) return u;\n        for(int k=MAX_LOG_V - 1; k>=0;\
    \ k--) {\n            if(parent[k][u] != parent[k][v]) {\n                u =\
    \ parent[k][u];\n                v = parent[k][v];\n            }\n        }\n\
    \        return parent[0][u];\n    }\n\n    // u \u3068 v \u306E\u30D1\u30B9\u306E\
    \u9577\u3055 (LCA \u3092\u4F7F\u3063\u3066\u8A08\u7B97)\n    int dist(int u, int\
    \ v) {\n        int anc = lca(u, v);\n        return depth[u] + depth[v] - 2 *\
    \ depth[anc];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_011_lca.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_011_lca.cpp
layout: document
redirect_from:
- /library/graph/graph_011_lca.cpp
- /library/graph/graph_011_lca.cpp.html
title: graph/graph_011_lca.cpp
---
