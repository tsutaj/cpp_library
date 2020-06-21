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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :heavy_check_mark: verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#1a823b70107b4403d17260d22304db20">verifying_test/yosupo/data_structure/static_range_sum</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-21 23:39:53+09:00


* see: <a href="https://judge.yosupo.jp/problem/static_range_sum">https://judge.yosupo.jp/problem/static_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../../../library/algorithm/cumulative_sum.cpp.html">1 次元累積和 (1 Dimension Cumulative Sum) <small>(algorithm/cumulative_sum.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using ll = long long int;
using namespace std;

#define call_from_test
#include "../../../../algorithm/cumulative_sum.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<ll> A(N);
    for(auto &e : A) scanf("%lld", &e);

    CumulativeSum<ll> cumsum(A, 0,
                             [](ll a, ll b) { return a + b; },
                             [](ll a, ll b) { return a - b; });
    while(Q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%lld\n", cumsum.get_subseq(l, r));
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using ll = long long int;
using namespace std;

#define call_from_test
#line 2 "algorithm/cumulative_sum.cpp"

/**
 * @brief 1 次元累積和 (1 Dimension Cumulative Sum)
 * @docs ./docs/cumulative_sum.md
 */

#line 10 "algorithm/cumulative_sum.cpp"
template <typename MonoidType>
struct CumulativeSum {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void accumulate() {
        int m = pre.size();
        for(int i=0; i+1<m; i++) {
            pre[i+1] = op(pre[i+1], pre[i]);
        }
        for(int i=m-2; i>=0; i--) {
            suf[i] = op(suf[i], suf[i+1]);
        }
    }

    CumulativeSum() {}
    CumulativeSum(vector<MonoidType> val_array, MonoidType E_,
                  MMtoM op_, MMtoM rop_ = MMtoM(),
                  bool need_accumulate = true) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        pre = suf = vector<MonoidType>(n+2, E);
        for(int i=0; i<n; i++) pre[i+1] = suf[i+1] = val_array[i];
        if(need_accumulate) accumulate();
    }

    void range_apply(int l, int r, MonoidType val) {
        pre[l+1] = op(pre[l+1], val);
        pre[r+1] = rop(pre[r+1], val);
        suf[r] = op(suf[r], val);
        suf[l] = rop(suf[l], val);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k+1 and k+1 <= n ? suf[k+1] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};
#line 11 "verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<ll> A(N);
    for(auto &e : A) scanf("%lld", &e);

    CumulativeSum<ll> cumsum(A, 0,
                             [](ll a, ll b) { return a + b; },
                             [](ll a, ll b) { return a - b; });
    while(Q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%lld\n", cumsum.get_subseq(l, r));
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

