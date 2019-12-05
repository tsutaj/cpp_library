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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../dp/dp_002_maxRectangle.cpp
* category: ../../dp


[Back to top page](../../index.html)



## Code
```cpp
// 最大長方形問題 (綺麗なタイルのみを使ってできる長方形の面積最大)
// ※ dp_003_histogram.cpp を呼び出すので注意！
// 0 -> 綺麗なタイル、 1 -> 汚れているタイル
// Verified: AOJ DPL_3_B: Largest Rectangle

int maxRectangle(vector< vector<int> > board) {
    int H = board.size(), W = board[0].size();
    vector< vector<int> > sum(H, vector<int>(W));
    rep(i,0,H) rep(j,0,W) {
        if(board[i][j] == 1) continue;
        sum[i][j] = (i > 0 ? sum[i-1][j] : 0) + 1;
    }
    int ret = 0;
    rep(i,0,H) chmax(ret, histArea(sum[i]));
    return ret;
}
```

[Back to top page](../../index.html)
