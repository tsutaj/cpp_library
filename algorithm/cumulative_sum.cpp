#pragma once

/**
 * @brief 1 次元累積和 (1 Dimension Cumulative Sum)
 * @docs ./docs/cumulative_sum.md
 */

#include <functional>
#include <vector>
template <typename MonoidType>
struct CumulativeSum {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void accumulate() {
        int m = pre.size();
        for(int i=0; i+1<m; i++) {
            pre[i+1] = op(pre[i+1], pre[i]);
        }
        for(int i=m-2; i>=0; i--) {
            suf[i] = op(suf[i], suf[i+1]);
        }
    }

    CumulativeSum() {}
    CumulativeSum(vector<MonoidType> val_array, MonoidType E_,
                  MMtoM op_, MMtoM rop_ = MMtoM(),
                  bool need_accumulate = true) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        pre = suf = vector<MonoidType>(n+2, E);
        for(int i=0; i<n; i++) pre[i+1] = suf[i+1] = val_array[i];
        if(need_accumulate) accumulate();
    }

    void range_apply(int l, int r, MonoidType val) {
        pre[l+1] = op(pre[l+1], val);
        pre[r+1] = rop(pre[r+1], val);
        suf[r] = op(suf[r], val);
        suf[l] = rop(suf[l], val);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k+1 and k+1 <= n ? suf[k+1] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};
