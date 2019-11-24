<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_019\_specific\_ragrange\_polynomial.cpp

## Code

```cpp
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

```

[トップページに戻る](../index.html)
