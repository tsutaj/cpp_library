---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verifying_test/AOJ/GRL_5_D/hld.test.cpp
    title: verifying_test/AOJ/GRL_5_D/hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_020_HLDecomposition.cpp\"\n// HL \u5206\u89E3\
    \ (Heavy-Light Decomposition)\n// \u9802\u70B9 v \u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728: [ in[v], out[v] )\n// \u9802\u70B9 v \u304B\u3089\u898B\u305F\
    \ heavy edge chain \u306E\u982D: head[v]\nstruct HLD {\n    vector< vector<int>\
    \ > G;\n    vector<int> sub, par, depth, in, out, rev, head;\n    \n    void dfs_sub(int\
    \ cur) {\n        for(auto& to : G[cur]) {\n            if(par[cur] == to) continue;\n\
    \            par[to] = cur;\n            depth[to] = depth[cur] + 1;\n       \
    \     dfs_sub(to);\n            sub[cur] += sub[to];\n            if(sub[to] >\
    \ sub[ G[cur][0] ]) swap(to, G[cur][0]);\n        }\n    }\n    void dfs_hld(int\
    \ cur, int& ptr) {\n        in[cur] = ptr; rev[ptr++] = cur;\n        for(auto\
    \ to : G[cur]) {\n            if(par[cur] == to) continue;\n            head[to]\
    \ = (to == G[cur][0] ? head[cur] : to);\n            dfs_hld(to, ptr);\n     \
    \   }\n        out[cur] = ptr;\n    }\n\n    HLD(int N) : G(N), sub(N, 1), par(N,\
    \ -1), depth(N),\n                 in(N), out(N), rev(N), head(N) {}\n    void\
    \ add_edge(int u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    void build(int root=0) {\n        int ptr = 0; dfs_sub(root); dfs_hld(root,\
    \ ptr);\n    }\n    int lca(int u, int v) {\n        while(1) {\n            if(in[u]\
    \ > in[v]) swap(u, v);\n            if(head[u] == head[v]) return u;\n       \
    \     v = par[ head[v] ];\n        }\n    }\n    int distance(int u, int v) {\n\
    \        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    template\
    \ <typename F>\n    void proceed(int u, int v, const F& f, bool b) {\n       \
    \ for(; head[u] != head[v]; v = par[ head[v] ]) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            f(in[ head[v] ], in[v] + 1);\n        }\n        if(in[u]\
    \ > in[v]) swap(u, v);\n        f(in[u] + b, in[v] + 1);\n    }\n\n    // u -\
    \ v \u30D1\u30B9\u4E0A\u306B\u5B58\u5728\u3059\u308B\u300C\u9802\u70B9\u300Dor\u300C\
    \u8FBA\u300D\u5168\u4F53\u306B f(l, r) \u3092\u4F5C\u7528\n    // l, r \u306F\
    \ SegmentTree \u3068\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u4E0A\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n    template <typename F>\n    void apply_vertices(int\
    \ u, int v, const F& f) {\n        proceed(u, v, f, false);\n    }\n\n    template\
    \ <typename F>\n    void apply_edges(int u, int v, const F& f) {\n        proceed(u,\
    \ v, f, true);\n    }\n\n    template <typename T, typename F, typename M>\n \
    \   T proceed(int u, int v, T E, const F& f, const M& m, bool b) {\n        T\
    \ vl(E), vr(E);\n        for(; head[u] != head[v]; v = par[ head[v] ]) {\n   \
    \         if(in[u] > in[v]) swap(u, v), swap(vl, vr);\n            vr = m(f(in[\
    \ head[v] ], in[v] + 1), vr);\n        }\n        if(in[u] > in[v]) swap(u, v),\
    \ swap(vl, vr);\n        vr = m(f(in[u] + b, in[v] + 1), vr);\n        return\
    \ m(vl, vr);\n    }\n\n    // u - v \u30D1\u30B9\u4E0A\u306B\u5B58\u5728\u3059\
    \u308B\u300C\u9802\u70B9\u300Dor\u300C\u8FBA\u300D\u5168\u4F53\u306B\u5272\u308A\
    \u5F53\u3066\u3089\u308C\u305F\u5024\u3092\n    // \u5404 chunk \u306B\u5BFE\u3057\
    \u3066 f(l, r) \u3067\u5F97\u3066\u3001\u305D\u308C\u3089\u3092 m(vl, vr) \u3067\
    \ merge \u3057\u305F\u3082\u306E\u3092\u5F97\u308B\n    // \u5358\u4F4D\u5143\
    \ E \u3082\u6E21\u305D\u3046\n    template <typename T, typename F, typename M>\n\
    \    T query_vertices(int u, int v, T E, const F& f, const M& m) {\n        return\
    \ proceed(u, v, E, f, m, false);\n    }\n\n    template <typename T, typename\
    \ F, typename M>\n    T query_edges(int u, int v, T E, const F& f, const M& m)\
    \ {\n        return proceed(u, v, E, f, m, true);\n    }\n};\n"
  code: "// HL \u5206\u89E3 (Heavy-Light Decomposition)\n// \u9802\u70B9 v \u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728: [ in[v], out[v] )\n// \u9802\u70B9 v \u304B\
    \u3089\u898B\u305F heavy edge chain \u306E\u982D: head[v]\nstruct HLD {\n    vector<\
    \ vector<int> > G;\n    vector<int> sub, par, depth, in, out, rev, head;\n   \
    \ \n    void dfs_sub(int cur) {\n        for(auto& to : G[cur]) {\n          \
    \  if(par[cur] == to) continue;\n            par[to] = cur;\n            depth[to]\
    \ = depth[cur] + 1;\n            dfs_sub(to);\n            sub[cur] += sub[to];\n\
    \            if(sub[to] > sub[ G[cur][0] ]) swap(to, G[cur][0]);\n        }\n\
    \    }\n    void dfs_hld(int cur, int& ptr) {\n        in[cur] = ptr; rev[ptr++]\
    \ = cur;\n        for(auto to : G[cur]) {\n            if(par[cur] == to) continue;\n\
    \            head[to] = (to == G[cur][0] ? head[cur] : to);\n            dfs_hld(to,\
    \ ptr);\n        }\n        out[cur] = ptr;\n    }\n\n    HLD(int N) : G(N), sub(N,\
    \ 1), par(N, -1), depth(N),\n                 in(N), out(N), rev(N), head(N) {}\n\
    \    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    void build(int root=0) {\n        int ptr = 0; dfs_sub(root); dfs_hld(root,\
    \ ptr);\n    }\n    int lca(int u, int v) {\n        while(1) {\n            if(in[u]\
    \ > in[v]) swap(u, v);\n            if(head[u] == head[v]) return u;\n       \
    \     v = par[ head[v] ];\n        }\n    }\n    int distance(int u, int v) {\n\
    \        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\n    template\
    \ <typename F>\n    void proceed(int u, int v, const F& f, bool b) {\n       \
    \ for(; head[u] != head[v]; v = par[ head[v] ]) {\n            if(in[u] > in[v])\
    \ swap(u, v);\n            f(in[ head[v] ], in[v] + 1);\n        }\n        if(in[u]\
    \ > in[v]) swap(u, v);\n        f(in[u] + b, in[v] + 1);\n    }\n\n    // u -\
    \ v \u30D1\u30B9\u4E0A\u306B\u5B58\u5728\u3059\u308B\u300C\u9802\u70B9\u300Dor\u300C\
    \u8FBA\u300D\u5168\u4F53\u306B f(l, r) \u3092\u4F5C\u7528\n    // l, r \u306F\
    \ SegmentTree \u3068\u304B\u306E\u30C7\u30FC\u30BF\u69CB\u9020\u4E0A\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\n    template <typename F>\n    void apply_vertices(int\
    \ u, int v, const F& f) {\n        proceed(u, v, f, false);\n    }\n\n    template\
    \ <typename F>\n    void apply_edges(int u, int v, const F& f) {\n        proceed(u,\
    \ v, f, true);\n    }\n\n    template <typename T, typename F, typename M>\n \
    \   T proceed(int u, int v, T E, const F& f, const M& m, bool b) {\n        T\
    \ vl(E), vr(E);\n        for(; head[u] != head[v]; v = par[ head[v] ]) {\n   \
    \         if(in[u] > in[v]) swap(u, v), swap(vl, vr);\n            vr = m(f(in[\
    \ head[v] ], in[v] + 1), vr);\n        }\n        if(in[u] > in[v]) swap(u, v),\
    \ swap(vl, vr);\n        vr = m(f(in[u] + b, in[v] + 1), vr);\n        return\
    \ m(vl, vr);\n    }\n\n    // u - v \u30D1\u30B9\u4E0A\u306B\u5B58\u5728\u3059\
    \u308B\u300C\u9802\u70B9\u300Dor\u300C\u8FBA\u300D\u5168\u4F53\u306B\u5272\u308A\
    \u5F53\u3066\u3089\u308C\u305F\u5024\u3092\n    // \u5404 chunk \u306B\u5BFE\u3057\
    \u3066 f(l, r) \u3067\u5F97\u3066\u3001\u305D\u308C\u3089\u3092 m(vl, vr) \u3067\
    \ merge \u3057\u305F\u3082\u306E\u3092\u5F97\u308B\n    // \u5358\u4F4D\u5143\
    \ E \u3082\u6E21\u305D\u3046\n    template <typename T, typename F, typename M>\n\
    \    T query_vertices(int u, int v, T E, const F& f, const M& m) {\n        return\
    \ proceed(u, v, E, f, m, false);\n    }\n\n    template <typename T, typename\
    \ F, typename M>\n    T query_edges(int u, int v, T E, const F& f, const M& m)\
    \ {\n        return proceed(u, v, E, f, m, true);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_020_HLDecomposition.cpp
  requiredBy: []
  timestamp: '2022-01-28 01:38:40+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verifying_test/AOJ/GRL_5_D/hld.test.cpp
documentation_of: graph/graph_020_HLDecomposition.cpp
layout: document
redirect_from:
- /library/graph/graph_020_HLDecomposition.cpp
- /library/graph/graph_020_HLDecomposition.cpp.html
title: graph/graph_020_HLDecomposition.cpp
---
