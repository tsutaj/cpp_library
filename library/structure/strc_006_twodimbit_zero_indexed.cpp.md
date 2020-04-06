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


# :warning: structure/strc_006_twodimbit_zero_indexed.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_006_twodimbit_zero_indexed.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/strc_006_twodimbit_zero_indexed.cpp"
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

