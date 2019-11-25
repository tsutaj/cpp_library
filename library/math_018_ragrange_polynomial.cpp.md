<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_018\_ragrange\_polynomial.cpp

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

```

[トップページに戻る](../index.html)
