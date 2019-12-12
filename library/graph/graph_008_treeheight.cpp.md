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


# :warning: graph/graph_008_treeheight.cpp
<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_008_treeheight.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// 木の高さを求めるアルゴリズム O(E log |V|)
// ある頂点に対して最遠の頂点は、木の直径となる両頂点のうち、
// ある頂点からの距離が大きい方となる

// → 木の直径となるパスは必ず木の中心を通るので、中心を根とする根付き木を考えた時に、
// 木の高さは、「中心まで登り、ある頂点が属していない方の部分木を下る」か
// 「ある頂点が属しているの方の部分木を下る」ほうのどちらかとなる。

// → したがって、ダイクストラを3回回せば木の高さが求められる。

template <typename T>
vector<T> treeHeight(vector< vector< Edge<T> > > &G) {
    int n = G.size();
    vector<T> v1, v2, v3, ret(n);
    int p1, p2;
    v1 = dijkstra<T>(G, 0);
    p1 = max_element(v1.begin(), v1.end()) - v1.begin();

    v2 = dijkstra<T>(G, p1);
    p2 = max_element(v2.begin(), v2.end()) - v2.begin();

    v3 = dijkstra<T>(G, p2);
    for(int i=0; i<n; i++) ret[i] = max(v2[i], v3[i]);
    return ret;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

