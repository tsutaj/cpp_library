---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_002_prime.cpp\"\n// \u30A8\u30E9\u30C8\u30B9\u30C6\
    \u30CD\u30B9\u306E\u7BE9\r\n// [0,n) \u306E\u7BC4\u56F2\u306E i \u306B\u3064\u3044\
    \u3066\u3001primes[i] != 0 \u21D4 i \u306F\u7D20\u6570\r\nvector<int> erat(int\
    \ n) {\r\n    vector<int> primes(n);\r\n    for (int i = 2; i < n; ++i) primes[i]\
    \ = i;\r\n    for (int i = 2; i*i < n; ++i)\r\n        if (primes[i])\r\n    \
    \        for (int j = i*i; j < n; j+=i) primes[j] = 0;\r\n    // \u7D20\u6570\u306E\
    \u307F\u3092vector\u306B\u683C\u7D0D\u3059\u308B\u5834\u5408\u306F\u4EE5\u4E0B\
    \u306E\u884C\u3092\u8FFD\u52A0 (0 \u3067\u3042\u308B\u8981\u7D20\u3092\u5168\u524A\
    \u9664)\r\n    // primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());\r\
    \n    return primes;\r\n}\r\n\r\n// \u7D20\u6570\u5224\u5B9A\r\nbool isprime(int\
    \ n) { //\u7D20\u6570\u306A\u3089\u3070true\r\n    for(int i=2; i*i <= n; i++)\
    \ {\r\n        if(n%i==0) return false;\r\n    }\r\n    return n != 1;\r\n}\r\n\
    \r\n// \u7D20\u56E0\u6570\u5206\u89E3\r\nvector<int> primeFactorization(int n)\
    \ {\r\n    int k = n;\r\n    vector<int> ret;\r\n    repq(i,2,sqrt(n)) {\r\n \
    \       while(k % i == 0) {\r\n            ret.pb(i);\r\n            k /= i; //\
    \ \u91CD\u8907\u3092\u8A31\u3055\u306A\u3044\u306A\u3089\u3053\u3053\u3092 while\
    \ \u306B\r\n        }\r\n    }\r\n    if(k > 1) ret.pb(k);\r\n    return ret;\r\
    \n}\r\n\r\n// \u30AC\u30A6\u30B9\u7D20\u6570\u5224\u5B9A\r\n// \u203B\u8907\u7D20\
    \u6574\u6570(\u5B9F\u90E8\u3082\u865A\u90E8\u3082\u6574\u6570\u306E\u8907\u7D20\
    \u6570) a + bi \u304C\u30AC\u30A6\u30B9\u7D20\u6570\u3067\u3042\u308B\u3068\u306F\
    \u3001\r\n// \u3053\u308C\u3092\u5272\u308A\u5207\u308B\u975E\u81EA\u660E\u306A\
    \u8907\u7D20\u6574\u6570\u304C\u5B58\u5728\u3057\u306A\u3044\u3053\u3068\u3092\
    \u8A00\u3046\u3002\r\n\r\n// \u4F8B: 5\u306F\u7D20\u6570\u3060\u304C\u30AC\u30A6\
    \u30B9\u7D20\u6570\u3067\u306F\u306A\u3044 ( 5 = (2+i)(2-i) )\r\nbool isGaussianprime(Int\
    \ a, Int b) {\r\n  if (a < 0) a = -a;\r\n  if (b < 0) b = -b;\r\n  if (a == 0)\
    \ return b % 4 == 3 && isprime(b);\r\n  if (b == 0) return a % 4 == 3 && isprime(a);\r\
    \n  return isprime(a*a+b*b);\r\n}\r\n\r\n// \u7D20\u6570\u8868\u306E\u4F5C\u6210\
    \ (n\u307E\u3067\u306E\u7D20\u6570\u3092\u914D\u5217v\u306B\u683C\u7D0D)\r\nint\
    \ main() {\r\n    int n;\r\n    vector<int> v;\r\n\r\n    cin >> n;\r\n    v.pb(2);\r\
    \n    for(int i=3;i<=n;i+=2) {\r\n        bool add = true;\r\n        rep(j,0,v.size())\
    \ {\r\n            if(v[j] * v[j] > i) break;\r\n            if(i % v[j] == 0)\
    \ {\r\n                add = false;\r\n                break;\r\n            }\r\
    \n        }\r\n        if(add) v.pb(i);\r\n    }\r\n\r\n    //rep(i,0,v.size())\
    \ cout << v[i] << endl;\r\n    return 0;\r\n}\r\n\r\n// \u7D04\u6570\u5168\u5217\
    \u6319\r\nvector<ll> OutDivisor(ll n) {\r\n    vector<ll> ret;\r\n    for(ll i=1;\
    \ i*i<=n; i++) {\r\n        if(n % i == 0) {\r\n            ret.push_back(i);\r\
    \n            if(i*i!=n) ret.push_back(n / i);\r\n        }\r\n    }\r\n    return\
    \ ret;\r\n}\n"
  code: "// \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\r\n// [0,n) \u306E\
    \u7BC4\u56F2\u306E i \u306B\u3064\u3044\u3066\u3001primes[i] != 0 \u21D4 i \u306F\
    \u7D20\u6570\r\nvector<int> erat(int n) {\r\n    vector<int> primes(n);\r\n  \
    \  for (int i = 2; i < n; ++i) primes[i] = i;\r\n    for (int i = 2; i*i < n;\
    \ ++i)\r\n        if (primes[i])\r\n            for (int j = i*i; j < n; j+=i)\
    \ primes[j] = 0;\r\n    // \u7D20\u6570\u306E\u307F\u3092vector\u306B\u683C\u7D0D\
    \u3059\u308B\u5834\u5408\u306F\u4EE5\u4E0B\u306E\u884C\u3092\u8FFD\u52A0 (0 \u3067\
    \u3042\u308B\u8981\u7D20\u3092\u5168\u524A\u9664)\r\n    // primes.erase(remove(primes.begin(),\
    \ primes.end(), 0), primes.end());\r\n    return primes;\r\n}\r\n\r\n// \u7D20\
    \u6570\u5224\u5B9A\r\nbool isprime(int n) { //\u7D20\u6570\u306A\u3089\u3070true\r\
    \n    for(int i=2; i*i <= n; i++) {\r\n        if(n%i==0) return false;\r\n  \
    \  }\r\n    return n != 1;\r\n}\r\n\r\n// \u7D20\u56E0\u6570\u5206\u89E3\r\nvector<int>\
    \ primeFactorization(int n) {\r\n    int k = n;\r\n    vector<int> ret;\r\n  \
    \  repq(i,2,sqrt(n)) {\r\n        while(k % i == 0) {\r\n            ret.pb(i);\r\
    \n            k /= i; // \u91CD\u8907\u3092\u8A31\u3055\u306A\u3044\u306A\u3089\
    \u3053\u3053\u3092 while \u306B\r\n        }\r\n    }\r\n    if(k > 1) ret.pb(k);\r\
    \n    return ret;\r\n}\r\n\r\n// \u30AC\u30A6\u30B9\u7D20\u6570\u5224\u5B9A\r\n\
    // \u203B\u8907\u7D20\u6574\u6570(\u5B9F\u90E8\u3082\u865A\u90E8\u3082\u6574\u6570\
    \u306E\u8907\u7D20\u6570) a + bi \u304C\u30AC\u30A6\u30B9\u7D20\u6570\u3067\u3042\
    \u308B\u3068\u306F\u3001\r\n// \u3053\u308C\u3092\u5272\u308A\u5207\u308B\u975E\
    \u81EA\u660E\u306A\u8907\u7D20\u6574\u6570\u304C\u5B58\u5728\u3057\u306A\u3044\
    \u3053\u3068\u3092\u8A00\u3046\u3002\r\n\r\n// \u4F8B: 5\u306F\u7D20\u6570\u3060\
    \u304C\u30AC\u30A6\u30B9\u7D20\u6570\u3067\u306F\u306A\u3044 ( 5 = (2+i)(2-i)\
    \ )\r\nbool isGaussianprime(Int a, Int b) {\r\n  if (a < 0) a = -a;\r\n  if (b\
    \ < 0) b = -b;\r\n  if (a == 0) return b % 4 == 3 && isprime(b);\r\n  if (b ==\
    \ 0) return a % 4 == 3 && isprime(a);\r\n  return isprime(a*a+b*b);\r\n}\r\n\r\
    \n// \u7D20\u6570\u8868\u306E\u4F5C\u6210 (n\u307E\u3067\u306E\u7D20\u6570\u3092\
    \u914D\u5217v\u306B\u683C\u7D0D)\r\nint main() {\r\n    int n;\r\n    vector<int>\
    \ v;\r\n\r\n    cin >> n;\r\n    v.pb(2);\r\n    for(int i=3;i<=n;i+=2) {\r\n\
    \        bool add = true;\r\n        rep(j,0,v.size()) {\r\n            if(v[j]\
    \ * v[j] > i) break;\r\n            if(i % v[j] == 0) {\r\n                add\
    \ = false;\r\n                break;\r\n            }\r\n        }\r\n       \
    \ if(add) v.pb(i);\r\n    }\r\n\r\n    //rep(i,0,v.size()) cout << v[i] << endl;\r\
    \n    return 0;\r\n}\r\n\r\n// \u7D04\u6570\u5168\u5217\u6319\r\nvector<ll> OutDivisor(ll\
    \ n) {\r\n    vector<ll> ret;\r\n    for(ll i=1; i*i<=n; i++) {\r\n        if(n\
    \ % i == 0) {\r\n            ret.push_back(i);\r\n            if(i*i!=n) ret.push_back(n\
    \ / i);\r\n        }\r\n    }\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/math_002_prime.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_002_prime.cpp
layout: document
redirect_from:
- /library/math/math_002_prime.cpp
- /library/math/math_002_prime.cpp.html
title: math/math_002_prime.cpp
---
