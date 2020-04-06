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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: graph/verify/verify_graph_020_HLDecomposition.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_020_HLDecomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../graph_020_HLDecomposition.cpp.html">graph/graph_020_HLDecomposition.cpp</a>
* :warning: <a href="../../math/math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../../math/math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../../math/math_024_fixed_matrix.cpp.html">math/math_024_fixed_matrix.cpp</a>
* :warning: <a href="../../structure/strc_008_abst_segtree.cpp.html">セグメント木 (Segment Tree)</a>
* :warning: <a href="../../structure/strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <cassert>
#include <valarray>
using namespace std;
#include "../graph_020_HLDecomposition.cpp"
#include "../../structure/strc_008_abst_segtree.cpp"
#include "../../structure/strc_009_abst_lazy_segtree.cpp"
#include "../../math/math_004_matrix.cpp"
#include "../../math/math_017_modint.cpp"
#include "../../math/math_024_fixed_matrix.cpp"

void GRL_5_C() {
    int N; cin >> N;
    HLD hl(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            hl.add_edge(u, v);
        }
    }
    hl.build();

    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        cout << hl.lca(u, v) << endl;
    }
}

void ABC014_D() {
    int N; cin >> N;
    HLD hl(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        hl.add_edge(u, v);
    }
    hl.build();
 
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        cout << hl.distance(u, v) + 1 << endl;
    }
}

void AOJ2871() {
    int N, Q; cin >> N >> Q;
    HLD hl(N);
    for(int i=1; i<N; i++) {
        int u = i, v; cin >> v; v--;
        hl.add_edge(u, v);
    }
    hl.build();

    vector<int> color(N);
    auto &in = hl.in, &out = hl.out;
    
    for(int i=0; i<N; i++) {
        char c; cin >> c;
        color[ in[i] ] = (c == 'G' ? 1 : -1);
    }
    LazySegmentTree<int, int> seg(N, 0, 1,
                                  [](int a, int b) { return a * b; },
                                  [](int a, int b) { return a + b; },
                                  [](int a, int b) { return a * b; },
                                  [](int a, int x) { return a; },
                                  color);
    // seg.dump();
    for(int i=0; i<Q; i++) {
        int v; cin >> v; v--;
        seg.update(in[v], out[v], -1);
        int res = seg.query(in[0], out[0]);
        if(res < 0) cout << "cauliflower" << endl;
        else cout << "broccoli" << endl;
        // seg.dump();
    }
}

void yuki_650() {
    using mint = ModInt<1000000007>;
    int N; cin >> N;
    HLD hl(N);
    vector<int> u(N), v(N);
    for(int i=0; i<N-1; i++) {
        cin >> u[i] >> v[i];
        hl.add_edge(u[i], v[i]);
    }

    hl.build();
    auto &ord = hl.in;
    
    using Mat = Matrix<mint>;
    Mat I = eigen<mint>(2);
    LazySegmentTree<Mat, Mat> seg(N, I, I,
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, Mat b) { return a * b; },
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, int x) { return a; });
    auto f = [&](int l, int r) { return seg.query(l, r); };
    auto m = [&](Mat a, Mat b) { return a * b; };
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        char q; cin >> q;
        if(q == 'x') {
            int e; mint ul, ur, dl, dr; cin >> e >> ul >> ur >> dl >> dr;
            Mat mat(2, 2);
            mat[0] = {ul, ur};
            mat[1] = {dl, dr};
            hl.query_edges(u[e], v[e], [&mat, &seg](int l, int r) { seg.update(l, r, mat); });
        }
        if(q == 'g') {
            int x, y; cin >> x >> y;
            Mat res = hl.query_edges(x, y, I, f, m);
            cout << res[0][0] << " " << res[0][1] << " " << res[1][0] << " " << res[1][1] << endl;
        }
    }
}

