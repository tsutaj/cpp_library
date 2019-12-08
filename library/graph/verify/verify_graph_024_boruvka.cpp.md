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
* category: graph/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [graph/graph_024_boruvka.cpp](../graph_024_boruvka.cpp.html)
* :warning: [structure/strc_001_unionfind.cpp](../../structure/strc_001_unionfind.cpp.html)


## Code
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

[Back to top page](../../../index.html)

