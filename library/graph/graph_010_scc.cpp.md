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


# :warning: graph/graph_010_scc.cpp
<a href="../../index.html">Back to top page</a>

* category: graph
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_010_scc.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Required
* :warning: <a href="verify/verify_graph_025_2SAT.cpp.html">graph/verify/verify_graph_025_2SAT.cpp</a>


## Code
{% raw %}
```cpp
// 強連結成分分解
// Verified: AOJ GRL_3_C (Strongly Connected Components)
// Verified: ARC030 C (有向グラフ) ← 強連結を潰したグラフの構築の検証

// これは 2 回の DFS によって実現できる。
// はじめに普通の DFS をするが、その時に帰りがけ順に頂点番号の配列を作る。
// 次に、元のグラフの逆辺のみで構成されたグラフに対して、
// 帰りがけ順が遅かったものから順に DFS を行う。
// 帰りかけが遅かった頂点ほど、 DAG の先頭の強連結成分に属しているため、
// 辺を逆向きにすると、先頭の強連結成分から外に出られなくなることを利用している。

template <typename T = int>
struct GraphSCC {
public:
    const int n;
    vector<bool> isthrough;
    vector<int> vs, cmp;
    vector< vector<int> > G, rG, H; // グラフ、逆辺グラフ、縮約後のグラフ

    GraphSCC(vector< vector< Edge<T> > > &g) :
        n(g.size()), isthrough(n, false), cmp(n, 0), G(n), rG(n) {
        for(int i=0; i<n; i++) {
            for(size_t j=0; j<g[i].size(); j++) {
                G[i].push_back(g[i][j].to);
                rG[ g[i][j].to ].push_back(i);
            }
        }
    }

    void SCC_dfsone(int cur) {
        isthrough[cur] = true;
        for(size_t i=0; i<G[cur].size(); i++) {
            if(!isthrough[G[cur][i]]) {
                SCC_dfsone(G[cur][i]);
            }
        }
        vs.push_back(cur);
    }

    void SCC_dfstwo(vector<int> &vec, int cur, int k) {
        cmp[cur] = k;
        isthrough[cur] = true;
        vec.push_back(cur);
        for(size_t i=0; i<rG[cur].size(); i++) {
            if(!isthrough[rG[cur][i]]) {
                SCC_dfstwo(vec, rG[cur][i], k);
            }
        }
    }

    // 縮約後のグループ、グループ数
    pair<vector<int>, int> scc() {
        // 1回めのDFS
        for(int i=0; i<n; i++)
            if(!isthrough[i]) SCC_dfsone(i);

        fill(isthrough.begin(), isthrough.end(), false);
        reverse(vs.begin(), vs.end());
        int k = 0; vector< vector<int> > S;

        // 2回めのDFS
        for(size_t i=0; i<vs.size(); i++) {
            if(!isthrough[vs[i]]) {
                S.push_back(vector<int>());
                SCC_dfstwo(S.back(), vs[i], k++);
            }
        }

        H.resize(k);
        fill(isthrough.begin(), isthrough.end(), false);
        for(size_t i=0; i<k; i++) {
            for(size_t j=0; j<S[i].size(); j++) {
                int v = S[i][j];
                for(size_t x=0; x<G[v].size(); x++) {
                    int u = G[v][x];
                    if(isthrough[cmp[u]] || cmp[v] == cmp[u]) continue;
                    isthrough[cmp[u]] = true;
                    H[cmp[v]].push_back(cmp[u]);
                }
            }
            for(size_t j=0; j<H[i].size(); j++) isthrough[ H[i][j] ] = false;
        }
        return make_pair(cmp, k);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

