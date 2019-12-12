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


# :warning: graph/graph_017_bipartite.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_017_bipartite.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 二部マッチング (最大流を使って解く)
// ・普通に辺を張る他に、自分で別に頂点を 2 つ用意する

template <typename T>
struct Edge {
    int to; T cap, cost; int rev;
    Edge(int t, T c, int r) : to(t), cap(c), rev(r) {}
    Edge(int t, T ca, T co, int r) : to(t), cap(ca), cost(co), rev(r) {}
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;

struct BipartiteMatching {
    int S, T, E, a, b;
    vector< vector< Edge<int> > > G;
    vector<int> used;
    BipartiteMatching(int x, int y, int z) : S(x), T(y), E(z) {
        G.resize(S+T+2);
        used.resize(S+T+2);
        a = S + T, b = a + 1;
        for(int i=0; i<S; i++) add_edge(a  , i, 1);
        for(int i=0; i<T; i++) add_edge(i+S, b, 1);
    }
    void add_edge(int from, int to, int cap) {
        G[from].push_back(Edge<int>(to  , cap, G[to  ].size()    ));
        G[to  ].push_back(Edge<int>(from, 0  , G[from].size() - 1));
    }
    void readGraph() {
        for(int i=0; i<E; i++) {
            int x, y; cin >> x >> y;
            // x--; y--;
            add_edge(x, y+S, 1);
        }
    }
    int dfs(int v, int t, int f) {
        if(v == t) return f;
        used[v] = true;
        for(size_t i=0; i<G[v].size(); i++) {
            Edge<int> &e = G[v][i];
            if(!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    int solve() {
        int flow = 0;
        while(1) {
            fill(used.begin(), used.end(), 0);
            int f = dfs(a, b, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }
};

/*
signed main() {
    int x, y, e; cin >> x >> y >> e;
    BipartiteMatching B(x, y, e);
    B.readGraph();
    cout << B.solve() << endl;
    return 0;
}
*/
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

