<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../../../css/copy-button.css" />
<script type="text/javascript" src="../../../js/balloons.js"></script>
<script type="text/javascript" src="../../../js/copy-button.js"></script>



[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/CGL\_2\_C/geometry.test.cpp

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=ja)
* 線分 $$s_1, s_2$$ の交点の座標を求める

## Dependencies
* [geometry\_2D.cpp](../../../library/geometry_2D.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=ja"
#define ERROR "1e-8"
#define DESCRIPTION "線分 $$s_1, s_2$$ の交点の座標を求める"

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
        Point ans = crossp_ll(a,b,c,d);
        printf("%.10f %.10f\n", ans.real(), ans.imag());
    }
    return 0;
}

```

[トップページに戻る](../../../index.html)
