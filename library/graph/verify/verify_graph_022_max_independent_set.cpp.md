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


# :warning: graph/verify/verify_graph_022_max_independent_set.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_022_max_independent_set.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../graph_000_basic.cpp.html">graph/graph_000_basic.cpp</a>
* :warning: <a href="../graph_022_max_independent_set.cpp.html">graph/graph_022_max_independent_set.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <utility>
#include <cassert>
#include <bitset>
#include <map>
#include <climits>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_022_max_independent_set.cpp"

void CODE_THANKS_FESTIVAL_2017_G() {
    int N, M; scanf("%d%d", &N, &M);
    Graph<int> G(N);
    for(int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v); u--; v--;
        G[u].emplace_back(v, 1);
        G[v].emplace_back(u, 1);
    }

    MaximalIndependentSet<> miset(G);
    printf("%d\n", miset.solve());
}

void AOJ2403() {
    auto solve_testcase = [&]() {
        int N; cin >> N;
        if(N == 0) return 1;

        map<string, int> comp;
        vector<string> A(N); vector< vector<string> > D(N);
        vector<int> B(N);

        for(int i=0; i<N; i++) {
            int k; cin >> A[i] >> B[i] >> k;
            comp[ A[i] ]++;
            for(int j=0; j<k; j++) {
                string s; cin >> s;
                D[i].emplace_back(s);
                comp[s]++;
            }
        }

        int id = 0;
        for(auto &e : comp) e.second = id++;

        vector<int> costs(N), used(N);

        // 自分の国の隣は選べないため
        for(auto s : D[0]) {
            int v = comp[s];
            used[v] = true;
        }
        
        Graph<int> G(N);
        for(int i=0; i<N; i++) {
            int u = comp[ A[i] ];
            if(used[u]) continue;
            costs[u] = B[i];

            // 対称らしいので片方だけでいい
            // 自分の国の隣は選べないので辺を張らない
            for(auto s : D[i]) {
                int v = comp[s];
                if(!used[v]) G[u].emplace_back(v, 1);
            }
        }

        MaximalIndependentSet<> miset(G, costs);
        cout << miset.solve() << endl;
        return 0;
    };

    while(!solve_testcase());
}

int main() {
    CODE_THANKS_FESTIVAL_2017_G();
    // AOJ2403();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

