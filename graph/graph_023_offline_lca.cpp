// Tarjan's off-line LCA algorithm
// 依存ライブラリ
// ・グラフ辺構造体 (graph_000_basic.cpp)

struct OfflineLCA {
    Graph<> G;
    vector<int> node, anc, color, answers;
    vector< vector< pair<int, int> > > queries;
    int find(int k) { return node[k] < 0 ? k : find(node[k]); }
    int size(int k) { return -node[find(k)]; }
    void unite(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return;
        if(size(u) < size(v)) swap(u, v);
        node[u] += node[v];
        node[v] = u;
    }

    void build(int cur, int par=-1) {
        anc[cur] = cur;
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            build(e.to, cur);
            unite(e.to, cur);
            anc[find(cur)] = cur;
        }
        color[cur] = 1;
        for(auto q : queries[cur]) {
            int to, idx; tie(to, idx) = q;
            if(color[to] == 1) {
                int lca = anc[find(to)];
                answers[idx] = lca;
            }
        }
    }
    
    OfflineLCA(Graph<> G, vector< pair<int, int> > Q, int root=0) : G(G) {
        size_t N = G.size(), M = Q.size();
        node = anc = color = vector<int>(N);
        fill(node.begin(), node.end(), -1);

        queries.resize(N); answers.resize(M);
        for(size_t i=0; i<M; i++) {
            int u, v; tie(u, v) = Q[i];
            queries[u].emplace_back(v, i);
            queries[v].emplace_back(u, i);
        }
        build(root);
    }

    int& operator[] (int k) { return answers[k]; }
};
