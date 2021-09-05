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
  bundledCode: "#line 1 \"structure/strc_018_binarytrie.cpp\"\n// Binary Trie\n//\
    \ \u30FB\u8272\u3005 verify \u305F\u308A\u306A\u3044\u3002\u7279\u306B\u9045\u5EF6\
    \u8A55\u4FA1\u306F\u307E\u3060\u4F55\u3082 verify \u3057\u3066\u306A\u3044\uFF01\
    \u8981\u6CE8\u610F\uFF01\uFF01\n\n// Verify \u6E08\u307F\n// \u30FBinsert, erase\n\
    // \u30FBmin_element\n// \u30FBcount_less\n// \u30FBget_kth\n\n// \u901A\u3057\
    \u305F\u554F\u984C\u4E00\u89A7\n// \u30FBARC033-C \u30C7\u30FC\u30BF\u69CB\u9020\
    \ (insert, erase, get_kth)\n// \u30FBCodeforces Round #470 C Perfect Security\
    \ (insert, erase, min_element)\n// \u30FBSPOJ SubXor (insert, erase, count_less)\n\
    \ntemplate <typename Type = unsigned int, int B = 32>\nstruct BinaryTrie {\nprivate:\n\
    \    struct Node {\n        int cnt;\n        Type lazy;\n        Node* child[2];\n\
    \        Node() : cnt(0), lazy(0), child{ nullptr, nullptr } {}\n    };\n\n  \
    \  int get_size(Node *t) const { return t ? t->cnt : 0; }\n    void lazy_eval(Node*\
    \ t, int b) const {\n        if((t->lazy >> (Type)b) & (Type)1) swap(t->child[0],\
    \ t->child[1]);\n        if(t->child[0]) t->child[0]->lazy ^= t->lazy;\n     \
    \   if(t->child[1]) t->child[1]->lazy ^= t->lazy;\n        t->lazy = 0;\n    }\n\
    \n    Node* add(Node* t, Type val, int b = B - 1) {\n        if(!t) t = new Node;\n\
    \        t->cnt++;\n        if(b < 0) return t;\n        lazy_eval(t, b);\n  \
    \      int bin = (val >> (Type)b) & (Type)1;\n        t->child[bin] = add(t->child[bin],\
    \ val, b-1);\n        return t;\n    }\n\n    Node* sub(Node* t, Type val, int\
    \ b = B - 1) {\n        assert(t);\n        t->cnt--;\n        if(t->cnt == 0)\
    \ return nullptr;\n        if(b < 0) return t;\n        lazy_eval(t, b);\n   \
    \     int bin = (val >> (Type)b) & (Type)1;\n        t->child[bin] = sub(t->child[bin],\
    \ val, b-1);\n        return t;\n    }\n\n    // \u5168\u4F53\u3092 val \u3067\
    \ XOR \u53D6\u3063\u305F\u6642\u306E\u6700\u5C0F\u5024\n    Type get_min(Node*\
    \ t, Type val, int b = B - 1) const {\n        assert(t);\n        if(b < 0) return\
    \ 0;\n        lazy_eval(t, b);\n        int bin = (val >> (Type)b) & (Type)1;\
    \ bin ^= !t->child[bin];\n        return get_min(t->child[bin], val, b-1) | ((Type)bin\
    \ << (Type)b);\n    }\n\n    // \u5168\u4F53\u3092 val \u3067 XOR \u53D6\u3063\
    \u305F\u3068\u304D\u306B k \u756A\u76EE (1-indexed) \u306B\u5C0F\u3055\u3044\u5024\
    \n    Type get_kth(Node* t, Type val, int k, int b = B - 1) const {\n        assert(t);\n\
    \        if(b < 0) return 0;\n        lazy_eval(t, b);\n        int bin = (val\
    \ >> (Type)b) & (Type)1;\n        if(get_size(t->child[bin]) < k) k -= get_size(t->child[bin]),\
    \ bin ^= 1;\n\n        // fprintf(stderr, \"bin = %d\\n\", bin);\n        return\
    \ get_kth(t->child[bin], val, k, b-1) | ((Type)bin << (Type)b);\n    }\n\n   \
    \ // \u96C6\u5408\u5185\u306B\u3042\u308B val \u4EE5\u4E0A\u306E\u8981\u7D20\u306E\
    \u4E2D\u3067\u6700\u5C0F\u306E\u3082\u306E\u306E id (1-indexed? (TODO: verify))\n\
    \    int get_lower(Node* t, Type val, int b = B - 1) {\n        if(!t || b < 0)\
    \ return 0;\n        lazy_eval(t, b);\n        bool bin = (val >> (Type)b) & (Type)1;\n\
    \        return (bin && t->child[0] ? t->child[0]->cnt : 0) + get_lower(t->child[bin],\
    \ val, b-1);\n    }\n\n    // \u5168\u4F53\u3092 val \u3067 XOR \u53D6\u3063\u305F\
    \u3068\u304D\u306B x \u672A\u6E80\u306B\u306A\u308B\u8981\u7D20\u306E\u6570\n\
    \    int count_less(Node* t, Type val, Type x, int b = B - 1) {\n        if(!t\
    \ || b < 0) return 0;\n        lazy_eval(t, b);\n        bool bin = (val >> (Type)b)\
    \ & (Type)1;\n        int add = 0;\n        if(x >> (Type)b & 1) add += get_size(t->child[bin]),\
    \ bin ^= 1;\n        return add + count_less(t->child[bin], val, x, b-1);\n  \
    \  }\n\n    Node* root;\n\npublic:\n    BinaryTrie() : root(nullptr) {}\n    int\
    \ size() const {\n        return get_size(root);\n    }\n    bool empty() const\
    \ {\n        return !root;\n    }\n    void insert(Type val) {\n        root =\
    \ add(root, val);\n    }\n    void erase(Type val) {\n        root = sub(root,\
    \ val);\n    }\n\n    // XOR \u3068\u3063\u305F\u5F8C\u306E\u5024\u3067\u306F\u306A\
    \u304F\u3001\u96C6\u5408\u5185\u306B\u3042\u308B\u5024\u304C\u305D\u306E\u307E\
    \u307E\u8FD4\u308B\n    Type max_element(Type XOR = 0) const {\n        return\
    \ get_min(root, ~XOR);\n    }\n    Type min_element(Type XOR = 0) const {\n  \
    \      return get_min(root,  XOR);\n    }\n\n    // \u8981\u7D20\u5168\u4F53\u3092\
    \ XOR\n    void xor_all(Type val) {\n        if(root) root->lazy ^= val;\n   \
    \ }\n\n    // \u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304C\u8FD4\
    \u3063\u3066\u304F\u308B\u3053\u3068\u306B\u6CE8\u610F\n    int lower_bound(Type\
    \ val) {\n        return get_lower(root, val);\n    }\n    int upper_bound(Type\
    \ val) {\n        return get_lower(root, val + 1);\n    }\n\n    // \u5168\u4F53\
    \u306B XOR \u3057\u305F\u3068\u304D\u306E val \u672A\u6E80\u306E\u5024\u306E\u6570\
    \n    int count_less(Type val, Type XOR = 0) {\n        return count_less(root,\
    \ XOR, val);\n    }\n\n    // \u5168\u4F53\u306B XOR \u3057\u305F\u3068\u304D\u306E\
    \ val \u3092\u8D85\u3048\u308B\u5024\u306E\u6570\n    int count_upper(Type val,\
    \ Type XOR = 0) {\n        return size() - count_less(root, XOR, val + 1);\n \
    \   }\n\n    // 0-indexed\n    Type get_kth(int k, Type XOR = 0) const {\n   \
    \     assert(0 <= k and k < size());\n        return get_kth(root, XOR, k+1);\n\
    \    }\n\n    // 0-indexed\n    Type operator[](int k) {\n        return get_kth(k);\n\
    \    }\n};\n"
  code: "// Binary Trie\n// \u30FB\u8272\u3005 verify \u305F\u308A\u306A\u3044\u3002\
    \u7279\u306B\u9045\u5EF6\u8A55\u4FA1\u306F\u307E\u3060\u4F55\u3082 verify \u3057\
    \u3066\u306A\u3044\uFF01\u8981\u6CE8\u610F\uFF01\uFF01\n\n// Verify \u6E08\u307F\
    \n// \u30FBinsert, erase\n// \u30FBmin_element\n// \u30FBcount_less\n// \u30FB\
    get_kth\n\n// \u901A\u3057\u305F\u554F\u984C\u4E00\u89A7\n// \u30FBARC033-C \u30C7\
    \u30FC\u30BF\u69CB\u9020 (insert, erase, get_kth)\n// \u30FBCodeforces Round #470\
    \ C Perfect Security (insert, erase, min_element)\n// \u30FBSPOJ SubXor (insert,\
    \ erase, count_less)\n\ntemplate <typename Type = unsigned int, int B = 32>\n\
    struct BinaryTrie {\nprivate:\n    struct Node {\n        int cnt;\n        Type\
    \ lazy;\n        Node* child[2];\n        Node() : cnt(0), lazy(0), child{ nullptr,\
    \ nullptr } {}\n    };\n\n    int get_size(Node *t) const { return t ? t->cnt\
    \ : 0; }\n    void lazy_eval(Node* t, int b) const {\n        if((t->lazy >> (Type)b)\
    \ & (Type)1) swap(t->child[0], t->child[1]);\n        if(t->child[0]) t->child[0]->lazy\
    \ ^= t->lazy;\n        if(t->child[1]) t->child[1]->lazy ^= t->lazy;\n       \
    \ t->lazy = 0;\n    }\n\n    Node* add(Node* t, Type val, int b = B - 1) {\n \
    \       if(!t) t = new Node;\n        t->cnt++;\n        if(b < 0) return t;\n\
    \        lazy_eval(t, b);\n        int bin = (val >> (Type)b) & (Type)1;\n   \
    \     t->child[bin] = add(t->child[bin], val, b-1);\n        return t;\n    }\n\
    \n    Node* sub(Node* t, Type val, int b = B - 1) {\n        assert(t);\n    \
    \    t->cnt--;\n        if(t->cnt == 0) return nullptr;\n        if(b < 0) return\
    \ t;\n        lazy_eval(t, b);\n        int bin = (val >> (Type)b) & (Type)1;\n\
    \        t->child[bin] = sub(t->child[bin], val, b-1);\n        return t;\n  \
    \  }\n\n    // \u5168\u4F53\u3092 val \u3067 XOR \u53D6\u3063\u305F\u6642\u306E\
    \u6700\u5C0F\u5024\n    Type get_min(Node* t, Type val, int b = B - 1) const {\n\
    \        assert(t);\n        if(b < 0) return 0;\n        lazy_eval(t, b);\n \
    \       int bin = (val >> (Type)b) & (Type)1; bin ^= !t->child[bin];\n       \
    \ return get_min(t->child[bin], val, b-1) | ((Type)bin << (Type)b);\n    }\n\n\
    \    // \u5168\u4F53\u3092 val \u3067 XOR \u53D6\u3063\u305F\u3068\u304D\u306B\
    \ k \u756A\u76EE (1-indexed) \u306B\u5C0F\u3055\u3044\u5024\n    Type get_kth(Node*\
    \ t, Type val, int k, int b = B - 1) const {\n        assert(t);\n        if(b\
    \ < 0) return 0;\n        lazy_eval(t, b);\n        int bin = (val >> (Type)b)\
    \ & (Type)1;\n        if(get_size(t->child[bin]) < k) k -= get_size(t->child[bin]),\
    \ bin ^= 1;\n\n        // fprintf(stderr, \"bin = %d\\n\", bin);\n        return\
    \ get_kth(t->child[bin], val, k, b-1) | ((Type)bin << (Type)b);\n    }\n\n   \
    \ // \u96C6\u5408\u5185\u306B\u3042\u308B val \u4EE5\u4E0A\u306E\u8981\u7D20\u306E\
    \u4E2D\u3067\u6700\u5C0F\u306E\u3082\u306E\u306E id (1-indexed? (TODO: verify))\n\
    \    int get_lower(Node* t, Type val, int b = B - 1) {\n        if(!t || b < 0)\
    \ return 0;\n        lazy_eval(t, b);\n        bool bin = (val >> (Type)b) & (Type)1;\n\
    \        return (bin && t->child[0] ? t->child[0]->cnt : 0) + get_lower(t->child[bin],\
    \ val, b-1);\n    }\n\n    // \u5168\u4F53\u3092 val \u3067 XOR \u53D6\u3063\u305F\
    \u3068\u304D\u306B x \u672A\u6E80\u306B\u306A\u308B\u8981\u7D20\u306E\u6570\n\
    \    int count_less(Node* t, Type val, Type x, int b = B - 1) {\n        if(!t\
    \ || b < 0) return 0;\n        lazy_eval(t, b);\n        bool bin = (val >> (Type)b)\
    \ & (Type)1;\n        int add = 0;\n        if(x >> (Type)b & 1) add += get_size(t->child[bin]),\
    \ bin ^= 1;\n        return add + count_less(t->child[bin], val, x, b-1);\n  \
    \  }\n\n    Node* root;\n\npublic:\n    BinaryTrie() : root(nullptr) {}\n    int\
    \ size() const {\n        return get_size(root);\n    }\n    bool empty() const\
    \ {\n        return !root;\n    }\n    void insert(Type val) {\n        root =\
    \ add(root, val);\n    }\n    void erase(Type val) {\n        root = sub(root,\
    \ val);\n    }\n\n    // XOR \u3068\u3063\u305F\u5F8C\u306E\u5024\u3067\u306F\u306A\
    \u304F\u3001\u96C6\u5408\u5185\u306B\u3042\u308B\u5024\u304C\u305D\u306E\u307E\
    \u307E\u8FD4\u308B\n    Type max_element(Type XOR = 0) const {\n        return\
    \ get_min(root, ~XOR);\n    }\n    Type min_element(Type XOR = 0) const {\n  \
    \      return get_min(root,  XOR);\n    }\n\n    // \u8981\u7D20\u5168\u4F53\u3092\
    \ XOR\n    void xor_all(Type val) {\n        if(root) root->lazy ^= val;\n   \
    \ }\n\n    // \u8981\u7D20\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u304C\u8FD4\
    \u3063\u3066\u304F\u308B\u3053\u3068\u306B\u6CE8\u610F\n    int lower_bound(Type\
    \ val) {\n        return get_lower(root, val);\n    }\n    int upper_bound(Type\
    \ val) {\n        return get_lower(root, val + 1);\n    }\n\n    // \u5168\u4F53\
    \u306B XOR \u3057\u305F\u3068\u304D\u306E val \u672A\u6E80\u306E\u5024\u306E\u6570\
    \n    int count_less(Type val, Type XOR = 0) {\n        return count_less(root,\
    \ XOR, val);\n    }\n\n    // \u5168\u4F53\u306B XOR \u3057\u305F\u3068\u304D\u306E\
    \ val \u3092\u8D85\u3048\u308B\u5024\u306E\u6570\n    int count_upper(Type val,\
    \ Type XOR = 0) {\n        return size() - count_less(root, XOR, val + 1);\n \
    \   }\n\n    // 0-indexed\n    Type get_kth(int k, Type XOR = 0) const {\n   \
    \     assert(0 <= k and k < size());\n        return get_kth(root, XOR, k+1);\n\
    \    }\n\n    // 0-indexed\n    Type operator[](int k) {\n        return get_kth(k);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_018_binarytrie.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_018_binarytrie.cpp
layout: document
redirect_from:
- /library/structure/strc_018_binarytrie.cpp
- /library/structure/strc_018_binarytrie.cpp.html
title: structure/strc_018_binarytrie.cpp
---
