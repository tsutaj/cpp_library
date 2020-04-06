#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0516"

#include <cstdio>
using namespace std;
#include "../../../algorithm/cumulative_sum.cpp"
using ll = long long int;

int solve() {
    int N, K; scanf("%d%d", &N, &K);
    if(N == 0 and K == 0) return 1;
    
    vector<ll> A(N);
    for(int i=0; i<N; i++) scanf("%lld", &A[i]);

    CumulativeSum<ll> cs(A, 0LL,
                         [](ll a, ll b) { return a + b; },
                         [](ll a, ll b) { return a - b; });

    ll ans = -(1LL << 60);
    for(int i=0; i<N-K+1; i++) {
        ans = max(ans, cs.get_subseq(i, i+K));
    }
    printf("%lld\n", ans);
    return 0;
}

int main() {
    while(!solve());
    return 0;
}
