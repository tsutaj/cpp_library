<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
  jax: ["input/TeX", "output/HTML-CSS"],
  tex2jax: {
    inlineMath: [ ['$', '$'] ],
    displayMath: [ ['$$', '$$']],
    processEscapes: true,
    skipTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']
  },
  messageStyle: "none",
  "HTML-CSS": { preferredFont: "TeX", availableFonts: ["STIX","TeX"] }
});
</script>
<script src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML" type="text/javascript"></script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_008\_treeheight.cpp

## Code

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

[トップページに戻る](../index.html)
