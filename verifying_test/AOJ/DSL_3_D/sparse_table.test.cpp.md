---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/strc_007_sparsetable.cpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n#include <cstdio>\n#include <algorithm>\nusing namespace std;\n\n#define call_from_test\n\
    #line 2 \"structure/strc_007_sparsetable.cpp\"\n\n// @brief Sparse Table\n// @docs\
    \ ./docs/sparse_table.md\n\n#include <vector>\n#include <functional>\n#include\
    \ <cassert>\n\ntemplate <typename Tp>\nstruct SparseTable {\n    size_t N, LN;\n\
    \    vector<Tp> A, logs;\n    vector< vector<Tp> > node;\n    function<Tp(Tp,\
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
    \        return f(x, y);\n    }\n};\n#line 8 \"verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, L; scanf(\"%d%d\", &N, &L);\n\
    \    vector<int> A(N);\n    for(int i=0; i<N; i++) scanf(\"%d\", &A[i]);\n\n \
    \   SparseTable<int> sp(A, [](int x, int y) { return min(x, y); });\n    for(int\
    \ i=0; i<N-L+1; i++) {\n        printf(\"%d%c\", sp.query(i, i+L), \" \\n\"[i\
    \ == N-L]);\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n#include <cstdio>\n#include <algorithm>\nusing namespace std;\n\n#define call_from_test\n\
    #include \"../../../structure/strc_007_sparsetable.cpp\"\n#undef call_from_test\n\
    \nint main() {\n    int N, L; scanf(\"%d%d\", &N, &L);\n    vector<int> A(N);\n\
    \    for(int i=0; i<N; i++) scanf(\"%d\", &A[i]);\n\n    SparseTable<int> sp(A,\
    \ [](int x, int y) { return min(x, y); });\n    for(int i=0; i<N-L+1; i++) {\n\
    \        printf(\"%d%c\", sp.query(i, i+L), \" \\n\"[i == N-L]);\n    }\n    return\
    \ 0;\n}\n"
  dependsOn:
  - structure/strc_007_sparsetable.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
  requiredBy: []
  timestamp: '2020-07-13 09:25:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
- /verify/verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp.html
title: verifying_test/AOJ/DSL_3_D/sparse_table.test.cpp
---
