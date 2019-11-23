#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C&lang=ja"

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
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by;
    Point a(ax, ay), b(bx, by);
    
    int n; cin >> n;
    map<int, string> m;
    m[1] = "COUNTER_CLOCKWISE";
    m[-1] = "CLOCKWISE";
    m[2] = "ONLINE_BACK";
    m[-2] = "ONLINE_FRONT";
    m[0] = "ON_SEGMENT";

    for(int i=0; i<n; i++) {
        cin >> cx >> cy;
        Point c(cx, cy);
        int ans = ccw(a, b, c);
        cout << m[ans] << endl;
    }
    return 0;
}
