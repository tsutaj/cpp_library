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


# :warning: graph/verify/verify_graph_023_offline_lca.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_023_offline_lca.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../graph_000_basic.cpp.html">graph/graph_000_basic.cpp</a>
* :warning: <a href="../graph_023_offline_lca.cpp.html">graph/graph_023_offline_lca.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_023_offline_lca.cpp"

void GRL_5_C() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        queries[i] = make_pair(u, v);
    }
    
    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) cout << lca[i] << endl;
}

void ABC014_D() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> depth(N);
    function<void(int, int)> go = [&](int cur, int par) {
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            depth[e.to] = depth[cur] + 1;
            go(e.to, cur);
        }
    };
    go(0, -1);

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        queries[i] = make_pair(u, v);
    }

    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) {
        int u, v; tie(u, v) = queries[i];
        int du = depth[u], dv = depth[v], dl = depth[ lca[i] ];
        cout << du + dv - 2 * dl + 1 << endl;
    }
}

int main() {
    // GRL_5_C();
    ABC014_D();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_023_offline_lca.cpp"
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;
#line 1 "graph/verify/../graph_000_basic.cpp"
// 移動元と行先と辺のコストを記録する構造体
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    Edge(int s, T d = 1) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

template <typename T = int>
using Graph = vector< vector< Edge<T> > >;
#line 1 "graph/verify/../graph_023_offline_lca.cpp"
// Tarjan's off-line LCA algorithm
// 依存ライブラリ
// ・グラフ辺構造体 (graph_000_basic.cpp)

struct OfflineLCA {
    Graph<> G;
    vector<int> node, anc, color, answers;
    vector< vector< pair<int, int> > > queries;
    int find(int k) { return node[k] < 0 ? k : find(node[k]); }
    int size(int k) { return -node[find(k)]; }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(size(u) < size(v)) swap(u, v);
        node[u] += node[v];
        node[v] = u;
    }

    void build(int cur, int par=-1) {
        anc[cur] = cur;
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            build(e.to, cur);
            unite(e.to, cur);
            anc[find(cur)] = cur;
        }
        color[cur] = 1;
        for(auto q : queries[cur]) {
            int to, idx; tie(to, idx) = q;
            if(color[to] == 1) {
                int lca = anc[find(to)];
                answers[idx] = lca;
            }
        }
    }
    
    OfflineLCA(Graph<> G, vector< pair<int, int> > Q, int root=0) : G(G) {
        size_t N = G.size(), M = Q.size();
        node = anc = color = vector<int>(N);
        fill(node.begin(), node.end(), -1);

        queries.resize(N); answers.resize(M);
        for(size_t i=0; i<M; i++) {
            int u, v; tie(u, v) = Q[i];
            queries[u].emplace_back(v, i);
            queries[v].emplace_back(u, i);
        }
        build(root);
    }

    int& operator[] (int k) { return answers[k]; }
};
#line 10 "graph/verify/verify_graph_023_offline_lca.cpp"

void GRL_5_C() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        queries[i] = make_pair(u, v);
    }
    
    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) cout << lca[i] << endl;
}

void ABC014_D() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> depth(N);
    function<void(int, int)> go = [&](int cur, int par) {
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            depth[e.to] = depth[cur] + 1;
            go(e.to, cur);
        }
    };
    go(0, -1);

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        queries[i] = make_pair(u, v);
    }

    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) {
        int u, v; tie(u, v) = queries[i];
        int du = depth[u], dv = depth[v], dl = depth[ lca[i] ];
        cout << du + dv - 2 * dl + 1 << endl;
    }
}

int main() {
    // GRL_5_C();
    ABC014_D();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

