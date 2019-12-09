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


# :warning: geometry/old/gmtr_004_circle_dist.cpp
* category: geometry/old


[Back to top page](../../../index.html)



## Code
{% raw %}
```cpp
/***** 円に関する問題 *****/

// 直線 a1, a2 と 円 C との距離
double dist_lc(Point a1, Point a2, Circle c) {
    return max(dist_lp(a1, a2, c.first) - c.second, 0.0);
}

// 線分 a1, a2 と 円 C との距離
double dist_sc(Point a1, Point a2, Circle c) {
    double dSqr1 = norm(c.first - a1), dSqr2 = norm(c.first - a2);
    double r = c.second;
    if(dSqr1 < r*r ^ dSqr2 < r*r) return 0; //円が線分を包含するとき距離0ならばここをORに変える
    if(dSqr1 < r*r & dSqr2 < r*r) return r - sqrt(max(dSqr1, dSqr2));
    return max(dist_sp(a1, a2, c.first) - r, 0.0);
}

// 円 x と円 y との距離
double dist_cc(Circle x, Circle y) {
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    double d = abs(a-b);
    return GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;
}


```
{% endraw %}

[Back to top page](../../../index.html)

