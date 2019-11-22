#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"

int main() {
    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];

    SuccinctBitVector<> sb(vec);
    for(int i=0; i<N; i++) {
        cout << sb.rank(i) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_nxt(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_pre(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;

    cout << "count: " << sb.count() << ", size = " << sb.size() << endl;
    
/*
    while(true) {
        int q; cin >> q;
        if(q == 1) {
            int k; cin >> k; k--;
            cout << sb.rank(k) << endl;
        }
        if(q == 2) {
            int k; cin >> k; k--;
            int a = sb.select_nxt(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 3) {
            int k; cin >> k; k--;
            int a = sb.select_pre(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 4) {
            int l, r; cin >> l >> r; l--;
            cout << sb.rank(l, r) << endl;
        }
    }
*/
    return 0;
}
