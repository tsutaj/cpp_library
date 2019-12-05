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


# :warning: ../../structure/strc_011_weighted_unionfind.cpp
* category: ../../structure


[Back to top page](../../index.html)



## Code
```cpp
// 重み付き UnionFind - マージテク (QuickFind) を使用した実装
// merge の計算量はならし O(log N)
// Verified: Never Wait for Weights (AOJ 1330)

struct QuickFind {
    int N;
    vector<int> i2g;
    vector< vector<int> > g2i;
    vector<long long int> weight;
 
    QuickFind(int N_) {
        N = N_;
        i2g.resize(N);
        g2i.resize(N);
        weight.resize(N);
 
        for(int i=0; i<N; i++) {
            i2g[i] = i;
            g2i[i] = vector<int>{i};
        }
    }
 
    bool same(int u, int v) {
        return i2g[u] == i2g[v];
    }
 
    // v の方が w だけ大きい
    void unite(int u, int v, int w) {
        int ru = i2g[u], rv = i2g[v];
        if(ru == rv) return;
 
        // マージする対象を変更する場合は swap する
        if(g2i[rv].size() > g2i[ru].size()) {
            swap(ru, rv);
            swap(u, v);
            w = -w;
        }
 
        long long int prev = weight[v];
        weight[v] = weight[u] + w;
 
        for(auto e : g2i[rv]) {
            i2g[e] = ru;
            long long int diff = weight[e] - prev;
            // v 自身は更新済みなのでスキップ (重要)
            if(e != v) weight[e] = weight[v] + diff;
        }
 
        // rv の中身を全部 ru に移す
        for(auto e : g2i[rv]) {
            g2i[ru].push_back(e);
        }
        g2i[rv].clear();
    }
 
    long long int query(int u, int v) {
        assert(same(u, v));
        return weight[v] - weight[u];
    }
};
```

[Back to top page](../../index.html)
