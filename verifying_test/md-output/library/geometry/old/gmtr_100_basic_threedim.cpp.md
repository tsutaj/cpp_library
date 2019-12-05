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


# :warning: ../../geometry/old/gmtr_100_basic_threedim.cpp
* category: ../../geometry/old


[Back to top page](../../../index.html)



## Code
```cpp
// 3 次元の幾何テンプレ (最低限のもののみ)
// AOJ 2641 でちょっと必要になったので作りました

struct Point3D {
    double x, y, z;
};

Point3D operator+(Point3D a, Point3D b) {
    return Point3D{a.x+b.x, a.y+b.y, a.z+b.z};
}

Point3D operator-(Point3D a, Point3D b) {
    return Point3D{a.x-b.x, a.y-b.y, a.z-b.z};
}

Point3D operator*(double a, Point3D b) {
    return Point3D{a*b.x, a*b.y, a*b.z};
}

double abs(Point3D a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

double cross(Point3D a, Point3D b) {
    double ra = a.y * b.z - a.z * b.y;
    double rb = a.z * b.x - a.x * b.z;
    double rc = a.x * b.y - a.y * b.x;
    return sqrt(ra*ra + rb*rb + rc*rc);
}

double dot(Point3D a, Point3D b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}

```

[Back to top page](../../../index.html)
