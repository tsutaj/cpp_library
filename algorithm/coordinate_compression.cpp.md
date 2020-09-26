---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
    title: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5EA7\u6A19\u5727\u7E2E (Coordinate Compression)"
    links: []
  bundledCode: "#line 2 \"algorithm/coordinate_compression.cpp\"\n\n// @brief \u5EA7\
    \u6A19\u5727\u7E2E (Coordinate Compression)\n\n#include <vector>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <typename Tp>\nstruct coor_comp {\nprivate:\n \
    \   vector<Tp> vec;\n\npublic:\n    coor_comp() : vec() {}\n    coor_comp(int\
    \ n) : vec() { vec.reserve(n); }\n    coor_comp(const vector<Tp> &vec_) : vec(vec_)\
    \ { build(); }\n\n    size_t size() const {\n        return vec.size();\n    }\n\
    \    \n    void emplace_back(Tp value) {\n        vec.emplace_back(value);\n \
    \   }\n\n    void build() {\n        sort(vec.begin(), vec.end());\n        vec.erase(unique(vec.begin(),\
    \ vec.end()), vec.end());\n    }\n       \n    int operator[](const Tp &value)\
    \ const {\n        auto itr = lower_bound(vec.begin(), vec.end(), value);\n  \
    \      assert(itr != vec.end() and *itr == value);\n        return itr - vec.begin();\n\
    \    }\n\n    vector<int> compress(const vector<Tp> &A) {\n        vector<int>\
    \ comp_vec(A.size());\n        for(size_t i=0; i<A.size(); i++) comp_vec[i] =\
    \ (*this)[ A[i] ];\n        return comp_vec;\n    }\n};\n"
  code: "#pragma once\n\n// @brief \u5EA7\u6A19\u5727\u7E2E (Coordinate Compression)\n\
    \n#include <vector>\n#include <algorithm>\n#include <cassert>\n\ntemplate <typename\
    \ Tp>\nstruct coor_comp {\nprivate:\n    vector<Tp> vec;\n\npublic:\n    coor_comp()\
    \ : vec() {}\n    coor_comp(int n) : vec() { vec.reserve(n); }\n    coor_comp(const\
    \ vector<Tp> &vec_) : vec(vec_) { build(); }\n\n    size_t size() const {\n  \
    \      return vec.size();\n    }\n    \n    void emplace_back(Tp value) {\n  \
    \      vec.emplace_back(value);\n    }\n\n    void build() {\n        sort(vec.begin(),\
    \ vec.end());\n        vec.erase(unique(vec.begin(), vec.end()), vec.end());\n\
    \    }\n       \n    int operator[](const Tp &value) const {\n        auto itr\
    \ = lower_bound(vec.begin(), vec.end(), value);\n        assert(itr != vec.end()\
    \ and *itr == value);\n        return itr - vec.begin();\n    }\n\n    vector<int>\
    \ compress(const vector<Tp> &A) {\n        vector<int> comp_vec(A.size());\n \
    \       for(size_t i=0; i<A.size(); i++) comp_vec[i] = (*this)[ A[i] ];\n    \
    \    return comp_vec;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/coordinate_compression.cpp
  requiredBy: []
  timestamp: '2020-06-20 01:16:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
documentation_of: algorithm/coordinate_compression.cpp
layout: document
redirect_from:
- /library/algorithm/coordinate_compression.cpp
- /library/algorithm/coordinate_compression.cpp.html
title: "\u5EA7\u6A19\u5727\u7E2E (Coordinate Compression)"
---
