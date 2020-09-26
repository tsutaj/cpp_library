---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_015_remainder_sum.cpp
    title: math/verify/verify_math_015_remainder_sum.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_015_remainder_sum.cpp\"\n// F(i) := P (mod 1)\
    \ + P (mod 2) + ... + P (mod i) \u3092\u8A08\u7B97\n// \u7B54\u3048\u306F NumType\
    \ \u578B\u3067\u8FD4\u3063\u3066\u304F\u308B\ntemplate <typename NumType, int\
    \ K = 10000000>\nstruct RemainderSum {\n    using lint = long long;\n    lint\
    \ P;\n    vector<NumType> small_case;\n    RemainderSum(lint P_) {\n        P\
    \ = P_;\n        build();\n    }\n\n    // \u5C0F\u3055\u3044\u30B1\u30FC\u30B9\
    \u306B\u5BFE\u3059\u308B\u7B54\u3048\u3092\u899A\u3048\u308B\n    void build()\
    \ {\n        small_case.resize(K + 1, NumType(0));\n        for(lint i=1; i<=K;\
    \ i++) {\n            NumType mod(P % i);\n            small_case[i] = small_case[i-1]\
    \ + mod;\n        }\n    }\n\n    // [1, x] (\u9589\u533A\u9593\u3067\u3042\u308B\
    \u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n    // F(x) \u3092\u8A08\u7B97 \n\
    \    NumType sum_func(lint x) {\n        if(x <= K) return small_case[x];\n  \
    \      return small_case[K] + sum_func(K+1, x);\n    }\n\n    // [l, r] (\u9589\
    \u533A\u9593\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n  \
    \  // P (mod l) + P (mod l+1) + ... + P (mod r) \u3092\u8A08\u7B97\n    NumType\
    \ sum_func(lint l, lint r) {\n        if(r <= K) return small_case[r] - small_case[l-1];\n\
    \        if(l <= K) return small_case[K] - small_case[l-1] + sum_func(K+1, r);\n\
    \n        NumType ans(0);\n        // l \u3082 r \u3082\u3001 K \u3092\u8D85\u3048\
    \u308B\u5024\u3067\u3042\u308B\n        lint dmax = P / l, dmin = P / r, num =\
    \ l;\n        for(lint div=dmax; div>=dmin; div--) {\n            if(div == 0)\
    \ {\n                // \u5546\u304C div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\
    \u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n      \
    \          lint idx_l = max(l, P + 1);\n                lint idx_r = r;\n    \
    \            NumType range(idx_r - idx_l + 1);\n\n                // \u3053\u306E\
    \u3068\u304D\u306E\u5270\u4F59\u306E\u5024\u306F\u5168\u3066 P \u306B\u7B49\u3057\
    \u3044\n                NumType sum = range * NumType(P);\n                ans\
    \ += sum;\n            }\n            else {\n                // \u5546\u304C\
    \ div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n                lint idx_l = max(l, P\
    \ / (div + 1) + 1);\n                lint idx_r = min(r, P / div);\n         \
    \       NumType range(idx_r - idx_l + 1);\n                \n                //\
    \ \u5DE6\u7AEF\u3068\u53F3\u7AEF\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u5270\
    \u4F59\u306E\u5024\n                NumType mod_l(P % idx_l);\n              \
    \  NumType mod_r(P % idx_r);\n                \n                // \u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\n                NumType sum = range * (mod_l + mod_r)\
    \ / NumType(2);\n                ans += sum;\n                \n             \
    \   // \u6B21\u306E div \u3092\u6C42\u3081\u308B (1 \u305A\u3064\u6E1B\u3089\u306A\
    \u3044\u5834\u5408\u304C\u3042\u308B)\n                if(P / num != P / (num\
    \ + 1)) {\n                    div = P / (num + 1) + 1;\n                    num++;\n\
    \                }\n            }\n        }\n        return ans;\n    }\n};\n"
  code: "// F(i) := P (mod 1) + P (mod 2) + ... + P (mod i) \u3092\u8A08\u7B97\n//\
    \ \u7B54\u3048\u306F NumType \u578B\u3067\u8FD4\u3063\u3066\u304F\u308B\ntemplate\
    \ <typename NumType, int K = 10000000>\nstruct RemainderSum {\n    using lint\
    \ = long long;\n    lint P;\n    vector<NumType> small_case;\n    RemainderSum(lint\
    \ P_) {\n        P = P_;\n        build();\n    }\n\n    // \u5C0F\u3055\u3044\
    \u30B1\u30FC\u30B9\u306B\u5BFE\u3059\u308B\u7B54\u3048\u3092\u899A\u3048\u308B\
    \n    void build() {\n        small_case.resize(K + 1, NumType(0));\n        for(lint\
    \ i=1; i<=K; i++) {\n            NumType mod(P % i);\n            small_case[i]\
    \ = small_case[i-1] + mod;\n        }\n    }\n\n    // [1, x] (\u9589\u533A\u9593\
    \u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n    // F(x) \u3092\
    \u8A08\u7B97 \n    NumType sum_func(lint x) {\n        if(x <= K) return small_case[x];\n\
    \        return small_case[K] + sum_func(K+1, x);\n    }\n\n    // [l, r] (\u9589\
    \u533A\u9593\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n  \
    \  // P (mod l) + P (mod l+1) + ... + P (mod r) \u3092\u8A08\u7B97\n    NumType\
    \ sum_func(lint l, lint r) {\n        if(r <= K) return small_case[r] - small_case[l-1];\n\
    \        if(l <= K) return small_case[K] - small_case[l-1] + sum_func(K+1, r);\n\
    \n        NumType ans(0);\n        // l \u3082 r \u3082\u3001 K \u3092\u8D85\u3048\
    \u308B\u5024\u3067\u3042\u308B\n        lint dmax = P / l, dmin = P / r, num =\
    \ l;\n        for(lint div=dmax; div>=dmin; div--) {\n            if(div == 0)\
    \ {\n                // \u5546\u304C div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\
    \u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n      \
    \          lint idx_l = max(l, P + 1);\n                lint idx_r = r;\n    \
    \            NumType range(idx_r - idx_l + 1);\n\n                // \u3053\u306E\
    \u3068\u304D\u306E\u5270\u4F59\u306E\u5024\u306F\u5168\u3066 P \u306B\u7B49\u3057\
    \u3044\n                NumType sum = range * NumType(P);\n                ans\
    \ += sum;\n            }\n            else {\n                // \u5546\u304C\
    \ div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n                lint idx_l = max(l, P\
    \ / (div + 1) + 1);\n                lint idx_r = min(r, P / div);\n         \
    \       NumType range(idx_r - idx_l + 1);\n                \n                //\
    \ \u5DE6\u7AEF\u3068\u53F3\u7AEF\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u5270\
    \u4F59\u306E\u5024\n                NumType mod_l(P % idx_l);\n              \
    \  NumType mod_r(P % idx_r);\n                \n                // \u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\n                NumType sum = range * (mod_l + mod_r)\
    \ / NumType(2);\n                ans += sum;\n                \n             \
    \   // \u6B21\u306E div \u3092\u6C42\u3081\u308B (1 \u305A\u3064\u6E1B\u3089\u306A\
    \u3044\u5834\u5408\u304C\u3042\u308B)\n                if(P / num != P / (num\
    \ + 1)) {\n                    div = P / (num + 1) + 1;\n                    num++;\n\
    \                }\n            }\n        }\n        return ans;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_015_remainder_sum.cpp
  requiredBy:
  - math/verify/verify_math_015_remainder_sum.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_015_remainder_sum.cpp
layout: document
redirect_from:
- /library/math/math_015_remainder_sum.cpp
- /library/math/math_015_remainder_sum.cpp.html
title: math/math_015_remainder_sum.cpp
---
