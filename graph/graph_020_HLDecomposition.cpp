// HL 分解 (Heavy-Light Decomposition)
// 頂点 v を根とする部分木: [ in[v], out[v] )
// 頂点 v から見た heavy edge chain の頭: head[v]
struct HLD {
    vector< vector<int> > G;
    vector<int> sub, par, depth, in, out, rev, head;
    
    void dfs_sub(int cur) {
        for(auto& to : G[cur]) {
            if(par[cur] == to) continue;
            par[to] = cur;
            depth[to] = depth[cur] + 1;
            dfs_sub(to);
            sub[cur] += sub[to];
            if(sub[to] > sub[ G[cur][0] ]) swap(to, G[cur][0]);
        }
    }
    void dfs_hld(int cur, int& ptr) {
        in[cur] = ptr; rev[ptr++] = cur;
        for(auto to : G[cur]) {
            if(par[cur] == to) continue;
            head[to] = (to == G[cur][0] ? head[cur] : to);
            dfs_hld(to, ptr);
        }
        out[cur] = ptr;
    }

    HLD(int N) : G(N), sub(N, 1), par(N, -1), depth(N),
                 in(N), out(N), rev(N), head(N) {}
    void add_edge(int u, int v) {
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int root=0) {
        int ptr = 0; dfs_sub(root); dfs_hld(root, ptr);
    }
    int lca(int u, int v) {
        while(1) {
            if(in[u] > in[v]) swap(u, v);
            if(head[u] == head[v]) return u;
            v = par[ head[v] ];
        }
    }
    int distance(int u, int v) {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

    template <typename F>
    void proceed(int u, int v, const F& f, bool b) {
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v);
            f(in[ head[v] ], in[v] + 1);
        }
        if(in[u] > in[v]) swap(u, v);
        f(in[u] + b, in[v] + 1);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に f(l, r) を作用
    // l, r は SegmentTree とかのデータ構造上のインデックス
    template <typename F>
    void apply_vertices(int u, int v, const F& f) {
        proceed(u, v, f, false);
    }

    template <typename F>
    void apply_edges(int u, int v, const F& f) {
        proceed(u, v, f, true);
    }

    template <typename T, typename F, typename M>
    T proceed(int u, int v, T E, const F& f, const M& m, bool b) {
        T vl(E), vr(E);
        for(; head[u] != head[v]; v = par[ head[v] ]) {
            if(in[u] > in[v]) swap(u, v), swap(vl, vr);
            vr = m(f(in[ head[v] ], in[v] + 1), vr);
        }
        if(in[u] > in[v]) swap(u, v), swap(vl, vr);
        vr = m(f(in[u] + b, in[v] + 1), vr);
        return m(vl, vr);
    }

    // u - v パス上に存在する「頂点」or「辺」全体に割り当てられた値を
    // 各 chunk に対して f(l, r) で得て、それらを m(vl, vr) で merge したものを得る
    // 単位元 E も渡そう
    template <typename T, typename F, typename M>
    T query_vertices(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, false);
    }

    template <typename T, typename F, typename M>
    T query_edges(int u, int v, T E, const F& f, const M& m) {
        return proceed(u, v, E, f, m, true);
    }
};
