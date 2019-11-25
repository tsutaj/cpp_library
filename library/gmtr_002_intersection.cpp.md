<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script src="../js/balloons.js"></script>
<script src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: gmtr\_002\_intersection.cpp

## Code

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

[トップページに戻る](../index.html)
