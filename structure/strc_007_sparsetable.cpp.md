---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
    title: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: ./docs/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 2 \"structure/strc_007_sparsetable.cpp\"\n\n// @brief Sparse\
    \ Table\n// @docs ./docs/sparse_table.md\n\n#include <vector>\n#include <functional>\n\
    #include <cassert>\n\ntemplate <typename Tp>\nstruct SparseTable {\n    size_t\
    \ N, LN;\n    vector<Tp> A, logs;\n    vector< vector<Tp> > node;\n    function<Tp(Tp,\
    \ Tp)> f;\n\n    SparseTable() = default;\n    SparseTable(vector<Tp> A_, function<Tp(Tp,\
    \ Tp)> f_) :\n        A(A_), f(f_) {\n        N = LN = 1;\n        while(N < A.size())\
    \ N <<= 1, LN++;\n        N = A.size();\n        logs.resize(N+1);\n        node.resize(N,\
    \ vector<int>(LN));\n        build();\n    }\n\n    void build() {\n        for(size_t\
    \ i=2; i<N; i++) {\n            logs[i] = logs[i>>1] + 1;\n        }\n       \
    \ for(size_t i=0; i<N; i++) {\n            node[i][0] = A[i];\n        }\n   \
    \     for(size_t k=0; k+1<LN; k++) {\n            for(size_t i=0; i+(1<<k)<N;\
    \ i++) {\n                Tp x = node[i][k];\n                Tp y = node[i+(1<<k)][k];\n\
    \                node[i][k+1] = f(x, y);\n            }\n        }\n    }\n\n\
    \    inline Tp query(size_t l, size_t r) {\n        assert(l < r and r <= N);\n\
    \        int d = logs[r-l];\n        Tp x = node[l][d];\n        Tp y = node[r-(1<<d)][d];\n\
    \        return f(x, y);\n    }\n};\n"
  code: "#pragma once\n\n// @brief Sparse Table\n// @docs ./docs/sparse_table.md\n\
    \n#include <vector>\n#include <functional>\n#include <cassert>\n\ntemplate <typename\
    \ Tp>\nstruct SparseTable {\n    size_t N, LN;\n    vector<Tp> A, logs;\n    vector<\
    \ vector<Tp> > node;\n    function<Tp(Tp, Tp)> f;\n\n    SparseTable() = default;\n\
    \    SparseTable(vector<Tp> A_, function<Tp(Tp, Tp)> f_) :\n        A(A_), f(f_)\
    \ {\n        N = LN = 1;\n        while(N < A.size()) N <<= 1, LN++;\n       \
    \ N = A.size();\n        logs.resize(N+1);\n        node.resize(N, vector<int>(LN));\n\
    \        build();\n    }\n\n    void build() {\n        for(size_t i=2; i<N; i++)\
    \ {\n            logs[i] = logs[i>>1] + 1;\n        }\n        for(size_t i=0;\
    \ i<N; i++) {\n            node[i][0] = A[i];\n        }\n        for(size_t k=0;\
    \ k+1<LN; k++) {\n            for(size_t i=0; i+(1<<k)<N; i++) {\n           \
    \     Tp x = node[i][k];\n                Tp y = node[i+(1<<k)][k];\n        \
    \        node[i][k+1] = f(x, y);\n            }\n        }\n    }\n\n    inline\
    \ Tp query(size_t l, size_t r) {\n        assert(l < r and r <= N);\n        int\
    \ d = logs[r-l];\n        Tp x = node[l][d];\n        Tp y = node[r-(1<<d)][d];\n\
    \        return f(x, y);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_007_sparsetable.cpp
  requiredBy: []
  timestamp: '2020-07-13 09:25:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
documentation_of: structure/strc_007_sparsetable.cpp
layout: document
redirect_from:
- /library/structure/strc_007_sparsetable.cpp
- /library/structure/strc_007_sparsetable.cpp.html
title: Sparse Table
---
