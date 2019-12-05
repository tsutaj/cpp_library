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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../math/verify/verify_math_016_mod_sqrt.cpp
* category: ../../math/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../math/math_016_mod_sqrt.cpp](../math_016_mod_sqrt.cpp.html)


## Code
```cpp
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
#include "../math_016_mod_sqrt.cpp"

// Verified on Apr 09, 2019
// yukicoder No.551: 夏休みの思い出 (2)
// Judge: https://yukicoder.me/problems/no/551
void yuki_551() {
    using lint = long long int;
    lint P, R, Q; cin >> P >> R >> Q;
    QuadraticResidue qr;
    while(Q--) {
        lint A, B, C; scanf("%lld%lld%lld", &A, &B, &C);
        lint r = qr.mod_inv(A, P);
        (A *= r) %= P;
        (B *= r) %= P;
        (C *= r) %= P;
        (B *= qr.mod_inv(2, P)) %= P;

        lint D = (P - C + (B*B%P)) % P;
        if(D == 0) {
            printf("%lld\n", (P - B) % P);
        }
        else {
            // D の平方根を求める
            vector<lint> ks = qr.TonelliShanks(D, P);
            if(ks.size() == 0) {
                printf("-1\n");
            }
            else {
                lint X = (2*P + ks[0] - B) % P;
                lint Y = (2*P + ks[1] - B) % P;
                if(X > Y) swap(X, Y);
                printf("%lld %lld\n", X, Y);
            }
        }
    }
}

int main() {
    yuki_551();
}

```

[Back to top page](../../../index.html)

