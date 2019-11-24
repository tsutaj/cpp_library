[トップページに戻る](../index.html)

# math\_000\_limits.cpp
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
#include <climits>
#include <cfloat>

[int]
INT_MIN ～ INT_MAX
-2^31 ～ 2^31 - 1
-2147483648 ～ 2147483647

[unsigned int]
0 ～ UINT_MAX
0 ～ 2^32 - 1
0 ～ 4294967295

[long long]
LLONG_MIN ～ LLONG_MAX
-2^63 ～ 2^63 - 1
-9223372036854775808 ～ 9223372036854775807

[unsigned long long]
0 ～ ULONG_MAX
0 ～ 2^64 - 1
0 ～ 18446744073709551615

[float] ※ 単精度
FLT_MIN ～ FLT_MAX
1.175494351e-38F ～ 3.402823466e+38F

[double] ※ 倍精度
DBL_MIN ～ DBL_MAX
2.2250738585072014e-308 ～ 1.7976931348623158e+308

[long double]
LDBL_MIN ～ LDBL_MAX
環境によって変化するが、double型よりも精度が良い場合がほとんど。```

[トップページに戻る](../index.html)
