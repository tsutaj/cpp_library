#ifndef SLOPE_TRICK_CPP
#define SLOPE_TRICK_CPP

#include <queue>
#include <vector>
#include <algorithm>
#include <cassert>

// 区分線形凸関数 f: Tp -> Tp を管理
template <typename Tp = int>
struct SlopeTrick {
  SlopeTrick(Tp minF = 0) : minF(minF), addL((Tp)0), addR((Tp)0) {}

  // 定数関数 a を加算: O(1)
  void addConstFunc(Tp a) { minF += a; }
  // f(x) = (x - a)+ = max(0, x - a) を加算: O(log N)
  void addIncreasingFunc(Tp a);
  // f(x) = (a - x)+ = max(0, a - x) を加算: O(log N)
  void addDecreasingFunc(Tp a);
  // f(x) = |x - a| を加算: O(log N)
  void addAbsFunc(Tp a);
  // 左側累積 min (\min_{y \leq x} f(y)) を取る: amortize O(1)
  void cumulateLeft() { ptsR = decltype(ptsR)(); }
  // 右側累積 min (\min_{y \geq x} f(y)) を取る: amortize O(1)
  void cumulateRight() { ptsL = decltype(ptsL)(); }
  // 平行移動 すなわち g(x) = f(x - a) のように更新: O(1)
  void applyTranslation(Tp a);
  // スライド最小値 すなわち g(x) = \min_{y \in [x-b, x-a]} f(y) のように更新: O(1)
  void applySlidingWindow(Tp a, Tp b);

  // 関数の最小値を返す: O(1)
  Tp getMinVal() const { return minF; }
  // 関数の値が最小になるような x の範囲を返す: O(1)
  void getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty) const;

private:
  // pt の値 v について、その真の値: L の場合 v + addL, R の場合 v + addR
  Tp minF, addL, addR;
  std::priority_queue<Tp> ptsL;
  std::priority_queue<Tp, std::vector<Tp>, std::greater<Tp>> ptsR;
};

template <typename Tp>
void SlopeTrick<Tp>::addIncreasingFunc(Tp a) {
  if(ptsL.size()) {
    minF += std::max((Tp)0, (ptsL.top() + addL) - a);
  }
  ptsL.emplace(a - addL);
  Tp maxPt = ptsL.top() + addL; ptsL.pop();
  ptsR.emplace(maxPt - addR);
}

template <typename Tp>
void SlopeTrick<Tp>::addDecreasingFunc(Tp a) {
  if(ptsR.size()) {
    minF += std::max((Tp)0, a - (ptsR.top() + addR));
  }
  ptsR.emplace(a - addR);
  Tp minPt = ptsR.top() + addR; ptsR.pop();
  ptsL.emplace(minPt - addL);
}

template <typename Tp>
void SlopeTrick<Tp>::addAbsFunc(Tp a) {
  addIncreasingFunc(a);
  addDecreasingFunc(a);
}

template <typename Tp>
void SlopeTrick<Tp>::applyTranslation(Tp a) {
  applySlidingWindow(a, a);
}

template <typename Tp>
void SlopeTrick<Tp>::applySlidingWindow(Tp a, Tp b) {
  assert(a <= b);
  addL += a;
  addR += b;
}

template <typename Tp>
void SlopeTrick<Tp>::getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty) const {
  if(ptsL.size()) {
    lb = ptsL.top() + addL;
    isLbInfty = false;
  }
  else {
    isLbInfty = true;
  }

  if(ptsR.size()) {
    ub = ptsR.top() + addR;
    isUbInfty = false;
  }
  else {
    isUbInfty = true;
  }
}

#endif // !SLOPE_TRICK_CPP