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


# :warning: math/verify/verify_math_019_specific_ragrange_polynomial.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_019_specific_ragrange_polynomial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_019_specific_ragrange_polynomial.cpp.html">math/math_019_specific_ragrange_polynomial.cpp</a>
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
#include "../math_019_specific_ragrange_polynomial.cpp"

// Verified on Apr 23, 2019
// Educational Codeforces Round 63 E: Guess the Root
// Judge: https://codeforces.com/contest/1155/problem/E
// TLE が厳しいので逆元は前計算しないと通りません
// あと f(0) から f(N) までわかっていれば O(N) でできるのでそちらの戦略のほうがよいかも
void ECR065_E() {
    const int MOD = 1000003;
    using mint = ModInt<MOD>;

    const int DEG = 11;
    auto eval_expr = [&](vector<mint> &expr, mint x) {
        mint base(1), res(0);
        for(int i=0; i<DEG; i++) {
            res += expr[i] * base;
            base *= x;
        }
        return res;
    };
    
    vector<mint> x, y, expr;
    vector<int> raw_expr = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<DEG; i++) {
        expr.emplace_back(mint(raw_expr[i]));
    }
    
    for(int i=0; i<DEG; i++) {
        x.push_back(mint(i));
        cout << "? " << i << endl;
        int res;
        cin >> res;
        // res = eval_expr(expr, i).v;
        y.push_back(mint(res));
    }

    SpecificLagrangePolynomial<mint> lp(y, MOD);
    for(int i=0; i<MOD; i++) {
        if(lp.interpolate(i) == mint(0)) {
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
}

// Verified on Apr 23, 2019
// AtCoder Regular Contest 033 F (旧 D): 見たことのない多項式
// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4
void ARC033_F() {
    const int MOD = 1000000007;
    using mint = ModInt<MOD>;

    int N; cin >> N;
    vector<mint> y(N+1);
    for(int i=0; i<=N; i++) cin >> y[i];

    int T; cin >> T;
    SpecificLagrangePolynomial<mint> lp(y);
    cout << lp.interpolate(T) << endl;
}

int main() {
    // ECR065_E();
    ARC033_F();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_019_specific_ragrange_polynomial.cpp"
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
#line 1 "math/verify/../math_019_specific_ragrange_polynomial.cpp"
ll mod_pow(ll n, ll k, ll mod) {
    ll res = 1;
    for(; k>0; k>>=1) {
        if(k & 1) (res *= n) %= mod;
        (n *= n) %= mod;
    }
    return res;
}

// N 未満の範囲で、i の逆元 (mod P) を配列に覚える
template <typename NumType>
vector<NumType> get_inv_table(int N, int P) {
    vector<NumType> res;
    for(int i=0; i<N; i++) {
        res.emplace_back(NumType(mod_pow(i, P-2, P)));
    }
    return res;
}

// f(0) ... f(N) の値がわかっているときに
// 多項式補間を O(N) で実現するバージョンのラグランジュ補間
template <typename NumType, int LIMIT = 2000010>
struct SpecificLagrangePolynomial {
    Combination<NumType> comb;
    vector<NumType> y, inv_table;
    bool use_inv_table;
    SpecificLagrangePolynomial() : comb(), y() {}
    SpecificLagrangePolynomial(vector<NumType> y_, int P=LIMIT)
        : comb(min(LIMIT, P-1)), y(y_), use_inv_table(false) {
        if(P < LIMIT) use_inv_table = true;
        
        // get_inv_table がないと CE になるので、
        // コピペが面倒ならここを消す (最悪)
        if(use_inv_table) {
            inv_table = get_inv_table<NumType>(P, P);
        }
    }

    NumType interpolate(NumType p) {
        NumType pre(1);
        int N = y.size(), pv = int(p);
        if(pv < N) return y[pv];
        for(int i=0; i<N; i++) {
            pre *= NumType(pv - i);
        }
        
        NumType res(0);
        for(int i=0; i<N; i++) {
            NumType numer(0), denom(1);
            if(use_inv_table)
                numer = pre * inv_table[pv - i];
            else
                numer = pre / NumType(pv - i);

            denom *= comb.finv(N - 1 - i) * comb.finv(i);
            if((N - 1 - i) % 2) res -= numer * denom * y[i];
            else res += numer * denom * y[i];
        }
        return res;
    }
};
#line 8 "math/verify/verify_math_019_specific_ragrange_polynomial.cpp"

// Verified on Apr 23, 2019
// Educational Codeforces Round 63 E: Guess the Root
// Judge: https://codeforces.com/contest/1155/problem/E
// TLE が厳しいので逆元は前計算しないと通りません
// あと f(0) から f(N) までわかっていれば O(N) でできるのでそちらの戦略のほうがよいかも
void ECR065_E() {
    const int MOD = 1000003;
    using mint = ModInt<MOD>;

    const int DEG = 11;
    auto eval_expr = [&](vector<mint> &expr, mint x) {
        mint base(1), res(0);
        for(int i=0; i<DEG; i++) {
            res += expr[i] * base;
            base *= x;
        }
        return res;
    };
    
    vector<mint> x, y, expr;
    vector<int> raw_expr = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<DEG; i++) {
        expr.emplace_back(mint(raw_expr[i]));
    }
    
    for(int i=0; i<DEG; i++) {
        x.push_back(mint(i));
        cout << "? " << i << endl;
        int res;
        cin >> res;
        // res = eval_expr(expr, i).v;
        y.push_back(mint(res));
    }

    SpecificLagrangePolynomial<mint> lp(y, MOD);
    for(int i=0; i<MOD; i++) {
        if(lp.interpolate(i) == mint(0)) {
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
}

// Verified on Apr 23, 2019
// AtCoder Regular Contest 033 F (旧 D): 見たことのない多項式
// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4
void ARC033_F() {
    const int MOD = 1000000007;
    using mint = ModInt<MOD>;

    int N; cin >> N;
    vector<mint> y(N+1);
    for(int i=0; i<=N; i++) cin >> y[i];

    int T; cin >> T;
    SpecificLagrangePolynomial<mint> lp(y);
    cout << lp.interpolate(T) << endl;
}

int main() {
    // ECR065_E();
    ARC033_F();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

