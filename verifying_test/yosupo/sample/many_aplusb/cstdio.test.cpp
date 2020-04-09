#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include <cstdio>

void solve() {
    long long int A, B; scanf("%lld%lld", &A, &B);
    printf("%lld\n", A + B);
}

int main() {
    int T; scanf("%d", &T);
    while(T--) solve();
    return 0;
}
