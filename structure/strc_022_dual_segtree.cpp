// @category セグメント木 (Segment Tree)
// @title 双対セグメント木 (Dual Segment Tree)
// 双対セグメント木 (Dual Segment Tree)
// ref: https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/
template <typename MonoidType, typename OperatorType>
struct DualSegmentTree {
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;

    int n;
    vector<MonoidType> bottom;
    vector<OperatorType> lazy;
    OperatorType E;

    // update / lazy function
    MOtoM upd_f;
    OOtoO lzy_f;

    inline void build(const vector<MonoidType> &v) {
        int m = v.size();
        n = 1; while(n < m) n *= 2;
        bottom = v; bottom.resize(n);
        lazy.resize(n - 1, E);
    }

    DualSegmentTree() {}
    DualSegmentTree(OperatorType E_,
                    MOtoM upd_f_, OOtoO lzy_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E(E_), upd_f(upd_f_), lzy_f(lzy_f_) {
        build(v);
    }

    void update(int a, int b, OperatorType x, int l, int r, size_t k) {
        if(b <= l or r <= a) return;
        if(a <= l and r <= b) {
            if(k < lazy.size())
                lazy[k] = lzy_f(lazy[k], x);
            else
                bottom[k-n+1] = upd_f(bottom[k-n+1], x);
        }
        else {
            int mid = (l + r) >> 1;
            update(0, n, lazy[k], l, mid, 2*k+1);
            update(0, n, lazy[k], mid, r, 2*k+2);
            lazy[k] = E;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
        }
    }

    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    MonoidType query(int k) {
        MonoidType res = bottom[k];
        for(k = (k+n)>>1; k>0; k>>=1) { // 1-indexed
            res = upd_f(res, lazy[k-1]);
        }
        return res;
    }
};
