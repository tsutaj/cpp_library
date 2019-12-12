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


# :warning: graph/graph_004_prim.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_004_prim.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// プリム法 (最小全域木問題)
// Edgeには from, to, cost の情報が必須。計算量 O( |V|^2 )
// → priority_queueを用いて、O( |E| log|V| )！
// ここに書いてあるのは勿論オーダー小さい方の実装です。

// 最小全域木(無向)
// Verified: AOJ GRL_2_A: Minimum Spanning Tree
template <typename T>
T prim(vector< vector< Edge<T> > > &G) {
    int V = G.size(); T ans = 0;
    vector<bool> used(V, false);
    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;
    q.push(Edge<T>(0, 0, 0));
    while(!q.empty()) {
        Edge<T> temp = q.top(); q.pop();
        if(used[temp.to]) continue;
        used[temp.to] = true;
        ans += temp.cost;
        for(size_t i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);
    }
    return ans;
}

// 最小全域木(無向) 重みと辺集合のペアで返すよ！
template <typename T>
pair<int, vector< Edge<T> > > prim(vector< vector< Edge<T> > > &G) {
    int V = G.size(); T ans = 0;
    vector< Edge<T> > ans_e;
    vector<bool> used(V, false);
    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;
    q.push(Edge<T>(-1, 0, 0));
    while(!q.empty()) {
        Edge<T> temp = q.top(); q.pop();
        if(used[temp.to]) continue;
        used[temp.to] = true;
        ans += temp.cost; if(temp.from >= 0) ans_e.push_back(temp);
        for(size_t i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);
    }
    // 全域木作れないなら答えを INF にする
    for(int i=0; i<V; i++) if(!used[i]) ans = numeric_limits<T>::max();
    return pair<int, vector< Edge<T> > >(ans, ans_e);
}

// 最小全域有向木 (有向)
// (Under construction)

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

