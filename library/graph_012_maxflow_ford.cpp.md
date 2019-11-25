<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script src="../js/balloons.js"></script>
<script src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_012\_maxflow\_ford.cpp

## Code

```cpp
// Ford-Fulkerson 法による 最大流 O( F |E| )
// Bellman-Ford 法による 最小費用流 O( F |V| |E| )
// [条件に注意] Dijkstra 法による 最小費用流 O( F |E| log |V| )

template <typename CapTp=int, typename CostTp=int>
struct Edge {
    int to, rev;
    CapTp cap; CostTp cost;
    bool is_rev;
    Edge(int t, bool f, int r, CapTp ca, CostTp co=0)
        : to(t), rev(r), cap(ca), cost(co), is_rev(f) {}
};

template <typename CapTp=int, typename CostTp=int>
struct Flow {
    using Graph = vector< vector< Edge<CapTp, CostTp> > >;
    Graph G; const CapTp IA; const CostTp IO;
    vector< pair<int, int> > r_edges;
    Flow(int N_, CapTp IA_=1<<29, CostTp IO_=1<<29)
        : G(N_), IA(IA_), IO(IO_), r_edges() {}
    // 辺を追加 (from -> to に流量 ca, コスト co)
    void add_edge(int from, int to, CapTp ca, CostTp co=0) {
        G[from].emplace_back(to, false, G[to].size(), ca, co);
        G[to].emplace_back(from, true, G[from].size() - 1, 0, -co);
        r_edges.emplace_back(to, G[to].size() - 1);
    }
    // k 番目の辺にいくつ流れたか
    CapTp get_flowed_cap(size_t k) {
        if(r_edges.size() <= k) return -1;
        int v, i; tie(v, i) = r_edges[k];
        return G[v][i].cap;
    }
    // s -> t 最大流
    CapTp max_flow(int s, int t) {
        vector<bool> used(G.size());
        auto dfs = [&](auto &&func, int v, int t, CapTp f) -> CapTp {
            if(v == t) return f;
            used[v] = true;
            for(auto &e : G[v]) {
                if(used[e.to] or e.cap == 0) continue;
                CapTp d = func(func, e.to, t, min(f, e.cap));
                if(d == 0) continue;
                e.cap -= d; G[e.to][e.rev].cap += d;
                return d;
            }
            return 0;
        };

        CapTp res(0);
        while(true) {
            fill(used.begin(), used.end(), false);
            CapTp delta = dfs(dfs, s, t, IA);
            if(delta == 0) return res;
            res += delta;
        }
    }
    // ベルマンフォードをつかって最小費用流
    CostTp mincost_flow(int s, int t, CapTp f) {
        vector<CostTp> dist(G.size()); CostTp res(0);
        vector<int> prevv(G.size()), preve(G.size());
        while(f > 0) {
            fill(dist.begin(), dist.end(), IO);
            dist[s] = 0;
            while(1) {
                bool upd = false;
                for(int v=0; v<(int)G.size(); v++) {
                    if(dist[v] == IO) continue;
                    for(size_t i=0; i<G[v].size(); i++) {
                        auto &e = G[v][i];
                        if(e.cap == 0 or dist[e.to] <= dist[v] + e.cost) continue;
                        dist[e.to] = dist[v] + e.cost;
                        prevv[e.to] = v, preve[e.to] = i;
                        upd = true;
                    }
                }
                if(!upd) break;
            }

            if(dist[t] == IO) return -1;
            CapTp d = f;
            for(int v=t; v!=s; v=prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);
            f -= d; res += d * dist[t];
            for(int v=t; v!=s; v=prevv[v]) {
                auto &e = G[prevv[v]][preve[v]];
                e.cap -= d, G[v][e.rev].cap += d;
            }
        }
        return res;
    }
    // ポテンシャルの導入により、ダイクストラ法で最小費用流を解く
    // [仮定している条件]
    //     1. グラフに負の閉路が存在しない (流量の 0 初期化のため)
    //        もし存在するならベルマンフォードで負の閉路を見つけ
    //        そこに流せるだけ流してスタート
    //     2. グラフに負の辺が存在しない (pot_0 の計算可能性)
    //        もし存在する場合は最初のみベルマンフォードを使う必要あり
    CostTp fast_mincost_flow(int s, int t, CapTp f) {
        CostTp res = 0;
        vector<CostTp> dist(G.size()), pot(G.size());
        vector<int> prevv(G.size()), preve(G.size());
        while(f > 0) {
            using PT = pair<CostTp, int>;
            priority_queue< PT, vector<PT>, greater<PT> > que;
            fill(dist.begin(), dist.end(), IO);

            dist[s] = 0;
            que.push(make_pair(0, s));
            while(!que.empty()) {
                PT cur = que.top(); que.pop();
                int v = cur.second;
                if(dist[v] < cur.first) continue;
                for(size_t i=0; i<G[v].size(); i++) {
                    auto& e = G[v][i];
                    if(e.cap > 0 and dist[e.to] > dist[v] + e.cost + pot[v] - pot[e.to]) {
                        dist[e.to] = dist[v] + e.cost + pot[v] - pot[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(make_pair(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == IO) {
                return -1;
            }
            for(int v=0; v<(int)G.size(); v++) pot[v] += dist[v];

            CapTp d = f;
            for(int v=t; v!=s; v=prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * pot[t];
            for(int v=t; v!=s; v=prevv[v]) {
                auto& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }    
};

```

[トップページに戻る](../index.html)
