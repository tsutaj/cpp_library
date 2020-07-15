#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"

#include <vector>
#include <cstdio>
using namespace std;
using ll = long long int;

#define call_from_test
#include "../../../structure/disjoint_sparse_table.cpp"
#undef call_from_test

int main() {
    int N, L; scanf("%d%d", &N, &L);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    DisjointSparseTable<int> dst(A, [](int x, int y) { return min(x, y); });
    for(int i=0; i<N-L+1; i++) {        
        printf("%d%c", dst.query(i, i+L), " \n"[i == N - L]);
    }
    return 0;
}
