#define PROBLEM "https://atcoder.jp/contests/dwango2016-prelims/tasks/dwango2016qual_e"

#include <cstdio>
#include <cassert>
#include <vector>
#include "../../../structure/slope_trick.cpp"
using ll = long long int;

int main() {
  SlopeTrick<ll> slope;
  int N, L; scanf("%d%d", &N, &L);
  std::vector<std::vector<int>> ps(100010);
  for(int i=0; i<N; i++) {
    int t, p; scanf("%d%d", &t, &p); t--;
    ps[t].emplace_back(p);
  }
  for(int i=0; i<100010; i++) {
    slope.accumulateLeft();
    for(auto x : ps[i]) {
      slope.addAbsFunc(x);
    }
  }
  printf("%lld\n", slope.getMinVal());
  return 0;
}
