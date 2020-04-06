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
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../graph_000_basic.cpp.html">graph/graph_000_basic.cpp</a>
* :warning: <a href="../graph_022_max_independent_set.cpp.html">graph/graph_022_max_independent_set.cpp</a>


## Code

<a id="unbundled"></a>
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

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_022_max_independent_set.cpp"
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
#line 1 "graph/graph_000_basic.cpp"
// 移動元と行先と辺のコストを記録する構造体
template <typename T = int>
struct Edge {
    int from, to;
    T cost;
    Edge(int s, T d = 1) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

template <typename T = int>
using Graph = vector< vector< Edge<T> > >;
#line 1 "graph/graph_022_max_independent_set.cpp"
// 無向非連結グラフの最大独立集合 (maximal independent set)
// 頂点の集合 V であって、V の任意の 2 つをつなぐ辺が存在しない場合
// 次数 1 であれば必ず採用・そうでなければ次数が大きいものから試す、
// とすると枝刈りがきいて高速になる

const int GRAPH_SIZE = 40;
using gbit = bitset<GRAPH_SIZE>;

// bitset には比較演算子がないので・・・
namespace std {
    bool operator<(const gbit &a, const gbit &b) {
        gbit ab = a ^ b;
        int k = ab._Find_first();
        return k < GRAPH_SIZE and b[k] == 1;
    }
}

template <typename CostType = int>
struct MaximalIndependentSet {   
    Graph<int> G;
    int N; vector<CostType> costs;
    gbit alive;
    vector<gbit> adj;
    bool weighted;
    map<gbit, CostType> rec;

    // 無向グラフを入力として与える
    MaximalIndependentSet(Graph<int> G_,
                          vector<CostType> costs_ = vector<CostType>())
        : G(G_), costs(costs_) {

        N = G_.size();
        if(costs.size() != N) {
            costs = vector<CostType>(N, 1);
            weighted = false;
        }
        else weighted = true;
   
        alive = gbit();
        adj = vector<gbit>(N);

        for(int i=0; i<N; i++) {
            alive[i] = true;
            for(auto e : G[i]) adj[i][e.to] = 1;
        }
    }

    inline int deg(int v) {
        return (alive & adj[v]).count();
    }

    // その時点で次数最大の頂点を見つける
    int argmax_deg() {
        int max_deg = -1, res = -1;
        for(int i=0; i<N; i++) {
            if(!alive[i]) continue;
            int d = deg(i);
            if(d > max_deg) max_deg = d, res = i;
        }
        return res;
    }

    pair< CostType, gbit > solve_part1() {
        CostType d = 0; gbit res;
        // 次数 0 または 1 の頂点を全部見つける
        // 重みがある場合は 0 のみ
        for(int i=0; i<N; i++) {
            if(alive[i] and !res[i] and deg(i) <= !weighted) {
                res[i] = true; d += costs[i];
                res |= (alive & adj[i]);
            }
        }
        return make_pair(d, res);
    }

    CostType solve_part2() {
        int v = argmax_deg(); CostType res = 0;
        if(v < 0) return CostType(0);
        
        // v を使わない
        alive[v] = false;
        res = max(res, solve());

        // v を使う
        gbit vs = alive & adj[v];
        alive ^= vs;
        res = max(res, solve() + costs[v]);
        alive ^= vs;

        alive[v] = true;
        return res;
    }

    CostType solve() {
        if(rec.count(alive)) return rec[alive];
        
        CostType v1; gbit vs;
        tie(v1, vs) = solve_part1();
        alive ^= vs;
        CostType v2 = solve_part2();
        alive ^= vs;
        return rec[alive] = v1 + v2;
    }
};
#line 14 "graph/verify/verify_graph_022_max_independent_set.cpp"

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

