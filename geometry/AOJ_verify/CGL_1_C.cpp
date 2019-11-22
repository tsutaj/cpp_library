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

// ccw (c が直線(線分) ab に対してどのような位置関係か？)
// +1 ... a → b で半時計方向に折れて b → c (COUNTER_CLOCKWISE)
// -1 ... a → b で時計方向に折れて b → c (CLOCKWISE)
// +2 ... c, a, b がこの順で同一直線状にある場合 (ONLINE_BACK)
// -2 ... a, b, c がこの順で同一直線状にある場合 ( or a == b ) (ONLINE_FRONT)
//  0 ... c が線分 ab 上にある場合 (点 a, b 上を含む) (ON_SEGMENT)
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

int main() {
    P a, b, c; cin >> a.X >> a.Y >> b.X >> b.Y;
    int n; cin >> n;
    map<int, string> m;
    m[1] = "COUNTER_CLOCKWISE";
    m[-1] = "CLOCKWISE";
    m[2] = "ONLINE_BACK";
    m[-2] = "ONLINE_FRONT";
    m[0] = "ON_SEGMENT";
    rep(i,0,n) {
        cin >> c.X >> c.Y;
        int ans = ccw(a, b, c);
        cout << m[ans] << endl;
    }
    return 0;
}