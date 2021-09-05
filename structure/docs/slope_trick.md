---
title: Slope Trick
documentation_of: ../slope_trick.cpp
---

## 概要

- 下に凸であるような区分線形凸関数 $F: \mathrm{Tp} \rightarrow \mathrm{Tp}$ の傾きが変化する点を管理する
  - 定義域と値域はとりあえず同じ型にしている (不都合があったら変えるかも)
- 区分線形凸関数であるという制約を満たしつつ関数を変化させる処理や、関数の最小値を求める処理などが高速に行える

## 使用方法

### 初期化

- `SlopeTrick(Tp minF = 0)`
  - 定数関数 $F(x) = \mathrm{minF}$ を用意
  - デフォルトの挙動について: 単に `SlopeTrick()` と呼ぶ場合は $F(x) = 0$ となる
  - Time Complexity: $O(1)$

```cpp
// $F(x) = 0$ である関数からスタートする例
SlopeTrick slope;
```

### 関数に変化を加える
- `void addConstFunc(Tp a)`
  - 定数関数 $a$ を加算
  - Time Complexity: $O(1)$
- `void addIncreasingFunc(Tp a)`
  - $f(x) = (x - a)_{+} = \max \left( 0, x - a \right)$ を加算
  - Time Complexity: $O(\log N)$
- `void addDecreasingFunc(Tp a)`
  - $f(x) = (a - x)_{+} = \max \left( 0, a - x \right)$ を加算
  - Time Complexity: $O(\log N)$
- `void addAbsFunc(Tp a)`
  - $f(x) = \left| x - a \right| = (x - a)_{+} + (a - x)_{+}$を加算
  - Time Complexity: $O(\log N)$
- `void cumulateLeft()`
  - 左側累積 min を取る。すなわち、持つ関数を $G(x) = \min_{y \leq x} F(y)$ を満たすような $G(x)$ に変化させる
  - Time Complexity: $O(1)$
- `void cumulateRight()`
  - 右側累積 min を取る。すなわち、持つ関数を $G(x) = \min_{y \geq x} F(y)$ を満たすような $G(x)$ に変化させる
  - Time Complexity: $O(1)$
- `void applyTranslation(Tp a)`
  - 平行移動をする。すなわち $G(x) = F(x - a)$ のように更新する
  - Time Complexity: $O(1)$
- `void applySlidingWindow(Tp a, Tp b)`
  - スライド最小値を取る。すなわち $G(x) = \min_{y \in [x-b, x-a]} F(y)$ のように更新
  - Time Complexity: $O(1)$

### 関数の値を求める  

- `Tp getMinVal()`
  - 関数の最小値を返す
  - Time Complexity: $O(1)$
- `Tp getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty)`
  - 関数の値が最小となるような $x$ の範囲 $\left[ \mathrm{lb}, \mathrm{ub} \right]$ を求める
  - $x$ の範囲の下限が $-\infty$ であるとき、かつそのときに限り `isLbInfty = true` となり、`lb` の値は不定
  - $x$ の範囲の上限が $\infty$ であるとき、かつそのときに限り `isUbInfty = true` となり、`ub` の値は不定

## 参考文献

- [maspy](https://twitter.com/maspy_stars) さんによる記事
  - [Slope Trick (1) 解説編](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
  - [Slope Trick (2) 問題編](https://maspypy.com/slope-trick-2-%e5%95%8f%e9%a1%8c%e7%b7%a8)