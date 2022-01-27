#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/arc070/tasks/arc070_c"

#include <cstdio>
#include <cassert>
#include <vector>
#include "../../../structure/slope_trick.cpp"
using ll = long long int;

int main() {
  SlopeTrick<ll> slope;
  int N; scanf("%d", &N);
  std::vector<ll> L(N), R(N);
  for(int i=0; i<N; i++) {
    scanf("%lld%lld", &L[i], &R[i]);
    if(i == 0) {
      slope.addAbsFunc(L[i]);
    }
    else {
      // dp[i][x] = min_{x - (R[i-1] - L[i-1]) <= j <= x + (R[i] - L[i])} dp[i-1][j]
      slope.applySlidingWindow(L[i] - R[i], R[i-1] - L[i-1]);
      slope.addAbsFunc(L[i]);
    }
  }
  printf("%lld\n", slope.getMinVal());
  return 0;
}