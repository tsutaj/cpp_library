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
* category: math/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [math/math_015_remainder_sum.cpp](../math_015_remainder_sum.cpp.html)
* :warning: [math/math_017_modint.cpp](../math_017_modint.cpp.html)


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

[Back to top page](../../../index.html)

