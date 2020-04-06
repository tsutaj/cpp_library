# pragma once

/**
 * @brief 2 次元累積和 (2 Dimension Cumulative Sum)
 * @docs ./docs/cumulative_sum_2d.md
 */

#include <functional>
#include <vector>
#include <cassert>
template <typename MonoidType>
struct CumulativeSum2D {
    // 持つ矩形領域のサイズ
    // 縦横とも、acc はこれより 2 大きくしておく
    int n, m;
    MonoidType E;
    vector< vector<MonoidType> > acc;
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void accumulate() {
        for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                acc[i][j+1] = op(acc[i][j+1], acc[i][j]);
            }
        }
        for(int j=0; j<=m; j++) {
            for(int i=0; i<n; i++) {
                acc[i+1][j] = op(acc[i+1][j], acc[i][j]);
            }
        }
    }

    CumulativeSum2D() {}
    CumulativeSum2D(int n_, int m_, int E_, MMtoM op_, MMtoM rop_) :
        n(n_), m(m_), E(E_), acc(n_+2, vector<MonoidType>(m_+2, E_)),
        op(op_), rop(rop_) {}
    CumulativeSum2D(vector< vector<MonoidType> > mat, int E_,
                    MMtoM op_, MMtoM rop_,
                    bool need_accumulate = true) :
        E(E_), op(op_), rop(rop_) {
        assert(mat.size() > 0);
        n = mat.size(), m = mat[0].size();
        acc = vector< vector<MonoidType> >(n+2, vector<MonoidType>(m+2, E_));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                acc[i+1][j+1] = mat[i][j];
            }
        }
        if(need_accumulate) accumulate();
    }

    // [lx, rx), [ly, ry) の矩形領域に val を適用
    void range_apply(int lx, int ly, int rx, int ry, MonoidType val) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return;
        lx++, ly++; rx++; ry++;
        acc[lx][ly] = op(acc[lx][ly], val);
        acc[rx][ry] = op(acc[rx][ry], val);
        acc[lx][ry] = rop(acc[lx][ry], val);
        acc[rx][ly] = rop(acc[rx][ly], val);
    }

    // [lx, rx), [ly, ry) の矩形領域の値
    MonoidType range_val(int lx, int ly, int rx, int ry) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return E;
        MonoidType res = E;
        res = op(res, acc[lx][ly]);
        res = op(res, acc[rx][ry]);
        res = rop(res, acc[lx][ry]);
        res = rop(res, acc[rx][ly]);
        return res;
    }
};
