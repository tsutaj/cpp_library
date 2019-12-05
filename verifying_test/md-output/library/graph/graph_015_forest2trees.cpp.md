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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../graph/graph_015_forest2trees.cpp
* category: ../../graph


[Back to top page](../../index.html)



## Code
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

[Back to top page](../../index.html)
