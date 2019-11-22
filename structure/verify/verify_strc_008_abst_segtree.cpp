#include <vector>
#include <functional>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
#include "../strc_008_abst_segtree.cpp"

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

// Range Minimum Query
// query 1: update
// query 2: range minimum
void DSL_2_A() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, INT_MAX,
                         [](int a, int b) { return b; },
                         [](int a, int b) { return min(a, b); });

    int indexed = 0;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

// Verified on Apr 27, 2019
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B

// Range Sum Query
// query 1: add
// query 2: range sum
void DSL_2_B() {
    int N, Q; cin >> N >> Q;
    SegmentTree<int> seg(N, 0,
                         [](int a, int b) { return a + b; },
                         [](int a, int b) { return a + b; });

    int indexed = 1;
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        int x, y; cin >> x >> y;
        if(query_type == 0) {
            x -= indexed;
            seg.update(x, y);
        }
        if(query_type == 1) {
            x -= indexed, y -= indexed;
            y++;
            cout << seg.query(x, y) << endl;
        }
    }
}

int main() {
    // DSL_2_A();
    DSL_2_B();
    return 0;
}
