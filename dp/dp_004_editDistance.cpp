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