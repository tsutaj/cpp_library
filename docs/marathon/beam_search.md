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
- 以下の関数を定義する
    - `add_next_lite_states`: 状態を受けとり、次の状態を軽量化したものを返す関数
    - `to_next_state`: 軽量化した状態を受けとり、それを元の (軽量化していない) 状態に変換する関数
- 概ね次のようにしてビームサーチをする
  - 初期状態を登録
  - ターン数だけ次を繰り返す
    - 最初のターン以外: `reconstruct_states` で、軽量化した状態を元の状態に変換
    - `add_lite_states` で、軽量化した状態を登録
      - どのターンに対しても登録可能

AHC049 で使用実績あり。  
[https://atcoder.jp/contests/ahc049/submissions/67053066](https://atcoder.jp/contests/ahc049/submissions/67053066)
