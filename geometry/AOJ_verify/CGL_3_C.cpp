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
    bool operator<(const P a, const P b) {
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

int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

// 凸多角形の内部判定 O(n)
int inPolygon(P p, const vector<P> &ps) {
    int n = ps.size();
    bool in = false;
    rep(i,0,n) {
        P a = ps[i] - p;
        P b = ps[(i+1) % n] - p;
        if(EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
        if(a.Y > b.Y) swap(a,b);
        if((a.Y * b.Y < 0 || (a.Y * b.Y < EPS && b.Y > EPS)) && LE(cross(a,b), 0)) in = !in;
    }
    return in;
}

int main() {
    int n; cin >> n;
    vector<P> ps;
    P a;
    rep(i,0,n) {
        cin >> a.X >> a.Y;
        ps.pb(a);
    }

    map<int, int> d;
    d[2] = 1;
    d[1] = 2;

    int m; P b;
    cin >> m;
    rep(i,0,m) {
        cin >> b.X >> b.Y;
        cout << d[inPolygon(b, ps)] << endl;
    }
    return 0;
}