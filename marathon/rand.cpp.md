---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"marathon/rand.cpp\"\n// [lb, ub] \u306E\u9589\u533A\u9593\
    \u5185\u306E\u5024\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u8FD4\u3059\u69CB\u9020\
    \u4F53\n// #include <random> \u3057\u3088\u3046\n\nstruct Rand {\npublic:\n  \
    \  Rand() = default;\n    Rand(std::mt19937::result_type seed) : eng(seed) {}\n\
    \    int NextInt(int lb, int ub) {\n        return std::uniform_int_distribution<int>{lb,\
    \ ub}(eng);\n    }\n    ll NextLong(ll lb, ll ub) {\n        return std::uniform_int_distribution<ll>{lb,\
    \ ub}(eng);\n    }\n    double NextDouble(double lb, double ub) {\n        return\
    \ std::uniform_real_distribution<double>{lb, ub}(eng);\n    }\nprivate:\n    std::mt19937\
    \ eng{std::random_device{}()};\n};\n\n/* \n// example.\nint main() {\n    Rand\
    \ rnd(114514);\n    int l, r; scanf(\"%d%d\", &l, &r);\n    printf(\"l = %d, r\
    \ = %d, value = %d\\n\", l, r, rnd.NextInt(l, r));\n\n    double L, R; scanf(\"\
    %lf%lf\", &L, &R);\n    printf(\"L = %.12f, R = %.12f, value = %.12f\\n\", L,\
    \ R, rnd.NextDouble(L, R));\n\n    long long int a, b; scanf(\"%lld%lld\", &a,\
    \ &b);\n    printf(\"a = %lld, b = %lld, value = %lld\\n\", a, b, rnd.NextLong(a,\
    \ b));\n    return 0;\n}\n*/\n"
  code: "// [lb, ub] \u306E\u9589\u533A\u9593\u5185\u306E\u5024\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u8FD4\u3059\u69CB\u9020\u4F53\n// #include <random> \u3057\u3088\u3046\
    \n\nstruct Rand {\npublic:\n    Rand() = default;\n    Rand(std::mt19937::result_type\
    \ seed) : eng(seed) {}\n    int NextInt(int lb, int ub) {\n        return std::uniform_int_distribution<int>{lb,\
    \ ub}(eng);\n    }\n    ll NextLong(ll lb, ll ub) {\n        return std::uniform_int_distribution<ll>{lb,\
    \ ub}(eng);\n    }\n    double NextDouble(double lb, double ub) {\n        return\
    \ std::uniform_real_distribution<double>{lb, ub}(eng);\n    }\nprivate:\n    std::mt19937\
    \ eng{std::random_device{}()};\n};\n\n/* \n// example.\nint main() {\n    Rand\
    \ rnd(114514);\n    int l, r; scanf(\"%d%d\", &l, &r);\n    printf(\"l = %d, r\
    \ = %d, value = %d\\n\", l, r, rnd.NextInt(l, r));\n\n    double L, R; scanf(\"\
    %lf%lf\", &L, &R);\n    printf(\"L = %.12f, R = %.12f, value = %.12f\\n\", L,\
    \ R, rnd.NextDouble(L, R));\n\n    long long int a, b; scanf(\"%lld%lld\", &a,\
    \ &b);\n    printf(\"a = %lld, b = %lld, value = %lld\\n\", a, b, rnd.NextLong(a,\
    \ b));\n    return 0;\n}\n*/"
  dependsOn: []
  isVerificationFile: false
  path: marathon/rand.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/rand.cpp
layout: document
redirect_from:
- /library/marathon/rand.cpp
- /library/marathon/rand.cpp.html
title: marathon/rand.cpp
---
