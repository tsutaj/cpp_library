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


# :warning: structure/old/strc_002_segment_rmq.cpp
* category: structure/old


[Back to top page](../../../index.html)



## Code
{% raw %}
```cpp
// Range Minimum Query (区間最小クエリ、RMQ)
// Verified: AOJ DSL_2_A: Range Minimum Query (int型のみ)

template <typename T>
class rmq {
public:
    int n;
    vector<T> dat;

    // 要素数 m の RMQ を作る
    rmq(int m) {
        n = 1;
        while(n < m) n *= 2;
        dat.resize(2*n-1);
        rep(i,0,2*n-1) dat[i] = INT_MAX;
    }

    // k番目 (0-indexed) の値を a に更新
    void update(int k, T a) {
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }

    // [a, b) の最小値を返す
    // 最初に呼び出すときは XX.query(a, b, 0, 0, -1) とする
    T query(int a, int b, int k, int l, int r) {
        if(r == -1) r = n;
        if(r <= a || b <= l) return INT_MAX;
        if(a <= l && r <= b) return dat[k];
        else {
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
```
{% endraw %}

[Back to top page](../../../index.html)

