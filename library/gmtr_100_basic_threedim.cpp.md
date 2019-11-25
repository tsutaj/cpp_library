<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: gmtr\_100\_basic\_threedim.cpp

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

[トップページに戻る](../index.html)
