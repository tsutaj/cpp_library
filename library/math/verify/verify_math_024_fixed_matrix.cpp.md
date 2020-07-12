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


# :warning: math/verify/verify_math_024_fixed_matrix.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_024_fixed_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_024_fixed_matrix.cpp.html">math/math_024_fixed_matrix.cpp</a>
* :heavy_check_mark: <a href="../../structure/strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <valarray>
#include <vector>
#include <functional>
using namespace std;
#include "../math_024_fixed_matrix.cpp"
#include "../math_017_modint.cpp"
#include "../../structure/strc_009_abst_lazy_segtree.cpp"

void CF373_div2_E() {
    using mint = ModInt<1000000007>;
    using Mat = FixedMatrix<mint, 2, 2>;
    using Vec = FixedMatrix<mint, 2, 1>;
 
    auto f = [](Vec a, Mat b) { return b * a; };
    auto g = [](Vec a, Vec b) {
        return a + b;
    };
    auto h = [](Mat a, Mat b) {
        return a * b;
    };
    auto p = [](Mat a, int x) {
        return a;
    };
 
    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;
    Mat E1 = eigen<mint, 2, 2>();
        
    Mat fib;
    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0) = 1;
    fib.at(1, 1) = 0;
    
    Vec vec;
    vec.at(0, 0) = 1, vec.at(1, 0) = 0;
    
    int N, Q; scanf("%d%d", &N, &Q);
    vector<Vec> matrices(N);
    for(int i=0; i<N; i++) {
        int v; scanf("%d", &v);
        Mat pow_fib = pow(fib, v - 1);
        matrices[i] = pow_fib * vec;
    }
    
    LazySegmentTree<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);
    
    while(Q--) {
        int type; scanf("%d", &type);
        if(type == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x); l--;
            Mat pow_fib = pow(fib, x);
            seg.update(l, r, pow_fib);
        }
        if(type == 2) {
            int l, r; scanf("%d%d", &l, &r); l--;
            auto res = seg.query(l, r);
            printf("%lld\n", res.at(0, 0).v);
        }
    }
}

int main() {
    CF373_div2_E();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_024_fixed_matrix.cpp"
#include <iostream>
#include <cstdio>
#include <valarray>
#include <vector>
#include <functional>
using namespace std;
#line 1 "math/math_024_fixed_matrix.cpp"
// 行列ライブラリ

// 演算子: 複合代入 (+=, -=), 単項 (-), 二項 (+, -, *, ==)
// eigen(N): N*N 単位行列を返す
// pow(mat, k): mat の k 乗を返す

template <typename T, int h, int w>
struct FixedMatrix {
    using array_type = array<T, h * w>;
    array_type mat;

    FixedMatrix(T val = T(0)) { mat.fill(val); }
    
    const T& at(int i, int j) const { return mat[i*w + j]; }
    T& at(int i, int j) { return mat[i*w + j]; }

    FixedMatrix<T, h, w> &operator+=(const FixedMatrix<T, h, w>& rhs) {
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                this->at(i, j) += rhs.at(i, j);
            }
        }
        return *this;
    }

    FixedMatrix<T, h, w> operator-() const {
        FixedMatrix<T, h, w> res(*this);
        for(size_t i=0; i<h; i++) {
            for(size_t j=0; j<w; j++) {
                res.at(i, j) *= T(-1);
            }
        }
        return res;
    }

    FixedMatrix<T, h, w> &operator-=(const FixedMatrix<T, h, w>& rhs) {
        return (FixedMatrix<T, h, w>(*this) += -rhs);
    }

    template <int wr>
    FixedMatrix<T, h, wr> operator*(const FixedMatrix<T, w, wr>& rhs) {
        size_t H = h, W = wr, C = w;
        FixedMatrix<T, h, wr> res;
        for(size_t i=0; i<H; i++) {
            for(size_t j=0; j<W; j++) {
                for(size_t k=0; k<C; k++) {
                    res.at(i, j) += this->at(i, k) * rhs.at(k, j);
                }
            }
        }
        return res;
    }

    FixedMatrix<T, h, w> operator+(const FixedMatrix<T, h, w>& rhs) {
        return (FixedMatrix<T, h, w>(*this) += rhs);
    }

    FixedMatrix<T, h, w> operator-(const FixedMatrix<T, h, w> &rhs) {
        return (FixedMatrix<T, h, w>(*this) -= rhs);
    }

    bool operator==(const FixedMatrix<T, h, w> &rhs) const {
        return this->mat == rhs.mat;
    }
    bool operator!=(const FixedMatrix<T, h, w> &rhs) const {
        return !(*this == rhs);
    }
};

template <typename T, int h, int w>
FixedMatrix<T, h, w> eigen() {
    FixedMatrix<T, h, w> res(0);
    for(size_t i=0; i<h; i++) res.at(i, i) = T(1);
    return res;
}

template <typename T, int h, int w>
FixedMatrix<T, h, w> pow(FixedMatrix<T, h, w> mat, long long int k) {
    FixedMatrix<T, h, w> res = eigen<T, h, w>();
    for(; k>0; k>>=1) {
        if(k & 1) res = res * mat;
        mat = mat * mat;
    }
    return res;
}

template <typename T, int h, int w>
ostream& operator<< (ostream& out, FixedMatrix<T, h, w> mat) {
    int H = mat.h, W = mat.w;
    out << "[" << endl;
    for(int i=0; i<H; i++) {
        out << "  [ ";
        for(int j=0; j<W; j++) out << mat.at(i, j) << " ";
        out << "]" << endl;
    }
    out << "]" << endl;
    return out;
}
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
#line 1 "structure/strc_009_abst_lazy_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title 遅延伝播セグメント木 (Lazy Segment Tree)
template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,
                    MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    // range query for [a, b)
    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};
#line 10 "math/verify/verify_math_024_fixed_matrix.cpp"

void CF373_div2_E() {
    using mint = ModInt<1000000007>;
    using Mat = FixedMatrix<mint, 2, 2>;
    using Vec = FixedMatrix<mint, 2, 1>;
 
    auto f = [](Vec a, Mat b) { return b * a; };
    auto g = [](Vec a, Vec b) {
        return a + b;
    };
    auto h = [](Mat a, Mat b) {
        return a * b;
    };
    auto p = [](Mat a, int x) {
        return a;
    };
 
    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;
    Mat E1 = eigen<mint, 2, 2>();
        
    Mat fib;
    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0) = 1;
    fib.at(1, 1) = 0;
    
    Vec vec;
    vec.at(0, 0) = 1, vec.at(1, 0) = 0;
    
    int N, Q; scanf("%d%d", &N, &Q);
    vector<Vec> matrices(N);
    for(int i=0; i<N; i++) {
        int v; scanf("%d", &v);
        Mat pow_fib = pow(fib, v - 1);
        matrices[i] = pow_fib * vec;
    }
    
    LazySegmentTree<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);
    
    while(Q--) {
        int type; scanf("%d", &type);
        if(type == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x); l--;
            Mat pow_fib = pow(fib, x);
            seg.update(l, r, pow_fib);
        }
        if(type == 2) {
            int l, r; scanf("%d%d", &l, &r); l--;
            auto res = seg.query(l, r);
            printf("%lld\n", res.at(0, 0).v);
        }
    }
}

int main() {
    CF373_div2_E();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

