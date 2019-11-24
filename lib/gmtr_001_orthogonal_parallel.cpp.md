[トップページに戻る](../index.html)

# gmtr\_001\_orthogonal\_parallel.cpp
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
/***** 直交・平行判定 *****/
// Verified: AOJ CGL_2_A: Parallel/Orthogonal

// 2直線の直交判定 (内積が0であること)
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
    return EQ( dot(a1-a2, b1-b2), 0.0 );
}

// 2直線の平行判定 (外積が0であること)
bool is_parallel(Point a1, Point a2, Point b1, Point b2) {
    return EQ( cross(a1-a2, b1-b2), 0.0 );
}
```

[トップページに戻る](../index.html)
