[トップページに戻る](../index.html)

# strc\_002\_segment\_rmq.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

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
};```

[トップページに戻る](../index.html)
