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


# :warning: structure/verify/verify_strc_009_abst_lazy_segtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_009_abst_lazy_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00




## Depends on

* :x: <a href="../strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <utility>
using namespace std;
#include "../strc_009_abst_lazy_segtree.cpp"

// Verified on Apr 27, 2019
void DSL_2_D() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s; cin >> s;
            s -= indexed;
            cout << seg.query(s, s+1) << endl;
        }
        // seg.dump();
    }
}

void DSL_2_D_pair() {
    int N, Q; cin >> N >> Q;
    using Pair = pair<int, int>;
    LazySegmentTree<int, Pair> seg(N, INT_MAX, make_pair(0, 0),
                                   [](int x, Pair p) {
                                       if(p.second == 0) return x;
                                       return p.first;
                                   },
                                   [](int a, int b) { return min(a, b); },
                                   [](Pair a, Pair b) {
                                       return b.second ? b : a;
                                   },
                                   [](Pair a, int x) { return a; },
                                   vector<int>(N, INT_MAX));

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int q; cin >> q;
        if(q == 0) {
            int s, t, x; cin >> s >> t >> x;
            s -= indexed, t -= indexed, t++;
            seg.update(s, t, make_pair(x, 1));
        }
        if(q == 1) {
            int x; cin >> x; x -= indexed;
            cout << seg.query(x, x+1) << endl;
        }
    }
}

// Verified on Apr 27, 2019
void DSL_2_E() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, 0, 0,
                                  [](int a, int b) { return a + b; },  // upd
                                  [](int a, int b) { return a + b; },  // cmb
                                  [](int a, int b) { return a + b; },  // lzy
                                  [](int a, int x) { return a * x; }); // acc
    
    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s; cin >> s;
            s -= indexed;
            cout << seg.query(s, s+1) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_F() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, INT_MAX, 0,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                  [](ll a, ll  b) { return a + b; },  // upd
                                  [](ll a, ll  b) { return a + b; },  // cmb
                                  [](ll a, ll  b) { return a + b; },  // lzy
                                  [](ll a, int x) { return a * x; }); // acc
    
    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_H() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, INT_MAX, 0,
                                [](ll a, ll  b) { return a + b;     },  // upd
                                [](ll a, ll  b) { return min(a, b); },  // cmb
                                [](ll a, ll  b) { return a + b;     },  // lzy
                                [](ll a, int x) { return a;         },  // acc
                                vector<ll>(N));
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_H_simple() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    using Pair = pair<ll, ll>;
    LazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 1),
                                  [](ll   a, Pair b) { return a * b.second + b.first; },  // upd
                                  [](ll   a, ll   b) { return min(a, b); },  // cmb
                                  [](Pair a, Pair b) { return make_pair(a.first * b.second + b.first, a.second & b.second); },  // lzy
                                  [](Pair a, int  x) { return a; }); // acc

    seg.update(0, N, make_pair(0, 0));
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, make_pair(x, 1));
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}


// Verified on Apr 27, 2019
void DSL_2_I() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                [](ll a, ll  b) { return b;     },  // upd
                                [](ll a, ll  b) { return a + b; },  // cmb
                                [](ll a, ll  b) { return b;     },  // lzy
                                [](ll a, int x) { return a * x; },  // acc
                                vector<ll>(N));
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on May 31, 2019
void ABC128_E() {
    int N, Q; cin >> N >> Q;

    map<int, int> cmp; int id = 0;
    vector<int> s(N), t(N), x(N), p(Q);
    for(int i=0; i<N; i++) {
        cin >> s[i] >> t[i] >> x[i];
        s[i] = max(0, s[i] - x[i]);
        t[i] = max(0, t[i] - x[i]);
        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[ t[i] - 1 ]++;
    }
    for(int i=0; i<Q; i++) {
        cin >> p[i];
        cmp[ p[i] ]++;
    }
    for(auto &e : cmp) e.second = id++;
    for(int i=0; i<N; i++) {
        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];
    }
    for(int i=0; i<Q; i++) {
        p[i] = cmp[ p[i] ];
    }
    
    LazySegmentTree<int, int> seg(id, INT_MAX, INT_MAX,
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int x) { return a; });
    
    for(int i=0; i<N; i++) {
        seg.update(s[i], t[i], x[i]);
    }
    for(int i=0; i<Q; i++) {
        int res = seg.query(p[i], p[i]+1);
        if(res == INT_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
}

/*
void yuki_749() {
    int N, Q; cin >> N >> Q;

    
    
}
*/

int main() {
    // DSL_2_D();
    // DSL_2_D_pair();
    // DSL_2_E();
    // DSL_2_F();
    // DSL_2_G();
    // DSL_2_H();
    DSL_2_H_simple();
    // DSL_2_I();
    // ABC128_E();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_009_abst_lazy_segtree.cpp"
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
#include <map>
#include <utility>
using namespace std;
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
#line 10 "structure/verify/verify_strc_009_abst_lazy_segtree.cpp"

// Verified on Apr 27, 2019
void DSL_2_D() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s; cin >> s;
            s -= indexed;
            cout << seg.query(s, s+1) << endl;
        }
        // seg.dump();
    }
}

