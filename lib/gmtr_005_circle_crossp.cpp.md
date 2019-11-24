[トップページに戻る](../index.html)

# gmtr\_005\_circle\_crossp.cpp
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
// 直線 a1, a2 と円 C との交点
// Verified: AOJ CGL_7_D: Cross Points of a Circle and a Line
vector<Point> crossp_lc(Point a1, Point a2, Circle c) {
    vector<Point> ps;
    double r = c.second;
    Point ft = projection(a1, a2, c.first);
    if(!GEQ(r*r, norm(ft-c.first))) return ps;

    Point dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);
    return ps;
}

// 円 x と円 y の交点
// Verified: AOJ CGL_7_E: Cross Points of Circles
vector<Point> crossp_cc(Circle x, Circle y) {
    vector<Point> ps;
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    Point ab = b-a;
    double d = abs(ab);
    double crL = (norm(ab) + ar * ar - br * br) / (2 * d);
    if(EQ(d,0) || ar < abs(crL)) return ps;

    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);
    Point cp = a + crL/d * ab;
    ps.push_back(cp + abN);
    if(!EQ(norm(abN), 0)) ps.push_back(cp - abN);
    return ps;
}
```

[トップページに戻る](../index.html)
