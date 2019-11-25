<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
  jax: ["input/TeX", "output/HTML-CSS"],
  tex2jax: {
    inlineMath: [ ['$', '$'] ],
    displayMath: [ ['$$', '$$']],
    processEscapes: true,
    skipTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']
  },
  messageStyle: "none",
  "HTML-CSS": { preferredFont: "TeX", availableFonts: ["STIX","TeX"] }
});
</script>
<script src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML" type="text/javascript"></script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_005\_kruskal.cpp

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

[トップページに戻る](../index.html)
