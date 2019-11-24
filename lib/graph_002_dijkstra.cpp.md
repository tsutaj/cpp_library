[トップページに戻る](../index.html)

# graph\_002\_dijkstra.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

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
}```

[トップページに戻る](../index.html)
