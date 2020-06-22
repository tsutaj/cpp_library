#include <cstdio>
#include <vector>
#include <functional>
using namespace std;
using ll = long long int;

#define call_from_test
#include "../../../graph/graph_020_HLDecomposition.cpp"
#include "../../../structure/strc_009_abst_lazy_segtree.cpp"
#undef call_from_test

int main() {
    int N; scanf("%d", &N);
    HLD hld(N);
    for(int i=0; i<N; i++) {
        int K; scanf("%d", &K);
        for(int j=0; j<K; j++) {
            int v; scanf("%d", &v);
            hld.add_edge(i, v);
        }
    }
    hld.build();

    LazySegmentTree<ll, ll> seg(N, 0, 0,
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, ll b) { return a + b; },
                                [](ll a, int x) { return a * x; });
    int Q; scanf("%d", &Q);
    while(Q--) {
        int t; scanf("%d", &t);
        if(t == 0) {
            int v, w; scanf("%d%d", &v, &w);
            int u = hld.par[v];
            hld.query_edges(u, v, [&](int l, int r) {
                    seg.update(l, r, w);
                });
        }
        if(t == 1) {
            int u; scanf("%d", &u);
            auto f = [&](int l, int r) {
                return seg.query(l, r);
            };
            auto m = [&](ll v0, ll v1) {
                return v0 + v1;
            };
            ll ans = hld.query_edges(0, u, 0, f, m);
            printf("%lld\n", ans);
        }
    }
    return 0;
}
