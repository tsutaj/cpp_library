#pragma once

// @brief Disjoint Sparse Table
// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946
// @docs ./docs/disjoint_sparse_table.md

#include <vector>
#include <functional>
#include <cassert>

template <typename Tp>
struct DisjointSparseTable {
    int N, LN;
    vector<Tp> A;
    vector< vector<Tp> > seg_l, seg_r;
    function<Tp(Tp, Tp)> cmb_f;
    
    DisjointSparseTable() = default;
    DisjointSparseTable(vector<Tp> A_,
                        function<Tp(Tp, Tp)> cmb_f_)
        : A(A_), cmb_f(cmb_f_) {
        N = A.size(), LN = 1;
        while((1<<LN) < N) LN++;
        seg_l.resize(LN, vector<Tp>(N));
        seg_r.resize(LN, vector<Tp>(N));
        build(A);
    }

    void build(const vector<Tp> &A) {
        for(int i=0; i<LN; i++) {
            // [j-(1<<i), j), [ j, j+(1<<i) )
            for(int j=(1<<i); j<=N; j+=(1<<(i+1))) {
                if(j < N) seg_r[i][j] = A[j];
                for(int k=j+1; k<j+(1<<i); k++) {
                    if(k >= N) break;
                    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);
                }
                if(j-1 >= 0) seg_l[i][j-1] = A[j-1];
                for(int k=j-2; k>=j-(1<<i); k--) {
                    if(k < 0) break;
                    seg_l[i][k] = cmb_f(seg_l[i][k+1], A[k]);
                }
            }
        }
    }

    Tp query(int l, int r) {
        assert(0 <= l and l < r and r <= N); r--;
        if(l == r) return A[l];
        int k = 31 - __builtin_clz((unsigned int)(l ^ r));
        return cmb_f(seg_l[k][l], seg_r[k][r]);
    }
};
