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


# :warning: math/verify/verify_math_020_combination.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_020_combination.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_020_combination.cpp.html">math/math_020_combination.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_020_combination.cpp"

// Verified on Apr 23, 2019
// DPL_5: A, B, C, D, E, F, G, I, J, L (写像 12 相)
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=DPL
using mint = ModInt<1000000007>;
const int lim = 2000010;

void DPL_5_A() {
    int N, K; cin >> N >> K;
    mint ans(K);
    cout << ans.pow(N) << endl;
}

void DPL_5_B() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.P(K, N) << endl;
}

void DPL_5_C() {
    int N, K; cin >> N >> K;

    Combination<mint> comb(lim);
    mint ans = comb.S(N, K) * comb.fact(K);
    cout << ans << endl;
}

void DPL_5_D() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.H(K, N) << endl;
}

void DPL_5_E() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(K, N) << endl;
}

void DPL_5_F() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(N-1, K-1) << endl;
}

void DPL_5_G() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.B(N, K) << endl;
}

void DPL_5_I() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.S(N, K) << endl;
}

void DPL_5_J() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N, K) << endl;
}

void DPL_5_L() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N-K, K) << endl;
}

int main() {
    // DPL_5_A();
    // DPL_5_B();
    // DPL_5_C();
    // DPL_5_D();
    // DPL_5_E();
    // DPL_5_F();
    // DPL_5_G();
    // DPL_5_I();
    // DPL_5_J();
    // DPL_5_L();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_020_combination.cpp"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#line 1 "math/verify/../math_017_modint.cpp"
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
#line 1 "math/verify/../math_020_combination.cpp"
// 各種組み合わせを求めるライブラリ
template <typename NumType>
struct Combination {
    int LIMIT;
    vector<NumType> fact_, finv_;

    Combination() {}
    Combination(int LIMIT_) : LIMIT(LIMIT_), fact_(LIMIT+1), finv_(LIMIT+1) {
        fact_[0] = finv_[LIMIT] = NumType(1);
        for(int i=1; i<=LIMIT; i++) {
            fact_[i] = fact_[i-1] * NumType(i);
        }
        
        finv_[LIMIT] /= fact_[LIMIT];
        for(int i=LIMIT-1; i>=0; i--) {
            finv_[i] = finv_[i+1] * NumType(i+1);
        }
    }

    inline NumType fact(int k) const { return fact_[k]; }
    inline NumType finv(int k) const { return finv_[k]; }
    NumType P(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r];
    }
    NumType C(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r] * finv_[r];
    }
    // 重複組み合わせ
    NumType H(int n, int r) const {
        if(n < 0 or r < 0) return NumType(0);
        return r == 0 ? NumType(1) : C(n + r - 1, r);
    }
    // ベル数 (区別できる n 個のボールを区別できない k 個以下の箱に分割)
    // B(n, n) := n 個のボールを任意個のグループに分割する場合の数
    NumType B(int n, int k) const {
        if(n == 0) return NumType(1);
        k = min(n, k);
        NumType ret(0);
        vector<NumType> pref(k + 1); pref[0] = NumType(1);
        for(int i=1; i<=k; i++) {
            if(i & 1) pref[i] = pref[i-1] - finv_[i];
            else pref[i] = pref[i-1] + finv_[i];
        }
        for(int i=1; i<=k; i++) {
            // 累乗が必要なので適宜書き換える？
            // ModInt 使うならこれでいい
            ret += NumType(i).pow(n) * finv_[i] * pref[k-i];
        }
        return ret;
    }
    // スターリング数 (区別できる n 個のボールを区別できない k 個の箱に分割)
    NumType S(int n, int k) const {
        if(n < k) return NumType(0);
        NumType ans(0);
        for(int i=0; i<=k; i++) {
            NumType val = C(k, i) * NumType(i).pow(n);
            if((k - i) % 2) ans -= val;
            else ans += val;
        }
        return ans * finv_[k];
    }

    // ランダムウォーク: 左に X 回、右に Y 回進むとき、
    // 移動途中・終了時に座標 K を超えないものを数える
    // K が非負なら左側、負なら右側領域 (？) のランダムウォーク
    NumType walk(int X, int Y, int K) {
        if(K < 0) return walk(Y, X, -K);
        if(Y <= K) return C(X+Y, X); // 引っかからない
        if(Y - X > K) return NumType(0); // そもそも合計が超える
        
        int A = Y - K - 1, B = X + K + 1;
        return C(X+Y, X) - C(A+B, A);
    }
};

// P(n, k) := n の k 分割 (k 個の 0 以上の整数の和)
template <typename NumType, int LIMIT = 3010>
struct Partition {
    vector< vector<NumType> > dp;
    Partition() : dp(LIMIT, vector<NumType>(LIMIT)) {
        for(int k=0; k<LIMIT; k++) dp[0][k] = NumType(1);
        for(int i=1; i<LIMIT; i++) {
            for(int j=1; j<LIMIT; j++) {
                dp[i][j] += dp[i][j-1];
                if(i-j >= 0) dp[i][j] += dp[i-j][j];
            }
        }
    }
    inline NumType get(int n, int k) {
        if(n < 0 or k < 0) return NumType(0);
        return dp[n][k];
    }
};
#line 7 "math/verify/verify_math_020_combination.cpp"

// Verified on Apr 23, 2019
// DPL_5: A, B, C, D, E, F, G, I, J, L (写像 12 相)
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=DPL
using mint = ModInt<1000000007>;
const int lim = 2000010;

void DPL_5_A() {
    int N, K; cin >> N >> K;
    mint ans(K);
    cout << ans.pow(N) << endl;
}

void DPL_5_B() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.P(K, N) << endl;
}

void DPL_5_C() {
    int N, K; cin >> N >> K;

    Combination<mint> comb(lim);
    mint ans = comb.S(N, K) * comb.fact(K);
    cout << ans << endl;
}

void DPL_5_D() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.H(K, N) << endl;
}

void DPL_5_E() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(K, N) << endl;
}

void DPL_5_F() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(N-1, K-1) << endl;
}

void DPL_5_G() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.B(N, K) << endl;
}

void DPL_5_I() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.S(N, K) << endl;
}

void DPL_5_J() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N, K) << endl;
}

void DPL_5_L() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N-K, K) << endl;
}

int main() {
    // DPL_5_A();
    // DPL_5_B();
    // DPL_5_C();
    // DPL_5_D();
    // DPL_5_E();
    // DPL_5_F();
    // DPL_5_G();
    // DPL_5_I();
    // DPL_5_J();
    // DPL_5_L();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

