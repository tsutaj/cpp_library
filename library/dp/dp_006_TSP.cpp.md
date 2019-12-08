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
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: dp/dp_006_TSP.cpp
* category: dp


[Back to top page](../../index.html)



## Code
```cpp
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
```

[Back to top page](../../index.html)

