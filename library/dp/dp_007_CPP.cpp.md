---
layout: default
---

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


# :warning: dp/dp_007_CPP.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#95687afb5d9a2a9fa39038f991640b0c">dp</a>
* <a href="{{ site.github.repository_url }}/blob/master/dp/dp_007_CPP.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 中国人郵便配達問題 (重み付き無向グラフについて、次の条件を満たす最短経路の距離)
// ・ある頂点から出発し、出発点へ戻る閉路
// ・各辺を少なくとも 1 度は通る
// -> オイラー閉路 (グラフ中のすべての辺を 1 度ずつ通るような閉路) を持つように
//    グラフを変形する。オイラー閉路を持つならば、全ての頂点の次数が偶数である。
//    よって、次数が奇数である任意の 2 頂点に辺を張り (重みは元のグラフにおける最短経路)
//    一般マッチングを行えばよい。一般マッチングには bit DP を用いる。
//    答えは、元のグラフの全ての辺の重み総和 + 一般マッチングの結果 となる。
// Verified: AOJ DPL_2_B: Chinese Postman Problem (多重辺に注意！！！)

// (to, cost)
vector<pii> G[20];
int deg[20], dist[20][20], w[20][20], dp[1 << 15];

void solve() {
    int total = 0;
    int V, E; cin >> V >> E;
    rep(i,0,V) rep(j,0,V) {
        if(i == j) dist[i][j] = 0;
        else dist[i][j] = INF;
    }
    rep(i,0,E) {
        int s, t, d; cin >> s >> t >> d;
        G[s].push_back(pii(t, d));
        G[t].push_back(pii(s, d));
        chmin(dist[s][t], d);
        chmin(dist[t][s], d);
        total += d;
        deg[s]++; deg[t]++;
    }

    vector<int> odds;
    rep(i,0,V) if(deg[i] % 2) odds.push_back(i);
    int M = odds.size();

    rep(k,0,V) rep(i,0,V) rep(j,0,V) {
        chmin(dist[i][j], dist[i][k] + dist[k][j]);
    }
    rep(i,0,M) rep(j,0,M) w[i][j] = dist[ odds[i] ][ odds[j] ];

    rep(i,1,1<<M) dp[i] = INF;
    rep(bit,0,1<<M) rep(i,0,M) rep(j,i+1,M) {
        if((bit >> i & 1) || (bit >> j & 1)) continue;
        chmin(dp[bit | (1 << i) | (1 << j)], dp[bit] + w[i][j]);
    }
    cout << total + dp[(1<<M)-1] << endl;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

