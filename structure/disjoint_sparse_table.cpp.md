---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/DSL_3_D/disjoint_sparse_table.test.cpp
    title: verifying_test/AOJ/DSL_3_D/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
    title: verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/data_structure/static_rmq/disjoint_sparse_table.test.cpp
    title: verifying_test/yosupo/data_structure/static_rmq/disjoint_sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/structure/disjoint_sparse_table.md
    document_title: Disjoint Sparse Table
    links:
    - https://noshi91.hatenablog.com/entry/2018/05/08/183946
  bundledCode: "#line 2 \"structure/disjoint_sparse_table.cpp\"\n\n// @brief Disjoint\
    \ Sparse Table\n// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946\n\
    // @docs docs/structure/disjoint_sparse_table.md\n\n#include <vector>\n#include\
    \ <functional>\n#include <cassert>\n\ntemplate <typename Tp>\nstruct DisjointSparseTable\
    \ {\n    int N, LN;\n    vector<Tp> A;\n    vector< vector<Tp> > seg_l, seg_r;\n\
    \    function<Tp(Tp, Tp)> cmb_f;\n    \n    DisjointSparseTable() = default;\n\
    \    DisjointSparseTable(vector<Tp> A_,\n                        function<Tp(Tp,\
    \ Tp)> cmb_f_)\n        : A(A_), cmb_f(cmb_f_) {\n        N = A.size(), LN = 1;\n\
    \        while((1<<LN) < N) LN++;\n        seg_l.resize(LN, vector<Tp>(N));\n\
    \        seg_r.resize(LN, vector<Tp>(N));\n        build(A);\n    }\n\n    void\
    \ build(const vector<Tp> &A) {\n        for(int i=0; i<LN; i++) {\n          \
    \  // [j-(1<<i), j), [ j, j+(1<<i) )\n            for(int j=(1<<i); j<=N; j+=(1<<(i+1)))\
    \ {\n                if(j < N) seg_r[i][j] = A[j];\n                for(int k=j+1;\
    \ k<j+(1<<i); k++) {\n                    if(k >= N) break;\n                \
    \    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);\n                }\n          \
    \      if(j-1 >= 0) seg_l[i][j-1] = A[j-1];\n                for(int k=j-2; k>=j-(1<<i);\
    \ k--) {\n                    if(k < 0) break;\n                    seg_l[i][k]\
    \ = cmb_f(seg_l[i][k+1], A[k]);\n                }\n            }\n        }\n\
    \    }\n\n    Tp query(int l, int r) {\n        assert(0 <= l and l < r and r\
    \ <= N); r--;\n        if(l == r) return A[l];\n        int k = 31 - __builtin_clz((unsigned\
    \ int)(l ^ r));\n        return cmb_f(seg_l[k][l], seg_r[k][r]);\n    }\n};\n"
  code: "#pragma once\n\n// @brief Disjoint Sparse Table\n// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946\n\
    // @docs docs/structure/disjoint_sparse_table.md\n\n#include <vector>\n#include\
    \ <functional>\n#include <cassert>\n\ntemplate <typename Tp>\nstruct DisjointSparseTable\
    \ {\n    int N, LN;\n    vector<Tp> A;\n    vector< vector<Tp> > seg_l, seg_r;\n\
    \    function<Tp(Tp, Tp)> cmb_f;\n    \n    DisjointSparseTable() = default;\n\
    \    DisjointSparseTable(vector<Tp> A_,\n                        function<Tp(Tp,\
    \ Tp)> cmb_f_)\n        : A(A_), cmb_f(cmb_f_) {\n        N = A.size(), LN = 1;\n\
    \        while((1<<LN) < N) LN++;\n        seg_l.resize(LN, vector<Tp>(N));\n\
    \        seg_r.resize(LN, vector<Tp>(N));\n        build(A);\n    }\n\n    void\
    \ build(const vector<Tp> &A) {\n        for(int i=0; i<LN; i++) {\n          \
    \  // [j-(1<<i), j), [ j, j+(1<<i) )\n            for(int j=(1<<i); j<=N; j+=(1<<(i+1)))\
    \ {\n                if(j < N) seg_r[i][j] = A[j];\n                for(int k=j+1;\
    \ k<j+(1<<i); k++) {\n                    if(k >= N) break;\n                \
    \    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);\n                }\n          \
    \      if(j-1 >= 0) seg_l[i][j-1] = A[j-1];\n                for(int k=j-2; k>=j-(1<<i);\
    \ k--) {\n                    if(k < 0) break;\n                    seg_l[i][k]\
    \ = cmb_f(seg_l[i][k+1], A[k]);\n                }\n            }\n        }\n\
    \    }\n\n    Tp query(int l, int r) {\n        assert(0 <= l and l < r and r\
    \ <= N); r--;\n        if(l == r) return A[l];\n        int k = 31 - __builtin_clz((unsigned\
    \ int)(l ^ r));\n        return cmb_f(seg_l[k][l], seg_r[k][r]);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/disjoint_sparse_table.cpp
  requiredBy: []
  timestamp: '2022-01-28 02:17:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
  - verifying_test/yosupo/data_structure/static_rmq/disjoint_sparse_table.test.cpp
  - verifying_test/AOJ/DSL_3_D/disjoint_sparse_table.test.cpp
documentation_of: structure/disjoint_sparse_table.cpp
layout: document
redirect_from:
- /library/structure/disjoint_sparse_table.cpp
- /library/structure/disjoint_sparse_table.cpp.html
title: Disjoint Sparse Table
---
- 構築: $O(N \log N)$
- クエリ: $O(1)$
  - 普通の Sparse Table とは違い、結合則を満たすものなら乗るため、和や xor, gcd などでも OK
