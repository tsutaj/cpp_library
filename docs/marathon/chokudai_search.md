---
title: chokudai サーチ
documentation_of: ./marathon/chokudai_search.cpp
---

- `add_next_states` で状態遷移を定義する
    - 状態およびそのターン数が与えられるので、次の状態およびそのターン数を決定し、 `register_state` を使って状態を登録
- メモリ制約に引っかからないように、各ターンで持つ状態数に上限を設けることが可能
    - `set_max_num_states` で設定する
    - Interval Heap を使って、あふれた状態を消している

AHC032 で利用実績あり。  
[https://atcoder.jp/contests/ahc032/submissions/61302590](https://atcoder.jp/contests/ahc032/submissions/61302590)
