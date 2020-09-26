---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_010_scc.cpp\"\n// \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\n// Verified: AOJ GRL_3_C (Strongly Connected Components)\n// Verified:\
    \ ARC030 C (\u6709\u5411\u30B0\u30E9\u30D5) \u2190 \u5F37\u9023\u7D50\u3092\u6F70\
    \u3057\u305F\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\u306E\u691C\u8A3C\n\n// \u3053\
    \u308C\u306F 2 \u56DE\u306E DFS \u306B\u3088\u3063\u3066\u5B9F\u73FE\u3067\u304D\
    \u308B\u3002\n// \u306F\u3058\u3081\u306B\u666E\u901A\u306E DFS \u3092\u3059\u308B\
    \u304C\u3001\u305D\u306E\u6642\u306B\u5E30\u308A\u304C\u3051\u9806\u306B\u9802\
    \u70B9\u756A\u53F7\u306E\u914D\u5217\u3092\u4F5C\u308B\u3002\n// \u6B21\u306B\u3001\
    \u5143\u306E\u30B0\u30E9\u30D5\u306E\u9006\u8FBA\u306E\u307F\u3067\u69CB\u6210\
    \u3055\u308C\u305F\u30B0\u30E9\u30D5\u306B\u5BFE\u3057\u3066\u3001\n// \u5E30\u308A\
    \u304C\u3051\u9806\u304C\u9045\u304B\u3063\u305F\u3082\u306E\u304B\u3089\u9806\
    \u306B DFS \u3092\u884C\u3046\u3002\n// \u5E30\u308A\u304B\u3051\u304C\u9045\u304B\
    \u3063\u305F\u9802\u70B9\u307B\u3069\u3001 DAG \u306E\u5148\u982D\u306E\u5F37\u9023\
    \u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\u308B\u305F\u3081\u3001\n// \u8FBA\
    \u3092\u9006\u5411\u304D\u306B\u3059\u308B\u3068\u3001\u5148\u982D\u306E\u5F37\
    \u9023\u7D50\u6210\u5206\u304B\u3089\u5916\u306B\u51FA\u3089\u308C\u306A\u304F\
    \u306A\u308B\u3053\u3068\u3092\u5229\u7528\u3057\u3066\u3044\u308B\u3002\n\ntemplate\
    \ <typename T = int>\nstruct GraphSCC {\npublic:\n    const int n;\n    vector<bool>\
    \ isthrough;\n    vector<int> vs, cmp;\n    vector< vector<int> > G, rG, H; //\
    \ \u30B0\u30E9\u30D5\u3001\u9006\u8FBA\u30B0\u30E9\u30D5\u3001\u7E2E\u7D04\u5F8C\
    \u306E\u30B0\u30E9\u30D5\n\n    GraphSCC(vector< vector< Edge<T> > > &g) :\n \
    \       n(g.size()), isthrough(n, false), cmp(n, 0), G(n), rG(n) {\n        for(int\
    \ i=0; i<n; i++) {\n            for(size_t j=0; j<g[i].size(); j++) {\n      \
    \          G[i].push_back(g[i][j].to);\n                rG[ g[i][j].to ].push_back(i);\n\
    \            }\n        }\n    }\n\n    void SCC_dfsone(int cur) {\n        isthrough[cur]\
    \ = true;\n        for(size_t i=0; i<G[cur].size(); i++) {\n            if(!isthrough[G[cur][i]])\
    \ {\n                SCC_dfsone(G[cur][i]);\n            }\n        }\n      \
    \  vs.push_back(cur);\n    }\n\n    void SCC_dfstwo(vector<int> &vec, int cur,\
    \ int k) {\n        cmp[cur] = k;\n        isthrough[cur] = true;\n        vec.push_back(cur);\n\
    \        for(size_t i=0; i<rG[cur].size(); i++) {\n            if(!isthrough[rG[cur][i]])\
    \ {\n                SCC_dfstwo(vec, rG[cur][i], k);\n            }\n        }\n\
    \    }\n\n    // \u7E2E\u7D04\u5F8C\u306E\u30B0\u30EB\u30FC\u30D7\u3001\u30B0\u30EB\
    \u30FC\u30D7\u6570\n    pair<vector<int>, int> scc() {\n        // 1\u56DE\u3081\
    \u306EDFS\n        for(int i=0; i<n; i++)\n            if(!isthrough[i]) SCC_dfsone(i);\n\
    \n        fill(isthrough.begin(), isthrough.end(), false);\n        reverse(vs.begin(),\
    \ vs.end());\n        int k = 0; vector< vector<int> > S;\n\n        // 2\u56DE\
    \u3081\u306EDFS\n        for(size_t i=0; i<vs.size(); i++) {\n            if(!isthrough[vs[i]])\
    \ {\n                S.push_back(vector<int>());\n                SCC_dfstwo(S.back(),\
    \ vs[i], k++);\n            }\n        }\n\n        H.resize(k);\n        fill(isthrough.begin(),\
    \ isthrough.end(), false);\n        for(size_t i=0; i<k; i++) {\n            for(size_t\
    \ j=0; j<S[i].size(); j++) {\n                int v = S[i][j];\n             \
    \   for(size_t x=0; x<G[v].size(); x++) {\n                    int u = G[v][x];\n\
    \                    if(isthrough[cmp[u]] || cmp[v] == cmp[u]) continue;\n   \
    \                 isthrough[cmp[u]] = true;\n                    H[cmp[v]].push_back(cmp[u]);\n\
    \                }\n            }\n            for(size_t j=0; j<H[i].size();\
    \ j++) isthrough[ H[i][j] ] = false;\n        }\n        return make_pair(cmp,\
    \ k);\n    }\n};\n"
  code: "// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n// Verified: AOJ GRL_3_C (Strongly\
    \ Connected Components)\n// Verified: ARC030 C (\u6709\u5411\u30B0\u30E9\u30D5\
    ) \u2190 \u5F37\u9023\u7D50\u3092\u6F70\u3057\u305F\u30B0\u30E9\u30D5\u306E\u69CB\
    \u7BC9\u306E\u691C\u8A3C\n\n// \u3053\u308C\u306F 2 \u56DE\u306E DFS \u306B\u3088\
    \u3063\u3066\u5B9F\u73FE\u3067\u304D\u308B\u3002\n// \u306F\u3058\u3081\u306B\u666E\
    \u901A\u306E DFS \u3092\u3059\u308B\u304C\u3001\u305D\u306E\u6642\u306B\u5E30\u308A\
    \u304C\u3051\u9806\u306B\u9802\u70B9\u756A\u53F7\u306E\u914D\u5217\u3092\u4F5C\
    \u308B\u3002\n// \u6B21\u306B\u3001\u5143\u306E\u30B0\u30E9\u30D5\u306E\u9006\u8FBA\
    \u306E\u307F\u3067\u69CB\u6210\u3055\u308C\u305F\u30B0\u30E9\u30D5\u306B\u5BFE\
    \u3057\u3066\u3001\n// \u5E30\u308A\u304C\u3051\u9806\u304C\u9045\u304B\u3063\u305F\
    \u3082\u306E\u304B\u3089\u9806\u306B DFS \u3092\u884C\u3046\u3002\n// \u5E30\u308A\
    \u304B\u3051\u304C\u9045\u304B\u3063\u305F\u9802\u70B9\u307B\u3069\u3001 DAG \u306E\
    \u5148\u982D\u306E\u5F37\u9023\u7D50\u6210\u5206\u306B\u5C5E\u3057\u3066\u3044\
    \u308B\u305F\u3081\u3001\n// \u8FBA\u3092\u9006\u5411\u304D\u306B\u3059\u308B\u3068\
    \u3001\u5148\u982D\u306E\u5F37\u9023\u7D50\u6210\u5206\u304B\u3089\u5916\u306B\
    \u51FA\u3089\u308C\u306A\u304F\u306A\u308B\u3053\u3068\u3092\u5229\u7528\u3057\
    \u3066\u3044\u308B\u3002\n\ntemplate <typename T = int>\nstruct GraphSCC {\npublic:\n\
    \    const int n;\n    vector<bool> isthrough;\n    vector<int> vs, cmp;\n   \
    \ vector< vector<int> > G, rG, H; // \u30B0\u30E9\u30D5\u3001\u9006\u8FBA\u30B0\
    \u30E9\u30D5\u3001\u7E2E\u7D04\u5F8C\u306E\u30B0\u30E9\u30D5\n\n    GraphSCC(vector<\
    \ vector< Edge<T> > > &g) :\n        n(g.size()), isthrough(n, false), cmp(n,\
    \ 0), G(n), rG(n) {\n        for(int i=0; i<n; i++) {\n            for(size_t\
    \ j=0; j<g[i].size(); j++) {\n                G[i].push_back(g[i][j].to);\n  \
    \              rG[ g[i][j].to ].push_back(i);\n            }\n        }\n    }\n\
    \n    void SCC_dfsone(int cur) {\n        isthrough[cur] = true;\n        for(size_t\
    \ i=0; i<G[cur].size(); i++) {\n            if(!isthrough[G[cur][i]]) {\n    \
    \            SCC_dfsone(G[cur][i]);\n            }\n        }\n        vs.push_back(cur);\n\
    \    }\n\n    void SCC_dfstwo(vector<int> &vec, int cur, int k) {\n        cmp[cur]\
    \ = k;\n        isthrough[cur] = true;\n        vec.push_back(cur);\n        for(size_t\
    \ i=0; i<rG[cur].size(); i++) {\n            if(!isthrough[rG[cur][i]]) {\n  \
    \              SCC_dfstwo(vec, rG[cur][i], k);\n            }\n        }\n   \
    \ }\n\n    // \u7E2E\u7D04\u5F8C\u306E\u30B0\u30EB\u30FC\u30D7\u3001\u30B0\u30EB\
    \u30FC\u30D7\u6570\n    pair<vector<int>, int> scc() {\n        // 1\u56DE\u3081\
    \u306EDFS\n        for(int i=0; i<n; i++)\n            if(!isthrough[i]) SCC_dfsone(i);\n\
    \n        fill(isthrough.begin(), isthrough.end(), false);\n        reverse(vs.begin(),\
    \ vs.end());\n        int k = 0; vector< vector<int> > S;\n\n        // 2\u56DE\
    \u3081\u306EDFS\n        for(size_t i=0; i<vs.size(); i++) {\n            if(!isthrough[vs[i]])\
    \ {\n                S.push_back(vector<int>());\n                SCC_dfstwo(S.back(),\
    \ vs[i], k++);\n            }\n        }\n\n        H.resize(k);\n        fill(isthrough.begin(),\
    \ isthrough.end(), false);\n        for(size_t i=0; i<k; i++) {\n            for(size_t\
    \ j=0; j<S[i].size(); j++) {\n                int v = S[i][j];\n             \
    \   for(size_t x=0; x<G[v].size(); x++) {\n                    int u = G[v][x];\n\
    \                    if(isthrough[cmp[u]] || cmp[v] == cmp[u]) continue;\n   \
    \                 isthrough[cmp[u]] = true;\n                    H[cmp[v]].push_back(cmp[u]);\n\
    \                }\n            }\n            for(size_t j=0; j<H[i].size();\
    \ j++) isthrough[ H[i][j] ] = false;\n        }\n        return make_pair(cmp,\
    \ k);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_010_scc.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_010_scc.cpp
layout: document
redirect_from:
- /library/graph/graph_010_scc.cpp
- /library/graph/graph_010_scc.cpp.html
title: graph/graph_010_scc.cpp
---
