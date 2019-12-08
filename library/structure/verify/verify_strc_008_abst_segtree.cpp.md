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
* category: structure/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [structure/strc_008_abst_segtree.cpp](../strc_008_abst_segtree.cpp.html)


## Code
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

[Back to top page](../../../index.html)

