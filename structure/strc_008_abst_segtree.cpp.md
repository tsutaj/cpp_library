---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_008_abst_segtree.cpp
    title: structure/verify/verify_strc_008_abst_segtree.cpp
  - icon: ':warning:'
    path: string/verify/verify_str_009_manacher.cpp
    title: string/verify/verify_str_009_manacher.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
    links:
    - http://d.hatena.ne.jp/komiyam/20131202/1385992406
  bundledCode: "#line 1 \"structure/strc_008_abst_segtree.cpp\"\n// @category \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728 (Segment Tree)\n// \u62BD\u8C61 SegmentTree (0-indexed\u30FB\u4E00\
    \u70B9\u66F4\u65B0\u30FB\u533A\u9593\u53D6\u5F97)\ntemplate <typename MonoidType>\n\
    struct SegmentTree {\n    using Function = function< MonoidType(MonoidType, MonoidType)\
    \ >;\n\n    // node, identity element\n    int n;\n    vector<MonoidType> node;\n\
    \    MonoidType E0;\n\n    // update / combine function\n    Function upd_f, cmb_f;\n\
    \n    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {\n     \
    \   if(v != vector<MonoidType>()) m = v.size();\n        n = 1; while(n < m) n\
    \ *= 2;\n\n        node = vector<MonoidType>(2*n-1, E0);\n        if(v != vector<MonoidType>())\
    \ {\n            for(int i=0; i<m; i++) {\n                node[n-1+i] = v[i];\n\
    \            }\n            for(int i=n-2; i>=0; i--) {\n                node[i]\
    \ = cmb_f(node[2*i+1], node[2*i+2]);\n            }\n        }\n    }\n\n    //\
    \ initialize\n    SegmentTree() {}\n    SegmentTree(int n_, MonoidType E0_,\n\
    \                Function upd_f_, Function cmb_f_,\n                vector<MonoidType>\
    \ v = vector<MonoidType>()) :\n        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {\n\
    \        build(n_, v);\n    }\n\n    // update k-th element (applied value: x)\n\
    \    void update(int k, MonoidType x) {\n        k += n - 1;\n        node[k]\
    \ = upd_f(node[k], x);\n        while(k > 0) {\n            k = (k - 1) / 2;\n\
    \            node[k] = cmb_f(node[2*k+1], node[2*k+2]);\n        }\n    }\n\n\
    \    // range query for [a, b)\n    // \u975E\u518D\u5E30\u306E\u30A2\u30A4\u30C7\
    \u30A2: http://d.hatena.ne.jp/komiyam/20131202/1385992406\n    MonoidType query(int\
    \ a, int b) {\n        MonoidType vl = E0, vr = E0;\n        for(int l=a+n, r=b+n;\
    \ l<r; l>>=1, r>>=1) {\n            if(l & 1) vl = cmb_f(vl, node[(l++)-1]);\n\
    \            if(r & 1) vr = cmb_f(node[(--r)-1], vr);\n        }\n        return\
    \ cmb_f(vl, vr);\n    }\n};\n"
  code: "// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// \u62BD\u8C61 SegmentTree\
    \ (0-indexed\u30FB\u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u53D6\u5F97)\ntemplate\
    \ <typename MonoidType>\nstruct SegmentTree {\n    using Function = function<\
    \ MonoidType(MonoidType, MonoidType) >;\n\n    // node, identity element\n   \
    \ int n;\n    vector<MonoidType> node;\n    MonoidType E0;\n\n    // update /\
    \ combine function\n    Function upd_f, cmb_f;\n\n    void build(int m, vector<MonoidType>\
    \ v = vector<MonoidType>()) {\n        if(v != vector<MonoidType>()) m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n\n        node = vector<MonoidType>(2*n-1,\
    \ E0);\n        if(v != vector<MonoidType>()) {\n            for(int i=0; i<m;\
    \ i++) {\n                node[n-1+i] = v[i];\n            }\n            for(int\
    \ i=n-2; i>=0; i--) {\n                node[i] = cmb_f(node[2*i+1], node[2*i+2]);\n\
    \            }\n        }\n    }\n\n    // initialize\n    SegmentTree() {}\n\
    \    SegmentTree(int n_, MonoidType E0_,\n                Function upd_f_, Function\
    \ cmb_f_,\n                vector<MonoidType> v = vector<MonoidType>()) :\n  \
    \      E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {\n        build(n_, v);\n    }\n\
    \n    // update k-th element (applied value: x)\n    void update(int k, MonoidType\
    \ x) {\n        k += n - 1;\n        node[k] = upd_f(node[k], x);\n        while(k\
    \ > 0) {\n            k = (k - 1) / 2;\n            node[k] = cmb_f(node[2*k+1],\
    \ node[2*k+2]);\n        }\n    }\n\n    // range query for [a, b)\n    // \u975E\
    \u518D\u5E30\u306E\u30A2\u30A4\u30C7\u30A2: http://d.hatena.ne.jp/komiyam/20131202/1385992406\n\
    \    MonoidType query(int a, int b) {\n        MonoidType vl = E0, vr = E0;\n\
    \        for(int l=a+n, r=b+n; l<r; l>>=1, r>>=1) {\n            if(l & 1) vl\
    \ = cmb_f(vl, node[(l++)-1]);\n            if(r & 1) vr = cmb_f(node[(--r)-1],\
    \ vr);\n        }\n        return cmb_f(vl, vr);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_008_abst_segtree.cpp
  requiredBy:
  - structure/verify/verify_strc_008_abst_segtree.cpp
  - string/verify/verify_str_009_manacher.cpp
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_008_abst_segtree.cpp
layout: document
redirect_from:
- /library/structure/strc_008_abst_segtree.cpp
- /library/structure/strc_008_abst_segtree.cpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
---
