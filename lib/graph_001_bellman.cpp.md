[トップページに戻る](../index.html)

# graph\_001\_bellman.cpp
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
/***** ベルマンフォード法 *****/
// 計算量 O(|V| |E|)
// 単一始点最短路問題を解く。各辺の重みは負数でもよい
// 通常 |V| - 1 回実行してループを抜けるが、負のコストの閉路が存在する場合は
// V 回目でも更新が発生する → 負の閉路の検出にも使える

// グラフに、s から到達可能な負の閉路があるかどうかを検出する
template <typename T>
bool find_negative_loop(vector< vector< Edge<T> > > &G, int s) {
    int V = G.size();
    vector<T> d(V);
    for(int i=0; i<V; i++) d[i] = numeric_limits<T>::max(); d[s] = 0;
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            for(int k=0; k<G[j].size(); k++) {
                Edge<T> e = G[j][k];
                if(d[j] != numeric_limits<T>::max() && d[e.to] > d[j] + e.cost) {
                    d[e.to] = d[j] + e.cost;

                    // n 回目にも更新があるなら負の閉路が存在する
                    if(i == V - 1) return true;
                }
            }
        }
    }
    return false;
}

// グラフ全体を見て、負の閉路があるかどうかを検出する
template <typename T>
bool find_negative_loop_whole(vector< vector< Edge<T> > > &G) {
    int V = G.size();
    vector<T> d(V);
    fill(d.begin(), d.end(), 0);
    for(int i=0; i<V; i++) {
        for(int j=0; j<V; j++) {
            for(int k=0; k<G[j].size(); k++) {
                Edge<T> e = G[j][k];
                if(d[e.to] > d[j] + e.cost) {
                    d[e.to] = d[j] + e.cost;

                    // n 回目にも更新があるなら負の閉路が存在する
                    if(i == V - 1) return true;
                }
            }
        }
    }
    return false;
}

// 頂点の数V, 辺の数Eのグラフにおいて、 s 番目の頂点から各頂点への最短距離を求める
template <typename T>
vector<T> bellman(vector< vector< Edge<T> > > &G, int s) {
    // 頂点の数と辺の数を数える
    int V = G.size();
    vector<T> d(V);
    for(int i=0; i<V; i++) d[i] = numeric_limits<T>::max();
    d[s] = 0;

    while(true) {
        bool update = false;
        for(int i=0; i<V; i++) {
            for(int j=0; j<G[i].size(); j++) {
                Edge<T> e = G[i][j];
                if(d[i] != numeric_limits<T>::max() && d[e.to] > d[i] + e.cost) {
                    d[e.to] = d[i] + e.cost;
                    update = true;
                }
            }
        }
        if(!update) break;
    }
    return d;
}```

[トップページに戻る](../index.html)
