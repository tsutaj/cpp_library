<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../../../css/copy-button.css" />
<script type="text/javascript" src="../../../js/balloons.js"></script>
<script type="text/javascript" src="../../../js/copy-button.js"></script>



[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/2426/static\_wavelet\_matrix.test.cpp

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426)
* 矩形 $$x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$$ 内に属する点の個数を求める

## Dependencies
* [strc\_023\_compact\_bitvector.cpp](../../../library/strc_023_compact_bitvector.cpp.html)
* [strc\_024\_static\_wavelet\_matrix.cpp](../../../library/strc_024_static_wavelet_matrix.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426"
#define DESCRIPTION "矩形 $$x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$$ 内に属する点の個数を求める"

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

[トップページに戻る](../../../index.html)
