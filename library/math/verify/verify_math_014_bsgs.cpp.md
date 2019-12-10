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


# :warning: math/verify/verify_math_014_bsgs.cpp
<a href="../../../index.html">Back to top page</a>

* category: math/verify
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_014_bsgs.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Dependencies
* :warning: <a href="../math_014_bsgs.cpp.html">math/math_014_bsgs.cpp</a>


## Code
{% raw %}
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <cmath>
using namespace std;
#include "../math_014_bsgs.cpp"

// Verified on Mar 28, 2019
// Taipei Regional Contest 2015: D
// Judge: https://vjudge.net/contest/271429#problem/D
void TaipeiRegional2015_D() {
    int a, b, prime; cin >> prime;
    while(scanf("%d%d", &a, &b) == 2) {
        DiscreteLogarithm<int> dl;
        int ans = dl.BSGS(a, b, prime);
        if(ans < 0) puts("0");
        else printf("%d\n", ans);
    }
}

// Verified on Mar 30, 2019
// yukicoder No.551: 夏休みの思い出 (2)
// Judge: https://yukicoder.me/problems/no/551
void yuki_551() {
    using lint = long long int;
    lint P, R, Q; cin >> P >> R >> Q;
    double ratio = 0.3;
    DiscreteLogarithm<lint> dl(R, P, ratio);
    while(Q--) {
        lint A, B, C; scanf("%lld%lld%lld", &A, &B, &C);
        lint r = dl.mod_inv(A, P);
        (A *= r) %= P;
        (B *= r) %= P;
        (C *= r) %= P;
        (B *= dl.mod_inv(2, P)) %= P;

        lint D = (P - C + (B*B%P)) % P;
        if(D == 0) {
            printf("%lld\n", (P - B) % P);
        }
        else {
            // R^k = D なる k を求める
            // k が奇数 ... 解なし
            // k が偶数 ... k/2 と k/2 + (P-1)/2 が解
            lint k = dl.BSGS(R, D, P, true, ratio);
            if(k < 0 or k % 2 == 1) {
                printf("-1\n");
            }
            else {
                lint sqrtd = dl.mod_pow(R, k/2, P);
                lint X = (2*P + sqrtd - B) % P;
                lint Y = (2*P - sqrtd - B) % P;
                if(X > Y) swap(X, Y);
                printf("%lld %lld\n", X, Y);
            }
        }
    }
}

int main() {
    TaipeiRegional2015_D();
    // yuki_551();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

