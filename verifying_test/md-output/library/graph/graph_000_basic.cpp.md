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


# :warning: ../../graph/graph_000_basic.cpp
* category: ../../graph


[Back to top page](../../index.html)



## Required
* :warning: [../../graph/verify/verify_graph_022_max_independent_set.cpp](verify/verify_graph_022_max_independent_set.cpp.html)
* :warning: [../../graph/verify/verify_graph_023_offline_lca.cpp](verify/verify_graph_023_offline_lca.cpp.html)
* :warning: [../../graph/verify/verify_graph_025_2SAT.cpp](verify/verify_graph_025_2SAT.cpp.html)


## Code
```cpp
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

```

[Back to top page](../../index.html)

