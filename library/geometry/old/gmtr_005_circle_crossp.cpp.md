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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: geometry/old/gmtr_005_circle_crossp.cpp
* category: geometry/old


[Back to top page](../../../index.html)



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

[Back to top page](../../../index.html)

