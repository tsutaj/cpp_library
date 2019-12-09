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


# :warning: structure/strc_015_partial_persistent_unionfind.cpp
* category: structure


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
// 部分永続 UnionFind
// バージョンを指定して関数を動かすことで、その時点での連結情報が得られる

struct PartialPersistentUnionFind {
    vector<int> node, last;
    vector< vector< pair<int, int> > > history;
    PartialPersistentUnionFind(int size_) : node(size_, -1), last(size_, 1e9), history(size_) {
        for(auto &vec : history) vec.emplace_back(-1, -1);
    }
    bool unite(int t, int x, int y) {
        x = find(t, x);
        y = find(t, y);
        if(x == y) return false;
        if(node[x] > node[y]) swap(x, y);
        node[x] += node[y];
        history[x].emplace_back(t, node[x]);
        node[y] = x; last[y] = t;
        return true;
    }
    bool same(int t, int x, int y) {
        return find(t, x) == find(t, y);
    }
    int find(int t, int x) {
        if(t < last[x]) return x;
        return find(t, node[x]);
    }
    int size(int t, int x) {
        x = find(t, x);
        return -prev(lower_bound(history[x].begin(), history[x].end(), make_pair(t, (int)0)))->second;
    }
};
```
{% endraw %}

[Back to top page](../../index.html)

