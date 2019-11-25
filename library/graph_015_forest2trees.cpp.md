<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_015\_forest2trees.cpp

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

[トップページに戻る](../index.html)