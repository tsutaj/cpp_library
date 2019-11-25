<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: gmtr\_010\_rotate.cpp

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

[トップページに戻る](../index.html)
