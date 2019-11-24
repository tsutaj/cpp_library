[トップページに戻る](../index.html)

# math\_003\_digit.cpp
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
// 整数の桁数を調べる (10進数)
template <typename T_digit>
int digit(T_digit n) {
    int ans = 0;
    while(n != 0) {n /= 10; ans++;}
    return ans;
}

// 整数の桁数を調べる (k進数)
template <typename T_digit>
template <typename U_digit>
int digit(T_digit n, U_digit k) {
    int ans = 0;
    while(n != 0) {n /= k; ans++;}
    return ans;
}

// インデックス (10進数)
template <typename T_numIndex>
int numIndex(T_numIndex n, int k) {
    rep(i,0,k) n /= 10;
    return n % 10;
}```

[トップページに戻る](../index.html)
