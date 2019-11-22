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

pair<int, int> convexDiameter(const vector<P> &ps) {
    int n = ps.size();
    int i = min_element(ps.begin(), ps.end()) - ps.begin();
    int j = max_element(ps.begin(), ps.end()) - ps.begin();
    int maxI, maxJ;
    double maxD = 0;
    rep(_, 0, 2*n) {
        if(maxD < norm(ps[i] - ps[j])) {
            maxD = norm(ps[i] - ps[j]);
            maxI = i;
            maxJ = j;
        }
        if(cross(ps[i] - ps[(i+1) % n], ps[(j+1) % n] - ps[j]) <= 0) j = (j+1) % n;
        else i = (i+1) % n;
    }
    return make_pair(maxI, maxJ);
}

int main() {
    int n; cin >> n;
    vector<P> ps;
    rep(i,0,n) {
        P temp; cin >> temp.X >> temp.Y;
        ps.pb(temp);
    }
    pii ans = convexDiameter(ps);
    printf("%.10f\n", sqrt(norm(ps[ans.first] - ps[ans.second])));
    return 0;
}