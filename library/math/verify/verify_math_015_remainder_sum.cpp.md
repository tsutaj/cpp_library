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


# :warning: math/verify/verify_math_015_remainder_sum.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_015_remainder_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../math_015_remainder_sum.cpp.html">math/math_015_remainder_sum.cpp</a>
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>


## Code
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_015_remainder_sum.cpp"

// Verified on Mar 30, 2019
// Educational Codeforces Round 5 E: Sum of Remainders
// Judge: https://codeforces.com/contest/616/problem/E
void ECR005_E() {
    long long int N, M; cin >> N >> M;
    using mint = ModInt<1000000007>;
    RemainderSum<mint> rs(N);
    cout << rs.sum_func(M) << endl;
}

// Verified on Mar 30, 2019
// yukicoder No. 752: mod 数列
// Judge: https://yukicoder.me/problems/no/752
void yuki_752() {
    long long int P, Q; cin >> P >> Q;
    RemainderSum<long long int> rs(P);
    while(Q--) {
        long long int l, r; cin >> l >> r;
        cout << rs.sum_func(l, r) << endl;
    }
}

int main() {
    ECR005_E();
    // yuki_752();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

