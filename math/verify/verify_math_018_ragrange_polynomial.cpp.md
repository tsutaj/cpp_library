---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  - icon: ':warning:'
    path: math/math_018_ragrange_polynomial.cpp
    title: math/math_018_ragrange_polynomial.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://arc033.contest.atcoder.jp/tasks/arc033_4
    - https://codeforces.com/contest/1155/problem/E
  bundledCode: "#line 1 \"math/verify/verify_math_018_ragrange_polynomial.cpp\"\n\
    #include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing namespace\
    \ std;\r\n#line 1 \"math/math_017_modint.cpp\"\n// ModInt begin\r\n\r\nusing ll\
    \ = long long;\r\ntemplate<ll mod>\r\nstruct ModInt {\r\n    ll v;\r\n    ll mod_pow(ll\
    \ x, ll n) const {\r\n        return (!n) ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1))\
    \ % mod;\r\n    }\r\n    ModInt(ll a = 0) : v((a %= mod) < 0 ? a + mod : a) {}\r\
    \n    ModInt operator+ ( const ModInt& b ) const {\r\n        return (v + b.v\
    \ >= mod ? ModInt(v + b.v - mod) : ModInt(v + b.v));\r\n    }\r\n    ModInt operator-\
    \ () const {\r\n        return ModInt(-v);\r\n    }\r\n    ModInt operator- (\
    \ const ModInt& b ) const {\r\n        return (v - b.v < 0 ? ModInt(v - b.v +\
    \ mod) : ModInt(v - b.v));\r\n    }\r\n    ModInt operator* ( const ModInt& b\
    \ ) const {return (v * b.v) % mod;}\r\n    ModInt operator/ ( const ModInt& b\
    \ ) const {return (v * mod_pow(b.v, mod-2)) % mod;}\r\n    \r\n    bool operator==\
    \ ( const ModInt &b ) const {return v == b.v;}\r\n    bool operator!= ( const\
    \ ModInt &b ) const {return !(*this == b); }\r\n    ModInt& operator+= ( const\
    \ ModInt &b ) {\r\n        v += b.v;\r\n        if(v >= mod) v -= mod;\r\n   \
    \     return *this;\r\n    }\r\n    ModInt& operator-= ( const ModInt &b ) {\r\
    \n        v -= b.v;\r\n        if(v < 0) v += mod;\r\n        return *this;\r\n\
    \    }\r\n    ModInt& operator*= ( const ModInt &b ) {\r\n        (v *= b.v) %=\
    \ mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator/= ( const ModInt\
    \ &b ) {\r\n        (v *= mod_pow(b.v, mod-2)) %= mod;\r\n        return *this;\r\
    \n    }\r\n    ModInt pow(ll x) { return ModInt(mod_pow(v, x)); }\r\n    // operator\
    \ int() const { return int(v); }\r\n    // operator long long int() const { return\
    \ v; }\r\n};\r\n\r\ntemplate<ll mod>\r\nModInt<mod> pow(ModInt<mod> n, ll k) {\r\
    \n    return ModInt<mod>(n.mod_pow(n.v, k));\r\n}\r\n\r\ntemplate<ll mod>\r\n\
    ostream& operator<< (ostream& out, ModInt<mod> a) {return out << a.v;}\r\ntemplate<ll\
    \ mod>\r\nistream& operator>> (istream& in, ModInt<mod>& a) {\r\n    in >> a.v;\r\
    \n    return in;\r\n}\r\n\r\n// ModInt end\r\n#line 1 \"math/math_018_ragrange_polynomial.cpp\"\
    \nll mod_pow(ll n, ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1)\
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
    \     }\r\n        }\r\n        return res;\r\n    }\r\n};\r\n#line 7 \"math/verify/verify_math_018_ragrange_polynomial.cpp\"\
    \n\r\n// Verified on Apr 23, 2019\r\n// Educational Codeforces Round 63 E: Guess\
    \ the Root\r\n// Judge: https://codeforces.com/contest/1155/problem/E\r\n// TLE\
    \ \u304C\u53B3\u3057\u3044\u306E\u3067\u9006\u5143\u306F\u524D\u8A08\u7B97\u3057\
    \u306A\u3044\u3068\u901A\u308A\u307E\u305B\u3093\r\n// \u3042\u3068 f(0) \u304B\
    \u3089 f(N) \u307E\u3067\u308F\u304B\u3063\u3066\u3044\u308C\u3070 O(N) \u3067\
    \u3067\u304D\u308B\u306E\u3067\u305D\u3061\u3089\u306E\u6226\u7565\u306E\u307B\
    \u3046\u304C\u3088\u3044\u304B\u3082\r\nvoid ECR065_E() {\r\n    const int MOD\
    \ = 1000003;\r\n    using mint = ModInt<MOD>;\r\n\r\n    const int DEG = 11;\r\
    \n    auto eval_expr = [&](vector<mint> &expr, mint x) {\r\n        mint base(1),\
    \ res(0);\r\n        for(int i=0; i<DEG; i++) {\r\n            res += expr[i]\
    \ * base;\r\n            base *= x;\r\n        }\r\n        return res;\r\n  \
    \  };\r\n    \r\n    vector<mint> x, y, expr;\r\n    vector<int> raw_expr = {1,\
    \ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};\r\n    for(int i=0; i<DEG; i++) {\r\n       \
    \ expr.emplace_back(mint(raw_expr[i]));\r\n    }\r\n    \r\n    for(int i=1; i<=DEG;\
    \ i++) {\r\n        x.push_back(mint(i));\r\n        cout << \"? \" << i << endl;\r\
    \n        int res;\r\n        cin >> res;\r\n        // res = eval_expr(expr,\
    \ i).v;\r\n        y.push_back(mint(res));\r\n    }\r\n\r\n    LagrangePolynomial<mint>\
    \ lp(x, y, MOD);\r\n    for(int i=0; i<MOD; i++) {\r\n        if(lp.interpolate(i)\
    \ == mint(0)) {\r\n            cout << \"! \" << i << endl;\r\n            return;\r\
    \n        }\r\n    }\r\n    cout << \"! \" << -1 << endl;\r\n}\r\n\r\n// Verified\
    \ (\u90E8\u5206\u70B9, N <= 3000) on Apr 23, 2019\r\n// AtCoder Regular Contest\
    \ 033 F (\u65E7 D): \u898B\u305F\u3053\u3068\u306E\u306A\u3044\u591A\u9805\u5F0F\
    \r\n// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4\r\nvoid ARC033_F_PART()\
    \ {\r\n    const int MOD = 1000000007;\r\n    using mint = ModInt<MOD>;\r\n\r\n\
    \    int N; cin >> N;\r\n    if(N > 3000) exit(1);\r\n    \r\n    vector<mint>\
    \ x(N+1);\r\n    vector<mint> y(N+1);\r\n    for(int i=0; i<=N; i++) {\r\n   \
    \     x[i] = mint(i);\r\n        cin >> y[i];\r\n    }\r\n\r\n    int T; cin >>\
    \ T;\r\n    LagrangePolynomial<mint> lp(x, y);\r\n    cout << lp.interpolate(T)\
    \ << endl;\r\n}\r\n\r\nint main() {\r\n    // ECR065_E();\r\n    ARC033_F_PART();\r\
    \n    return 0;\r\n}\r\n"
  code: "#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing\
    \ namespace std;\r\n#include \"../math_017_modint.cpp\"\r\n#include \"../math_018_ragrange_polynomial.cpp\"\
    \r\n\r\n// Verified on Apr 23, 2019\r\n// Educational Codeforces Round 63 E: Guess\
    \ the Root\r\n// Judge: https://codeforces.com/contest/1155/problem/E\r\n// TLE\
    \ \u304C\u53B3\u3057\u3044\u306E\u3067\u9006\u5143\u306F\u524D\u8A08\u7B97\u3057\
    \u306A\u3044\u3068\u901A\u308A\u307E\u305B\u3093\r\n// \u3042\u3068 f(0) \u304B\
    \u3089 f(N) \u307E\u3067\u308F\u304B\u3063\u3066\u3044\u308C\u3070 O(N) \u3067\
    \u3067\u304D\u308B\u306E\u3067\u305D\u3061\u3089\u306E\u6226\u7565\u306E\u307B\
    \u3046\u304C\u3088\u3044\u304B\u3082\r\nvoid ECR065_E() {\r\n    const int MOD\
    \ = 1000003;\r\n    using mint = ModInt<MOD>;\r\n\r\n    const int DEG = 11;\r\
    \n    auto eval_expr = [&](vector<mint> &expr, mint x) {\r\n        mint base(1),\
    \ res(0);\r\n        for(int i=0; i<DEG; i++) {\r\n            res += expr[i]\
    \ * base;\r\n            base *= x;\r\n        }\r\n        return res;\r\n  \
    \  };\r\n    \r\n    vector<mint> x, y, expr;\r\n    vector<int> raw_expr = {1,\
    \ 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};\r\n    for(int i=0; i<DEG; i++) {\r\n       \
    \ expr.emplace_back(mint(raw_expr[i]));\r\n    }\r\n    \r\n    for(int i=1; i<=DEG;\
    \ i++) {\r\n        x.push_back(mint(i));\r\n        cout << \"? \" << i << endl;\r\
    \n        int res;\r\n        cin >> res;\r\n        // res = eval_expr(expr,\
    \ i).v;\r\n        y.push_back(mint(res));\r\n    }\r\n\r\n    LagrangePolynomial<mint>\
    \ lp(x, y, MOD);\r\n    for(int i=0; i<MOD; i++) {\r\n        if(lp.interpolate(i)\
    \ == mint(0)) {\r\n            cout << \"! \" << i << endl;\r\n            return;\r\
    \n        }\r\n    }\r\n    cout << \"! \" << -1 << endl;\r\n}\r\n\r\n// Verified\
    \ (\u90E8\u5206\u70B9, N <= 3000) on Apr 23, 2019\r\n// AtCoder Regular Contest\
    \ 033 F (\u65E7 D): \u898B\u305F\u3053\u3068\u306E\u306A\u3044\u591A\u9805\u5F0F\
    \r\n// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4\r\nvoid ARC033_F_PART()\
    \ {\r\n    const int MOD = 1000000007;\r\n    using mint = ModInt<MOD>;\r\n\r\n\
    \    int N; cin >> N;\r\n    if(N > 3000) exit(1);\r\n    \r\n    vector<mint>\
    \ x(N+1);\r\n    vector<mint> y(N+1);\r\n    for(int i=0; i<=N; i++) {\r\n   \
    \     x[i] = mint(i);\r\n        cin >> y[i];\r\n    }\r\n\r\n    int T; cin >>\
    \ T;\r\n    LagrangePolynomial<mint> lp(x, y);\r\n    cout << lp.interpolate(T)\
    \ << endl;\r\n}\r\n\r\nint main() {\r\n    // ECR065_E();\r\n    ARC033_F_PART();\r\
    \n    return 0;\r\n}\r\n"
  dependsOn:
  - math/math_017_modint.cpp
  - math/math_018_ragrange_polynomial.cpp
  isVerificationFile: false
  path: math/verify/verify_math_018_ragrange_polynomial.cpp
  requiredBy: []
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_018_ragrange_polynomial.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_018_ragrange_polynomial.cpp
- /library/math/verify/verify_math_018_ragrange_polynomial.cpp.html
title: math/verify/verify_math_018_ragrange_polynomial.cpp
---
