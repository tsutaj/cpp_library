[トップページに戻る](../index.html)

# strc\_004\_bit\_sec.cpp
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
// 次の2つのクエリに対応するBIT
// ・[a, b) の要素全てに x を加えるクエリ
// ・[a, b) の和を計算するクエリ
// Verified: POJ 3468 (A Simple Problem with Integers)

template <typename U>
class BIT_sec {
public:
    int n;
    BIT<U> bit0, bit1;
    BIT_sec(int n_) {
        n = n_;
        bit0 = BIT<U>(n);
        bit1 = BIT<U>(n);
    }

    // 最初に要素を追加するときはこっち
    void add(int i, int x) {
        bit0.add(i, x);
    }

    // [l, r] の全要素に x を加える
    void add(int l, int r, U x) {
        bit0.add(l, -x * (l-1));
        bit1.add(l, x);
        bit0.add(r+1, x*r);
        bit1.add(r+1, -x);
    }

    U sum(int l, int r) {
        U res = 0;
        res += bit0.sum(r) + bit1.sum(r) * r;
        res -= bit0.sum(l-1) + bit1.sum(l-1) * (l-1);
        return res;
    }
};
```

[トップページに戻る](../index.html)
