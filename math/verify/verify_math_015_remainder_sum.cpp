#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_015_remainder_sum.cpp"

// Verified on Mar 30, 2019
// Educational Codeforces Round 5 E: Sum of Remainders
// Judge: https://codeforces.com/contest/616/problem/E
void ECR005_E() {
    long long int N, M; cin >> N >> M;
    using mint = ModInt<1000000007>;
    RemainderSum<mint> rs(N);
    cout << rs.sum_func(M) << endl;
}

// Verified on Mar 30, 2019
// yukicoder No. 752: mod 数列
// Judge: https://yukicoder.me/problems/no/752
void yuki_752() {
    long long int P, Q; cin >> P >> Q;
    RemainderSum<long long int> rs(P);
    while(Q--) {
        long long int l, r; cin >> l >> r;
        cout << rs.sum_func(l, r) << endl;
    }
}

int main() {
    ECR005_E();
    // yuki_752();
    return 0;
}
