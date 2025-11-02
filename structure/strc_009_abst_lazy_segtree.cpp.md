---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_024_fixed_matrix.cpp
    title: math/verify/verify_math_024_fixed_matrix.cpp
  - icon: ':warning:'
    path: structure/verify/verify_strc_009_abst_lazy_segtree.cpp
    title: structure/verify/verify_strc_009_abst_lazy_segtree.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/GRL_5_D/hld.test.cpp
    title: verifying_test/AOJ/GRL_5_D/hld.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      \ (Lazy Segment Tree)"
    links: []
  bundledCode: "#line 1 \"structure/strc_009_abst_lazy_segtree.cpp\"\n// @category\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u9045\u5EF6\u4F1D\
    \u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)\ntemplate <typename\
    \ MonoidType, typename OperatorType>\nstruct LazySegmentTree {\n    using MMtoM\
    \ = function< MonoidType(MonoidType, MonoidType) >;\n    using OOtoO = function<\
    \ OperatorType(OperatorType, OperatorType) >;\n    using MOtoM = function< MonoidType(MonoidType,\
    \ OperatorType) >;\n    using OItoO = function< OperatorType(OperatorType, int)\
    \ >;\n\n    // node, lazy, update flag (for lazy), identity element\n    int n;\n\
    \    vector<MonoidType> node;\n    vector<OperatorType> lazy;\n    vector<bool>\
    \ need_update;\n    MonoidType E0;\n    OperatorType E1;\n\n    // update / combine\
    \ / lazy / accumulate function\n    MOtoM upd_f;\n    MMtoM cmb_f;\n    OOtoO\
    \ lzy_f;\n    OItoO acc_f;\n\n    void build(int m, vector<MonoidType> v = vector<MonoidType>())\
    \ {\n        if(v != vector<MonoidType>()) m = v.size();\n        n = 1; while(n\
    \ < m) n *= 2;\n\n        node = vector<MonoidType>(2*n-1, E0);\n        lazy\
    \ = vector<OperatorType>(2*n-1, E1);\n        need_update = vector<bool>(2*n-1,\
    \ false);\n        if(v != vector<MonoidType>()) {\n            for(int i=0; i<m;\
    \ i++) {\n                node[n-1+i] = v[i];\n            }\n            for(int\
    \ i=n-2; i>=0; i--) {\n                node[i] = cmb_f(node[2*i+1], node[2*i+2]);\n\
    \            }\n        }\n    }\n\n    // initialize\n    LazySegmentTree() {}\n\
    \    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,\n             \
    \       MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,\n            \
    \        vector<MonoidType> v = vector<MonoidType>()) :\n        E0(E0_), E1(E1_),\n\
    \        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {\n      \
    \  build(n_, v);\n    }\n\n    void eval(int k, int l, int r) {\n        if(!need_update[k])\
    \ return;\n        node[k] = upd_f(node[k], acc_f(lazy[k], r - l));\n        if(r\
    \ - l > 1) {\n            lazy[2*k+1] = lzy_f(lazy[2*k+1], lazy[k]);\n       \
    \     lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);\n            need_update[2*k+1]\
    \ = need_update[2*k+2] = true;\n        }\n        lazy[k] = E1;\n        need_update[k]\
    \ = false;\n    }\n\n    void update(int a, int b, OperatorType x, int l, int\
    \ r, int k) {\n        eval(k, l, r);\n        if(b <= l or  r <= a) return;\n\
    \        if(a <= l and r <= b) {\n            lazy[k] = lzy_f(lazy[k], x);\n \
    \           need_update[k] = true;\n            eval(k, l, r);\n        }\n  \
    \      else {\n            int mid = (l + r) / 2;\n            update(a, b, x,\
    \ l, mid, 2*k+1);\n            update(a, b, x, mid, r, 2*k+2);\n            node[k]\
    \ = cmb_f(node[2*k+1], node[2*k+2]);\n        }\n    }\n\n    MonoidType query(int\
    \ a, int b, int l, int r, int k) {\n        if(b <= l or  r <= a) return E0;\n\
    \        eval(k, l, r);\n        if(a <= l and r <= b) return node[k];\n     \
    \   int mid = (l + r) / 2;\n        MonoidType vl = query(a, b, l, mid, 2*k+1);\n\
    \        MonoidType vr = query(a, b, mid, r, 2*k+2);\n        return cmb_f(vl,\
    \ vr);\n    }\n\n    // update [a, b)-th element (applied value, x)\n    void\
    \ update(int a, int b, OperatorType x) {\n        update(a, b, x, 0, n, 0);\n\
    \    }\n\n    // range query for [a, b)\n    MonoidType query(int a, int b) {\n\
    \        return query(a, b, 0, n, 0);\n    }\n\n    void dump() {\n        fprintf(stderr,\
    \ \"[lazy]\\n\");\n        for(int i=0; i<2*n-1; i++) {\n            if(i == n-1)\
    \ fprintf(stderr, \"xxx \");\n            if(lazy[i] == E1) fprintf(stderr, \"\
    \  E \");\n            else fprintf(stderr, \"%3d \", lazy[i]);\n        }\n \
    \       fprintf(stderr, \"\\n\");\n\n        fprintf(stderr, \"[node]\\n\");\n\
    \        for(int i=0; i<2*n-1; i++) {\n            if(i == n-1) fprintf(stderr,\
    \ \"xxx \");\n            if(node[i] == E0) fprintf(stderr, \"  E \");\n     \
    \       else fprintf(stderr, \"%3d \", node[i]);\n        }\n        fprintf(stderr,\
    \ \"\\n\");\n    }\n};\n"
  code: "// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)\n\
    template <typename MonoidType, typename OperatorType>\nstruct LazySegmentTree\
    \ {\n    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;\n    using\
    \ OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n    using MOtoM\
    \ = function< MonoidType(MonoidType, OperatorType) >;\n    using OItoO = function<\
    \ OperatorType(OperatorType, int) >;\n\n    // node, lazy, update flag (for lazy),\
    \ identity element\n    int n;\n    vector<MonoidType> node;\n    vector<OperatorType>\
    \ lazy;\n    vector<bool> need_update;\n    MonoidType E0;\n    OperatorType E1;\n\
    \n    // update / combine / lazy / accumulate function\n    MOtoM upd_f;\n   \
    \ MMtoM cmb_f;\n    OOtoO lzy_f;\n    OItoO acc_f;\n\n    void build(int m, vector<MonoidType>\
    \ v = vector<MonoidType>()) {\n        if(v != vector<MonoidType>()) m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n\n        node = vector<MonoidType>(2*n-1,\
    \ E0);\n        lazy = vector<OperatorType>(2*n-1, E1);\n        need_update =\
    \ vector<bool>(2*n-1, false);\n        if(v != vector<MonoidType>()) {\n     \
    \       for(int i=0; i<m; i++) {\n                node[n-1+i] = v[i];\n      \
    \      }\n            for(int i=n-2; i>=0; i--) {\n                node[i] = cmb_f(node[2*i+1],\
    \ node[2*i+2]);\n            }\n        }\n    }\n\n    // initialize\n    LazySegmentTree()\
    \ {}\n    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,\n        \
    \            MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_,\n       \
    \             vector<MonoidType> v = vector<MonoidType>()) :\n        E0(E0_),\
    \ E1(E1_),\n        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_)\
    \ {\n        build(n_, v);\n    }\n\n    void eval(int k, int l, int r) {\n  \
    \      if(!need_update[k]) return;\n        node[k] = upd_f(node[k], acc_f(lazy[k],\
    \ r - l));\n        if(r - l > 1) {\n            lazy[2*k+1] = lzy_f(lazy[2*k+1],\
    \ lazy[k]);\n            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);\n        \
    \    need_update[2*k+1] = need_update[2*k+2] = true;\n        }\n        lazy[k]\
    \ = E1;\n        need_update[k] = false;\n    }\n\n    void update(int a, int\
    \ b, OperatorType x, int l, int r, int k) {\n        eval(k, l, r);\n        if(b\
    \ <= l or  r <= a) return;\n        if(a <= l and r <= b) {\n            lazy[k]\
    \ = lzy_f(lazy[k], x);\n            need_update[k] = true;\n            eval(k,\
    \ l, r);\n        }\n        else {\n            int mid = (l + r) / 2;\n    \
    \        update(a, b, x, l, mid, 2*k+1);\n            update(a, b, x, mid, r,\
    \ 2*k+2);\n            node[k] = cmb_f(node[2*k+1], node[2*k+2]);\n        }\n\
    \    }\n\n    MonoidType query(int a, int b, int l, int r, int k) {\n        if(b\
    \ <= l or  r <= a) return E0;\n        eval(k, l, r);\n        if(a <= l and r\
    \ <= b) return node[k];\n        int mid = (l + r) / 2;\n        MonoidType vl\
    \ = query(a, b, l, mid, 2*k+1);\n        MonoidType vr = query(a, b, mid, r, 2*k+2);\n\
    \        return cmb_f(vl, vr);\n    }\n\n    // update [a, b)-th element (applied\
    \ value, x)\n    void update(int a, int b, OperatorType x) {\n        update(a,\
    \ b, x, 0, n, 0);\n    }\n\n    // range query for [a, b)\n    MonoidType query(int\
    \ a, int b) {\n        return query(a, b, 0, n, 0);\n    }\n\n    void dump()\
    \ {\n        fprintf(stderr, \"[lazy]\\n\");\n        for(int i=0; i<2*n-1; i++)\
    \ {\n            if(i == n-1) fprintf(stderr, \"xxx \");\n            if(lazy[i]\
    \ == E1) fprintf(stderr, \"  E \");\n            else fprintf(stderr, \"%3d \"\
    , lazy[i]);\n        }\n        fprintf(stderr, \"\\n\");\n\n        fprintf(stderr,\
    \ \"[node]\\n\");\n        for(int i=0; i<2*n-1; i++) {\n            if(i == n-1)\
    \ fprintf(stderr, \"xxx \");\n            if(node[i] == E0) fprintf(stderr, \"\
    \  E \");\n            else fprintf(stderr, \"%3d \", node[i]);\n        }\n \
    \       fprintf(stderr, \"\\n\");\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_009_abst_lazy_segtree.cpp
  requiredBy:
  - structure/verify/verify_strc_009_abst_lazy_segtree.cpp
  - math/verify/verify_math_024_fixed_matrix.cpp
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/GRL_5_D/hld.test.cpp
documentation_of: structure/strc_009_abst_lazy_segtree.cpp
layout: document
redirect_from:
- /library/structure/strc_009_abst_lazy_segtree.cpp
- /library/structure/strc_009_abst_lazy_segtree.cpp.html
title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment\
  \ Tree)"
---
