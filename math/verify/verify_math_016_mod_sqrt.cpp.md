---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_016_mod_sqrt.cpp
    title: math/math_016_mod_sqrt.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://yukicoder.me/problems/no/551
  bundledCode: "#line 1 \"math/verify/verify_math_016_mod_sqrt.cpp\"\n#include <cstdio>\n\
    #include <vector>\n#include <iostream>\n#include <algorithm>\n#include <random>\n\
    using namespace std;\n#line 1 \"math/math_016_mod_sqrt.cpp\"\n// Tonelli-Shanks\
    \ Algorithm\n// \u7D20\u6570 p \u3092\u6CD5\u3068\u3057\u3001n \u304C\u4E0E\u3048\
    \u3089\u308C\u305F\u3068\u304D\u3001\n// r^2 = n (mod p) \u3092\u6E80\u305F\u3059\
    \ r \u3092\u6C42\u3081\u308B\n\nstruct QuadraticResidue {\n    using lint = long\
    \ long int;\n    QuadraticResidue() {}\n\n    // x^k (mod p)\n    lint mod_pow(lint\
    \ x, lint k, lint p) {\n        lint res = 1;\n        for(; k>0; k>>=1) {\n \
    \           if(k & 1) (res *= x) %= p;\n            (x *= x) %= p;\n        }\n\
    \        return res;\n    }\n\n    lint mod_inv(lint x, lint p) {\n        return\
    \ mod_pow(x, p-2, p);\n    }\n\n    // \u30EB\u30B8\u30E3\u30F3\u30C9\u30EB\u8A18\
    \u53F7 (a/p) = a^{\\frac{p-1}{2}} (p \u304C\u5947\u7D20\u6570\u306E\u5834\u5408\
    )\n    // (a/p) =  0 ... a = 0 (mod p)\n    // (a/p) =  1 ... a \u304C p \u3092\
    \u6CD5\u3068\u3057\u3066\u5E73\u65B9\u5270\u4F59\n    // (a/p) = -1 ... a \u304C\
    \ p \u3092\u6CD5\u3068\u3057\u3066\u5E73\u65B9\u5270\u4F59\u3067\u306A\u3044\n\
    \    // \u5E73\u65B9\u6839\u306E\u89E3\u306E\u5B58\u5728\u304C\u3053\u308C\u3067\
    \u78BA\u8A8D\u3067\u304D\u308B\n    lint Legendre(lint a, lint p) {\n        if(a\
    \ % p == 0) return 0;\n        lint res = mod_pow(a, (p-1)/2, p);\n        if(res\
    \ == p-1) return -1;\n        return res;\n    }\n\n    // r^2 = n (mod p) \u306A\
    \u308B r \u3092\u6C42\u3081\u308B (mod p \u4E0A\u3067\u306E n \u306E\u5E73\u65B9\
    \u6839)\n    vector<lint> TonelliShanks(lint n, lint p) {\n        if(Legendre(n,\
    \ p) == -1) return {};\n        if(p == 2) {\n            if(n == 0) return {0};\n\
    \            if(n == 1) return {1};\n        }\n\n        lint Q = p - 1, S =\
    \ 0;\n        while(Q % 2 == 0) Q /= 2, S++;\n\n        lint z = 2;\n        while(z\
    \ < p and Legendre(z, p) != -1) z++;\n        if(z == p) return {};\n        \n\
    \        lint M = S;\n        lint c = mod_pow(z, Q, p);\n        lint t = mod_pow(n,\
    \ Q, p);\n        lint R = mod_pow(n, (Q+1)/2, p);\n\n        lint r = -1;\n \
    \       while(1) {\n            if(t == 0) { r = 0; break; }\n            if(t\
    \ == 1) { r = R; break; }\n\n            lint i = 1, tt = t * t % p;\n       \
    \     for(i=1; i<M; i++) {\n                if(tt == 1) break;\n             \
    \   tt = tt * tt % p;\n            }\n            if(i == M) return {};\n\n  \
    \          lint b = c;\n            for(lint j=0; j<M-i-1; j++) {\n          \
    \      b = b * b % p;\n            }\n            \n            M = i;\n     \
    \       c = b * b % p;\n            t = t * c % p;\n            R = R * b % p;\n\
    \        }\n\n        vector<lint> ans;\n        ans.push_back(r);\n        if(r\
    \ != p - r) ans.push_back(p - r);\n        return ans;\n    }\n};\n#line 8 \"\
    math/verify/verify_math_016_mod_sqrt.cpp\"\n\n// Verified on Apr 09, 2019\n//\
    \ yukicoder No.551: \u590F\u4F11\u307F\u306E\u601D\u3044\u51FA (2)\n// Judge:\
    \ https://yukicoder.me/problems/no/551\nvoid yuki_551() {\n    using lint = long\
    \ long int;\n    lint P, R, Q; cin >> P >> R >> Q;\n    QuadraticResidue qr;\n\
    \    while(Q--) {\n        lint A, B, C; scanf(\"%lld%lld%lld\", &A, &B, &C);\n\
    \        lint r = qr.mod_inv(A, P);\n        (A *= r) %= P;\n        (B *= r)\
    \ %= P;\n        (C *= r) %= P;\n        (B *= qr.mod_inv(2, P)) %= P;\n\n   \
    \     lint D = (P - C + (B*B%P)) % P;\n        if(D == 0) {\n            printf(\"\
    %lld\\n\", (P - B) % P);\n        }\n        else {\n            // D \u306E\u5E73\
    \u65B9\u6839\u3092\u6C42\u3081\u308B\n            vector<lint> ks = qr.TonelliShanks(D,\
    \ P);\n            if(ks.size() == 0) {\n                printf(\"-1\\n\");\n\
    \            }\n            else {\n                lint X = (2*P + ks[0] - B)\
    \ % P;\n                lint Y = (2*P + ks[1] - B) % P;\n                if(X\
    \ > Y) swap(X, Y);\n                printf(\"%lld %lld\\n\", X, Y);\n        \
    \    }\n        }\n    }\n}\n\nint main() {\n    yuki_551();\n}\n"
  code: "#include <cstdio>\n#include <vector>\n#include <iostream>\n#include <algorithm>\n\
    #include <random>\nusing namespace std;\n#include \"../math_016_mod_sqrt.cpp\"\
    \n\n// Verified on Apr 09, 2019\n// yukicoder No.551: \u590F\u4F11\u307F\u306E\
    \u601D\u3044\u51FA (2)\n// Judge: https://yukicoder.me/problems/no/551\nvoid yuki_551()\
    \ {\n    using lint = long long int;\n    lint P, R, Q; cin >> P >> R >> Q;\n\
    \    QuadraticResidue qr;\n    while(Q--) {\n        lint A, B, C; scanf(\"%lld%lld%lld\"\
    , &A, &B, &C);\n        lint r = qr.mod_inv(A, P);\n        (A *= r) %= P;\n \
    \       (B *= r) %= P;\n        (C *= r) %= P;\n        (B *= qr.mod_inv(2, P))\
    \ %= P;\n\n        lint D = (P - C + (B*B%P)) % P;\n        if(D == 0) {\n   \
    \         printf(\"%lld\\n\", (P - B) % P);\n        }\n        else {\n     \
    \       // D \u306E\u5E73\u65B9\u6839\u3092\u6C42\u3081\u308B\n            vector<lint>\
    \ ks = qr.TonelliShanks(D, P);\n            if(ks.size() == 0) {\n           \
    \     printf(\"-1\\n\");\n            }\n            else {\n                lint\
    \ X = (2*P + ks[0] - B) % P;\n                lint Y = (2*P + ks[1] - B) % P;\n\
    \                if(X > Y) swap(X, Y);\n                printf(\"%lld %lld\\n\"\
    , X, Y);\n            }\n        }\n    }\n}\n\nint main() {\n    yuki_551();\n\
    }\n"
  dependsOn:
  - math/math_016_mod_sqrt.cpp
  isVerificationFile: false
  path: math/verify/verify_math_016_mod_sqrt.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_016_mod_sqrt.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_016_mod_sqrt.cpp
- /library/math/verify/verify_math_016_mod_sqrt.cpp.html
title: math/verify/verify_math_016_mod_sqrt.cpp
---
