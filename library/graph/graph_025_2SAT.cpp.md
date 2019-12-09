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


# :warning: graph/graph_025_2SAT.cpp
* category: graph


[Back to top page](../../index.html)



## Required
* :warning: [graph/verify/verify_graph_025_2SAT.cpp](verify/verify_graph_025_2SAT.cpp.html)


## Code
{% raw %}
```cpp
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

```
{% endraw %}

[Back to top page](../../index.html)

