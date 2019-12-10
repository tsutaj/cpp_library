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


# :warning: geometry/old/gmtr_007_circle_intersection.cpp
<a href="../../../index.html">Back to top page</a>

* category: geometry/old
* <a href="{{ site.github.repository_url }}/blob/master/geometry/old/gmtr_007_circle_intersection.cpp">View this file on GitHub</a> (Last commit date: 2019-11-24 02:02:41 +0900)




## Code
{% raw %}
```cpp
// 円 c1 と円 c2 の位置関係
// Verified: AOJ CGL_7_A: Intersection
int intersectCC(Circle c1, Circle c2){
    Point c1p = c1.first, c2p = c2.first;
    double c1r = c1.second, c2r = c2.second;
    long double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;
    if(r1 + r2 < d)            return  0; // 離れている
    if(abs(r1 + r2 - d) < EPS) return -2; // 外接
    if(abs(d + r1 - r2) < EPS) return +1; // c1 が c2 の中で内接
    if(abs(d + r2 - r1) < EPS) return -1; // c2 が c1 の中で内接
    if(d + r1 < r2)            return +3; // c1 が c2 の中
    if(d + r2 < r1)            return -3; // c2 が c1 の中
    return 2; // 2つの交点を持つ
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

