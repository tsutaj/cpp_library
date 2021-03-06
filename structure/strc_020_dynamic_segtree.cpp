// @category セグメント木 (Segment Tree)
// @title 動的セグメント木 (Dynamic Segment Tree)
// 動的セグメント木 (必要なノードだけ作る)

template <typename MonoidType>
struct SegNode {
    MonoidType value;
    SegNode *ch[2];
    SegNode() {}
    SegNode(MonoidType value_) : value(value_) {
        ch[0] = ch[1] = nullptr;
    }
};

template <typename MonoidType, typename IdxType = int>
struct DynamicSegmentTree {
    using Function = function< MonoidType(MonoidType, MonoidType) >;

    // node, identity element
    IdxType n;
    SegNode<MonoidType> *root;
    MonoidType E0;

    // update / combine function
    Function upd_f, cmb_f;

    // initialize
    DynamicSegmentTree() {
        root = new SegNode<MonoidType>;
    }
    DynamicSegmentTree(IdxType n_, MonoidType E0_,
                       Function upd_f_, Function cmb_f_) :
        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {
        root = new SegNode<MonoidType>(E0_);
        n = 1; while(n < n_) n *= 2;
    }

    void update(SegNode<MonoidType> *node, IdxType k, MonoidType x, IdxType l, IdxType r) {
        if(r - l == 1) {
            node->value = upd_f(node->value, x);
            return;
        }

        IdxType mid = (l + r) / 2;
        MonoidType vl = E0, vr = E0;
        if(l <= k and k < mid) {
            if(!node->ch[0]) node->ch[0] = new SegNode<MonoidType>(E0);
            update(node->ch[0], k, x, l, mid);
        }
        if(mid <= k and k < r) {
            if(!node->ch[1]) node->ch[1] = new SegNode<MonoidType>(E0);
            update(node->ch[1], k, x, mid, r);
        }
        vl = (node->ch[0] ? node->ch[0]->value : E0);
        vr = (node->ch[1] ? node->ch[1]->value : E0);
        node->value = cmb_f(vl, vr);
    }

    MonoidType query(SegNode<MonoidType> *node, IdxType a, IdxType b, IdxType l, IdxType r) {
        if(b <= l or r <= a) return E0;
        if(a <= l and r <= b) return node->value;

        IdxType mid = (l + r) / 2;
        MonoidType vl = (node->ch[0] ? query(node->ch[0], a, b, l, mid) : E0);
        MonoidType vr = (node->ch[1] ? query(node->ch[1], a, b, mid, r) : E0);
        return cmb_f(vl, vr);
    }
    
    // update k-th element (applied value: x)
    void update(IdxType k, MonoidType x) {
        update(root, k, x, 0, n);
    }

    // range query for [a, b)
    MonoidType query(IdxType a, IdxType b) {
        return query(root, a, b, 0, n);
    }
};
