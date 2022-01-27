---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
    title: verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
  - icon: ':x:'
    path: verifying_test/AtCoder/ABC217/H_slope_trick.test.cpp
    title: verifying_test/AtCoder/ABC217/H_slope_trick.test.cpp
  - icon: ':x:'
    path: verifying_test/AtCoder/ARC070/ARC070_C_slope_trick.test.cpp
    title: verifying_test/AtCoder/ARC070/ARC070_C_slope_trick.test.cpp
  - icon: ':x:'
    path: verifying_test/AtCoder/DWANGO2016/E_slope_trick.test.cpp
    title: verifying_test/AtCoder/DWANGO2016/E_slope_trick.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/slope_trick.cpp\"\n\n\n\n#include <queue>\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n\n// \u533A\u5206\u7DDA\u5F62\
    \u51F8\u95A2\u6570 f: Tp -> Tp \u3092\u7BA1\u7406\ntemplate <typename Tp = int>\n\
    struct SlopeTrick {\n  SlopeTrick(Tp minF = 0) : minF(minF), addL((Tp)0), addR((Tp)0)\
    \ {}\n\n  // \u5B9A\u6570\u95A2\u6570 a \u3092\u52A0\u7B97: O(1)\n  void addConstFunc(Tp\
    \ a) { minF += a; }\n  // f(x) = (x - a)+ = max(0, x - a) \u3092\u52A0\u7B97:\
    \ O(log N)\n  void addXmaFunc(Tp a);\n  // f(x) = (a - x)+ = max(0, a - x) \u3092\
    \u52A0\u7B97: O(log N)\n  void addAmxFunc(Tp a);\n  // f(x) = |x - a| \u3092\u52A0\
    \u7B97: O(log N)\n  void addAbsFunc(Tp a);\n  // \u5DE6\u5074\u7D2F\u7A4D min\
    \ (\\min_{y \\leq x} f(y)) \u3092\u53D6\u308B: O(1)\n  void accumulateLeft() {\
    \ ptsR = decltype(ptsR)(); }\n  // \u53F3\u5074\u7D2F\u7A4D min (\\min_{y \\geq\
    \ x} f(y)) \u3092\u53D6\u308B: O(1)\n  void accumulateRight() { ptsL = decltype(ptsL)();\
    \ }\n  // \u5E73\u884C\u79FB\u52D5 \u3059\u306A\u308F\u3061 g(x) = f(x - a) \u306E\
    \u3088\u3046\u306B\u66F4\u65B0: O(1)\n  void applyTranslation(Tp a);\n  // \u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024 \u3059\u306A\u308F\u3061 g(x) = \\min_{y\
    \ \\in [x-b, x-a]} f(y) \u306E\u3088\u3046\u306B\u66F4\u65B0: O(1)\n  void applySlidingWindow(Tp\
    \ a, Tp b);\n\n  // \u95A2\u6570\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059: O(1)\n\
    \  Tp getMinVal() const { return minF; }\n  // \u95A2\u6570\u306E\u5024\u304C\u6700\
    \u5C0F\u306B\u306A\u308B\u3088\u3046\u306A x \u306E\u7BC4\u56F2\u3092\u8FD4\u3059\
    : O(1)\n  void getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty)\
    \ const;\n\nprivate:\n  // pt \u306E\u5024 v \u306B\u3064\u3044\u3066\u3001\u305D\
    \u306E\u771F\u306E\u5024: L \u306E\u5834\u5408 v + addL, R \u306E\u5834\u5408\
    \ v + addR\n  Tp minF, addL, addR;\n  std::priority_queue<Tp> ptsL;\n  std::priority_queue<Tp,\
    \ std::vector<Tp>, std::greater<Tp>> ptsR;\n};\n\ntemplate <typename Tp>\nvoid\
    \ SlopeTrick<Tp>::addXmaFunc(Tp a) {\n  if(ptsL.size()) {\n    minF += std::max((Tp)0,\
    \ (ptsL.top() + addL) - a);\n  }\n  ptsL.emplace(a - addL);\n  Tp maxPt = ptsL.top()\
    \ + addL; ptsL.pop();\n  ptsR.emplace(maxPt - addR);\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::addAmxFunc(Tp a) {\n  if(ptsR.size()) {\n    minF\
    \ += std::max((Tp)0, a - (ptsR.top() + addR));\n  }\n  ptsR.emplace(a - addR);\n\
    \  Tp minPt = ptsR.top() + addR; ptsR.pop();\n  ptsL.emplace(minPt - addL);\n\
    }\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::addAbsFunc(Tp a) {\n  addXmaFunc(a);\n\
    \  addAmxFunc(a);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::applyTranslation(Tp\
    \ a) {\n  applySlidingWindow(a, a);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::applySlidingWindow(Tp\
    \ a, Tp b) {\n  assert(a <= b);\n  addL += a;\n  addR += b;\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub,\
    \ bool& isUbInfty) const {\n  if(ptsL.size()) {\n    lb = ptsL.top() + addL;\n\
    \    isLbInfty = false;\n  }\n  else {\n    isLbInfty = true;\n  }\n\n  if(ptsR.size())\
    \ {\n    ub = ptsR.top() + addR;\n    isUbInfty = false;\n  }\n  else {\n    isUbInfty\
    \ = true;\n  }\n}\n\n\n"
  code: "#ifndef SLOPE_TRICK_CPP\n#define SLOPE_TRICK_CPP\n\n#include <queue>\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n\n// \u533A\u5206\u7DDA\u5F62\
    \u51F8\u95A2\u6570 f: Tp -> Tp \u3092\u7BA1\u7406\ntemplate <typename Tp = int>\n\
    struct SlopeTrick {\n  SlopeTrick(Tp minF = 0) : minF(minF), addL((Tp)0), addR((Tp)0)\
    \ {}\n\n  // \u5B9A\u6570\u95A2\u6570 a \u3092\u52A0\u7B97: O(1)\n  void addConstFunc(Tp\
    \ a) { minF += a; }\n  // f(x) = (x - a)+ = max(0, x - a) \u3092\u52A0\u7B97:\
    \ O(log N)\n  void addXmaFunc(Tp a);\n  // f(x) = (a - x)+ = max(0, a - x) \u3092\
    \u52A0\u7B97: O(log N)\n  void addAmxFunc(Tp a);\n  // f(x) = |x - a| \u3092\u52A0\
    \u7B97: O(log N)\n  void addAbsFunc(Tp a);\n  // \u5DE6\u5074\u7D2F\u7A4D min\
    \ (\\min_{y \\leq x} f(y)) \u3092\u53D6\u308B: O(1)\n  void accumulateLeft() {\
    \ ptsR = decltype(ptsR)(); }\n  // \u53F3\u5074\u7D2F\u7A4D min (\\min_{y \\geq\
    \ x} f(y)) \u3092\u53D6\u308B: O(1)\n  void accumulateRight() { ptsL = decltype(ptsL)();\
    \ }\n  // \u5E73\u884C\u79FB\u52D5 \u3059\u306A\u308F\u3061 g(x) = f(x - a) \u306E\
    \u3088\u3046\u306B\u66F4\u65B0: O(1)\n  void applyTranslation(Tp a);\n  // \u30B9\
    \u30E9\u30A4\u30C9\u6700\u5C0F\u5024 \u3059\u306A\u308F\u3061 g(x) = \\min_{y\
    \ \\in [x-b, x-a]} f(y) \u306E\u3088\u3046\u306B\u66F4\u65B0: O(1)\n  void applySlidingWindow(Tp\
    \ a, Tp b);\n\n  // \u95A2\u6570\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059: O(1)\n\
    \  Tp getMinVal() const { return minF; }\n  // \u95A2\u6570\u306E\u5024\u304C\u6700\
    \u5C0F\u306B\u306A\u308B\u3088\u3046\u306A x \u306E\u7BC4\u56F2\u3092\u8FD4\u3059\
    : O(1)\n  void getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty)\
    \ const;\n\nprivate:\n  // pt \u306E\u5024 v \u306B\u3064\u3044\u3066\u3001\u305D\
    \u306E\u771F\u306E\u5024: L \u306E\u5834\u5408 v + addL, R \u306E\u5834\u5408\
    \ v + addR\n  Tp minF, addL, addR;\n  std::priority_queue<Tp> ptsL;\n  std::priority_queue<Tp,\
    \ std::vector<Tp>, std::greater<Tp>> ptsR;\n};\n\ntemplate <typename Tp>\nvoid\
    \ SlopeTrick<Tp>::addXmaFunc(Tp a) {\n  if(ptsL.size()) {\n    minF += std::max((Tp)0,\
    \ (ptsL.top() + addL) - a);\n  }\n  ptsL.emplace(a - addL);\n  Tp maxPt = ptsL.top()\
    \ + addL; ptsL.pop();\n  ptsR.emplace(maxPt - addR);\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::addAmxFunc(Tp a) {\n  if(ptsR.size()) {\n    minF\
    \ += std::max((Tp)0, a - (ptsR.top() + addR));\n  }\n  ptsR.emplace(a - addR);\n\
    \  Tp minPt = ptsR.top() + addR; ptsR.pop();\n  ptsL.emplace(minPt - addL);\n\
    }\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::addAbsFunc(Tp a) {\n  addXmaFunc(a);\n\
    \  addAmxFunc(a);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::applyTranslation(Tp\
    \ a) {\n  applySlidingWindow(a, a);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::applySlidingWindow(Tp\
    \ a, Tp b) {\n  assert(a <= b);\n  addL += a;\n  addR += b;\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub,\
    \ bool& isUbInfty) const {\n  if(ptsL.size()) {\n    lb = ptsL.top() + addL;\n\
    \    isLbInfty = false;\n  }\n  else {\n    isLbInfty = true;\n  }\n\n  if(ptsR.size())\
    \ {\n    ub = ptsR.top() + addR;\n    isUbInfty = false;\n  }\n  else {\n    isUbInfty\
    \ = true;\n  }\n}\n\n#endif // !SLOPE_TRICK_CPP"
  dependsOn: []
  isVerificationFile: false
  path: structure/slope_trick.cpp
  requiredBy: []
  timestamp: '2021-09-05 23:10:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verifying_test/AtCoder/ABC217/H_slope_trick.test.cpp
  - verifying_test/AtCoder/DWANGO2016/E_slope_trick.test.cpp
  - verifying_test/AtCoder/ARC070/ARC070_C_slope_trick.test.cpp
  - verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
documentation_of: structure/slope_trick.cpp
layout: document
title: Slope Trick
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
- `void addXmaFunc(Tp a)`
  - $f(x) = (x - a)_{+} = \max \left( 0, x - a \right)$ を加算
  - Time Complexity: $O(\log N)$
- `void addAmxFunc(Tp a)`
  - $f(x) = (a - x)_{+} = \max \left( 0, a - x \right)$ を加算
  - Time Complexity: $O(\log N)$
- `void addAbsFunc(Tp a)`
  - $f(x) = \lvert x - a \rvert = (x - a)\_{+} + (a - x)\_{+}$を加算
  - Time Complexity: $O(\log N)$
- `void accumulateLeft()`
  - 左側累積 min を取る。すなわち、持つ関数を $G(x) = \min_{y \leq x} F(y)$ を満たすような $G(x)$ に変化させる
  - Time Complexity: $O(1)$
- `void accumulateRight()`
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