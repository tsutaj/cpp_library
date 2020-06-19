#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <tuple>
#include <utility>
using ll = long long int;
using namespace std;

#define call_from_test
#include "../../../../algorithm/coordinate_compression.cpp"
#undef call_from_test

int main() {
    int Q; scanf("%d", &Q);
    vector< tuple<ll, ll, ll> > queries(Q);
    vector<ll> indices(Q);
    for(int i=0; i<Q; i++) {
        ll t, k, v=-1; scanf("%lld", &t);
        if(t == 0) {
            scanf("%lld%lld", &k, &v);
        }
        if(t == 1) {
            scanf("%lld", &k);
        }
        queries[i] = make_tuple(t, k, v);
        indices[i] = k;
    }

    coor_comp<ll> comp(indices);
    vector<ll> rec(comp.size());
    for(int i=0; i<Q; i++) {
        ll t, k, v; tie(t, k, v) = queries[i];
        if(t == 0) {
            rec[ comp[k] ] = v;
        }
        if(t == 1) {
            printf("%lld\n", rec[ comp[k] ]);
        }
    }
    return 0;
}
