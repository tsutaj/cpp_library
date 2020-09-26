---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/0560/cumulative_sum_2d.test.cpp
    title: verifying_test/AOJ/0560/cumulative_sum_2d.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: ./docs/cumulative_sum_2d.md
    document_title: "2 \u6B21\u5143\u7D2F\u7A4D\u548C (2 Dimension Cumulative Sum)"
    links: []
  bundledCode: "#line 2 \"algorithm/cumulative_sum_2d.cpp\"\n\n/**\n * @brief 2 \u6B21\
    \u5143\u7D2F\u7A4D\u548C (2 Dimension Cumulative Sum)\n * @docs ./docs/cumulative_sum_2d.md\n\
    \ */\n\n#include <functional>\n#include <vector>\n#include <cassert>\ntemplate\
    \ <typename MonoidType>\nstruct CumulativeSum2D {\n    // \u6301\u3064\u77E9\u5F62\
    \u9818\u57DF\u306E\u30B5\u30A4\u30BA\n    // \u7E26\u6A2A\u3068\u3082\u3001acc\
    \ \u306F\u3053\u308C\u3088\u308A 2 \u5927\u304D\u304F\u3057\u3066\u304A\u304F\n\
    \    int n, m;\n    MonoidType E;\n    vector< vector<MonoidType> > acc;\n   \
    \ using MMtoM = function< MonoidType(MonoidType, MonoidType) >;\n    MMtoM op,\
    \ rop;\n\n    void accumulate() {\n        for(int i=0; i<=n; i++) {\n       \
    \     for(int j=0; j<m; j++) {\n                acc[i][j+1] = op(acc[i][j+1],\
    \ acc[i][j]);\n            }\n        }\n        for(int j=0; j<=m; j++) {\n \
    \           for(int i=0; i<n; i++) {\n                acc[i+1][j] = op(acc[i+1][j],\
    \ acc[i][j]);\n            }\n        }\n    }\n\n    CumulativeSum2D() {}\n \
    \   CumulativeSum2D(int n_, int m_, int E_, MMtoM op_, MMtoM rop_) :\n       \
    \ n(n_), m(m_), E(E_), acc(n_+2, vector<MonoidType>(m_+2, E_)),\n        op(op_),\
    \ rop(rop_) {}\n    CumulativeSum2D(vector< vector<MonoidType> > mat, int E_,\n\
    \                    MMtoM op_, MMtoM rop_,\n                    bool need_accumulate\
    \ = true) :\n        E(E_), op(op_), rop(rop_) {\n        assert(mat.size() >\
    \ 0);\n        n = mat.size(), m = mat[0].size();\n        acc = vector< vector<MonoidType>\
    \ >(n+2, vector<MonoidType>(m+2, E_));\n        for(int i=0; i<n; i++) {\n   \
    \         for(int j=0; j<m; j++) {\n                acc[i+1][j+1] = mat[i][j];\n\
    \            }\n        }\n        if(need_accumulate) accumulate();\n    }\n\n\
    \    // [lx, rx), [ly, ry) \u306E\u77E9\u5F62\u9818\u57DF\u306B val \u3092\u9069\
    \u7528\n    void range_apply(int lx, int ly, int rx, int ry, MonoidType val) {\n\
    \        if(lx < 0 or ly < 0 or rx > n or ry > m) return;\n        lx++, ly++;\
    \ rx++; ry++;\n        acc[lx][ly] = op(acc[lx][ly], val);\n        acc[rx][ry]\
    \ = op(acc[rx][ry], val);\n        acc[lx][ry] = rop(acc[lx][ry], val);\n    \
    \    acc[rx][ly] = rop(acc[rx][ly], val);\n    }\n\n    // [lx, rx), [ly, ry)\
    \ \u306E\u77E9\u5F62\u9818\u57DF\u306E\u5024\n    MonoidType range_val(int lx,\
    \ int ly, int rx, int ry) {\n        if(lx < 0 or ly < 0 or rx > n or ry > m)\
    \ return E;\n        MonoidType res = E;\n        res = op(res, acc[lx][ly]);\n\
    \        res = op(res, acc[rx][ry]);\n        res = rop(res, acc[lx][ry]);\n \
    \       res = rop(res, acc[rx][ly]);\n        return res;\n    }\n};\n"
  code: "# pragma once\n\n/**\n * @brief 2 \u6B21\u5143\u7D2F\u7A4D\u548C (2 Dimension\
    \ Cumulative Sum)\n * @docs ./docs/cumulative_sum_2d.md\n */\n\n#include <functional>\n\
    #include <vector>\n#include <cassert>\ntemplate <typename MonoidType>\nstruct\
    \ CumulativeSum2D {\n    // \u6301\u3064\u77E9\u5F62\u9818\u57DF\u306E\u30B5\u30A4\
    \u30BA\n    // \u7E26\u6A2A\u3068\u3082\u3001acc \u306F\u3053\u308C\u3088\u308A\
    \ 2 \u5927\u304D\u304F\u3057\u3066\u304A\u304F\n    int n, m;\n    MonoidType\
    \ E;\n    vector< vector<MonoidType> > acc;\n    using MMtoM = function< MonoidType(MonoidType,\
    \ MonoidType) >;\n    MMtoM op, rop;\n\n    void accumulate() {\n        for(int\
    \ i=0; i<=n; i++) {\n            for(int j=0; j<m; j++) {\n                acc[i][j+1]\
    \ = op(acc[i][j+1], acc[i][j]);\n            }\n        }\n        for(int j=0;\
    \ j<=m; j++) {\n            for(int i=0; i<n; i++) {\n                acc[i+1][j]\
    \ = op(acc[i+1][j], acc[i][j]);\n            }\n        }\n    }\n\n    CumulativeSum2D()\
    \ {}\n    CumulativeSum2D(int n_, int m_, int E_, MMtoM op_, MMtoM rop_) :\n \
    \       n(n_), m(m_), E(E_), acc(n_+2, vector<MonoidType>(m_+2, E_)),\n      \
    \  op(op_), rop(rop_) {}\n    CumulativeSum2D(vector< vector<MonoidType> > mat,\
    \ int E_,\n                    MMtoM op_, MMtoM rop_,\n                    bool\
    \ need_accumulate = true) :\n        E(E_), op(op_), rop(rop_) {\n        assert(mat.size()\
    \ > 0);\n        n = mat.size(), m = mat[0].size();\n        acc = vector< vector<MonoidType>\
    \ >(n+2, vector<MonoidType>(m+2, E_));\n        for(int i=0; i<n; i++) {\n   \
    \         for(int j=0; j<m; j++) {\n                acc[i+1][j+1] = mat[i][j];\n\
    \            }\n        }\n        if(need_accumulate) accumulate();\n    }\n\n\
    \    // [lx, rx), [ly, ry) \u306E\u77E9\u5F62\u9818\u57DF\u306B val \u3092\u9069\
    \u7528\n    void range_apply(int lx, int ly, int rx, int ry, MonoidType val) {\n\
    \        if(lx < 0 or ly < 0 or rx > n or ry > m) return;\n        lx++, ly++;\
    \ rx++; ry++;\n        acc[lx][ly] = op(acc[lx][ly], val);\n        acc[rx][ry]\
    \ = op(acc[rx][ry], val);\n        acc[lx][ry] = rop(acc[lx][ry], val);\n    \
    \    acc[rx][ly] = rop(acc[rx][ly], val);\n    }\n\n    // [lx, rx), [ly, ry)\
    \ \u306E\u77E9\u5F62\u9818\u57DF\u306E\u5024\n    MonoidType range_val(int lx,\
    \ int ly, int rx, int ry) {\n        if(lx < 0 or ly < 0 or rx > n or ry > m)\
    \ return E;\n        MonoidType res = E;\n        res = op(res, acc[lx][ly]);\n\
    \        res = op(res, acc[rx][ry]);\n        res = rop(res, acc[lx][ry]);\n \
    \       res = rop(res, acc[rx][ly]);\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/cumulative_sum_2d.cpp
  requiredBy: []
  timestamp: '2020-04-07 01:41:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/0560/cumulative_sum_2d.test.cpp
documentation_of: algorithm/cumulative_sum_2d.cpp
layout: document
redirect_from:
- /library/algorithm/cumulative_sum_2d.cpp
- /library/algorithm/cumulative_sum_2d.cpp.html
title: "2 \u6B21\u5143\u7D2F\u7A4D\u548C (2 Dimension Cumulative Sum)"
---
