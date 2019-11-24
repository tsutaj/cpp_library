[トップページに戻る](../index.html)

# graph\_005\_kruskal.cpp
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
