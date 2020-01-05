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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: graph/verify/verify_graph_018_dinic.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_018_dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../graph_018_dinic.cpp.html">graph/graph_018_dinic.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#include "../graph_018_dinic.cpp"

void GRL_6_A() {
    int V, E; scanf("%d%d", &V, &E);
    Dinic<> fl(V);
    for(int i=0; i<E; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        fl.add_edge(u, v, c);
    }
    int source = 0, sink = V - 1;
    printf("%d\n", fl.max_flow(source, sink));
}

// 復元の Verify
void AOJ2304() {
    int N, M; scanf("%d%d", &N, &M);
    Dinic<> fl(N);
    for(int i=0; i<M; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        fl.add_edge(u, v, 1);
        fl.add_edge(v, u, 1); // 逆向きの辺 (これに流れるかどうか？)
    }
    int source, sink; scanf("%d%d", &source, &sink);
    source--; sink--;
    
    int flow = fl.max_flow(source, sink);
    printf("%d\n", flow);
    vector<int> ans;
    for(int i=0; i<M; i++) {
        int k = 2*i + 1;
        if(fl.get_flowed_cap(k) == 1) ans.emplace_back(i + 1);
    }
    printf("%zu\n", ans.size());
    for(auto k : ans) printf("%d\n", k);
}

int main() {
    // GRL_6_A();
    AOJ2304();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_018_dinic.cpp"
#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#line 1 "graph/verify/../graph_018_dinic.cpp"
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
#line 9 "graph/verify/verify_graph_018_dinic.cpp"

void GRL_6_A() {
    int V, E; scanf("%d%d", &V, &E);
    Dinic<> fl(V);
    for(int i=0; i<E; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        fl.add_edge(u, v, c);
    }
    int source = 0, sink = V - 1;
    printf("%d\n", fl.max_flow(source, sink));
}

// 復元の Verify
void AOJ2304() {
    int N, M; scanf("%d%d", &N, &M);
    Dinic<> fl(N);
    for(int i=0; i<M; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        fl.add_edge(u, v, 1);
        fl.add_edge(v, u, 1); // 逆向きの辺 (これに流れるかどうか？)
    }
    int source, sink; scanf("%d%d", &source, &sink);
    source--; sink--;
    
    int flow = fl.max_flow(source, sink);
    printf("%d\n", flow);
    vector<int> ans;
    for(int i=0; i<M; i++) {
        int k = 2*i + 1;
        if(fl.get_flowed_cap(k) == 1) ans.emplace_back(i + 1);
    }
    printf("%zu\n", ans.size());
    for(auto k : ans) printf("%d\n", k);
}

int main() {
    // GRL_6_A();
    AOJ2304();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

