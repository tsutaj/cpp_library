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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../geometry/old/gmtr_001_orthogonal_parallel.cpp
* category: ../../geometry/old


[Back to top page](../../../index.html)



## Code
```cpp
/***** 直交・平行判定 *****/
// Verified: AOJ CGL_2_A: Parallel/Orthogonal

// 2直線の直交判定 (内積が0であること)
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
    return EQ( dot(a1-a2, b1-b2), 0.0 );
}

// 2直線の平行判定 (外積が0であること)
bool is_parallel(Point a1, Point a2, Point b1, Point b2) {
    return EQ( cross(a1-a2, b1-b2), 0.0 );
}

```

[Back to top page](../../../index.html)
