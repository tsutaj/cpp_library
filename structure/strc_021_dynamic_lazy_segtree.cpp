// @category セグメント木 (Segment Tree)
// @title 動的遅延セグメント木 (Dynamic Lazy Segment Tree)
// 動的遅延セグメント木 (必要なところだけノードを作る)

template <typename MonoidType, typename OperatorType>
struct LazySegNode {
    MonoidType value;
    OperatorType lazy_value;
    bool need_update;
    LazySegNode *ch[2];
    
    LazySegNode() {}
    LazySegNode(MonoidType value_, OperatorType lazy_value_) :
        value(value_), lazy_value(lazy_value_) {
        need_update = false;
        ch[0] = ch[1] = nullptr;
    }
};

template <typename MonoidType, typename OperatorType, typename IdxType = int>
struct DynamicLazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;
    using LNode = LazySegNode<MonoidType, OperatorType>;

    // node, identity element
    IdxType n;
    LNode *root;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    DynamicLazySegmentTree() {}
    DynamicLazySegmentTree(IdxType n_, MonoidType E0_, OperatorType E1_,
                           MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        root = new LNode(E0_, E1_);
        n = 1; while(n < n_) n *= 2;
    }

    void eval(LNode *node, IdxType l, IdxType r) {
        if(!node->need_update) return;
        node->value = upd_f(node->value, acc_f(node->lazy_value, r - l));
        if(r - l > 1) {
            if(!node->ch[0]) node->ch[0] = new LNode(E0, E1);
            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);
            node->ch[0]->lazy_value = lzy_f(node->ch[0]->lazy_value, node->lazy_value);
            node->ch[1]->lazy_value = lzy_f(node->ch[1]->lazy_value, node->lazy_value);
            node->ch[0]->need_update = node->ch[1]->need_update = true;
        }
        node->lazy_value = E1;
        node->need_update = false;
    }

    void update(LNode *node, IdxType a, IdxType b, OperatorType x,
                IdxType l, IdxType r) {
        eval(node, l, r);
        if(b <= l or r <= a) return;
        if(a <= l and r <= b) {
            node->lazy_value = lzy_f(node->lazy_value, x);
            node->need_update = true;
            eval(node, l, r);
        }
        else {
            IdxType mid = (l + r) / 2;
            if(!node->ch[0]) node->ch[0] = new LNode(E0, E1);
            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);
            update(node->ch[0], a, b, x, l, mid);
            update(node->ch[1], a, b, x, mid, r);
            node->value = cmb_f(node->ch[0]->value, node->ch[1]->value);
        }
    }

    MonoidType query(LNode *node, IdxType a, IdxType b, IdxType l, IdxType r) {
        if(b <= l or r <= a) return E0;
        eval(node, l, r);
        if(a <= l and r <= b) return node->value;
        IdxType mid = (l + r) / 2;
        MonoidType vl = (node->ch[0] ? query(node->ch[0], a, b, l, mid) : E0);
        MonoidType vr = (node->ch[1] ? query(node->ch[1], a, b, mid, r) : E0);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value: x)
    void update(IdxType a, IdxType b, OperatorType x) {
        update(root, a, b, x, 0, n);
    }

    // range query for [a, b)
    MonoidType query(IdxType a, IdxType b) {
        return query(root, a, b, 0, n);
    }
};
