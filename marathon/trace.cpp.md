---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/1227/trace.test.cpp
    title: verifying_test/AOJ/1227/trace.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"marathon/trace.cpp\"\ntemplate <typename Tp>\nclass Trace\
    \ {\npublic:\n    Trace() = default;\n\n    int add(const Tp& value, int parent)\
    \ {\n        log_.emplace_back(value, parent);\n        return (int)log_.size()\
    \ - 1;\n    }\n\n    vector<Tp> get(int index) const {\n        vector<Tp> result;\n\
    \        while (index >= 0) {\n            result.emplace_back(log_[index].first);\n\
    \            index = log_[index].second;\n        }\n        reverse(result.begin(),\
    \ result.end());\n        return result;\n    }\n\nprivate:\n    vector<pair<Tp,\
    \ int>> log_;\n};\n"
  code: "template <typename Tp>\nclass Trace {\npublic:\n    Trace() = default;\n\n\
    \    int add(const Tp& value, int parent) {\n        log_.emplace_back(value,\
    \ parent);\n        return (int)log_.size() - 1;\n    }\n\n    vector<Tp> get(int\
    \ index) const {\n        vector<Tp> result;\n        while (index >= 0) {\n \
    \           result.emplace_back(log_[index].first);\n            index = log_[index].second;\n\
    \        }\n        reverse(result.begin(), result.end());\n        return result;\n\
    \    }\n\nprivate:\n    vector<pair<Tp, int>> log_;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/trace.cpp
  requiredBy: []
  timestamp: '2025-10-19 18:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/1227/trace.test.cpp
documentation_of: marathon/trace.cpp
layout: document
title: "Trace\uFF08\u7D4C\u8DEF\u5FA9\u5143\uFF09"
---

- `add(value, id)`
  - 採用した値 `value` と直前の状態の識別子 `id` を与えて、状態を追加する
  - 追加した状態の識別子が返ってくる
- `get(id)`
  - 状態の識別子 `id` を与えると、初期状態からここに至るまでの経路を復元したものが返ってくる
