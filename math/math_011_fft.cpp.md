---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_011_fft.cpp\"\n// FFT (\u9AD8\u901F\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB)\n// Verified: \u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\
    \u63DB (ATC 001 C)\ntemplate < typename Tp = complex<double> >\nstruct FFT {\n\
    \    static constexpr long double PI = acos(-1.0L);\n    static constexpr int\
    \ P = 22;\n    Tp zs[P+1], zinvs[P+1];\n\n    FFT () {\n        for(int i=0, m=1;\
    \ i<=P; i++, m<<=1) {\n            long double rad = 2.0 * PI / m;\n         \
    \   long double cr = cos(rad), sr = sin(rad);\n            zs[i] = Tp(cr, sr);\n\
    \            zinvs[i] = Tp(cr, -sr);\n        }\n    }\n    \n    void dft(vector<Tp>\
    \ &A, int K, int sgn = 1) {\n        int N = 1 << K;\n        for(int i=0, j=1;\
    \ j<N-1; j++) {\n            for(int k=N >> 1; k>(i ^= k); k >>= 1);\n       \
    \     if(j < i) swap(A[i], A[j]);\n        }\n\n        for(int m=2, k=1; m<=N;\
    \ m<<=1, k++) {\n            Tp zeta = (sgn < 0 ? zinvs[k] : zs[k]);\n\n     \
    \       for(int i=0; i<N; i+=m) {\n                Tp zeta_pow = 1;\n        \
    \        for(int u=i, v=i+m/2; v<i+m; u++, v++) {\n                    Tp vl =\
    \ A[u], vr = zeta_pow * A[v];\n                    A[u] = vl + vr;\n         \
    \           A[v] = vl - vr;\n                    zeta_pow = zeta_pow * zeta;\n\
    \                }\n            }\n        }\n    }\n\n    vector<Tp> multiply(const\
    \ vector<Tp> &x, const vector<Tp> &y) {\n        int sz = x.size() + y.size()\
    \ - 1;\n        int N = 1, K = 0; while(N < sz) N <<= 1, K++;\n\n        vector<Tp>\
    \ X(N), Y(N);\n        for(size_t i=0; i<x.size(); i++) X[i] = x[i];\n       \
    \ for(size_t i=0; i<y.size(); i++) Y[i] = y[i];\n        dft(X, K), dft(Y, K);\n\
    \n        for(int i=0; i<N; i++) X[i] *= Y[i];\n        dft(X, K, -1);\n     \
    \   for(int i=0; i<sz; i++) X[i] /= N;\n        X.resize(sz);\n        return\
    \ X;\n    }\n\n    vector<Tp> multiply(const vector<Tp> &x) {\n        int sz\
    \ = x.size() + x.size() - 1;\n        int N = 1, K = 0; while(N < sz) N <<= 1,\
    \ K++;\n\n        vector<Tp> X(N);\n        for(size_t i=0; i<x.size(); i++) X[i]\
    \ = x[i];\n        dft(X, K);\n\n        for(int i=0; i<N; i++) X[i] *= X[i];\n\
    \        dft(X, K, -1);\n        for(int i=0; i<sz; i++) X[i] /= N;\n        X.resize(sz);\n\
    \        return X;\n    }\n};\n"
  code: "// FFT (\u9AD8\u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB)\n// Verified: \u9AD8\
    \u901F\u30D5\u30FC\u30EA\u30A8\u5909\u63DB (ATC 001 C)\ntemplate < typename Tp\
    \ = complex<double> >\nstruct FFT {\n    static constexpr long double PI = acos(-1.0L);\n\
    \    static constexpr int P = 22;\n    Tp zs[P+1], zinvs[P+1];\n\n    FFT () {\n\
    \        for(int i=0, m=1; i<=P; i++, m<<=1) {\n            long double rad =\
    \ 2.0 * PI / m;\n            long double cr = cos(rad), sr = sin(rad);\n     \
    \       zs[i] = Tp(cr, sr);\n            zinvs[i] = Tp(cr, -sr);\n        }\n\
    \    }\n    \n    void dft(vector<Tp> &A, int K, int sgn = 1) {\n        int N\
    \ = 1 << K;\n        for(int i=0, j=1; j<N-1; j++) {\n            for(int k=N\
    \ >> 1; k>(i ^= k); k >>= 1);\n            if(j < i) swap(A[i], A[j]);\n     \
    \   }\n\n        for(int m=2, k=1; m<=N; m<<=1, k++) {\n            Tp zeta =\
    \ (sgn < 0 ? zinvs[k] : zs[k]);\n\n            for(int i=0; i<N; i+=m) {\n   \
    \             Tp zeta_pow = 1;\n                for(int u=i, v=i+m/2; v<i+m; u++,\
    \ v++) {\n                    Tp vl = A[u], vr = zeta_pow * A[v];\n          \
    \          A[u] = vl + vr;\n                    A[v] = vl - vr;\n            \
    \        zeta_pow = zeta_pow * zeta;\n                }\n            }\n     \
    \   }\n    }\n\n    vector<Tp> multiply(const vector<Tp> &x, const vector<Tp>\
    \ &y) {\n        int sz = x.size() + y.size() - 1;\n        int N = 1, K = 0;\
    \ while(N < sz) N <<= 1, K++;\n\n        vector<Tp> X(N), Y(N);\n        for(size_t\
    \ i=0; i<x.size(); i++) X[i] = x[i];\n        for(size_t i=0; i<y.size(); i++)\
    \ Y[i] = y[i];\n        dft(X, K), dft(Y, K);\n\n        for(int i=0; i<N; i++)\
    \ X[i] *= Y[i];\n        dft(X, K, -1);\n        for(int i=0; i<sz; i++) X[i]\
    \ /= N;\n        X.resize(sz);\n        return X;\n    }\n\n    vector<Tp> multiply(const\
    \ vector<Tp> &x) {\n        int sz = x.size() + x.size() - 1;\n        int N =\
    \ 1, K = 0; while(N < sz) N <<= 1, K++;\n\n        vector<Tp> X(N);\n        for(size_t\
    \ i=0; i<x.size(); i++) X[i] = x[i];\n        dft(X, K);\n\n        for(int i=0;\
    \ i<N; i++) X[i] *= X[i];\n        dft(X, K, -1);\n        for(int i=0; i<sz;\
    \ i++) X[i] /= N;\n        X.resize(sz);\n        return X;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_011_fft.cpp
  requiredBy: []
  timestamp: '2020-09-27 03:55:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_011_fft.cpp
layout: document
redirect_from:
- /library/math/math_011_fft.cpp
- /library/math/math_011_fft.cpp.html
title: math/math_011_fft.cpp
---
