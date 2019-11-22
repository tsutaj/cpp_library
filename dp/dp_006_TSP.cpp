// 巡回セールスマン問題 (重み付き有向グラフについて、次の条件を満たす最短経路の距離)
// ・ある頂点から出発して、出発点へ戻る閉路
// ・各頂点をちょうど 1 度通る
// -> 閉路なので、出発点はどこでもよい。この実装では 0 をスタートとしている。
// Verified: AOJ DPL_2_A: Traveling Salesman Problem

// (to, cost)
vector<pii> G[20];
int dp[1 << 15][15];

void solve() {
    int V, E; cin >> V >> E;
    rep(i,0,E) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(pii(t, d));
    }

    // 出発点だけ初期値 0 にする
    rep(i,0,1<<V) rep(j,0,V) dp[i][j] = INF;
    dp[0][0] = 0;
    
    rep(bit,0,1<<V) rep(i,0,V) {
        for(auto x : G[i]) {
            if(bit >> x.first & 1) continue;
            int nbit = bit | (1 << x.first);
            chmin(dp[nbit][x.first], dp[bit][i] + x.second);
        }
    }
    int ans = (dp[(1<<V)-1][0] == INF ? -1 : dp[(1<<V)-1][0]);
    cout << ans << endl;
}