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


# :warning: graph/verify/verify_graph_024_boruvka.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#18777f84943a96e2bda3d93e0ed91d5c">graph/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/verify/verify_graph_024_boruvka.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../graph_024_boruvka.cpp.html">graph/graph_024_boruvka.cpp</a>
* :warning: <a href="../../structure/strc_001_unionfind.cpp.html">structure/strc_001_unionfind.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <tuple>
using namespace std;
#include "../../structure/strc_001_unionfind.cpp"
#include "../graph_024_boruvka.cpp"

void GRL_2_A() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> s(M), t(M), w(M);
    for(int i=0; i<M; i++) {
        scanf("%d%d%d", &s[i], &t[i], &w[i]);
    }

    const int INF = 1 << 30;
    auto f = [&](int sz, vector<int> group) {
        vector< pair<int, int> > res(sz, {INF, -1});
        for(int i=0; i<M; i++) {
            int gs = group[ s[i] ], gt = group[ t[i] ];
            if(gs == gt) continue;
            res[gs] = min(res[gs], {w[i], gt});
            res[gt] = min(res[gt], {w[i], gs});
        }
        return res;
    };

    cout << boruvka< int, decltype(f) >(N, f) << endl;
}

void KEYENCE_2019_E() {
    using int64 = long long int;
    int64 N, D; cin >> N >> D;
    vector<int64> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    using Candidate = tuple< pair<int64, int64>, pair<int64, int64> >;
    auto g = [&](Candidate cand, pair<int64, int64> p) {
        pair<int64, int64> c1, c2; tie(c1, c2) = cand;
        if(c1.first < p.first and c2.first < p.first) return cand;
        if(c1.first < p.first) {
            if(c1.second == p.second) return cand;
            return make_tuple(c1, p);
        }
        if(c1.second != p.second) return make_tuple(p, c1);
        return make_tuple(p, c2);
    };

    const int64 INF = 1LL << 60;
    pair<int64, int64> I(INF, -1);
    auto f = [&](int sz, vector<int> group) {
        vector< pair<int64, int64> > res(sz, I);

        {
            Candidate cand(I, I);
            for(int i=0; i<N; i++) {
                pair<int64, int64> c1, c2; tie(c1, c2) = cand;
                pair<int64, int64> p = (c1.second != group[i] ? c1 : c2);
                int64 v = p.first + A[i] + i * D;
                if(res[ group[i] ].first > v) {
                    res[ group[i] ] = make_pair(v, p.second);
                }

                cand = g(cand, make_pair(A[i] - i * D, group[i]));
            }
        }

        {
            Candidate cand(I, I);
            for(int i=N-1; i>=0; i--) {
                pair<int64, int64> c1, c2; tie(c1, c2) = cand;
                pair<int64, int64> p = (c1.second != group[i] ? c1 : c2);
                int64 v = p.first + A[i] + (N - 1 - i) * D;
                if(res[ group[i] ].first > v) {
                    res[ group[i] ] = make_pair(v, p.second);
                }

                cand = g(cand, make_pair(A[i] - (N - 1 - i) * D, group[i]));
            }
        }

        return res;
    };

    cout << boruvka< int64, decltype(f) >(N, f) << endl;
}

int main() {
    // GRL_2_A();
    KEYENCE_2019_E();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/verify/verify_graph_024_boruvka.cpp"
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <tuple>
using namespace std;
#line 1 "graph/verify/../../structure/strc_001_unionfind.cpp"
// Union-Find 木 (Verified: AtCoder Typical Contest 001 B)
struct UnionFind {
private:
    const int n;
    int size_;
    vector<int> uf;
public:
    // 初期化 UnionFind uni(n) のように宣言すれば良い
    UnionFind(int _n) : n(_n), size_(_n), uf(_n, -1) {}
    // find (木の根を求める)
    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}
    // x と y が同じ集合に属するかどうか
    bool same(int x, int y) {return find(x) == find(y);}
    // x が属する集合の要素数
    int size(int x) {return -uf[find(x)];}
    // 集合はいくつあるか
    int size()      {return size_;}
    // x と y の属する集合を併合
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        size_--;
        if(-uf[x] < -uf[y]) swap(x, y);
        uf[x] += uf[y]; uf[y] = x;
        return true;
    }
};
#line 1 "graph/verify/../graph_024_boruvka.cpp"
// Boruvka's algorithm (最小全域木を求める)
// その時点で存在するそれぞれの木について、それに接続している辺で重み最小のものを探す関数が必要
// 依存ライブラリ: UnionFind

