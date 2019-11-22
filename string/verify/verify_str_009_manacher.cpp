#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#include "../str_009_manacher.cpp"
#include "../../structure/strc_008_abst_segtree.cpp"

void tiny_test_str() {
    string s; cin >> s;
    char dummy = '$';

    Manacher<string, char> man(s, dummy);
    man.dump();
}

void tiny_test_int() {
    int N; cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    int dummy = 0;

    Manacher< vector<int>, int > man(v, dummy);
    man.dump(false);
}

void yuki_464() {
    string s; cin >> s;
    int N = s.size();
    Manacher<string, char> man(s, '$');

    long long int dp[5010][5] = {};
    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            for(int k=0; k<4; k++) {
                if(k != 2) {
                    if(!man.is_palindrome(i, j)) continue;
                    dp[j][k+1] += dp[i][k];
                }
                else {
                    dp[j][k+1] += dp[i][k];
                }
            }
        }
    }
    cout << dp[N][4] << endl;
}

void WUPC2019_E() {
    int N, M; cin >> N >> M;
    vector<int> row(N), col(M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c; cin >> c;
            if(c == '1') row[i]++, col[j]++;
        }
    }

    int dummy = -1, ans = 0;
    Manacher< vector<int>, int > mr(row, dummy), mc(col, dummy);
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            bool ok = true;
            ok &= mr.is_palindrome(0, i+1);
            ok &= mr.is_palindrome(i+1, N);
            ok &= mc.is_palindrome(0, j+1);
            ok &= mc.is_palindrome(j+1, M);
            if(ok) ans++;
        }
    }
    cout << ans << endl;
}

void ukuku09_D() {
    struct SegFunc {
        static int update(int a, int b) { return max(a, b); }
        static int combine(int a, int b) { return max(a, b); }
    };
    
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    Manacher< string, char > man(s, '$');
    SegmentTree< int, SegFunc > seg(N, -1);

    for(int i=0; i<N; i++) {
        int rad = man.get_rad(i);
        seg.update(i, rad);
    }
    
    while(Q--) {
        int ql, qr; cin >> ql >> qr; ql--;

        int ub = (N + 1) / 2 + 1, lb = -1;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            int l = ql + mid - 1;
            int r = qr - mid + 1;

            bool ok = true;
            if(l >= r) ok = false;
            else {
                int val = seg.query(l, r);
                ok = (val >= mid);
            }

            if(ok) lb = mid;
            else ub = mid;
        }
        int ans = lb * 2 - 1;
        cout << ans << endl;
    }
}

int main() {
    // tiny_test_str();
    // tiny_test_int();
    // yuki_464();
    // WUPC2019_E();
    ukuku09_D();
    return 0;
}
