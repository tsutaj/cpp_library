---
layout: default
---

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


# :warning: geometry/old/gmtr_006_circle_tangent.cpp
<a href="../../../index.html">Back to top page</a>

* category: geometry/old
* <a href="{{ site.github.repository_url }}/blob/master/geometry/old/gmtr_006_circle_tangent.cpp">View this file on GitHub</a> (Last commit date: 2019-11-24 02:02:41 +0900)




## Code
{% raw %}
```cpp
// 点 p から円 x への接線の接点
// Verified: AOJ CGL_7_F: Tangent to a Circle
vector<Point> tangentPoints(Point p, Circle x) {
    vector<Point> ps;
    Point a = x.first; double ar = x.second;
    double sin = ar / abs(p-a);
    if(!LE(sin, 1)) return ps; // ここで NaN もはじかれる

    double t = M_PI_2 - asin(min(sin, 1.0));
    ps.push_back(a + (p-a) * polar(sin, t));
    if(!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
    return ps;
}

// 円 x と円 y の共通接線。返される各直線に含まれる頂点は円との接点となる
// Verified: AOJ CGL_7_G: Common Tangent
// ※ やること: -0.0000000になる問題を直したい・・・
vector<L> tangentLines(Circle x, Circle y) {
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;
    vector<L> ls;
    double d = abs(b-a);

    for(int i=0; i<2; i++) {
        double sin = (ar - (1-i*2)*br) / d;
        if(!LE(sin*sin, 1)) break;

        double cos = sqrt(max(1 - sin*sin, 0.0));
        for(int j=0; j<2; j++) {
            Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
            ls.push_back(L(a + ar*n, b + (1-i+2)*br*n));
            if(cos < EPS) break; // 重複する接線を無視 (重複してよいならこの行は不要)
        }
    }
    return ls;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

