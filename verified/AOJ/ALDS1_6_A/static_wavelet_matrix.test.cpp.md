<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../../../css/copy-button.css" />
<script type="text/javascript" src="../../../js/balloons.js"></script>
<script type="text/javascript" src="../../../js/copy-button.js"></script>



[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/ALDS1\_6\_A/static\_wavelet\_matrix.test.cpp

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=ja)
* ソートを行う (小さいものから $$k$$ 番目を求められることを利用)

## Dependencies
* [strc\_023\_compact\_bitvector.cpp](../../../library/strc_023_compact_bitvector.cpp.html)
* [strc\_024\_static\_wavelet\_matrix.cpp](../../../library/strc_024_static_wavelet_matrix.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A&lang=ja"
#define DESCRIPTION "ソートを行う (小さいものから $$k$$ 番目を求められることを利用)"

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
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    WaveletMatrix<14> wm(A);
    for(int i=0; i<N; i++) printf("%d%c", wm.quantile(i+1), " \n"[i + 1 == N]);
    return 0;
}

```

[トップページに戻る](../../../index.html)
