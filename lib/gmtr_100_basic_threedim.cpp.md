[トップページに戻る](../index.html)

# gmtr\_100\_basic\_threedim.cpp
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
