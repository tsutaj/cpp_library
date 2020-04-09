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


# :heavy_check_mark: Union-Find <small>(structure/union_find.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-10 01:41:38+09:00




経路圧縮とサイズ比較をどちらも行っているため、クエリあたりの計算量は $O(\alpha(N))$ になっているはず。

- `find(x)`: $x$ が属する集合の代表元を返す
- `same(x, y)`: $x$ と $y$ が同じ集合に属するかどうかの bool 値を返す
- `size(x)`: $x$ が属する集合の濃度 (要素数) を返す
- `size()`: 素集合がいくつ存在するかを返す
- `unite(x, y)`: $x$ と $y$ が同じ集合に属するなら `false` を返す。そうでなければ `true` を返すとともに、$x$ が属する集合と $y$ が属する集合を併合する


## Verified with

* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/DSL_1_A/union_find.test.cpp.html">verifying_test/AOJ/DSL_1_A/union_find.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verifying_test/yosupo/data_structure/unionfind/union_find.test.cpp.html">verifying_test/yosupo/data_structure/unionfind/union_find.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

