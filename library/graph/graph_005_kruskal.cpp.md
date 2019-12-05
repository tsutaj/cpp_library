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


# :warning: graph/graph_005_kruskal.cpp
* category: graph


[Back to top page](../../index.html)



## Code
```cpp
// クラスカル法 (最小全域木問題)
// Edgeには from, to, cost の情報が必須。計算量( |E| log|V| )
// Union-find木を使うので、それも忘れずに組み込むこと。

template <typename T>
T kruskal(vector< vector< Edge<T> > > &G) {
    int V = G.size();
    vector< Edge<T> > es;
    for(size_t i=0; i<V; i++) {
        for(size_t j=0; j<G[i].size(); j++) {
            es.push_back(G[i][j]);
        }
    }
    int E = es.size();
    sort(es.begin(), es.end());
    UnionFind uf(V);
    T res = 0;
    for(int i=0; i<E; i++) {
        Edge<T> e = es[i];
        if(!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            res += e.cost;
        }
    }
    return res;
}

// 最小全域有向木 (有向グラフ)

```

[Back to top page](../../index.html)

