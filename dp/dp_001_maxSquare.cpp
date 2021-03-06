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