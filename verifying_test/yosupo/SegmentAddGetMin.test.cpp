#define PROBLEM "https://judge.yosupo.jp/problem/segment_add_get_min"

// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>
using namespace std;
using ll = long long int;
using int64 = long long int;
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll MOD = 1000000007LL;

#include "../../math/math_010_convexhulltrick.cpp"

const ll INF = 1LL << 62;
int main() {
    int N, Q; scanf("%d%d", &N, &Q);

    vector<ll> points, L(N), R(N), A(N), B(N);
    for(int i=0; i<N; i++) {
        scanf("%lld%lld%lld%lld", &L[i], &R[i], &A[i], &B[i]); R[i]--;
        points.emplace_back(L[i]);
        points.emplace_back(R[i]);
    }

    vector<ll> t(Q), l(Q), r(Q), a(Q), b(Q), p(Q);
    for(int i=0; i<Q; i++) {
        scanf("%lld", &t[i]);
        if(t[i] == 0) {
            scanf("%lld%lld%lld%lld", &l[i], &r[i], &a[i], &b[i]); r[i]--;
            points.emplace_back(l[i]);
            points.emplace_back(r[i]);
        }
        if(t[i] == 1) {
            scanf("%lld", &p[i]);
            points.emplace_back(p[i]);
        }
    }
    
    LiChaoTree<ll, ll> cht(points, INF,
                           [](ll a, ll b) { return a > b; });
    for(int i=0; i<N; i++) {
        cht.insert(A[i], B[i], L[i], R[i]);
    }
    for(int i=0; i<Q; i++) {
        if(t[i] == 0) {
            cht.insert(a[i], b[i], l[i], r[i]);
        }
        if(t[i] == 1) {
            ll res = cht.query(p[i]);
            if(res == INF) puts("INFINITY");
            else printf("%lld\n", res);
        }
    }
    return 0;
}
