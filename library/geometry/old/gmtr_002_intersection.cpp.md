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


# :warning: geometry/old/gmtr_002_intersection.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ee276eb56ad4bc3f1e3c8191a9303fa9">geometry/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/old/gmtr_002_intersection.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-24 02:02:41+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/***** 各種交差判定 (intersection) *****/
// 豆知識: 線分 ... line segment (英)

// 直線 a1, a2 と点 b の交差判定 (直線上に点があるかの判定)
// ccwで絶対値が1 (一直線で線分上にない) でなければ交差している
bool isec_lp(Point a1, Point a2, Point b) {
    return abs( ccw(a1, a2, b) ) != 1;
}

// 直線 a1, a2 と直線 b1, b2 の交差判定
bool isec_ll(Point a1, Point a2, Point b1, Point b2) {
    return !isec_lp(a2-a1, b2-b1, 0) || isec_lp(a1, b1, b2);
}

// 直線 a1, a2 と線分 b1, b2 の交差判定
bool isec_ls(Point a1, Point a2, Point b1, Point b2) {
    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分 a1, a2 と線分 b1, b2 の交差判定
// Verified: CGL_2_B: Intersection
bool isec_ss(Point a1, Point a2, Point b1, Point b2) {
    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

// 線分 a1, a2 と点 b の交差判定 (線分上に点があるかの判定)
bool isec_sp(Point a1, Point a2, Point b) {
    return !ccw(a1, a2, b);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "geometry/old/gmtr_002_intersection.cpp"
/***** 各種交差判定 (intersection) *****/
// 豆知識: 線分 ... line segment (英)

// 直線 a1, a2 と点 b の交差判定 (直線上に点があるかの判定)
// ccwで絶対値が1 (一直線で線分上にない) でなければ交差している
bool isec_lp(Point a1, Point a2, Point b) {
    return abs( ccw(a1, a2, b) ) != 1;
}

// 直線 a1, a2 と直線 b1, b2 の交差判定
bool isec_ll(Point a1, Point a2, Point b1, Point b2) {
    return !isec_lp(a2-a1, b2-b1, 0) || isec_lp(a1, b1, b2);
}

// 直線 a1, a2 と線分 b1, b2 の交差判定
bool isec_ls(Point a1, Point a2, Point b1, Point b2) {
    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分 a1, a2 と線分 b1, b2 の交差判定
// Verified: CGL_2_B: Intersection
bool isec_ss(Point a1, Point a2, Point b1, Point b2) {
    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

// 線分 a1, a2 と点 b の交差判定 (線分上に点があるかの判定)
bool isec_sp(Point a1, Point a2, Point b) {
    return !ccw(a1, a2, b);
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

