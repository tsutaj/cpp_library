---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/strc_008_abst_segtree.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"structure/verify/verify_strc_008_abst_segtree.cpp\"\n#include\
    \ <vector>\n#include <functional>\n#include <algorithm>\n#include <iostream>\n\
    #include <climits>\nusing namespace std;\n#line 1 \"structure/strc_008_abst_segtree.cpp\"\
    \n// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
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
    \ vr);\n        }\n        return cmb_f(vl, vr);\n    }\n};\n#line 8 \"structure/verify/verify_strc_008_abst_segtree.cpp\"\
    \n\n// Verified on Apr 27, 2019\n// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    \n// Range Minimum Query\n// query 1: update\n// query 2: range minimum\nvoid\
    \ DSL_2_A() {\n    int N, Q; cin >> N >> Q;\n    SegmentTree<int> seg(N, INT_MAX,\n\
    \                         [](int a, int b) { return b; },\n                  \
    \       [](int a, int b) { return min(a, b); });\n\n    int indexed = 0;\n   \
    \ for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n     \
    \   int x, y; cin >> x >> y;\n        if(query_type == 0) {\n            x -=\
    \ indexed;\n            seg.update(x, y);\n        }\n        if(query_type ==\
    \ 1) {\n            x -= indexed, y -= indexed;\n            y++;\n          \
    \  cout << seg.query(x, y) << endl;\n        }\n    }\n}\n\n// Verified on Apr\
    \ 27, 2019\n// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    \n// Range Sum Query\n// query 1: add\n// query 2: range sum\nvoid DSL_2_B() {\n\
    \    int N, Q; cin >> N >> Q;\n    SegmentTree<int> seg(N, 0,\n              \
    \           [](int a, int b) { return a + b; },\n                         [](int\
    \ a, int b) { return a + b; });\n\n    int indexed = 1;\n    for(int i=0; i<Q;\
    \ i++) {\n        int query_type; cin >> query_type;\n        int x, y; cin >>\
    \ x >> y;\n        if(query_type == 0) {\n            x -= indexed;\n        \
    \    seg.update(x, y);\n        }\n        if(query_type == 1) {\n           \
    \ x -= indexed, y -= indexed;\n            y++;\n            cout << seg.query(x,\
    \ y) << endl;\n        }\n    }\n}\n\nint main() {\n    // DSL_2_A();\n    DSL_2_B();\n\
    \    return 0;\n}\n"
  code: "#include <vector>\n#include <functional>\n#include <algorithm>\n#include\
    \ <iostream>\n#include <climits>\nusing namespace std;\n#include \"../strc_008_abst_segtree.cpp\"\
    \n\n// Verified on Apr 27, 2019\n// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\n\
    \n// Range Minimum Query\n// query 1: update\n// query 2: range minimum\nvoid\
    \ DSL_2_A() {\n    int N, Q; cin >> N >> Q;\n    SegmentTree<int> seg(N, INT_MAX,\n\
    \                         [](int a, int b) { return b; },\n                  \
    \       [](int a, int b) { return min(a, b); });\n\n    int indexed = 0;\n   \
    \ for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n     \
    \   int x, y; cin >> x >> y;\n        if(query_type == 0) {\n            x -=\
    \ indexed;\n            seg.update(x, y);\n        }\n        if(query_type ==\
    \ 1) {\n            x -= indexed, y -= indexed;\n            y++;\n          \
    \  cout << seg.query(x, y) << endl;\n        }\n    }\n}\n\n// Verified on Apr\
    \ 27, 2019\n// Judge: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\n\
    \n// Range Sum Query\n// query 1: add\n// query 2: range sum\nvoid DSL_2_B() {\n\
    \    int N, Q; cin >> N >> Q;\n    SegmentTree<int> seg(N, 0,\n              \
    \           [](int a, int b) { return a + b; },\n                         [](int\
    \ a, int b) { return a + b; });\n\n    int indexed = 1;\n    for(int i=0; i<Q;\
    \ i++) {\n        int query_type; cin >> query_type;\n        int x, y; cin >>\
    \ x >> y;\n        if(query_type == 0) {\n            x -= indexed;\n        \
    \    seg.update(x, y);\n        }\n        if(query_type == 1) {\n           \
    \ x -= indexed, y -= indexed;\n            y++;\n            cout << seg.query(x,\
    \ y) << endl;\n        }\n    }\n}\n\nint main() {\n    // DSL_2_A();\n    DSL_2_B();\n\
    \    return 0;\n}\n"
  dependsOn:
  - structure/strc_008_abst_segtree.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_008_abst_segtree.cpp
  requiredBy: []
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_008_abst_segtree.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_008_abst_segtree.cpp
- /library/structure/verify/verify_strc_008_abst_segtree.cpp.html
title: structure/verify/verify_strc_008_abst_segtree.cpp
---
