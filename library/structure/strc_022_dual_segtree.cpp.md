---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
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
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: structure/strc_022_dual_segtree.cpp
* category: structure


[Back to top page](../../index.html)



## Required
* :warning: [structure/verify/verify_strc_022_dual_segtree.cpp](verify/verify_strc_022_dual_segtree.cpp.html)


## Code
{% raw %}
```cpp
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

```
{% endraw %}

[Back to top page](../../index.html)

