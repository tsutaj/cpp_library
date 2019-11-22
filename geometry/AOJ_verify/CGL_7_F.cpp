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
#define LEQ(n, m) ((n) <= (m) + EPS)
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

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

// 点 p から円 x への接線の接点
vector<P> tangentPoints(P p, C x) {
    vector<P> ps;
    P a = x.first; double ar = x.second;
    double sin = ar / abs(p-a);
    if(!LE(sin, 1)) return ps; // ここで NaN もはじかれる

    double t = M_PI_2 - asin(min(sin, 1.0));
    ps.push_back(a + (p-a) * polar(sin, t));
    if(!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
    return ps;
}

int main() {
    P a; cin >> a.X >> a.Y;
    C c; cin >> c.fr.X >> c.fr.Y >> c.sc;

    vector<P> ans = tangentPoints(a, c);
    sort(ans.begin(), ans.end());
    printf("%.10f %.10f\n%.10f %.10f\n", ans[0].X, ans[0].Y, ans[1].X, ans[1].Y);
    return 0;
}