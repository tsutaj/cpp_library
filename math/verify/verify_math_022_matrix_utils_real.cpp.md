---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: math/math_004_matrix.cpp
    title: math/math_004_matrix.cpp
  - icon: ':warning:'
    path: math/math_022_matrix_utils_real.cpp
    title: math/math_022_matrix_utils_real.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/verify/verify_math_022_matrix_utils_real.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <iostream>\n#include <cstdio>\n#include\
    \ <cmath>\n#include <iomanip>\nusing namespace std;\n#line 1 \"math/math_004_matrix.cpp\"\
    \n// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n\n// size(): \u884C\u6570\u3092\
    \u8FD4\u3059 (\u5217\u6570\u306F mat[0].size() \u3067)\n// \u6F14\u7B97\u5B50\
    : \u8907\u5408\u4EE3\u5165 (+=, *=, -=), \u5358\u9805 (-), \u4E8C\u9805 (+, -,\
    \ *, ==)\n// eigen(N): N*N \u5358\u4F4D\u884C\u5217\u3092\u8FD4\u3059\n// pow(mat,\
    \ k): mat \u306E k \u4E57\u3092\u8FD4\u3059\n\ntemplate <typename T>\nstruct Matrix\
    \ {\n    vector< vector<T> > mat;\n    Matrix() {}\n    Matrix(int h, int w, T\
    \ val = T(0)) : mat(h, vector<T>(w, val)) {}\n    size_t size() const { return\
    \ mat.size(); }\n    const vector<T>& operator[](int i) const { return mat[i];\
    \ }\n    vector<T>& operator[](int i) { return mat[i]; }\n\n    Matrix<T> &operator+=(const\
    \ Matrix<T>& rhs) {\n        assert(mat.size() == rhs.size());\n        assert(mat[0].size()\
    \ == rhs[0].size());\n        for(size_t i=0; i<mat.size(); i++) {\n         \
    \   for(size_t j=0; j<mat[0].size(); j++) {\n                mat[i][j] += rhs[i][j];\n\
    \            }\n        }\n        return *this;\n    }\n\n    Matrix<T> operator-()\
    \ const {\n        Matrix<T> res(*this);\n        for(size_t i=0; i<res.size();\
    \ i++) {\n            for(size_t j=0; j<res[0].size(); j++) {\n              \
    \  res[i][j] *= T(-1);\n            }\n        }\n        return res;\n    }\n\
    \n    Matrix<T>& operator-=(const Matrix<T>& rhs) {\n        return (Matrix<T>(*this)\
    \ += -rhs);\n    }\n\n    Matrix<T>& operator*=(const Matrix<T>& rhs) {\n    \
    \    assert(mat[0].size() == rhs.size());\n        size_t H = mat.size(), W =\
    \ rhs[0].size(), C = rhs.size();\n        Matrix<T> res(H, W);\n        for(size_t\
    \ i=0; i<H; i++) {\n            for(size_t j=0; j<W; j++) {\n                for(size_t\
    \ k=0; k<C; k++) {\n                    res[i][j] += mat[i][k] * rhs[k][j];\n\
    \                }\n            }\n        }\n        this->mat = res.mat;\n \
    \       return *this;\n    }\n\n    Matrix<T> operator+(const Matrix<T>& rhs)\
    \ {\n        return (Matrix<T>(*this) += rhs);\n    }\n\n    Matrix<T> operator*(const\
    \ Matrix<T>& rhs) {\n        return (Matrix<T>(*this) *= rhs);\n    }\n\n    Matrix<T>\
    \ operator-(const Matrix<T> &rhs) {\n        return (Matrix<T>(*this) -= rhs);\n\
    \    }\n\n    bool operator==(const Matrix<T> &rhs) const {\n        return this->mat\
    \ == rhs.mat;\n    }\n    bool operator!=(const Matrix<T> &rhs) const {\n    \
    \    return !(*this == rhs);\n    }\n};\n\ntemplate <typename T>\nMatrix<T> eigen(size_t\
    \ N) {\n    Matrix<T> res(N, N, 0);\n    for(size_t i=0; i<N; i++) res[i][i] =\
    \ T(1);\n    return res;\n}\n\ntemplate <typename T>\nMatrix<T> pow(Matrix<T>\
    \ mat, long long int k) {\n    Matrix<T> res = eigen<T>(mat.size());\n    for(;\
    \ k>0; k>>=1) {\n        if(k & 1) res *= mat;\n        mat *= mat;\n    }\n \
    \   return res;\n}\n\ntemplate <typename T>\nostream& operator<< (ostream& out,\
    \ Matrix<T> mat) {\n    int H = mat.size(), W = mat[0].size();\n    out << \"\
    [\" << endl;\n    for(int i=0; i<H; i++) {\n        out << \"  [ \";\n       \
    \ for(int j=0; j<W; j++) out << mat[i][j] << \" \";\n        out << \"]\" << endl;\n\
    \    }\n    out << \"]\" << endl;\n    return out;\n}\n#line 1 \"math/math_022_matrix_utils_real.cpp\"\
    \n// \u5B9F\u6570\u884C\u5217\u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\u4F5C\
    \n\n// \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5 (\u5143\u306E\u884C\u5217\u3092\
    \u53C2\u7167\u3067\u5909\u5F62\u3001\u30E9\u30F3\u30AF\u3092\u8FD4\u3059)\ntemplate\
    \ <typename Real>\nint gaussianEliminationReal(Matrix<Real> &mat,\n          \
    \                  const Real EPS=1e-9, bool ext=false) {\n    int N = mat.size(),\
    \ M = mat[0].size(), rank = 0;\n\n    // \u62E1\u5927\u4FC2\u6570\u884C\u5217\u306A\
    \u3089\u6700\u5F8C\u306E\u5217\u306F\u6383\u304D\u51FA\u3057\u306E\u5BFE\u8C61\
    \u306B\u3057\u306A\u3044\n    for(int j=0; j+ext<M; j++) {\n        int piv =\
    \ -1; Real abs_max(0.0);\n        for(int i=rank; i<N; i++) {\n            Real\
    \ val(abs(mat[i][j]));\n            if(val >= EPS and abs_max < val) abs_max =\
    \ val, piv = i;\n        }\n        if(piv < 0) continue;\n        swap(mat[rank],\
    \ mat[piv]);\n        Real div(mat[rank][j]);\n        for(auto &v : mat[rank])\
    \ v /= div;\n        for(int i=0; i<N; i++) {\n            if(i == rank or abs(mat[i][j])\
    \ < EPS) continue;\n            Real scale = mat[i][j];\n            for(int k=0;\
    \ k<M; k++) {\n                mat[i][k] -= mat[rank][k] * scale;\n          \
    \  }\n        }\n        rank++;\n    }\n    return rank;\n}\n\n// \u7DDA\u5F62\
    \u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\n// empty \u306A\u3089\u89E3\u306A\u3057\u3001\
    M != rank \u306A\u3089\u7121\u9650\u306B\u5B58\u5728\u3001\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070\u4E00\u610F\ntemplate <typename Real>\nvector<Real> linearEquationReal(Matrix<Real>\
    \ A, vector<Real> b,\n                                const Real EPS = 1e-9) {\n\
    \    int N = A.size(), M = A[0].size();\n    Matrix<Real> mat(N, M+1);\n    for(int\
    \ i=0; i<N; i++) {\n        for(int j=0; j<M+1; j++) {\n            mat[i][j]\
    \ = (j < M ? A[i][j] : b[i]);\n        }\n    }\n\n    int rank = gaussianEliminationReal(mat,\
    \ EPS, true);\n    vector<Real> res(N);\n    for(int i=0; i<N; i++) {\n      \
    \  res[i] = mat[i][M];\n        if(i >= rank and abs(mat[i][M]) > EPS) return\
    \ {};\n    }\n    return res;\n}\n\ntemplate <typename Real>\nReal detReal(Matrix<Real>\
    \ A, const Real EPS=1e-9) {\n    int N = A.size(), cnt_swap = 0;\n    for(int\
    \ j=0; j<N; j++) {\n        int piv = -1; Real abs_max(0);\n        for(int i=j;\
    \ i<N; i++) {\n            Real val = abs(A[i][j]);\n            if(val >= EPS\
    \ and abs_max < val) abs_max = val, piv = i;\n        }\n        if(piv < 0) return\
    \ Real(0);\n        cnt_swap += (piv != j);\n        swap(A[piv], A[j]);\n   \
    \     for(int i=j+1; i<N; i++) {\n            Real scale(A[i][j] / A[j][j]);\n\
    \            for(int k=0; k<N; k++) {\n                A[i][k] -= A[j][k] * scale;\n\
    \            }\n        }\n    }\n\n    Real res = (cnt_swap % 2 ? Real(-1) :\
    \ Real(1));\n    for(int i=0; i<N; i++) res *= A[i][i];\n    return res;\n}\n\
    #line 10 \"math/verify/verify_math_022_matrix_utils_real.cpp\"\n\nvoid tiny_test()\
    \ {\n    int N, M; cin >> N >> M;\n    Matrix<double> mat(N, M);\n    for(int\
    \ i=0; i<N; i++) {\n        for(int j=0; j<M; j++) {\n            cin >> mat[i][j];\n\
    \        }\n    }\n\n    cout << fixed << setprecision(12) << detReal(mat) <<\
    \ endl;\n\n    vector<double> vec(N);\n    for(int i=0; i<N; i++) cin >> vec[i];\n\
    \    auto ans = linearEquationReal(mat, vec);\n    for(auto e : ans) cout << e\
    \ << \" \";\n    cout << endl;\n}\n\nvoid AOJ1328() {\n    int d;\n    using ld\
    \ = long double;\n    const ld EPS = 9e-5;\n    while(cin >> d, d) {\n       \
    \ vector<ld> v(d+3);\n        for(int i=0; i<d+3; i++) cin >> v[i];\n\n      \
    \  int row = d+3, col = d+1;\n        Matrix<ld> mat(row, col);\n        for(int\
    \ i=0; i<row; i++) {\n            ld p = 1;\n            for(int j=0; j<col; j++)\
    \ {\n                mat[i][j] = p;\n                p *= i;\n            }\n\
    \        }\n\n        for(int i=0; i<row; i++) {\n            vector<ld> tm =\
    \ mat[i];\n            ld tv = v[i];\n            for(int j=0; j<col; j++) mat[i][j]\
    \ = 0;\n            v[i] = 0;\n\n            auto res = linearEquationReal(mat,\
    \ v, EPS);\n            if(res.size()) {\n                cout << i << endl;\n\
    \                i = d + 5;\n            }\n            else {\n             \
    \   for(int j=0; j<col; j++) mat[i][j] = tm[j];\n                v[i] = tv;\n\
    \            }\n        }\n    }\n}\n\nint main() {\n    tiny_test();\n    //\
    \ AOJ1328(); // linear equation\n}\n"
  code: "#include <vector>\n#include <algorithm>\n#include <iostream>\n#include <cstdio>\n\
    #include <cmath>\n#include <iomanip>\nusing namespace std;\n#include \"../math_004_matrix.cpp\"\
    \n#include \"../math_022_matrix_utils_real.cpp\"\n\nvoid tiny_test() {\n    int\
    \ N, M; cin >> N >> M;\n    Matrix<double> mat(N, M);\n    for(int i=0; i<N; i++)\
    \ {\n        for(int j=0; j<M; j++) {\n            cin >> mat[i][j];\n       \
    \ }\n    }\n\n    cout << fixed << setprecision(12) << detReal(mat) << endl;\n\
    \n    vector<double> vec(N);\n    for(int i=0; i<N; i++) cin >> vec[i];\n    auto\
    \ ans = linearEquationReal(mat, vec);\n    for(auto e : ans) cout << e << \" \"\
    ;\n    cout << endl;\n}\n\nvoid AOJ1328() {\n    int d;\n    using ld = long double;\n\
    \    const ld EPS = 9e-5;\n    while(cin >> d, d) {\n        vector<ld> v(d+3);\n\
    \        for(int i=0; i<d+3; i++) cin >> v[i];\n\n        int row = d+3, col =\
    \ d+1;\n        Matrix<ld> mat(row, col);\n        for(int i=0; i<row; i++) {\n\
    \            ld p = 1;\n            for(int j=0; j<col; j++) {\n             \
    \   mat[i][j] = p;\n                p *= i;\n            }\n        }\n\n    \
    \    for(int i=0; i<row; i++) {\n            vector<ld> tm = mat[i];\n       \
    \     ld tv = v[i];\n            for(int j=0; j<col; j++) mat[i][j] = 0;\n   \
    \         v[i] = 0;\n\n            auto res = linearEquationReal(mat, v, EPS);\n\
    \            if(res.size()) {\n                cout << i << endl;\n          \
    \      i = d + 5;\n            }\n            else {\n                for(int\
    \ j=0; j<col; j++) mat[i][j] = tm[j];\n                v[i] = tv;\n          \
    \  }\n        }\n    }\n}\n\nint main() {\n    tiny_test();\n    // AOJ1328();\
    \ // linear equation\n}\n"
  dependsOn:
  - math/math_004_matrix.cpp
  - math/math_022_matrix_utils_real.cpp
  isVerificationFile: false
  path: math/verify/verify_math_022_matrix_utils_real.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_022_matrix_utils_real.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_022_matrix_utils_real.cpp
- /library/math/verify/verify_math_022_matrix_utils_real.cpp.html
title: math/verify/verify_math_022_matrix_utils_real.cpp
---
