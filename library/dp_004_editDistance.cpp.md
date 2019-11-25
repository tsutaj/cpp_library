<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: dp\_004\_editDistance.cpp

## Code

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

[トップページに戻る](../index.html)
