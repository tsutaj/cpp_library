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

    bool cmp_y(const P &a, const P& b) {
        return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
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

vector<P> convexHull(vector<P> ps) {
    int n = ps.size();
    sort(ps.begin(),ps.end(), cmp_y);
    int k = 0;
    vector<P> convex(n*2);
    for(int i=0; i<n; i++) {
        while (k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;
        convex[ k++ ] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--) {
        while (k > t && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;
        convex[ k++ ] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

int main() {
    int n; cin >> n;
    vector<P> ps;
    P a;
    rep(i,0,n) {
        cin >> a.X >> a.Y;
        ps.pb(a);
    }

    vector<P> ans = convexHull(ps);
    cout << ans.size() << endl;
    rep(i,0,ans.size()) {
        printf("%d %d\n", (int)ans[i].X, (int)ans[i].Y);
    }
    return 0;
}