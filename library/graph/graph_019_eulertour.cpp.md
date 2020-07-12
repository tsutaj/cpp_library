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


# :warning: graph/graph_019_eulertour.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_019_eulertour.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Euler-tour (Verified: Codeforces Round #225 Div.1: Propagating Tree)
// 頂点 i を根とした部分木の情報は [ etbegin[i], etend[i] ) を参照
constexpr int MAXN = 200010;
vector<int> G[MAXN];
int k=0, euler_tour[2*MAXN], etbegin[MAXN], etend[MAXN];

// usage: make_et(root)
void make_et(int v, int par=-1) {
    euler_tour[k] = v;
    etbegin[v] = k++;
    for(size_t i=0; i<G[v].size(); i++) {
        int to = G[v][i];
        if(to == par) continue;
        make_et(to, v);
        euler_tour[k++] = v;
    }
    etend[v] = k;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/graph_019_eulertour.cpp"
// Euler-tour (Verified: Codeforces Round #225 Div.1: Propagating Tree)
// 頂点 i を根とした部分木の情報は [ etbegin[i], etend[i] ) を参照
constexpr int MAXN = 200010;
vector<int> G[MAXN];
int k=0, euler_tour[2*MAXN], etbegin[MAXN], etend[MAXN];

// usage: make_et(root)
void make_et(int v, int par=-1) {
    euler_tour[k] = v;
    etbegin[v] = k++;
    for(size_t i=0; i<G[v].size(); i++) {
        int to = G[v][i];
        if(to == par) continue;
        make_et(to, v);
        euler_tour[k++] = v;
    }
    etend[v] = k;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
