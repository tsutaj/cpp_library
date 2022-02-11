## Summary

グラフ $G$ の接続行列 $B \in \mathbb{R}^{V \times E}$ とは、頂点を行に・辺を列に対応させ、グラフの接続関係を要素で表したような行列である。有向・無向どちらでも定義できる。

接続行列を係数に持つ線形方程式は線形時間 $O( \lvert V \rvert + \lvert E \rvert )$ で解ける。方針としては、全域木を作って葉から値を決定していく。途中で矛盾するような結果になれば解なし。

詳しくは下記資料を参考のこと。なお、問題によっては $\bmod 2$ で解を求めることを要求されるが、`ModInt<2>` 型で与えれば問題ないと思う。

## Reference

- [「接続行列を係数にもつ線型方程式」の競プロでの応用](https://drive.google.com/file/d/1GYxjvoEIn_j9i9AEWP5zQ4yyCQCLysrn/view) (opt さん)