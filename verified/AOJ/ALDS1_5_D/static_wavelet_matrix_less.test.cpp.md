<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_less.test.cpp
---

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja)
* 転倒数を求める (自分より小さいものを数えるアプローチ)

## Dependencies
* [strc\_023\_compact\_bitvector.cpp](../../../library/strc_023_compact_bitvector.cpp.html)
* [strc\_024\_static\_wavelet\_matrix.cpp](../../../library/strc_024_static_wavelet_matrix.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja"
#define DESCRIPTION "転倒数を求める (自分より小さいものを数えるアプローチ)"

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

int main() {
    int N; scanf("%d", &N);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    WaveletMatrix<> wm(A);
    ll ans = 0;
    for(int i=0; i<N; i++) ans += wm.freq_less(i, N, A[i]);
    printf("%lld\n", ans);
    return 0;
}

```

[トップページに戻る](../../../index.html)