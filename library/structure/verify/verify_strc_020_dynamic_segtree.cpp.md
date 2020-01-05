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


# :warning: structure/verify/verify_strc_020_dynamic_segtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_020_dynamic_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00




## Depends on

* :warning: <a href="../strc_020_dynamic_segtree.cpp.html">動的セグメント木 (Dynamic Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <climits>
#include <utility>
using namespace std;
#include "../strc_020_dynamic_segtree.cpp"

void DSL_2_A() {
    int N, Q; cin >> N >> Q;
    int indexed = 0;

    DynamicSegmentTree<int> seg(N, INT_MAX,
                                [](int a, int b) { return b; },
                                [](int a, int b) { return min(a, b); });
    for(int i=0; i<Q; i++) {
        int q, x, y; cin >> q >> x >> y;
        if(q == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(q == 1) {
            x -= indexed; y -= indexed; y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

void DSL_2_B() {
    int N, Q; cin >> N >> Q;
    int indexed = 1;

    DynamicSegmentTree<int> seg(N, 0,
                                [](int a, int b) { return a + b; },
                                [](int a, int b) { return a + b; });
    for(int i=0; i<Q; i++) {
        int q, x, y; cin >> q >> x >> y;
        if(q == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(q == 1) {
            x -= indexed; y -= indexed; y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

void ARC008_D() {
    using int64 = long long int;
    using DblPair = pair<double, double>;
    
    int64 N, M; cin >> N >> M;
    DynamicSegmentTree<DblPair, int64> seg(N, make_pair(1, 0),
                                           [](DblPair a, DblPair b) {
                                               return b;
                                           },
                                           [](DblPair a, DblPair b) {
                                               // b.f * (a.f * x + a.s) + b.s
                                               // -> (b.f * a.f) x + b.f * a.s + b.s
                                               double ra = a.first * b.first;
                                               double rb = b.first * a.second + b.second;
                                               return make_pair(ra, rb);
                                           });

    double mi = 1, ma = 1;
    for(int i=0; i<M; i++) {
        int64 idx; double a, b;
        cin >> idx >> a >> b; idx--;
        seg.update(idx, make_pair(a, b));

        auto res = seg.query(0, N);
        mi = min(mi, res.first + res.second);
        ma = max(ma, res.first + res.second);
    }
    printf("%.12f\n%.12f\n", mi, ma);
}

int main() {
    // DSL_2_A();
    // DSL_2_B();
    ARC008_D();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_020_dynamic_segtree.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <functional>
#include <climits>
#include <utility>
using namespace std;
#line 1 "structure/verify/../strc_020_dynamic_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title 動的セグメント木 (Dynamic Segment Tree)
// 動的セグメント木 (必要なノードだけ作る)

template <typename MonoidType>
struct SegNode {
    MonoidType value;
    SegNode *ch[2];
    SegNode() {}
    SegNode(MonoidType value_) : value(value_) {
        ch[0] = ch[1] = nullptr;
    }
};

template <typename MonoidType, typename IdxType = int>
struct DynamicSegmentTree {
    using Function = function< MonoidType(MonoidType, MonoidType) >;

    // node, identity element
    IdxType n;
    SegNode<MonoidType> *root;
    MonoidType E0;

    // update / combine function
    Function upd_f, cmb_f;

    // initialize
    DynamicSegmentTree() {
        root = new SegNode<MonoidType>;
    }
    DynamicSegmentTree(IdxType n_, MonoidType E0_,
                       Function upd_f_, Function cmb_f_) :
        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {
        root = new SegNode<MonoidType>(E0_);
        n = 1; while(n < n_) n *= 2;
    }

    void update(SegNode<MonoidType> *node, IdxType k, MonoidType x, IdxType l, IdxType r) {
        if(r - l == 1) {
            node->value = upd_f(node->value, x);
            return;
        }

        IdxType mid = (l + r) / 2;
        MonoidType vl = E0, vr = E0;
        if(l <= k and k < mid) {
            if(!node->ch[0]) node->ch[0] = new SegNode<MonoidType>(E0);
            update(node->ch[0], k, x, l, mid);
        }
        if(mid <= k and k < r) {
            if(!node->ch[1]) node->ch[1] = new SegNode<MonoidType>(E0);
            update(node->ch[1], k, x, mid, r);
        }
        vl = (node->ch[0] ? node->ch[0]->value : E0);
        vr = (node->ch[1] ? node->ch[1]->value : E0);
        node->value = cmb_f(vl, vr);
    }

    MonoidType query(SegNode<MonoidType> *node, IdxType a, IdxType b, IdxType l, IdxType r) {
        if(b <= l or r <= a) return E0;
        if(a <= l and r <= b) return node->value;

        IdxType mid = (l + r) / 2;
        MonoidType vl = (node->ch[0] ? query(node->ch[0], a, b, l, mid) : E0);
        MonoidType vr = (node->ch[1] ? query(node->ch[1], a, b, mid, r) : E0);
        return cmb_f(vl, vr);
    }
    
    // update k-th element (applied value: x)
    void update(IdxType k, MonoidType x) {
        update(root, k, x, 0, n);
    }

    // range query for [a, b)
    MonoidType query(IdxType a, IdxType b) {
        return query(root, a, b, 0, n);
    }
};
#line 11 "structure/verify/verify_strc_020_dynamic_segtree.cpp"

void DSL_2_A() {
    int N, Q; cin >> N >> Q;
    int indexed = 0;

    DynamicSegmentTree<int> seg(N, INT_MAX,
                                [](int a, int b) { return b; },
                                [](int a, int b) { return min(a, b); });
    for(int i=0; i<Q; i++) {
        int q, x, y; cin >> q >> x >> y;
        if(q == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(q == 1) {
            x -= indexed; y -= indexed; y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

void DSL_2_B() {
    int N, Q; cin >> N >> Q;
    int indexed = 1;

    DynamicSegmentTree<int> seg(N, 0,
                                [](int a, int b) { return a + b; },
                                [](int a, int b) { return a + b; });
    for(int i=0; i<Q; i++) {
        int q, x, y; cin >> q >> x >> y;
        if(q == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(q == 1) {
            x -= indexed; y -= indexed; y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

void ARC008_D() {
    using int64 = long long int;
    using DblPair = pair<double, double>;
    
    int64 N, M; cin >> N >> M;
    DynamicSegmentTree<DblPair, int64> seg(N, make_pair(1, 0),
                                           [](DblPair a, DblPair b) {
                                               return b;
                                           },
                                           [](DblPair a, DblPair b) {
                                               // b.f * (a.f * x + a.s) + b.s
                                               // -> (b.f * a.f) x + b.f * a.s + b.s
                                               double ra = a.first * b.first;
                                               double rb = b.first * a.second + b.second;
                                               return make_pair(ra, rb);
                                           });

    double mi = 1, ma = 1;
    for(int i=0; i<M; i++) {
        int64 idx; double a, b;
        cin >> idx >> a >> b; idx--;
        seg.update(idx, make_pair(a, b));

        auto res = seg.query(0, N);
        mi = min(mi, res.first + res.second);
        ma = max(ma, res.first + res.second);
    }
    printf("%.12f\n%.12f\n", mi, ma);
}

int main() {
    // DSL_2_A();
    // DSL_2_B();
    ARC008_D();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

