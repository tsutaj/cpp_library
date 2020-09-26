---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/graph_020_HLDecomposition.cpp
    title: graph/graph_020_HLDecomposition.cpp
  - icon: ':heavy_check_mark:'
    path: structure/strc_009_abst_lazy_segtree.cpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment\
      \ Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D
  bundledCode: "#line 1 \"verifying_test/AOJ/GRL_5_D/hld.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\n#include\
    \ <cstdio>\n#include <vector>\n#include <functional>\nusing namespace std;\nusing\
    \ ll = long long int;\n\n#define call_from_test\n#line 1 \"graph/graph_020_HLDecomposition.cpp\"\
    \n// HL \u5206\u89E3 (Heavy-Light Decomposition)\n// \u9802\u70B9 v \u3092\u6839\
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
    \u30F3\u30C7\u30C3\u30AF\u30B9\n    template <typename F>\n    void query_vertices(int\
    \ u, int v, const F& f) {\n        proceed(u, v, f, false);\n    }\n\n    template\
    \ <typename F>\n    void query_edges(int u, int v, const F& f) {\n        proceed(u,\
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
    \ {\n        return proceed(u, v, E, f, m, true);\n    }\n};\n#line 1 \"structure/strc_009_abst_lazy_segtree.cpp\"\
    \n// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)\n\
    template <typename MonoidType, typename OperatorType>\nstruct LazySegmentTree\
    \ {\n    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;\n    using\
    \ OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n    using MOtoM\
    \ = function< MonoidType(MonoidType, OperatorType) >;\n    using OItoO = function<\
    \ OperatorType(OperatorType, int) >;\n\n    // node, lazy, update flag (for lazy),\
    \ identity element\n    int n;\n    vector<MonoidType> node;\n    vector<OperatorType>\
    \ lazy;\n    vector<bool> need_update;\n    MonoidType E0;\n    OperatorType E1;\n\
    \n    // update / combine / lazy / accumulate function\n    MOtoM upd_f;\n   \
    \ MMtoM cmb_f;\n    OOtoO lzy_f;\n    OItoO acc_f;\n\n    void build(int m, vector<MonoidType>\
    \ v = vector<MonoidType>()) {\n        if(v != vector<MonoidType>()) m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n\n        node = vector<MonoidType>(2*n-1,\
    \ E0);\n        lazy = vector<OperatorType>(2*n-1, E1);\n        need_update =\
    \ vector<bool>(2*n-1, false);\n        if(v != vector<MonoidType>()) {\n     \
    \       for(int i=0; i<m; i++) {\n                node[n-1+i] = v[i];\n      \
    \      }\n            for(int i=n-2; i>=0; i--) {\n                node[i] = cmb_f(node[2*i+1],\
    \ node[2*i+2]);\n            }\n        }\n    }\n\n    // initialize\n    LazySegmentTree()\
    \ {}\n    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,\n        \
    \            MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,\n       \
    \             vector<MonoidType> v = vector<MonoidType>()) :\n        E0(E0_),\
    \ E1(E1_),\n        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_)\
    \ {\n        build(n_, v);\n    }\n\n    void eval(int k, int l, int r) {\n  \
    \      if(!need_update[k]) return;\n        node[k] = upd_f(node[k], acc_f(lazy[k],\
    \ r - l));\n        if(r - l > 1) {\n            lazy[2*k+1] = lzy_f(lazy[2*k+1],\
    \ lazy[k]);\n            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);\n        \
    \    need_update[2*k+1] = need_update[2*k+2] = true;\n        }\n        lazy[k]\
    \ = E1;\n        need_update[k] = false;\n    }\n\n    void update(int a, int\
    \ b, OperatorType x, int l, int r, int k) {\n        eval(k, l, r);\n        if(b\
    \ <= l or  r <= a) return;\n        if(a <= l and r <= b) {\n            lazy[k]\
    \ = lzy_f(lazy[k], x);\n            need_update[k] = true;\n            eval(k,\
    \ l, r);\n        }\n        else {\n            int mid = (l + r) / 2;\n    \
    \        update(a, b, x, l, mid, 2*k+1);\n            update(a, b, x, mid, r,\
    \ 2*k+2);\n            node[k] = cmb_f(node[2*k+1], node[2*k+2]);\n        }\n\
    \    }\n\n    MonoidType query(int a, int b, int l, int r, int k) {\n        if(b\
    \ <= l or  r <= a) return E0;\n        eval(k, l, r);\n        if(a <= l and r\
    \ <= b) return node[k];\n        int mid = (l + r) / 2;\n        MonoidType vl\
    \ = query(a, b, l, mid, 2*k+1);\n        MonoidType vr = query(a, b, mid, r, 2*k+2);\n\
    \        return cmb_f(vl, vr);\n    }\n\n    // update [a, b)-th element (applied\
    \ value, x)\n    void update(int a, int b, OperatorType x) {\n        update(a,\
    \ b, x, 0, n, 0);\n    }\n\n    // range query for [a, b)\n    MonoidType query(int\
    \ a, int b) {\n        return query(a, b, 0, n, 0);\n    }\n\n    void dump()\
    \ {\n        fprintf(stderr, \"[lazy]\\n\");\n        for(int i=0; i<2*n-1; i++)\
    \ {\n            if(i == n-1) fprintf(stderr, \"xxx \");\n            if(lazy[i]\
    \ == E1) fprintf(stderr, \"  E \");\n            else fprintf(stderr, \"%3d \"\
    , lazy[i]);\n        }\n        fprintf(stderr, \"\\n\");\n\n        fprintf(stderr,\
    \ \"[node]\\n\");\n        for(int i=0; i<2*n-1; i++) {\n            if(i == n-1)\
    \ fprintf(stderr, \"xxx \");\n            if(node[i] == E0) fprintf(stderr, \"\
    \  E \");\n            else fprintf(stderr, \"%3d \", node[i]);\n        }\n \
    \       fprintf(stderr, \"\\n\");\n    }\n};\n#line 11 \"verifying_test/AOJ/GRL_5_D/hld.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N; scanf(\"%d\", &N);\n    HLD\
    \ hld(N);\n    for(int i=0; i<N; i++) {\n        int K; scanf(\"%d\", &K);\n \
    \       for(int j=0; j<K; j++) {\n            int v; scanf(\"%d\", &v);\n    \
    \        hld.add_edge(i, v);\n        }\n    }\n    hld.build();\n\n    LazySegmentTree<ll,\
    \ ll> seg(N, 0, 0,\n                                [](ll a, ll b) { return a\
    \ + b; },\n                                [](ll a, ll b) { return a + b; },\n\
    \                                [](ll a, ll b) { return a + b; },\n         \
    \                       [](ll a, int x) { return a * x; });\n    int Q; scanf(\"\
    %d\", &Q);\n    while(Q--) {\n        int t; scanf(\"%d\", &t);\n        if(t\
    \ == 0) {\n            int v, w; scanf(\"%d%d\", &v, &w);\n            int u =\
    \ hld.par[v];\n            hld.query_edges(u, v, [&](int l, int r) {\n       \
    \             seg.update(l, r, w);\n                });\n        }\n        if(t\
    \ == 1) {\n            int u; scanf(\"%d\", &u);\n            auto f = [&](int\
    \ l, int r) {\n                return seg.query(l, r);\n            };\n     \
    \       auto m = [&](ll v0, ll v1) {\n                return v0 + v1;\n      \
    \      };\n            ll ans = hld.query_edges(0, u, 0, f, m);\n            printf(\"\
    %lld\\n\", ans);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_D\"\
    \n#include <cstdio>\n#include <vector>\n#include <functional>\nusing namespace\
    \ std;\nusing ll = long long int;\n\n#define call_from_test\n#include \"../../../graph/graph_020_HLDecomposition.cpp\"\
    \n#include \"../../../structure/strc_009_abst_lazy_segtree.cpp\"\n#undef call_from_test\n\
    \nint main() {\n    int N; scanf(\"%d\", &N);\n    HLD hld(N);\n    for(int i=0;\
    \ i<N; i++) {\n        int K; scanf(\"%d\", &K);\n        for(int j=0; j<K; j++)\
    \ {\n            int v; scanf(\"%d\", &v);\n            hld.add_edge(i, v);\n\
    \        }\n    }\n    hld.build();\n\n    LazySegmentTree<ll, ll> seg(N, 0, 0,\n\
    \                                [](ll a, ll b) { return a + b; },\n         \
    \                       [](ll a, ll b) { return a + b; },\n                  \
    \              [](ll a, ll b) { return a + b; },\n                           \
    \     [](ll a, int x) { return a * x; });\n    int Q; scanf(\"%d\", &Q);\n   \
    \ while(Q--) {\n        int t; scanf(\"%d\", &t);\n        if(t == 0) {\n    \
    \        int v, w; scanf(\"%d%d\", &v, &w);\n            int u = hld.par[v];\n\
    \            hld.query_edges(u, v, [&](int l, int r) {\n                    seg.update(l,\
    \ r, w);\n                });\n        }\n        if(t == 1) {\n            int\
    \ u; scanf(\"%d\", &u);\n            auto f = [&](int l, int r) {\n          \
    \      return seg.query(l, r);\n            };\n            auto m = [&](ll v0,\
    \ ll v1) {\n                return v0 + v1;\n            };\n            ll ans\
    \ = hld.query_edges(0, u, 0, f, m);\n            printf(\"%lld\\n\", ans);\n \
    \       }\n    }\n    return 0;\n}\n"
  dependsOn:
  - graph/graph_020_HLDecomposition.cpp
  - structure/strc_009_abst_lazy_segtree.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/GRL_5_D/hld.test.cpp
  requiredBy: []
  timestamp: '2020-07-13 08:30:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AOJ/GRL_5_D/hld.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/GRL_5_D/hld.test.cpp
- /verify/verifying_test/AOJ/GRL_5_D/hld.test.cpp.html
title: verifying_test/AOJ/GRL_5_D/hld.test.cpp
---
