---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_013_ntt.cpp\"\n// NTT (\u5270\u4F59\u74B0\u3092\
    \u7528\u3044\u305F FFT)\n// \u4EFB\u610F mod \u3067\u3084\u308B\u306A\u3089\u3001\
    garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 + \u30E9\u30A4\u30D6\u30E9\u30EA\
    \u4E0B\u90E8\u304C\u5FC5\u9808\n// mod 998244353 \u306A\u3089 NTT<998244353, 5>\
    \ ntt; \u3068\u304B\u3067\u5341\u5206\u3067\u3059\n\ntemplate<ll mod, ll primitive_root>\n\
    struct NTT {\n    int get_mod() const { return mod; }\n    static const int P\
    \ = 22;\n    ll zs[P+1], zinvs[P+1];\n\n    ll mod_pow(ll n, ll k) const {\n \
    \       ll res = 1;\n        for(; k>0; k>>=1) {\n            if(k & 1) (res *=\
    \ n) %= mod;\n            (n *= n) %= mod;\n        }\n        return res;\n \
    \   }\n    \n    NTT() {\n        zs[P] = mod_pow(primitive_root, (mod - 1) >>\
    \ P);\n        zinvs[P] = mod_pow(zs[P], mod - 2);\n        for(int k=P-1; k>=1;\
    \ k--) {\n            zs[k] = zs[k+1] * zs[k+1] % mod;\n            zinvs[k] =\
    \ zinvs[k+1] * zinvs[k+1] % mod;\n        }\n    }\n\n    void dft(vector<ll>\
    \ &A, int K, int sgn = 1) {\n        int N = 1 << K;\n        for(int i=0, j=1;\
    \ j<N-1; j++) {\n            for(int k=N >> 1; k>(i ^= k); k >>= 1);\n       \
    \     if(j < i) swap(A[i], A[j]);\n        }\n        \n        for(int m=2, k=1;\
    \ m<=N; m <<= 1, k++) {\n            ll zeta = (sgn < 0 ? zinvs[k] : zs[k]);\n\
    \            for(int i=0; i<N; i+=m) {\n                ll zeta_pow = 1LL;\n \
    \               for(int u=i, v=i+(m>>1); v<i+m; u++, v++) {\n                \
    \    ll vl = A[u];\n                    ll vr = zeta_pow * A[v] % mod;\n     \
    \               A[u] = vl + vr;\n                    A[v] = vl - vr + mod;\n \
    \                   if(A[u] >= mod) A[u] -= mod;\n                    if(A[v]\
    \ >= mod) A[v] -= mod;\n                    (zeta_pow *= zeta) %= mod;\n     \
    \           }\n            }\n        }\n    }\n\n    vector<ll> multiply(const\
    \ vector<ll> &x, const vector<ll> &y) {\n        if(x == y) return multiply(x);\n\
    \        int sz = x.size() + y.size() - 1;\n        int N = 1, K = 0; while(N\
    \ < sz) N <<= 1, K++;\n        ll inv_N = mod_pow(N, mod-2);\n\n        vector<ll>\
    \ X(N), Y(N);\n        for(size_t i=0; i<x.size(); i++) X[i] = x[i];\n       \
    \ for(size_t i=0; i<y.size(); i++) Y[i] = y[i];\n        dft(X, K), dft(Y, K);\n\
    \        \n        for(int i=0; i<N; i++) (X[i] *= Y[i]) %= mod;\n        dft(X,\
    \ K, -1);\n\n        for(int i=0; i<sz; i++) (X[i] *= inv_N) %= mod;\n       \
    \ X.resize(sz);\n        return X;\n    }\n\n    vector<ll> multiply(const vector<ll>\
    \ &x) {\n        int sz = x.size() + x.size() - 1;\n        int N = 1, K = 0;\
    \ while(N < sz) N <<= 1, K++;\n        ll inv_N = mod_pow(N, mod-2);\n\n     \
    \   vector<ll> X(N);\n        for(size_t i=0; i<x.size(); i++) X[i] = x[i];\n\
    \        dft(X, K);\n\n        for(int i=0; i<N; i++) (X[i] *= X[i]) %= mod;\n\
    \        dft(X, K, -1);\n\n        for(int i=0; i<sz; i++) (X[i] *= inv_N) %=\
    \ mod;\n        X.resize(sz);\n        return X;\n    }\n};\n\nusing NTT_1 = NTT<\
    \ 167772161, 3>;\nusing NTT_2 = NTT< 469762049, 3>;\nusing NTT_3 = NTT<1224736769,\
    \ 3>;\n\nvector<ll> convolution_using_ntt(vector<ll> A, vector<ll> B, ll mod)\
    \ {\n    for(auto &x : A) x %= mod;\n    for(auto &x : B) x %= mod;\n\n    NTT_1\
    \ ntt_1; NTT_2 ntt_2; NTT_3 ntt_3;\n    vector< vector<ll> > convo(3);\n    convo[0]\
    \ = ntt_1.multiply(A, B);\n    convo[1] = ntt_2.multiply(A, B);\n    convo[2]\
    \ = ntt_3.multiply(A, B);\n\n    int N = convo[0].size();\n    vector<ll> ret(N),\
    \ mods(3);\n    mods[0] = ntt_1.get_mod();\n    mods[1] = ntt_2.get_mod();\n \
    \   mods[2] = ntt_3.get_mod();\n\n    for(int i=0; i<N; i++) {\n        vector<ll>\
    \ values(3);\n        for(int k=0; k<3; k++) {\n            values[k] = convo[k][i];\n\
    \        }\n        ret[i] = garner(values, mods, mod);\n    }\n    return ret;\n\
    }\n"
  code: "// NTT (\u5270\u4F59\u74B0\u3092\u7528\u3044\u305F FFT)\n// \u4EFB\u610F\
    \ mod \u3067\u3084\u308B\u306A\u3089\u3001garner \u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 + \u30E9\u30A4\u30D6\u30E9\u30EA\u4E0B\u90E8\u304C\u5FC5\u9808\n\
    // mod 998244353 \u306A\u3089 NTT<998244353, 5> ntt; \u3068\u304B\u3067\u5341\u5206\
    \u3067\u3059\n\ntemplate<ll mod, ll primitive_root>\nstruct NTT {\n    int get_mod()\
    \ const { return mod; }\n    static const int P = 22;\n    ll zs[P+1], zinvs[P+1];\n\
    \n    ll mod_pow(ll n, ll k) const {\n        ll res = 1;\n        for(; k>0;\
    \ k>>=1) {\n            if(k & 1) (res *= n) %= mod;\n            (n *= n) %=\
    \ mod;\n        }\n        return res;\n    }\n    \n    NTT() {\n        zs[P]\
    \ = mod_pow(primitive_root, (mod - 1) >> P);\n        zinvs[P] = mod_pow(zs[P],\
    \ mod - 2);\n        for(int k=P-1; k>=1; k--) {\n            zs[k] = zs[k+1]\
    \ * zs[k+1] % mod;\n            zinvs[k] = zinvs[k+1] * zinvs[k+1] % mod;\n  \
    \      }\n    }\n\n    void dft(vector<ll> &A, int K, int sgn = 1) {\n       \
    \ int N = 1 << K;\n        for(int i=0, j=1; j<N-1; j++) {\n            for(int\
    \ k=N >> 1; k>(i ^= k); k >>= 1);\n            if(j < i) swap(A[i], A[j]);\n \
    \       }\n        \n        for(int m=2, k=1; m<=N; m <<= 1, k++) {\n       \
    \     ll zeta = (sgn < 0 ? zinvs[k] : zs[k]);\n            for(int i=0; i<N; i+=m)\
    \ {\n                ll zeta_pow = 1LL;\n                for(int u=i, v=i+(m>>1);\
    \ v<i+m; u++, v++) {\n                    ll vl = A[u];\n                    ll\
    \ vr = zeta_pow * A[v] % mod;\n                    A[u] = vl + vr;\n         \
    \           A[v] = vl - vr + mod;\n                    if(A[u] >= mod) A[u] -=\
    \ mod;\n                    if(A[v] >= mod) A[v] -= mod;\n                   \
    \ (zeta_pow *= zeta) %= mod;\n                }\n            }\n        }\n  \
    \  }\n\n    vector<ll> multiply(const vector<ll> &x, const vector<ll> &y) {\n\
    \        if(x == y) return multiply(x);\n        int sz = x.size() + y.size()\
    \ - 1;\n        int N = 1, K = 0; while(N < sz) N <<= 1, K++;\n        ll inv_N\
    \ = mod_pow(N, mod-2);\n\n        vector<ll> X(N), Y(N);\n        for(size_t i=0;\
    \ i<x.size(); i++) X[i] = x[i];\n        for(size_t i=0; i<y.size(); i++) Y[i]\
    \ = y[i];\n        dft(X, K), dft(Y, K);\n        \n        for(int i=0; i<N;\
    \ i++) (X[i] *= Y[i]) %= mod;\n        dft(X, K, -1);\n\n        for(int i=0;\
    \ i<sz; i++) (X[i] *= inv_N) %= mod;\n        X.resize(sz);\n        return X;\n\
    \    }\n\n    vector<ll> multiply(const vector<ll> &x) {\n        int sz = x.size()\
    \ + x.size() - 1;\n        int N = 1, K = 0; while(N < sz) N <<= 1, K++;\n   \
    \     ll inv_N = mod_pow(N, mod-2);\n\n        vector<ll> X(N);\n        for(size_t\
    \ i=0; i<x.size(); i++) X[i] = x[i];\n        dft(X, K);\n\n        for(int i=0;\
    \ i<N; i++) (X[i] *= X[i]) %= mod;\n        dft(X, K, -1);\n\n        for(int\
    \ i=0; i<sz; i++) (X[i] *= inv_N) %= mod;\n        X.resize(sz);\n        return\
    \ X;\n    }\n};\n\nusing NTT_1 = NTT< 167772161, 3>;\nusing NTT_2 = NTT< 469762049,\
    \ 3>;\nusing NTT_3 = NTT<1224736769, 3>;\n\nvector<ll> convolution_using_ntt(vector<ll>\
    \ A, vector<ll> B, ll mod) {\n    for(auto &x : A) x %= mod;\n    for(auto &x\
    \ : B) x %= mod;\n\n    NTT_1 ntt_1; NTT_2 ntt_2; NTT_3 ntt_3;\n    vector< vector<ll>\
    \ > convo(3);\n    convo[0] = ntt_1.multiply(A, B);\n    convo[1] = ntt_2.multiply(A,\
    \ B);\n    convo[2] = ntt_3.multiply(A, B);\n\n    int N = convo[0].size();\n\
    \    vector<ll> ret(N), mods(3);\n    mods[0] = ntt_1.get_mod();\n    mods[1]\
    \ = ntt_2.get_mod();\n    mods[2] = ntt_3.get_mod();\n\n    for(int i=0; i<N;\
    \ i++) {\n        vector<ll> values(3);\n        for(int k=0; k<3; k++) {\n  \
    \          values[k] = convo[k][i];\n        }\n        ret[i] = garner(values,\
    \ mods, mod);\n    }\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_013_ntt.cpp
  requiredBy: []
  timestamp: '2020-09-27 03:55:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_013_ntt.cpp
layout: document
redirect_from:
- /library/math/math_013_ntt.cpp
- /library/math/math_013_ntt.cpp.html
title: math/math_013_ntt.cpp
---
