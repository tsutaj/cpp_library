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
};