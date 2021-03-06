#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G&lang=ja"
#define ERROR "1e-5"
#define DESCRIPTION "$2$ つの円 $c_1, c_2$ の共通接線を求める"

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
    vector<Line> ans = tangentLines(a, b);
    sort(ans.begin(), ans.end());
    for(size_t i=0; i<ans.size(); i++) {
        /*
        if(abs(ans[i].first.real()) < EPS) ans[i].first.real() = 0.0;
        if(abs(ans[i].first.imag()) < EPS) ans[i].first.imag() = 0.0;
        */
        printf("%.10f %.10f\n", ans[i].first.real(), ans[i].first.imag());
    }
    return 0;
}
