---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_022_matrix_utils_real.cpp
    title: math/verify/verify_math_022_matrix_utils_real.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_022_matrix_utils_real.cpp\"\n// \u5B9F\u6570\u884C\
    \u5217\u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\u4F5C\n\n// \u30AC\u30A6\
    \u30B9\u306E\u6D88\u53BB\u6CD5 (\u5143\u306E\u884C\u5217\u3092\u53C2\u7167\u3067\
    \u5909\u5F62\u3001\u30E9\u30F3\u30AF\u3092\u8FD4\u3059)\ntemplate <typename Real>\n\
    int gaussianEliminationReal(Matrix<Real> &mat,\n                            const\
    \ Real EPS=1e-9, bool ext=false) {\n    int N = mat.size(), M = mat[0].size(),\
    \ rank = 0;\n\n    // \u62E1\u5927\u4FC2\u6570\u884C\u5217\u306A\u3089\u6700\u5F8C\
    \u306E\u5217\u306F\u6383\u304D\u51FA\u3057\u306E\u5BFE\u8C61\u306B\u3057\u306A\
    \u3044\n    for(int j=0; j+ext<M; j++) {\n        int piv = -1; Real abs_max(0.0);\n\
    \        for(int i=rank; i<N; i++) {\n            Real val(abs(mat[i][j]));\n\
    \            if(val >= EPS and abs_max < val) abs_max = val, piv = i;\n      \
    \  }\n        if(piv < 0) continue;\n        swap(mat[rank], mat[piv]);\n    \
    \    Real div(mat[rank][j]);\n        for(auto &v : mat[rank]) v /= div;\n   \
    \     for(int i=0; i<N; i++) {\n            if(i == rank or abs(mat[i][j]) < EPS)\
    \ continue;\n            Real scale = mat[i][j];\n            for(int k=0; k<M;\
    \ k++) {\n                mat[i][k] -= mat[rank][k] * scale;\n            }\n\
    \        }\n        rank++;\n    }\n    return rank;\n}\n\n// \u7DDA\u5F62\u65B9\
    \u7A0B\u5F0F\u3092\u89E3\u304F\n// empty \u306A\u3089\u89E3\u306A\u3057\u3001\
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
    \ Real(1));\n    for(int i=0; i<N; i++) res *= A[i][i];\n    return res;\n}\n"
  code: "// \u5B9F\u6570\u884C\u5217\u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\
    \u4F5C\n\n// \u30AC\u30A6\u30B9\u306E\u6D88\u53BB\u6CD5 (\u5143\u306E\u884C\u5217\
    \u3092\u53C2\u7167\u3067\u5909\u5F62\u3001\u30E9\u30F3\u30AF\u3092\u8FD4\u3059\
    )\ntemplate <typename Real>\nint gaussianEliminationReal(Matrix<Real> &mat,\n\
    \                            const Real EPS=1e-9, bool ext=false) {\n    int N\
    \ = mat.size(), M = mat[0].size(), rank = 0;\n\n    // \u62E1\u5927\u4FC2\u6570\
    \u884C\u5217\u306A\u3089\u6700\u5F8C\u306E\u5217\u306F\u6383\u304D\u51FA\u3057\
    \u306E\u5BFE\u8C61\u306B\u3057\u306A\u3044\n    for(int j=0; j+ext<M; j++) {\n\
    \        int piv = -1; Real abs_max(0.0);\n        for(int i=rank; i<N; i++) {\n\
    \            Real val(abs(mat[i][j]));\n            if(val >= EPS and abs_max\
    \ < val) abs_max = val, piv = i;\n        }\n        if(piv < 0) continue;\n \
    \       swap(mat[rank], mat[piv]);\n        Real div(mat[rank][j]);\n        for(auto\
    \ &v : mat[rank]) v /= div;\n        for(int i=0; i<N; i++) {\n            if(i\
    \ == rank or abs(mat[i][j]) < EPS) continue;\n            Real scale = mat[i][j];\n\
    \            for(int k=0; k<M; k++) {\n                mat[i][k] -= mat[rank][k]\
    \ * scale;\n            }\n        }\n        rank++;\n    }\n    return rank;\n\
    }\n\n// \u7DDA\u5F62\u65B9\u7A0B\u5F0F\u3092\u89E3\u304F\n// empty \u306A\u3089\
    \u89E3\u306A\u3057\u3001M != rank \u306A\u3089\u7121\u9650\u306B\u5B58\u5728\u3001\
    \u305D\u3046\u3067\u306A\u3051\u308C\u3070\u4E00\u610F\ntemplate <typename Real>\n\
    vector<Real> linearEquationReal(Matrix<Real> A, vector<Real> b,\n            \
    \                    const Real EPS = 1e-9) {\n    int N = A.size(), M = A[0].size();\n\
    \    Matrix<Real> mat(N, M+1);\n    for(int i=0; i<N; i++) {\n        for(int\
    \ j=0; j<M+1; j++) {\n            mat[i][j] = (j < M ? A[i][j] : b[i]);\n    \
    \    }\n    }\n\n    int rank = gaussianEliminationReal(mat, EPS, true);\n   \
    \ vector<Real> res(N);\n    for(int i=0; i<N; i++) {\n        res[i] = mat[i][M];\n\
    \        if(i >= rank and abs(mat[i][M]) > EPS) return {};\n    }\n    return\
    \ res;\n}\n\ntemplate <typename Real>\nReal detReal(Matrix<Real> A, const Real\
    \ EPS=1e-9) {\n    int N = A.size(), cnt_swap = 0;\n    for(int j=0; j<N; j++)\
    \ {\n        int piv = -1; Real abs_max(0);\n        for(int i=j; i<N; i++) {\n\
    \            Real val = abs(A[i][j]);\n            if(val >= EPS and abs_max <\
    \ val) abs_max = val, piv = i;\n        }\n        if(piv < 0) return Real(0);\n\
    \        cnt_swap += (piv != j);\n        swap(A[piv], A[j]);\n        for(int\
    \ i=j+1; i<N; i++) {\n            Real scale(A[i][j] / A[j][j]);\n           \
    \ for(int k=0; k<N; k++) {\n                A[i][k] -= A[j][k] * scale;\n    \
    \        }\n        }\n    }\n\n    Real res = (cnt_swap % 2 ? Real(-1) : Real(1));\n\
    \    for(int i=0; i<N; i++) res *= A[i][i];\n    return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_022_matrix_utils_real.cpp
  requiredBy:
  - math/verify/verify_math_022_matrix_utils_real.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_022_matrix_utils_real.cpp
layout: document
redirect_from:
- /library/math/math_022_matrix_utils_real.cpp
- /library/math/math_022_matrix_utils_real.cpp.html
title: math/math_022_matrix_utils_real.cpp
---
