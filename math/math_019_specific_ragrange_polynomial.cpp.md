---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
    title: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_019_specific_ragrange_polynomial.cpp\"\nll mod_pow(ll\
    \ n, ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1) {\r\n       \
    \ if(k & 1) (res *= n) %= mod;\r\n        (n *= n) %= mod;\r\n    }\r\n    return\
    \ res;\r\n}\r\n\r\n// N \u672A\u6E80\u306E\u7BC4\u56F2\u3067\u3001i \u306E\u9006\
    \u5143 (mod P) \u3092\u914D\u5217\u306B\u899A\u3048\u308B\r\ntemplate <typename\
    \ NumType>\r\nvector<NumType> get_inv_table(int N, int P) {\r\n    vector<NumType>\
    \ res;\r\n    for(int i=0; i<N; i++) {\r\n        res.emplace_back(NumType(mod_pow(i,\
    \ P-2, P)));\r\n    }\r\n    return res;\r\n}\r\n\r\n// f(0) ... f(N) \u306E\u5024\
    \u304C\u308F\u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\r\n// \u591A\u9805\
    \u5F0F\u88DC\u9593\u3092 O(N) \u3067\u5B9F\u73FE\u3059\u308B\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306E\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\r\ntemplate\
    \ <typename NumType, int LIMIT = 2000010>\r\nstruct SpecificLagrangePolynomial\
    \ {\r\n    Combination<NumType> comb;\r\n    vector<NumType> y, inv_table;\r\n\
    \    bool use_inv_table;\r\n    SpecificLagrangePolynomial() : comb(), y() {}\r\
    \n    SpecificLagrangePolynomial(vector<NumType> y_, int P=LIMIT)\r\n        :\
    \ comb(min(LIMIT, P-1)), y(y_), use_inv_table(false) {\r\n        if(P < LIMIT)\
    \ use_inv_table = true;\r\n        \r\n        // get_inv_table \u304C\u306A\u3044\
    \u3068 CE \u306B\u306A\u308B\u306E\u3067\u3001\r\n        // \u30B3\u30D4\u30DA\
    \u304C\u9762\u5012\u306A\u3089\u3053\u3053\u3092\u6D88\u3059 (\u6700\u60AA)\r\n\
    \        if(use_inv_table) {\r\n            inv_table = get_inv_table<NumType>(P,\
    \ P);\r\n        }\r\n    }\r\n\r\n    NumType interpolate(NumType p) {\r\n  \
    \      NumType pre(1);\r\n        int N = y.size(), pv = int(p);\r\n        if(pv\
    \ < N) return y[pv];\r\n        for(int i=0; i<N; i++) {\r\n            pre *=\
    \ NumType(pv - i);\r\n        }\r\n        \r\n        NumType res(0);\r\n   \
    \     for(int i=0; i<N; i++) {\r\n            NumType numer(0), denom(1);\r\n\
    \            if(use_inv_table)\r\n                numer = pre * inv_table[pv -\
    \ i];\r\n            else\r\n                numer = pre / NumType(pv - i);\r\n\
    \r\n            denom *= comb.finv(N - 1 - i) * comb.finv(i);\r\n            if((N\
    \ - 1 - i) % 2) res -= numer * denom * y[i];\r\n            else res += numer\
    \ * denom * y[i];\r\n        }\r\n        return res;\r\n    }\r\n};\r\n"
  code: "ll mod_pow(ll n, ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1)\
    \ {\r\n        if(k & 1) (res *= n) %= mod;\r\n        (n *= n) %= mod;\r\n  \
    \  }\r\n    return res;\r\n}\r\n\r\n// N \u672A\u6E80\u306E\u7BC4\u56F2\u3067\u3001\
    i \u306E\u9006\u5143 (mod P) \u3092\u914D\u5217\u306B\u899A\u3048\u308B\r\ntemplate\
    \ <typename NumType>\r\nvector<NumType> get_inv_table(int N, int P) {\r\n    vector<NumType>\
    \ res;\r\n    for(int i=0; i<N; i++) {\r\n        res.emplace_back(NumType(mod_pow(i,\
    \ P-2, P)));\r\n    }\r\n    return res;\r\n}\r\n\r\n// f(0) ... f(N) \u306E\u5024\
    \u304C\u308F\u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\r\n// \u591A\u9805\
    \u5F0F\u88DC\u9593\u3092 O(N) \u3067\u5B9F\u73FE\u3059\u308B\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306E\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\r\ntemplate\
    \ <typename NumType, int LIMIT = 2000010>\r\nstruct SpecificLagrangePolynomial\
    \ {\r\n    Combination<NumType> comb;\r\n    vector<NumType> y, inv_table;\r\n\
    \    bool use_inv_table;\r\n    SpecificLagrangePolynomial() : comb(), y() {}\r\
    \n    SpecificLagrangePolynomial(vector<NumType> y_, int P=LIMIT)\r\n        :\
    \ comb(min(LIMIT, P-1)), y(y_), use_inv_table(false) {\r\n        if(P < LIMIT)\
    \ use_inv_table = true;\r\n        \r\n        // get_inv_table \u304C\u306A\u3044\
    \u3068 CE \u306B\u306A\u308B\u306E\u3067\u3001\r\n        // \u30B3\u30D4\u30DA\
    \u304C\u9762\u5012\u306A\u3089\u3053\u3053\u3092\u6D88\u3059 (\u6700\u60AA)\r\n\
    \        if(use_inv_table) {\r\n            inv_table = get_inv_table<NumType>(P,\
    \ P);\r\n        }\r\n    }\r\n\r\n    NumType interpolate(NumType p) {\r\n  \
    \      NumType pre(1);\r\n        int N = y.size(), pv = int(p);\r\n        if(pv\
    \ < N) return y[pv];\r\n        for(int i=0; i<N; i++) {\r\n            pre *=\
    \ NumType(pv - i);\r\n        }\r\n        \r\n        NumType res(0);\r\n   \
    \     for(int i=0; i<N; i++) {\r\n            NumType numer(0), denom(1);\r\n\
    \            if(use_inv_table)\r\n                numer = pre * inv_table[pv -\
    \ i];\r\n            else\r\n                numer = pre / NumType(pv - i);\r\n\
    \r\n            denom *= comb.finv(N - 1 - i) * comb.finv(i);\r\n            if((N\
    \ - 1 - i) % 2) res -= numer * denom * y[i];\r\n            else res += numer\
    \ * denom * y[i];\r\n        }\r\n        return res;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_019_specific_ragrange_polynomial.cpp
  requiredBy:
  - math/verify/verify_math_019_specific_ragrange_polynomial.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_019_specific_ragrange_polynomial.cpp
layout: document
redirect_from:
- /library/math/math_019_specific_ragrange_polynomial.cpp
- /library/math/math_019_specific_ragrange_polynomial.cpp.html
title: math/math_019_specific_ragrange_polynomial.cpp
---
