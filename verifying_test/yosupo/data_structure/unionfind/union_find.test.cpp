#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include <cstdio>
using namespace std;

#define call_from_test
#include "../../../../structure/union_find.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    UnionFind uf(N);
    while(Q--) {
        int t, u, v; scanf("%d%d%d", &t, &u, &v);
        if(t == 0) uf.unite(u, v);
        else printf("%d\n", uf.same(u, v) ? 1 : 0);
    }
    return 0;
}
