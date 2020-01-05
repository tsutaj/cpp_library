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


# :warning: math/verify/verify_math_023_matrix_utils_modp.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_023_matrix_utils_modp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-06 07:57:20+09:00




## Depends on

* :warning: <a href="../math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_023_matrix_utils_modp.cpp.html">math/math_023_matrix_utils_modp.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_004_matrix.cpp"
#include "../math_023_matrix_utils_modp.cpp"


void ARC054_C() {
    using mint = ModInt<2>;
    int N; cin >> N;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = mint(1);
        }
    }

    mint d = detModp(mat);
    if(d == mint(0)) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    using mint = ModInt<2>;
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    Matrix<mint> mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = mint(p);
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = mint(p);
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationModp(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != mint(0)) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank;
    cout << ModInt<1000000007>(2).pow(p) << endl;
}

int main() {
    // ARC054_C(); // detModp
    yuki_803(); // gaussianEliminationModp
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_023_matrix_utils_modp.cpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
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
#line 1 "math/verify/../math_004_matrix.cpp"
// 行列ライブラリ

// size(): 行数を返す (列数は mat[0].size() で)
// 演算子: 複合代入 (+=, *=, -=), 単項 (-), 二項 (+, -, *, ==)
// eigen(N): N*N 単位行列を返す
// pow(mat, k): mat の k 乗を返す

template <typename T>
struct Matrix {
    vector< vector<T> > mat;
    Matrix() {}
    Matrix(int h, int w, T val = T(0)) : mat(h, vector<T>(w, val)) {}
    size_t size() const { return mat.size(); }
    const vector<T>& operator[](int i) const { return mat[i]; }
    vector<T>& operator[](int i) { return mat[i]; }

    Matrix<T> &operator+=(const Matrix<T>& rhs) {
        assert(mat.size() == rhs.size());
        assert(mat[0].size() == rhs[0].size());
        for(size_t i=0; i<mat.size(); i++) {
            for(size_t j=0; j<mat[0].size(); j++) {
                mat[i][j] += rhs[i][j];
            }
        }
        return *this;
    }

    Matrix<T> operator-() const {
        Matrix<T> res(*this);
        for(size_t i=0; i<res.size(); i++) {
            for(size_t j=0; j<res[0].size(); j++) {
                res[i][j] *= T(-1);
            }
        }
        return res;
    }

    Matrix<T>& operator-=(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) += -rhs);
    }

    Matrix<T>& operator*=(const Matrix<T>& rhs) {
        assert(mat[0].size() == rhs.size());
        size_t H = mat.size(), W = rhs[0].size(), C = rhs.size();
        Matrix<T> res(H, W);
        for(size_t i=0; i<H; i++) {
            for(size_t j=0; j<W; j++) {
                for(size_t k=0; k<C; k++) {
                    res[i][j] += mat[i][k] * rhs[k][j];
                }
            }
        }
        this->mat = res.mat;
        return *this;
    }

    Matrix<T> operator+(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) += rhs);
    }

    Matrix<T> operator*(const Matrix<T>& rhs) {
        return (Matrix<T>(*this) *= rhs);
    }

    Matrix<T> operator-(const Matrix<T> &rhs) {
        return (Matrix<T>(*this) -= rhs);
    }

    bool operator==(const Matrix<T> &rhs) const {
        return this->mat == rhs.mat;
    }
    bool operator!=(const Matrix<T> &rhs) const {
        return !(*this == rhs);
    }
};

template <typename T>
Matrix<T> eigen(size_t N) {
    Matrix<T> res(N, N, 0);
    for(size_t i=0; i<N; i++) res[i][i] = T(1);
    return res;
}

template <typename T>
Matrix<T> pow(Matrix<T> mat, long long int k) {
    Matrix<T> res = eigen<T>(mat.size());
    for(; k>0; k>>=1) {
        if(k & 1) res *= mat;
        mat *= mat;
    }
    return res;
}

template <typename T>
ostream& operator<< (ostream& out, Matrix<T> mat) {
    int H = mat.size(), W = mat[0].size();
    out << "[" << endl;
    for(int i=0; i<H; i++) {
        out << "  [ ";
        for(int j=0; j<W; j++) out << mat[i][j] << " ";
        out << "]" << endl;
    }
    out << "]" << endl;
    return out;
}
#line 1 "math/verify/../math_023_matrix_utils_modp.cpp"
// mod p 行列に対する主要な操作
// 実数じゃないので絶対値最大のものを pivot にするとかがいらない

// ガウスの消去法
template <typename mint>
int gaussianEliminationModp(Matrix<mint> &mat, bool ext=false) {
    int N = mat.size(), M = mat[0].size(), rank = 0;
    for(int j=0; j+ext<M; j++) {
        int piv = -1;
        for(int i=rank; i<N; i++) {
            if(mat[i][j] != mint(0)) piv = i, i = N;
        }
        if(piv < 0) continue;
        swap(mat[rank], mat[piv]);
        mint div(mat[rank][j]);
        for(auto &v : mat[rank]) v /= div;
        for(int i=0; i<N; i++) {
            if(i == rank or mat[i][j] == mint(0)) continue;
            mint scale = mat[i][j];
            for(int k=0; k<M; k++) {
                mat[i][k] -= mat[rank][k] * scale;
            }
        }
        rank++;
    }
    return rank;
}

template <typename mint>
vector<mint> linearEquationModp(Matrix<mint> A, vector<mint> b) {
    int N = A.size(), M = A[0].size();
    Matrix<mint> mat(N, M+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M+1; j++) {
            mat[i][j] = (j < M ? A[i][j] : b[i]);
        }
    }

    int rank = gaussianEliminationModp(mat, true);
    vector<mint> res(N);
    for(int i=0; i<N; i++) {
        res[i] = mat[i][M];
        if(i >= rank and mat[i][M] != mint(0)) return {};
    }
    return res;
}

template <typename mint>
mint detModp(Matrix<mint> A) {
    int N = A.size(), cnt_swap = 0;
    for(int j=0; j<N; j++) {
        int piv = -1;
        for(int i=j; i<N; i++) {
            if(A[i][j] != mint(0)) piv = i, i = N;
        }
        if(piv < 0) return mint(0);
        cnt_swap += (piv != j);
        swap(A[piv], A[j]);
        for(int i=j+1; i<N; i++) {
            mint scale(A[i][j] / A[j][j]);
            for(int k=0; k<N; k++) {
                A[i][k] -= A[j][k] * scale;
            }
        }
    }

    mint res = (cnt_swap % 2 ? mint(-1) : mint(1));
    for(int i=0; i<N; i++) res *= A[i][i];
    return res;
}
#line 11 "math/verify/verify_math_023_matrix_utils_modp.cpp"


void ARC054_C() {
    using mint = ModInt<2>;
    int N; cin >> N;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = mint(1);
        }
    }

    mint d = detModp(mat);
    if(d == mint(0)) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    using mint = ModInt<2>;
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    Matrix<mint> mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = mint(p);
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = mint(p);
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationModp(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != mint(0)) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank;
    cout << ModInt<1000000007>(2).pow(p) << endl;
}

int main() {
    // ARC054_C(); // detModp
    yuki_803(); // gaussianEliminationModp
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

