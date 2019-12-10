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


# :warning: graph/graph_001_bellman.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_001_bellman.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
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
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

