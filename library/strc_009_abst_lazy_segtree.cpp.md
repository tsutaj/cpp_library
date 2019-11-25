<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_009\_abst\_lazy\_segtree.cpp

## Code

```cpp
template <typename MonoidType, typename OperatorType>
struct LazySegmentTree {
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    using OOtoO = function< OperatorType(OperatorType, OperatorType) >;
    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;
    using OItoO = function< OperatorType(OperatorType, int) >;

    // node, lazy, update flag (for lazy), identity element
    int n;
    vector<MonoidType> node;
    vector<OperatorType> lazy;
    vector<bool> need_update;
    MonoidType E0;
    OperatorType E1;

    // update / combine / lazy / accumulate function
    MOtoM upd_f;
    MMtoM cmb_f;
    OOtoO lzy_f;
    OItoO acc_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        lazy = vector<OperatorType>(2*n-1, E1);
        need_update = vector<bool>(2*n-1, false);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    LazySegmentTree() {}
    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,
                    MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,
                    vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), E1(E1_),
        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {
        build(n_, v);
    }

    void eval(int k, int l, int r) {
        if(!need_update[k]) return;
        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));
        if(r - l > 1) {
            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);
            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);
            need_update[2*k+1] = need_update[2*k+2] = true;
        }
        lazy[k] = E1;
        need_update[k] = false;
    }

    void update(int a, int b, OperatorType x, int l, int r, int k) {
        eval(k, l, r);
        if(b <= l or  r <= a) return;
        if(a <= l and r <= b) {
            lazy[k] = lzy_f(lazy[k], x);
            need_update[k] = true;
            eval(k, l, r);
        }
        else {
            int mid = (l + r) / 2;
            update(a, b, x, l, mid, 2*k+1);
            update(a, b, x, mid, r, 2*k+2);
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    MonoidType query(int a, int b, int l, int r, int k) {
        if(b <= l or  r <= a) return E0;
        eval(k, l, r);
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) / 2;
        MonoidType vl = query(a, b, l, mid, 2*k+1);
        MonoidType vr = query(a, b, mid, r, 2*k+2);
        return cmb_f(vl, vr);
    }

    // update [a, b)-th element (applied value, x)
    void update(int a, int b, OperatorType x) {
        update(a, b, x, 0, n, 0);
    }

    // range query for [a, b)
    MonoidType query(int a, int b) {
        return query(a, b, 0, n, 0);
    }

    void dump() {
        fprintf(stderr, "[lazy]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(lazy[i] == E1) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", lazy[i]);
        }
        fprintf(stderr, "\n");

        fprintf(stderr, "[node]\n");
        for(int i=0; i<2*n-1; i++) {
            if(i == n-1) fprintf(stderr, "xxx ");
            if(node[i] == E0) fprintf(stderr, "  E ");
            else fprintf(stderr, "%3d ", node[i]);
        }
        fprintf(stderr, "\n");
    }
};

```

[トップページに戻る](../index.html)
