[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/DSL\_3\_D/static\_wavelet\_matrix.test.cpp
---

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja)
* 連続部分列中の最小の要素を答える

## Dependencies
* [strc\_023\_compact\_bitvector.cpp](../../../lib/strc_023_compact_bitvector.cpp.html)
* [strc\_024\_static\_wavelet\_matrix.cpp](../../../lib/strc_024_static_wavelet_matrix.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja"
#define DESCRIPTION "連続部分列中の最小の要素を答える"

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
    int N, L; scanf("%d%d", &N, &L);
    vector<int> A(N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);

    WaveletMatrix<> wm(A);
    for(int i=0; i<N-L+1; i++) {
        printf("%d%c", wm.min_value(i, i+L), " \n"[i+1 == N-L+1]);
    }
    return 0;
}
```

[トップページに戻る](../../../index.html)
