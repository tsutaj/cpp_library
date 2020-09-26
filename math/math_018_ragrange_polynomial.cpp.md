---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_018_ragrange_polynomial.cpp
    title: math/verify/verify_math_018_ragrange_polynomial.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_018_ragrange_polynomial.cpp\"\nll mod_pow(ll n,\
    \ ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1) {\r\n        if(k\
    \ & 1) (res *= n) %= mod;\r\n        (n *= n) %= mod;\r\n    }\r\n    return res;\r\
    \n}\r\n\r\n// N \u672A\u6E80\u306E\u7BC4\u56F2\u3067\u3001i \u306E\u9006\u5143\
    \ (mod P) \u3092\u914D\u5217\u306B\u899A\u3048\u308B\r\ntemplate <typename NumType>\r\
    \nvector<NumType> get_inv_table(int N, int P) {\r\n    vector<NumType> res;\r\n\
    \    for(int i=0; i<N; i++) {\r\n        res.emplace_back(NumType(mod_pow(i, P-2,\
    \ P)));\r\n    }\r\n    return res;\r\n}\r\n\r\n// \u30E9\u30B0\u30E9\u30F3\u30B8\
    \u30E5\u88DC\u9593\r\n// \u89B3\u6E2C\u3055\u308C\u305F (x_i, y_i) \u3092\u5143\
    \u306B\u591A\u9805\u5F0F\u3092\u88DC\u9593\r\n// \u5143\u306E\u5F0F\u304C N \u6B21\
    \u5F0F\u3067 N+1 \u500B\u306E\u70B9\u304C\u89B3\u6E2C\u3055\u308C\u3066\u3044\u308B\
    \u5834\u5408\u306F\u5143\u306E\u5F0F\u304C\u5FA9\u5143\u53EF\u80FD\r\n// \u89B3\
    \u6E2C\u3055\u308C\u305F\u70B9\u3092 N \u3068\u3059\u308B\u3068 O(N^2) \u3067\u52D5\
    \u304F\r\ntemplate <typename NumType>\r\nstruct LagrangePolynomial {\r\n    vector<NumType>\
    \ x, y, f_table, inv_table;\r\n    bool use_inv_table;\r\n    LagrangePolynomial()\
    \ : x(), y() {}\r\n    LagrangePolynomial(vector<NumType> x_,\r\n            \
    \           vector<NumType> y_,\r\n                       int P=-1)\r\n      \
    \  : x(x_), y(y_), use_inv_table(P > 0) {\r\n\r\n        int N = x.size();\r\n\
    \        for(int i=0; i<N; i++) {\r\n            f_table.emplace_back(f(i, x[i]));\r\
    \n        }\r\n\r\n        // get_inv_table \u304C\u306A\u3044\u3068 CE \u306B\
    \u306A\u308B\u306E\u3067\u3001\r\n        // \u30B3\u30D4\u30DA\u304C\u9762\u5012\
    \u306A\u3089\u3053\u3053\u3092\u6D88\u3059 (\u6700\u60AA)\r\n        if(use_inv_table)\
    \ {\r\n            inv_table = get_inv_table<NumType>(P, P);\r\n        }\r\n\
    \    }\r\n\r\n    NumType f(int i, NumType p) {\r\n        int N = x.size();\r\
    \n        NumType res(1);\r\n        for(int k=0; k<N; k++) {\r\n            if(i\
    \ == k) continue;\r\n            res *= NumType(p - x[k]);\r\n        }\r\n  \
    \      return res;\r\n    }\r\n\r\n    NumType interpolate(NumType p) {\r\n  \
    \      int N = x.size();\r\n        NumType res(0);\r\n        for(int i=0; i<N;\
    \ i++) {\r\n            if(use_inv_table) {\r\n                res += y[i] * f(i,\
    \ p) * inv_table[ int(f_table[i]) ];\r\n            }\r\n            else {\r\n\
    \                res += y[i] * f(i, p) / f_table[i];\r\n            }\r\n    \
    \    }\r\n        return res;\r\n    }\r\n};\r\n"
  code: "ll mod_pow(ll n, ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1)\
    \ {\r\n        if(k & 1) (res *= n) %= mod;\r\n        (n *= n) %= mod;\r\n  \
    \  }\r\n    return res;\r\n}\r\n\r\n// N \u672A\u6E80\u306E\u7BC4\u56F2\u3067\u3001\
    i \u306E\u9006\u5143 (mod P) \u3092\u914D\u5217\u306B\u899A\u3048\u308B\r\ntemplate\
    \ <typename NumType>\r\nvector<NumType> get_inv_table(int N, int P) {\r\n    vector<NumType>\
    \ res;\r\n    for(int i=0; i<N; i++) {\r\n        res.emplace_back(NumType(mod_pow(i,\
    \ P-2, P)));\r\n    }\r\n    return res;\r\n}\r\n\r\n// \u30E9\u30B0\u30E9\u30F3\
    \u30B8\u30E5\u88DC\u9593\r\n// \u89B3\u6E2C\u3055\u308C\u305F (x_i, y_i) \u3092\
    \u5143\u306B\u591A\u9805\u5F0F\u3092\u88DC\u9593\r\n// \u5143\u306E\u5F0F\u304C\
    \ N \u6B21\u5F0F\u3067 N+1 \u500B\u306E\u70B9\u304C\u89B3\u6E2C\u3055\u308C\u3066\
    \u3044\u308B\u5834\u5408\u306F\u5143\u306E\u5F0F\u304C\u5FA9\u5143\u53EF\u80FD\
    \r\n// \u89B3\u6E2C\u3055\u308C\u305F\u70B9\u3092 N \u3068\u3059\u308B\u3068 O(N^2)\
    \ \u3067\u52D5\u304F\r\ntemplate <typename NumType>\r\nstruct LagrangePolynomial\
    \ {\r\n    vector<NumType> x, y, f_table, inv_table;\r\n    bool use_inv_table;\r\
    \n    LagrangePolynomial() : x(), y() {}\r\n    LagrangePolynomial(vector<NumType>\
    \ x_,\r\n                       vector<NumType> y_,\r\n                      \
    \ int P=-1)\r\n        : x(x_), y(y_), use_inv_table(P > 0) {\r\n\r\n        int\
    \ N = x.size();\r\n        for(int i=0; i<N; i++) {\r\n            f_table.emplace_back(f(i,\
    \ x[i]));\r\n        }\r\n\r\n        // get_inv_table \u304C\u306A\u3044\u3068\
    \ CE \u306B\u306A\u308B\u306E\u3067\u3001\r\n        // \u30B3\u30D4\u30DA\u304C\
    \u9762\u5012\u306A\u3089\u3053\u3053\u3092\u6D88\u3059 (\u6700\u60AA)\r\n    \
    \    if(use_inv_table) {\r\n            inv_table = get_inv_table<NumType>(P,\
    \ P);\r\n        }\r\n    }\r\n\r\n    NumType f(int i, NumType p) {\r\n     \
    \   int N = x.size();\r\n        NumType res(1);\r\n        for(int k=0; k<N;\
    \ k++) {\r\n            if(i == k) continue;\r\n            res *= NumType(p -\
    \ x[k]);\r\n        }\r\n        return res;\r\n    }\r\n\r\n    NumType interpolate(NumType\
    \ p) {\r\n        int N = x.size();\r\n        NumType res(0);\r\n        for(int\
    \ i=0; i<N; i++) {\r\n            if(use_inv_table) {\r\n                res +=\
    \ y[i] * f(i, p) * inv_table[ int(f_table[i]) ];\r\n            }\r\n        \
    \    else {\r\n                res += y[i] * f(i, p) / f_table[i];\r\n       \
    \     }\r\n        }\r\n        return res;\r\n    }\r\n};\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_018_ragrange_polynomial.cpp
  requiredBy:
  - math/verify/verify_math_018_ragrange_polynomial.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_018_ragrange_polynomial.cpp
layout: document
redirect_from:
- /library/math/math_018_ragrange_polynomial.cpp
- /library/math/math_018_ragrange_polynomial.cpp.html
title: math/math_018_ragrange_polynomial.cpp
---
