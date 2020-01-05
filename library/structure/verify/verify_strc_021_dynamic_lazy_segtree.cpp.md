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

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00




## Depends on

* :warning: <a href="../strc_021_dynamic_lazy_segtree.cpp.html">動的遅延セグメント木 (Dynamic Lazy Segment Tree)</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <functional>
using namespace std;
#line 1 "structure/verify/../strc_021_dynamic_lazy_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title 動的遅延セグメント木 (Dynamic Lazy Segment Tree)
// 動的遅延セグメント木 (必要なところだけノードを作る)

template <typename MonoidType, typename OperatorType>
struct LazySegNode {
    MonoidType value;
    OperatorType lazy_value;
    bool need_update;
    LazySegNode *ch[2];
    
    LazySegNode() {}
    LazySegNode(MonoidType value_, OperatorType lazy_value_) :
        value(value_), lazy_value(lazy_value_) {
        need_update = false;
        ch[0] = ch[1] = nullptr;
    }
};

template <typename MonoidType, typename OperatorType, typename IdxType = int>
struct DynamicLazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;
    using LNode = LazySegNode<MonoidType, OperatorType>;

    // node, identity element
    IdxType n;
    LNode *root;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    DynamicLazySegmentTree() {}
    DynamicLazySegmentTree(IdxType n_, MonoidType E0_, OperatorType E1_,
                           MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        root = new LNode(E0_, E1_);
        n = 1; while(n < n_) n *= 2;
    }

    void eval(LNode *node, IdxType l, IdxType r) {
        if(!node->need_update) return;
        node->value = upd_f(node->value, acc_f(node->lazy_value, r - l));
        if(r - l > 1) {
            if(!node->ch[0]) node->ch[0] = new LNode(E0, E1);
            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);
            node->ch[0]->lazy_value = lzy_f(node->ch[0]->lazy_value, node->lazy_value);
            node->ch[1]->lazy_value = lzy_f(node->ch[1]->lazy_value, node->lazy_value);
            node->ch[0]->need_update = node->ch[1]->need_update = true;
        }
        node->lazy_value = E1;
        node->need_update = false;
    }

    void update(LNode *node, IdxType a, IdxType b, OperatorType x,
                IdxType l, IdxType r) {
        eval(node, l, r);
        if(b <= l or r <= a) return;
        if(a <= l and r <= b) {
            node->lazy_value = lzy_f(node->lazy_value, x);
            node->need_update = true;
            eval(node, l, r);
        }
        else {
            IdxType mid = (l + r) / 2;
            if(!node->ch[0]) node->ch[0] = new LNode(E0, E1);
            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);
            update(node->ch[0], a, b, x, l, mid);
            update(node->ch[1], a, b, x, mid, r);
            node->value = cmb_f(node->ch[0]->value, node->ch[1]->value);
        }
    }

    MonoidType query(LNode *node, IdxType a, IdxType b, IdxType l, IdxType r) {
        if(b <= l or r <= a) return E0;
        eval(node, l, r);
        if(a <= l and r <= b) return node->value;
        IdxType mid = (l + r) / 2;
        MonoidType vl = (node->ch[0] ? query(node->ch[0], a, b, l, mid) : E0);
        MonoidType vr = (node->ch[1] ? query(node->ch[1], a, b, mid, r) : E0);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value: x)
    void update(IdxType a, IdxType b, OperatorType x) {
        update(root, a, b, x, 0, n);
    }

    // range query for [a, b)
    MonoidType query(IdxType a, IdxType b) {
        return query(root, a, b, 0, n);
    }
};
#line 8 "structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp"

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

<a href="../../../index.html">Back to top page</a>

