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
#define EPS (1e-13)
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

double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}

// 2つのベクトルの外積を求める
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

P projection(P a1, P a2, P p) {
    return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);
}

// 直線 a1, a2 と円 C との交点
vector<P> crossp_lc(P a1, P a2, C c) {
    vector<P> ps;
    double r = c.second;
    P ft = projection(a1, a2, c.first);
    if(!GEQ(r*r, norm(ft-c.first))) return ps;

    P dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);
    return ps;
}

int main() {
    C a;
    cin >> a.fr.X >> a.fr.Y >> a.sc;
    int n; cin >> n;
    rep(i,0,n) {
        P x, y;
        cin >> x.X >> x.Y >> y.X >> y.Y;
        vector<P> ans = crossp_lc(x, y, a);
        if(ans.size() == 1) {
            printf("%.10f %.10f %.10f %.10f\n", ans[0].X, ans[0].Y, ans[0].X, ans[0].Y);
        }
        else {
            sort(ans.begin(), ans.end());
            printf("%.10f %.10f %.10f %.10f\n", ans[0].X, ans[0].Y, ans[1].X, ans[1].Y);
        }
    }
    return 0;
}