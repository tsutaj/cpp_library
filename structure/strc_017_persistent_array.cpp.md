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
  bundledCode: "#line 1 \"structure/strc_017_persistent_array.cpp\"\n// \u6C38\u7D9A\
    \u914D\u5217 (2^{LOG} \u5206\u6728\u306B\u3088\u308B\u5B9F\u88C5)\n// \u30D1\u30B9\
    \u30B3\u30D4\u30FC\u306F mutable_get \u3067\u884C\u304A\u3046\uFF01\u5024\u3092\
    \u6301\u3063\u3066\u304F\u308B\u3060\u3051\u306A\u3089 get \u3092\u4F7F\u304A\u3046\
    \n\ntemplate <typename Type, int LOG>\nstruct PersistentArray {\n    struct Node\
    \ {\n        Type data;\n        Node* child[1 << LOG] = {};\n        Node() {}\n\
    \        Node(const Type& data_) : data(data_) {}\n    };\n    Node* root;\n\n\
    \    PersistentArray() : root(nullptr) {}\n    Type get(Node* t, int k) {\n  \
    \      if(k == 0) return t->data;\n        return get(t->child[k & ((1 << LOG)\
    \ - 1)], k >> LOG);\n    }\n\n    Type get(const int& k) {\n        return get(root,\
    \ k);\n    }\n\n    pair<Node*, Type*> mutable_get(Node* t, int k) {\n       \
    \ t = t ? new Node(*t) : new Node();\n        if(k == 0) return {t, &t->data};\n\
    \        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);\n   \
    \     t->child[k & ((1 << LOG) - 1)] = p.first;\n        return {t, p.second};\n\
    \    }\n\n    Type* mutable_get(const int& k) {\n        auto ret = mutable_get(root,\
    \ k);\n        root = ret.first;\n        return ret.second;\n    }\n\n    Node*\
    \ build(Node* t, const Type& data, int k) {\n        if(!t) t = new Node();\n\
    \        if(k == 0) {\n            t->data = data;\n            return t;\n  \
    \      }\n        auto p = build(t->child[k & ((1 << LOG) - 1)], data, k >> LOG);\n\
    \        t->child[k & ((1 << LOG) - 1)] = p;\n        return t;\n    }\n\n   \
    \ void build(const vector<Type>& vec) {\n        root = nullptr;\n        for(size_t\
    \ i=0; i<vec.size(); i++) {\n            root = build(root, vec[i], i);\n    \
    \    }\n    }\n};\n"
  code: "// \u6C38\u7D9A\u914D\u5217 (2^{LOG} \u5206\u6728\u306B\u3088\u308B\u5B9F\
    \u88C5)\n// \u30D1\u30B9\u30B3\u30D4\u30FC\u306F mutable_get \u3067\u884C\u304A\
    \u3046\uFF01\u5024\u3092\u6301\u3063\u3066\u304F\u308B\u3060\u3051\u306A\u3089\
    \ get \u3092\u4F7F\u304A\u3046\n\ntemplate <typename Type, int LOG>\nstruct PersistentArray\
    \ {\n    struct Node {\n        Type data;\n        Node* child[1 << LOG] = {};\n\
    \        Node() {}\n        Node(const Type& data_) : data(data_) {}\n    };\n\
    \    Node* root;\n\n    PersistentArray() : root(nullptr) {}\n    Type get(Node*\
    \ t, int k) {\n        if(k == 0) return t->data;\n        return get(t->child[k\
    \ & ((1 << LOG) - 1)], k >> LOG);\n    }\n\n    Type get(const int& k) {\n   \
    \     return get(root, k);\n    }\n\n    pair<Node*, Type*> mutable_get(Node*\
    \ t, int k) {\n        t = t ? new Node(*t) : new Node();\n        if(k == 0)\
    \ return {t, &t->data};\n        auto p = mutable_get(t->child[k & ((1 << LOG)\
    \ - 1)], k >> LOG);\n        t->child[k & ((1 << LOG) - 1)] = p.first;\n     \
    \   return {t, p.second};\n    }\n\n    Type* mutable_get(const int& k) {\n  \
    \      auto ret = mutable_get(root, k);\n        root = ret.first;\n        return\
    \ ret.second;\n    }\n\n    Node* build(Node* t, const Type& data, int k) {\n\
    \        if(!t) t = new Node();\n        if(k == 0) {\n            t->data = data;\n\
    \            return t;\n        }\n        auto p = build(t->child[k & ((1 <<\
    \ LOG) - 1)], data, k >> LOG);\n        t->child[k & ((1 << LOG) - 1)] = p;\n\
    \        return t;\n    }\n\n    void build(const vector<Type>& vec) {\n     \
    \   root = nullptr;\n        for(size_t i=0; i<vec.size(); i++) {\n          \
    \  root = build(root, vec[i], i);\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_017_persistent_array.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_017_persistent_array.cpp
layout: document
redirect_from:
- /library/structure/strc_017_persistent_array.cpp
- /library/structure/strc_017_persistent_array.cpp.html
title: structure/strc_017_persistent_array.cpp
---
