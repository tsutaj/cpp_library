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


# :warning: structure/verify/verify_strc_023_compact_bitvector.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_023_compact_bitvector.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28 +0900




## Depends On
* :heavy_check_mark: <a href="../strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>


## Code
{% raw %}
```cpp
#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"

int main() {
    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];

    SuccinctBitVector<> sb(vec);
    for(int i=0; i<N; i++) {
        cout << sb.rank(i) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_nxt(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_pre(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;

    cout << "count: " << sb.count() << ", size = " << sb.size() << endl;
    
/*
    while(true) {
        int q; cin >> q;
        if(q == 1) {
            int k; cin >> k; k--;
            cout << sb.rank(k) << endl;
        }
        if(q == 2) {
            int k; cin >> k; k--;
            int a = sb.select_nxt(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 3) {
            int k; cin >> k; k--;
            int a = sb.select_pre(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 4) {
            int l, r; cin >> l >> r; l--;
            cout << sb.rank(l, r) << endl;
        }
    }
*/
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

