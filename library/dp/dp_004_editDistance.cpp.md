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


# :warning: dp/dp_004_editDistance.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#95687afb5d9a2a9fa39038f991640b0c">dp</a>
* <a href="{{ site.github.repository_url }}/blob/master/dp/dp_004_editDistance.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 編集距離 (レーベンシュタイン距離)
// Verified: DPL_1_E: Edit Distance (Levenshtein Distance)

int dp[1010][1010];
int editDistance(string s, string t) {
    int n = s.length(), m = t.length();
    rep(i,0,n) dp[i+1][0] = i+1;
    rep(i,0,m) dp[0][i+1] = i+1;

    rep(i,0,n) rep(j,0,m) {
        int cost = (s[i] != t[j]);
        dp[i+1][j+1] = min(dp[i+1][j] + 1, 
                       min(dp[i][j+1] + 1, dp[i][j] + cost));
    }
    return dp[n][m];
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "dp/dp_004_editDistance.cpp"
// 編集距離 (レーベンシュタイン距離)
// Verified: DPL_1_E: Edit Distance (Levenshtein Distance)

int dp[1010][1010];
int editDistance(string s, string t) {
    int n = s.length(), m = t.length();
    rep(i,0,n) dp[i+1][0] = i+1;
    rep(i,0,m) dp[0][i+1] = i+1;

    rep(i,0,n) rep(j,0,m) {
        int cost = (s[i] != t[j]);
        dp[i+1][j+1] = min(dp[i+1][j] + 1, 
                       min(dp[i][j+1] + 1, dp[i][j] + cost));
    }
    return dp[n][m];
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

