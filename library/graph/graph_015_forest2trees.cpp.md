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


# :warning: graph/graph_015_forest2trees.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_015_forest2trees.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 森を木の vector に分解する (無向) O(|V|)
// ・まだチェックしていない頂点に関して、その頂点から BFS を行う
// ・頂点番号を振り直しながら辺を張っていく

template <typename T>
using Graph = vector< vector< Edge<T> > >;

template <typename T>
Graph<T> Forest2Trees(Graph<T> &G) {
    int n = (int)G.size();
    vector<int> vtxid(n, -1);

    vector< Graph<T> > ret;
    for(int i=0; i<n; i++) {
        if(vtxid[i] >= 0) continue;
        Graph<T> Tree(1);
        int cur = 0;
        vtxid[i] = cur++;

        queue<int> q; q.push(i);
        while(!q.empty()) {
            int k = q.front(); q.pop();
            for(size_t x=0; x<G[k].size(); x++) {
                int to = G[k][x].to; T cost = G[k][x].cost;
                if(vtxid[to] >= 0) continue;
                vtxid[to] = cur++;
                Tree.push_back(vector< Edge<T> >());
                Tree[ vtxid[k ] ].push_back( Edge<T>(vtxid[to], cost) );
                Tree[ vtxid[to] ].push_back( Edge<T>(vtxid[k ], cost) );
                q.push(to);
            }
        }
        ret.push_back(Tree);
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

