#define PROBLEM "https://atcoder.jp/contests/abc127/tasks/abc127_f"

#include <cstdio>
#include <cassert>
#include "../../../structure/slope_trick.cpp"
using ll = long long int;

int main() {
  int Q; scanf("%d", &Q);

  SlopeTrick<ll> slope;
  while(Q--) {
    int type; scanf("%d", &type);
    if(type == 1) {
      ll a, b; scanf("%lld%lld", &a, &b);
      slope.addAbsFunc(a);
      slope.addConstFunc(b);
    }
    if(type == 2) {
      ll minF = slope.getMinVal();
      ll lb, ub; bool isLbInfty, isUbInfty;
      slope.getArgminInterval(lb, isLbInfty, ub, isUbInfty);
      assert(!isLbInfty);
      printf("%lld %lld\n", lb, minF);
    }
  }
  return 0;
}
