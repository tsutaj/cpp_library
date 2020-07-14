#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <cstdio>
using namespace std;

#define call_from_test
#include "../../../../structure/disjoint_sparse_table.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    DisjointSparseTable<int> dst(A, [](int x, int y) { return min(x, y); });
    while(Q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%d\n", dst.query(l, r));
    }
    return 0;
}
