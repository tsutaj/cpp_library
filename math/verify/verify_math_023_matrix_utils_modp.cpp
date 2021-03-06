#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_004_matrix.cpp"
#include "../math_023_matrix_utils_modp.cpp"


void ARC054_C() {
    using mint = ModInt<2>;
    int N; cin >> N;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = mint(1);
        }
    }

    mint d = detModp(mat);
    if(d == mint(0)) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    using mint = ModInt<2>;
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    Matrix<mint> mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = mint(p);
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = mint(p);
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationModp(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != mint(0)) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank;
    cout << ModInt<1000000007>(2).pow(p) << endl;
}

int main() {
    // ARC054_C(); // detModp
    yuki_803(); // gaussianEliminationModp
}
