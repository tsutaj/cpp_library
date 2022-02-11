---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_004_matrix.cpp
    title: math/math_004_matrix.cpp
  - icon: ':x:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  - icon: ':warning:'
    path: math/math_023_matrix_utils_modp.cpp
    title: math/math_023_matrix_utils_modp.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/verify/verify_math_023_matrix_utils_modp.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <iostream>\n#include <cstdio>\n#include\
    \ <cmath>\n#include <iomanip>\nusing namespace std;\n#line 1 \"math/math_017_modint.cpp\"\
    \n// ModInt begin\r\n\r\nusing ll = long long;\r\ntemplate<ll mod>\r\nstruct ModInt\
    \ {\r\n    ll v;\r\n    ll mod_pow(ll x, ll n) const {\r\n        return (!n)\
    \ ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;\r\n    }\r\n    ModInt(ll\
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
    \ end\r\n#line 1 \"math/math_004_matrix.cpp\"\n// \u884C\u5217\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n\n// size(): \u884C\u6570\u3092\u8FD4\u3059 (\u5217\u6570\u306F\
    \ mat[0].size() \u3067)\n// \u6F14\u7B97\u5B50: \u8907\u5408\u4EE3\u5165 (+=,\
    \ *=, -=), \u5358\u9805 (-), \u4E8C\u9805 (+, -, *, ==)\n// eigen(N): N*N \u5358\
    \u4F4D\u884C\u5217\u3092\u8FD4\u3059\n// pow(mat, k): mat \u306E k \u4E57\u3092\
    \u8FD4\u3059\n\ntemplate <typename T>\nstruct Matrix {\n    vector< vector<T>\
    \ > mat;\n    Matrix() {}\n    Matrix(int h, int w, T val = T(0)) : mat(h, vector<T>(w,\
    \ val)) {}\n    size_t size() const { return mat.size(); }\n    const vector<T>&\
    \ operator[](int i) const { return mat[i]; }\n    vector<T>& operator[](int i)\
    \ { return mat[i]; }\n\n    Matrix<T> &operator+=(const Matrix<T>& rhs) {\n  \
    \      assert(mat.size() == rhs.size());\n        assert(mat[0].size() == rhs[0].size());\n\
    \        for(size_t i=0; i<mat.size(); i++) {\n            for(size_t j=0; j<mat[0].size();\
    \ j++) {\n                mat[i][j] += rhs[i][j];\n            }\n        }\n\
    \        return *this;\n    }\n\n    Matrix<T> operator-() const {\n        Matrix<T>\
    \ res(*this);\n        for(size_t i=0; i<res.size(); i++) {\n            for(size_t\
    \ j=0; j<res[0].size(); j++) {\n                res[i][j] *= T(-1);\n        \
    \    }\n        }\n        return res;\n    }\n\n    Matrix<T>& operator-=(const\
    \ Matrix<T>& rhs) {\n        return (Matrix<T>(*this) += -rhs);\n    }\n\n   \
    \ Matrix<T>& operator*=(const Matrix<T>& rhs) {\n        assert(mat[0].size()\
    \ == rhs.size());\n        size_t H = mat.size(), W = rhs[0].size(), C = rhs.size();\n\
    \        Matrix<T> res(H, W);\n        for(size_t i=0; i<H; i++) {\n         \
    \   for(size_t j=0; j<W; j++) {\n                for(size_t k=0; k<C; k++) {\n\
    \                    res[i][j] += mat[i][k] * rhs[k][j];\n                }\n\
    \            }\n        }\n        this->mat = res.mat;\n        return *this;\n\
    \    }\n\n    Matrix<T> operator+(const Matrix<T>& rhs) {\n        return (Matrix<T>(*this)\
    \ += rhs);\n    }\n\n    Matrix<T> operator*(const Matrix<T>& rhs) {\n       \
    \ return (Matrix<T>(*this) *= rhs);\n    }\n\n    Matrix<T> operator-(const Matrix<T>\
    \ &rhs) {\n        return (Matrix<T>(*this) -= rhs);\n    }\n\n    bool operator==(const\
    \ Matrix<T> &rhs) const {\n        return this->mat == rhs.mat;\n    }\n    bool\
    \ operator!=(const Matrix<T> &rhs) const {\n        return !(*this == rhs);\n\
    \    }\n};\n\ntemplate <typename T>\nMatrix<T> eigen(size_t N) {\n    Matrix<T>\
    \ res(N, N, 0);\n    for(size_t i=0; i<N; i++) res[i][i] = T(1);\n    return res;\n\
    }\n\ntemplate <typename T>\nMatrix<T> pow(Matrix<T> mat, long long int k) {\n\
    \    Matrix<T> res = eigen<T>(mat.size());\n    for(; k>0; k>>=1) {\n        if(k\
    \ & 1) res *= mat;\n        mat *= mat;\n    }\n    return res;\n}\n\ntemplate\
    \ <typename T>\nostream& operator<< (ostream& out, Matrix<T> mat) {\n    int H\
    \ = mat.size(), W = mat[0].size();\n    out << \"[\" << endl;\n    for(int i=0;\
    \ i<H; i++) {\n        out << \"  [ \";\n        for(int j=0; j<W; j++) out <<\
    \ mat[i][j] << \" \";\n        out << \"]\" << endl;\n    }\n    out << \"]\"\
    \ << endl;\n    return out;\n}\n#line 1 \"math/math_023_matrix_utils_modp.cpp\"\
    \n// mod p \u884C\u5217\u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\u4F5C\n\
    // \u5B9F\u6570\u3058\u3083\u306A\u3044\u306E\u3067\u7D76\u5BFE\u5024\u6700\u5927\
    \u306E\u3082\u306E\u3092 pivot \u306B\u3059\u308B\u3068\u304B\u304C\u3044\u3089\
    \u306A\u3044\n\n// \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\ntemplate <typename\
    \ mint>\nint gaussianEliminationModp(Matrix<mint> &mat, bool ext=false) {\n  \
    \  int N = mat.size(), M = mat[0].size(), rank = 0;\n    for(int j=0; j+ext<M;\
    \ j++) {\n        int piv = -1;\n        for(int i=rank; i<N; i++) {\n       \
    \     if(mat[i][j] != mint(0)) piv = i, i = N;\n        }\n        if(piv < 0)\
    \ continue;\n        swap(mat[rank], mat[piv]);\n        mint div(mat[rank][j]);\n\
    \        for(auto &v : mat[rank]) v /= div;\n        for(int i=0; i<N; i++) {\n\
    \            if(i == rank or mat[i][j] == mint(0)) continue;\n            mint\
    \ scale = mat[i][j];\n            for(int k=0; k<M; k++) {\n                mat[i][k]\
    \ -= mat[rank][k] * scale;\n            }\n        }\n        rank++;\n    }\n\
    \    return rank;\n}\n\ntemplate <typename mint>\nvector<mint> linearEquationModp(Matrix<mint>\
    \ A, vector<mint> b) {\n    int N = A.size(), M = A[0].size();\n    Matrix<mint>\
    \ mat(N, M+1);\n    for(int i=0; i<N; i++) {\n        for(int j=0; j<M+1; j++)\
    \ {\n            mat[i][j] = (j < M ? A[i][j] : b[i]);\n        }\n    }\n\n \
    \   int rank = gaussianEliminationModp(mat, true);\n    vector<mint> res(N);\n\
    \    for(int i=0; i<N; i++) {\n        res[i] = mat[i][M];\n        if(i >= rank\
    \ and mat[i][M] != mint(0)) return {};\n    }\n    return res;\n}\n\ntemplate\
    \ <typename mint>\nmint detModp(Matrix<mint> A) {\n    int N = A.size(), cnt_swap\
    \ = 0;\n    for(int j=0; j<N; j++) {\n        int piv = -1;\n        for(int i=j;\
    \ i<N; i++) {\n            if(A[i][j] != mint(0)) piv = i, i = N;\n        }\n\
    \        if(piv < 0) return mint(0);\n        cnt_swap += (piv != j);\n      \
    \  swap(A[piv], A[j]);\n        for(int i=j+1; i<N; i++) {\n            mint scale(A[i][j]\
    \ / A[j][j]);\n            for(int k=0; k<N; k++) {\n                A[i][k] -=\
    \ A[j][k] * scale;\n            }\n        }\n    }\n\n    mint res = (cnt_swap\
    \ % 2 ? mint(-1) : mint(1));\n    for(int i=0; i<N; i++) res *= A[i][i];\n   \
    \ return res;\n}\n#line 11 \"math/verify/verify_math_023_matrix_utils_modp.cpp\"\
    \n\n\nvoid ARC054_C() {\n    using mint = ModInt<2>;\n    int N; cin >> N;\n \
    \   Matrix<mint> mat(N, N);\n    for(int i=0; i<N; i++) {\n        for(int j=0;\
    \ j<N; j++) {\n            char c; cin >> c;\n            if(c == '1') mat[i][j]\
    \ = mint(1);\n        }\n    }\n\n    mint d = detModp(mat);\n    if(d == mint(0))\
    \ cout << \"Even\" << endl;\n    else cout << \"Odd\" << endl;\n}\n\nvoid yuki_803()\
    \ {\n    using mint = ModInt<2>;\n    const int B = 30;\n    int N, M, X; cin\
    \ >> N >> M >> X;\n    Matrix<mint> mat(B+M, N+1);\n\n    for(int j=0; j<B; j++)\
    \ {\n        int p = X & 1;\n        mat[j][N] = mint(p);\n        X >>= 1;\n\
    \    }\n\n    for(int i=0; i<N; i++) {\n        int val; cin >> val;\n       \
    \ for(int j=0; j<B; j++) {\n            int p = val & 1;\n            mat[j][i]\
    \ = mint(p);\n            val >>= 1;\n        }\n    }\n\n    for(int i=0; i<M;\
    \ i++) {\n        int t, l, r; cin >> t >> l >> r; l--;\n        mat[B+i][N] =\
    \ t;\n        for(int x=l; x<r; x++) mat[B+i][x] = 1;\n    }\n\n    int rank =\
    \ gaussianEliminationModp(mat, true);\n    for(int i=rank; i<B+M; i++) {\n   \
    \     if(mat[i][N] != mint(0)) {\n            cout << 0 << endl;\n           \
    \ return;\n        }\n    }\n\n    int p = N - rank;\n    cout << ModInt<1000000007>(2).pow(p)\
    \ << endl;\n}\n\nint main() {\n    // ARC054_C(); // detModp\n    yuki_803();\
    \ // gaussianEliminationModp\n}\n"
  code: "#include <vector>\n#include <algorithm>\n#include <iostream>\n#include <cstdio>\n\
    #include <cmath>\n#include <iomanip>\nusing namespace std;\n#include \"../math_017_modint.cpp\"\
    \n#include \"../math_004_matrix.cpp\"\n#include \"../math_023_matrix_utils_modp.cpp\"\
    \n\n\nvoid ARC054_C() {\n    using mint = ModInt<2>;\n    int N; cin >> N;\n \
    \   Matrix<mint> mat(N, N);\n    for(int i=0; i<N; i++) {\n        for(int j=0;\
    \ j<N; j++) {\n            char c; cin >> c;\n            if(c == '1') mat[i][j]\
    \ = mint(1);\n        }\n    }\n\n    mint d = detModp(mat);\n    if(d == mint(0))\
    \ cout << \"Even\" << endl;\n    else cout << \"Odd\" << endl;\n}\n\nvoid yuki_803()\
    \ {\n    using mint = ModInt<2>;\n    const int B = 30;\n    int N, M, X; cin\
    \ >> N >> M >> X;\n    Matrix<mint> mat(B+M, N+1);\n\n    for(int j=0; j<B; j++)\
    \ {\n        int p = X & 1;\n        mat[j][N] = mint(p);\n        X >>= 1;\n\
    \    }\n\n    for(int i=0; i<N; i++) {\n        int val; cin >> val;\n       \
    \ for(int j=0; j<B; j++) {\n            int p = val & 1;\n            mat[j][i]\
    \ = mint(p);\n            val >>= 1;\n        }\n    }\n\n    for(int i=0; i<M;\
    \ i++) {\n        int t, l, r; cin >> t >> l >> r; l--;\n        mat[B+i][N] =\
    \ t;\n        for(int x=l; x<r; x++) mat[B+i][x] = 1;\n    }\n\n    int rank =\
    \ gaussianEliminationModp(mat, true);\n    for(int i=rank; i<B+M; i++) {\n   \
    \     if(mat[i][N] != mint(0)) {\n            cout << 0 << endl;\n           \
    \ return;\n        }\n    }\n\n    int p = N - rank;\n    cout << ModInt<1000000007>(2).pow(p)\
    \ << endl;\n}\n\nint main() {\n    // ARC054_C(); // detModp\n    yuki_803();\
    \ // gaussianEliminationModp\n}\n"
  dependsOn:
  - math/math_017_modint.cpp
  - math/math_004_matrix.cpp
  - math/math_023_matrix_utils_modp.cpp
  isVerificationFile: false
  path: math/verify/verify_math_023_matrix_utils_modp.cpp
  requiredBy: []
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_023_matrix_utils_modp.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_023_matrix_utils_modp.cpp
- /library/math/verify/verify_math_023_matrix_utils_modp.cpp.html
title: math/verify/verify_math_023_matrix_utils_modp.cpp
---
