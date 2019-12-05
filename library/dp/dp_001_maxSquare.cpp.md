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


# :warning: dp/dp_001_maxSquare.cpp
* category: dp


[Back to top page](../../index.html)



## Code
```cpp
// 最大正方形問題 (綺麗なタイルのみを使ってできる正方形の面積最大)
// 0 -> 綺麗なタイル、 1 -> 汚れているタイル
// Verified: AOJ DPL_3_A: Largest Square

int maxSquare(vector< vector<int> > board) {
    int H = board.size(), W = board[0].size();
    vector< vector<int> > dp(H, vector<int>(W));

    int ret = 0;
    rep(i,0,H) rep(j,0,W) {
        if(board[i][j] == 1) continue;
        if(i == 0 || j == 0) dp[i][j] = 1;
        else {
            int mi = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            dp[i][j] = mi + 1;
        }
        chmax(ret, dp[i][j] * dp[i][j]);
    }
    return ret;
}
```

[Back to top page](../../index.html)

