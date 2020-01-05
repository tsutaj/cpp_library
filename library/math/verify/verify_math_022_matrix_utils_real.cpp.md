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


# :warning: math/verify/verify_math_022_matrix_utils_real.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_022_matrix_utils_real.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../math_022_matrix_utils_real.cpp.html">math/math_022_matrix_utils_real.cpp</a>


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
#include "../math_004_matrix.cpp"
#include "../math_022_matrix_utils_real.cpp"

void tiny_test() {
    int N, M; cin >> N >> M;
    Matrix<double> mat(N, M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }

    cout << fixed << setprecision(12) << detReal(mat) << endl;

    vector<double> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];
    auto ans = linearEquationReal(mat, vec);
    for(auto e : ans) cout << e << " ";
    cout << endl;
}

void AOJ1328() {
    int d;
    using ld = long double;
    const ld EPS = 9e-5;
    while(cin >> d, d) {
        vector<ld> v(d+3);
        for(int i=0; i<d+3; i++) cin >> v[i];

        int row = d+3, col = d+1;
        Matrix<ld> mat(row, col);
        for(int i=0; i<row; i++) {
            ld p = 1;
            for(int j=0; j<col; j++) {
                mat[i][j] = p;
                p *= i;
            }
        }

        for(int i=0; i<row; i++) {
            vector<ld> tm = mat[i];
            ld tv = v[i];
            for(int j=0; j<col; j++) mat[i][j] = 0;
            v[i] = 0;

            auto res = linearEquationReal(mat, v, EPS);
            if(res.size()) {
                cout << i << endl;
                i = d + 5;
            }
            else {
                for(int j=0; j<col; j++) mat[i][j] = tm[j];
                v[i] = tv;
            }
        }
    }
}

int main() {
    tiny_test();
    // AOJ1328(); // linear equation
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_022_matrix_utils_real.cpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
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
#line 1 "math/verify/../math_022_matrix_utils_real.cpp"
// 実数行列に対する主要な操作

// ガウスの消去法 (元の行列を参照で変形、ランクを返す)
template <typename Real>
int gaussianEliminationReal(Matrix<Real> &mat,
                            const Real EPS=1e-9, bool ext=false) {
    int N = mat.size(), M = mat[0].size(), rank = 0;

    // 拡大係数行列なら最後の列は掃き出しの対象にしない
    for(int j=0; j+ext<M; j++) {
        int piv = -1; Real abs_max(0.0);
        for(int i=rank; i<N; i++) {
            Real val(abs(mat[i][j]));
            if(val >= EPS and abs_max < val) abs_max = val, piv = i;
        }
        if(piv < 0) continue;
        swap(mat[rank], mat[piv]);
        Real div(mat[rank][j]);
        for(auto &v : mat[rank]) v /= div;
        for(int i=0; i<N; i++) {
            if(i == rank or abs(mat[i][j]) < EPS) continue;
            Real scale = mat[i][j];
            for(int k=0; k<M; k++) {
                mat[i][k] -= mat[rank][k] * scale;
            }
        }
        rank++;
    }
    return rank;
}

// 線形方程式を解く
// empty なら解なし、M != rank なら無限に存在、そうでなければ一意
template <typename Real>
vector<Real> linearEquationReal(Matrix<Real> A, vector<Real> b,
                                const Real EPS = 1e-9) {
    int N = A.size(), M = A[0].size();
    Matrix<Real> mat(N, M+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M+1; j++) {
            mat[i][j] = (j < M ? A[i][j] : b[i]);
        }
    }

    int rank = gaussianEliminationReal(mat, EPS, true);
    vector<Real> res(N);
    for(int i=0; i<N; i++) {
        res[i] = mat[i][M];
        if(i >= rank and abs(mat[i][M]) > EPS) return {};
    }
    return res;
}

template <typename Real>
Real detReal(Matrix<Real> A, const Real EPS=1e-9) {
    int N = A.size(), cnt_swap = 0;
    for(int j=0; j<N; j++) {
        int piv = -1; Real abs_max(0);
        for(int i=j; i<N; i++) {
            Real val = abs(A[i][j]);
            if(val >= EPS and abs_max < val) abs_max = val, piv = i;
        }
        if(piv < 0) return Real(0);
        cnt_swap += (piv != j);
        swap(A[piv], A[j]);
        for(int i=j+1; i<N; i++) {
            Real scale(A[i][j] / A[j][j]);
            for(int k=0; k<N; k++) {
                A[i][k] -= A[j][k] * scale;
            }
        }
    }

    Real res = (cnt_swap % 2 ? Real(-1) : Real(1));
    for(int i=0; i<N; i++) res *= A[i][i];
    return res;
}
#line 10 "math/verify/verify_math_022_matrix_utils_real.cpp"

void tiny_test() {
    int N, M; cin >> N >> M;
    Matrix<double> mat(N, M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }

    cout << fixed << setprecision(12) << detReal(mat) << endl;

    vector<double> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];
    auto ans = linearEquationReal(mat, vec);
    for(auto e : ans) cout << e << " ";
    cout << endl;
}

void AOJ1328() {
    int d;
    using ld = long double;
    const ld EPS = 9e-5;
    while(cin >> d, d) {
        vector<ld> v(d+3);
        for(int i=0; i<d+3; i++) cin >> v[i];

        int row = d+3, col = d+1;
        Matrix<ld> mat(row, col);
        for(int i=0; i<row; i++) {
            ld p = 1;
            for(int j=0; j<col; j++) {
                mat[i][j] = p;
                p *= i;
            }
        }

        for(int i=0; i<row; i++) {
            vector<ld> tm = mat[i];
            ld tv = v[i];
            for(int j=0; j<col; j++) mat[i][j] = 0;
            v[i] = 0;

            auto res = linearEquationReal(mat, v, EPS);
            if(res.size()) {
                cout << i << endl;
                i = d + 5;
            }
            else {
                for(int j=0; j<col; j++) mat[i][j] = tm[j];
                v[i] = tv;
            }
        }
    }
}

int main() {
    tiny_test();
    // AOJ1328(); // linear equation
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

