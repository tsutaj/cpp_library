---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/union_find.cpp
    title: Union-Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp
  bundledCode: "#line 1 \"verifying_test/AOJ/DSL_1_A/union_find.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp\"\
    \n\n#include <cstdio>\nusing namespace std;\n\n#define call_from_test\n#line 2\
    \ \"structure/union_find.cpp\"\n\r\n/**\r\n * @brief Union-Find\r\n * @docs ./docs/union_find.md\r\
    \n */\r\n\r\n#include <algorithm>\r\n#include <vector>\r\n\r\nstruct UnionFind\
    \ {\r\nprivate:\r\n    const int n;\r\n    int size_;\r\n    vector<int> uf;\r\
    \npublic:\r\n    // \u521D\u671F\u5316 UnionFind uni(n) \u306E\u3088\u3046\u306B\
    \u5BA3\u8A00\u3059\u308C\u3070\u826F\u3044\r\n    UnionFind(int _n) : n(_n), size_(_n),\
    \ uf(_n, -1) {}\r\n    // find (\u6728\u306E\u6839\u3092\u6C42\u3081\u308B)\r\n\
    \    int find(int x) {return (uf[x] < 0) ? x : uf[x] = find(uf[x]);}\r\n    //\
    \ x \u3068 y \u304C\u540C\u3058\u96C6\u5408\u306B\u5C5E\u3059\u308B\u304B\u3069\
    \u3046\u304B\r\n    bool same(int x, int y) {return find(x) == find(y);}\r\n \
    \   // x \u304C\u5C5E\u3059\u308B\u96C6\u5408\u306E\u8981\u7D20\u6570\r\n    int\
    \ size(int x) {return -uf[find(x)];}\r\n    // \u96C6\u5408\u306F\u3044\u304F\u3064\
    \u3042\u308B\u304B\r\n    int size()      {return size_;}\r\n    // x \u3068 y\
    \ \u306E\u5C5E\u3059\u308B\u96C6\u5408\u3092\u4F75\u5408\r\n    bool unite(int\
    \ x, int y) {\r\n        x = find(x); y = find(y);\r\n        if(x == y) return\
    \ false;\r\n        size_--;\r\n        if(-uf[x] < -uf[y]) swap(x, y);\r\n  \
    \      uf[x] += uf[y]; uf[y] = x;\r\n        return true;\r\n    }\r\n};\r\n#line\
    \ 8 \"verifying_test/AOJ/DSL_1_A/union_find.test.cpp\"\n#undef call_from_test\n\
    \nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    UnionFind uf(N);\n\
    \    while(Q--) {\n        int t; scanf(\"%d\", &t);\n        int x, y; scanf(\"\
    %d%d\", &x, &y);\n        if(t == 0) {\n            uf.unite(x, y);\n        }\n\
    \        if(t == 1) {\n            printf(\"%d\\n\", uf.same(x, y) ? 1 : 0);\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A&lang=jp\"\
    \n\n#include <cstdio>\nusing namespace std;\n\n#define call_from_test\n#include\
    \ \"../../../structure/union_find.cpp\"\n#undef call_from_test\n\nint main() {\n\
    \    int N, Q; scanf(\"%d%d\", &N, &Q);\n    UnionFind uf(N);\n    while(Q--)\
    \ {\n        int t; scanf(\"%d\", &t);\n        int x, y; scanf(\"%d%d\", &x,\
    \ &y);\n        if(t == 0) {\n            uf.unite(x, y);\n        }\n       \
    \ if(t == 1) {\n            printf(\"%d\\n\", uf.same(x, y) ? 1 : 0);\n      \
    \  }\n    }\n}\n"
  dependsOn:
  - structure/union_find.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/DSL_1_A/union_find.test.cpp
  requiredBy: []
  timestamp: '2020-04-10 01:41:38+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AOJ/DSL_1_A/union_find.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/DSL_1_A/union_find.test.cpp
- /verify/verifying_test/AOJ/DSL_1_A/union_find.test.cpp.html
title: verifying_test/AOJ/DSL_1_A/union_find.test.cpp
---
