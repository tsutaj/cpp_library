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


# :heavy_check_mark: verifying_test/AOJ/CGL_7_D/geometry.test.cpp


[Back to top page](../../../../index.html)

* 円 $c$ と直線 $l$ の交点を求める
* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=ja)


## Dependencies
* :heavy_check_mark: [geometry/geometry_2D.cpp](../../../../library/geometry/geometry_2D.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=ja"
#define ERROR "1e-6"
#define DESCRIPTION "円 $c$ と直線 $l$ の交点を求める"

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
    double ax, ay, ar; cin >> ax >> ay >> ar;
    Circle a({ax, ay}, ar);

    int n; cin >> n;
    for(int i=0; i<n; i++) {
        double px, py, qx, qy; cin >> px >> py >> qx >> qy;
        Point x(px, py), y(qx, qy);
        vector<Point> ans = crossp_lc(x, y, a);
        if(ans.size() == 1) {
            printf("%.10f %.10f %.10f %.10f\n", ans[0].real(), ans[0].imag(), ans[0].real(), ans[0].imag());
        }
        else {
            sort(ans.begin(), ans.end());
            printf("%.10f %.10f %.10f %.10f\n", ans[0].real(), ans[0].imag(), ans[1].real(), ans[1].imag());
        }
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../../../index.html)

