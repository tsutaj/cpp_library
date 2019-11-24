### 静的ウェーブレット行列 (Wavelet Matrix)

簡潔ビットベクトルにより非負整数列に対する各種クエリを高速に処理可能

| メソッド                                                                        | 説明                                                                                                                                         | 計算量               |
|---------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------|----------------------|
| `WaveletMatrix(vector<value_type> vec);`                                        | Wavelet 行列を構築                                                                                                                           | $$O(N \log \sigma)$$ |
| `value_type at(int k) const;`                                                   | 列の $$k$$ 番目にアクセス                                                                                                                    | $$O(\log \sigma)$$   |
| `value_type operator[](int k) const;`                                           | 同上                                                                                                                                         | 同上                 |
| `tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;`            | $$\left[ l, r \right)$$ の範囲内に ($$x$$ 未満、$$x$$ と等しい、$$x$$ を超える) 要素がそれぞれ何個存在するかを数える                         | $$O(\log \sigma)$$   |
| `tuple<int, int, int> rank_tuple(value_type x) const;`                          | 上の機能で範囲を限定しないもの                                                                                                               | 同上                 |
| `value_type quantile(int l, int r, value_type mi, value_type ma, int k) const;` | $$\left[ l, r \right)$$ の範囲内にある $$\left[ \mathrm{mi}, \mathrm{ma} \right]$$ 内の値のうち、$$k$$ 番目 (1-indexed) に小さい要素を答える | $$O(\log \sigma)$$   |

