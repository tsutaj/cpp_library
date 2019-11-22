#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <tuple>
#include <utility>
#include <cassert>
#include <bitset>
#include <map>
#include <climits>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_022_max_independent_set.cpp"

void CODE_THANKS_FESTIVAL_2017_G() {
    int N, M; scanf("%d%d", &N, &M);
    Graph<int> G(N);
    for(int i=0; i<M; i++) {
        int u, v;
        scanf("%d%d", &u, &v); u--; v--;
        G[u].emplace_back(v, 1);
        G[v].emplace_back(u, 1);
    }

    MaximalIndependentSet<> miset(G);
    printf("%d\n", miset.solve());
}

void AOJ2403() {
    auto solve_testcase = [&]() {
        int N; cin >> N;
        if(N == 0) return 1;

        map<string, int> comp;
        vector<string> A(N); vector< vector<string> > D(N);
        vector<int> B(N);

        for(int i=0; i<N; i++) {
            int k; cin >> A[i] >> B[i] >> k;
            comp[ A[i] ]++;
            for(int j=0; j<k; j++) {
                string s; cin >> s;
                D[i].emplace_back(s);
                comp[s]++;
            }
        }

        int id = 0;
        for(auto &e : comp) e.second = id++;

        vector<int> costs(N), used(N);

        // 自分の国の隣は選べないため
        for(auto s : D[0]) {
            int v = comp[s];
            used[v] = true;
        }
        
        Graph<int> G(N);
        for(int i=0; i<N; i++) {
            int u = comp[ A[i] ];
            if(used[u]) continue;
            costs[u] = B[i];

            // 対称らしいので片方だけでいい
            // 自分の国の隣は選べないので辺を張らない
            for(auto s : D[i]) {
                int v = comp[s];
                if(!used[v]) G[u].emplace_back(v, 1);
            }
        }

        MaximalIndependentSet<> miset(G, costs);
        cout << miset.solve() << endl;
        return 0;
    };

    while(!solve_testcase());
}

int main() {
    CODE_THANKS_FESTIVAL_2017_G();
    // AOJ2403();
    return 0;
}
