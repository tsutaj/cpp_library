#define IGNORE
#define PROBLEM "https://atcoder.jp/contests/abc155/tasks/abc155_f"

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
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD = 1000000007LL;

#include "../../../graph/linear_system_incidence.cpp"
#include "../../../math/math_017_modint.cpp"
using mint = ModInt<2>;
 
int main() {
    int N, M; cin >> N >> M;
    vector< pair<int, int> > bomb;
    for(int i=0; i<N; i++) {
        int A, B; cin >> A >> B;
        bomb.emplace_back(A, B);
    }
    sort(bomb.begin(), bomb.end());

    // 隣接 xor
    vector<mint> b(N + 1);
    b[0] = mint(bomb.front().second);
    for(int i=0; i+1<N; i++) {
        b[i+1] = mint(bomb[i].second ^ bomb[i+1].second);
    }
    b[N] = mint(bomb.back().second);

    vector< pair<int, int> > edges;
    vector<int> ids;
    for(int i=0; i<M; i++) {
        int L, R; cin >> L >> R;
        // 範囲内にある爆弾のインデックス [bl, br)
        int bl = lower_bound(bomb.begin(), bomb.end(), make_pair(L, 0)) - bomb.begin();
        int br = upper_bound(bomb.begin(), bomb.end(), make_pair(R, 1)) - bomb.begin();

        if(bl >= br) continue;
        edges.emplace_back(bl, br);
        ids.emplace_back(i);
    }
    M = edges.size();

    // Ax + b = 0 -> Ax = b (mod 2)
    LinearSystemIncidence<mint> lsi(N+1, edges);
    auto ans = lsi.solve(b);
    if(!ans.first) cout << -1 << endl;
    else {
        vector<int> vec;
        for(int i=0; i<M; i++) {
            if(ans.second[i] == mint(1)) vec.emplace_back(ids[i]);
        }

        cout << vec.size() << endl;
        for(size_t i=0; i<vec.size(); i++) cout << vec[i] + 1 << " \n"[i + 1 == vec.size()];
    }
    return 0;
}
