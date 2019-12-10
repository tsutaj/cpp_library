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


# :warning: graph/graph_002_dijkstra.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_002_dijkstra.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Code
{% raw %}
```cpp
// ダイクストラ法 (priority_queueを用いて、 O(|E| log|V|) )
// 注意: 負の辺が存在する場合、この方法は使えないよ！！！！

template <typename T>
vector<T> dijkstra(vector< vector< Edge<T> > > &G, int s) {
    int V = G.size();
    vector<T> d(V); fill(d.begin(), d.end(), numeric_limits<T>::max());
    priority_queue<pair<T, int> , vector< pair<T, int> >, greater< pair<T, int> > > que;
    d[s] = 0;
    que.push(make_pair(0,s));

    while(!que.empty()) {
        pair<T, int> p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;
        for(int i=0; i<G[v].size(); i++) {
            Edge<T> e = G[v][i];
            if(d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(make_pair(d[e.to], e.to));
            }
        }
    }
    return d;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

