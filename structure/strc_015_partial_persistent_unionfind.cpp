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