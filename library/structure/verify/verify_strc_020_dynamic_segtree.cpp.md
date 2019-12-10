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

* category: structure/verify
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_020_dynamic_segtree.cpp">View this file on GitHub</a> (Last commit date: 2019-12-09 17:27:28 +0900)




## Dependencies
* :warning: <a href="../strc_020_dynamic_segtree.cpp.html">動的セグメント木 (Dynamic Segment Tree)</a>


## Code
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

<a href="../../../index.html">Back to top page</a>