void yuki_650_fixed() {
    using mint = ModInt<1000000007>;
    int N; cin >> N;
    HLD hl(N);
    vector<int> u(N), v(N);
    for(int i=0; i<N-1; i++) {
        cin >> u[i] >> v[i];
        hl.add_edge(u[i], v[i]);
    }

    hl.build();
    auto &ord = hl.in;
    
    using Mat = FixedMatrix<mint, 2, 2>;
    Mat I = eigen<mint, 2, 2>();
    LazySegmentTree<Mat, Mat> seg(N, I, I,
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, Mat b) { return a * b; },
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, int x) { return a; });
    auto f = [&](int l, int r) { return seg.query(l, r); };
    auto m = [&](Mat a, Mat b) { return a * b; };
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        char q; cin >> q;
        if(q == 'x') {
            int e; mint ul, ur, dl, dr; cin >> e >> ul >> ur >> dl >> dr;
            Mat mat;
            mat.at(0, 0) = ul, mat.at(0, 1) = ur;
            mat.at(1, 0) = dl, mat.at(1, 1) = dr;
            hl.query_edges(u[e], v[e], [&mat, &seg](int l, int r) { seg.update(l, r, mat); });
        }
        if(q == 'g') {
            int x, y; cin >> x >> y;
            Mat res = hl.query_edges(x, y, I, f, m);
            cout << res.at(0, 0) << " " << res.at(0, 1) << " " << res.at(1, 0) << " " << res.at(1, 1) << endl;
        }
    }    
}

void yuki_399() {
    int N; scanf("%d", &N);
    HLD hl(N);
    for(int i=0; i<N-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        hl.add_edge(u, v);
    }
    hl.build();

    using int64 = long long int;
    LazySegmentTree<int64, int64> seg(N, 0, 0,
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int   x) { return a * x; });

    auto f = [&](int   l, int   r) { return seg.query(l, r); };
    auto g = [&](int   l, int   r) { seg.update(l, r, 1); };
    auto m = [&](int64 a, int64 b) { return a + b; };
    
    int Q; scanf("%d", &Q);
    int64 ans = 0;
    for(int i=0; i<Q; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        ans += hl.distance(u, v) + 1;
        ans += hl.query_vertices(u, v, 0LL, f, m);
        hl.query_vertices(u, v, g);
    }

    printf("%lld\n", ans);
}

