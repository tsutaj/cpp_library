---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :x: verifying_test/AOJ/GRL_5_D/hld.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#2635c77cc4ff07f49346a24e71bb0668">verifying_test/AOJ/GRL_5_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/GRL_5_D/hld.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-22 23:54:50+09:00




## Depends on

* :x: <a href="../../../../library/graph/graph_020_HLDecomposition.cpp.html">graph/graph_020_HLDecomposition.cpp</a>
* :x: <a href="../../../../library/structure/strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
using ll = long long int;

#define call_from_test
#include "../../../graph/graph_020_HLDecomposition.cpp"
#include "../../../structure/strc_009_abst_lazy_segtree.cpp"
#undef call_from_test

int main() {
    int N; scanf("%d", &N);
    HLD hld(N);
    for(int i=0; i<N; i++) {
        int K; scanf("%d", &K);
        for(int j=0; j<K; j++) {
            int v; scanf("%d", &v);
            hld.add_edge(i, v);
        }
    }
    hld.build();

    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, int x) { return a * x; });
    int Q; scanf("%d", &Q);
    while(Q--) {
        int t; scanf("%d", &t);
        if(t == 0) {
            int v, w; scanf("%d%d", &v, &w);
            int u = hld.par[v];
            hld.query_edges(u, v, [&](int l, int r) {
                    seg.update(l, r, w);
                });
        }
        if(t == 1) {
            int u; scanf("%d", &u);
            auto f = [&](int l, int r) {
                return seg.query(l, r);
            };
            auto m = [&](ll v0, ll v1) {
                return v0 + v1;
            };
            ll ans = hld.query_edges(0, u, 0, f, m);
            printf("%lld\n", ans);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/AOJ/GRL_5_D/hld.test.cpp"
#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
using ll = long long int;

#define call_from_test
#line 1 "graph/graph_020_HLDecomposition.cpp"
// HL 分解 (Heavy-Light Decomposition)
// 頂点 v を根とする部分木: [ in[v], out[v] )
// 頂点 v から見た heavy edge chain の頭: head[v]
struct HLD {
    vector< vector<int> > G;
    vector<int> sub, par, depth, in, out, rev, head;
    
    void dfs_sub(int cur) {
        for(auto& to : G[cur]) {
            if(par[cur] == to) continue;
            par[to] = cur;
            depth[to] = depth[cur] + 1;
            dfs_sub(to);
            sub[cur] += sub[to];
            if(sub[to] > sub[ G[cur][0] ]) swap(to, G[cur][0]);
        }
    }
    void dfs_hld(int cur, int& ptr) {
        in[cur] = ptr; rev[ptr++] = cur;
        for(auto to : G[cur]) {
            if(par[cur] == to) continue;
            head[to] = (to == G[cur][0] ? head[cur] : to);
            dfs_hld(to, ptr);
        }
        out[cur] = ptr;
    }

    HLD(int N) : G(N), sub(N, 1), par(N, -1), depth(N),
                 in(N), out(N), rev(N), head(N) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int root=0) {
        int ptr = 0; dfs_sub(root); dfs_hld(root, ptr);
    }
    int lca(int u, int v) {
        while(1) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[ head[v] ];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    template <typename F>
    void proceed(int u, int v, const F& f, bool b) {
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v);
            f(in[ head[v] ], in[v] + 1);
        }
        if(in[u] > in[v]) swap(u, v);
        f(in[u] + b, in[v] + 1);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に f(l, r) を作用
    // l, r は SegmentTree とかのデータ構造上のインデックス
    template <typename F>
    void query_vertices(int u, int v, const F& f) {
        proceed(u, v, f, false);
    }

    template <typename F>
    void query_edges(int u, int v, const F& f) {
        proceed(u, v, f, true);
    }

    template <typename T, typename F, typename M>
    T proceed(int u, int v, T E, const F& f, const M& m, bool b) {
        T vl(E), vr(E);
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v), swap(vl, vr);
            vr = m(f(in[ head[v] ], in[v] + 1), vr);
        }
        if(in[u] > in[v]) swap(u, v), swap(vl, vr);
        vr = m(f(in[u] + b, in[v] + 1), vr);
        return m(vl, vr);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に割り当てられた値を
    // 各 chunk に対して f(l, r) で得て、それらを m(vl, vr) で merge したものを得る
    // 単位元 E も渡そう
    template <typename T, typename F, typename M>
    T query_vertices(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, false);
    }

    template <typename T, typename F, typename M>
    T query_edges(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, true);
    }
};
#line 1 "structure/strc_009_abst_lazy_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title 遅延伝播セグメント木 (Lazy Segment Tree)
template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,
                    MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    // range query for [a, b)
    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};
#line 10 "verifying_test/AOJ/GRL_5_D/hld.test.cpp"
#undef call_from_test

int main() {
    int N; scanf("%d", &N);
    HLD hld(N);
    for(int i=0; i<N; i++) {
        int K; scanf("%d", &K);
        for(int j=0; j<K; j++) {
            int v; scanf("%d", &v);
            hld.add_edge(i, v);
        }
    }
    hld.build();

    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, int x) { return a * x; });
    int Q; scanf("%d", &Q);
    while(Q--) {
        int t; scanf("%d", &t);
        if(t == 0) {
            int v, w; scanf("%d%d", &v, &w);
            int u = hld.par[v];
            hld.query_edges(u, v, [&](int l, int r) {
                    seg.update(l, r, w);
                });
        }
        if(t == 1) {
            int u; scanf("%d", &u);
            auto f = [&](int l, int r) {
                return seg.query(l, r);
            };
            auto m = [&](ll v0, ll v1) {
                return v0 + v1;
            };
            ll ans = hld.query_edges(0, u, 0, f, m);
            printf("%lld\n", ans);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

