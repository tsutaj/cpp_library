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
  bundledCode: "#line 1 \"marathon/index_set.cpp\"\nclass IndexSet {\npublic:\n  \
    \  IndexSet(int n) : pos_(n, -1) {}\n\n    void insert(int x) {\n        if (contains(x))\
    \ return;\n        que_.push_back(x);\n        pos_[x] = que_.size() - 1;\n  \
    \  }\n\n    void erase(int x) {\n        if (!contains(x)) return;\n        int\
    \ idx = pos_[x];\n        if (idx == -1) return;\n        int last = que_.back();\n\
    \        que_[idx] = last;\n        pos_[last] = idx;\n        que_.pop_back();\n\
    \        pos_[x] = -1;\n    }\n\n    int size() const {\n        return que_.size();\n\
    \    }\n\n    bool contains(int x) const {\n        return pos_[x] != -1;\n  \
    \  }\n\n    int operator[](int idx) const {\n        return que_[idx];\n    }\n\
    \n    const vector<int>& get_elements() const {\n        return que_;\n    }\n\
    \nprivate:\n    vector<int> que_;\n    vector<int> pos_;\n};\n"
  code: "class IndexSet {\npublic:\n    IndexSet(int n) : pos_(n, -1) {}\n\n    void\
    \ insert(int x) {\n        if (contains(x)) return;\n        que_.push_back(x);\n\
    \        pos_[x] = que_.size() - 1;\n    }\n\n    void erase(int x) {\n      \
    \  if (!contains(x)) return;\n        int idx = pos_[x];\n        if (idx == -1)\
    \ return;\n        int last = que_.back();\n        que_[idx] = last;\n      \
    \  pos_[last] = idx;\n        que_.pop_back();\n        pos_[x] = -1;\n    }\n\
    \n    int size() const {\n        return que_.size();\n    }\n\n    bool contains(int\
    \ x) const {\n        return pos_[x] != -1;\n    }\n\n    int operator[](int idx)\
    \ const {\n        return que_[idx];\n    }\n\n    const vector<int>& get_elements()\
    \ const {\n        return que_;\n    }\n\nprivate:\n    vector<int> que_;\n  \
    \  vector<int> pos_;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/index_set.cpp
  requiredBy: []
  timestamp: '2025-03-01 10:35:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/index_set.cpp
layout: document
title: Index Set
---

- $\left\[ 0, n \right\)$ の整数の集合を扱うデータ構造
- 値の追加・削除・存在確認について、最悪時間計算量 $O(1)$、空間計算量 $O(N)$

参考: [https://topcoder-tomerun.hatenablog.jp/entry/2021/06/12/134643](https://topcoder-tomerun.hatenablog.jp/entry/2021/06/12/134643)
