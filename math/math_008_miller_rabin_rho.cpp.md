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
  bundledCode: "#line 1 \"math/math_008_miller_rabin_rho.cpp\"\n// \u30FB\u30DF\u30E9\
    \u30FC\u30E9\u30D3\u30F3 (\u9AD8\u901F\u306A\u7D20\u6570\u5224\u5B9A)\n// \u30FB\
    \u30ED\u30FC\u6CD5 (\u9AD8\u901F\u306A\u7D20\u56E0\u6570\u5206\u89E3)\n// \u30FB\
    \u3069\u3061\u3089\u3082\u78BA\u7387\u7684\u306A\u30A2\u30EB\u30B4\u30EA\u30BA\
    \u30E0\u3067\u3042\u308B\u305F\u3081\u3001\u5C0F\u3055\u3044\u3082\u306E\u306F\
    \u901A\u5E38\u306E\u7D20\u6570\u5224\u5B9A\u3067\u51E6\u7406\u3057\u305F\u307B\
    \u3046\u304C\u78BA\u5B9F\n// Verified: POJ 2429 (GCD & LCM Inverse)\n\nint gcd(int\
    \ a, int b) {\n    assert(a >= 0 && b >= 0);\n    if(a < b) swap(a, b);\n    return\
    \ (b == 0 ? a : gcd(b, a%b));\n}\n\n// \u5C0F\u3055\u3044\u6570\u5B57\u306F\u901A\
    \u5E38\u901A\u308A\u306E\u7D20\u6570\u5224\u5B9A\u3067\u51E6\u7406\u3059\u308B\
    \ (\u9AD8\u901F\u5316\u306E\u305F\u3081)\nconst int MAX_PRIME = 300000;\nconst\
    \ int MINI_PRIME = 40;\nbool is_prime[MAX_PRIME + 10];\nvector<int> primes, mini_primes;\n\
    \nvoid init_primes() {\n    fill(is_prime, is_prime + MAX_PRIME + 10, true);\n\
    \    is_prime[0] = is_prime[1] = false;\n    for(int i=0; i<=MAX_PRIME; i++) {\n\
    \        if(is_prime[i]) {\n            if(i < MINI_PRIME) mini_primes.push_back(i);\n\
    \            primes.push_back(i);\n            for(int k=i+i; k<=MAX_PRIME; k+=i)\
    \ {\n                is_prime[k] = false;\n            }\n        }\n    }\n}\n\
    \n// \u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u7D20\u6570\u5224\u5B9A\u6CD5 (Miller-Rabin\
    \ Primality Test)\n// \u666E\u901A\u306B\u639B\u3051\u7B97\u3059\u308B\u3068\u30AA\
    \u30FC\u30D0\u30FC\u30D5\u30ED\u30FC\u3067\u6B7B\u306C\u305F\u3081\u3001\u30D0\
    \u30A4\u30CA\u30EA\u6CD5\u3067\u51E6\u7406\ntemplate<typename T>\nstruct MLPT\
    \ {\n    MLPT() {}\n\n    T mod_mul(T a, T b, T mod) {\n        T res = 0; a %=\
    \ mod;\n        while(b) {\n            if(b & 1) (res += a) %= mod;\n       \
    \     a = (a + a) % mod;\n            b >>= 1;\n        }\n        return res;\n\
    \    }\n\n    T mod_pow(T x, T n, T mod) {\n        x %= mod;\n        if(n ==\
    \ 0) return 1;\n        T res = mod_pow(mod_mul(x, x, mod), n / 2, mod);\n   \
    \     if(n & 1) res = mod_mul(res, x, mod);\n        return res;\n    }\n\n  \
    \  // \u5C0F\u3055\u3044\u6570\u306A\u3089\u7D20\u6570\u5224\u5B9A\u30C6\u30FC\
    \u30D6\u30EB\u3092\u305D\u306E\u307E\u307E\u4F7F\u3046\n    // \u5927\u304D\u3051\
    \u308C\u3070\u3057\u3087\u3046\u304C\u306A\u3044\u306E\u3067\u30DF\u30E9\u30FC\
    \u30E9\u30D3\u30F3\u3067\n    bool solve(T N) {\n        if(N <= MAX_PRIME) return\
    \ is_prime[N];\n        for(size_t i=0; i<mini_primes.size(); i++) {\n       \
    \     T a = mini_primes[i];\n            if(N == a) return true;\n           \
    \ if(N % a == 0) return false;\n\n            T d = N-1, s = 0;\n            while(d\
    \ % 2 == 0) d >>= 1, s++;\n\n            if(mod_pow(a, d, N) == 1) continue;\n\
    \            bool pbprime = false;\n            for(int r=0; r<s; r++) {\n   \
    \             if(mod_pow(a, d*(1LL << r), N) == N-1) {\n                    pbprime\
    \ = true;\n                    break;\n                }\n            }\n    \
    \        if(!pbprime) return false;\n        }\n        return true;\n    }\n\
    };\n\n// \u30ED\u30FC\u6CD5\u306B\u3088\u308B\u7D20\u56E0\u6570\u5206\u89E3\n\
    // \u5BFE\u8C61\u3068\u306A\u308B\u6570\u304C\u7D20\u6570\u306E\u5834\u5408\u306F\
    \u5E38\u306B failure -> Miller Rabin \u3068\u4F75\u7528\u3057\u3088\u3046\ntemplate<typename\
    \ T>\nstruct Rho {\n    vector<int> pat;\n    Rho() {}\n\n    MLPT<T> ml;\n  \
    \  T func(T x, T c, T mod) {\n        return (ml.mod_mul(x, x, mod) + c) % mod;\n\
    \    }\n\n    T check(T N, int c) {\n        T x = 2, y = 2, d = 1;\n        while(d\
    \ == 1) {\n            x = func(x, c, N);\n            y = func(func(y, c, N),\
    \ c, N);\n            d = gcd((x-y>0 ? x-y : y-x), N);\n        }\n        return\
    \ (d == N ? check(N, c+1) : d);\n    }\n\n    // \u30BD\u30FC\u30C8\u3055\u308C\
    \u3066\u306A\u3044\u306E\u3067\u3001\u5FC5\u8981\u3060\u3063\u305F\u3089\u5225\
    \u9014\u30BD\u30FC\u30C8\u3057\u3066\u306D\n    vector<T> factor(T N) {\n    \
    \    if(N < 2) return vector<T>();\n        if(ml.solve(N)) return vector<T>(1,\
    \ N);\n\n        vector<T> res;\n        // \u5C0F\u3055\u3044\u7D20\u56E0\u6570\
    \u306F\u666E\u901A\u306B\u7D20\u56E0\u6570\u5206\u89E3\n        for(size_t i=0;\
    \ i<primes.size(); i++) {\n            T a = primes[i];\n            if(a > N)\
    \ break;\n            while(N % a == 0) {\n                res.push_back(a);\n\
    \                N /= a;\n            }\n        }\n\n        // \u6B8B\u3063\u305F\
    \u3084\u3064\u306F\u3057\u3087\u3046\u304C\u306A\u3044\u306E\u3067\u30ED\u30FC\
    \u6CD5\u3067\n        if(N != 1) {\n            if(ml.solve(N)) res.push_back(N);\n\
    \            else {\n                T D = check(N, 1);\n                vector<T>\
    \ va = factor(D), vb = factor(N / D);\n                res.insert(res.end(), va.begin(),\
    \ va.end());\n                res.insert(res.end(), vb.begin(), vb.end());\n \
    \           }\n        }\n        return res;\n    }\n};\n"
  code: "// \u30FB\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3 (\u9AD8\u901F\u306A\u7D20\u6570\
    \u5224\u5B9A)\n// \u30FB\u30ED\u30FC\u6CD5 (\u9AD8\u901F\u306A\u7D20\u56E0\u6570\
    \u5206\u89E3)\n// \u30FB\u3069\u3061\u3089\u3082\u78BA\u7387\u7684\u306A\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\u3067\u3042\u308B\u305F\u3081\u3001\u5C0F\u3055\
    \u3044\u3082\u306E\u306F\u901A\u5E38\u306E\u7D20\u6570\u5224\u5B9A\u3067\u51E6\
    \u7406\u3057\u305F\u307B\u3046\u304C\u78BA\u5B9F\n// Verified: POJ 2429 (GCD &\
    \ LCM Inverse)\n\nint gcd(int a, int b) {\n    assert(a >= 0 && b >= 0);\n   \
    \ if(a < b) swap(a, b);\n    return (b == 0 ? a : gcd(b, a%b));\n}\n\n// \u5C0F\
    \u3055\u3044\u6570\u5B57\u306F\u901A\u5E38\u901A\u308A\u306E\u7D20\u6570\u5224\
    \u5B9A\u3067\u51E6\u7406\u3059\u308B (\u9AD8\u901F\u5316\u306E\u305F\u3081)\n\
    const int MAX_PRIME = 300000;\nconst int MINI_PRIME = 40;\nbool is_prime[MAX_PRIME\
    \ + 10];\nvector<int> primes, mini_primes;\n\nvoid init_primes() {\n    fill(is_prime,\
    \ is_prime + MAX_PRIME + 10, true);\n    is_prime[0] = is_prime[1] = false;\n\
    \    for(int i=0; i<=MAX_PRIME; i++) {\n        if(is_prime[i]) {\n          \
    \  if(i < MINI_PRIME) mini_primes.push_back(i);\n            primes.push_back(i);\n\
    \            for(int k=i+i; k<=MAX_PRIME; k+=i) {\n                is_prime[k]\
    \ = false;\n            }\n        }\n    }\n}\n\n// \u30DF\u30E9\u30FC\u30E9\u30D3\
    \u30F3\u7D20\u6570\u5224\u5B9A\u6CD5 (Miller-Rabin Primality Test)\n// \u666E\u901A\
    \u306B\u639B\u3051\u7B97\u3059\u308B\u3068\u30AA\u30FC\u30D0\u30FC\u30D5\u30ED\
    \u30FC\u3067\u6B7B\u306C\u305F\u3081\u3001\u30D0\u30A4\u30CA\u30EA\u6CD5\u3067\
    \u51E6\u7406\ntemplate<typename T>\nstruct MLPT {\n    MLPT() {}\n\n    T mod_mul(T\
    \ a, T b, T mod) {\n        T res = 0; a %= mod;\n        while(b) {\n       \
    \     if(b & 1) (res += a) %= mod;\n            a = (a + a) % mod;\n         \
    \   b >>= 1;\n        }\n        return res;\n    }\n\n    T mod_pow(T x, T n,\
    \ T mod) {\n        x %= mod;\n        if(n == 0) return 1;\n        T res = mod_pow(mod_mul(x,\
    \ x, mod), n / 2, mod);\n        if(n & 1) res = mod_mul(res, x, mod);\n     \
    \   return res;\n    }\n\n    // \u5C0F\u3055\u3044\u6570\u306A\u3089\u7D20\u6570\
    \u5224\u5B9A\u30C6\u30FC\u30D6\u30EB\u3092\u305D\u306E\u307E\u307E\u4F7F\u3046\
    \n    // \u5927\u304D\u3051\u308C\u3070\u3057\u3087\u3046\u304C\u306A\u3044\u306E\
    \u3067\u30DF\u30E9\u30FC\u30E9\u30D3\u30F3\u3067\n    bool solve(T N) {\n    \
    \    if(N <= MAX_PRIME) return is_prime[N];\n        for(size_t i=0; i<mini_primes.size();\
    \ i++) {\n            T a = mini_primes[i];\n            if(N == a) return true;\n\
    \            if(N % a == 0) return false;\n\n            T d = N-1, s = 0;\n \
    \           while(d % 2 == 0) d >>= 1, s++;\n\n            if(mod_pow(a, d, N)\
    \ == 1) continue;\n            bool pbprime = false;\n            for(int r=0;\
    \ r<s; r++) {\n                if(mod_pow(a, d*(1LL << r), N) == N-1) {\n    \
    \                pbprime = true;\n                    break;\n               \
    \ }\n            }\n            if(!pbprime) return false;\n        }\n      \
    \  return true;\n    }\n};\n\n// \u30ED\u30FC\u6CD5\u306B\u3088\u308B\u7D20\u56E0\
    \u6570\u5206\u89E3\n// \u5BFE\u8C61\u3068\u306A\u308B\u6570\u304C\u7D20\u6570\u306E\
    \u5834\u5408\u306F\u5E38\u306B failure -> Miller Rabin \u3068\u4F75\u7528\u3057\
    \u3088\u3046\ntemplate<typename T>\nstruct Rho {\n    vector<int> pat;\n    Rho()\
    \ {}\n\n    MLPT<T> ml;\n    T func(T x, T c, T mod) {\n        return (ml.mod_mul(x,\
    \ x, mod) + c) % mod;\n    }\n\n    T check(T N, int c) {\n        T x = 2, y\
    \ = 2, d = 1;\n        while(d == 1) {\n            x = func(x, c, N);\n     \
    \       y = func(func(y, c, N), c, N);\n            d = gcd((x-y>0 ? x-y : y-x),\
    \ N);\n        }\n        return (d == N ? check(N, c+1) : d);\n    }\n\n    //\
    \ \u30BD\u30FC\u30C8\u3055\u308C\u3066\u306A\u3044\u306E\u3067\u3001\u5FC5\u8981\
    \u3060\u3063\u305F\u3089\u5225\u9014\u30BD\u30FC\u30C8\u3057\u3066\u306D\n   \
    \ vector<T> factor(T N) {\n        if(N < 2) return vector<T>();\n        if(ml.solve(N))\
    \ return vector<T>(1, N);\n\n        vector<T> res;\n        // \u5C0F\u3055\u3044\
    \u7D20\u56E0\u6570\u306F\u666E\u901A\u306B\u7D20\u56E0\u6570\u5206\u89E3\n   \
    \     for(size_t i=0; i<primes.size(); i++) {\n            T a = primes[i];\n\
    \            if(a > N) break;\n            while(N % a == 0) {\n             \
    \   res.push_back(a);\n                N /= a;\n            }\n        }\n\n \
    \       // \u6B8B\u3063\u305F\u3084\u3064\u306F\u3057\u3087\u3046\u304C\u306A\u3044\
    \u306E\u3067\u30ED\u30FC\u6CD5\u3067\n        if(N != 1) {\n            if(ml.solve(N))\
    \ res.push_back(N);\n            else {\n                T D = check(N, 1);\n\
    \                vector<T> va = factor(D), vb = factor(N / D);\n             \
    \   res.insert(res.end(), va.begin(), va.end());\n                res.insert(res.end(),\
    \ vb.begin(), vb.end());\n            }\n        }\n        return res;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: math/math_008_miller_rabin_rho.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_008_miller_rabin_rho.cpp
layout: document
redirect_from:
- /library/math/math_008_miller_rabin_rho.cpp
- /library/math/math_008_miller_rabin_rho.cpp.html
title: math/math_008_miller_rabin_rho.cpp
---
