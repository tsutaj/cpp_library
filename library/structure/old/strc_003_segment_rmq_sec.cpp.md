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


# :warning: structure/old/strc_003_segment_rmq_sec.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ea7b7b53f881f37feb2f447585bbcf5b">structure/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/old/strc_003_segment_rmq_sec.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 次の2つのクエリに対応するRMQ
// ・[a, b) の要素全てに x を加えるクエリ
// ・[a, b) の和を計算するクエリ
// (strc_006_bit_sec.cpp に BIT 版があり、そちらの方が速いです)
// Verify: なし (POJ の問題が TLE した)

template <typename T>
class rmq_sec {
public:
    vector<T> data, datb;
    rmq_sec(int n_) {
        int m = 1; while(m < n_) m *= 2;
        data.resize(2*m-1);
        datb.resize(2*m-1);
    }

    void add(int a, int b, int x, int k, int l, int r) {
        if(a <= l && r <= b) {
            data[k] += x;
        }
        else if(l < b && a < r) {
            datb[k] += (min(b, r) - max(a, l)) * x;
            add(a, b, x, k*2 + 1, l, (l + r) / 2);
            add(a, b, x, k*2 + 2, (l + r) / 2, r);
        }
    }

    ll sum(int a, int b, int k, int l, int r) {
        if(b <= l || r <= a) {
            return 0;
        }
        else if(a <= l && r <= b) {
            return data[k] * (r - l) + datb[k];
        }
        else {
            ll res = (min(b, r) - max(a, l)) * data[k];
            res += sum(a, b, k*2 + 1, l, (l + r) / 2);
            res += sum(a, b, k*2 + 2, (l + r) / 2, r);
            return res;
        }
    }
};
```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

