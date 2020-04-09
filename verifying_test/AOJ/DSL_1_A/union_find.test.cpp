#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp"

#include <cstdio>
using namespace std;

#define call_from_test
#include "../../../structure/union_find.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    UnionFind uf(N);
    while(Q--) {
        int t; scanf("%d", &t);
        int x, y; scanf("%d%d", &x, &y);
        if(t == 0) {
            uf.unite(x, y);
        }
        if(t == 1) {
            printf("%d\n", uf.same(x, y) ? 1 : 0);
        }
    }
}
