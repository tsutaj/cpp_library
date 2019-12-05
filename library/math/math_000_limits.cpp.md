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


# :warning: math/math_000_limits.cpp
* category: math


[Back to top page](../../index.html)



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

[Back to top page](../../index.html)

