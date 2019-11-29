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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../structure/strc_016_persistent_unionfind.cpp
* category: ../../structure


[Back to top page](../../index.html)



## Code
```cpp
// 完全永続 UnionFind
// PersistentArray がないと動きません

struct PersistentUnionFind {
    PersistentArray<int, 3> data;
    PersistentUnionFind() {}
    PersistentUnionFind(int size_) {
        data.build(vector<int>(size_, -1));
    }

    int find(int k) {
        int p = data.get(k);
        return p >= 0 ? find(p) : k;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int k) {
        return (-data.get(find(k)));
    }
    
    PersistentUnionFind unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return *this;
        auto u = data.get(x);
        auto v = data.get(y);
        if(u > v) swap(u, v), swap(x, y);

        auto a = data.mutable_get(x);
        *a += v;
        auto b = data.mutable_get(y);
        *b = x;
        return *this;
    }
};
```

[Back to top page](../../index.html)

