---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_019_intervalset.cpp\"\n// \u533A\u9593\u3092\
    \ set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\n// \u9589\u533A\u9593 [l, r]\
    \ \u3092\u6271\u3046\u3053\u3068\u306B\u6CE8\u610F\ntemplate <typename numericType,\
    \ numericType infty = numeric_limits<numericType>::max() >\nstruct IntervalSet\
    \ : set< pair<numericType, numericType> > {\n    // x \u3092\u542B\u3080\u9589\
    \u533A\u9593 [l, r] \u3092\u53D6\u5F97\n    // \u30A4\u30C6\u30EC\u30FC\u30BF\u3092\
    \u8FD4\u3059\n    auto get(numericType x) {\n        // x \u3088\u308A\u59CB\u70B9\
    \u304C\u5927\u304D\u3044\u533A\u9593\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u3082\
    \u306E\n        auto itr = this->upper_bound(make_pair(x, infty));\n        if(itr\
    \ == this->begin() or (--itr)->second < x) return this->end();\n        return\
    \ itr;\n    }\n\n    // [l, r] \u3068 overlap \u3059\u308B\u533A\u9593\u306E\u96C6\
    \u5408\u3092\u53D6\u5F97\n    // vector \u3092\u8FD4\u3059\n    vector< pair<numericType,\
    \ numericType> > get(numericType l, numericType r) {\n        auto itr = this->upper_bound(make_pair(l,\
    \ l));\n        if(itr != this->begin()) itr--;\n\n        vector< pair<numericType,\
    \ numericType> > res;\n        for(; itr != this->end(); itr++) {\n          \
    \  numericType il, ir; tie(il, ir) = *itr;\n            if(r < il) break; // \u5BFE\
    \u79F0\u533A\u9593\u306B\u5BFE\u3057\u3066\u53F3\u306B\u98DB\u3073\u51FA\u305F\
    \n            // \u5BFE\u79F0\u533A\u9593\u306B\u5BFE\u3057\u3066\u5DE6\u306B\u98DB\
    \u3073\u51FA\u308B\u304B\u3001\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3057\
    \u304B\u306A\u3044\n            if(ir >= l) res.push_back(make_pair(il, ir));\n\
    \        }\n        return res;\n    }\n    \n    void insert(numericType l, numericType\
    \ r) {\n        auto vec = this->get(l, r);\n        numericType il = l, ir =\
    \ r;\n        for(auto e : vec) {\n            this->erase(e);\n            il\
    \ = min(il, e.first);\n            ir = max(ir, e.second);\n        }\n      \
    \  this->emplace(il, ir);\n    }\n    \n    void remove(numericType l, numericType\
    \ r) {\n        auto vec = this->get(l, r);\n        for(auto e : vec) this->erase(e);\n\
    \    }\n\n    // p \u3068 q \u306F\u540C\u3058\u533A\u9593\u4E0A\u306B\u3042\u308B\
    \u304B\uFF1F\n    bool same(numericType p, numericType q) {\n        auto itr\
    \ = get(p);\n        return itr != this->end() and itr->first <= q and q <= itr.second;\n\
    \    }\n\n    void dump() {\n        for(auto e : *this) {\n            numericType\
    \ l, r; tie(l, r) = e;\n            fprintf(stderr, \"# debug: [%g, %g]\\n\",\
    \ l, r);\n        }\n    }\n};\n"
  code: "// \u533A\u9593\u3092 set \u3067\u7BA1\u7406\u3059\u308B\u3084\u3064\n//\
    \ \u9589\u533A\u9593 [l, r] \u3092\u6271\u3046\u3053\u3068\u306B\u6CE8\u610F\n\
    template <typename numericType, numericType infty = numeric_limits<numericType>::max()\
    \ >\nstruct IntervalSet : set< pair<numericType, numericType> > {\n    // x \u3092\
    \u542B\u3080\u9589\u533A\u9593 [l, r] \u3092\u53D6\u5F97\n    // \u30A4\u30C6\u30EC\
    \u30FC\u30BF\u3092\u8FD4\u3059\n    auto get(numericType x) {\n        // x \u3088\
    \u308A\u59CB\u70B9\u304C\u5927\u304D\u3044\u533A\u9593\u306E\u4E2D\u3067\u6700\
    \u5C0F\u306E\u3082\u306E\n        auto itr = this->upper_bound(make_pair(x, infty));\n\
    \        if(itr == this->begin() or (--itr)->second < x) return this->end();\n\
    \        return itr;\n    }\n\n    // [l, r] \u3068 overlap \u3059\u308B\u533A\
    \u9593\u306E\u96C6\u5408\u3092\u53D6\u5F97\n    // vector \u3092\u8FD4\u3059\n\
    \    vector< pair<numericType, numericType> > get(numericType l, numericType r)\
    \ {\n        auto itr = this->upper_bound(make_pair(l, l));\n        if(itr !=\
    \ this->begin()) itr--;\n\n        vector< pair<numericType, numericType> > res;\n\
    \        for(; itr != this->end(); itr++) {\n            numericType il, ir; tie(il,\
    \ ir) = *itr;\n            if(r < il) break; // \u5BFE\u79F0\u533A\u9593\u306B\
    \u5BFE\u3057\u3066\u53F3\u306B\u98DB\u3073\u51FA\u305F\n            // \u5BFE\u79F0\
    \u533A\u9593\u306B\u5BFE\u3057\u3066\u5DE6\u306B\u98DB\u3073\u51FA\u308B\u304B\
    \u3001\u542B\u307E\u308C\u3066\u3044\u308B\u304B\u3057\u304B\u306A\u3044\n   \
    \         if(ir >= l) res.push_back(make_pair(il, ir));\n        }\n        return\
    \ res;\n    }\n    \n    void insert(numericType l, numericType r) {\n       \
    \ auto vec = this->get(l, r);\n        numericType il = l, ir = r;\n        for(auto\
    \ e : vec) {\n            this->erase(e);\n            il = min(il, e.first);\n\
    \            ir = max(ir, e.second);\n        }\n        this->emplace(il, ir);\n\
    \    }\n    \n    void remove(numericType l, numericType r) {\n        auto vec\
    \ = this->get(l, r);\n        for(auto e : vec) this->erase(e);\n    }\n\n   \
    \ // p \u3068 q \u306F\u540C\u3058\u533A\u9593\u4E0A\u306B\u3042\u308B\u304B\uFF1F\
    \n    bool same(numericType p, numericType q) {\n        auto itr = get(p);\n\
    \        return itr != this->end() and itr->first <= q and q <= itr.second;\n\
    \    }\n\n    void dump() {\n        for(auto e : *this) {\n            numericType\
    \ l, r; tie(l, r) = e;\n            fprintf(stderr, \"# debug: [%g, %g]\\n\",\
    \ l, r);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_019_intervalset.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_019_intervalset.cpp
layout: document
redirect_from:
- /library/structure/strc_019_intervalset.cpp
- /library/structure/strc_019_intervalset.cpp.html
title: structure/strc_019_intervalset.cpp
---
