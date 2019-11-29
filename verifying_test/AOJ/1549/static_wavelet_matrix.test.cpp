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
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

#include "../../../structure/strc_023_compact_bitvector.cpp"
#include "../../../structure/strc_024_static_wavelet_matrix.cpp"

// @see http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
// @brief 閉区間 $\left[ l, r \right]$ にある整数の中で $D$ に最も近いものを求める

int main() {
    int N; scanf("%d", &N);

    int ofs = 1 << 20;
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]), A[i] += ofs;
    WaveletMatrix<25> wm(A);

    int Q; scanf("%d", &Q);
    for(int i=0; i<Q; i++) {
        int l, r, d; scanf("%d%d%d", &l, &r, &d);
        r++; d += ofs;
        if(wm.freq(l, r, d) > 0) printf("0\n");
        else {
            int vu = wm.next_val(l, r, d);
            int vd = wm.prev_val(l, r, d);
            int ans = ofs;
            if(vu != -1) ans = min(ans, vu - d);
            if(vd != -1) ans = min(ans, d - vd);
            printf("%d\n", ans);
        }
    }
    return 0;
}
