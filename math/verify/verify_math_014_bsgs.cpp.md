---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_014_bsgs.cpp
    title: math/math_014_bsgs.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://vjudge.net/contest/271429#problem/D
    - https://yukicoder.me/problems/no/551
  bundledCode: "#line 1 \"math/verify/verify_math_014_bsgs.cpp\"\n#include <cstdio>\n\
    #include <vector>\n#include <algorithm>\n#include <unordered_map>\n#include <iostream>\n\
    #include <cmath>\nusing namespace std;\n#line 1 \"math/math_014_bsgs.cpp\"\n//\
    \ \u96E2\u6563\u5BFE\u6570\u554F\u984C (Discrete Logarithm Problem) \u3092\u89E3\
    \u304F\n// a^x = b (mod p, p \u306F\u7D20\u6570) \u3092\u6E80\u305F\u3059\u3088\
    \u3046\u306A x (1 <= x <= p-1) \u3092\u6C42\u3081\u308B\ntemplate <typename NumType>\n\
    struct DiscreteLogarithm {\n    unordered_map<NumType, NumType> pow_table_;\n\n\
    \    // a \u3068 p \u3092\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u3067\u6307\
    \u5B9A\u3059\u308B\u3068\u3001pow_table_ \u304C\u4F5C\u3089\u308C\u308B\n    DiscreteLogarithm()\
    \ : pow_table_() {}\n    DiscreteLogarithm(NumType a, NumType p, double ratio=0.5)\
    \ {\n        set_rec_table(a, p, ratio);\n    }\n    \n    NumType mod_pow(NumType\
    \ x, NumType k, NumType p) {\n        NumType res = 1;\n        for(; k>0; k>>=1)\
    \ {\n            if(k & 1) (res *= x) %= p;\n            (x *= x) %= p;\n    \
    \    }\n        return res;\n    }\n\n    NumType mod_inv(NumType x, NumType p)\
    \ {\n        return mod_pow(x, p-2, p);\n    }\n\n    // a^{-s * sqrtp} => s \u304C\
    \u683C\u7D0D\u3055\u308C\u305F map \u3092\u8FD4\u3059\n    unordered_map<NumType,\
    \ NumType> get_rec_table(NumType a, NumType p, double ratio=0.5) {\n        unordered_map<NumType,\
    \ NumType> num_rec;\n        NumType sp = pow(p, ratio) + 1;\n        NumType\
    \ tp = pow(p, 1.0 - ratio) + 1;\n\n        // a^{-sqrtp}\n        NumType inv_pow_a\
    \ = mod_inv(mod_pow(a, sp, p), p);\n\n        // a^{-s * sqrtp}\n        NumType\
    \ mul = 1;\n        for(NumType s=0; s<=tp; s++) {\n            NumType key =\
    \ mul;\n            if(num_rec.count(key)) break;\n            num_rec[key] =\
    \ s;\n            (mul *= inv_pow_a) %= p;\n        }\n        return num_rec;\n\
    \    }\n\n    // pow_table_ \u306B map \u3092\u30BB\u30C3\u30C8\u3059\u308B\n\
    \    void set_rec_table(NumType a, NumType p, double ratio) {\n        pow_table_\
    \ = get_rec_table(a, p, ratio);\n    }\n\n    // Baby-step Giant-step Algorithm:\
    \ O(sqrt(p)) \u3060\u304C ratio \u306B\u4F9D\u5B58\n    // a^{-s * sp} \u306E\
    \ map \u306F\u3001\u76F4\u524D\u306E\u3082\u306E\u3092\u4F7F\u3044\u307E\u308F\
    \u3059\u3053\u3068\u3082\u3067\u304D\u308B\n    // pow_table_ \u304C\u7A7A\u306E\
    \u5834\u5408\u3001\u307E\u305F\u306F use_same_table \u304C\u6307\u5B9A\u3055\u308C\
    \u3066\u3044\u306A\u3044\u5834\u5408\u306F\u81EA\u52D5\u7684\u306B map \u304C\u4F5C\
    \u3089\u308C\u3001\u305D\u308C\u304C pow_table_ \u306B\u4FDD\u5B58\u3055\u308C\
    \u308B\n    NumType BSGS(NumType a, NumType b, NumType p, bool use_same_table=false,\
    \ double ratio=0.5) {\n        a %= p, b %= p;\n        NumType sp = pow(p, ratio)\
    \ + 1;\n        \n        // a^{-s * sp} => s\n        unordered_map<NumType,\
    \ NumType> &num_rec = pow_table_;\n        if(num_rec.empty() or !use_same_table)\
    \ {\n            set_rec_table(a, p, ratio);\n        }\n        \n        //\
    \ a^t * b^{-1} = a^{-s * sp}\n        // \u3053\u306E\u6642\u306E\u7B54\u3048\u306F\
    \ s * sp + t\n        NumType mul = mod_inv(b, p);\n        for(NumType t=0; t<=sp;\
    \ t++) {\n            if(num_rec.count(mul)) {\n                NumType s = num_rec[mul];\n\
    \n                // \u89E3\u306E\u7BC4\u56F2\u306F 1 \u4EE5\u4E0A p-1 \u4EE5\u4E0B\
    \u306A\u306E\u3067\u305D\u308C\u306F\u30C1\u30A7\u30C3\u30AF\u304C\u5FC5\u8981\
    \n                NumType ans = s * sp + t;\n                if(1 <= ans and ans\
    \ <= p-1) return ans;\n            }\n            (mul *= a) %= p;\n        }\n\
    \n        // \u89E3\u306A\u3057\n        return NumType(-1);\n    }\n};\n#line\
    \ 9 \"math/verify/verify_math_014_bsgs.cpp\"\n\n// Verified on Mar 28, 2019\n\
    // Taipei Regional Contest 2015: D\n// Judge: https://vjudge.net/contest/271429#problem/D\n\
    void TaipeiRegional2015_D() {\n    int a, b, prime; cin >> prime;\n    while(scanf(\"\
    %d%d\", &a, &b) == 2) {\n        DiscreteLogarithm<int> dl;\n        int ans =\
    \ dl.BSGS(a, b, prime);\n        if(ans < 0) puts(\"0\");\n        else printf(\"\
    %d\\n\", ans);\n    }\n}\n\n// Verified on Mar 30, 2019\n// yukicoder No.551:\
    \ \u590F\u4F11\u307F\u306E\u601D\u3044\u51FA (2)\n// Judge: https://yukicoder.me/problems/no/551\n\
    void yuki_551() {\n    using lint = long long int;\n    lint P, R, Q; cin >> P\
    \ >> R >> Q;\n    double ratio = 0.3;\n    DiscreteLogarithm<lint> dl(R, P, ratio);\n\
    \    while(Q--) {\n        lint A, B, C; scanf(\"%lld%lld%lld\", &A, &B, &C);\n\
    \        lint r = dl.mod_inv(A, P);\n        (A *= r) %= P;\n        (B *= r)\
    \ %= P;\n        (C *= r) %= P;\n        (B *= dl.mod_inv(2, P)) %= P;\n\n   \
    \     lint D = (P - C + (B*B%P)) % P;\n        if(D == 0) {\n            printf(\"\
    %lld\\n\", (P - B) % P);\n        }\n        else {\n            // R^k = D \u306A\
    \u308B k \u3092\u6C42\u3081\u308B\n            // k \u304C\u5947\u6570 ... \u89E3\
    \u306A\u3057\n            // k \u304C\u5076\u6570 ... k/2 \u3068 k/2 + (P-1)/2\
    \ \u304C\u89E3\n            lint k = dl.BSGS(R, D, P, true, ratio);\n        \
    \    if(k < 0 or k % 2 == 1) {\n                printf(\"-1\\n\");\n         \
    \   }\n            else {\n                lint sqrtd = dl.mod_pow(R, k/2, P);\n\
    \                lint X = (2*P + sqrtd - B) % P;\n                lint Y = (2*P\
    \ - sqrtd - B) % P;\n                if(X > Y) swap(X, Y);\n                printf(\"\
    %lld %lld\\n\", X, Y);\n            }\n        }\n    }\n}\n\nint main() {\n \
    \   TaipeiRegional2015_D();\n    // yuki_551();\n}\n"
  code: "#include <cstdio>\n#include <vector>\n#include <algorithm>\n#include <unordered_map>\n\
    #include <iostream>\n#include <cmath>\nusing namespace std;\n#include \"../math_014_bsgs.cpp\"\
    \n\n// Verified on Mar 28, 2019\n// Taipei Regional Contest 2015: D\n// Judge:\
    \ https://vjudge.net/contest/271429#problem/D\nvoid TaipeiRegional2015_D() {\n\
    \    int a, b, prime; cin >> prime;\n    while(scanf(\"%d%d\", &a, &b) == 2) {\n\
    \        DiscreteLogarithm<int> dl;\n        int ans = dl.BSGS(a, b, prime);\n\
    \        if(ans < 0) puts(\"0\");\n        else printf(\"%d\\n\", ans);\n    }\n\
    }\n\n// Verified on Mar 30, 2019\n// yukicoder No.551: \u590F\u4F11\u307F\u306E\
    \u601D\u3044\u51FA (2)\n// Judge: https://yukicoder.me/problems/no/551\nvoid yuki_551()\
    \ {\n    using lint = long long int;\n    lint P, R, Q; cin >> P >> R >> Q;\n\
    \    double ratio = 0.3;\n    DiscreteLogarithm<lint> dl(R, P, ratio);\n    while(Q--)\
    \ {\n        lint A, B, C; scanf(\"%lld%lld%lld\", &A, &B, &C);\n        lint\
    \ r = dl.mod_inv(A, P);\n        (A *= r) %= P;\n        (B *= r) %= P;\n    \
    \    (C *= r) %= P;\n        (B *= dl.mod_inv(2, P)) %= P;\n\n        lint D =\
    \ (P - C + (B*B%P)) % P;\n        if(D == 0) {\n            printf(\"%lld\\n\"\
    , (P - B) % P);\n        }\n        else {\n            // R^k = D \u306A\u308B\
    \ k \u3092\u6C42\u3081\u308B\n            // k \u304C\u5947\u6570 ... \u89E3\u306A\
    \u3057\n            // k \u304C\u5076\u6570 ... k/2 \u3068 k/2 + (P-1)/2 \u304C\
    \u89E3\n            lint k = dl.BSGS(R, D, P, true, ratio);\n            if(k\
    \ < 0 or k % 2 == 1) {\n                printf(\"-1\\n\");\n            }\n  \
    \          else {\n                lint sqrtd = dl.mod_pow(R, k/2, P);\n     \
    \           lint X = (2*P + sqrtd - B) % P;\n                lint Y = (2*P - sqrtd\
    \ - B) % P;\n                if(X > Y) swap(X, Y);\n                printf(\"\
    %lld %lld\\n\", X, Y);\n            }\n        }\n    }\n}\n\nint main() {\n \
    \   TaipeiRegional2015_D();\n    // yuki_551();\n}\n"
  dependsOn:
  - math/math_014_bsgs.cpp
  isVerificationFile: false
  path: math/verify/verify_math_014_bsgs.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_014_bsgs.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_014_bsgs.cpp
- /library/math/verify/verify_math_014_bsgs.cpp.html
title: math/verify/verify_math_014_bsgs.cpp
---
