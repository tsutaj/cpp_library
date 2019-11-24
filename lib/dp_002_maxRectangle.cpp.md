[トップページに戻る](../index.html)

# dp\_002\_maxRectangle.cpp
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
}```

[トップページに戻る](../index.html)
