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


# :warning: geometry/old/gmtr_008_circle_points.cpp
* category: geometry/old


[Back to top page](../../../index.html)



## Code
```cpp
// 三角形の外心。点 a, b, c は同一線上にあってはならない
Point circumcenter(Point a, Point b, Point c) {
    a = (a-c) * 0.5;
    b = (b-c) * 0.5;
    return c + crossp_ll(a, a*Point(1,1), b, b*Point(1,1));
}

// 三角形の内心
Point InnerCenter(Point a, Point b, Point c) {
    double p = abs(b-c), q = abs(c-a), r = abs(a-b);
    return (p*a + q*b + r*c) / (p + q + r);
}

// 三角形の重心
Point CenterOfGravity(Point a, Point b, Point c) {
    return (a + b + c) / 3.0;
}

// 三角形の垂心
Point Orthocenter(Point a, Point b, Point c) {
    Point x = circumcenter(a, b, c);
    Point ret = (a-x) + (b-x) + (c-x);
    return ret-x;
}

// 点 a と 点 b を通り、半径が r の円の中心を返す
vector<Point> circlesPointsRadius(Point a, Point b, double r) {
    vector<Point> cs;
    Point abH = (b-a) * 0.5;
    double d = abs(abH);

    if(d == 0 || d > r) return cs; // 必要なら !LE(d,r) として円1つになる側へ丸める
    double dN = sqrt(r*r - d*d);   // 必要なら max(r*r - d*d, 0) とする
    Point n = abH * Point(0,1) * (dN / d);
    cs.push_back(a + abH + n);
    if(dN > 0) cs.push_back(a + abH - n);
    return cs;
}

// 点 a と点 b を通り、直線 l に接する円の中心
vector<Point> circlesPointsTangent(Point a, Point b, Point l1, Point l2) {
    Point n = (l2-l1) * Point(0,1);
    Point m = (b-a) * Point(0,0.5);
    double rC = dot((a+b)*0.5-l1, n);
    double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);
    double qb = -rC * dot(n,m);
    double qc = norm(n)*norm(m) - rC*rC;
    double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0

    vector<Point> cs;
    if(qd < -EPS) return cs;
    if(EQ(qa, 0)) {
        if(!EQ(qb,0)) cs.push_back((a+b)*0.5 - m * (qc/qb/2));
        return cs;
    }
    double t = -1*qb/qa;
    cs.push_back( (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0)) / qa ));
    if(qd > EPS) cs.push_back( (a+b)*0.5 + m * (t - sqrt(max(qd, 0.0)) / qa));
    return cs;
}

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const vector<Point> &ps) {
    Point c;
    double move = 0.5;
    for(int i=0; i<39; i++) { // 2^(-39-1) \approx 0.9e-12
        for(int t=0; t<50; t++) {
            double max = 0;
            int k = 0;
            for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c)) {
                max = norm(ps[j] - c);
                k = j;
            }
            c += (ps[k] - c) * move;
        }
        move /= 2;
    }
    return c;
}

```

[Back to top page](../../../index.html)

