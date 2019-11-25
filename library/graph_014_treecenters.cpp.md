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

# :warning: graph\_014\_treecenters.cpp

## Code

```cpp
// 木の中心を求めるアルゴリズム O(|V|)
// ・まずは、木の最遠点対と、この 2 点から任意の点との距離をそれぞれ求める
// ・木の中心とは、頂点 u から任意の頂点 x までの最短距離の最大値を最小化する頂点 u である
//   -> これは、木の直径の真ん中の点に当たるので、該当する点を vector に追加する
// ・木の中心は高々 2 個である

template <typename T>
void dfs(int p, vector< vector< Edge<T> > > &G, vector<T> &dist) {
    if(dist[p] == -1) dist[p] = 0;
    T cur = dist[p];
    for(size_t i=0; i<G[p].size(); i++) {
        int to = G[p][i].to;
        if(dist[to] != -1) continue;
        dist[to] = cur + G[p][i].cost;
        dfs(to, G, dist);
    }
}

template <typename T>
vector<int> getCenters(vector< vector< Edge<T> > > &G) {
    int n = (int)G.size();
    vector<T> d0(n, -1), d1(n, -1), d2(n, -1);
    dfs(0, G, d0);
    int p1 = max_element(d0.begin(), d0.end()) - d0.begin();
    dfs(p1, G, d1);
    int p2 = max_element(d1.begin(), d1.end()) - d1.begin();
    dfs(p2, G, d2);

    vector<int> ret;
    T diameter = d2[p1];
    for(int i=0; i<n; i++) {
        bool b1 = (d1[i] + d2[i] == diameter);
        bool b2 = (d1[i] == diameter / 2 || d2[i] == diameter / 2);
        if(b1 && b2) ret.push_back(i);
    }
    return ret;
}

```

[トップページに戻る](../index.html)
