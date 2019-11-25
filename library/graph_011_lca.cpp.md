<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_011\_lca.cpp

## Code

```cpp
// 最小共通先祖 (Lowest Common Ancestor, LCA) を求める
// Verified: AOJ GRL_5_C (Lowest Common Ancestor)

template <typename T>
struct TreeLCA {
public:
    int const MAX_LOG_V;
    vector< vector< Edge<T> > > G;
    int root, vn;
    vector< vector<int> > parent;
    vector<int> depth;

    // constructor (Graph, root)
    TreeLCA(vector< vector< Edge<T> > > &_G, int _r) : 
        MAX_LOG_V(35), G(_G), root(_r), vn(G.size()), 
        parent(MAX_LOG_V, vector<int>(vn, 0)), depth(vn, -1)
        { depth[root] = 0; init(vn); }

    void dfs(int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for(int i=0; i<G[v].size(); i++) {
            if(depth[ G[v][i].to ] >= 0) continue;
            if(G[v][i].to != p) dfs(G[v][i].to, v, d+1);
        }
    }

    void init(int V) {
        dfs(root, -1, 0);
        for(int k=0; k+1 < MAX_LOG_V; k++) {
            for(int v=0; v < V; v++) {
                if(parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    // u と v の最小共通祖先
    int lca(int u, int v) {
        if(depth[u] > depth[v]) swap(u, v);
        for(int k=0; k < MAX_LOG_V; k++) {
            if((depth[v] - depth[u]) >> k & 1) {
                v = parent[k][v];
            }
        }
        if(u == v) return u;
        for(int k=MAX_LOG_V - 1; k>=0; k--) {
            if(parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // u と v のパスの長さ (LCA を使って計算)
    int dist(int u, int v) {
        int anc = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[anc];
    }
};
```

[トップページに戻る](../index.html)
