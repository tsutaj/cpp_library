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


# :warning: structure/verify/verify_strc_008_abst_segtree.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_008_abst_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00




## Depends on

* :warning: <a href="../strc_008_abst_segtree.cpp.html">セグメント木 (Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
#include "../strc_008_abst_segtree.cpp"

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

// Range Minimum Query
// query 1: update
// query 2: range minimum
void DSL_2_A() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, INT_MAX,
                         [](int a, int b) { return b; },
                         [](int a, int b) { return min(a, b); });

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

// Range Sum Query
// query 1: add
// query 2: range sum
void DSL_2_B() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) { return a + b; });

    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

int main() {
    // DSL_2_A();
    DSL_2_B();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_008_abst_segtree.cpp"
#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
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
#line 8 "structure/verify/verify_strc_008_abst_segtree.cpp"

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

// Range Minimum Query
// query 1: update
// query 2: range minimum
void DSL_2_A() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, INT_MAX,
                         [](int a, int b) { return b; },
                         [](int a, int b) { return min(a, b); });

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

// Range Sum Query
// query 1: add
// query 2: range sum
void DSL_2_B() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) { return a + b; });

    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

int main() {
    // DSL_2_A();
    DSL_2_B();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
