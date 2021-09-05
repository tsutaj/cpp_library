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
  bundledCode: "#line 1 \"math/math_006_eulerphi.cpp\"\n// \u30AA\u30A4\u30E9\u30FC\
    \u306E \u03C6 \u95A2\u6570 (n \u4EE5\u4E0B\u306E\u81EA\u7136\u6570\u306E\u3046\
    \u3061 n \u3068\u4E92\u3044\u306B\u7D20\u306A\u3082\u306E\u306E\u500B\u6570)\n\
    // \\phi(n) = n \\times \\prod_{i=1}^{k} (1 - \\frac{1}{p_i}) \u3092\u4F7F\u304A\
    \u3046\n// (\u305F\u3060\u3057\u3001 p_i \u306F n \u306E\u7D20\u56E0\u6570)\n\
    // Complexity: O(sqrt n)\n// Vefiried: AOJ NTL_1_D: Euler's Phi Function\n\nint\
    \ Euler_phi(int n) {\n    int ret = n;\n    for(int i=2; i*i <= n; i++) {\n  \
    \      if(n % i == 0) {\n            ret -= ret / i;\n            while(n % i\
    \ == 0) n /= i;\n        }\n    }\n    if(n != 1) ret -= ret / n;\n    return\
    \ ret;\n}\n\n// \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570 (n \u3068\u4E92\
    \u3044\u306B\u7D20\u306A\u6570 p \u305D\u308C\u305E\u308C\u306B\u5BFE\u3057\u3066\
    \u3001p^x \u2261 1 \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E x)\nlong long int\
    \ Carmichael(long long int n, long long int prime=0, int pow_cnt=0) {\n    if(prime\
    \ == 2) {\n        // n = 2^x\n        if(pow_cnt == 1) return 1;\n        if(pow_cnt\
    \ == 2) return 2;\n        return 1LL << (pow_cnt - 2);\n    }\n    else if(prime\
    \ > 0) {\n        // n = p^x (p is odd-prime number)\n        return n / prime\
    \ * (prime - 1);\n    }\n    else {\n        long long int ans = 1;\n        std::map<long\
    \ long int, int> primes;\n        for(long long int i=2; i*i<=n; i++) {\n    \
    \        while(n % i == 0) {\n                primes[i]++;\n                n\
    \ /= i;\n            }\n        }\n        if(n != 1) primes[n]++;\n\n       \
    \ for(auto x : primes) {\n            long long int m = 1;\n            for(int\
    \ i=0; i<x.second; i++) m *= x.first;\n            ans = lcm(ans, Carmichael(m,\
    \ x.first, x.second));\n        }\n        return ans;\n    }\n}\n"
  code: "// \u30AA\u30A4\u30E9\u30FC\u306E \u03C6 \u95A2\u6570 (n \u4EE5\u4E0B\u306E\
    \u81EA\u7136\u6570\u306E\u3046\u3061 n \u3068\u4E92\u3044\u306B\u7D20\u306A\u3082\
    \u306E\u306E\u500B\u6570)\n// \\phi(n) = n \\times \\prod_{i=1}^{k} (1 - \\frac{1}{p_i})\
    \ \u3092\u4F7F\u304A\u3046\n// (\u305F\u3060\u3057\u3001 p_i \u306F n \u306E\u7D20\
    \u56E0\u6570)\n// Complexity: O(sqrt n)\n// Vefiried: AOJ NTL_1_D: Euler's Phi\
    \ Function\n\nint Euler_phi(int n) {\n    int ret = n;\n    for(int i=2; i*i <=\
    \ n; i++) {\n        if(n % i == 0) {\n            ret -= ret / i;\n         \
    \   while(n % i == 0) n /= i;\n        }\n    }\n    if(n != 1) ret -= ret / n;\n\
    \    return ret;\n}\n\n// \u30AB\u30FC\u30DE\u30A4\u30B1\u30EB\u95A2\u6570 (n\
    \ \u3068\u4E92\u3044\u306B\u7D20\u306A\u6570 p \u305D\u308C\u305E\u308C\u306B\u5BFE\
    \u3057\u3066\u3001p^x \u2261 1 \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E x)\n\
    long long int Carmichael(long long int n, long long int prime=0, int pow_cnt=0)\
    \ {\n    if(prime == 2) {\n        // n = 2^x\n        if(pow_cnt == 1) return\
    \ 1;\n        if(pow_cnt == 2) return 2;\n        return 1LL << (pow_cnt - 2);\n\
    \    }\n    else if(prime > 0) {\n        // n = p^x (p is odd-prime number)\n\
    \        return n / prime * (prime - 1);\n    }\n    else {\n        long long\
    \ int ans = 1;\n        std::map<long long int, int> primes;\n        for(long\
    \ long int i=2; i*i<=n; i++) {\n            while(n % i == 0) {\n            \
    \    primes[i]++;\n                n /= i;\n            }\n        }\n       \
    \ if(n != 1) primes[n]++;\n\n        for(auto x : primes) {\n            long\
    \ long int m = 1;\n            for(int i=0; i<x.second; i++) m *= x.first;\n \
    \           ans = lcm(ans, Carmichael(m, x.first, x.second));\n        }\n   \
    \     return ans;\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/math_006_eulerphi.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_006_eulerphi.cpp
layout: document
redirect_from:
- /library/math/math_006_eulerphi.cpp
- /library/math/math_006_eulerphi.cpp.html
title: math/math_006_eulerphi.cpp
---
