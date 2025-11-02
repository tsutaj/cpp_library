---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_004_matrix.cpp
    title: math/verify/verify_math_004_matrix.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_015_remainder_sum.cpp
    title: math/verify/verify_math_015_remainder_sum.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_018_ragrange_polynomial.cpp
    title: math/verify/verify_math_018_ragrange_polynomial.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
    title: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_020_combination.cpp
    title: math/verify/verify_math_020_combination.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_023_matrix_utils_modp.cpp
    title: math/verify/verify_math_023_matrix_utils_modp.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_024_fixed_matrix.cpp
    title: math/verify/verify_math_024_fixed_matrix.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
    title: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_017_modint.cpp\"\n// ModInt begin\r\n\r\nusing\
    \ ll = long long;\r\ntemplate<ll mod>\r\nstruct ModInt {\r\n    ll v;\r\n    ll\
    \ mod_pow(ll x, ll n) const {\r\n        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2)\
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
    \ end\r\n"
  code: "// ModInt begin\r\n\r\nusing ll = long long;\r\ntemplate<ll mod>\r\nstruct\
    \ ModInt {\r\n    ll v;\r\n    ll mod_pow(ll x, ll n) const {\r\n        return\
    \ (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;\r\n    }\r\n    ModInt(ll\
    \ a = 0) : v((a %= mod) < 0 ? a + mod : a) {}\r\n    ModInt operator+ ( const\
    \ ModInt& b ) const {\r\n        return (v + b.v >= mod ? ModInt(v + b.v - mod)\
    \ : ModInt(v + b.v));\r\n    }\r\n    ModInt operator- () const {\r\n        return\
    \ ModInt(-v);\r\n    }\r\n    ModInt operator- ( const ModInt& b ) const {\r\n\
    \        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));\r\n \
    \   }\r\n    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}\r\
    \n    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2))\
    \ % mod;}\r\n    \r\n    bool operator== ( const ModInt &b ) const {return v ==\
    \ b.v;}\r\n    bool operator!= ( const ModInt &b ) const {return !(*this == b);\
    \ }\r\n    ModInt& operator+= ( const ModInt &b ) {\r\n        v += b.v;\r\n \
    \       if(v >= mod) v -= mod;\r\n        return *this;\r\n    }\r\n    ModInt&\
    \ operator-= ( const ModInt &b ) {\r\n        v -= b.v;\r\n        if(v < 0) v\
    \ += mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator*= ( const\
    \ ModInt &b ) {\r\n        (v *= b.v) %= mod;\r\n        return *this;\r\n   \
    \ }\r\n    ModInt& operator/= ( const ModInt &b ) {\r\n        (v *= mod_pow(b.v,\
    \ mod-2)) %= mod;\r\n        return *this;\r\n    }\r\n    ModInt pow(ll x) {\
    \ return ModInt(mod_pow(v, x)); }\r\n    // operator int() const { return int(v);\
    \ }\r\n    // operator long long int() const { return v; }\r\n};\r\n\r\ntemplate<ll\
    \ mod>\r\nModInt<mod> pow(ModInt<mod> n, ll k) {\r\n    return ModInt<mod>(n.mod_pow(n.v,\
    \ k));\r\n}\r\n\r\ntemplate<ll mod>\r\nostream& operator<< (ostream& out, ModInt<mod>\
    \ a) {return out << a.v;}\r\ntemplate<ll mod>\r\nistream& operator>> (istream&\
    \ in, ModInt<mod>& a) {\r\n    in >> a.v;\r\n    return in;\r\n}\r\n\r\n// ModInt\
    \ end\r\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_017_modint.cpp
  requiredBy:
  - math/verify/verify_math_024_fixed_matrix.cpp
  - math/verify/verify_math_015_remainder_sum.cpp
  - math/verify/verify_math_004_matrix.cpp
  - math/verify/verify_math_020_combination.cpp
  - math/verify/verify_math_019_specific_ragrange_polynomial.cpp
  - math/verify/verify_math_023_matrix_utils_modp.cpp
  - math/verify/verify_math_018_ragrange_polynomial.cpp
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
documentation_of: math/math_017_modint.cpp
layout: document
redirect_from:
- /library/math/math_017_modint.cpp
- /library/math/math_017_modint.cpp.html
title: math/math_017_modint.cpp
---
