#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;
#include "../math_004_matrix.cpp"
#include "../math_017_modint.cpp"

void EDPC_R() {
    using mint = ModInt<1000000007>;
    long long int N, K; cin >> N >> K;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> mat[i][j];
        }
    }

    mat = pow(mat, K);
    mint ans(0);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            ans += mat[i][j];
        }
    }
    cout << ans << endl;
}

// https://codeforces.com/contest/1117/problem/D
void ECR060_D() {
    long long int N, M; cin >> N >> M;
    
}

// https://codeforces.com/contest/691/problem/E
void ECR014_E() {

}

int main() {
    EDPC_R();
    return 0;
}
