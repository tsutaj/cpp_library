#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc217/tasks/abc217_h"

#include <cstdio>
#include <cassert>
#include <vector>
#include "../../../structure/slope_trick.cpp"
using ll = long long int;

int main() {
  SlopeTrick<ll> slope;

  int N; scanf("%d", &N);
  for(int i=0; i<2*N; i++) {
    slope.addAbsFunc(0);
  }
  ll prevT = 0;
  for(int i=0; i<N; i++) {
    ll t, d, x; scanf("%lld%lld%lld", &t, &d, &x);
    // 自由な時間が dur 秒ある -> [x-dur, x+dur] から x にいける
    ll dur = t - prevT;
    slope.applySlidingWindow(-dur, +dur);
    if(d == 0) slope.addAmxFunc(x);
    if(d == 1) slope.addXmaFunc(x);
    prevT = t;
  }
  printf("%lld\n", slope.getMinVal());
  return 0;
}