template <typename T, typename F>
T boruvka(int N, F f) {
    UnionFind uf(N);
    vector<int> group(N), rev(N);
    T ans(0);

    while(uf.size() > 1) {
        // 各頂点が何番目の連結成分に属するか？
        // ある連結成分について代表元はなにか？
        int ptr = 0;
        for(int i=0; i<N; i++) {
            if(uf.find(i) == i) {
                group[i] = ptr++;
                rev[ group[i] ] = i;
            }
        }
        for(int i=0; i<N; i++) group[i] = group[ uf.find(i) ];

        // 異なる連結成分同士を結んでいる辺の候補をもってくる
        // 各連結成分に対して (最小コスト・繋げる先 (ないなら -1))
        auto edges = f(ptr, group);

        bool changed = false;
        for(int u=0; u<ptr; u++) {
            T cost; int v; tie(cost, v) = edges[u];
            if(v >= 0 and uf.unite(rev[u], rev[v])) {
                ans += cost;
                changed = true;
            }
        }

        if(!changed) return false;
    }

    return ans;
}
#line 9 "graph/verify/verify_graph_024_boruvka.cpp"

void GRL_2_A() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> s(M), t(M), w(M);
    for(int i=0; i<M; i++) {
        scanf("%d%d%d", &s[i], &t[i], &w[i]);
    }

    const int INF = 1 << 30;
    auto f = [&](int sz, vector<int> group) {
        vector< pair<int, int> > res(sz, {INF, -1});
        for(int i=0; i<M; i++) {
            int gs = group[ s[i] ], gt = group[ t[i] ];
            if(gs == gt) continue;
            res[gs] = min(res[gs], {w[i], gt});
            res[gt] = min(res[gt], {w[i], gs});
        }
        return res;
    };

    cout << boruvka< int, decltype(f) >(N, f) << endl;
}

void KEYENCE_2019_E() {
    using int64 = long long int;
    int64 N, D; cin >> N >> D;
    vector<int64> A(N);
    for(int i=0; i<N; i++) cin >> A[i];

    using Candidate = tuple< pair<int64, int64>, pair<int64, int64> >;
    auto g = [&](Candidate cand, pair<int64, int64> p) {
        pair<int64, int64> c1, c2; tie(c1, c2) = cand;
        if(c1.first < p.first and c2.first < p.first) return cand;
        if(c1.first < p.first) {
            if(c1.second == p.second) return cand;
            return make_tuple(c1, p);
        }
        if(c1.second != p.second) return make_tuple(p, c1);
        return make_tuple(p, c2);
    };

    const int64 INF = 1LL << 60;
    pair<int64, int64> I(INF, -1);
    auto f = [&](int sz, vector<int> group) {
        vector< pair<int64, int64> > res(sz, I);

        {
            Candidate cand(I, I);
            for(int i=0; i<N; i++) {
                pair<int64, int64> c1, c2; tie(c1, c2) = cand;
                pair<int64, int64> p = (c1.second != group[i] ? c1 : c2);
                int64 v = p.first + A[i] + i * D;
                if(res[ group[i] ].first > v) {
                    res[ group[i] ] = make_pair(v, p.second);
                }

                cand = g(cand, make_pair(A[i] - i * D, group[i]));
            }
        }

        {
            Candidate cand(I, I);
            for(int i=N-1; i>=0; i--) {
                pair<int64, int64> c1, c2; tie(c1, c2) = cand;
                pair<int64, int64> p = (c1.second != group[i] ? c1 : c2);
                int64 v = p.first + A[i] + (N - 1 - i) * D;
                if(res[ group[i] ].first > v) {
                    res[ group[i] ] = make_pair(v, p.second);
                }

                cand = g(cand, make_pair(A[i] - (N - 1 - i) * D, group[i]));
            }
        }

        return res;
    };

    cout << boruvka< int64, decltype(f) >(N, f) << endl;
}

int main() {
    // GRL_2_A();
    KEYENCE_2019_E();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

