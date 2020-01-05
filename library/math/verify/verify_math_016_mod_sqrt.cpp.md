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


# :warning: math/verify/verify_math_016_mod_sqrt.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_016_mod_sqrt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../math_016_mod_sqrt.cpp.html">math/math_016_mod_sqrt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_016_mod_sqrt.cpp"
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
using namespace std;
#line 1 "math/verify/../math_016_mod_sqrt.cpp"
// Tonelli-Shanks Algorithm
// 素数 p を法とし、n が与えられたとき、
// r^2 = n (mod p) を満たす r を求める

struct QuadraticResidue {
    using lint = long long int;
    QuadraticResidue() {}

    // x^k (mod p)
    lint mod_pow(lint x, lint k, lint p) {
        lint res = 1;
        for(; k>0; k>>=1) {
            if(k & 1) (res *= x) %= p;
            (x *= x) %= p;
        }
        return res;
    }

    lint mod_inv(lint x, lint p) {
        return mod_pow(x, p-2, p);
    }

    // ルジャンドル記号 (a/p) = a^{\frac{p-1}{2}} (p が奇素数の場合)
    // (a/p) =  0 ... a = 0 (mod p)
    // (a/p) =  1 ... a が p を法として平方剰余
    // (a/p) = -1 ... a が p を法として平方剰余でない
    // 平方根の解の存在がこれで確認できる
    lint Legendre(lint a, lint p) {
        if(a % p == 0) return 0;
        lint res = mod_pow(a, (p-1)/2, p);
        if(res == p-1) return -1;
        return res;
    }

    // r^2 = n (mod p) なる r を求める (mod p 上での n の平方根)
    vector<lint> TonelliShanks(lint n, lint p) {
        if(Legendre(n, p) == -1) return {};
        if(p == 2) {
            if(n == 0) return {0};
            if(n == 1) return {1};
        }

        lint Q = p - 1, S = 0;
        while(Q % 2 == 0) Q /= 2, S++;

        lint z = 2;
        while(z < p and Legendre(z, p) != -1) z++;
        if(z == p) return {};
        
        lint M = S;
        lint c = mod_pow(z, Q, p);
        lint t = mod_pow(n, Q, p);
        lint R = mod_pow(n, (Q+1)/2, p);

        lint r = -1;
        while(1) {
            if(t == 0) { r = 0; break; }
            if(t == 1) { r = R; break; }

            lint i = 1, tt = t * t % p;
            for(i=1; i<M; i++) {
                if(tt == 1) break;
                tt = tt * tt % p;
            }
            if(i == M) return {};

            lint b = c;
            for(lint j=0; j<M-i-1; j++) {
                b = b * b % p;
            }
            
            M = i;
            c = b * b % p;
            t = t * c % p;
            R = R * b % p;
        }

        vector<lint> ans;
        ans.push_back(r);
        if(r != p - r) ans.push_back(p - r);
        return ans;
    }
};
#line 8 "math/verify/verify_math_016_mod_sqrt.cpp"

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
{% endraw %}

<a href="../../../index.html">Back to top page</a>

