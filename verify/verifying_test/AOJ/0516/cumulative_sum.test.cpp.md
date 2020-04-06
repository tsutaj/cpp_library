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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: verifying_test/AOJ/0516/cumulative_sum.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#e9a8f9879edfa1d3b6a1cdfdbac78c62">verifying_test/AOJ/0516</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/0516/cumulative_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 01:30:23+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/algorithm/cumulative_sum.cpp.html">1 次元累積和 (1 Dimension Cumulative Sum) <small>(algorithm/cumulative_sum.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <cstdio>
using namespace std;
#include "../../../algorithm/cumulative_sum.cpp"
using ll = long long int;

int solve() {
    int N, K; scanf("%d%d", &N, &K);
    if(N == 0 and K == 0) return 1;
    
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    CumulativeSum<ll> cs(A, 0LL,
                         [](ll a, ll b) { return a + b; },
                         [](ll a, ll b) { return a - b; });

    ll ans = -(1LL << 60);
    for(int i=0; i<N-K+1; i++) {
        ans = max(ans, cs.get_subseq(i, i+K));
    }
    printf("%lld\n", ans);
    return 0;
}

int main() {
    while(!solve());
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/AOJ/0516/cumulative_sum.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <cstdio>
using namespace std;
#line 2 "algorithm/cumulative_sum.cpp"

/**
 * @brief 1 次元累積和 (1 Dimension Cumulative Sum)
 * @brief - `get_prefix`: 半開区間 $\left[ 0, k \right)$ に関して値を求める
 * @brief - 'get_suffix': 半開区間 $\left[ k, N \right)$ に関して値を求める
 * @brief - 'get_subseq': 半開区間 $\left[ l, r \right)$ に関して値を求める
 * @brief   - `subseq` は逆演算が存在するときのみ可能
 */

#include <functional>
#include <vector>
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
        n = val_array.size() + 2;
        pre = suf = vector<MonoidType>(n, E);
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
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k+1] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k and k <= n ? suf[k+1] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};
#line 6 "verifying_test/AOJ/0516/cumulative_sum.test.cpp"
using ll = long long int;

int solve() {
    int N, K; scanf("%d%d", &N, &K);
    if(N == 0 and K == 0) return 1;
    
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    CumulativeSum<ll> cs(A, 0LL,
                         [](ll a, ll b) { return a + b; },
                         [](ll a, ll b) { return a - b; });

    ll ans = -(1LL << 60);
    for(int i=0; i<N-K+1; i++) {
        ans = max(ans, cs.get_subseq(i, i+K));
    }
    printf("%lld\n", ans);
    return 0;
}

int main() {
    while(!solve());
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

