---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_004_matrix.cpp
    title: math/verify/verify_math_004_matrix.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_022_matrix_utils_real.cpp
    title: math/verify/verify_math_022_matrix_utils_real.cpp
  - icon: ':warning:'
    path: math/verify/verify_math_023_matrix_utils_modp.cpp
    title: math/verify/verify_math_023_matrix_utils_modp.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_004_matrix.cpp\"\n// \u884C\u5217\u30E9\u30A4\u30D6\
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
    \ << endl;\n    return out;\n}\n"
  code: "// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n\n// size(): \u884C\u6570\u3092\
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
    \    }\n    out << \"]\" << endl;\n    return out;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_004_matrix.cpp
  requiredBy:
  - math/verify/verify_math_004_matrix.cpp
  - math/verify/verify_math_023_matrix_utils_modp.cpp
  - math/verify/verify_math_022_matrix_utils_real.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_004_matrix.cpp
layout: document
redirect_from:
- /library/math/math_004_matrix.cpp
- /library/math/math_004_matrix.cpp.html
title: math/math_004_matrix.cpp
---
