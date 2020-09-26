---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  - icon: ':warning:'
    path: math/math_020_combination.cpp
    title: math/math_020_combination.cpp
  - icon: ':warning:'
    path: math/math_019_specific_ragrange_polynomial.cpp
    title: math/math_019_specific_ragrange_polynomial.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://arc033.contest.atcoder.jp/tasks/arc033_4
    - https://codeforces.com/contest/1155/problem/E
  bundledCode: "#line 1 \"math/verify/verify_math_019_specific_ragrange_polynomial.cpp\"\
    \n#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing namespace\
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
    \n    return in;\r\n}\r\n\r\n// ModInt end\r\n#line 1 \"math/math_020_combination.cpp\"\
    \n// \u5404\u7A2E\u7D44\u307F\u5408\u308F\u305B\u3092\u6C42\u3081\u308B\u30E9\u30A4\
    \u30D6\u30E9\u30EA\ntemplate <typename NumType>\nstruct Combination {\n    int\
    \ LIMIT;\n    vector<NumType> fact_, finv_;\n\n    Combination() {}\n    Combination(int\
    \ LIMIT_) : LIMIT(LIMIT_), fact_(LIMIT+1), finv_(LIMIT+1) {\n        fact_[0]\
    \ = finv_[LIMIT] = NumType(1);\n        for(int i=1; i<=LIMIT; i++) {\n      \
    \      fact_[i] = fact_[i-1] * NumType(i);\n        }\n        \n        finv_[LIMIT]\
    \ /= fact_[LIMIT];\n        for(int i=LIMIT-1; i>=0; i--) {\n            finv_[i]\
    \ = finv_[i+1] * NumType(i+1);\n        }\n    }\n\n    inline NumType fact(int\
    \ k) const { return fact_[k]; }\n    inline NumType finv(int k) const { return\
    \ finv_[k]; }\n    NumType P(int n, int r) const {\n        if(r < 0 or n < r)\
    \ return NumType(0);\n        return fact_[n] * finv_[n-r];\n    }\n    NumType\
    \ C(int n, int r) const {\n        if(r < 0 or n < r) return NumType(0);\n   \
    \     return fact_[n] * finv_[n-r] * finv_[r];\n    }\n    // \u91CD\u8907\u7D44\
    \u307F\u5408\u308F\u305B\n    NumType H(int n, int r) const {\n        if(n <\
    \ 0 or r < 0) return NumType(0);\n        return r == 0 ? NumType(1) : C(n + r\
    \ - 1, r);\n    }\n    // \u30D9\u30EB\u6570 (\u533A\u5225\u3067\u304D\u308B n\
    \ \u500B\u306E\u30DC\u30FC\u30EB\u3092\u533A\u5225\u3067\u304D\u306A\u3044 k \u500B\
    \u4EE5\u4E0B\u306E\u7BB1\u306B\u5206\u5272)\n    // B(n, n) := n \u500B\u306E\u30DC\
    \u30FC\u30EB\u3092\u4EFB\u610F\u500B\u306E\u30B0\u30EB\u30FC\u30D7\u306B\u5206\
    \u5272\u3059\u308B\u5834\u5408\u306E\u6570\n    NumType B(int n, int k) const\
    \ {\n        if(n == 0) return NumType(1);\n        k = min(n, k);\n        NumType\
    \ ret(0);\n        vector<NumType> pref(k + 1); pref[0] = NumType(1);\n      \
    \  for(int i=1; i<=k; i++) {\n            if(i & 1) pref[i] = pref[i-1] - finv_[i];\n\
    \            else pref[i] = pref[i-1] + finv_[i];\n        }\n        for(int\
    \ i=1; i<=k; i++) {\n            // \u7D2F\u4E57\u304C\u5FC5\u8981\u306A\u306E\
    \u3067\u9069\u5B9C\u66F8\u304D\u63DB\u3048\u308B\uFF1F\n            // ModInt\
    \ \u4F7F\u3046\u306A\u3089\u3053\u308C\u3067\u3044\u3044\n            ret += NumType(i).pow(n)\
    \ * finv_[i] * pref[k-i];\n        }\n        return ret;\n    }\n    // \u30B9\
    \u30BF\u30FC\u30EA\u30F3\u30B0\u6570 (\u533A\u5225\u3067\u304D\u308B n \u500B\u306E\
    \u30DC\u30FC\u30EB\u3092\u533A\u5225\u3067\u304D\u306A\u3044 k \u500B\u306E\u7BB1\
    \u306B\u5206\u5272)\n    NumType S(int n, int k) const {\n        if(n < k) return\
    \ NumType(0);\n        NumType ans(0);\n        for(int i=0; i<=k; i++) {\n  \
    \          NumType val = C(k, i) * NumType(i).pow(n);\n            if((k - i)\
    \ % 2) ans -= val;\n            else ans += val;\n        }\n        return ans\
    \ * finv_[k];\n    }\n\n    // \u30E9\u30F3\u30C0\u30E0\u30A6\u30A9\u30FC\u30AF\
    : \u5DE6\u306B X \u56DE\u3001\u53F3\u306B Y \u56DE\u9032\u3080\u3068\u304D\u3001\
    \n    // \u79FB\u52D5\u9014\u4E2D\u30FB\u7D42\u4E86\u6642\u306B\u5EA7\u6A19 K\
    \ \u3092\u8D85\u3048\u306A\u3044\u3082\u306E\u3092\u6570\u3048\u308B\n    // K\
    \ \u304C\u975E\u8CA0\u306A\u3089\u5DE6\u5074\u3001\u8CA0\u306A\u3089\u53F3\u5074\
    \u9818\u57DF (\uFF1F) \u306E\u30E9\u30F3\u30C0\u30E0\u30A6\u30A9\u30FC\u30AF\n\
    \    NumType walk(int X, int Y, int K) {\n        if(K < 0) return walk(Y, X,\
    \ -K);\n        if(Y <= K) return C(X+Y, X); // \u5F15\u3063\u304B\u304B\u3089\
    \u306A\u3044\n        if(Y - X > K) return NumType(0); // \u305D\u3082\u305D\u3082\
    \u5408\u8A08\u304C\u8D85\u3048\u308B\n        \n        int A = Y - K - 1, B =\
    \ X + K + 1;\n        return C(X+Y, X) - C(A+B, A);\n    }\n};\n\n// P(n, k) :=\
    \ n \u306E k \u5206\u5272 (k \u500B\u306E 0 \u4EE5\u4E0A\u306E\u6574\u6570\u306E\
    \u548C)\ntemplate <typename NumType, int LIMIT = 3010>\nstruct Partition {\n \
    \   vector< vector<NumType> > dp;\n    Partition() : dp(LIMIT, vector<NumType>(LIMIT))\
    \ {\n        for(int k=0; k<LIMIT; k++) dp[0][k] = NumType(1);\n        for(int\
    \ i=1; i<LIMIT; i++) {\n            for(int j=1; j<LIMIT; j++) {\n           \
    \     dp[i][j] += dp[i][j-1];\n                if(i-j >= 0) dp[i][j] += dp[i-j][j];\n\
    \            }\n        }\n    }\n    inline NumType get(int n, int k) {\n   \
    \     if(n < 0 or k < 0) return NumType(0);\n        return dp[n][k];\n    }\n\
    };\n#line 1 \"math/math_019_specific_ragrange_polynomial.cpp\"\nll mod_pow(ll\
    \ n, ll k, ll mod) {\r\n    ll res = 1;\r\n    for(; k>0; k>>=1) {\r\n       \
    \ if(k & 1) (res *= n) %= mod;\r\n        (n *= n) %= mod;\r\n    }\r\n    return\
    \ res;\r\n}\r\n\r\n// N \u672A\u6E80\u306E\u7BC4\u56F2\u3067\u3001i \u306E\u9006\
    \u5143 (mod P) \u3092\u914D\u5217\u306B\u899A\u3048\u308B\r\ntemplate <typename\
    \ NumType>\r\nvector<NumType> get_inv_table(int N, int P) {\r\n    vector<NumType>\
    \ res;\r\n    for(int i=0; i<N; i++) {\r\n        res.emplace_back(NumType(mod_pow(i,\
    \ P-2, P)));\r\n    }\r\n    return res;\r\n}\r\n\r\n// f(0) ... f(N) \u306E\u5024\
    \u304C\u308F\u304B\u3063\u3066\u3044\u308B\u3068\u304D\u306B\r\n// \u591A\u9805\
    \u5F0F\u88DC\u9593\u3092 O(N) \u3067\u5B9F\u73FE\u3059\u308B\u30D0\u30FC\u30B8\
    \u30E7\u30F3\u306E\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\r\ntemplate\
    \ <typename NumType, int LIMIT = 2000010>\r\nstruct SpecificLagrangePolynomial\
    \ {\r\n    Combination<NumType> comb;\r\n    vector<NumType> y, inv_table;\r\n\
    \    bool use_inv_table;\r\n    SpecificLagrangePolynomial() : comb(), y() {}\r\
    \n    SpecificLagrangePolynomial(vector<NumType> y_, int P=LIMIT)\r\n        :\
    \ comb(min(LIMIT, P-1)), y(y_), use_inv_table(false) {\r\n        if(P < LIMIT)\
    \ use_inv_table = true;\r\n        \r\n        // get_inv_table \u304C\u306A\u3044\
    \u3068 CE \u306B\u306A\u308B\u306E\u3067\u3001\r\n        // \u30B3\u30D4\u30DA\
    \u304C\u9762\u5012\u306A\u3089\u3053\u3053\u3092\u6D88\u3059 (\u6700\u60AA)\r\n\
    \        if(use_inv_table) {\r\n            inv_table = get_inv_table<NumType>(P,\
    \ P);\r\n        }\r\n    }\r\n\r\n    NumType interpolate(NumType p) {\r\n  \
    \      NumType pre(1);\r\n        int N = y.size(), pv = int(p);\r\n        if(pv\
    \ < N) return y[pv];\r\n        for(int i=0; i<N; i++) {\r\n            pre *=\
    \ NumType(pv - i);\r\n        }\r\n        \r\n        NumType res(0);\r\n   \
    \     for(int i=0; i<N; i++) {\r\n            NumType numer(0), denom(1);\r\n\
    \            if(use_inv_table)\r\n                numer = pre * inv_table[pv -\
    \ i];\r\n            else\r\n                numer = pre / NumType(pv - i);\r\n\
    \r\n            denom *= comb.finv(N - 1 - i) * comb.finv(i);\r\n            if((N\
    \ - 1 - i) % 2) res -= numer * denom * y[i];\r\n            else res += numer\
    \ * denom * y[i];\r\n        }\r\n        return res;\r\n    }\r\n};\r\n#line\
    \ 8 \"math/verify/verify_math_019_specific_ragrange_polynomial.cpp\"\n\r\n// Verified\
    \ on Apr 23, 2019\r\n// Educational Codeforces Round 63 E: Guess the Root\r\n\
    // Judge: https://codeforces.com/contest/1155/problem/E\r\n// TLE \u304C\u53B3\
    \u3057\u3044\u306E\u3067\u9006\u5143\u306F\u524D\u8A08\u7B97\u3057\u306A\u3044\
    \u3068\u901A\u308A\u307E\u305B\u3093\r\n// \u3042\u3068 f(0) \u304B\u3089 f(N)\
    \ \u307E\u3067\u308F\u304B\u3063\u3066\u3044\u308C\u3070 O(N) \u3067\u3067\u304D\
    \u308B\u306E\u3067\u305D\u3061\u3089\u306E\u6226\u7565\u306E\u307B\u3046\u304C\
    \u3088\u3044\u304B\u3082\r\nvoid ECR065_E() {\r\n    const int MOD = 1000003;\r\
    \n    using mint = ModInt<MOD>;\r\n\r\n    const int DEG = 11;\r\n    auto eval_expr\
    \ = [&](vector<mint> &expr, mint x) {\r\n        mint base(1), res(0);\r\n   \
    \     for(int i=0; i<DEG; i++) {\r\n            res += expr[i] * base;\r\n   \
    \         base *= x;\r\n        }\r\n        return res;\r\n    };\r\n    \r\n\
    \    vector<mint> x, y, expr;\r\n    vector<int> raw_expr = {1, 0, 1, 0, 0, 0,\
    \ 0, 0, 0, 0, 0};\r\n    for(int i=0; i<DEG; i++) {\r\n        expr.emplace_back(mint(raw_expr[i]));\r\
    \n    }\r\n    \r\n    for(int i=0; i<DEG; i++) {\r\n        x.push_back(mint(i));\r\
    \n        cout << \"? \" << i << endl;\r\n        int res;\r\n        cin >> res;\r\
    \n        // res = eval_expr(expr, i).v;\r\n        y.push_back(mint(res));\r\n\
    \    }\r\n\r\n    SpecificLagrangePolynomial<mint> lp(y, MOD);\r\n    for(int\
    \ i=0; i<MOD; i++) {\r\n        if(lp.interpolate(i) == mint(0)) {\r\n       \
    \     cout << \"! \" << i << endl;\r\n            return;\r\n        }\r\n   \
    \ }\r\n    cout << \"! \" << -1 << endl;\r\n}\r\n\r\n// Verified on Apr 23, 2019\r\
    \n// AtCoder Regular Contest 033 F (\u65E7 D): \u898B\u305F\u3053\u3068\u306E\u306A\
    \u3044\u591A\u9805\u5F0F\r\n// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4\r\
    \nvoid ARC033_F() {\r\n    const int MOD = 1000000007;\r\n    using mint = ModInt<MOD>;\r\
    \n\r\n    int N; cin >> N;\r\n    vector<mint> y(N+1);\r\n    for(int i=0; i<=N;\
    \ i++) cin >> y[i];\r\n\r\n    int T; cin >> T;\r\n    SpecificLagrangePolynomial<mint>\
    \ lp(y);\r\n    cout << lp.interpolate(T) << endl;\r\n}\r\n\r\nint main() {\r\n\
    \    // ECR065_E();\r\n    ARC033_F();\r\n    return 0;\r\n}\r\n"
  code: "#include <iostream>\r\n#include <vector>\r\n#include <algorithm>\r\nusing\
    \ namespace std;\r\n#include \"../math_017_modint.cpp\"\r\n#include \"../math_020_combination.cpp\"\
    \r\n#include \"../math_019_specific_ragrange_polynomial.cpp\"\r\n\r\n// Verified\
    \ on Apr 23, 2019\r\n// Educational Codeforces Round 63 E: Guess the Root\r\n\
    // Judge: https://codeforces.com/contest/1155/problem/E\r\n// TLE \u304C\u53B3\
    \u3057\u3044\u306E\u3067\u9006\u5143\u306F\u524D\u8A08\u7B97\u3057\u306A\u3044\
    \u3068\u901A\u308A\u307E\u305B\u3093\r\n// \u3042\u3068 f(0) \u304B\u3089 f(N)\
    \ \u307E\u3067\u308F\u304B\u3063\u3066\u3044\u308C\u3070 O(N) \u3067\u3067\u304D\
    \u308B\u306E\u3067\u305D\u3061\u3089\u306E\u6226\u7565\u306E\u307B\u3046\u304C\
    \u3088\u3044\u304B\u3082\r\nvoid ECR065_E() {\r\n    const int MOD = 1000003;\r\
    \n    using mint = ModInt<MOD>;\r\n\r\n    const int DEG = 11;\r\n    auto eval_expr\
    \ = [&](vector<mint> &expr, mint x) {\r\n        mint base(1), res(0);\r\n   \
    \     for(int i=0; i<DEG; i++) {\r\n            res += expr[i] * base;\r\n   \
    \         base *= x;\r\n        }\r\n        return res;\r\n    };\r\n    \r\n\
    \    vector<mint> x, y, expr;\r\n    vector<int> raw_expr = {1, 0, 1, 0, 0, 0,\
    \ 0, 0, 0, 0, 0};\r\n    for(int i=0; i<DEG; i++) {\r\n        expr.emplace_back(mint(raw_expr[i]));\r\
    \n    }\r\n    \r\n    for(int i=0; i<DEG; i++) {\r\n        x.push_back(mint(i));\r\
    \n        cout << \"? \" << i << endl;\r\n        int res;\r\n        cin >> res;\r\
    \n        // res = eval_expr(expr, i).v;\r\n        y.push_back(mint(res));\r\n\
    \    }\r\n\r\n    SpecificLagrangePolynomial<mint> lp(y, MOD);\r\n    for(int\
    \ i=0; i<MOD; i++) {\r\n        if(lp.interpolate(i) == mint(0)) {\r\n       \
    \     cout << \"! \" << i << endl;\r\n            return;\r\n        }\r\n   \
    \ }\r\n    cout << \"! \" << -1 << endl;\r\n}\r\n\r\n// Verified on Apr 23, 2019\r\
    \n// AtCoder Regular Contest 033 F (\u65E7 D): \u898B\u305F\u3053\u3068\u306E\u306A\
    \u3044\u591A\u9805\u5F0F\r\n// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4\r\
    \nvoid ARC033_F() {\r\n    const int MOD = 1000000007;\r\n    using mint = ModInt<MOD>;\r\
    \n\r\n    int N; cin >> N;\r\n    vector<mint> y(N+1);\r\n    for(int i=0; i<=N;\
    \ i++) cin >> y[i];\r\n\r\n    int T; cin >> T;\r\n    SpecificLagrangePolynomial<mint>\
    \ lp(y);\r\n    cout << lp.interpolate(T) << endl;\r\n}\r\n\r\nint main() {\r\n\
    \    // ECR065_E();\r\n    ARC033_F();\r\n    return 0;\r\n}\r\n"
  dependsOn:
  - math/math_017_modint.cpp
  - math/math_020_combination.cpp
  - math/math_019_specific_ragrange_polynomial.cpp
  isVerificationFile: false
  path: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
  requiredBy: []
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_019_specific_ragrange_polynomial.cpp
- /library/math/verify/verify_math_019_specific_ragrange_polynomial.cpp.html
title: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
---
