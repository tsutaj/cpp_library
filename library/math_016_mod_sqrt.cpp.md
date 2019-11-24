<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_016\_mod\_sqrt.cpp
---

## Code

```cpp
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

```

[トップページに戻る](../index.html)
