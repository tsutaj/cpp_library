#pragma once

/**
 * @brief Cartesian Tree
 * @docs ./docs/cartesian_tree.md
 */

#include <vector>
#include <stack>
#include <utility>
#include <functional>
using namespace std;

#include "../graph/graph_000_basic.cpp"

template <typename Tp = int>
pair< Graph<>, int > getCartesianTree(const vector<Tp> &A,
    function<bool(Tp, Tp)> cmp = [](Tp a, Tp b) {
        return a < b; // min
    }
) {
    int N = A.size();
    vector<int> par(N, -1), st;
    st.reserve(N);
    for(int i=0; i<N; i++) {
        int prev_idx = -1;
        while(st.size() and cmp(A[i], A[st.back()])) {
            prev_idx = st.back(); st.pop_back();
        }
        if(prev_idx >= 0) {
            par[ prev_idx ] = i;
        }
        if(st.size()) {
            par[i] = st.back();
        }
        st.emplace_back(i);
    }

    int root = -1;
    Graph<> G(N);
    for(int i=0; i<N; i++) {
        if(par[i] < 0) {
            root = i;
        }
        else {
            G[ par[i] ].emplace_back(i);
        }
    }
    return make_pair(G, root);
}
