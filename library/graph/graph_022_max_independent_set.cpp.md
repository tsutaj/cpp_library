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


# :warning: graph/graph_022_max_independent_set.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_022_max_independent_set.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

