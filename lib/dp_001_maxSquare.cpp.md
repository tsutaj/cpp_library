[トップページに戻る](../index.html)

# dp\_001\_maxSquare.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

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
}```

[トップページに戻る](../index.html)
