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


# :warning: structure/strc_004_bit_sec.cpp
<a href="../../index.html">Back to top page</a>

* category: structure
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_004_bit_sec.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Required
* :warning: <a href="verify/verify_strc_004_bit_sec.cpp.html">structure/verify/verify_strc_004_bit_sec.cpp</a>


## Code
{% raw %}
```cpp
// 次の2つのクエリに対応するBIT
// ・[a, b) の要素全てに x を加えるクエリ
// ・[a, b) の和を計算するクエリ
// Verified: POJ 3468 (A Simple Problem with Integers)

template <typename U>
class BIT_sec {
public:
    int n;
    BIT<U> bit0, bit1;
    BIT_sec(int n_) {
        n = n_;
        bit0 = BIT<U>(n);
        bit1 = BIT<U>(n);
    }

    // 最初に要素を追加するときはこっち
    void add(int i, int x) {
        bit0.add(i, x);
    }

    // [l, r] の全要素に x を加える
    void add(int l, int r, U x) {
        bit0.add(l, -x * (l-1));
        bit1.add(l, x);
        bit0.add(r+1, x*r);
        bit1.add(r+1, -x);
    }

    U sum(int l, int r) {
        U res = 0;
        res += bit0.sum(r) + bit1.sum(r) * r;
        res -= bit0.sum(l-1) + bit1.sum(l-1) * (l-1);
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

