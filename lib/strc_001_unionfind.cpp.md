[トップページに戻る](../index.html)

# strc\_001\_unionfind.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

```cpp
// Union-Find 木 (Verified: AtCoder Typical Contest 001 B)
struct UnionFind {
private:
    const int n;
    int size_;
    vector<int> uf;
public:
    // 初期化 UnionFind uni(n) のように宣言すれば良い
    UnionFind(int _n) : n(_n), size_(_n), uf(_n, -1) {}
    // find (木の根を求める)
    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}
    // x と y が同じ集合に属するかどうか
    bool same(int x, int y) {return find(x) == find(y);}
    // x が属する集合の要素数
    int size(int x) {return -uf[find(x)];}
    // 集合はいくつあるか
    int size()      {return size_;}
    // x と y の属する集合を併合
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if(x == y) return false;
        size_--;
        if(-uf[x] < -uf[y]) swap(x, y);
        uf[x] += uf[y]; uf[y] = x;
        return true;
    }
};
```

[トップページに戻る](../index.html)
