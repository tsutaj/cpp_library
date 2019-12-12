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
    - Last commit date: 2019-12-09 17:27:28 +0900




## Depends On
* :warning: <a href="../strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>


## Code
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

<a href="../../../index.html">Back to top page</a>

