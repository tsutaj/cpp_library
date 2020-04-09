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


# :heavy_check_mark: verifying_test/AOJ/DSL_1_A/union_find.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#0f362725f1b6d2122533c8758cd97614">verifying_test/AOJ/DSL_1_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/DSL_1_A/union_find.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 01:41:38+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/structure/union_find.cpp.html">Union-Find <small>(structure/union_find.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp"

#include <cstdio>
using namespace std;

#define call_from_test
#include "../../../structure/union_find.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    UnionFind uf(N);
    while(Q--) {
        int t; scanf("%d", &t);
        int x, y; scanf("%d%d", &x, &y);
        if(t == 0) {
            uf.unite(x, y);
        }
        if(t == 1) {
            printf("%d\n", uf.same(x, y) ? 1 : 0);
        }
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/AOJ/DSL_1_A/union_find.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp"

#include <cstdio>
using namespace std;

#define call_from_test
#line 2 "structure/union_find.cpp"

/**
 * @brief Union-Find
 * @docs ./docs/union_find.md
 */

#include <algorithm>
#include <vector>

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
#line 8 "verifying_test/AOJ/DSL_1_A/union_find.test.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    UnionFind uf(N);
    while(Q--) {
        int t; scanf("%d", &t);
        int x, y; scanf("%d%d", &x, &y);
        if(t == 0) {
            uf.unite(x, y);
        }
        if(t == 1) {
            printf("%d\n", uf.same(x, y) ? 1 : 0);
        }
    }
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

