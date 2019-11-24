<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: graph\_000\_basic.cpp
---

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

[トップページに戻る](../index.html)
