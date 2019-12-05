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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../graph/verify/verify_graph_020_HLDecomposition.cpp
* category: ../../graph/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../graph/graph_020_HLDecomposition.cpp](../graph_020_HLDecomposition.cpp.html)
* :warning: [../../math/math_004_matrix.cpp](../../math/math_004_matrix.cpp.html)
* :warning: [../../math/math_017_modint.cpp](../../math/math_017_modint.cpp.html)
* :warning: [../../math/math_024_fixed_matrix.cpp](../../math/math_024_fixed_matrix.cpp.html)
* :warning: [../../structure/strc_008_abst_segtree.cpp](../../structure/strc_008_abst_segtree.cpp.html)
* :warning: [../../structure/strc_009_abst_lazy_segtree.cpp](../../structure/strc_009_abst_lazy_segtree.cpp.html)


## Code
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

[Back to top page](../../../index.html)

