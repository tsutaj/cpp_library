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


# :warning: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
* category: structure/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [structure/strc_021_dynamic_lazy_segtree.cpp](../strc_021_dynamic_lazy_segtree.cpp.html)


## Code
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
#include "../strc_021_dynamic_lazy_segtree.cpp"

// Verified on May 28, 2019
void DSL_2_D() {
    int N, Q; cin >> N >> Q;
    DynamicLazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,
                                         [](int a, int b) { return b; },
                                         [](int a, int b) { return min(a, b); },
                                         [](int a, int b) { return b; },
                                         [](int a, int b) { return a; });

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int q; cin >> q;
        if(q == 0) {
            int s, t, x; cin >> s >> t >> x;
            s -= indexed; t -= indexed; t++;
            seg.update(s, t, x);
        }
        if(q == 1) {
            int k; cin >> k;
            k -= indexed;
            cout << seg.query(k, k+1) << endl;
        }
    }
}

// Verified on May 28, 2019
void DSL_2_E() {
    int N, Q; cin >> N >> Q;
    DynamicLazySegmentTree<int, int> seg(N, 0, 0,
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

// Verified on May 28, 2019
void DSL_2_F() {
    int N, Q; cin >> N >> Q;
    DynamicLazySegmentTree<int, int> seg(N, INT_MAX, 0,
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

// Verified on May 28, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,
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
void DSL_2_H_simple() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    using Pair = pair<ll, ll>;
    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 1),
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

// Verified on May 28, 2019
void DSL_2_H_pair() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    using Pair = pair<ll, ll>;
    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 0),
                                       [](ll a, Pair b) {
                                             if(b.second == 1) {
                                                 return b.first;
                                             }
                                             else {
                                                 return a + b.first;
                                             }
                                         },  // upd
                                       [](ll a, ll  b) { return min(a, b); },  // cmb
                                       [](Pair a, Pair b) {
                                           if(a.second == 0 and b.second == 0) {
                                               return make_pair(a.first + b.first, 0LL);
                                           }
                                           if(a.second == 0 and b.second == 1) {
                                               return b;
                                           }
                                           if(a.second == 1 and b.second == 0) {
                                               return make_pair(a.first + b.first, 1LL);
                                           }
                                           if(a.second == 1 and b.second == 1) {
                                               return b;
                                           }
                                       },
                                       [](Pair a, int x) { return a;         }); // acc
    
    int indexed = 0;
    seg.update(0, N, make_pair(0, 1));
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x; t++;
            s -= indexed, t -= indexed;
            seg.update(s, t, make_pair(x, 0));
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t; t++;
            s -= indexed; t -= indexed;
            cout << seg.query(s, t) << endl;
        }
        // seg.dump();
    }    
}

// Verified on May 28, 2019
void DSL_2_I() {
    int N, Q; cin >> N >> Q;
    using ll = long long int;
    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,
                                       [](ll a, ll  b) { return b;     },  // upd
                                       [](ll a, ll  b) { return a + b; },  // cmb
                                       [](ll a, ll  b) { return b;     },  // lzy
                                       [](ll a, int x) { return a * x; }); // acc
    
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

// TLE
void ABC128_E() {
    const int RANGE = 1 << 30;
    int N, Q; cin >> N >> Q;

    DynamicLazySegmentTree<int, int> seg(RANGE, INT_MAX, INT_MAX,
                                         [](int a, int b) { return min(a, b); },
                                         [](int a, int b) { return min(a, b); },
                                         [](int a, int b) { return min(a, b); },
                                         [](int a, int b) { return a; });

    for(int i=0; i<N; i++) {
        int s, t, x; cin >> s >> t >> x;
        s = max(0, s-x), t = max(0, t-x);
        seg.update(s, t, x);
    }
    for(int i=0; i<Q; i++) {
        int x; cin >> x;
        int res = seg.query(x, x+1);
        if(res == INT_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
}

int main() {
    // DSL_2_D();
    // DSL_2_E();
    // DSL_2_F();
    // DSL_2_G();
    DSL_2_H_simple();
    // DSL_2_H_pair();
    // DSL_2_I();
    // ABC128_E();
    return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

