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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../algorithm/algo_002_accumulation.cpp
* category: ../../algorithm


[Back to top page](../../index.html)



## Required
* :warning: [../../algorithm/verify/verify_algo_002_accumulation.cpp](verify/verify_algo_002_accumulation.cpp.html)


## Code
```cpp
// 累積演算 (0-indexed・prefix, suffix, 任意連続部分列)
// 任意連続部分列は逆演算があるときのみできる？

template <typename MonoidType>
struct Accumulation {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void build(int m, vector<MonoidType> vec) {
        pre = suf = vector<MonoidType>(m+1, E);
        for(int i=0; i<m; i++) {
            pre[i+1] = op(pre[i], vec[i]);
        }
        for(int i=m-1; i>=0; i--) {
            suf[i] = op(suf[i+1], vec[i]);
        }
    }

    Accumulation() {}
    Accumulation(vector<MonoidType> val_array, MonoidType E_,
                 MMtoM op_, MMtoM rop_ = MMtoM()) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        build(n, val_array);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k and k <= n ? suf[k] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};

```

[Back to top page](../../index.html)

