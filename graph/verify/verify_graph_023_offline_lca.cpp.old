#include <vector>
#include <tuple>
#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_023_offline_lca.cpp"

void GRL_5_C() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N; i++) {
        int c; cin >> c;
        for(int j=0; j<c; j++) {
            int u = i, v; cin >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
    }

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        queries[i] = make_pair(u, v);
    }
    
    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) cout << lca[i] << endl;
}

void ABC014_D() {
    int N; cin >> N;
    Graph<> G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> depth(N);
    function<void(int, int)> go = [&](int cur, int par) {
        for(auto e : G[cur]) {
            if(e.to == par) continue;
            depth[e.to] = depth[cur] + 1;
            go(e.to, cur);
        }
    };
    go(0, -1);

    int Q; cin >> Q;
    vector< pair<int, int> > queries(Q);
    for(int i=0; i<Q; i++) {
        int u, v; cin >> u >> v;
        u--; v--;
        queries[i] = make_pair(u, v);
    }

    OfflineLCA lca(G, queries);
    for(int i=0; i<Q; i++) {
        int u, v; tie(u, v) = queries[i];
        int du = depth[u], dv = depth[v], dl = depth[ lca[i] ];
        cout << du + dv - 2 * dl + 1 << endl;
    }
}

int main() {
    // GRL_5_C();
    ABC014_D();
    return 0;
}
