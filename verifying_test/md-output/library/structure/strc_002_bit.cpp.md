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


# :warning: ../../structure/strc_002_bit.cpp
* category: ../../structure


[Back to top page](../../index.html)



## Required
* :warning: [../../structure/verify/verify_strc_004_bit_sec.cpp](verify/verify_strc_004_bit_sec.cpp.html)


## Code
```cpp
// Binary Indexed Tree (BIT)
// Verified: AOJ DSL_2_B: Range Sum Query (intのみ)

template <typename T>
struct BIT{
private:
    vector<T> array;
    int n;

public:
    // 初期化
    BIT() {}
    BIT(int _n) : array(_n + 1, 0), n(_n) {}

    // 1番目から i番目までの累積和を求める
    T sum(int i) {
        T s = 0;
        while(i > 0) {
            s += array[i];
            i -= i & -i;      // LSB 減算
        }
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
        while(i <= n) {
            array[i] += x;
            i += i & -i;      // LSB 加算
        }
    }
};

```

[Back to top page](../../index.html)

