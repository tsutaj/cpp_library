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


# :warning: structure/verify/verify_strc_004_bit_sec.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_004_bit_sec.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../strc_002_bit.cpp.html">structure/strc_002_bit.cpp</a>
* :warning: <a href="../strc_004_bit_sec.cpp.html">structure/strc_004_bit_sec.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "../strc_002_bit.cpp"
#include "../strc_004_bit_sec.cpp"

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;

    using ll = long long int;
    BIT_sec<ll> bit(N);
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x;
            bit.add(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t;
            cout << bit.sum(s, t) << endl;
        }
    }
}

int main() {
    DSL_2_G();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

