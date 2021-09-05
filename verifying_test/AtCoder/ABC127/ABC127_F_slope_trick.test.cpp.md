---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: structure/slope_trick.cpp
    title: Slope Trick
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://atcoder.jp/contests/abc127/tasks/abc127_f
    links:
    - https://atcoder.jp/contests/abc127/tasks/abc127_f
  bundledCode: "#line 1 \"verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp\"\
    \n#define PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\n\n#include\
    \ <cstdio>\n#include <cassert>\n#line 1 \"structure/slope_trick.cpp\"\n\n\n\n\
    #include <queue>\n#include <vector>\n#include <algorithm>\n#line 8 \"structure/slope_trick.cpp\"\
    \n\n// \u533A\u5206\u7DDA\u5F62\u51F8\u95A2\u6570 f: Tp -> Tp \u3092\u7BA1\u7406\
    \ntemplate <typename Tp = int>\nstruct SlopeTrick {\n  SlopeTrick(Tp minF = 0)\
    \ : minF(minF), addL((Tp)0), addR((Tp)0) {}\n\n  // \u5B9A\u6570\u95A2\u6570 a\
    \ \u3092\u52A0\u7B97: O(1)\n  void addConstFunc(Tp a) { minF += a; }\n  // f(x)\
    \ = (x - a)+ = max(0, x - a) \u3092\u52A0\u7B97: O(log N)\n  void addIncreasingFunc(Tp\
    \ a);\n  // f(x) = (a - x)+ = max(0, a - x) \u3092\u52A0\u7B97: O(log N)\n  void\
    \ addDecreasingFunc(Tp a);\n  // f(x) = |x - a| \u3092\u52A0\u7B97: O(log N)\n\
    \  void addAbsFunc(Tp a);\n  // \u5DE6\u5074\u7D2F\u7A4D min (\\min_{y \\leq x}\
    \ f(y)) \u3092\u53D6\u308B: amortize O(1)\n  void cumulateLeft() { ptsR = decltype(ptsR)();\
    \ }\n  // \u53F3\u5074\u7D2F\u7A4D min (\\min_{y \\geq x} f(y)) \u3092\u53D6\u308B\
    : amortize O(1)\n  void cumulateRight() { ptsL = decltype(ptsL)(); }\n  // \u5E73\
    \u884C\u79FB\u52D5 \u3059\u306A\u308F\u3061 g(x) = f(x - a) \u306E\u3088\u3046\
    \u306B\u66F4\u65B0: O(1)\n  void applyTranslation(Tp a);\n  // \u30B9\u30E9\u30A4\
    \u30C9\u6700\u5C0F\u5024 \u3059\u306A\u308F\u3061 g(x) = \\min_{y \\in [x-b, x-a]}\
    \ f(y) \u306E\u3088\u3046\u306B\u66F4\u65B0: O(1)\n  void applySlidingWindow(Tp\
    \ a, Tp b);\n\n  // \u95A2\u6570\u306E\u6700\u5C0F\u5024\u3092\u8FD4\u3059: O(1)\n\
    \  Tp getMinVal() const { return minF; }\n  // \u95A2\u6570\u306E\u5024\u304C\u6700\
    \u5C0F\u306B\u306A\u308B\u3088\u3046\u306A x \u306E\u7BC4\u56F2\u3092\u8FD4\u3059\
    : O(1)\n  void getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub, bool& isUbInfty)\
    \ const;\n\nprivate:\n  // pt \u306E\u5024 v \u306B\u3064\u3044\u3066\u3001\u305D\
    \u306E\u771F\u306E\u5024: L \u306E\u5834\u5408 v + addL, R \u306E\u5834\u5408\
    \ v + addR\n  Tp minF, addL, addR;\n  std::priority_queue<Tp> ptsL;\n  std::priority_queue<Tp,\
    \ std::vector<Tp>, std::greater<Tp>> ptsR;\n};\n\ntemplate <typename Tp>\nvoid\
    \ SlopeTrick<Tp>::addIncreasingFunc(Tp a) {\n  if(ptsL.size()) {\n    minF +=\
    \ std::max((Tp)0, (ptsL.top() + addL) - a);\n  }\n  ptsL.emplace(a - addL);\n\
    \  Tp maxPt = ptsL.top() + addL; ptsL.pop();\n  ptsR.emplace(maxPt - addR);\n\
    }\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::addDecreasingFunc(Tp a) {\n\
    \  if(ptsR.size()) {\n    minF += std::max((Tp)0, a - (ptsR.top() + addR));\n\
    \  }\n  ptsR.emplace(a - addR);\n  Tp minPt = ptsR.top() + addR; ptsR.pop();\n\
    \  ptsL.emplace(minPt - addL);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::addAbsFunc(Tp\
    \ a) {\n  addIncreasingFunc(a);\n  addDecreasingFunc(a);\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::applyTranslation(Tp a) {\n  applySlidingWindow(a,\
    \ a);\n}\n\ntemplate <typename Tp>\nvoid SlopeTrick<Tp>::applySlidingWindow(Tp\
    \ a, Tp b) {\n  assert(a <= b);\n  addL += a;\n  addR += b;\n}\n\ntemplate <typename\
    \ Tp>\nvoid SlopeTrick<Tp>::getArgminInterval(Tp& lb, bool& isLbInfty, Tp& ub,\
    \ bool& isUbInfty) const {\n  if(ptsL.size()) {\n    lb = ptsL.top() + addL;\n\
    \    isLbInfty = false;\n  }\n  else {\n    isLbInfty = true;\n  }\n\n  if(ptsR.size())\
    \ {\n    ub = ptsR.top() + addR;\n    isUbInfty = false;\n  }\n  else {\n    isUbInfty\
    \ = true;\n  }\n}\n\n\n#line 6 \"verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp\"\
    \nusing ll = long long int;\n\nint main() {\n  int Q; scanf(\"%d\", &Q);\n\n \
    \ SlopeTrick<ll> slope;\n  while(Q--) {\n    int type; scanf(\"%d\", &type);\n\
    \    if(type == 1) {\n      ll a, b; scanf(\"%lld%lld\", &a, &b);\n      slope.addAbsFunc(a);\n\
    \      slope.addConstFunc(b);\n    }\n    if(type == 2) {\n      ll minF = slope.getMinVal();\n\
    \      ll lb, ub; bool isLbInfty, isUbInfty;\n      slope.getArgminInterval(lb,\
    \ isLbInfty, ub, isUbInfty);\n      assert(!isLbInfty);\n      printf(\"%lld %lld\\\
    n\", lb, minF);\n    }\n  }\n  return 0;\n}\n"
  code: "#define PROBLEM \"https://atcoder.jp/contests/abc127/tasks/abc127_f\"\n\n\
    #include <cstdio>\n#include <cassert>\n#include \"../../../structure/slope_trick.cpp\"\
    \nusing ll = long long int;\n\nint main() {\n  int Q; scanf(\"%d\", &Q);\n\n \
    \ SlopeTrick<ll> slope;\n  while(Q--) {\n    int type; scanf(\"%d\", &type);\n\
    \    if(type == 1) {\n      ll a, b; scanf(\"%lld%lld\", &a, &b);\n      slope.addAbsFunc(a);\n\
    \      slope.addConstFunc(b);\n    }\n    if(type == 2) {\n      ll minF = slope.getMinVal();\n\
    \      ll lb, ub; bool isLbInfty, isUbInfty;\n      slope.getArgminInterval(lb,\
    \ isLbInfty, ub, isUbInfty);\n      assert(!isLbInfty);\n      printf(\"%lld %lld\\\
    n\", lb, minF);\n    }\n  }\n  return 0;\n}\n"
  dependsOn:
  - structure/slope_trick.cpp
  isVerificationFile: true
  path: verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
  requiredBy: []
  timestamp: '2021-09-05 19:51:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
- /verify/verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp.html
title: verifying_test/AtCoder/ABC127/ABC127_F_slope_trick.test.cpp
---
