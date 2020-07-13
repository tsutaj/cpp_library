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
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#89efefd1f922c5c91b78ccaab1b53a96">verifying_test/AOJ/DSL_3_D</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-13 09:25:35+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/structure/strc_007_sparsetable.cpp.html">Sparse Table <small>(structure/strc_007_sparsetable.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"
#include <cstdio>
#include <algorithm>
using namespace std;

#define call_from_test
#include "../../../structure/strc_007_sparsetable.cpp"
#undef call_from_test

int main() {
    int N, L; scanf("%d%d", &N, &L);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    SparseTable<int> sp(A, [](int x, int y) { return min(x, y); });
    for(int i=0; i<N-L+1; i++) {
        printf("%d%c", sp.query(i, i+L), " \n"[i == N-L]);
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"
#include <cstdio>
#include <algorithm>
using namespace std;

#define call_from_test
#line 2 "structure/strc_007_sparsetable.cpp"

// @brief Sparse Table
// @docs ./docs/sparse_table.md

#include <vector>
#include <functional>
#include <cassert>

template <typename Tp>
struct SparseTable {
    size_t N, LN;
    vector<Tp> A, logs;
    vector< vector<Tp> > node;
    function<Tp(Tp, Tp)> f;

    SparseTable() = default;
    SparseTable(vector<Tp> A_, function<Tp(Tp, Tp)> f_) :
        A(A_), f(f_) {
        N = LN = 1;
        while(N < A.size()) N <<= 1, LN++;
        N = A.size();
        logs.resize(N+1);
        node.resize(N, vector<int>(LN));
        build();
    }

    void build() {
        for(size_t i=2; i<N; i++) {
            logs[i] = logs[i>>1] + 1;
        }
        for(size_t i=0; i<N; i++) {
            node[i][0] = A[i];
        }
        for(size_t k=0; k+1<LN; k++) {
            for(size_t i=0; i+(1<<k)<N; i++) {
                Tp x = node[i][k];
                Tp y = node[i+(1<<k)][k];
                node[i][k+1] = f(x, y);
            }
        }
    }

    inline Tp query(size_t l, size_t r) {
        assert(l < r and r <= N);
        int d = logs[r-l];
        Tp x = node[l][d];
        Tp y = node[r-(1<<d)][d];
        return f(x, y);
    }
};
#line 8 "verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp"
#undef call_from_test

int main() {
    int N, L; scanf("%d%d", &N, &L);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    SparseTable<int> sp(A, [](int x, int y) { return min(x, y); });
    for(int i=0; i<N-L+1; i++) {
        printf("%d%c", sp.query(i, i+L), " \n"[i == N-L]);
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

