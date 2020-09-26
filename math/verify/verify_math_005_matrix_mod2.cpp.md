---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_005_matrix_mod2.cpp
    title: math/math_005_matrix_mod2.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/verify/verify_math_005_matrix_mod2.cpp\"\n#include\
    \ <vector>\n#include <bitset>\n#include <algorithm>\n#include <iostream>\n#include\
    \ <cassert>\nusing namespace std;\n#line 1 \"math/math_005_matrix_mod2.cpp\"\n\
    // mod2 \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA (bitset \u3092\u4F7F\u3063\u3066\
    \u9AD8\u901F\u5316\u3001\u6A2A\u306F SIZE \u56FA\u5B9A\u3068\u3059\u308B)\n//\
    \ TODO: \u4E57\u7B97\u306E verify\nstruct BinaryMatrix {\n    int H, W;\n    static\
    \ const int SIZE = 2010;\n    vector< bitset<SIZE> > mat;\n    BinaryMatrix(int\
    \ H_, int W_) : H(H_), W(W_), mat(H_) {}\n\n    // \u4E57\u7B97\u306B\u4F7F\u7528\
    \ (\u3053\u308C\u5FAE\u5999\u306B\u8EE2\u7F6E\u3058\u3083\u306A\u3044\u3051\u3069\
    \u306A\u3093\u3066\u3044\u3046\u3093\u3060)\n    BinaryMatrix T(const BinaryMatrix&\
    \ A) {\n        int h = A.H, w = A.W;\n        BinaryMatrix res(w, h);\n     \
    \   for(int i=0; i<h; i++) {\n            for(int j=0; j<w; j++) {\n         \
    \       res[j][i] = A[i][j];\n            }\n        }\n        return res;\n\
    \    }\n\n    BinaryMatrix& operator*=(const BinaryMatrix& rhs) {\n        assert(W\
    \ == rhs.H);\n        BinaryMatrix res(H, rhs.W), trhs = T(rhs);\n        for(int\
    \ i=0; i<H; i++) {\n            for(int j=0; j<rhs.W; j++) {\n               \
    \ res[i][j] = (mat[i] & trhs[j]).count() % 2;\n            }\n        }\n    \
    \    return (*this = res);\n    }\n    BinaryMatrix& operator+=(const BinaryMatrix\
    \ &rhs) {\n        assert(H == rhs.H and W == rhs.W);\n        for(int i=0; i<H;\
    \ i++) mat[i] ^= rhs[i];\n        return *this;\n    }\n    BinaryMatrix& operator-=(const\
    \ BinaryMatrix &rhs) {\n        return (*this += rhs);\n    }\n\n    BinaryMatrix\
    \ operator*(const BinaryMatrix &rhs) {\n        return (BinaryMatrix(*this) *=\
    \ rhs);\n    }\n    BinaryMatrix operator+(const BinaryMatrix &rhs) {\n      \
    \  return (BinaryMatrix(*this) += rhs);\n    }\n    BinaryMatrix operator-(const\
    \ BinaryMatrix &rhs) {\n        return (BinaryMatrix(*this) -= rhs);\n    }\n\n\
    \    bool operator==(const BinaryMatrix &rhs) const {\n        if(H != rhs.H or\
    \ W != rhs.W) return false;\n        for(int i=0; i<H; i++) if(mat[i] != rhs[i])\
    \ return false;\n        return true;\n    }\n    bool operator!=(const BinaryMatrix\
    \ &rhs) const {\n        return !(*this == rhs);\n    }\n\n    const bitset<SIZE>&\
    \ operator[](int k) const { return mat[k]; }\n    bitset<SIZE>& operator[](int\
    \ k) { return mat[k]; }\n};\n\nBinaryMatrix eigen(size_t N) {\n    BinaryMatrix\
    \ res(N, N);\n    for(size_t i=0; i<N; i++) res[i][i] = 1;\n    return res;\n\
    }\n\nBinaryMatrix pow(BinaryMatrix mat, long long int k) {\n    BinaryMatrix res\
    \ = eigen(mat.H);\n    for(; k>0; k>>=1) {\n        if(k & 1) res *= mat;\n  \
    \      mat *= mat;\n    }\n    return res;\n}\n\nint gaussianEliminationBinary(BinaryMatrix\
    \ &mat, bool ext=false) {\n    int N = mat.H, M = mat.W, rank = 0;\n    for(int\
    \ j=0; j+ext<M; j++) {\n        int piv = -1;\n        for(int i=rank; i<N; i++)\
    \ {\n            if(mat[i][j] != 0) piv = i, i = N;\n        }\n        if(piv\
    \ < 0) continue;\n        swap(mat[rank], mat[piv]);\n        for(int i=0; i<N;\
    \ i++) {\n            if(i == rank or mat[i][j] == 0) continue;\n            mat[i]\
    \ ^= mat[rank];\n        }\n        rank++;\n    }\n    return rank;\n}\n\nvector<int>\
    \ linearEquationBinary(BinaryMatrix A, vector<int> b) {\n    int N = A.H, M =\
    \ A.W;\n    BinaryMatrix mat(N, M+1);\n    for(int i=0; i<N; i++) {\n        for(int\
    \ j=0; j<=M; j++) {\n            mat[i][j] = (j < M ? A[i][j] : b[i]);\n     \
    \   }\n    }\n\n    int rank = gaussianEliminationBinary(mat, true);\n    vector<int>\
    \ res(N);\n    for(int i=0; i<N; i++) {\n        res[i] = mat[i][M];\n       \
    \ if(i >= rank and mat[i][M] != 0) return {};\n    }\n    return res;\n}\n\nint\
    \ detBinary(BinaryMatrix A) {\n    int N = A.H;\n    for(int j=0; j<N; j++) {\n\
    \        int piv = -1;\n        for(int i=j; i<N; i++) {\n            if(A[i][j]\
    \ != 0) piv = i, i = N;\n        }\n        if(piv < 0) return 0;\n        swap(A[piv],\
    \ A[j]);\n        for(int i=j+1; i<N; i++) {\n            if(A[i][j]) A[i] ^=\
    \ A[j];\n        }\n    }\n    int res = 1;\n    for(int i=0; i<N; i++) res *=\
    \ A[i][i];\n    return res;\n}\n#line 8 \"math/verify/verify_math_005_matrix_mod2.cpp\"\
    \n\nvoid ARC054_C() {\n    int N; cin >> N;\n    BinaryMatrix mat(N, N);\n   \
    \ for(int i=0; i<N; i++) {\n        for(int j=0; j<N; j++) {\n            char\
    \ c; cin >> c;\n            if(c == '1') mat[i][j] = 1;\n        }\n    }\n\n\
    \    int d = detBinary(mat);\n    if(d == 0) cout << \"Even\" << endl;\n    else\
    \ cout << \"Odd\" << endl;\n}\n\nvoid yuki_803() {\n    const int B = 30;\n  \
    \  int N, M, X; cin >> N >> M >> X;\n    BinaryMatrix mat(B+M, N+1);\n\n    for(int\
    \ j=0; j<B; j++) {\n        int p = X & 1;\n        mat[j][N] = p;\n        X\
    \ >>= 1;\n    }\n\n    for(int i=0; i<N; i++) {\n        int val; cin >> val;\n\
    \        for(int j=0; j<B; j++) {\n            int p = val & 1;\n            mat[j][i]\
    \ = p;\n            val >>= 1;\n        }\n    }\n\n    for(int i=0; i<M; i++)\
    \ {\n        int t, l, r; cin >> t >> l >> r; l--;\n        mat[B+i][N] = t;\n\
    \        for(int x=l; x<r; x++) mat[B+i][x] = 1;\n    }\n\n    int rank = gaussianEliminationBinary(mat,\
    \ true);\n    for(int i=rank; i<B+M; i++) {\n        if(mat[i][N] != 0) {\n  \
    \          cout << 0 << endl;\n            return;\n        }\n    }\n\n    int\
    \ p = N - rank, ans = 1, MOD = 1000000007;\n    for(int i=0; i<p; i++) (ans *=\
    \ 2) %= MOD;\n    cout << ans << endl;\n}\n\nint main() {\n    // ARC054_C();\
    \ // detBinary\n    // yuki_803(); // gaussianEliminationBinary\n    return 0;\n\
    }\n"
  code: "#include <vector>\n#include <bitset>\n#include <algorithm>\n#include <iostream>\n\
    #include <cassert>\nusing namespace std;\n#include \"../math_005_matrix_mod2.cpp\"\
    \n\nvoid ARC054_C() {\n    int N; cin >> N;\n    BinaryMatrix mat(N, N);\n   \
    \ for(int i=0; i<N; i++) {\n        for(int j=0; j<N; j++) {\n            char\
    \ c; cin >> c;\n            if(c == '1') mat[i][j] = 1;\n        }\n    }\n\n\
    \    int d = detBinary(mat);\n    if(d == 0) cout << \"Even\" << endl;\n    else\
    \ cout << \"Odd\" << endl;\n}\n\nvoid yuki_803() {\n    const int B = 30;\n  \
    \  int N, M, X; cin >> N >> M >> X;\n    BinaryMatrix mat(B+M, N+1);\n\n    for(int\
    \ j=0; j<B; j++) {\n        int p = X & 1;\n        mat[j][N] = p;\n        X\
    \ >>= 1;\n    }\n\n    for(int i=0; i<N; i++) {\n        int val; cin >> val;\n\
    \        for(int j=0; j<B; j++) {\n            int p = val & 1;\n            mat[j][i]\
    \ = p;\n            val >>= 1;\n        }\n    }\n\n    for(int i=0; i<M; i++)\
    \ {\n        int t, l, r; cin >> t >> l >> r; l--;\n        mat[B+i][N] = t;\n\
    \        for(int x=l; x<r; x++) mat[B+i][x] = 1;\n    }\n\n    int rank = gaussianEliminationBinary(mat,\
    \ true);\n    for(int i=rank; i<B+M; i++) {\n        if(mat[i][N] != 0) {\n  \
    \          cout << 0 << endl;\n            return;\n        }\n    }\n\n    int\
    \ p = N - rank, ans = 1, MOD = 1000000007;\n    for(int i=0; i<p; i++) (ans *=\
    \ 2) %= MOD;\n    cout << ans << endl;\n}\n\nint main() {\n    // ARC054_C();\
    \ // detBinary\n    // yuki_803(); // gaussianEliminationBinary\n    return 0;\n\
    }\n"
  dependsOn:
  - math/math_005_matrix_mod2.cpp
  isVerificationFile: false
  path: math/verify/verify_math_005_matrix_mod2.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_005_matrix_mod2.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_005_matrix_mod2.cpp
- /library/math/verify/verify_math_005_matrix_mod2.cpp.html
title: math/verify/verify_math_005_matrix_mod2.cpp
---
