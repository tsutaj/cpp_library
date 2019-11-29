#include <vector>
#include <array>
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"
#include "../strc_024_static_wavelet_matrix.cpp"

int main() {
    vector<int> vec = {2, 10, 2, 3, 2, 5, 4, 4};
    WaveletMatrix<4> wm(vec);
    
    for(size_t i=0; i<vec.size(); i++) {
        cerr << wm[i] << " ";
    }
    cerr << endl;

    while(true) {
        // int k, x; cin >> k >> x; k--;
        // cout << wm.rank_idx(k, x) << endl;
        int l, r, k, x; cin >> l >> r >> k >> x; l--;
        cout << wm.select(l, r, k, x) << endl;
        // cout << res << endl;
    }
    return 0;
}
