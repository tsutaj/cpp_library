#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"

#include <cstdio>
#include <queue>
#include <cassert>
#include "../../../algorithm/cartesian_tree.cpp"

int main() {
    int N; scanf("%d", &N);

    vector<int> A(N);
    for(auto &e : A) scanf("%d", &e);

    auto [G, root] = getCartesianTree(A);
    vector<bool> visited(N);
    vector<int> ans(N, root);
    queue<int> que;
    que.emplace(root);
    visited[root] = true;
    while(que.size()) {
        int u = que.front(); que.pop();
        for(auto e : G[u]) {
            int v = e.to;
            assert(!visited[v]);
            ans[v] = u;
            visited[v] = true;
            que.emplace(v);
        }
    }

    for(int i=0; i<N; i++) printf("%d%c", ans[i], " \n"[i + 1 == N]);
    return 0;
}