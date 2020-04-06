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


# :warning: structure/strc_005_bit_zero_indexed.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_005_bit_zero_indexed.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/strc_005_bit_zero_indexed.cpp"
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

