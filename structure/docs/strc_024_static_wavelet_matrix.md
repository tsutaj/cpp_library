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
