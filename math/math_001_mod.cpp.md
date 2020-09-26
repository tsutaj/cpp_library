---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_001_mod.cpp\"\n/***** \u6700\u5927\u516C\u7D04\
    \u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570 *****/\r\n// gcd (2\u3064\u306E\u6574\
    \u6570\u306B\u95A2\u3057\u3066\u3001\u6700\u5927\u516C\u7D04\u6570)\r\nint gcd(int\
    \ a, int b) {\r\n    if(a < b) swap(a, b);\r\n    if(b == 0) return a;\r\n   \
    \ return gcd(b, a%b);\r\n}\r\n\r\n// lcm (2\u3064\u306E\u6574\u6570\u306B\u95A2\
    \u3057\u3066\u3001\u6700\u5C0F\u516C\u500D\u6570) \u203Bgcd\u5B9F\u88C5\u524D\u63D0\
    \r\nint lcm(int a, int b) {\r\n    return a * b / gcd(a,b);\r\n}\r\n\r\n// extgcd\
    \ (ax + by = gcd(a,b) \u3092\u6E80\u305F\u3059x,y\u3092\u6C42\u3081\u308B)\r\n\
    // x\u3068y\u3067\u53C2\u7167\u3092\u4F7F\u7528\u3057\u3066\u3044\u308B\r\n//\
    \ (\u5B9F\u5F15\u6570\u3067\u6307\u5B9A\u3057\u305F\u5909\u6570\u306E\u4E2D\u8EAB\
    \u304C\u95A2\u6570\u306B\u3088\u3063\u3066\u66F8\u304D\u63DB\u308F\u308B)\r\n\
    int extgcd(int a, int b, int& x, int& y) {\r\n    int d = a;\r\n    if(b!=0) {\r\
    \n        d = extgcd(b, a%b, y, x);\r\n        y -= (a / b) * x;\r\n    }\r\n\
    \    else {\r\n        x = 1; y = 0;\r\n    }\r\n    return d;\r\n}\r\n\r\n//\
    \ \u9006\u5143\u3092\u6C42\u3081\u308B (ax \u2261 1 (mod m) \u306B\u5BFE\u3057\
    \u3066\u3001x\u3092\u6C42\u3081\u308B\u3002) \u203Bextgcd\u5B9F\u88C5\u524D\u63D0\
    \r\nint mod_inverse(int a, int m) {\r\n    int x,y;\r\n    extgcd(a,m,x,y);\r\n\
    \    return (m + x % m) % m; //\u6B63\u306E\u6574\u6570\u3092\u4FDD\u8A3C\r\n\
    }\r\n\r\n/***** \u7D44\u307F\u5408\u308F\u305B\u95A2\u4FC2 *****/\r\n// combination\
    \ O(N)\r\n\r\nconst int MAXN = 100010;\r\nlong long int fact[MAXN], inv[MAXN];\r\
    \n\r\nvoid init_fact() {\r\n    fact[0] = 1;\r\n    for(int i=1; i<MAXN; i++)\
    \ {\r\n        fact[i] = (fact[i-1] * i) % MOD;\r\n    }\r\n\r\n    inv[MAXN -\
    \ 1] = mod_pow(fact[MAXN - 1], MOD-2);\r\n    for(int i=MAXN - 2; i>=0; i--) {\r\
    \n        inv[i] = (inv[i+1] * (i+1)) % MOD;\r\n    }\r\n}\r\n\r\nlong long int\
    \ comb(int n, int r) {\r\n    if(r < 0 || n < r) return 0;\r\n    return fact[n]\
    \ * inv[n-r] % MOD * inv[r] % MOD;\r\n}\r\n\r\n// \u7E70\u308A\u8FD4\u3057\u4E8C\
    \u4E57\u6CD5 (mod\u306E\u4E16\u754C\u3067\u306E\u7D2F\u4E57)\r\n// \u203Bmod\u304C\
    \u7D20\u6570\u306E\u5834\u5408\u3001\u3053\u306E\u95A2\u6570\u3067(mod - 2)\u4E57\
    \u3057\u305F\u3089\u3001mod\u5272\u308A\u7B97\u304C\u3067\u304D\u308B\u3088\uFF01\
    \r\n// (\u53C2\u8003\u554F\u984C: ABC034 C\u554F\u984C\u306A\u3069)\r\nll mod_pow(ll\
    \ x, ll n) {\r\n    ll res = 1;\r\n    while(n > 0) {\r\n        if(n & 1) res\
    \ = (res * x) % MOD; //\u30D3\u30C3\u30C8\u6F14\u7B97(\u6700\u4E0B\u4F4D\u30D3\
    \u30C3\u30C8\u304C1\u306E\u3068\u304D)\r\n        x = (x * x) % MOD;\r\n     \
    \   n >>= 1; //\u53F3\u30B7\u30D5\u30C8(n = n >> 1)\r\n    }\r\n    return res;\r\
    \n}\r\n\r\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (\u518D\u5E30\u30D0\u30FC\
    \u30B8\u30E7\u30F3)\r\n// typedef long long ll;\r\nll mod_pow(ll x, ll n) {\r\n\
    \    if(n == 0) return 1;\r\n    ll res = mod_pow((x * x) % MOD, n / 2);\r\n \
    \   if(n & 1) res = (res * x) % MOD;\r\n    return res;\r\n}\r\n\r\n// \u7D44\u307F\
    \u5408\u308F\u305B nCr mod p \u3092\u6C42\u3081\u308B\r\nll combination_mod(ll\
    \ n, ll r) {\r\n    if(n < r) return 0;\r\n    if(r == 0 || r == n) return 1;\r\
    \n    ll a = fact[n];\r\n    ll b = fact[n-r];\r\n    ll c = fact[r];\r\n\r\n\
    \    ll x = a, y = (b * c) % MOD;\r\n    return ( x * mod_pow(y, MOD-2) ) % MOD;\r\
    \n}\r\n\r\n// \u7D44\u307F\u5408\u308F\u305B\u3092\u6C42\u3081\u308B (DP\u3001\
    \u30D1\u30B9\u30AB\u30EB\u306E\u4E09\u89D2\u5F62)\r\nconst int SIZE = 5000;\r\n\
    ll comb[SIZE+10][SIZE+10];\r\n\r\ncomb[0][0] = 1;\r\nfor(int i=0; i<SIZE; i++)\
    \ {\r\n    for(int j=0; j<SIZE; j++) {\r\n        (comb[i+1][j] += comb[i][j])\
    \ %= MOD;\r\n        (comb[i][j+1] += comb[i][j]) %= MOD;\r\n    }\r\n}\r\n"
  code: "/***** \u6700\u5927\u516C\u7D04\u6570\u30FB\u6700\u5C0F\u516C\u500D\u6570\
    \ *****/\r\n// gcd (2\u3064\u306E\u6574\u6570\u306B\u95A2\u3057\u3066\u3001\u6700\
    \u5927\u516C\u7D04\u6570)\r\nint gcd(int a, int b) {\r\n    if(a < b) swap(a,\
    \ b);\r\n    if(b == 0) return a;\r\n    return gcd(b, a%b);\r\n}\r\n\r\n// lcm\
    \ (2\u3064\u306E\u6574\u6570\u306B\u95A2\u3057\u3066\u3001\u6700\u5C0F\u516C\u500D\
    \u6570) \u203Bgcd\u5B9F\u88C5\u524D\u63D0\r\nint lcm(int a, int b) {\r\n    return\
    \ a * b / gcd(a,b);\r\n}\r\n\r\n// extgcd (ax + by = gcd(a,b) \u3092\u6E80\u305F\
    \u3059x,y\u3092\u6C42\u3081\u308B)\r\n// x\u3068y\u3067\u53C2\u7167\u3092\u4F7F\
    \u7528\u3057\u3066\u3044\u308B\r\n// (\u5B9F\u5F15\u6570\u3067\u6307\u5B9A\u3057\
    \u305F\u5909\u6570\u306E\u4E2D\u8EAB\u304C\u95A2\u6570\u306B\u3088\u3063\u3066\
    \u66F8\u304D\u63DB\u308F\u308B)\r\nint extgcd(int a, int b, int& x, int& y) {\r\
    \n    int d = a;\r\n    if(b!=0) {\r\n        d = extgcd(b, a%b, y, x);\r\n  \
    \      y -= (a / b) * x;\r\n    }\r\n    else {\r\n        x = 1; y = 0;\r\n \
    \   }\r\n    return d;\r\n}\r\n\r\n// \u9006\u5143\u3092\u6C42\u3081\u308B (ax\
    \ \u2261 1 (mod m) \u306B\u5BFE\u3057\u3066\u3001x\u3092\u6C42\u3081\u308B\u3002\
    ) \u203Bextgcd\u5B9F\u88C5\u524D\u63D0\r\nint mod_inverse(int a, int m) {\r\n\
    \    int x,y;\r\n    extgcd(a,m,x,y);\r\n    return (m + x % m) % m; //\u6B63\u306E\
    \u6574\u6570\u3092\u4FDD\u8A3C\r\n}\r\n\r\n/***** \u7D44\u307F\u5408\u308F\u305B\
    \u95A2\u4FC2 *****/\r\n// combination O(N)\r\n\r\nconst int MAXN = 100010;\r\n\
    long long int fact[MAXN], inv[MAXN];\r\n\r\nvoid init_fact() {\r\n    fact[0]\
    \ = 1;\r\n    for(int i=1; i<MAXN; i++) {\r\n        fact[i] = (fact[i-1] * i)\
    \ % MOD;\r\n    }\r\n\r\n    inv[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD-2);\r\
    \n    for(int i=MAXN - 2; i>=0; i--) {\r\n        inv[i] = (inv[i+1] * (i+1))\
    \ % MOD;\r\n    }\r\n}\r\n\r\nlong long int comb(int n, int r) {\r\n    if(r <\
    \ 0 || n < r) return 0;\r\n    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;\r\
    \n}\r\n\r\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5 (mod\u306E\u4E16\u754C\
    \u3067\u306E\u7D2F\u4E57)\r\n// \u203Bmod\u304C\u7D20\u6570\u306E\u5834\u5408\u3001\
    \u3053\u306E\u95A2\u6570\u3067(mod - 2)\u4E57\u3057\u305F\u3089\u3001mod\u5272\
    \u308A\u7B97\u304C\u3067\u304D\u308B\u3088\uFF01\r\n// (\u53C2\u8003\u554F\u984C\
    : ABC034 C\u554F\u984C\u306A\u3069)\r\nll mod_pow(ll x, ll n) {\r\n    ll res\
    \ = 1;\r\n    while(n > 0) {\r\n        if(n & 1) res = (res * x) % MOD; //\u30D3\
    \u30C3\u30C8\u6F14\u7B97(\u6700\u4E0B\u4F4D\u30D3\u30C3\u30C8\u304C1\u306E\u3068\
    \u304D)\r\n        x = (x * x) % MOD;\r\n        n >>= 1; //\u53F3\u30B7\u30D5\
    \u30C8(n = n >> 1)\r\n    }\r\n    return res;\r\n}\r\n\r\n// \u7E70\u308A\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5 (\u518D\u5E30\u30D0\u30FC\u30B8\u30E7\u30F3)\r\n// typedef\
    \ long long ll;\r\nll mod_pow(ll x, ll n) {\r\n    if(n == 0) return 1;\r\n  \
    \  ll res = mod_pow((x * x) % MOD, n / 2);\r\n    if(n & 1) res = (res * x) %\
    \ MOD;\r\n    return res;\r\n}\r\n\r\n// \u7D44\u307F\u5408\u308F\u305B nCr mod\
    \ p \u3092\u6C42\u3081\u308B\r\nll combination_mod(ll n, ll r) {\r\n    if(n <\
    \ r) return 0;\r\n    if(r == 0 || r == n) return 1;\r\n    ll a = fact[n];\r\n\
    \    ll b = fact[n-r];\r\n    ll c = fact[r];\r\n\r\n    ll x = a, y = (b * c)\
    \ % MOD;\r\n    return ( x * mod_pow(y, MOD-2) ) % MOD;\r\n}\r\n\r\n// \u7D44\u307F\
    \u5408\u308F\u305B\u3092\u6C42\u3081\u308B (DP\u3001\u30D1\u30B9\u30AB\u30EB\u306E\
    \u4E09\u89D2\u5F62)\r\nconst int SIZE = 5000;\r\nll comb[SIZE+10][SIZE+10];\r\n\
    \r\ncomb[0][0] = 1;\r\nfor(int i=0; i<SIZE; i++) {\r\n    for(int j=0; j<SIZE;\
    \ j++) {\r\n        (comb[i+1][j] += comb[i][j]) %= MOD;\r\n        (comb[i][j+1]\
    \ += comb[i][j]) %= MOD;\r\n    }\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_001_mod.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_001_mod.cpp
layout: document
redirect_from:
- /library/math/math_001_mod.cpp
- /library/math/math_001_mod.cpp.html
title: math/math_001_mod.cpp
---
