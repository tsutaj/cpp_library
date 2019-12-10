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


# :warning: graph/graph_003_warshall.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_003_warshall.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// ワーシャルフロイド法 (全点対最短路問題)
// 計算量 O(|V|^3 )
// 負の閉路があるかどうかは、d[i][i]が負になる頂点 i があるかどうかで判定可能

template <typename T>
vector< vector<T> > warshall(vector< vector< Edge<T> > > &G) {
    int V = G.size();
    vector< vector<T> > d(V);
    for(size_t i=0; i<V; i++) {
        for(size_t j=0; j<V; j++) { {
                if(i == j) d[i].push_back(0);
                else d[i].push_back(numeric_limits<T>::max());
            }
        }
    }

    for(size_t i=0; i<V; i++) {
        for(size_t j=0; j<G[i].size(); j++) {
            Edge<T> e = G[i][j];
            d[i][e.to] = e.cost;
        }
    }

    for(size_t k=0; k<V; k++) {
        for(size_t i=0; i<V; i++) {
            for(size_t j=0; j<V; j++) {
                if(d[i][k] != numeric_limits<T>::max() && d[k][j] != numeric_limits<T>::max())
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    return d;
}

// (負の閉路があったら true になる bool minus)
bool minus = false;
vector< vector<Edge<T> > > G;
vector< vector<T> > d = warshall(G);
for(size_t i=0; i<G.size(); i++) if(d[i][i] < 0) minus = true;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

