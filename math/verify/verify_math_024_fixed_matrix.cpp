#include <iostream>
#include <cstdio>
#include <valarray>
#include <vector>
#include <functional>
using namespace std;
#include "../math_024_fixed_matrix.cpp"
#include "../math_017_modint.cpp"
#include "../../structure/strc_009_abst_lazy_segtree.cpp"

void CF373_div2_E() {
    using mint = ModInt<1000000007>;
    using Mat = FixedMatrix<mint, 2, 2>;
    using Vec = FixedMatrix<mint, 2, 1>;
 
    auto f = [](Vec a, Mat b) { return b * a; };
    auto g = [](Vec a, Vec b) {
        return a + b;
    };
    auto h = [](Mat a, Mat b) {
        return a * b;
    };
    auto p = [](Mat a, int x) {
        return a;
    };
 
    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;
    Mat E1 = eigen<mint, 2, 2>();
        
    Mat fib;
    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0) = 1;
    fib.at(1, 1) = 0;
    
    Vec vec;
    vec.at(0, 0) = 1, vec.at(1, 0) = 0;
    
    int N, Q; scanf("%d%d", &N, &Q);
    vector<Vec> matrices(N);
    for(int i=0; i<N; i++) {
        int v; scanf("%d", &v);
        Mat pow_fib = pow(fib, v - 1);
        matrices[i] = pow_fib * vec;
    }
    
    LazySegmentTree<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);
    
    while(Q--) {
        int type; scanf("%d", &type);
        if(type == 1) {
            int l, r, x; scanf("%d%d%d", &l, &r, &x); l--;
            Mat pow_fib = pow(fib, x);
            seg.update(l, r, pow_fib);
        }
        if(type == 2) {
            int l, r; scanf("%d%d", &l, &r); l--;
            auto res = seg.query(l, r);
            printf("%lld\n", res.at(0, 0).v);
        }
    }
}

int main() {
    CF373_div2_E();
}
