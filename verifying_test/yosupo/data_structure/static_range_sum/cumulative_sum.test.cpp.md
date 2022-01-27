---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/cumulative_sum.cpp
    title: "1 \u6B21\u5143\u7D2F\u7A4D\u548C (1 Dimension Cumulative Sum)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_sum
    links:
    - https://judge.yosupo.jp/problem/static_range_sum
  bundledCode: "#line 1 \"verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <cstdio>\n#include <vector>\n#include <algorithm>\n#include <functional>\nusing\
    \ ll = long long int;\nusing namespace std;\n\n#define call_from_test\n#line 2\
    \ \"algorithm/cumulative_sum.cpp\"\n\n/**\n * @brief 1 \u6B21\u5143\u7D2F\u7A4D\
    \u548C (1 Dimension Cumulative Sum)\n * @docs docs/algorithm/cumulative_sum.md\n\
    \ */\n\n#line 10 \"algorithm/cumulative_sum.cpp\"\ntemplate <typename MonoidType>\n\
    struct CumulativeSum {\n    int n;\n    vector<MonoidType> pre, suf;\n    MonoidType\
    \ E;\n    \n    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;\n\
    \    MMtoM op, rop;\n\n    void accumulate() {\n        int m = pre.size();\n\
    \        for(int i=0; i+1<m; i++) {\n            pre[i+1] = op(pre[i+1], pre[i]);\n\
    \        }\n        for(int i=m-2; i>=0; i--) {\n            suf[i] = op(suf[i],\
    \ suf[i+1]);\n        }\n    }\n\n    CumulativeSum() {}\n    CumulativeSum(vector<MonoidType>\
    \ val_array, MonoidType E_,\n                  MMtoM op_, MMtoM rop_ = MMtoM(),\n\
    \                  bool need_accumulate = true) :\n        E(E_), op(op_), rop(rop_)\
    \ {\n        n = val_array.size();\n        pre = suf = vector<MonoidType>(n+2,\
    \ E);\n        for(int i=0; i<n; i++) pre[i+1] = suf[i+1] = val_array[i];\n  \
    \      if(need_accumulate) accumulate();\n    }\n\n    void range_apply(int l,\
    \ int r, MonoidType val) {\n        pre[l+1] = op(pre[l+1], val);\n        pre[r+1]\
    \ = rop(pre[r+1], val);\n        suf[r] = op(suf[r], val);\n        suf[l] = rop(suf[l],\
    \ val);\n    }\n\n    // [0, k)\n    inline MonoidType get_prefix(int k) { return\
    \ 0 <= k and k <= n ? pre[k] : E; }\n    // [k, n)\n    inline MonoidType get_suffix(int\
    \ k) { return 0 <= k+1 and k+1 <= n ? suf[k+1] : E; }\n    // [l, r) (rop \u304C\
    \u5B9A\u7FA9\u3055\u308C\u3066\u308B\u3068\u304D\u306E\u307F)\n    inline MonoidType\
    \ get_subseq(int l, int r) {\n        return rop(get_prefix(r), get_prefix(l));\n\
    \    }\n};\n#line 11 \"verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp\"\
    \n#undef call_from_test\n\nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n\
    \    vector<ll> A(N);\n    for(auto &e : A) scanf(\"%lld\", &e);\n\n    CumulativeSum<ll>\
    \ cumsum(A, 0,\n                             [](ll a, ll b) { return a + b; },\n\
    \                             [](ll a, ll b) { return a - b; });\n    while(Q--)\
    \ {\n        int l, r; scanf(\"%d%d\", &l, &r);\n        printf(\"%lld\\n\", cumsum.get_subseq(l,\
    \ r));\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_sum\"\n#include\
    \ <cstdio>\n#include <vector>\n#include <algorithm>\n#include <functional>\nusing\
    \ ll = long long int;\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../../../algorithm/cumulative_sum.cpp\"\n#undef call_from_test\n\nint main()\
    \ {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    vector<ll> A(N);\n    for(auto\
    \ &e : A) scanf(\"%lld\", &e);\n\n    CumulativeSum<ll> cumsum(A, 0,\n       \
    \                      [](ll a, ll b) { return a + b; },\n                   \
    \          [](ll a, ll b) { return a - b; });\n    while(Q--) {\n        int l,\
    \ r; scanf(\"%d%d\", &l, &r);\n        printf(\"%lld\\n\", cumsum.get_subseq(l,\
    \ r));\n    }\n    return 0;\n}\n"
  dependsOn:
  - algorithm/cumulative_sum.cpp
  isVerificationFile: true
  path: verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp
  requiredBy: []
  timestamp: '2022-01-28 02:17:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp
- /verify/verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp.html
title: verifying_test/yosupo/data_structure/static_range_sum/cumulative_sum.test.cpp
---
