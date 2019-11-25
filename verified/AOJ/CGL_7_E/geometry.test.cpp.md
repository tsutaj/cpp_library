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

# :heavy_check_mark: ./AOJ/CGL\_7\_E/geometry.test.cpp

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=ja)
* $$2$$ つの円 $$c_1, c_2$$ の交点を求める

## Dependencies
* [geometry\_2D.cpp](../../../library/geometry_2D.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=ja"
#define ERROR "1e-6"
#define DESCRIPTION "$$2$$ つの円 $$c_1, c_2$$ の交点を求める"

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
    double ax, ay, ar, bx, by, br;
    cin >> ax >> ay >> ar >> bx >> by >> br;
    
    Circle a({ax, ay}, ar), b({bx, by}, br);
    vector<Point> ans = crossp_cc(a, b);
    if(ans.size() == 1) {
        printf("%.10f %.10f %.10f %.10f\n", ans[0].real(), ans[0].imag(), ans[0].real(), ans[0].imag());
    }
    else {
        sort(ans.begin(), ans.end());
        printf("%.10f %.10f %.10f %.10f\n", ans[0].real(), ans[0].imag(), ans[1].real(), ans[1].imag());
    }
    return 0;
}

```

[トップページに戻る](../../../index.html)
