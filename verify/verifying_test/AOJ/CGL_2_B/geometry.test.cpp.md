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


# :heavy_check_mark: verifying_test/AOJ/CGL_2_B/geometry.test.cpp


[Back to top page](../../../../index.html)

* 線分 $s_1, s_2$ について、交差を判定
* see: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=ja)


## Dependencies
* :heavy_check_mark: [geometry/geometry_2D.cpp](../../../../library/geometry/geometry_2D.cpp.html)


## Code
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=ja"
#define DESCRIPTION "線分 $s_1, s_2$ について、交差を判定"

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
 
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

int main() {
    int q; cin >> q;
    for(int i=0; i<q; i++) {
        double ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

        Point a(ax, ay), b(bx, by), c(cx, cy), d(dx, dy); 
        if(isec_ss(a,b,c,d)) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

```
{% endraw %}

[Back to top page](../../../../index.html)

