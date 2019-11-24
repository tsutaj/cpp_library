<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: strc\_005\_bit\_zero\_indexed.cpp
---

## Code

```cpp
// 0-indexed Binary Indexed Tree (BIT)
// Verified: AOJ DSL_2_B: Range Sum Query (intのみ)

template <typename T>
struct zeroIndexedBIT{
private:
    vector<T> array;
    int n;

public:
    // 初期化 (適当)
    zeroIndexedBIT() : array(10, 0), n(10) {}
    zeroIndexedBIT(int _n) : array(_n, 0), n(_n) {}

    // 他のクラスで BIT を呼び出すときに便利なので作った
    void resize(int _n) {
        array.resize(_n);
        n = _n;
    }

    // 0番目から i番目までの累積和を求める
    T sum(int i) {
        T s = 0;
        for(int k=i; k>=0; k = (k&(k+1)) - 1) s += array[k];
        return s;
    }

    // [i, j] の要素の総和
    T sum(int i, int j) {
        T ret_i = sum(i-1);
        T ret_j = sum(j);
        return ret_j - ret_i;
    }

    // i 番目に 要素 x を追加
    void add(int i, T x) {
        for(int k=i; k<n; k |= k+1) array[k] += x;
    }
};
```

[トップページに戻る](../index.html)
