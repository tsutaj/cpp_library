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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../geometry/old/gmtr_010_rotate.cpp
* category: ../../geometry/old


[Back to top page](../../../index.html)



## Code
```cpp
// 頂点を回転させる系

// 度数法 → 弧度法
double deg2rad(double x) {return x * M_PI / 180.0;}

// 点 a を中心として、点 b を z 度回転させたときの位置
Point rotatePoint(Point a, Point b, double z) {
    // 度数法の場合は変換
    z = deg2rad(z);

    b -= a;
    double rx = b.real() * cos(z) - b.imag() * sin(z);
    double ry = b.real() * sin(z) + b.imag() * cos(z);
    Point ret(rx, ry); ret += a;
    return ret;
}

```

[Back to top page](../../../index.html)

