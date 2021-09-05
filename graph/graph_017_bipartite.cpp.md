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
  bundledCode: "#line 1 \"graph/graph_017_bipartite.cpp\"\n// \u4E8C\u90E8\u30DE\u30C3\
    \u30C1\u30F3\u30B0 (\u6700\u5927\u6D41\u3092\u4F7F\u3063\u3066\u89E3\u304F)\n\
    // \u30FB\u666E\u901A\u306B\u8FBA\u3092\u5F35\u308B\u4ED6\u306B\u3001\u81EA\u5206\
    \u3067\u5225\u306B\u9802\u70B9\u3092 2 \u3064\u7528\u610F\u3059\u308B\n\ntemplate\
    \ <typename T>\nstruct Edge {\n    int to; T cap, cost; int rev;\n    Edge(int\
    \ t, T c, int r) : to(t), cap(c), rev(r) {}\n    Edge(int t, T ca, T co, int r)\
    \ : to(t), cap(ca), cost(co), rev(r) {}\n};\n\ntemplate <typename T>\nusing Graph\
    \ = vector< vector< Edge<T> > >;\n\nstruct BipartiteMatching {\n    int S, T,\
    \ E, a, b;\n    vector< vector< Edge<int> > > G;\n    vector<int> used;\n    BipartiteMatching(int\
    \ x, int y, int z) : S(x), T(y), E(z) {\n        G.resize(S+T+2);\n        used.resize(S+T+2);\n\
    \        a = S + T, b = a + 1;\n        for(int i=0; i<S; i++) add_edge(a  , i,\
    \ 1);\n        for(int i=0; i<T; i++) add_edge(i+S, b, 1);\n    }\n    void add_edge(int\
    \ from, int to, int cap) {\n        G[from].push_back(Edge<int>(to  , cap, G[to\
    \  ].size()    ));\n        G[to  ].push_back(Edge<int>(from, 0  , G[from].size()\
    \ - 1));\n    }\n    void readGraph() {\n        for(int i=0; i<E; i++) {\n  \
    \          int x, y; cin >> x >> y;\n            // x--; y--;\n            add_edge(x,\
    \ y+S, 1);\n        }\n    }\n    int dfs(int v, int t, int f) {\n        if(v\
    \ == t) return f;\n        used[v] = true;\n        for(size_t i=0; i<G[v].size();\
    \ i++) {\n            Edge<int> &e = G[v][i];\n            if(!used[e.to] && e.cap\
    \ > 0) {\n                int d = dfs(e.to, t, min(f, e.cap));\n             \
    \   if(d > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    int solve() {\n        int flow = 0;\n\
    \        while(1) {\n            fill(used.begin(), used.end(), 0);\n        \
    \    int f = dfs(a, b, INF);\n            if(f == 0) return flow;\n          \
    \  flow += f;\n        }\n    }\n};\n\n/*\nsigned main() {\n    int x, y, e; cin\
    \ >> x >> y >> e;\n    BipartiteMatching B(x, y, e);\n    B.readGraph();\n   \
    \ cout << B.solve() << endl;\n    return 0;\n}\n*/\n"
  code: "// \u4E8C\u90E8\u30DE\u30C3\u30C1\u30F3\u30B0 (\u6700\u5927\u6D41\u3092\u4F7F\
    \u3063\u3066\u89E3\u304F)\n// \u30FB\u666E\u901A\u306B\u8FBA\u3092\u5F35\u308B\
    \u4ED6\u306B\u3001\u81EA\u5206\u3067\u5225\u306B\u9802\u70B9\u3092 2 \u3064\u7528\
    \u610F\u3059\u308B\n\ntemplate <typename T>\nstruct Edge {\n    int to; T cap,\
    \ cost; int rev;\n    Edge(int t, T c, int r) : to(t), cap(c), rev(r) {}\n   \
    \ Edge(int t, T ca, T co, int r) : to(t), cap(ca), cost(co), rev(r) {}\n};\n\n\
    template <typename T>\nusing Graph = vector< vector< Edge<T> > >;\n\nstruct BipartiteMatching\
    \ {\n    int S, T, E, a, b;\n    vector< vector< Edge<int> > > G;\n    vector<int>\
    \ used;\n    BipartiteMatching(int x, int y, int z) : S(x), T(y), E(z) {\n   \
    \     G.resize(S+T+2);\n        used.resize(S+T+2);\n        a = S + T, b = a\
    \ + 1;\n        for(int i=0; i<S; i++) add_edge(a  , i, 1);\n        for(int i=0;\
    \ i<T; i++) add_edge(i+S, b, 1);\n    }\n    void add_edge(int from, int to, int\
    \ cap) {\n        G[from].push_back(Edge<int>(to  , cap, G[to  ].size()    ));\n\
    \        G[to  ].push_back(Edge<int>(from, 0  , G[from].size() - 1));\n    }\n\
    \    void readGraph() {\n        for(int i=0; i<E; i++) {\n            int x,\
    \ y; cin >> x >> y;\n            // x--; y--;\n            add_edge(x, y+S, 1);\n\
    \        }\n    }\n    int dfs(int v, int t, int f) {\n        if(v == t) return\
    \ f;\n        used[v] = true;\n        for(size_t i=0; i<G[v].size(); i++) {\n\
    \            Edge<int> &e = G[v][i];\n            if(!used[e.to] && e.cap > 0)\
    \ {\n                int d = dfs(e.to, t, min(f, e.cap));\n                if(d\
    \ > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    int solve() {\n        int flow = 0;\n\
    \        while(1) {\n            fill(used.begin(), used.end(), 0);\n        \
    \    int f = dfs(a, b, INF);\n            if(f == 0) return flow;\n          \
    \  flow += f;\n        }\n    }\n};\n\n/*\nsigned main() {\n    int x, y, e; cin\
    \ >> x >> y >> e;\n    BipartiteMatching B(x, y, e);\n    B.readGraph();\n   \
    \ cout << B.solve() << endl;\n    return 0;\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_017_bipartite.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_017_bipartite.cpp
layout: document
redirect_from:
- /library/graph/graph_017_bipartite.cpp
- /library/graph/graph_017_bipartite.cpp.html
title: graph/graph_017_bipartite.cpp
---
