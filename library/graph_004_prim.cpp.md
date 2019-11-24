<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# graph\_004\_prim.cpp
---

## Code

```cpp
// プリム法 (最小全域木問題)
// Edgeには from, to, cost の情報が必須。計算量 O( |V|^2 )
// → priority_queueを用いて、O( |E| log|V| )！
// ここに書いてあるのは勿論オーダー小さい方の実装です。

// 最小全域木(無向)
// Verified: AOJ GRL_2_A: Minimum Spanning Tree
template <typename T>
T prim(vector< vector< Edge<T> > > &G) {
    int V = G.size(); T ans = 0;
    vector<bool> used(V, false);
    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;
    q.push(Edge<T>(0, 0, 0));
    while(!q.empty()) {
        Edge<T> temp = q.top(); q.pop();
        if(used[temp.to]) continue;
        used[temp.to] = true;
        ans += temp.cost;
        for(size_t i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);
    }
    return ans;
}

// 最小全域木(無向) 重みと辺集合のペアで返すよ！
template <typename T>
pair<int, vector< Edge<T> > > prim(vector< vector< Edge<T> > > &G) {
    int V = G.size(); T ans = 0;
    vector< Edge<T> > ans_e;
    vector<bool> used(V, false);
    priority_queue< Edge<T>, vector< Edge<T> >, greater< Edge<T> > > q;
    q.push(Edge<T>(-1, 0, 0));
    while(!q.empty()) {
        Edge<T> temp = q.top(); q.pop();
        if(used[temp.to]) continue;
        used[temp.to] = true;
        ans += temp.cost; if(temp.from >= 0) ans_e.push_back(temp);
        for(size_t i=0; i<G[temp.to].size(); i++) q.push(G[temp.to][i]);
    }
    // 全域木作れないなら答えを INF にする
    for(int i=0; i<V; i++) if(!used[i]) ans = numeric_limits<T>::max();
    return pair<int, vector< Edge<T> > >(ans, ans_e);
}

// 最小全域有向木 (有向)
// (Under construction)

```

[トップページに戻る](../index.html)
