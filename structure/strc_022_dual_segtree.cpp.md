---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_022_dual_segtree.cpp
    title: structure/verify/verify_strc_022_dual_segtree.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment\
      \ Tree)"
    links:
    - https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/
  bundledCode: "#line 1 \"structure/strc_022_dual_segtree.cpp\"\n// @category \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u53CC\u5BFE\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)\n// \u53CC\u5BFE\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728 (Dual Segment Tree)\n// ref: https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/\n\
    template <typename MonoidType, typename OperatorType>\nstruct DualSegmentTree\
    \ {\n    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;\n   \
    \ using OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n\n    int\
    \ n;\n    vector<MonoidType> bottom;\n    vector<OperatorType> lazy;\n    OperatorType\
    \ E;\n\n    // update / lazy function\n    MOtoM upd_f;\n    OOtoO lzy_f;\n\n\
    \    inline void build(const vector<MonoidType> &v) {\n        int m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n        bottom = v; bottom.resize(n);\n\
    \        lazy.resize(n - 1, E);\n    }\n\n    DualSegmentTree() {}\n    DualSegmentTree(OperatorType\
    \ E_,\n                    MOtoM upd_f_, OOtoO lzy_f_,\n                    vector<MonoidType>\
    \ v = vector<MonoidType>()) :\n        E(E_), upd_f(upd_f_), lzy_f(lzy_f_) {\n\
    \        build(v);\n    }\n\n    void update(int a, int b, OperatorType x, int\
    \ l, int r, size_t k) {\n        if(b <= l or r <= a) return;\n        if(a <=\
    \ l and r <= b) {\n            if(k < lazy.size())\n                lazy[k] =\
    \ lzy_f(lazy[k], x);\n            else\n                bottom[k-n+1] = upd_f(bottom[k-n+1],\
    \ x);\n        }\n        else {\n            int mid = (l + r) >> 1;\n      \
    \      update(0, n, lazy[k], l, mid, 2*k+1);\n            update(0, n, lazy[k],\
    \ mid, r, 2*k+2);\n            lazy[k] = E;\n            update(a, b, x, l, mid,\
    \ 2*k+1);\n            update(a, b, x, mid, r, 2*k+2);\n        }\n    }\n\n \
    \   void update(int a, int b, OperatorType x) {\n        update(a, b, x, 0, n,\
    \ 0);\n    }\n\n    MonoidType query(int k) {\n        MonoidType res = bottom[k];\n\
    \        for(k = (k+n)>>1; k>0; k>>=1) { // 1-indexed\n            res = upd_f(res,\
    \ lazy[k-1]);\n        }\n        return res;\n    }\n};\n"
  code: "// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)\n// \u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)\n// ref: https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/\n\
    template <typename MonoidType, typename OperatorType>\nstruct DualSegmentTree\
    \ {\n    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;\n   \
    \ using OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n\n    int\
    \ n;\n    vector<MonoidType> bottom;\n    vector<OperatorType> lazy;\n    OperatorType\
    \ E;\n\n    // update / lazy function\n    MOtoM upd_f;\n    OOtoO lzy_f;\n\n\
    \    inline void build(const vector<MonoidType> &v) {\n        int m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n        bottom = v; bottom.resize(n);\n\
    \        lazy.resize(n - 1, E);\n    }\n\n    DualSegmentTree() {}\n    DualSegmentTree(OperatorType\
    \ E_,\n                    MOtoM upd_f_, OOtoO lzy_f_,\n                    vector<MonoidType>\
    \ v = vector<MonoidType>()) :\n        E(E_), upd_f(upd_f_), lzy_f(lzy_f_) {\n\
    \        build(v);\n    }\n\n    void update(int a, int b, OperatorType x, int\
    \ l, int r, size_t k) {\n        if(b <= l or r <= a) return;\n        if(a <=\
    \ l and r <= b) {\n            if(k < lazy.size())\n                lazy[k] =\
    \ lzy_f(lazy[k], x);\n            else\n                bottom[k-n+1] = upd_f(bottom[k-n+1],\
    \ x);\n        }\n        else {\n            int mid = (l + r) >> 1;\n      \
    \      update(0, n, lazy[k], l, mid, 2*k+1);\n            update(0, n, lazy[k],\
    \ mid, r, 2*k+2);\n            lazy[k] = E;\n            update(a, b, x, l, mid,\
    \ 2*k+1);\n            update(a, b, x, mid, r, 2*k+2);\n        }\n    }\n\n \
    \   void update(int a, int b, OperatorType x) {\n        update(a, b, x, 0, n,\
    \ 0);\n    }\n\n    MonoidType query(int k) {\n        MonoidType res = bottom[k];\n\
    \        for(k = (k+n)>>1; k>0; k>>=1) { // 1-indexed\n            res = upd_f(res,\
    \ lazy[k-1]);\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_022_dual_segtree.cpp
  requiredBy:
  - structure/verify/verify_strc_022_dual_segtree.cpp
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_022_dual_segtree.cpp
layout: document
redirect_from:
- /library/structure/strc_022_dual_segtree.cpp
- /library/structure/strc_022_dual_segtree.cpp.html
title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)"
---