int main() {
    // GRL_5_C();  // LCA
    // ABC014_D(); // distance
    // AOJ2871();  // query (subtree)
    // yuki_650(); // query (edges)
    yuki_650_fixed();
    // yuki_399(); // query (vertices)
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_020_HLDecomposition.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
#include <tuple>
#include <cassert>
#include <valarray>
using namespace std;
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
#line 1 "structure/strc_008_abst_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title セグメント木 (Segment Tree)
// 抽象 SegmentTree (0-indexed・一点更新・区間取得)
template <typename MonoidType>
struct SegmentTree {
    using Function = function< MonoidType(MonoidType, MonoidType) >;

    // node, identity element
    int n;
    vector<MonoidType> node;
    MonoidType E0;

    // update / combine function
    Function upd_f, cmb_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
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
    SegmentTree() {}
    SegmentTree(int n_, MonoidType E0_,
                Function upd_f_, Function cmb_f_,
                vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {
        build(n_, v);
    }

    // update k-th element (applied value: x)
    void update(int k, MonoidType x) {
        k += n - 1;
        node[k] = upd_f(node[k], x);
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    // range query for [a, b)
    // 非再帰のアイデア: http://d.hatena.ne.jp/komiyam/20131202/1385992406
    MonoidType query(int a, int b) {
        MonoidType vl = E0, vr = E0;
        for(int l=a+n, r=b+n; l<r; l>>=1, r>>=1) {
            if(l & 1) vl = cmb_f(vl, node[(l++)-1]);
            if(r & 1) vr = cmb_f(node[(--r)-1], vr);
        }
        return cmb_f(vl, vr);
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
#line 1 "math/math_004_matrix.cpp"
// 行列ライブラリ

// size(): 行数を返す (列数は mat[0].size() で)
// 演算子: 複合代入 (+=, *=, -=), 単項 (-), 二項 (+, -, *, ==)
// eigen(N): N*N 単位行列を返す
// pow(mat, k): mat の k 乗を返す

template <typename T>
struct Matrix {
    vector< vector<T> > mat;
    Matrix() {}
    Matrix(int h, int w, T val = T(0)) : mat(h, vector<T>(w, val)) {}
    size_t size() const { return mat.size(); }
    const vector<T>& operator[](int i) const { return mat[i]; }
    vector<T>& operator[](int i) { return mat[i]; }

    Matrix<T> &operator+=(const Matrix<T>& rhs) {
        assert(mat.size() == rhs.size());
        assert(mat[0].size() == rhs[0].size());
        for(size_t i=0; i<mat.size(); i++) {
            for(size_t j=0; j<mat[0].size(); j++) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Matrix<T> operator-() const {
        Matrix<T> res(*this);
        for(size_t i=0; i<res.size(); i++) {
            for(size_t j=0; j<res[0].size(); j++) {
                res[i][j] *= T(-1);
            }
        }
        return res;
    }

    Matrix<T>& operator-=(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) += -rhs);
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs) {
        assert(mat[0].size() == rhs.size());
        size_t H = mat.size(), W = rhs[0].size(), C = rhs.size();
        Matrix<T> res(H, W);
        for(size_t i=0; i<H; i++) {
            for(size_t j=0; j<W; j++) {
                for(size_t k=0; k<C; k++) {
                    res[i][j] += mat[i][k] * rhs[k][j];
                }
            }
        }
        this->mat = res.mat;
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) += rhs);
    }

    Matrix<T> operator*(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) *= rhs);
    }

    Matrix<T> operator-(const Matrix<T> &rhs) {
        return (Matrix<T>(*this) -= rhs);
    }

    bool operator==(const Matrix<T> &rhs) const {
        return this->mat == rhs.mat;
    }
    bool operator!=(const Matrix<T> &rhs) const {
        return !(*this == rhs);
    }
};

template <typename T>
Matrix<T> eigen(size_t N) {
    Matrix<T> res(N, N, 0);
    for(size_t i=0; i<N; i++) res[i][i] = T(1);
    return res;
}

template <typename T>
Matrix<T> pow(Matrix<T> mat, long long int k) {
    Matrix<T> res = eigen<T>(mat.size());
    for(; k>0; k>>=1) {
        if(k & 1) res *= mat;
        mat *= mat;
    }
    return res;
}

template <typename T>
ostream& operator<< (ostream& out, Matrix<T> mat) {
    int H = mat.size(), W = mat[0].size();
    out << "[" << endl;
    for(int i=0; i<H; i++) {
        out << "  [ ";
        for(int j=0; j<W; j++) out << mat[i][j] << " ";
        out << "]" << endl;
    }
    out << "]" << endl;
    return out;
}
#line 1 "math/math_017_modint.cpp"
// ModInt begin

using ll = long long;
template<ll mod>
struct ModInt {
    ll v;
    ll mod_pow(ll x, ll n) const {
        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;
    }
    ModInt(ll a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
    ModInt operator+ ( const ModInt& b ) const {
        return (v + b.v >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));
    }
    ModInt operator- () const {
        return ModInt(-v);
    }
    ModInt operator- ( const ModInt& b ) const {
        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));
    }
    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}
    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2)) % mod;}
    
    bool operator== ( const ModInt &b ) const {return v == b.v;}
    bool operator!= ( const ModInt &b ) const {return !(*this == b); }
    ModInt& operator+= ( const ModInt &b ) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }
    ModInt& operator-= ( const ModInt &b ) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }
    ModInt& operator*= ( const ModInt &b ) {
        (v *= b.v) %= mod;
        return *this;
    }
    ModInt& operator/= ( const ModInt &b ) {
        (v *= mod_pow(b.v, mod-2)) %= mod;
        return *this;
    }
    ModInt pow(ll x) { return ModInt(mod_pow(v, x)); }
    // operator int() const { return int(v); }
    // operator long long int() const { return v; }
};

template<ll mod>
ModInt<mod> pow(ModInt<mod> n, ll k) {
    return ModInt<mod>(n.mod_pow(n.v, k));
}

template<ll mod>
ostream& operator<< (ostream& out, ModInt<mod> a) {return out << a.v;}
template<ll mod>
istream& operator>> (istream& in, ModInt<mod>& a) {
    in >> a.v;
    return in;
}

// ModInt end
#line 1 "math/math_024_fixed_matrix.cpp"
// 行列ライブラリ

// 演算子: 複合代入 (+=, -=), 単項 (-), 二項 (+, -, *, ==)
// eigen(N): N*N 単位行列を返す
// pow(mat, k): mat の k 乗を返す

template <typename T, int h, int w>
struct FixedMatrix {
    using array_type = array<T, h * w>;
    array_type mat;

