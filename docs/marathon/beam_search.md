---
title: ビームサーチ
documentation_of: ./marathon/beam_search.cpp
---

- `BeamSearch` と `BeamSearchWithHash` の 2 種類が利用可能
    - 重複した状態を除去したいときは `BeamSearchWithHash` を使う。そうでないときは `BeamSearch` を使う。
    - `BeamSearch` だと $\log$ が落ちるはずなので、こっちのほうがイテレーションは回る
- 状態 `BeamSearchState` と、軽量化した状態 `LiteBeamSearchState` の両方を定義して使う
    - 軽量化した状態は、参照する `BeamSearchState` のインデックス +α の情報を持たせる
    - 両方ともスコア計算の実装が必須
- 以下の 2 つの関数を定義してビームサーチを実行する
    - `add_next_lite_states`: 状態を受けとり、次の状態を軽量化したものを返す関数
    - `to_next_state`: 軽量化した状態を受けとり、それを元の (軽量化していない) 状態に変換する関数

AHC040 で使用実績あり。  
[https://atcoder.jp/contests/ahc040/submissions/61300845](https://atcoder.jp/contests/ahc040/submissions/61300845)
