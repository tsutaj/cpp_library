[トップページに戻る](../index.html)

# strc\_016\_persistent\_unionfind.cpp
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
// 完全永続 UnionFind
// PersistentArray がないと動きません

struct PersistentUnionFind {
    PersistentArray<int, 3> data;
    PersistentUnionFind() {}
    PersistentUnionFind(int size_) {
        data.build(vector<int>(size_, -1));
    }

    int find(int k) {
        int p = data.get(k);
        return p >= 0 ? find(p) : k;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int k) {
        return (-data.get(find(k)));
    }
    
    PersistentUnionFind unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return *this;
        auto u = data.get(x);
        auto v = data.get(y);
        if(u > v) swap(u, v), swap(x, y);

        auto a = data.mutable_get(x);
        *a += v;
        auto b = data.mutable_get(y);
        *b = x;
        return *this;
    }
};```

[トップページに戻る](../index.html)
