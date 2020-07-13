#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D"
#include <cstdio>
#include <algorithm>
using namespace std;

#define call_from_test
#include "../../../structure/strc_007_sparsetable.cpp"
#undef call_from_test

int main() {
    int N, L; scanf("%d%d", &N, &L);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    SparseTable<int> sp(A, [](int x, int y) { return min(x, y); });
    for(int i=0; i<N-L+1; i++) {
        printf("%d%c", sp.query(i, i+L), " \n"[i == N-L]);
    }
    return 0;
}
