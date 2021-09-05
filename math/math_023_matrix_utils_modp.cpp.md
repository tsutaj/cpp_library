---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_023_matrix_utils_modp.cpp
    title: math/verify/verify_math_023_matrix_utils_modp.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_023_matrix_utils_modp.cpp\"\n// mod p \u884C\u5217\
    \u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\u4F5C\n// \u5B9F\u6570\u3058\u3083\
    \u306A\u3044\u306E\u3067\u7D76\u5BFE\u5024\u6700\u5927\u306E\u3082\u306E\u3092\
    \ pivot \u306B\u3059\u308B\u3068\u304B\u304C\u3044\u3089\u306A\u3044\n\n// \u30AC\
    \u30A6\u30B9\u306E\u6D88\u53BB\u6CD5\ntemplate <typename mint>\nint gaussianEliminationModp(Matrix<mint>\
    \ &mat, bool ext=false) {\n    int N = mat.size(), M = mat[0].size(), rank = 0;\n\
    \    for(int j=0; j+ext<M; j++) {\n        int piv = -1;\n        for(int i=rank;\
    \ i<N; i++) {\n            if(mat[i][j] != mint(0)) piv = i, i = N;\n        }\n\
    \        if(piv < 0) continue;\n        swap(mat[rank], mat[piv]);\n        mint\
    \ div(mat[rank][j]);\n        for(auto &v : mat[rank]) v /= div;\n        for(int\
    \ i=0; i<N; i++) {\n            if(i == rank or mat[i][j] == mint(0)) continue;\n\
    \            mint scale = mat[i][j];\n            for(int k=0; k<M; k++) {\n \
    \               mat[i][k] -= mat[rank][k] * scale;\n            }\n        }\n\
    \        rank++;\n    }\n    return rank;\n}\n\ntemplate <typename mint>\nvector<mint>\
    \ linearEquationModp(Matrix<mint> A, vector<mint> b) {\n    int N = A.size(),\
    \ M = A[0].size();\n    Matrix<mint> mat(N, M+1);\n    for(int i=0; i<N; i++)\
    \ {\n        for(int j=0; j<M+1; j++) {\n            mat[i][j] = (j < M ? A[i][j]\
    \ : b[i]);\n        }\n    }\n\n    int rank = gaussianEliminationModp(mat, true);\n\
    \    vector<mint> res(N);\n    for(int i=0; i<N; i++) {\n        res[i] = mat[i][M];\n\
    \        if(i >= rank and mat[i][M] != mint(0)) return {};\n    }\n    return\
    \ res;\n}\n\ntemplate <typename mint>\nmint detModp(Matrix<mint> A) {\n    int\
    \ N = A.size(), cnt_swap = 0;\n    for(int j=0; j<N; j++) {\n        int piv =\
    \ -1;\n        for(int i=j; i<N; i++) {\n            if(A[i][j] != mint(0)) piv\
    \ = i, i = N;\n        }\n        if(piv < 0) return mint(0);\n        cnt_swap\
    \ += (piv != j);\n        swap(A[piv], A[j]);\n        for(int i=j+1; i<N; i++)\
    \ {\n            mint scale(A[i][j] / A[j][j]);\n            for(int k=0; k<N;\
    \ k++) {\n                A[i][k] -= A[j][k] * scale;\n            }\n       \
    \ }\n    }\n\n    mint res = (cnt_swap % 2 ? mint(-1) : mint(1));\n    for(int\
    \ i=0; i<N; i++) res *= A[i][i];\n    return res;\n}\n"
  code: "// mod p \u884C\u5217\u306B\u5BFE\u3059\u308B\u4E3B\u8981\u306A\u64CD\u4F5C\
    \n// \u5B9F\u6570\u3058\u3083\u306A\u3044\u306E\u3067\u7D76\u5BFE\u5024\u6700\u5927\
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
    \ return res;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_023_matrix_utils_modp.cpp
  requiredBy:
  - math/verify/verify_math_023_matrix_utils_modp.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_023_matrix_utils_modp.cpp
layout: document
redirect_from:
- /library/math/math_023_matrix_utils_modp.cpp
- /library/math/math_023_matrix_utils_modp.cpp.html
title: math/math_023_matrix_utils_modp.cpp
---
