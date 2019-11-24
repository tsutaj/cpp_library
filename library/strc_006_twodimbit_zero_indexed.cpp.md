<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# strc\_006\_twodimbit\_zero\_indexed.cpp
---

## Code

```cpp
// 0-indexed 2次元BIT
// Verified: JOI 10 本選 Planetary Exploration
template <typename T>
struct zeroIndexedTwodimBIT{
private:
    vector< vector<T> > array;
    const int n;
    const int m;

public:
    // 初期化
    zeroIndexedTwodimBIT(int _n, int _m) : array(_n+1, vector<T>(_m+1, 0)), n(_n), m(_m) {}

    // (0, 0) から (x, y) までの累積和を求める
    T sum(int x, int y) {
        T s = 0;
        for(int i=x; i>=0; i = (i&(i+1))-1)
            for(int j=y; j>=0; j = (j&(j+1))-1)
                s += array[i][j];
        return s;
    }

    // [(x1, y1), (x2, y2)]の要素の総和
    T sum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);
    }

    // (x, y) に 要素 k を追加
    void add(int x, int y, T k) {
        for(int i=x; i<n; i |= i+1)
            for(int j=y; j<m; j |= j+1)
                array[i][j] += k;
    }
};
```

[トップページに戻る](../index.html)
