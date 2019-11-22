// Boruvka's algorithm (最小全域木を求める)
// その時点で存在するそれぞれの木について、それに接続している辺で重み最小のものを探す関数が必要
// 依存ライブラリ: UnionFind

template <typename T, typename F>
T boruvka(int N, F f) {
    UnionFind uf(N);
    vector<int> group(N), rev(N);
    T ans(0);

    while(uf.size() > 1) {
        // 各頂点が何番目の連結成分に属するか？
        // ある連結成分について代表元はなにか？
        int ptr = 0;
        for(int i=0; i<N; i++) {
            if(uf.find(i) == i) {
                group[i] = ptr++;
                rev[ group[i] ] = i;
            }
        }
        for(int i=0; i<N; i++) group[i] = group[ uf.find(i) ];

        // 異なる連結成分同士を結んでいる辺の候補をもってくる
        // 各連結成分に対して (最小コスト・繋げる先 (ないなら -1))
        auto edges = f(ptr, group);

        bool changed = false;
        for(int u=0; u<ptr; u++) {
            T cost; int v; tie(cost, v) = edges[u];
            if(v >= 0 and uf.unite(rev[u], rev[v])) {
                ans += cost;
                changed = true;
            }
        }

        if(!changed) return false;
    }

    return ans;
}
