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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_004\_matrix.cpp

## Code

```cpp
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

```

[トップページに戻る](../index.html)
