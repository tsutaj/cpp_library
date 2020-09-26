---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  - icon: ':warning:'
    path: math/math_015_remainder_sum.cpp
    title: math/math_015_remainder_sum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://codeforces.com/contest/616/problem/E
    - https://yukicoder.me/problems/no/752
  bundledCode: "#line 1 \"math/verify/verify_math_015_remainder_sum.cpp\"\n#include\
    \ <iostream>\n#include <cstdio>\n#include <vector>\n#include <algorithm>\nusing\
    \ namespace std;\n#line 1 \"math/math_017_modint.cpp\"\n// ModInt begin\r\n\r\n\
    using ll = long long;\r\ntemplate<ll mod>\r\nstruct ModInt {\r\n    ll v;\r\n\
    \    ll mod_pow(ll x, ll n) const {\r\n        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2)\
    \ * ((n&1)?x:1)) % mod;\r\n    }\r\n    ModInt(ll a = 0) : v((a %= mod) < 0 ?\
    \ a + mod : a) {}\r\n    ModInt operator+ ( const ModInt& b ) const {\r\n    \
    \    return (v + b.v >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));\r\n  \
    \  }\r\n    ModInt operator- () const {\r\n        return ModInt(-v);\r\n    }\r\
    \n    ModInt operator- ( const ModInt& b ) const {\r\n        return (v - b.v\
    \ < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));\r\n    }\r\n    ModInt operator*\
    \ ( const ModInt& b ) const {return (v * b.v) % mod;}\r\n    ModInt operator/\
    \ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2)) % mod;}\r\n    \r\
    \n    bool operator== ( const ModInt &b ) const {return v == b.v;}\r\n    bool\
    \ operator!= ( const ModInt &b ) const {return !(*this == b); }\r\n    ModInt&\
    \ operator+= ( const ModInt &b ) {\r\n        v += b.v;\r\n        if(v >= mod)\
    \ v -= mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator-= ( const\
    \ ModInt &b ) {\r\n        v -= b.v;\r\n        if(v < 0) v += mod;\r\n      \
    \  return *this;\r\n    }\r\n    ModInt& operator*= ( const ModInt &b ) {\r\n\
    \        (v *= b.v) %= mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator/=\
    \ ( const ModInt &b ) {\r\n        (v *= mod_pow(b.v, mod-2)) %= mod;\r\n    \
    \    return *this;\r\n    }\r\n    ModInt pow(ll x) { return ModInt(mod_pow(v,\
    \ x)); }\r\n    // operator int() const { return int(v); }\r\n    // operator\
    \ long long int() const { return v; }\r\n};\r\n\r\ntemplate<ll mod>\r\nModInt<mod>\
    \ pow(ModInt<mod> n, ll k) {\r\n    return ModInt<mod>(n.mod_pow(n.v, k));\r\n\
    }\r\n\r\ntemplate<ll mod>\r\nostream& operator<< (ostream& out, ModInt<mod> a)\
    \ {return out << a.v;}\r\ntemplate<ll mod>\r\nistream& operator>> (istream& in,\
    \ ModInt<mod>& a) {\r\n    in >> a.v;\r\n    return in;\r\n}\r\n\r\n// ModInt\
    \ end\r\n#line 1 \"math/math_015_remainder_sum.cpp\"\n// F(i) := P (mod 1) + P\
    \ (mod 2) + ... + P (mod i) \u3092\u8A08\u7B97\n// \u7B54\u3048\u306F NumType\
    \ \u578B\u3067\u8FD4\u3063\u3066\u304F\u308B\ntemplate <typename NumType, int\
    \ K = 10000000>\nstruct RemainderSum {\n    using lint = long long;\n    lint\
    \ P;\n    vector<NumType> small_case;\n    RemainderSum(lint P_) {\n        P\
    \ = P_;\n        build();\n    }\n\n    // \u5C0F\u3055\u3044\u30B1\u30FC\u30B9\
    \u306B\u5BFE\u3059\u308B\u7B54\u3048\u3092\u899A\u3048\u308B\n    void build()\
    \ {\n        small_case.resize(K + 1, NumType(0));\n        for(lint i=1; i<=K;\
    \ i++) {\n            NumType mod(P % i);\n            small_case[i] = small_case[i-1]\
    \ + mod;\n        }\n    }\n\n    // [1, x] (\u9589\u533A\u9593\u3067\u3042\u308B\
    \u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n    // F(x) \u3092\u8A08\u7B97 \n\
    \    NumType sum_func(lint x) {\n        if(x <= K) return small_case[x];\n  \
    \      return small_case[K] + sum_func(K+1, x);\n    }\n\n    // [l, r] (\u9589\
    \u533A\u9593\u3067\u3042\u308B\u3053\u3068\u306B\u6CE8\u610F\uFF01\uFF01)\n  \
    \  // P (mod l) + P (mod l+1) + ... + P (mod r) \u3092\u8A08\u7B97\n    NumType\
    \ sum_func(lint l, lint r) {\n        if(r <= K) return small_case[r] - small_case[l-1];\n\
    \        if(l <= K) return small_case[K] - small_case[l-1] + sum_func(K+1, r);\n\
    \n        NumType ans(0);\n        // l \u3082 r \u3082\u3001 K \u3092\u8D85\u3048\
    \u308B\u5024\u3067\u3042\u308B\n        lint dmax = P / l, dmin = P / r, num =\
    \ l;\n        for(lint div=dmax; div>=dmin; div--) {\n            if(div == 0)\
    \ {\n                // \u5546\u304C div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\
    \u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n      \
    \          lint idx_l = max(l, P + 1);\n                lint idx_r = r;\n    \
    \            NumType range(idx_r - idx_l + 1);\n\n                // \u3053\u306E\
    \u3068\u304D\u306E\u5270\u4F59\u306E\u5024\u306F\u5168\u3066 P \u306B\u7B49\u3057\
    \u3044\n                NumType sum = range * NumType(P);\n                ans\
    \ += sum;\n            }\n            else {\n                // \u5546\u304C\
    \ div \u306B\u306A\u308B\u3088\u3046\u306A\u8981\u7D20\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9 (\u9589\u533A\u9593)\n                lint idx_l = max(l, P\
    \ / (div + 1) + 1);\n                lint idx_r = min(r, P / div);\n         \
    \       NumType range(idx_r - idx_l + 1);\n                \n                //\
    \ \u5DE6\u7AEF\u3068\u53F3\u7AEF\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u5270\
    \u4F59\u306E\u5024\n                NumType mod_l(P % idx_l);\n              \
    \  NumType mod_r(P % idx_r);\n                \n                // \u7B49\u5DEE\
    \u6570\u5217\u306E\u548C\n                NumType sum = range * (mod_l + mod_r)\
    \ / NumType(2);\n                ans += sum;\n                \n             \
    \   // \u6B21\u306E div \u3092\u6C42\u3081\u308B (1 \u305A\u3064\u6E1B\u3089\u306A\
    \u3044\u5834\u5408\u304C\u3042\u308B)\n                if(P / num != P / (num\
    \ + 1)) {\n                    div = P / (num + 1) + 1;\n                    num++;\n\
    \                }\n            }\n        }\n        return ans;\n    }\n};\n\
    #line 8 \"math/verify/verify_math_015_remainder_sum.cpp\"\n\n// Verified on Mar\
    \ 30, 2019\n// Educational Codeforces Round 5 E: Sum of Remainders\n// Judge:\
    \ https://codeforces.com/contest/616/problem/E\nvoid ECR005_E() {\n    long long\
    \ int N, M; cin >> N >> M;\n    using mint = ModInt<1000000007>;\n    RemainderSum<mint>\
    \ rs(N);\n    cout << rs.sum_func(M) << endl;\n}\n\n// Verified on Mar 30, 2019\n\
    // yukicoder No. 752: mod \u6570\u5217\n// Judge: https://yukicoder.me/problems/no/752\n\
    void yuki_752() {\n    long long int P, Q; cin >> P >> Q;\n    RemainderSum<long\
    \ long int> rs(P);\n    while(Q--) {\n        long long int l, r; cin >> l >>\
    \ r;\n        cout << rs.sum_func(l, r) << endl;\n    }\n}\n\nint main() {\n \
    \   ECR005_E();\n    // yuki_752();\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <vector>\n#include <algorithm>\n\
    using namespace std;\n#include \"../math_017_modint.cpp\"\n#include \"../math_015_remainder_sum.cpp\"\
    \n\n// Verified on Mar 30, 2019\n// Educational Codeforces Round 5 E: Sum of Remainders\n\
    // Judge: https://codeforces.com/contest/616/problem/E\nvoid ECR005_E() {\n  \
    \  long long int N, M; cin >> N >> M;\n    using mint = ModInt<1000000007>;\n\
    \    RemainderSum<mint> rs(N);\n    cout << rs.sum_func(M) << endl;\n}\n\n// Verified\
    \ on Mar 30, 2019\n// yukicoder No. 752: mod \u6570\u5217\n// Judge: https://yukicoder.me/problems/no/752\n\
    void yuki_752() {\n    long long int P, Q; cin >> P >> Q;\n    RemainderSum<long\
    \ long int> rs(P);\n    while(Q--) {\n        long long int l, r; cin >> l >>\
    \ r;\n        cout << rs.sum_func(l, r) << endl;\n    }\n}\n\nint main() {\n \
    \   ECR005_E();\n    // yuki_752();\n    return 0;\n}\n"
  dependsOn:
  - math/math_017_modint.cpp
  - math/math_015_remainder_sum.cpp
  isVerificationFile: false
  path: math/verify/verify_math_015_remainder_sum.cpp
  requiredBy: []
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_015_remainder_sum.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_015_remainder_sum.cpp
- /library/math/verify/verify_math_015_remainder_sum.cpp.html
title: math/verify/verify_math_015_remainder_sum.cpp
---
