<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_002\_dijkstra.cpp

## Code

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

[トップページに戻る](../index.html)
