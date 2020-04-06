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


# :heavy_check_mark: algorithm/cumulative_sum.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/cumulative_sum.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 00:08:06+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/0516/cumulative_sum.test.cpp.html">verifying_test/AOJ/0516/cumulative_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// 累積演算 (0-indexed・prefix, suffix, 任意連続部分列)
// 任意連続部分列は逆演算があるときのみできる？

#include <functional>
#include <vector>
template <typename MonoidType>
struct CumulativeSum {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void accumulate(int m, vector<MonoidType> vec) {
        pre = suf = vector<MonoidType>(m+1, E);
        for(int i=0; i<m; i++) {
            pre[i+1] = op(pre[i], vec[i]);
        }
        for(int i=m-1; i>=0; i--) {
            suf[i] = op(suf[i+1], vec[i]);
        }
    }

    CumulativeSum() {}
    CumulativeSum(vector<MonoidType> val_array, MonoidType E_,
                  MMtoM op_, MMtoM rop_ = MMtoM(),
                  bool need_accumulate = true) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        if(need_accumulate) accumulate(n, val_array);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k and k <= n ? suf[k] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "algorithm/cumulative_sum.cpp"

// 累積演算 (0-indexed・prefix, suffix, 任意連続部分列)
// 任意連続部分列は逆演算があるときのみできる？

#include <functional>
#include <vector>
template <typename MonoidType>
struct CumulativeSum {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void accumulate(int m, vector<MonoidType> vec) {
        pre = suf = vector<MonoidType>(m+1, E);
        for(int i=0; i<m; i++) {
            pre[i+1] = op(pre[i], vec[i]);
        }
        for(int i=m-1; i>=0; i--) {
            suf[i] = op(suf[i+1], vec[i]);
        }
    }

    CumulativeSum() {}
    CumulativeSum(vector<MonoidType> val_array, MonoidType E_,
                  MMtoM op_, MMtoM rop_ = MMtoM(),
                  bool need_accumulate = true) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        if(need_accumulate) accumulate(n, val_array);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k and k <= n ? suf[k] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

