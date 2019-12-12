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


# :warning: dp/dp_005_limitKnapsack.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#95687afb5d9a2a9fa39038f991640b0c">dp</a>
* <a href="{{ site.github.repository_url }}/blob/master/dp/dp_005_limitKnapsack.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 個数制限付きナップザック問題
// 価値 v_i で重さ w_i の品物が m_i 個ある状態で
// 容量制限 W のナップザック内の価値最大化
// -> 個数の部分を 2^k 個ずつ処理することで O(NW log max m_i) くらいで処理可能
// Verified: DPL_1_G: Knapsack Problem with Limitations

// dp[i] := (weight) -> value
int dp[10010];
int v[110], w[110], m[110];

void solve() {
    int N, W; cin >> N >> W;
    rep(i,0,N) cin >> v[i] >> w[i] >> m[i];

    rep(i,0,N) {
        int rest = m[i], k = 0;
        while(rest > 0) {
            int take = min(rest, 1LL << k++);
            rest -= take;

            repr(j,W,0) {
                if(j-take*w[i] < 0) continue;
                chmax(dp[j], dp[j-take*w[i]] + take*v[i]);
            }
        }
    }
    cout << *max_element(dp, dp+W+1) << endl;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

