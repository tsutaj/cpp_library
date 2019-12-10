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


# :heavy_check_mark: 二次元平面における点集合 $P$ の凸包を求める
<a href="../../../../index.html">Back to top page</a>

* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/AOJ/CGL_4_A/geometry.test.cpp">View this file on GitHub</a> (Last commit date: 2019-11-25 23:59:53 +0900)


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja</a>


## Dependencies
* :heavy_check_mark: <a href="../../../../library/geometry/geometry_2D.cpp.html">geometry/geometry_2D.cpp</a>


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja"
#define DESCRIPTION "二次元平面における点集合 $P$ の凸包を求める"

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

#include "../../../geometry/geometry_2D.cpp"

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

int main() {
    int n; cin >> n;
    vector<Point> ps;
    for(int i=0; i<n; i++) {
        double x, y; cin >> x >> y;
        ps.emplace_back(x, y);
    }

    vector<Point> ans = convexHull(ps);
    cout << ans.size() << endl;
    for(size_t i=0; i<ans.size(); i++) {
        printf("%d %d\n", (int)ans[i].real(), (int)ans[i].imag());
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../index.html">Back to top page</a>

