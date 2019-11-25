<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script src="../js/balloons.js"></script>
<script src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_011\_lazysegtree.cpp

## Code

```cpp
// Lazy Segment Tree (遅延評価付きセグメント木)
// 総和バージョン (0-indexed, 区間 add, 区間 sum)
// Verified: AOJ DSL_2_E: Range Add Query (RAQ)

// 最下段のサイズ (元配列のサイズより大きい 2 ベキ)
constexpr ll SIZE = 1LL << 17;

template <typename T>
struct LazySegtree {
    T node[2*SIZE], lazy[2*SIZE];

    // 初期化
    LazySegtree() {}
    LazySegtree(vector<T> v) {
        for(size_t i=0; i<v.size(); ++i) {
            node[SIZE-1+i] = v[i];
        }
        for(int i=SIZE-2; i>=0; i--) {
            node[i] = node[2*i+1] + node[2*i+2];
        }
    }

    // 遅延評価
    void lazyUpdate(int a, int b, int k) {
        int rng = b - a;
        node[k] += lazy[k] * rng;
        if(rng > 1) {
            lazy[2*k+1] += lazy[k];
            lazy[2*k+2] += lazy[k];
        }
        lazy[k] = 0;
    }

    // 範囲 [a, b) に x を足す
    void add(int a, int b, T x, int l=0, int r=SIZE, int k=0) {
        lazyUpdate(l, r, k);
        if(b <= l || r <= a) return;
        if(a <= l && r <= b) {
            lazy[k] += x;
            lazyUpdate(l, r, k);
        }
        else {
            int mid = (l + r) / 2;
            add(a, b, x, l, mid, 2*k+1);
            add(a, b, x, mid, r, 2*k+2);
            node[k] = node[2*k+1] + node[2*k+2];
        }
    }

    // 範囲 [a, b) の総和
    T sum(int a, int b, int l=0, int r=SIZE, int k=0) {
        lazyUpdate(l, r, k);
        if(b <= l || r <= a) return 0;
        if(a <= l && r <= b) return node[k];
        int mid = (l + r) / 2;
        T vl = sum(a, b, l, mid, 2*k+1);
        T vr = sum(a, b, mid, r, 2*k+2);
        return vl + vr;
    }
};
```

[トップページに戻る](../index.html)
