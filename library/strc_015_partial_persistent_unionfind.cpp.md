<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_015\_partial\_persistent\_unionfind.cpp

## Code

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

[トップページに戻る](../index.html)
