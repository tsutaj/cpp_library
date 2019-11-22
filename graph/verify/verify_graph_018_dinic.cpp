#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
#include "../graph_018_dinic.cpp"

void GRL_6_A() {
    int V, E; scanf("%d%d", &V, &E);
    Dinic<> fl(V);
    for(int i=0; i<E; i++) {
        int u, v, c; scanf("%d%d%d", &u, &v, &c);
        fl.add_edge(u, v, c);
    }
    int source = 0, sink = V - 1;
    printf("%d\n", fl.max_flow(source, sink));
}

// 復元の Verify
void AOJ2304() {
    int N, M; scanf("%d%d", &N, &M);
    Dinic<> fl(N);
    for(int i=0; i<M; i++) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        fl.add_edge(u, v, 1);
        fl.add_edge(v, u, 1); // 逆向きの辺 (これに流れるかどうか？)
    }
    int source, sink; scanf("%d%d", &source, &sink);
    source--; sink--;
    
    int flow = fl.max_flow(source, sink);
    printf("%d\n", flow);
    vector<int> ans;
    for(int i=0; i<M; i++) {
        int k = 2*i + 1;
        if(fl.get_flowed_cap(k) == 1) ans.emplace_back(i + 1);
    }
    printf("%zu\n", ans.size());
    for(auto k : ans) printf("%d\n", k);
}

int main() {
    // GRL_6_A();
    AOJ2304();
    return 0;
}
