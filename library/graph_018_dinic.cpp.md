<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_018\_dinic.cpp

## Code

```cpp
// Dinic を信じろ

template <typename CapTp=int, typename CostTp=int>
struct Edge {
    int to, rev;
    CapTp cap; CostTp cost;
    bool is_rev;
    Edge(int t, bool f, int r, CapTp ca, CostTp co=0)
        : to(t), rev(r), cap(ca), cost(co), is_rev(f) {}
};

template<typename CapTp=int>
struct Dinic {
    using Graph = vector< vector< Edge<CapTp> > >;
    Graph G;
    vector<int> level, iter;
    const CapTp IA;
    vector< pair<int, int> > r_edges;
    Dinic(int N, CapTp IA_=1<<29) : IA(IA_) {
        G.resize(N);
        level.resize(N);
        iter.resize(N);
    }
    void add_edge(int from, int to, CapTp cap) {
        G[from].emplace_back(to, false, G[to].size(), cap);
        G[to].emplace_back(from, true, G[from].size() - 1, 0);
        r_edges.emplace_back(to, G[to].size() - 1);
    }
    CapTp get_flowed_cap(size_t k) {
        if(r_edges.size() <= k) return -1;
        int v, i; tie(v, i) = r_edges[k];
        return G[v][i].cap;
    }
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que; que.push(s);
        level[s] = 0;
        while(!que.empty()) {
            int temp = que.front(); que.pop();
            for(size_t i=0; i<G[temp].size(); i++) {
                auto &e = G[temp][i];
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[temp] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    CapTp dfs(int v, int t, CapTp f) {
        if(v == t) return f;
        for(int &i = iter[v]; i<(int)G[v].size(); i++) {
            auto &e = G[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                CapTp d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    CapTp max_flow(int s, int t) {
        CapTp flow = 0.0, f;
        while(1) {
            bfs(s);
            if(level[t] < 0) return flow;
            fill(iter.begin(), iter.end(), 0);
            while( (f = dfs(s, t, IA)) > 0 ) flow += f;
        }
    }
};

// 最小流量制約付きフロー
// u から v に最小 lb, 最大 ub 流す
template<typename flow_type>
struct Dinic_lr {
    Dinic<flow_type> fl;
    int S, T;
    flow_type sum_lb;

    Dinic_lr() {}
    Dinic_lr(int N) : fl(N+2, 0), S(N), T(N+1), sum_lb(0) {}

    void add_edge(int u, int v, flow_type lb, flow_type ub) {
        assert(0 <= lb && lb <= ub);
        if(u == v || ub == 0) return;
        fl.add_edge(u, v, ub - lb);
        fl.add_edge(S, v, lb);
        fl.add_edge(u, T, lb);
        sum_lb += lb;
    }

    flow_type max_flow(int s, int t) {
        flow_type a = fl.max_flow(S, T);
        flow_type b = fl.max_flow(s, T);
        flow_type c = fl.max_flow(S, t);
        flow_type d = fl.max_flow(s, t);
        return (a + c == sum_lb && a + b == sum_lb) ? b + d : -1;
    }
};

```

[トップページに戻る](../index.html)
