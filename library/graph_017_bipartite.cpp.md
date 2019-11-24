<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: graph\_017\_bipartite.cpp
---

## Code

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

[トップページに戻る](../index.html)
