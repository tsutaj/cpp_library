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


# :warning: graph/graph_024_boruvka.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_024_boruvka.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Required
* :warning: <a href="verify/verify_graph_024_boruvka.cpp.html">graph/verify/verify_graph_024_boruvka.cpp</a>


## Code
{% raw %}
```cpp
// Boruvka's algorithm (最小全域木を求める)
// その時点で存在するそれぞれの木について、それに接続している辺で重み最小のものを探す関数が必要
// 依存ライブラリ: UnionFind

template <typename T, typename F>
T boruvka(int N, F f) {
    UnionFind uf(N);
    vector<int> group(N), rev(N);
    T ans(0);

    while(uf.size() > 1) {
        // 各頂点が何番目の連結成分に属するか？
        // ある連結成分について代表元はなにか？
        int ptr = 0;
        for(int i=0; i<N; i++) {
            if(uf.find(i) == i) {
                group[i] = ptr++;
                rev[ group[i] ] = i;
            }
        }
        for(int i=0; i<N; i++) group[i] = group[ uf.find(i) ];

        // 異なる連結成分同士を結んでいる辺の候補をもってくる
        // 各連結成分に対して (最小コスト・繋げる先 (ないなら -1))
        auto edges = f(ptr, group);

        bool changed = false;
        for(int u=0; u<ptr; u++) {
            T cost; int v; tie(cost, v) = edges[u];
            if(v >= 0 and uf.unite(rev[u], rev[v])) {
                ans += cost;
                changed = true;
            }
        }

        if(!changed) return false;
    }

    return ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

