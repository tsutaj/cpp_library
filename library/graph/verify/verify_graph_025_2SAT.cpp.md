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


# :warning: graph/verify/verify_graph_025_2SAT.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_025_2SAT.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../graph_000_basic.cpp.html">graph/graph_000_basic.cpp</a>
* :warning: <a href="../graph_010_scc.cpp.html">graph/graph_010_scc.cpp</a>
* :warning: <a href="../graph_025_2SAT.cpp.html">graph/graph_025_2SAT.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <iostream>
#include <cstdio>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_010_scc.cpp"
#include "../graph_025_2SAT.cpp"

void yuki_274() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> L(N), R(N);

    auto flip = [&](int l, int r) {
        return make_pair(M - 1 - r, M - 1 - l);
    };

    auto intersect = [&](int al, int ar, int bl, int br) {
        return !(ar < bl or br < al);
    };
    
    for(int i=0; i<N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                int al = L[i], ar = R[i];
                int bl = L[j], br = R[j];
                if(bit & 1) tie(al, ar) = flip(al, ar);
                if(bit & 2) tie(bl, br) = flip(bl, br);

                if(intersect(al, ar, bl, br)) {
                    switch(bit) {
                    case 0:
                        // A and B はダメ -> NA or NB
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        // NA and B はダメ -> A or NB
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        // A and NB はダメ -> NA or B
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        // NA and NB はダメ -> A or B
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }
    auto res = tsat.build();
    if(res.size() == N) puts("YES");
    else puts("NO");
}

void yuki_470() {
    int N; cin >> N;
    vector<string> U(N);
    for(int i=0; i<N; i++) cin >> U[i];

    if(N > 52) {
        cout << "Impossible" << endl;
        return;
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                string sa, sb, ta, tb;
                if(bit & 1) sa = U[i].substr(0, 1), sb = U[i].substr(1); // NA, NB
                else sa = U[i].substr(0, 2), sb = U[i].substr(2); // A, B
                if(bit & 2) ta = U[j].substr(0, 1), tb = U[j].substr(1);
                else ta = U[j].substr(0, 2), tb = U[j].substr(2);

                if(sa == ta or sb == tb or sa == tb or sb == ta) {
                    switch(bit) {
                    case 0:
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }

    vector<int> res = tsat.build();
    if(res.empty()) cout << "Impossible" << endl;
    else {
        vector<string> pre(N), suf(N);
        for(int i=0; i<N; i++) {
            if(res[i]) pre[i] = U[i].substr(0, 2), suf[i] = U[i].substr(2);
            else pre[i] = U[i].substr(0, 1), suf[i] = U[i].substr(1);
            cout << pre[i] << " " << suf[i] << endl;
        }
    }
}

int main() {
    // yuki_274();
    yuki_470();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_025_2SAT.cpp"
#include <vector>
#include <iostream>
#include <cstdio>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
#line 1 "graph/verify/../graph_000_basic.cpp"
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
#line 1 "graph/verify/../graph_010_scc.cpp"
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
#line 1 "graph/verify/../graph_025_2SAT.cpp"
// クロージャ内にあるリテラルの数が高々 2 であるときの充足可能性問題 (2-SAT)
// 依存ライブラリ: SCC (graph_010_scc.cpp)
struct TwoSAT {
    int N; Graph<> G;
    TwoSAT(int N_) : N(N_), G(2*N_) {}
    int neg(int k) { return (k+N) % (2*N); }
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
    }
    void add_AorB(int a, int b) {
        // (a or b) -> (na => b) and (nb => a)
        add_edge(neg(a), b);
        add_edge(neg(b), a);
    }
    void add_NAorB(int a, int b) {
        // (na or b) -> (a => b) and (nb => na)
        add_edge(a, b);
        add_edge(neg(b), neg(a));
    }
    void add_AorNB(int a, int b) {
        // (a or nb) -> (na => nb) and (b => a)
        add_edge(neg(a), neg(b));
        add_edge(b, a);
    }
    void add_NAorNB(int a, int b) {
        // not (a and b) -> (na or nb)
        // (na or nb) -> (a => nb) and (b => na)
        add_edge(a, neg(b));
        add_edge(b, neg(a));
    }
    void add_AnandB(int a, int b) {
        add_NAorNB(neg(a), neg(b));
    }
    vector<int> build() {
        GraphSCC<> scc(G);
        vector<int> group, res(N); int K;
        tie(group, K) = scc.scc();
        for(int i=0; i<N; i++) {
            if(group[i] == group[N+i]) return {};
            res[i] = (group[i] > group[N+i]);
        }
        return res;
    }
};
#line 11 "graph/verify/verify_graph_025_2SAT.cpp"

void yuki_274() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> L(N), R(N);

    auto flip = [&](int l, int r) {
        return make_pair(M - 1 - r, M - 1 - l);
    };

    auto intersect = [&](int al, int ar, int bl, int br) {
        return !(ar < bl or br < al);
    };
    
    for(int i=0; i<N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                int al = L[i], ar = R[i];
                int bl = L[j], br = R[j];
                if(bit & 1) tie(al, ar) = flip(al, ar);
                if(bit & 2) tie(bl, br) = flip(bl, br);

                if(intersect(al, ar, bl, br)) {
                    switch(bit) {
                    case 0:
                        // A and B はダメ -> NA or NB
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        // NA and B はダメ -> A or NB
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        // A and NB はダメ -> NA or B
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        // NA and NB はダメ -> A or B
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }
    auto res = tsat.build();
    if(res.size() == N) puts("YES");
    else puts("NO");
}

void yuki_470() {
    int N; cin >> N;
    vector<string> U(N);
    for(int i=0; i<N; i++) cin >> U[i];

    if(N > 52) {
        cout << "Impossible" << endl;
        return;
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                string sa, sb, ta, tb;
                if(bit & 1) sa = U[i].substr(0, 1), sb = U[i].substr(1); // NA, NB
                else sa = U[i].substr(0, 2), sb = U[i].substr(2); // A, B
                if(bit & 2) ta = U[j].substr(0, 1), tb = U[j].substr(1);
                else ta = U[j].substr(0, 2), tb = U[j].substr(2);

                if(sa == ta or sb == tb or sa == tb or sb == ta) {
                    switch(bit) {
                    case 0:
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }

    vector<int> res = tsat.build();
    if(res.empty()) cout << "Impossible" << endl;
    else {
        vector<string> pre(N), suf(N);
        for(int i=0; i<N; i++) {
            if(res[i]) pre[i] = U[i].substr(0, 2), suf[i] = U[i].substr(2);
            else pre[i] = U[i].substr(0, 1), suf[i] = U[i].substr(1);
            cout << pre[i] << " " << suf[i] << endl;
        }
    }
}

int main() {
    // yuki_274();
    yuki_470();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

