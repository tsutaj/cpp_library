#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
#include "../math_004_matrix.cpp"
#include "../math_022_matrix_utils_real.cpp"

void tiny_test() {
    int N, M; cin >> N >> M;
    Matrix<double> mat(N, M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }

    cout << fixed << setprecision(12) << detReal(mat) << endl;

    vector<double> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];
    auto ans = linearEquationReal(mat, vec);
    for(auto e : ans) cout << e << " ";
    cout << endl;
}

void AOJ1328() {
    int d;
    using ld = long double;
    const ld EPS = 9e-5;
    while(cin >> d, d) {
        vector<ld> v(d+3);
        for(int i=0; i<d+3; i++) cin >> v[i];

        int row = d+3, col = d+1;
        Matrix<ld> mat(row, col);
        for(int i=0; i<row; i++) {
            ld p = 1;
            for(int j=0; j<col; j++) {
                mat[i][j] = p;
                p *= i;
            }
        }

        for(int i=0; i<row; i++) {
            vector<ld> tm = mat[i];
            ld tv = v[i];
            for(int j=0; j<col; j++) mat[i][j] = 0;
            v[i] = 0;

            auto res = linearEquationReal(mat, v, EPS);
            if(res.size()) {
                cout << i << endl;
                i = d + 5;
            }
            else {
                for(int j=0; j<col; j++) mat[i][j] = tm[j];
                v[i] = tv;
            }
        }
    }
}

int main() {
    tiny_test();
    // AOJ1328(); // linear equation
}