    FixedMatrix(T val = T(0)) { mat.fill(val); }
    
    const T& at(int i, int j) const { return mat[i*w + j]; }
    T& at(int i, int j) { return mat[i*w + j]; }

    FixedMatrix<T, h, w> &operator+=(const FixedMatrix<T, h, w>& rhs) {
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                this->at(i, j) += rhs.at(i, j);
            }
        }
        return *this;
    }

    FixedMatrix<T, h, w> operator-() const {
        FixedMatrix<T, h, w> res(*this);
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                res.at(i, j) *= T(-1);
            }
        }
        return res;
    }

    FixedMatrix<T, h, w> &operator-=(const FixedMatrix<T, h, w>& rhs) {
        return (FixedMatrix<T, h, w>(*this) += -rhs);
    }

    template <int wr>
    FixedMatrix<T, h, wr> operator*(const FixedMatrix<T, w, wr>& rhs) {
        size_t H = h, W = wr, C = w;
        FixedMatrix<T, h, wr> res;
        for(size_t i=0; i<H; i++) {
            for(size_t j=0; j<W; j++) {
                for(size_t k=0; k<C; k++) {
                    res.at(i, j) += this->at(i, k) * rhs.at(k, j);
                }
            }
        }
        return res;
    }

    FixedMatrix<T, h, w> operator+(const FixedMatrix<T, h, w>& rhs) {
        return (FixedMatrix<T, h, w>(*this) += rhs);
    }

    FixedMatrix<T, h, w> operator-(const FixedMatrix<T, h, w> &rhs) {
        return (FixedMatrix<T, h, w>(*this) -= rhs);
    }

    bool operator==(const FixedMatrix<T, h, w> &rhs) const {
        return this->mat == rhs.mat;
    }
    bool operator!=(const FixedMatrix<T, h, w> &rhs) const {
        return !(*this == rhs);
    }
};

template <typename T, int h, int w>
FixedMatrix<T, h, w> eigen() {
    FixedMatrix<T, h, w> res(0);
    for(size_t i=0; i<h; i++) res.at(i, i) = T(1);
    return res;
}

template <typename T, int h, int w>
FixedMatrix<T, h, w> pow(FixedMatrix<T, h, w> mat, long long int k) {
    FixedMatrix<T, h, w> res = eigen<T, h, w>();
    for(; k>0; k>>=1) {
        if(k & 1) res = res * mat;
        mat = mat * mat;
    }
    return res;
}

template <typename T, int h, int w>
ostream& operator<< (ostream& out, FixedMatrix<T, h, w> mat) {
    int H = mat.h, W = mat.w;
    out << "[" << endl;
    for(int i=0; i<H; i++) {
        out << "  [ ";
        for(int j=0; j<W; j++) out << mat.at(i, j) << " ";
        out << "]" << endl;
    }
    out << "]" << endl;
    return out;
}
#line 16 "graph/verify/verify_graph_020_HLDecomposition.cpp"

void GRL_5_C() {
    int N; cin >> N;
    HLD hl(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            hl.add_edge(u, v);
        }
    }
    hl.build();

    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        cout << hl.lca(u, v) << endl;
    }
}

void ABC014_D() {
    int N; cin >> N;
    HLD hl(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        hl.add_edge(u, v);
    }
    hl.build();
 
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        cout << hl.distance(u, v) + 1 << endl;
    }
}

void AOJ2871() {
    int N, Q; cin >> N >> Q;
    HLD hl(N);
    for(int i=1; i<N; i++) {
        int u = i, v; cin >> v; v--;
        hl.add_edge(u, v);
    }
    hl.build();

    vector<int> color(N);
    auto &in = hl.in, &out = hl.out;
    
    for(int i=0; i<N; i++) {
        char c; cin >> c;
        color[ in[i] ] = (c == 'G' ? 1 : -1);
    }
    LazySegmentTree<int, int> seg(N, 0, 1,
                                  [](int a, int b) { return a * b; },
                                  [](int a, int b) { return a + b; },
                                  [](int a, int b) { return a * b; },
                                  [](int a, int x) { return a; },
                                  color);
    // seg.dump();
    for(int i=0; i<Q; i++) {
        int v; cin >> v; v--;
        seg.update(in[v], out[v], -1);
        int res = seg.query(in[0], out[0]);
        if(res < 0) cout << "cauliflower" << endl;
        else cout << "broccoli" << endl;
        // seg.dump();
    }
}

