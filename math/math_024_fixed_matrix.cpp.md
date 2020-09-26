---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_024_fixed_matrix.cpp
    title: math/verify/verify_math_024_fixed_matrix.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_024_fixed_matrix.cpp\"\n// \u884C\u5217\u30E9\u30A4\
    \u30D6\u30E9\u30EA\n\n// \u6F14\u7B97\u5B50: \u8907\u5408\u4EE3\u5165 (+=, -=),\
    \ \u5358\u9805 (-), \u4E8C\u9805 (+, -, *, ==)\n// eigen(N): N*N \u5358\u4F4D\u884C\
    \u5217\u3092\u8FD4\u3059\n// pow(mat, k): mat \u306E k \u4E57\u3092\u8FD4\u3059\
    \n\ntemplate <typename T, int h, int w>\nstruct FixedMatrix {\n    using array_type\
    \ = array<T, h * w>;\n    array_type mat;\n\n    FixedMatrix(T val = T(0)) { mat.fill(val);\
    \ }\n    \n    const T& at(int i, int j) const { return mat[i*w + j]; }\n    T&\
    \ at(int i, int j) { return mat[i*w + j]; }\n\n    FixedMatrix<T, h, w> &operator+=(const\
    \ FixedMatrix<T, h, w>& rhs) {\n        for(size_t i=0; i<h; i++) {\n        \
    \    for(size_t j=0; j<w; j++) {\n                this->at(i, j) += rhs.at(i,\
    \ j);\n            }\n        }\n        return *this;\n    }\n\n    FixedMatrix<T,\
    \ h, w> operator-() const {\n        FixedMatrix<T, h, w> res(*this);\n      \
    \  for(size_t i=0; i<h; i++) {\n            for(size_t j=0; j<w; j++) {\n    \
    \            res.at(i, j) *= T(-1);\n            }\n        }\n        return\
    \ res;\n    }\n\n    FixedMatrix<T, h, w> &operator-=(const FixedMatrix<T, h,\
    \ w>& rhs) {\n        return (FixedMatrix<T, h, w>(*this) += -rhs);\n    }\n\n\
    \    template <int wr>\n    FixedMatrix<T, h, wr> operator*(const FixedMatrix<T,\
    \ w, wr>& rhs) {\n        size_t H = h, W = wr, C = w;\n        FixedMatrix<T,\
    \ h, wr> res;\n        for(size_t i=0; i<H; i++) {\n            for(size_t j=0;\
    \ j<W; j++) {\n                for(size_t k=0; k<C; k++) {\n                 \
    \   res.at(i, j) += this->at(i, k) * rhs.at(k, j);\n                }\n      \
    \      }\n        }\n        return res;\n    }\n\n    FixedMatrix<T, h, w> operator+(const\
    \ FixedMatrix<T, h, w>& rhs) {\n        return (FixedMatrix<T, h, w>(*this) +=\
    \ rhs);\n    }\n\n    FixedMatrix<T, h, w> operator-(const FixedMatrix<T, h, w>\
    \ &rhs) {\n        return (FixedMatrix<T, h, w>(*this) -= rhs);\n    }\n\n   \
    \ bool operator==(const FixedMatrix<T, h, w> &rhs) const {\n        return this->mat\
    \ == rhs.mat;\n    }\n    bool operator!=(const FixedMatrix<T, h, w> &rhs) const\
    \ {\n        return !(*this == rhs);\n    }\n};\n\ntemplate <typename T, int h,\
    \ int w>\nFixedMatrix<T, h, w> eigen() {\n    FixedMatrix<T, h, w> res(0);\n \
    \   for(size_t i=0; i<h; i++) res.at(i, i) = T(1);\n    return res;\n}\n\ntemplate\
    \ <typename T, int h, int w>\nFixedMatrix<T, h, w> pow(FixedMatrix<T, h, w> mat,\
    \ long long int k) {\n    FixedMatrix<T, h, w> res = eigen<T, h, w>();\n    for(;\
    \ k>0; k>>=1) {\n        if(k & 1) res = res * mat;\n        mat = mat * mat;\n\
    \    }\n    return res;\n}\n\ntemplate <typename T, int h, int w>\nostream& operator<<\
    \ (ostream& out, FixedMatrix<T, h, w> mat) {\n    int H = mat.h, W = mat.w;\n\
    \    out << \"[\" << endl;\n    for(int i=0; i<H; i++) {\n        out << \"  [\
    \ \";\n        for(int j=0; j<W; j++) out << mat.at(i, j) << \" \";\n        out\
    \ << \"]\" << endl;\n    }\n    out << \"]\" << endl;\n    return out;\n}\n"
  code: "// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n\n// \u6F14\u7B97\u5B50: \u8907\
    \u5408\u4EE3\u5165 (+=, -=), \u5358\u9805 (-), \u4E8C\u9805 (+, -, *, ==)\n//\
    \ eigen(N): N*N \u5358\u4F4D\u884C\u5217\u3092\u8FD4\u3059\n// pow(mat, k): mat\
    \ \u306E k \u4E57\u3092\u8FD4\u3059\n\ntemplate <typename T, int h, int w>\nstruct\
    \ FixedMatrix {\n    using array_type = array<T, h * w>;\n    array_type mat;\n\
    \n    FixedMatrix(T val = T(0)) { mat.fill(val); }\n    \n    const T& at(int\
    \ i, int j) const { return mat[i*w + j]; }\n    T& at(int i, int j) { return mat[i*w\
    \ + j]; }\n\n    FixedMatrix<T, h, w> &operator+=(const FixedMatrix<T, h, w>&\
    \ rhs) {\n        for(size_t i=0; i<h; i++) {\n            for(size_t j=0; j<w;\
    \ j++) {\n                this->at(i, j) += rhs.at(i, j);\n            }\n   \
    \     }\n        return *this;\n    }\n\n    FixedMatrix<T, h, w> operator-()\
    \ const {\n        FixedMatrix<T, h, w> res(*this);\n        for(size_t i=0; i<h;\
    \ i++) {\n            for(size_t j=0; j<w; j++) {\n                res.at(i, j)\
    \ *= T(-1);\n            }\n        }\n        return res;\n    }\n\n    FixedMatrix<T,\
    \ h, w> &operator-=(const FixedMatrix<T, h, w>& rhs) {\n        return (FixedMatrix<T,\
    \ h, w>(*this) += -rhs);\n    }\n\n    template <int wr>\n    FixedMatrix<T, h,\
    \ wr> operator*(const FixedMatrix<T, w, wr>& rhs) {\n        size_t H = h, W =\
    \ wr, C = w;\n        FixedMatrix<T, h, wr> res;\n        for(size_t i=0; i<H;\
    \ i++) {\n            for(size_t j=0; j<W; j++) {\n                for(size_t\
    \ k=0; k<C; k++) {\n                    res.at(i, j) += this->at(i, k) * rhs.at(k,\
    \ j);\n                }\n            }\n        }\n        return res;\n    }\n\
    \n    FixedMatrix<T, h, w> operator+(const FixedMatrix<T, h, w>& rhs) {\n    \
    \    return (FixedMatrix<T, h, w>(*this) += rhs);\n    }\n\n    FixedMatrix<T,\
    \ h, w> operator-(const FixedMatrix<T, h, w> &rhs) {\n        return (FixedMatrix<T,\
    \ h, w>(*this) -= rhs);\n    }\n\n    bool operator==(const FixedMatrix<T, h,\
    \ w> &rhs) const {\n        return this->mat == rhs.mat;\n    }\n    bool operator!=(const\
    \ FixedMatrix<T, h, w> &rhs) const {\n        return !(*this == rhs);\n    }\n\
    };\n\ntemplate <typename T, int h, int w>\nFixedMatrix<T, h, w> eigen() {\n  \
    \  FixedMatrix<T, h, w> res(0);\n    for(size_t i=0; i<h; i++) res.at(i, i) =\
    \ T(1);\n    return res;\n}\n\ntemplate <typename T, int h, int w>\nFixedMatrix<T,\
    \ h, w> pow(FixedMatrix<T, h, w> mat, long long int k) {\n    FixedMatrix<T, h,\
    \ w> res = eigen<T, h, w>();\n    for(; k>0; k>>=1) {\n        if(k & 1) res =\
    \ res * mat;\n        mat = mat * mat;\n    }\n    return res;\n}\n\ntemplate\
    \ <typename T, int h, int w>\nostream& operator<< (ostream& out, FixedMatrix<T,\
    \ h, w> mat) {\n    int H = mat.h, W = mat.w;\n    out << \"[\" << endl;\n   \
    \ for(int i=0; i<H; i++) {\n        out << \"  [ \";\n        for(int j=0; j<W;\
    \ j++) out << mat.at(i, j) << \" \";\n        out << \"]\" << endl;\n    }\n \
    \   out << \"]\" << endl;\n    return out;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_024_fixed_matrix.cpp
  requiredBy:
  - math/verify/verify_math_024_fixed_matrix.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_024_fixed_matrix.cpp
layout: document
redirect_from:
- /library/math/math_024_fixed_matrix.cpp
- /library/math/math_024_fixed_matrix.cpp.html
title: math/math_024_fixed_matrix.cpp
---
