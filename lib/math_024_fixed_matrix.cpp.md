[トップページに戻る](../index.html)

# math\_024\_fixed\_matrix.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

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

[トップページに戻る](../index.html)
