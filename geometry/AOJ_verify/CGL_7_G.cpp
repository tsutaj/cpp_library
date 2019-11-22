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

vector<L> tangentLines(C x, C y) {
    P a = x.first, b = y.first;
    double ar = x.second, br = y.second;
    vector<L> ls;
    double d = abs(b-a);

    rep(i,0,2) {
        double sin = (ar - (1-i*2)*br) / d;
        if(!LE(sin*sin, 1)) break;

        double cos = sqrt(max(1 - sin*sin, 0.0));
        rep(j,0,2) {
            P n = (b-a) * P(sin, (1-j*2)*cos) / d;
            ls.push_back(L(a + ar*n, b + (1-i+2)*br*n));
            if(cos < EPS) break; // 重複する接線を無視 (重複してよいならこの行は不要)
        }
    }
    return ls;
}

int main() {
    C a, b;
    cin >> a.fr.X >> a.fr.Y >> a.sc >> b.fr.X >> b.fr.Y >> b.sc;
    vector<L> ans = tangentLines(a, b);
    sort(ans.begin(), ans.end());
    rep(i,0,ans.size()) {
        if(abs(ans[i].fr.X) < EPS) ans[i].fr.X = 0.0;
        if(abs(ans[i].fr.Y) < EPS) ans[i].fr.Y = 0.0;
        printf("%.10f %.10f\n", ans[i].fr.X, ans[i].fr.Y);
    }
    return 0;
}