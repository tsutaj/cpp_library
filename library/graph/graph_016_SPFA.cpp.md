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


# :warning: graph/graph_016_SPFA.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_016_SPFA.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

