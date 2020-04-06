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
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_015_remainder_sum.cpp.html">math/math_015_remainder_sum.cpp</a>
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_015_remainder_sum.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#line 1 "math/math_017_modint.cpp"
// ModInt begin

using ll = long long;
template<ll mod>
struct ModInt {
    ll v;
    ll mod_pow(ll x, ll n) const {
        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;
    }
    ModInt(ll a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
    ModInt operator+ ( const ModInt& b ) const {
        return (v + b.v >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));
    }
    ModInt operator- () const {
        return ModInt(-v);
    }
    ModInt operator- ( const ModInt& b ) const {
        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));
    }
    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}
    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2)) % mod;}
    
    bool operator== ( const ModInt &b ) const {return v == b.v;}
    bool operator!= ( const ModInt &b ) const {return !(*this == b); }
    ModInt& operator+= ( const ModInt &b ) {
        v += b.v;
        if(v >= mod) v -= mod;
        return *this;
    }
    ModInt& operator-= ( const ModInt &b ) {
        v -= b.v;
        if(v < 0) v += mod;
        return *this;
    }
    ModInt& operator*= ( const ModInt &b ) {
        (v *= b.v) %= mod;
        return *this;
    }
    ModInt& operator/= ( const ModInt &b ) {
        (v *= mod_pow(b.v, mod-2)) %= mod;
        return *this;
    }
    ModInt pow(ll x) { return ModInt(mod_pow(v, x)); }
    // operator int() const { return int(v); }
    // operator long long int() const { return v; }
};

template<ll mod>
ModInt<mod> pow(ModInt<mod> n, ll k) {
    return ModInt<mod>(n.mod_pow(n.v, k));
}

template<ll mod>
ostream& operator<< (ostream& out, ModInt<mod> a) {return out << a.v;}
template<ll mod>
istream& operator>> (istream& in, ModInt<mod>& a) {
    in >> a.v;
    return in;
}

// ModInt end
#line 1 "math/math_015_remainder_sum.cpp"
// F(i) := P (mod 1) + P (mod 2) + ... + P (mod i) を計算
// 答えは NumType 型で返ってくる
template <typename NumType, int K = 10000000>
struct RemainderSum {
    using lint = long long;
    lint P;
    vector<NumType> small_case;
    RemainderSum(lint P_) {
        P = P_;
        build();
    }

    // 小さいケースに対する答えを覚える
    void build() {
        small_case.resize(K + 1, NumType(0));
        for(lint i=1; i<=K; i++) {
            NumType mod(P % i);
            small_case[i] = small_case[i-1] + mod;
        }
    }

    // [1, x] (閉区間であることに注意！！)
    // F(x) を計算 
    NumType sum_func(lint x) {
        if(x <= K) return small_case[x];
        return small_case[K] + sum_func(K+1, x);
    }

    // [l, r] (閉区間であることに注意！！)
    // P (mod l) + P (mod l+1) + ... + P (mod r) を計算
    NumType sum_func(lint l, lint r) {
        if(r <= K) return small_case[r] - small_case[l-1];
        if(l <= K) return small_case[K] - small_case[l-1] + sum_func(K+1, r);

        NumType ans(0);
        // l も r も、 K を超える値である
        lint dmax = P / l, dmin = P / r, num = l;
        for(lint div=dmax; div>=dmin; div--) {
            if(div == 0) {
                // 商が div になるような要素のインデックス (閉区間)
                lint idx_l = max(l, P + 1);
                lint idx_r = r;
                NumType range(idx_r - idx_l + 1);

                // このときの剰余の値は全て P に等しい
                NumType sum = range * NumType(P);
                ans += sum;
            }
            else {
                // 商が div になるような要素のインデックス (閉区間)
                lint idx_l = max(l, P / (div + 1) + 1);
                lint idx_r = min(r, P / div);
                NumType range(idx_r - idx_l + 1);
                
                // 左端と右端について、その剰余の値
                NumType mod_l(P % idx_l);
                NumType mod_r(P % idx_r);
                
                // 等差数列の和
                NumType sum = range * (mod_l + mod_r) / NumType(2);
                ans += sum;
                
                // 次の div を求める (1 ずつ減らない場合がある)
                if(P / num != P / (num + 1)) {
                    div = P / (num + 1) + 1;
                    num++;
                }
            }
        }
        return ans;
    }
};
#line 8 "math/verify/verify_math_015_remainder_sum.cpp"

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

