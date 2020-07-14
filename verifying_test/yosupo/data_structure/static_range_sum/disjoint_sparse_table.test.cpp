#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <vector>
#include <cstdio>
using namespace std;
using ll = long long int;

#define call_from_test
#include "../../../../structure/disjoint_sparse_table.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    DisjointSparseTable<ll> dst(A, [](ll x, ll y) { return x + y; });
    while(Q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%lld\n", dst.query(l, r));
    }
    return 0;
}
