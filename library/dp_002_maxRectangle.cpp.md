<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: dp\_002\_maxRectangle.cpp

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

[トップページに戻る](../index.html)
