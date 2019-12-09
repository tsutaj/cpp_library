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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: graph/verify/verify_graph_023_offline_lca.cpp
* category: graph/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [graph/graph_000_basic.cpp](../graph_000_basic.cpp.html)
* :warning: [graph/graph_023_offline_lca.cpp](../graph_023_offline_lca.cpp.html)


## Code
{% raw %}
```cpp
#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_023_offline_lca.cpp"

void GRL_5_C() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        queries[i] = make_pair(u, v);
    }
    
    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) cout << lca[i] << endl;
}

void ABC014_D() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> depth(N);
    function<void(int, int)> go = [&](int cur, int par) {
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            depth[e.to] = depth[cur] + 1;
            go(e.to, cur);
        }
    };
    go(0, -1);

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        queries[i] = make_pair(u, v);
    }

    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) {
        int u, v; tie(u, v) = queries[i];
        int du = depth[u], dv = depth[v], dl = depth[ lca[i] ];
        cout << du + dv - 2 * dl + 1 << endl;
    }
}

int main() {
    // GRL_5_C();
    ABC014_D();
    return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

