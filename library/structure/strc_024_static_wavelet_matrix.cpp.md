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


# :heavy_check_mark: Wavelet 行列 (wavelet matrix)

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_024_static_wavelet_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00


### 静的ウェーブレット行列 (Wavelet Matrix)

簡潔ビットベクトルにより非負整数列に対する各種クエリを高速に処理可能

#### Usage

* 注釈が特にないものは 0-indexed
* 変数について
  * $N$: 数列の長さ
  * $\sigma$: 値域
* **Usage、ソースコードの中身は間違っているかもしれません: 指摘があれば教えてください**

| メソッド                                                                        | 説明                                                                                                                                         | 計算量               |
|---------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------|----------------------|
| `WaveletMatrix(vec)`                                        | vector から Wavelet 行列を構築                                                                                                                           | $O(N \log \sigma)$ |
| `at(k)`                                                   | 列のインデックス $k$ 番目 (0-indexed) にアクセス                                                                                                                    | $O(\log \sigma)$   |
| `operator[](k)`                                           | 列のインデックス $k$ 番目 (0-indexed) にアクセス                                                                                                                                         | $O(\log \sigma)$                 |
| `rank_tuple(l, r, x)`            | インデックス $\left[ l, r \right)$ の範囲内に ($x$ 未満、$x$ と等しい、$x$ を超える) 要素がそれぞれいくつ存在するか答える                         | $O(\log \sigma)$   |
| `rank_tuple(x)`                          | 数列全体で ($x$ 未満、$x$ と等しい、$x$ を超える) 要素がそれぞれいくつ存在するか答える                                                                                                               | $O(\log \sigma)$                 |
| `quantile(l, r, mi, ma, k)` | インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち、$k$ 番目 (1-indexed) に小さいものを答える | $O(\log \sigma)$   |
|`quantile(l, r, k)`| インデックス $\left[ l, r \right)$ の範囲内にある要素のうち、$k$ 番目 (1-indexed) に小さいものを答える | $O(\log \sigma)$ |
|`quantile(k)`|数列全体で $k$ 番目 (1-indexed) に小さいものを答える| $O(\log \sigma)$ |
|`freq_less(l, r, m)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $m$ 未満の要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq_less(m)`|数列全体に値が $m$ 未満の要素がいくつ存在するか答える|$O(\log \sigma)$|
|`freq_greater(l, r, m)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $m$ を超える要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq_greater(m)`|数列全体に値が $m$ を超える要素がいくつ存在するか答える|$O(\log \sigma)$|
|`freq(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ と等しい要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq(mi, ma)`|数列全体に値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`min_value(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち最小値を答える| $O(\log \sigma)$|
|`min_value(l, r)`|インデックス $\left[ l, r \right)$ の範囲内にある要素のうち最小値を答える| $O(\log \sigma)$|
|`min_value()`|数列全体の要素の最小値を答える| $O(\log \sigma)$|
|`max_value(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち最大値を答える| $O(\log \sigma)$|
|`max_value(l, r)`|インデックス $\left[ l, r \right)$ の範囲内にある要素のうち最大値を答える| $O(\log \sigma)$|
|`max_value()`|数列全体の要素の最大値を答える| $O(\log \sigma)$|
|`select(l, r, k, x)`|インデックス $\left[ l, r \right)$ の範囲内にある $x$ と等しい要素のうち $k$ 番目 (1-indexed) にある値のインデックスを答える| $O(\log \sigma \log N)$ |
|`select(k, x)`|数列全体で $x$ と等しい要素のうち $k$ 番目 (1-indexed) にある値のインデックスを答える| $O(\log \sigma \log N)$ |
|`next_val(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ を超える要素の中で最小のものを答える| $O(\log \sigma \log N)$ |
|`prev_val(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ 未満の要素の中で最小のものを答える| $O(\log \sigma \log N)$ |


## Depends on

* :heavy_check_mark: <a href="strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>


## Required by

* :warning: <a href="verify/verify_strc_024_static_wavelet_matrix.cpp.html">structure/verify/verify_strc_024_static_wavelet_matrix.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp.html">$\left\[ l, r \right\]$ にある整数の中で $D$ に最も近いものを求める <small>(verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp)</small></a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp.html">矩形 $x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$ 内に属する点の個数を求める <small>(verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp)</small></a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_less.test.cpp.html">AOJ ALDS_1_5_D: 反転数 (01)</a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_more.test.cpp.html">AOJ ALDS_1_5_D: 反転数 (02)</a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp.html">ソートを行う (小さいものから $k$ 番目を求められることを利用) <small>(verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp)</small></a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp.html">連続部分列中の最小の要素を答える <small>(verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp)</small></a>
* :heavy_check_mark: <a href="../../verify/verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp.html">与えられた数列を逆順に出力 <small>(verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// @title Wavelet 行列 (wavelet matrix)
#define DOCS "./docs/strc_024_static_wavelet_matrix.md"
#define REQUIRES "./strc_023_compact_bitvector.cpp"
#undef REQUIRES

// ウェーブレット行列 (Wavelet Matrix)
// w は ビット幅, 30 bit で表現できる整数なら 30
template <uint64_t word_size = 30, typename value_type = int,
          uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct WaveletMatrix {
private:
    using BitVector = CompactBitVector<value_type, ln_big, ln_sml>;
    array<BitVector, word_size> vecs;

    // 要素数
    int n;
    // k ビット目を基準に安定ソート
    vector<value_type> sort_kth_bit(const vector<value_type>& vec, int k) const;

    // [l, r) の範囲内にある x と等しい要素は最下段のどの範囲に相当？
    // select するときに利用
    pair<int, int> rank_range(int l, int r, value_type x) const;    

public:
    // クエリは特に注釈がない限り 0-indexed
    // 構築: O(N w)
    WaveletMatrix(vector<value_type> vec);

    // k 番目の値を復元: O(w)
    // <verified> ITP1_6_A (Reversing Numbers)
    value_type at(int k) const;
    value_type operator[](int k) const;

    // [l, r) の範囲内に以下が何個存在するか: O(w)
    // ・x より小さい要素
    // ・x と等しい要素
    // ・x より大きい要素
    tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;
    tuple<int, int, int> rank_tuple(value_type x) const;
    
    // [l, r) の範囲内で k 番目 (1-indexed) に小さい要素が何か: O(w)
    // <verified> AOJ ALDS1_6_A (Count Sort)
    value_type quantile(int l, int r, value_type mi, value_type ma, int k) const;
    value_type quantile(int l, int r, int k) const;
    value_type quantile(int k) const;

    // [l, r) の範囲内の m 未満 / m を超える 要素はいくつか: O(w)
    // <verified> AOJ ALDS1_5_D (The Number of Inversions)
    int freq_less(int l, int r, value_type m) const;
    int freq_less(value_type m) const;
    int freq_greater(int l, int r, value_type m) const;
    int freq_greater(value_type m) const;
    
    // [l, r) の範囲内に x \in [mi, ma] を満たす x がいくつ出てきたか: O(w)
    // [mi, ma] は閉区間！！
    // <verified> AOJ 1549 (Hard Beans)
    // <verified> AOJ 2426 (Treasure Hunt)
    int freq(int l, int r, value_type mi, value_type ma) const;
    int freq(int l, int r, value_type x) const;
    int freq(value_type mi, value_type ma) const;
    
    // [l, r) の範囲内にある要素の最小値 (quantile 再利用): O(w)
    // <verified> AOJ DSL_3_D (Sliding Minimum Elements)
    value_type min_value(int l, int r, value_type mi, value_type ma) const;
    value_type min_value(int l, int r) const;
    value_type min_value() const;

    // [l, r) の範囲内にある要素の最大値 (quantile 再利用): O(w)
    value_type max_value(int l, int r, value_type mi, value_type ma) const;
    value_type max_value(int l, int r) const;
    value_type max_value() const;

    // [l, r) の範囲内にある k 番目 (1-indexed) の x の位置: O(w log N)
    int select(int l, int r, int k, value_type x) const;
    int select(int k, value_type x) const;

    // k 番目の要素と値が等しいもので、k 番目の直後 / 直前の要素 idx: O(w log N)
    int next_idx(int k) const;
    int prev_idx(int k) const;

    // [l, r) の範囲内にある、x 未満 / x を超える要素のうち 最大 / 最小 であるもの: O(w)
    // <verified> AOJ 1549 (Hard Beans)
    value_type next_val(int l, int r, value_type x) const;
    value_type prev_val(int l, int r, value_type x) const;
};

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
vector<value_type> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::sort_kth_bit(const vector<value_type>& vec, int k) const {
    vector<value_type> v0, v1;
    v0.reserve(vec.size()), v1.reserve(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);
    }
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
pair<int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_range(int l, int r, value_type x) const {
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return make_pair(l, r);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
WaveletMatrix<word_size, value_type, ln_big, ln_sml>::WaveletMatrix(vector<value_type> vec) : n(vec.size()) {
    vecs[0] = BitVector(vec, word_size - 1);
    for(size_t i=1; i<word_size; i++) {
        vec = sort_kth_bit(vec, word_size - i);
        vecs[i] = BitVector(vec, word_size - i - 1);
    }
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::at(int k) const {
    int b = k; value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(b), cnt0 = b + 1 - cnt1;
        if(vecs[i][b] == 1) {
            res |= (1ULL << (word_size - 1 - i));
            b = all0 + cnt1 - 1;
        }
        else {
            b = cnt0 - 1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::operator[](int k) const {
    return at(k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(int l, int r, value_type x) const {
    int small = 0, equal = 0, big = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            small += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            big += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    equal = r - l;
    return make_tuple(small, equal, big);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(value_type x) const {
    return rank_tuple(0, n, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, value_type mi, value_type ma, int k) const {
    int cnt_less = freq_less(l, r, mi), cnt_greater = freq_greater(l, r, ma);
    if(r - l - cnt_less - cnt_greater < k) return -1;
    return quantile(l, r, k + cnt_less);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, int k) const {
    if(r - l < k) return -1;
    value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(cnt0 >= k) {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
        else {
            k -= cnt0;
            res |= 1ULL << (word_size - 1 - i);
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int k) const {
    return quantile(0, n, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            res += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(value_type m) const {
    return freq_less(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            res += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(value_type m) const {
    return freq_greater(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type mi, value_type ma) const {
    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type x) const {
    return freq(l, r, x, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(value_type mi, value_type ma) const {
    return freq(0, n, mi, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r) const {
    return quantile(l, r, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value() const {
    return min_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, freq(l, r, mi, ma));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r) const {
    return quantile(l, r, r - l);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value() const {
    return max_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int l, int r, int k, value_type x) const {
    if(k <= 0) return -1;
    tie(l, r) = rank_range(l, r, x);
    if(r - l < k) return -1;

    int pos = l + k - 1;
    for(size_t i=0; i<word_size; i++) {
        int b = x >> i & 1;
        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;
        if(b == 0) {
            int m = pos;
            pos = vecs[word_size - 1 - i].select0(m, n);
        }
        else {
            int m = pos - cnt0;
            pos = vecs[word_size - 1 - i].select1(m, n);
        }
    }
    return pos;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int k, value_type x) const {
    return select(0, n, k, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m+1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m-1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_val(int l, int r, value_type x) const {
    int k = r - l - freq_greater(l, r, x) + 1;
    return quantile(l, r, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_val(int l, int r, value_type x) const {
    return quantile(l, r, freq_less(l, r, x));
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/strc_024_static_wavelet_matrix.cpp"
// @title Wavelet 行列 (wavelet matrix)
#define DOCS "./docs/strc_024_static_wavelet_matrix.md"
#define REQUIRES "./strc_023_compact_bitvector.cpp"
#undef REQUIRES

// ウェーブレット行列 (Wavelet Matrix)
// w は ビット幅, 30 bit で表現できる整数なら 30
template <uint64_t word_size = 30, typename value_type = int,
          uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct WaveletMatrix {
private:
    using BitVector = CompactBitVector<value_type, ln_big, ln_sml>;
    array<BitVector, word_size> vecs;

    // 要素数
    int n;
    // k ビット目を基準に安定ソート
    vector<value_type> sort_kth_bit(const vector<value_type>& vec, int k) const;

    // [l, r) の範囲内にある x と等しい要素は最下段のどの範囲に相当？
    // select するときに利用
    pair<int, int> rank_range(int l, int r, value_type x) const;    

public:
    // クエリは特に注釈がない限り 0-indexed
    // 構築: O(N w)
    WaveletMatrix(vector<value_type> vec);

    // k 番目の値を復元: O(w)
    // <verified> ITP1_6_A (Reversing Numbers)
    value_type at(int k) const;
    value_type operator[](int k) const;

    // [l, r) の範囲内に以下が何個存在するか: O(w)
    // ・x より小さい要素
    // ・x と等しい要素
    // ・x より大きい要素
    tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;
    tuple<int, int, int> rank_tuple(value_type x) const;
    
    // [l, r) の範囲内で k 番目 (1-indexed) に小さい要素が何か: O(w)
    // <verified> AOJ ALDS1_6_A (Count Sort)
    value_type quantile(int l, int r, value_type mi, value_type ma, int k) const;
    value_type quantile(int l, int r, int k) const;
    value_type quantile(int k) const;

    // [l, r) の範囲内の m 未満 / m を超える 要素はいくつか: O(w)
    // <verified> AOJ ALDS1_5_D (The Number of Inversions)
    int freq_less(int l, int r, value_type m) const;
    int freq_less(value_type m) const;
    int freq_greater(int l, int r, value_type m) const;
    int freq_greater(value_type m) const;
    
    // [l, r) の範囲内に x \in [mi, ma] を満たす x がいくつ出てきたか: O(w)
    // [mi, ma] は閉区間！！
    // <verified> AOJ 1549 (Hard Beans)
    // <verified> AOJ 2426 (Treasure Hunt)
    int freq(int l, int r, value_type mi, value_type ma) const;
    int freq(int l, int r, value_type x) const;
    int freq(value_type mi, value_type ma) const;
    
    // [l, r) の範囲内にある要素の最小値 (quantile 再利用): O(w)
    // <verified> AOJ DSL_3_D (Sliding Minimum Elements)
    value_type min_value(int l, int r, value_type mi, value_type ma) const;
    value_type min_value(int l, int r) const;
    value_type min_value() const;

    // [l, r) の範囲内にある要素の最大値 (quantile 再利用): O(w)
    value_type max_value(int l, int r, value_type mi, value_type ma) const;
    value_type max_value(int l, int r) const;
    value_type max_value() const;

    // [l, r) の範囲内にある k 番目 (1-indexed) の x の位置: O(w log N)
    int select(int l, int r, int k, value_type x) const;
    int select(int k, value_type x) const;

    // k 番目の要素と値が等しいもので、k 番目の直後 / 直前の要素 idx: O(w log N)
    int next_idx(int k) const;
    int prev_idx(int k) const;

    // [l, r) の範囲内にある、x 未満 / x を超える要素のうち 最大 / 最小 であるもの: O(w)
    // <verified> AOJ 1549 (Hard Beans)
    value_type next_val(int l, int r, value_type x) const;
    value_type prev_val(int l, int r, value_type x) const;
};

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
vector<value_type> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::sort_kth_bit(const vector<value_type>& vec, int k) const {
    vector<value_type> v0, v1;
    v0.reserve(vec.size()), v1.reserve(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);
    }
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
pair<int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_range(int l, int r, value_type x) const {
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return make_pair(l, r);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
WaveletMatrix<word_size, value_type, ln_big, ln_sml>::WaveletMatrix(vector<value_type> vec) : n(vec.size()) {
    vecs[0] = BitVector(vec, word_size - 1);
    for(size_t i=1; i<word_size; i++) {
        vec = sort_kth_bit(vec, word_size - i);
        vecs[i] = BitVector(vec, word_size - i - 1);
    }
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::at(int k) const {
    int b = k; value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(b), cnt0 = b + 1 - cnt1;
        if(vecs[i][b] == 1) {
            res |= (1ULL << (word_size - 1 - i));
            b = all0 + cnt1 - 1;
        }
        else {
            b = cnt0 - 1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::operator[](int k) const {
    return at(k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(int l, int r, value_type x) const {
    int small = 0, equal = 0, big = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            small += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            big += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    equal = r - l;
    return make_tuple(small, equal, big);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(value_type x) const {
    return rank_tuple(0, n, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, value_type mi, value_type ma, int k) const {
    int cnt_less = freq_less(l, r, mi), cnt_greater = freq_greater(l, r, ma);
    if(r - l - cnt_less - cnt_greater < k) return -1;
    return quantile(l, r, k + cnt_less);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, int k) const {
    if(r - l < k) return -1;
    value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(cnt0 >= k) {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
        else {
            k -= cnt0;
            res |= 1ULL << (word_size - 1 - i);
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int k) const {
    return quantile(0, n, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            res += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(value_type m) const {
    return freq_less(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            res += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(value_type m) const {
    return freq_greater(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type mi, value_type ma) const {
    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type x) const {
    return freq(l, r, x, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(value_type mi, value_type ma) const {
    return freq(0, n, mi, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r) const {
    return quantile(l, r, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value() const {
    return min_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, freq(l, r, mi, ma));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r) const {
    return quantile(l, r, r - l);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value() const {
    return max_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int l, int r, int k, value_type x) const {
    if(k <= 0) return -1;
    tie(l, r) = rank_range(l, r, x);
    if(r - l < k) return -1;

    int pos = l + k - 1;
    for(size_t i=0; i<word_size; i++) {
        int b = x >> i & 1;
        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;
        if(b == 0) {
            int m = pos;
            pos = vecs[word_size - 1 - i].select0(m, n);
        }
        else {
            int m = pos - cnt0;
            pos = vecs[word_size - 1 - i].select1(m, n);
        }
    }
    return pos;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int k, value_type x) const {
    return select(0, n, k, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m+1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m-1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_val(int l, int r, value_type x) const {
    int k = r - l - freq_greater(l, r, x) + 1;
    return quantile(l, r, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_val(int l, int r, value_type x) const {
    return quantile(l, r, freq_less(l, r, x));
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

