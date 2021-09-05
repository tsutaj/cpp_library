---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/coordinate_compression.cpp
    title: "\u5EA7\u6A19\u5727\u7E2E (Coordinate Compression)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/associative_array
    links:
    - https://judge.yosupo.jp/problem/associative_array
  bundledCode: "#line 1 \"verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <cstdio>\n#include\
    \ <tuple>\n#include <utility>\nusing ll = long long int;\nusing namespace std;\n\
    \n#define call_from_test\n#line 2 \"algorithm/coordinate_compression.cpp\"\n\n\
    // @brief \u5EA7\u6A19\u5727\u7E2E (Coordinate Compression)\n\n#line 8 \"algorithm/coordinate_compression.cpp\"\
    \n\ntemplate <typename Tp>\nstruct coor_comp {\nprivate:\n    vector<Tp> vec;\n\
    \npublic:\n    coor_comp() : vec() {}\n    coor_comp(int n) : vec() { vec.reserve(n);\
    \ }\n    coor_comp(const vector<Tp> &vec_) : vec(vec_) { build(); }\n\n    size_t\
    \ size() const {\n        return vec.size();\n    }\n    \n    void emplace_back(Tp\
    \ value) {\n        vec.emplace_back(value);\n    }\n\n    void build() {\n  \
    \      sort(vec.begin(), vec.end());\n        vec.erase(unique(vec.begin(), vec.end()),\
    \ vec.end());\n    }\n       \n    int operator[](const Tp &value) const {\n \
    \       auto itr = lower_bound(vec.begin(), vec.end(), value);\n        assert(itr\
    \ != vec.end() and *itr == value);\n        return itr - vec.begin();\n    }\n\
    \n    vector<int> compress(const vector<Tp> &A) {\n        vector<int> comp_vec(A.size());\n\
    \        for(size_t i=0; i<A.size(); i++) comp_vec[i] = (*this)[ A[i] ];\n   \
    \     return comp_vec;\n    }\n};\n#line 13 \"verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int Q; scanf(\"%d\", &Q);\n    vector<\
    \ tuple<ll, ll, ll> > queries(Q);\n    vector<ll> indices(Q);\n    for(int i=0;\
    \ i<Q; i++) {\n        ll t, k, v=-1; scanf(\"%lld\", &t);\n        if(t == 0)\
    \ {\n            scanf(\"%lld%lld\", &k, &v);\n        }\n        if(t == 1) {\n\
    \            scanf(\"%lld\", &k);\n        }\n        queries[i] = make_tuple(t,\
    \ k, v);\n        indices[i] = k;\n    }\n\n    coor_comp<ll> comp(indices);\n\
    \    vector<ll> rec(comp.size());\n    for(int i=0; i<Q; i++) {\n        ll t,\
    \ k, v; tie(t, k, v) = queries[i];\n        if(t == 0) {\n            rec[ comp[k]\
    \ ] = v;\n        }\n        if(t == 1) {\n            printf(\"%lld\\n\", rec[\
    \ comp[k] ]);\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/associative_array\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <cassert>\n#include <cstdio>\n#include\
    \ <tuple>\n#include <utility>\nusing ll = long long int;\nusing namespace std;\n\
    \n#define call_from_test\n#include \"../../../../algorithm/coordinate_compression.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int Q; scanf(\"%d\", &Q);\n    vector<\
    \ tuple<ll, ll, ll> > queries(Q);\n    vector<ll> indices(Q);\n    for(int i=0;\
    \ i<Q; i++) {\n        ll t, k, v=-1; scanf(\"%lld\", &t);\n        if(t == 0)\
    \ {\n            scanf(\"%lld%lld\", &k, &v);\n        }\n        if(t == 1) {\n\
    \            scanf(\"%lld\", &k);\n        }\n        queries[i] = make_tuple(t,\
    \ k, v);\n        indices[i] = k;\n    }\n\n    coor_comp<ll> comp(indices);\n\
    \    vector<ll> rec(comp.size());\n    for(int i=0; i<Q; i++) {\n        ll t,\
    \ k, v; tie(t, k, v) = queries[i];\n        if(t == 0) {\n            rec[ comp[k]\
    \ ] = v;\n        }\n        if(t == 1) {\n            printf(\"%lld\\n\", rec[\
    \ comp[k] ]);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - algorithm/coordinate_compression.cpp
  isVerificationFile: true
  path: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
  requiredBy: []
  timestamp: '2020-06-20 01:16:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
- /verify/verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp.html
title: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp
---
