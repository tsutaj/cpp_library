---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
    title: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      \ (Dynamic Lazy Segment Tree)"
    links: []
  bundledCode: "#line 1 \"structure/strc_021_dynamic_lazy_segtree.cpp\"\n// @category\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u52D5\u7684\u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Lazy Segment Tree)\n// \u52D5\
    \u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5FC5\u8981\u306A\u3068\
    \u3053\u308D\u3060\u3051\u30CE\u30FC\u30C9\u3092\u4F5C\u308B)\n\ntemplate <typename\
    \ MonoidType, typename OperatorType>\nstruct LazySegNode {\n    MonoidType value;\n\
    \    OperatorType lazy_value;\n    bool need_update;\n    LazySegNode *ch[2];\n\
    \    \n    LazySegNode() {}\n    LazySegNode(MonoidType value_, OperatorType lazy_value_)\
    \ :\n        value(value_), lazy_value(lazy_value_) {\n        need_update = false;\n\
    \        ch[0] = ch[1] = nullptr;\n    }\n};\n\ntemplate <typename MonoidType,\
    \ typename OperatorType, typename IdxType = int>\nstruct DynamicLazySegmentTree\
    \ {\n    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;\n    using\
    \ OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n    using MOtoM\
    \ = function< MonoidType(MonoidType, OperatorType) >;\n    using OItoO = function<\
    \ OperatorType(OperatorType, int) >;\n    using LNode = LazySegNode<MonoidType,\
    \ OperatorType>;\n\n    // node, identity element\n    IdxType n;\n    LNode *root;\n\
    \    MonoidType E0;\n    OperatorType E1;\n\n    // update / combine / lazy /\
    \ accumulate function\n    MOtoM upd_f;\n    MMtoM cmb_f;\n    OOtoO lzy_f;\n\
    \    OItoO acc_f;\n\n    DynamicLazySegmentTree() {}\n    DynamicLazySegmentTree(IdxType\
    \ n_, MonoidType E0_, OperatorType E1_,\n                           MOtoM upd_f_,\
    \ MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_) :\n        E0(E0_), E1(E1_),\n   \
    \     upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_), acc_f(acc_f_) {\n        root\
    \ = new LNode(E0_, E1_);\n        n = 1; while(n < n_) n *= 2;\n    }\n\n    void\
    \ eval(LNode *node, IdxType l, IdxType r) {\n        if(!node->need_update) return;\n\
    \        node->value = upd_f(node->value, acc_f(node->lazy_value, r - l));\n \
    \       if(r - l > 1) {\n            if(!node->ch[0]) node->ch[0] = new LNode(E0,\
    \ E1);\n            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);\n      \
    \      node->ch[0]->lazy_value = lzy_f(node->ch[0]->lazy_value, node->lazy_value);\n\
    \            node->ch[1]->lazy_value = lzy_f(node->ch[1]->lazy_value, node->lazy_value);\n\
    \            node->ch[0]->need_update = node->ch[1]->need_update = true;\n   \
    \     }\n        node->lazy_value = E1;\n        node->need_update = false;\n\
    \    }\n\n    void update(LNode *node, IdxType a, IdxType b, OperatorType x,\n\
    \                IdxType l, IdxType r) {\n        eval(node, l, r);\n        if(b\
    \ <= l or r <= a) return;\n        if(a <= l and r <= b) {\n            node->lazy_value\
    \ = lzy_f(node->lazy_value, x);\n            node->need_update = true;\n     \
    \       eval(node, l, r);\n        }\n        else {\n            IdxType mid\
    \ = (l + r) / 2;\n            if(!node->ch[0]) node->ch[0] = new LNode(E0, E1);\n\
    \            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);\n            update(node->ch[0],\
    \ a, b, x, l, mid);\n            update(node->ch[1], a, b, x, mid, r);\n     \
    \       node->value = cmb_f(node->ch[0]->value, node->ch[1]->value);\n       \
    \ }\n    }\n\n    MonoidType query(LNode *node, IdxType a, IdxType b, IdxType\
    \ l, IdxType r) {\n        if(b <= l or r <= a) return E0;\n        eval(node,\
    \ l, r);\n        if(a <= l and r <= b) return node->value;\n        IdxType mid\
    \ = (l + r) / 2;\n        MonoidType vl = (node->ch[0] ? query(node->ch[0], a,\
    \ b, l, mid) : E0);\n        MonoidType vr = (node->ch[1] ? query(node->ch[1],\
    \ a, b, mid, r) : E0);\n        return cmb_f(vl, vr);\n    }\n\n    // update\
    \ [a, b)-th element (applied value: x)\n    void update(IdxType a, IdxType b,\
    \ OperatorType x) {\n        update(root, a, b, x, 0, n);\n    }\n\n    // range\
    \ query for [a, b)\n    MonoidType query(IdxType a, IdxType b) {\n        return\
    \ query(root, a, b, 0, n);\n    }\n};\n"
  code: "// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Lazy Segment\
    \ Tree)\n// \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5FC5\
    \u8981\u306A\u3068\u3053\u308D\u3060\u3051\u30CE\u30FC\u30C9\u3092\u4F5C\u308B\
    )\n\ntemplate <typename MonoidType, typename OperatorType>\nstruct LazySegNode\
    \ {\n    MonoidType value;\n    OperatorType lazy_value;\n    bool need_update;\n\
    \    LazySegNode *ch[2];\n    \n    LazySegNode() {}\n    LazySegNode(MonoidType\
    \ value_, OperatorType lazy_value_) :\n        value(value_), lazy_value(lazy_value_)\
    \ {\n        need_update = false;\n        ch[0] = ch[1] = nullptr;\n    }\n};\n\
    \ntemplate <typename MonoidType, typename OperatorType, typename IdxType = int>\n\
    struct DynamicLazySegmentTree {\n    using MMtoM = function< MonoidType(MonoidType,\
    \ MonoidType) >;\n    using OOtoO = function< OperatorType(OperatorType, OperatorType)\
    \ >;\n    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;\n  \
    \  using OItoO = function< OperatorType(OperatorType, int) >;\n    using LNode\
    \ = LazySegNode<MonoidType, OperatorType>;\n\n    // node, identity element\n\
    \    IdxType n;\n    LNode *root;\n    MonoidType E0;\n    OperatorType E1;\n\n\
    \    // update / combine / lazy / accumulate function\n    MOtoM upd_f;\n    MMtoM\
    \ cmb_f;\n    OOtoO lzy_f;\n    OItoO acc_f;\n\n    DynamicLazySegmentTree() {}\n\
    \    DynamicLazySegmentTree(IdxType n_, MonoidType E0_, OperatorType E1_,\n  \
    \                         MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_)\
    \ :\n        E0(E0_), E1(E1_),\n        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_),\
    \ acc_f(acc_f_) {\n        root = new LNode(E0_, E1_);\n        n = 1; while(n\
    \ < n_) n *= 2;\n    }\n\n    void eval(LNode *node, IdxType l, IdxType r) {\n\
    \        if(!node->need_update) return;\n        node->value = upd_f(node->value,\
    \ acc_f(node->lazy_value, r - l));\n        if(r - l > 1) {\n            if(!node->ch[0])\
    \ node->ch[0] = new LNode(E0, E1);\n            if(!node->ch[1]) node->ch[1] =\
    \ new LNode(E0, E1);\n            node->ch[0]->lazy_value = lzy_f(node->ch[0]->lazy_value,\
    \ node->lazy_value);\n            node->ch[1]->lazy_value = lzy_f(node->ch[1]->lazy_value,\
    \ node->lazy_value);\n            node->ch[0]->need_update = node->ch[1]->need_update\
    \ = true;\n        }\n        node->lazy_value = E1;\n        node->need_update\
    \ = false;\n    }\n\n    void update(LNode *node, IdxType a, IdxType b, OperatorType\
    \ x,\n                IdxType l, IdxType r) {\n        eval(node, l, r);\n   \
    \     if(b <= l or r <= a) return;\n        if(a <= l and r <= b) {\n        \
    \    node->lazy_value = lzy_f(node->lazy_value, x);\n            node->need_update\
    \ = true;\n            eval(node, l, r);\n        }\n        else {\n        \
    \    IdxType mid = (l + r) / 2;\n            if(!node->ch[0]) node->ch[0] = new\
    \ LNode(E0, E1);\n            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);\n\
    \            update(node->ch[0], a, b, x, l, mid);\n            update(node->ch[1],\
    \ a, b, x, mid, r);\n            node->value = cmb_f(node->ch[0]->value, node->ch[1]->value);\n\
    \        }\n    }\n\n    MonoidType query(LNode *node, IdxType a, IdxType b, IdxType\
    \ l, IdxType r) {\n        if(b <= l or r <= a) return E0;\n        eval(node,\
    \ l, r);\n        if(a <= l and r <= b) return node->value;\n        IdxType mid\
    \ = (l + r) / 2;\n        MonoidType vl = (node->ch[0] ? query(node->ch[0], a,\
    \ b, l, mid) : E0);\n        MonoidType vr = (node->ch[1] ? query(node->ch[1],\
    \ a, b, mid, r) : E0);\n        return cmb_f(vl, vr);\n    }\n\n    // update\
    \ [a, b)-th element (applied value: x)\n    void update(IdxType a, IdxType b,\
    \ OperatorType x) {\n        update(root, a, b, x, 0, n);\n    }\n\n    // range\
    \ query for [a, b)\n    MonoidType query(IdxType a, IdxType b) {\n        return\
    \ query(root, a, b, 0, n);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_021_dynamic_lazy_segtree.cpp
  requiredBy:
  - structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_021_dynamic_lazy_segtree.cpp
layout: document
redirect_from:
- /library/structure/strc_021_dynamic_lazy_segtree.cpp
- /library/structure/strc_021_dynamic_lazy_segtree.cpp.html
title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Lazy\
  \ Segment Tree)"
---
