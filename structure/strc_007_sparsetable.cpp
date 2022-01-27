#pragma once

// @brief Sparse Table
// @docs docs/structure/sparse_table.md

#include <vector>
#include <functional>
#include <cassert>

template <typename Tp>
struct SparseTable {
    size_t N, LN;
    vector<Tp> A, logs;
    vector< vector<Tp> > node;
    function<Tp(Tp, Tp)> f;

    SparseTable() = default;
    SparseTable(vector<Tp> A_, function<Tp(Tp, Tp)> f_) :
        A(A_), f(f_) {
        N = LN = 1;
        while(N < A.size()) N <<= 1, LN++;
        N = A.size();
        logs.resize(N+1);
        node.resize(N, vector<int>(LN));
        build();
    }

    void build() {
        for(size_t i=2; i<N; i++) {
            logs[i] = logs[i>>1] + 1;
        }
        for(size_t i=0; i<N; i++) {
            node[i][0] = A[i];
        }
        for(size_t k=0; k+1<LN; k++) {
            for(size_t i=0; i+(1<<k)<N; i++) {
                Tp x = node[i][k];
                Tp y = node[i+(1<<k)][k];
                node[i][k+1] = f(x, y);
            }
        }
    }

    inline Tp query(size_t l, size_t r) {
        assert(l < r and r <= N);
        int d = logs[r-l];
        Tp x = node[l][d];
        Tp y = node[r-(1<<d)][d];
        return f(x, y);
    }
};
