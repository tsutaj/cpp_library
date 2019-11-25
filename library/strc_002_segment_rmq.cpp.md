<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_002\_segment\_rmq.cpp

## Code

```cpp
// Range Minimum Query (区間最小クエリ、RMQ)
// Verified: AOJ DSL_2_A: Range Minimum Query (int型のみ)

template <typename T>
class rmq {
public:
    int n;
    vector<T> dat;

    // 要素数 m の RMQ を作る
    rmq(int m) {
        n = 1;
        while(n < m) n *= 2;
        dat.resize(2*n-1);
        rep(i,0,2*n-1) dat[i] = INT_MAX;
    }

    // k番目 (0-indexed) の値を a に更新
    void update(int k, T a) {
        k += n - 1;
        dat[k] = a;
        while(k > 0) {
            k = (k - 1) / 2;
            dat[k] = min(dat[k*2+1], dat[k*2+2]);
        }
    }

    // [a, b) の最小値を返す
    // 最初に呼び出すときは XX.query(a, b, 0, 0, -1) とする
    T query(int a, int b, int k, int l, int r) {
        if(r == -1) r = n;
        if(r <= a || b <= l) return INT_MAX;
        if(a <= l && r <= b) return dat[k];
        else {
            T vl = query(a, b, k*2+1, l, (l+r)/2);
            T vr = query(a, b, k*2+2, (l+r)/2, r);
            return min(vl, vr);
        }
    }
};
```

[トップページに戻る](../index.html)
