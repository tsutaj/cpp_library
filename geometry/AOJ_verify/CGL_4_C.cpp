#include <iostream>
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
#include <climits>
#include <ctime>
#include <cassert>
using namespace std;

#define rep(i,a,n) for(int i=a; i<n; i++)
#define repr(i,a,n) for(int i=a; i>=n; i--)
#define pb(a) push_back(a)
#define fr first
#define sc second
#define INF 999999999

#define X real()
#define Y imag()
#define EPS (1e-10)
#define EQ(a,b) (abs((a) - (b)) < EPS)
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )
#define LE(n, m) ((n) < (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))

typedef vector<int> VI;
typedef vector<VI> MAT;
typedef pair<int, int> pii;
typedef long long int ll;

typedef complex<double> P;
typedef pair<P, P> L;
typedef pair<P, double> C;

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
int const MOD = 1000000007;

namespace std {
    bool operator<(const P& a, const P& b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// 2つのベクトルの内積を求める
double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}

// 2つのベクトルの外積を求める
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

double area(const vector<P> &ps) {
    double a = 0;
    rep(i,0,ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a / 2;
}

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

// 直線 a1, a2 と直線b1, b2の交点を求める
// Verified: AOJ CGL_2_C.cpp
P crossp_ll(P a1, P a2, P b1, P b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if( EQ(d1,0) && EQ(d2,0) ) return a1; // same line
    if( EQ(d2,0) ) assert(false); // precondition not satisfied
    return a1 + d1 / d2 * (a2 - a1);
}

// 凸多角形クリッピング
vector<P> convexCut(P a1, P a2, const vector<P> &ps) {
    int n = ps.size();
    vector<P> ret;
    rep(i,0,n) {
        int ccwc = ccw(a1, a2, ps[i]);
        if(ccwc != -1) ret.push_back(ps[i]);
        int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
        if(ccwc * ccwn == -1) ret.push_back(crossp_ll(a1, a2, ps[i], ps[(i + 1) % n]));
    }
    return ret;
}

int main() {
    int n; cin >> n;
    vector<P> ps;
    rep(i,0,n) {
        P temp; cin >> temp.X >> temp.Y;
        ps.pb(temp);
    }

    int q; cin >> q;
    rep(i,0,q) {
        P a, b; cin >> a.X >> a.Y >> b.X >> b.Y;
        vector<P> ret = convexCut(a, b, ps);
        printf("%.10f\n", area(ret));
    }
    return 0;
}