void DSL_2_D_pair() {
    int N, Q; cin >> N >> Q;
    using Pair = pair<int, int>;
    LazySegmentTree<int, Pair> seg(N, INT_MAX, make_pair(0, 0),
                                   [](int x, Pair p) {
                                       if(p.second == 0) return x;
                                       return p.first;
                                   },
                                   [](int a, int b) { return min(a, b); },
                                   [](Pair a, Pair b) {
                                       return b.second ? b : a;
                                   },
                                   [](Pair a, int x) { return a; },
                                   vector<int>(N, INT_MAX));

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int q; cin >> q;
        if(q == 0) {
            int s, t, x; cin >> s >> t >> x;
            s -= indexed, t -= indexed, t++;
            seg.update(s, t, make_pair(x, 1));
        }
        if(q == 1) {
            int x; cin >> x; x -= indexed;
            cout << seg.query(x, x+1) << endl;
        }
    }
}

// Verified on Apr 27, 2019
void DSL_2_E() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, 0, 0,
                                  [](int a, int b) { return a + b; },  // upd
                                  [](int a, int b) { return a + b; },  // cmb
                                  [](int a, int b) { return a + b; },  // lzy
                                  [](int a, int x) { return a * x; }); // acc
    
    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s; cin >> s;
            s -= indexed;
            cout << seg.query(s, s+1) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_F() {
    int N, Q; cin >> N >> Q;
    LazySegmentTree<int, int> seg(N, INT_MAX, 0,
                                  [](int a, int b) { return b;         },  // upd
                                  [](int a, int b) { return min(a, b); },  // cmb
                                  [](int a, int b) { return b;         },  // lzy
                                  [](int a, int x) { return a;         }); // acc
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                  [](ll a, ll  b) { return a + b; },  // upd
                                  [](ll a, ll  b) { return a + b; },  // cmb
                                  [](ll a, ll  b) { return a + b; },  // lzy
                                  [](ll a, int x) { return a * x; }); // acc
    
    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_H() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, INT_MAX, 0,
                                [](ll a, ll  b) { return a + b;     },  // upd
                                [](ll a, ll  b) { return min(a, b); },  // cmb
                                [](ll a, ll  b) { return a + b;     },  // lzy
                                [](ll a, int x) { return a;         },  // acc
                                vector<ll>(N));
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on Apr 27, 2019
void DSL_2_H_simple() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    using Pair = pair<ll, ll>;
    LazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 1),
                                  [](ll   a, Pair b) { return a * b.second + b.first; },  // upd
                                  [](ll   a, ll   b) { return min(a, b); },  // cmb
                                  [](Pair a, Pair b) { return make_pair(a.first * b.second + b.first, a.second & b.second); },  // lzy
                                  [](Pair a, int  x) { return a; }); // acc

    seg.update(0, N, make_pair(0, 0));
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, make_pair(x, 1));
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}


// Verified on Apr 27, 2019
void DSL_2_I() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                [](ll a, ll  b) { return b;     },  // upd
                                [](ll a, ll  b) { return a + b; },  // cmb
                                [](ll a, ll  b) { return b;     },  // lzy
                                [](ll a, int x) { return a * x; },  // acc
                                vector<ll>(N));
    
    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on May 31, 2019
void ABC128_E() {
    int N, Q; cin >> N >> Q;

    map<int, int> cmp; int id = 0;
    vector<int> s(N), t(N), x(N), p(Q);
    for(int i=0; i<N; i++) {
        cin >> s[i] >> t[i] >> x[i];
        s[i] = max(0, s[i] - x[i]);
        t[i] = max(0, t[i] - x[i]);
        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[ t[i] - 1 ]++;
    }
    for(int i=0; i<Q; i++) {
        cin >> p[i];
        cmp[ p[i] ]++;
    }
    for(auto &e : cmp) e.second = id++;
    for(int i=0; i<N; i++) {
        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];
    }
    for(int i=0; i<Q; i++) {
        p[i] = cmp[ p[i] ];
    }
    
    LazySegmentTree<int, int> seg(id, INT_MAX, INT_MAX,
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int x) { return a; });
    
    for(int i=0; i<N; i++) {
        seg.update(s[i], t[i], x[i]);
    }
    for(int i=0; i<Q; i++) {
        int res = seg.query(p[i], p[i]+1);
        if(res == INT_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
}

/*
void yuki_749() {
    int N, Q; cin >> N >> Q;

    
    
}
*/

int main() {
    // DSL_2_D();
    // DSL_2_D_pair();
    // DSL_2_E();
    // DSL_2_F();
    // DSL_2_G();
    // DSL_2_H();
    DSL_2_H_simple();
    // DSL_2_I();
    // ABC128_E();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

