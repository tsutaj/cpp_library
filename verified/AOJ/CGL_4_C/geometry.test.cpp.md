<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../../../css/copy-button.css" />
<script src="../../../js/balloons.js"></script>
<script src="../../../js/copy-button.js"></script>



[トップページに戻る](../../../index.html)

# :heavy_check_mark: ./AOJ/CGL\_4\_C/geometry.test.cpp

* URL: [http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja)
* 凸多角形 $$g$$ を直線 $$p_1 p_2$$ で切断したときの、その左側にできる凸多角形の面積 (Convex Cut) を求める

## Dependencies
* [geometry\_2D.cpp](../../../library/geometry_2D.cpp.html)

## Code

```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja"
#define ERROR "1e-5"
#define DESCRIPTION "凸多角形 $$g$$ を直線 $$p_1 p_2$$ で切断したときの、その左側にできる凸多角形の面積 (Convex Cut) を求める"

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

    int q; cin >> q;
    for(int i=0; i<q; i++) {
        double ax, ay, bx, by;
        cin >> ax >> ay >> bx >> by;
        
        Point a(ax, ay), b(bx, by);
        vector<Point> ret = convexCut(a, b, ps);
        printf("%.10f\n", area(ret));
    }
    return 0;
}

```

[トップページに戻る](../../../index.html)
