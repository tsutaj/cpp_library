---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/disjoint_sparse_table.cpp
    title: Disjoint Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n#include\
    \ <vector>\n#include <cstdio>\nusing namespace std;\nusing ll = long long int;\n\
    \n#define call_from_test\n#line 2 \"structure/disjoint_sparse_table.cpp\"\n\n\
    // @brief Disjoint Sparse Table\n// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946\n\
    // @docs ./docs/disjoint_sparse_table.md\n\n#line 8 \"structure/disjoint_sparse_table.cpp\"\
    \n#include <functional>\n#include <cassert>\n\ntemplate <typename Tp>\nstruct\
    \ DisjointSparseTable {\n    int N, LN;\n    vector<Tp> A;\n    vector< vector<Tp>\
    \ > seg_l, seg_r;\n    function<Tp(Tp, Tp)> cmb_f;\n    \n    DisjointSparseTable()\
    \ = default;\n    DisjointSparseTable(vector<Tp> A_,\n                       \
    \ function<Tp(Tp, Tp)> cmb_f_)\n        : A(A_), cmb_f(cmb_f_) {\n        N =\
    \ A.size(), LN = 1;\n        while((1<<LN) < N) LN++;\n        seg_l.resize(LN,\
    \ vector<Tp>(N));\n        seg_r.resize(LN, vector<Tp>(N));\n        build(A);\n\
    \    }\n\n    void build(const vector<Tp> &A) {\n        for(int i=0; i<LN; i++)\
    \ {\n            // [j-(1<<i), j), [ j, j+(1<<i) )\n            for(int j=(1<<i);\
    \ j<=N; j+=(1<<(i+1))) {\n                if(j < N) seg_r[i][j] = A[j];\n    \
    \            for(int k=j+1; k<j+(1<<i); k++) {\n                    if(k >= N)\
    \ break;\n                    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);\n    \
    \            }\n                if(j-1 >= 0) seg_l[i][j-1] = A[j-1];\n       \
    \         for(int k=j-2; k>=j-(1<<i); k--) {\n                    if(k < 0) break;\n\
    \                    seg_l[i][k] = cmb_f(seg_l[i][k+1], A[k]);\n             \
    \   }\n            }\n        }\n    }\n\n    Tp query(int l, int r) {\n     \
    \   assert(0 <= l and l < r and r <= N); r--;\n        if(l == r) return A[l];\n\
    \        int k = 31 - __builtin_clz((unsigned int)(l ^ r));\n        return cmb_f(seg_l[k][l],\
    \ seg_r[k][r]);\n    }\n};\n#line 10 \"verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n\
    \    vector<ll> A(N);\n    for(int i=0; i<N; i++) scanf(\"%lld\", &A[i]);\n\n\
    \    DisjointSparseTable<ll> dst(A, [](ll x, ll y) { return x + y; });\n    while(Q--)\
    \ {\n        int l, r; scanf(\"%d%d\", &l, &r);\n        printf(\"%lld\\n\", dst.query(l,\
    \ r));\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n\n\
    #include <vector>\n#include <cstdio>\nusing namespace std;\nusing ll = long long\
    \ int;\n\n#define call_from_test\n#include \"../../../../structure/disjoint_sparse_table.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n\
    \    vector<ll> A(N);\n    for(int i=0; i<N; i++) scanf(\"%lld\", &A[i]);\n\n\
    \    DisjointSparseTable<ll> dst(A, [](ll x, ll y) { return x + y; });\n    while(Q--)\
    \ {\n        int l, r; scanf(\"%d%d\", &l, &r);\n        printf(\"%lld\\n\", dst.query(l,\
    \ r));\n    }\n    return 0;\n}\n"
  dependsOn:
  - structure/disjoint_sparse_table.cpp
  isVerificationFile: true
  path: verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
  requiredBy: []
  timestamp: '2020-07-15 08:59:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
- /verify/verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp.html
title: verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp
---
