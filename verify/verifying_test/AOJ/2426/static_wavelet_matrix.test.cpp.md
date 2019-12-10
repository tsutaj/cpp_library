---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
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
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../assets/css/copy-button.css" />


# :heavy_check_mark: 矩形 $x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$ 内に属する点の個数を求める
<a href="../../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426</a>


## Dependencies
* :heavy_check_mark: <a href="../../../../library/structure/strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>
* :heavy_check_mark: <a href="../../../../library/structure/strc_024_static_wavelet_matrix.cpp.html">Wavelet 行列 (wavelet matrix)</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"
#define DESCRIPTION "矩形 $x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$ 内に属する点の個数を求める"

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
    int N, M; scanf("%d%d", &N, &M);

    ll ofs = 1LL << 30;
    vector< pair<ll, ll> > tre;
    for(int i=0; i<N; i++) {
        ll x, y; scanf("%lld%lld", &x, &y);
        x += ofs, y += ofs;
        tre.emplace_back(x, y);
    }

    sort(tre.begin(), tre.end());
    vector<ll> A;
    for(int i=0; i<N; i++) A.emplace_back(tre[i].second);
    WaveletMatrix<35, ll> wm(A);
    
    for(int i=0; i<M; i++) {
        ll xl, yl, xr, yr; scanf("%lld%lld%lld%lld", &xl, &yl, &xr, &yr);
        xl += ofs, yl += ofs;
        xr += ofs, yr += ofs;
        int l = lower_bound(tre.begin(), tre.end(), make_pair(xl, -1LL)) - tre.begin();
        int r = upper_bound(tre.begin(), tre.end(), make_pair(xr, LONGINF)) - tre.begin();
        printf("%d\n", wm.freq(l, r, yl, yr));
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

