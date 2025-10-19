---
title: Trace（経路復元）
documentation_of: ./marathon/trace.cpp
---

- `add(value, id)`
  - 採用した値 `value` と直前の状態の識別子 `id` を与えて、状態を追加する
  - 追加した状態の識別子が返ってくる
- `get(id)`
  - 状態の識別子 `id` を与えると、初期状態からここに至るまでの経路を復元したものが返ってくる
