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


# :warning: structure/verify/verify_strc_022_dual_segtree.cpp
<a href="../../../index.html">Back to top page</a>

* category: structure/verify
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_022_dual_segtree.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28 +0900




## Depends On
* :warning: <a href="../strc_022_dual_segtree.cpp.html">双対セグメント木 (Dual Segment Tree)</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
#include <climits>
#include <map>
using namespace std;
#include "../strc_022_dual_segtree.cpp"

void DSL_2_D() {
    int N, Q; cin >> N >> Q;
    using Pair = pair<int, int>;
    DualSegmentTree<int, Pair> seg(make_pair(0, 0),
                                   [](int x, Pair p) {
                                       if(p.second == 0) return x;
                                       return p.first;
                                   },
                                   [](Pair a, Pair b) {
                                       return b.second ? b : a;
                                   },
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
            cout << seg.query(x) << endl;
        }
    }
}

void DSL_2_E() {
    int N, Q; cin >> N >> Q;
    DualSegmentTree<int, int> seg(0,
                                  [](int a, int b) { return a + b; },
                                  [](int a, int b) { return a + b; },
                                  vector<int>(N, 0));
    
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
            cout << seg.query(s) << endl;
        }
        // seg.dump();
    }    
}

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
    
    DualSegmentTree<int, int> seg(INT_MAX,
                                  [](int a, int b) { return min(a, b); },
                                  [](int a, int b) { return min(a, b); },
                                  vector<int>(id, INT_MAX));
    
    for(int i=0; i<N; i++) {
        seg.update(s[i], t[i], x[i]);
    }
    for(int i=0; i<Q; i++) {
        int res = seg.query(p[i]);
        if(res == INT_MAX) cout << -1 << endl;
        else cout << res << endl;
    }
}

int main() {
    DSL_2_D();
    // DSL_2_E();
    // ABC128_E();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