void yuki_650() {
    using mint = ModInt<1000000007>;
    int N; cin >> N;
    HLD hl(N);
    vector<int> u(N), v(N);
    for(int i=0; i<N-1; i++) {
        cin >> u[i] >> v[i];
        hl.add_edge(u[i], v[i]);
    }

    hl.build();
    auto &ord = hl.in;
    
    using Mat = Matrix<mint>;
    Mat I = eigen<mint>(2);
    LazySegmentTree<Mat, Mat> seg(N, I, I,
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, Mat b) { return a * b; },
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, int x) { return a; });
    auto f = [&](int l, int r) { return seg.query(l, r); };
    auto m = [&](Mat a, Mat b) { return a * b; };
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        char q; cin >> q;
        if(q == 'x') {
            int e; mint ul, ur, dl, dr; cin >> e >> ul >> ur >> dl >> dr;
            Mat mat(2, 2);
            mat[0] = {ul, ur};
            mat[1] = {dl, dr};
            hl.query_edges(u[e], v[e], [&mat, &seg](int l, int r) { seg.update(l, r, mat); });
        }
        if(q == 'g') {
            int x, y; cin >> x >> y;
            Mat res = hl.query_edges(x, y, I, f, m);
            cout << res[0][0] << " " << res[0][1] << " " << res[1][0] << " " << res[1][1] << endl;
        }
    }
}

void yuki_650_fixed() {
    using mint = ModInt<1000000007>;
    int N; cin >> N;
    HLD hl(N);
    vector<int> u(N), v(N);
    for(int i=0; i<N-1; i++) {
        cin >> u[i] >> v[i];
        hl.add_edge(u[i], v[i]);
    }

    hl.build();
    auto &ord = hl.in;
    
    using Mat = FixedMatrix<mint, 2, 2>;
    Mat I = eigen<mint, 2, 2>();
    LazySegmentTree<Mat, Mat> seg(N, I, I,
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, Mat b) { return a * b; },
                                  [](Mat a, Mat b) { return b; },
                                  [](Mat a, int x) { return a; });
    auto f = [&](int l, int r) { return seg.query(l, r); };
    auto m = [&](Mat a, Mat b) { return a * b; };
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        char q; cin >> q;
        if(q == 'x') {
            int e; mint ul, ur, dl, dr; cin >> e >> ul >> ur >> dl >> dr;
            Mat mat;
            mat.at(0, 0) = ul, mat.at(0, 1) = ur;
            mat.at(1, 0) = dl, mat.at(1, 1) = dr;
            hl.query_edges(u[e], v[e], [&mat, &seg](int l, int r) { seg.update(l, r, mat); });
        }
        if(q == 'g') {
            int x, y; cin >> x >> y;
            Mat res = hl.query_edges(x, y, I, f, m);
            cout << res.at(0, 0) << " " << res.at(0, 1) << " " << res.at(1, 0) << " " << res.at(1, 1) << endl;
        }
    }    
}

void yuki_399() {
    int N; scanf("%d", &N);
    HLD hl(N);
    for(int i=0; i<N-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        hl.add_edge(u, v);
    }
    hl.build();

    using int64 = long long int;
    LazySegmentTree<int64, int64> seg(N, 0, 0,
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int64 b) { return a + b; },
                                      [](int64 a, int   x) { return a * x; });

    auto f = [&](int   l, int   r) { return seg.query(l, r); };
    auto g = [&](int   l, int   r) { seg.update(l, r, 1); };
    auto m = [&](int64 a, int64 b) { return a + b; };
    
    int Q; scanf("%d", &Q);
    int64 ans = 0;
    for(int i=0; i<Q; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        ans += hl.distance(u, v) + 1;
        ans += hl.query_vertices(u, v, 0LL, f, m);
        hl.query_vertices(u, v, g);
    }

    printf("%lld\n", ans);
}

int main() {
    // GRL_5_C();  // LCA
    // ABC014_D(); // distance
    // AOJ2871();  // query (subtree)
    // yuki_650(); // query (edges)
    yuki_650_fixed();
    // yuki_399(); // query (vertices)
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

