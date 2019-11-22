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

// 円 x と円 y の交点
vector<P> crossp_cc(C x, C y) {
    vector<P> ps;
    P a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    P ab = b-a;
    double d = abs(ab);
    double crL = (norm(ab) + ar * ar - br * br) / (2 * d);
    if(EQ(d,0) || ar < abs(crL)) return ps;

    P abN = ab * P(0, sqrt(ar*ar - crL*crL) / d);
    P cp = a + crL/d * ab;
    ps.push_back(cp + abN);
    if(!EQ(norm(abN), 0)) ps.push_back(cp - abN);
    return ps;
}

int main() {
    C a, b;
    cin >> a.fr.X >> a.fr.Y >> a.sc >> b.fr.X >> b.fr.Y >> b.sc;
    vector<P> ans = crossp_cc(a, b);
    if(ans.size() == 1) {
        printf("%.10f %.10f %.10f %.10f\n", ans[0].X, ans[0].Y, ans[0].X, ans[0].Y);
    }
    else {
        sort(ans.begin(), ans.end());
        printf("%.10f %.10f %.10f %.10f\n", ans[0].X, ans[0].Y, ans[1].X, ans[1].Y);
    }
    return 0;
}