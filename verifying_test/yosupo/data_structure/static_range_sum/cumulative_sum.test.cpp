#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>
using ll = long long int;
using namespace std;

#define call_from_test
#include "../../../../algorithm/cumulative_sum.cpp"
#undef call_from_test

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    vector<ll> A(N);
    for(auto &e : A) scanf("%lld", &e);

    CumulativeSum<ll> cumsum(A, 0,
                             [](ll a, ll b) { return a + b; },
                             [](ll a, ll b) { return a - b; });
    while(Q--) {
        int l, r; scanf("%d%d", &l, &r);
        printf("%lld\n", cumsum.get_subseq(l, r));
    }
    return 0;
}
