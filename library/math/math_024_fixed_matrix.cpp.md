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


# :warning: math/math_024_fixed_matrix.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_024_fixed_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Required By
* :warning: <a href="../graph/verify/verify_graph_020_HLDecomposition.cpp.html">graph/verify/verify_graph_020_HLDecomposition.cpp</a>
* :warning: <a href="verify/verify_math_024_fixed_matrix.cpp.html">math/verify/verify_math_024_fixed_matrix.cpp</a>


## Code
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

