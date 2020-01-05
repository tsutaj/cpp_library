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


# :warning: math/verify/verify_math_018_ragrange_polynomial.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_018_ragrange_polynomial.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_018_ragrange_polynomial.cpp.html">math/math_018_ragrange_polynomial.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_018_ragrange_polynomial.cpp"

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
    
    for(int i=1; i<=DEG; i++) {
        x.push_back(mint(i));
        cout << "? " << i << endl;
        int res;
        cin >> res;
        // res = eval_expr(expr, i).v;
        y.push_back(mint(res));
    }

    LagrangePolynomial<mint> lp(x, y, MOD);
    for(int i=0; i<MOD; i++) {
        if(lp.interpolate(i) == mint(0)) {
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
}

// Verified (部分点, N <= 3000) on Apr 23, 2019
// AtCoder Regular Contest 033 F (旧 D): 見たことのない多項式
// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4
void ARC033_F_PART() {
    const int MOD = 1000000007;
    using mint = ModInt<MOD>;

    int N; cin >> N;
    if(N > 3000) exit(1);
    
    vector<mint> x(N+1);
    vector<mint> y(N+1);
    for(int i=0; i<=N; i++) {
        x[i] = mint(i);
        cin >> y[i];
    }

    int T; cin >> T;
    LagrangePolynomial<mint> lp(x, y);
    cout << lp.interpolate(T) << endl;
}

int main() {
    // ECR065_E();
    ARC033_F_PART();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_018_ragrange_polynomial.cpp"
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
#line 1 "math/verify/../math_018_ragrange_polynomial.cpp"
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

// ラグランジュ補間
// 観測された (x_i, y_i) を元に多項式を補間
// 元の式が N 次式で N+1 個の点が観測されている場合は元の式が復元可能
// 観測された点を N とすると O(N^2) で動く
template <typename NumType>
struct LagrangePolynomial {
    vector<NumType> x, y, f_table, inv_table;
    bool use_inv_table;
    LagrangePolynomial() : x(), y() {}
    LagrangePolynomial(vector<NumType> x_,
                       vector<NumType> y_,
                       int P=-1)
        : x(x_), y(y_), use_inv_table(P > 0) {

        int N = x.size();
        for(int i=0; i<N; i++) {
            f_table.emplace_back(f(i, x[i]));
        }

        // get_inv_table がないと CE になるので、
        // コピペが面倒ならここを消す (最悪)
        if(use_inv_table) {
            inv_table = get_inv_table<NumType>(P, P);
        }
    }

    NumType f(int i, NumType p) {
        int N = x.size();
        NumType res(1);
        for(int k=0; k<N; k++) {
            if(i == k) continue;
            res *= NumType(p - x[k]);
        }
        return res;
    }

    NumType interpolate(NumType p) {
        int N = x.size();
        NumType res(0);
        for(int i=0; i<N; i++) {
            if(use_inv_table) {
                res += y[i] * f(i, p) * inv_table[ int(f_table[i]) ];
            }
            else {
                res += y[i] * f(i, p) / f_table[i];
            }
        }
        return res;
    }
};
#line 7 "math/verify/verify_math_018_ragrange_polynomial.cpp"

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
    
    for(int i=1; i<=DEG; i++) {
        x.push_back(mint(i));
        cout << "? " << i << endl;
        int res;
        cin >> res;
        // res = eval_expr(expr, i).v;
        y.push_back(mint(res));
    }

    LagrangePolynomial<mint> lp(x, y, MOD);
    for(int i=0; i<MOD; i++) {
        if(lp.interpolate(i) == mint(0)) {
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
}

// Verified (部分点, N <= 3000) on Apr 23, 2019
// AtCoder Regular Contest 033 F (旧 D): 見たことのない多項式
// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4
void ARC033_F_PART() {
    const int MOD = 1000000007;
    using mint = ModInt<MOD>;

    int N; cin >> N;
    if(N > 3000) exit(1);
    
    vector<mint> x(N+1);
    vector<mint> y(N+1);
    for(int i=0; i<=N; i++) {
        x[i] = mint(i);
        cin >> y[i];
    }

    int T; cin >> T;
    LagrangePolynomial<mint> lp(x, y);
    cout << lp.interpolate(T) << endl;
}

int main() {
    // ECR065_E();
    ARC033_F_PART();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

