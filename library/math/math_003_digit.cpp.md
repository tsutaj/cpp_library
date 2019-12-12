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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/math_003_digit.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_003_digit.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 整数の桁数を調べる (10進数)
template <typename T_digit>
int digit(T_digit n) {
    int ans = 0;
    while(n != 0) {n /= 10; ans++;}
    return ans;
}

// 整数の桁数を調べる (k進数)
template <typename T_digit>
template <typename U_digit>
int digit(T_digit n, U_digit k) {
    int ans = 0;
    while(n != 0) {n /= k; ans++;}
    return ans;
}

// インデックス (10進数)
template <typename T_numIndex>
int numIndex(T_numIndex n, int k) {
    rep(i,0,k) n /= 10;
    return n % 10;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

