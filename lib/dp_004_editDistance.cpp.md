[トップページに戻る](../index.html)

# dp\_004\_editDistance.cpp
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
}```

[トップページに戻る](../index.html)
