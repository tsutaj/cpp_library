#pragma once

/**
 * @brief 接続行列を係数に持つ線形方程式のソルバ
 * @docs docs/graph/linear_system_incidence.md
 */

#include <vector>
#include <utility>
#include <tuple>
#include <cassert>

template <typename Tp>
class LinearSystemIncidence {
public:
    struct Edge {
        int id, to;
        bool is_forward;
        Edge(int id, int to, int is_forward) : id(id), to(to), is_forward(is_forward) {}
    };

    LinearSystemIncidence(int N, const vector< pair<int, int> >& edges) : N(N), M(edges.size()), G(N) {
        for(int i=0; i<M; i++) {
            int u, v; tie(u, v) = edges[i];
            G[u].emplace_back(i, v, true);
            G[v].emplace_back(i, u, false);
        }
    }

    Tp dfs(int u, const vector<Tp> &b) {
        assert(!used[u]);
        used[u] = true;
        Tp res = b[u];
        for(const auto &e : G[u]) {
            if(used[e.to]) continue;
            Tp res_to = dfs(e.to, b);
            if(e.is_forward) x[e.id] = res_to;
            else x[e.id] = -res_to;
            res += res_to;
        }
        return res;
    }

    pair< bool, vector<Tp> > solve(vector<Tp> &b) {
        assert(static_cast<int>(b.size()) == N);
        used.assign(N, false);
        x.assign(M, Tp(0));
        for(int i=0; i<N; i++) {
            if(used[i]) continue;
            Tp v = dfs(i, b);
            if(v != Tp(0)) return make_pair(false, vector<Tp>());
        }
        return {true, move(x)};
    }

private:
    int N, M;
    vector< vector<Edge> > G;
    vector<bool> used;
    vector<Tp> x; // Ax = b
};
