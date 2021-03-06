// 個数制限付きナップザック問題
// 価値 v_i で重さ w_i の品物が m_i 個ある状態で
// 容量制限 W のナップザック内の価値最大化
// -> 個数の部分を 2^k 個ずつ処理することで O(NW log max m_i) くらいで処理可能
// Verified: DPL_1_G: Knapsack Problem with Limitations

// dp[i] := (weight) -> value
int dp[10010];
int v[110], w[110], m[110];

void solve() {
    int N, W; cin >> N >> W;
    rep(i,0,N) cin >> v[i] >> w[i] >> m[i];

    rep(i,0,N) {
        int rest = m[i], k = 0;
        while(rest > 0) {
            int take = min(rest, 1LL << k++);
            rest -= take;

            repr(j,W,0) {
                if(j-take*w[i] < 0) continue;
                chmax(dp[j], dp[j-take*w[i]] + take*v[i]);
            }
        }
    }
    cout << *max_element(dp, dp+W+1) << endl;
}