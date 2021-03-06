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
