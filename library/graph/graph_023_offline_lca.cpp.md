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


# :warning: graph/graph_023_offline_lca.cpp
* category: graph


[Back to top page](../../index.html)



## Required
* :warning: [graph/verify/verify_graph_023_offline_lca.cpp](verify/verify_graph_023_offline_lca.cpp.html)


## Code
{% raw %}
```cpp
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

```
{% endraw %}

[Back to top page](../../index.html)

