#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "../strc_002_bit.cpp"
#include "../strc_004_bit_sec.cpp"

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;

    using ll = long long int;
    BIT_sec<ll> bit(N);
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x;
            bit.add(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t;
            cout << bit.sum(s, t) << endl;
        }
    }
}

int main() {
    DSL_2_G();
    return 0;
}
