#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#include "../math_005_matrix_mod2.cpp"

void ARC054_C() {
    int N; cin >> N;
    BinaryMatrix mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = 1;
        }
    }

    int d = detBinary(mat);
    if(d == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    BinaryMatrix mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = p;
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = p;
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationBinary(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != 0) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank, ans = 1, MOD = 1000000007;
    for(int i=0; i<p; i++) (ans *= 2) %= MOD;
    cout << ans << endl;
}

int main() {
    // ARC054_C(); // detBinary
    // yuki_803(); // gaussianEliminationBinary
    return 0;
}
