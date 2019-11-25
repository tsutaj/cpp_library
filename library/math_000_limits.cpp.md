<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_000\_limits.cpp

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
環境によって変化するが、double型よりも精度が良い場合がほとんど。
```

[トップページに戻る](../index.html)
