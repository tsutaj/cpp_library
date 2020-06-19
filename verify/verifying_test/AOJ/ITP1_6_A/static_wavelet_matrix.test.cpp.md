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


# :heavy_check_mark: verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp

<a href="../../../../index.html">Back to top page</a>

* category: <a href="../../../../index.html#c55a923ec0d59eedfec592c514a270cb">verifying_test/AOJ/ITP1_6_A</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 00:46:27+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A&lang=ja</a>


## Depends on

* :heavy_check_mark: <a href="../../../../library/structure/strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>
* :heavy_check_mark: <a href="../../../../library/structure/strc_024_static_wavelet_matrix.cpp.html">Wavelet 行列 (wavelet matrix)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A&lang=ja"
#define DESCRIPTION "与えられた数列を逆順に出力"

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

    WaveletMatrix<10> wm(A);
    for(int i=0; i<N; i++) printf("%d%c", wm[N-1-i], " \n"[i + 1 == N]);
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 307, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: structure/strc_024_static_wavelet_matrix.cpp: line 7: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

