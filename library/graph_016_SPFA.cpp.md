<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: graph\_016\_SPFA.cpp
---

## Code

```cpp
// Shortest Path Faster Algorithm (SPFA)
// 平均計算量 O(|E|)、最悪計算量 O(|V||E|)
// Verified: AOJ GRL_1_A, GRL_1_B

// ・頂点がキューに入っているかどうかを記憶する配列が必要
// ・更新時に頂点がすでに入っているなら push しないが、頂点が入っていなければ push するだけ
// ・負閉路がない場合、各頂点に対して更新は V-1 回しか起こらないが、
//   負閉路の場合はそれを超えて更新されるため、負の閉路の検出が可能である
// ・頂点 1 から N までの最短経路を求める SPFA の最悪ケース
//   -> ランダムに大きい辺を 4N 本ほど張る
//   -> 1 to 2, 2 to 3, ..., N-1 to N にコストの小さい辺を張る
//      (要するに、最短経路が N-1 本の辺からなるようにする)
//   -> こうすることで更新が多数起こり、O(|V||E|) に近づくらしい

vector<int> m(V, 0);
vector<bool> inq(V, false);
queue<int> que;
vector<int> rec(V, 1 << 30);
que.push(start);
inq[start] = true;
rec[start] = 0;

while(!que.empty()) {
    int point = que.front(); que.pop();
    inq[point] = false;
    for(size_t i=0; i<G[point].size(); i++) {
        Edge<int> next = G[point][i];
        int to = next.to, cost = next.cost;
        if(rec[to] > rec[point] + cost) {
            rec[to] = rec[point] + cost;
            if(!inq[to]) {
                /*
                if(++m[to] >= V) {
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
                */
                inq[to] = true;
                que.push(to);
            }
        }
    }
}
```

[トップページに戻る](../index.html)
