#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
#include "../algo_002_accumulation.cpp"

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

// Verified on Apr 28, 2019 (prefix, suffix のみ)
// Judge: https://atcoder.jp/contests/abc125/tasks/abc125_c
void ABC125_C() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return gcd(a, b); });

    int ans = 0;
    for(int i=0; i<N; i++) {
        int vl = acc.get_prefix(i), vr = acc.get_suffix(i+1);
        ans = max(ans, gcd(vl, vr));
    }
    cout << ans << endl;
}

// Verified on Apr 28, 2019 (subseq のみ)
// Judge: https://atcoder.jp/contests/abc122/tasks/abc122_c
void ABC122_C() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    vector<int> A(N);
    for(int i=1; i<N; i++) {
        A[i] = (s[i-1] == 'A' and s[i] == 'C');
    }

    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return a + b; },
                          [](int a, int b) { return a - b; });

    for(int i=0; i<Q; i++) {
        int l, r; cin >> l >> r;
        cout << acc.get_subseq(l, r) << endl;
    }
}

int main() {
    // ABC125_C();
    ABC122_C();
    return 0;
}
