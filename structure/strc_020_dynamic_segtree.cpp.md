---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_020_dynamic_segtree.cpp
    title: structure/verify/verify_strc_020_dynamic_segtree.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Segment\
      \ Tree)"
    links: []
  bundledCode: "#line 1 \"structure/strc_020_dynamic_segtree.cpp\"\n// @category \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u52D5\u7684\u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728 (Dynamic Segment Tree)\n// \u52D5\u7684\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728 (\u5FC5\u8981\u306A\u30CE\u30FC\u30C9\u3060\u3051\u4F5C\u308B\
    )\n\ntemplate <typename MonoidType>\nstruct SegNode {\n    MonoidType value;\n\
    \    SegNode *ch[2];\n    SegNode() {}\n    SegNode(MonoidType value_) : value(value_)\
    \ {\n        ch[0] = ch[1] = nullptr;\n    }\n};\n\ntemplate <typename MonoidType,\
    \ typename IdxType = int>\nstruct DynamicSegmentTree {\n    using Function = function<\
    \ MonoidType(MonoidType, MonoidType) >;\n\n    // node, identity element\n   \
    \ IdxType n;\n    SegNode<MonoidType> *root;\n    MonoidType E0;\n\n    // update\
    \ / combine function\n    Function upd_f, cmb_f;\n\n    // initialize\n    DynamicSegmentTree()\
    \ {\n        root = new SegNode<MonoidType>;\n    }\n    DynamicSegmentTree(IdxType\
    \ n_, MonoidType E0_,\n                       Function upd_f_, Function cmb_f_)\
    \ :\n        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {\n        root = new SegNode<MonoidType>(E0_);\n\
    \        n = 1; while(n < n_) n *= 2;\n    }\n\n    void update(SegNode<MonoidType>\
    \ *node, IdxType k, MonoidType x, IdxType l, IdxType r) {\n        if(r - l ==\
    \ 1) {\n            node->value = upd_f(node->value, x);\n            return;\n\
    \        }\n\n        IdxType mid = (l + r) / 2;\n        MonoidType vl = E0,\
    \ vr = E0;\n        if(l <= k and k < mid) {\n            if(!node->ch[0]) node->ch[0]\
    \ = new SegNode<MonoidType>(E0);\n            update(node->ch[0], k, x, l, mid);\n\
    \        }\n        if(mid <= k and k < r) {\n            if(!node->ch[1]) node->ch[1]\
    \ = new SegNode<MonoidType>(E0);\n            update(node->ch[1], k, x, mid, r);\n\
    \        }\n        vl = (node->ch[0] ? node->ch[0]->value : E0);\n        vr\
    \ = (node->ch[1] ? node->ch[1]->value : E0);\n        node->value = cmb_f(vl,\
    \ vr);\n    }\n\n    MonoidType query(SegNode<MonoidType> *node, IdxType a, IdxType\
    \ b, IdxType l, IdxType r) {\n        if(b <= l or r <= a) return E0;\n      \
    \  if(a <= l and r <= b) return node->value;\n\n        IdxType mid = (l + r)\
    \ / 2;\n        MonoidType vl = (node->ch[0] ? query(node->ch[0], a, b, l, mid)\
    \ : E0);\n        MonoidType vr = (node->ch[1] ? query(node->ch[1], a, b, mid,\
    \ r) : E0);\n        return cmb_f(vl, vr);\n    }\n    \n    // update k-th element\
    \ (applied value: x)\n    void update(IdxType k, MonoidType x) {\n        update(root,\
    \ k, x, 0, n);\n    }\n\n    // range query for [a, b)\n    MonoidType query(IdxType\
    \ a, IdxType b) {\n        return query(root, a, b, 0, n);\n    }\n};\n"
  code: "// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Segment Tree)\n//\
    \ \u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5FC5\u8981\u306A\u30CE\u30FC\
    \u30C9\u3060\u3051\u4F5C\u308B)\n\ntemplate <typename MonoidType>\nstruct SegNode\
    \ {\n    MonoidType value;\n    SegNode *ch[2];\n    SegNode() {}\n    SegNode(MonoidType\
    \ value_) : value(value_) {\n        ch[0] = ch[1] = nullptr;\n    }\n};\n\ntemplate\
    \ <typename MonoidType, typename IdxType = int>\nstruct DynamicSegmentTree {\n\
    \    using Function = function< MonoidType(MonoidType, MonoidType) >;\n\n    //\
    \ node, identity element\n    IdxType n;\n    SegNode<MonoidType> *root;\n   \
    \ MonoidType E0;\n\n    // update / combine function\n    Function upd_f, cmb_f;\n\
    \n    // initialize\n    DynamicSegmentTree() {\n        root = new SegNode<MonoidType>;\n\
    \    }\n    DynamicSegmentTree(IdxType n_, MonoidType E0_,\n                 \
    \      Function upd_f_, Function cmb_f_) :\n        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_)\
    \ {\n        root = new SegNode<MonoidType>(E0_);\n        n = 1; while(n < n_)\
    \ n *= 2;\n    }\n\n    void update(SegNode<MonoidType> *node, IdxType k, MonoidType\
    \ x, IdxType l, IdxType r) {\n        if(r - l == 1) {\n            node->value\
    \ = upd_f(node->value, x);\n            return;\n        }\n\n        IdxType\
    \ mid = (l + r) / 2;\n        MonoidType vl = E0, vr = E0;\n        if(l <= k\
    \ and k < mid) {\n            if(!node->ch[0]) node->ch[0] = new SegNode<MonoidType>(E0);\n\
    \            update(node->ch[0], k, x, l, mid);\n        }\n        if(mid <=\
    \ k and k < r) {\n            if(!node->ch[1]) node->ch[1] = new SegNode<MonoidType>(E0);\n\
    \            update(node->ch[1], k, x, mid, r);\n        }\n        vl = (node->ch[0]\
    \ ? node->ch[0]->value : E0);\n        vr = (node->ch[1] ? node->ch[1]->value\
    \ : E0);\n        node->value = cmb_f(vl, vr);\n    }\n\n    MonoidType query(SegNode<MonoidType>\
    \ *node, IdxType a, IdxType b, IdxType l, IdxType r) {\n        if(b <= l or r\
    \ <= a) return E0;\n        if(a <= l and r <= b) return node->value;\n\n    \
    \    IdxType mid = (l + r) / 2;\n        MonoidType vl = (node->ch[0] ? query(node->ch[0],\
    \ a, b, l, mid) : E0);\n        MonoidType vr = (node->ch[1] ? query(node->ch[1],\
    \ a, b, mid, r) : E0);\n        return cmb_f(vl, vr);\n    }\n    \n    // update\
    \ k-th element (applied value: x)\n    void update(IdxType k, MonoidType x) {\n\
    \        update(root, k, x, 0, n);\n    }\n\n    // range query for [a, b)\n \
    \   MonoidType query(IdxType a, IdxType b) {\n        return query(root, a, b,\
    \ 0, n);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_020_dynamic_segtree.cpp
  requiredBy:
  - structure/verify/verify_strc_020_dynamic_segtree.cpp
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_020_dynamic_segtree.cpp
layout: document
redirect_from:
- /library/structure/strc_020_dynamic_segtree.cpp
- /library/structure/strc_020_dynamic_segtree.cpp.html
title: "\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Segment Tree)"
---
