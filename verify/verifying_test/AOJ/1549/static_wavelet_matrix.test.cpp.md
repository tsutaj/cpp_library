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


# :heavy_check_mark: $\left\[ l, r \right\]$ にある整数の中で $D$ に最も近いものを求める
<a href="../../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28 +0900


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549</a>


## Dependencies
* :heavy_check_mark: <a href="../../../../library/structure/strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>
* :heavy_check_mark: <a href="../../../../library/structure/strc_024_static_wavelet_matrix.cpp.html">Wavelet 行列 (wavelet matrix)</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549"
#define DESCRIPTION "\"閉区間\" $\left[ l, r \right]$ にある整数の中で $D$ に最も近いものを求める"

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

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

