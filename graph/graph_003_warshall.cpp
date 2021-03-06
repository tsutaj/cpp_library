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
