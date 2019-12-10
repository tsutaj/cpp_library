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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/math_005_matrix_mod2.cpp
<a href="../../index.html">Back to top page</a>

* category: math
* <a href="{{ site.github.repository_url }}/blob/master/math/math_005_matrix_mod2.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Required
* :warning: <a href="verify/verify_math_005_matrix_mod2.cpp.html">math/verify/verify_math_005_matrix_mod2.cpp</a>


## Code
{% raw %}
```cpp
// mod2 行列ライブラリ (bitset を使って高速化、横は SIZE 固定とする)
// TODO: 乗算の verify
struct BinaryMatrix {
    int H, W;
    static const int SIZE = 2010;
    vector< bitset<SIZE> > mat;
    BinaryMatrix(int H_, int W_) : H(H_), W(W_), mat(H_) {}

    // 乗算に使用 (これ微妙に転置じゃないけどなんていうんだ)
    BinaryMatrix T(const BinaryMatrix& A) {
        int h = A.H, w = A.W;
        BinaryMatrix res(w, h);
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                res[j][i] = A[i][j];
            }
        }
        return res;
    }

    BinaryMatrix& operator*=(const BinaryMatrix& rhs) {
        assert(W == rhs.H);
        BinaryMatrix res(H, rhs.W), trhs = T(rhs);
        for(int i=0; i<H; i++) {
            for(int j=0; j<rhs.W; j++) {
                res[i][j] = (mat[i] & trhs[j]).count() % 2;
            }
        }
        return (*this = res);
    }
    BinaryMatrix& operator+=(const BinaryMatrix &rhs) {
        assert(H == rhs.H and W == rhs.W);
        for(int i=0; i<H; i++) mat[i] ^= rhs[i];
        return *this;
    }
    BinaryMatrix& operator-=(const BinaryMatrix &rhs) {
        return (*this += rhs);
    }

    BinaryMatrix operator*(const BinaryMatrix &rhs) {
        return (BinaryMatrix(*this) *= rhs);
    }
    BinaryMatrix operator+(const BinaryMatrix &rhs) {
        return (BinaryMatrix(*this) += rhs);
    }
    BinaryMatrix operator-(const BinaryMatrix &rhs) {
        return (BinaryMatrix(*this) -= rhs);
    }

    bool operator==(const BinaryMatrix &rhs) const {
        if(H != rhs.H or W != rhs.W) return false;
        for(int i=0; i<H; i++) if(mat[i] != rhs[i]) return false;
        return true;
    }
    bool operator!=(const BinaryMatrix &rhs) const {
        return !(*this == rhs);
    }

    const bitset<SIZE>& operator[](int k) const { return mat[k]; }
    bitset<SIZE>& operator[](int k) { return mat[k]; }
};

BinaryMatrix eigen(size_t N) {
    BinaryMatrix res(N, N);
    for(size_t i=0; i<N; i++) res[i][i] = 1;
    return res;
}

BinaryMatrix pow(BinaryMatrix mat, long long int k) {
    BinaryMatrix res = eigen(mat.H);
    for(; k>0; k>>=1) {
        if(k & 1) res *= mat;
        mat *= mat;
    }
    return res;
}

int gaussianEliminationBinary(BinaryMatrix &mat, bool ext=false) {
    int N = mat.H, M = mat.W, rank = 0;
    for(int j=0; j+ext<M; j++) {
        int piv = -1;
        for(int i=rank; i<N; i++) {
            if(mat[i][j] != 0) piv = i, i = N;
        }
        if(piv < 0) continue;
        swap(mat[rank], mat[piv]);
        for(int i=0; i<N; i++) {
            if(i == rank or mat[i][j] == 0) continue;
            mat[i] ^= mat[rank];
        }
        rank++;
    }
    return rank;
}

vector<int> linearEquationBinary(BinaryMatrix A, vector<int> b) {
    int N = A.H, M = A.W;
    BinaryMatrix mat(N, M+1);
    for(int i=0; i<N; i++) {
        for(int j=0; j<=M; j++) {
            mat[i][j] = (j < M ? A[i][j] : b[i]);
        }
    }

    int rank = gaussianEliminationBinary(mat, true);
    vector<int> res(N);
    for(int i=0; i<N; i++) {
        res[i] = mat[i][M];
        if(i >= rank and mat[i][M] != 0) return {};
    }
    return res;
}

int detBinary(BinaryMatrix A) {
    int N = A.H;
    for(int j=0; j<N; j++) {
        int piv = -1;
        for(int i=j; i<N; i++) {
            if(A[i][j] != 0) piv = i, i = N;
        }
        if(piv < 0) return 0;
        swap(A[piv], A[j]);
        for(int i=j+1; i<N; i++) {
            if(A[i][j]) A[i] ^= A[j];
        }
    }
    int res = 1;
    for(int i=0; i<N; i++) res *= A[i][i];
    return res;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

