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