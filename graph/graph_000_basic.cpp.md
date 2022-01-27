---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/cartesian_tree.cpp
    title: Cartesian Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/tree/cartesian_tree.test.cpp
    title: verifying_test/yosupo/tree/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_000_basic.cpp\"\n// \u79FB\u52D5\u5143\u3068\
    \u884C\u5148\u3068\u8FBA\u306E\u30B3\u30B9\u30C8\u3092\u8A18\u9332\u3059\u308B\
    \u69CB\u9020\u4F53\r\ntemplate <typename T = int>\r\nstruct Edge {\r\n    int\
    \ from, to;\r\n    T cost;\r\n    Edge(int s, T d = 1) : to(s), cost(d) {}\r\n\
    \    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}\r\n\r\n    bool operator<(const\
    \ Edge &e) const {\r\n        return cost < e.cost;\r\n    }\r\n    bool operator>(const\
    \ Edge &e) const {\r\n        return cost > e.cost;\r\n    }\r\n};\r\n\r\ntemplate\
    \ <typename T = int>\r\nusing Graph = vector< vector< Edge<T> > >;\r\n"
  code: "// \u79FB\u52D5\u5143\u3068\u884C\u5148\u3068\u8FBA\u306E\u30B3\u30B9\u30C8\
    \u3092\u8A18\u9332\u3059\u308B\u69CB\u9020\u4F53\r\ntemplate <typename T = int>\r\
    \nstruct Edge {\r\n    int from, to;\r\n    T cost;\r\n    Edge(int s, T d = 1)\
    \ : to(s), cost(d) {}\r\n    Edge(int f, int s, T d) : from(f), to(s), cost(d)\
    \ {}\r\n\r\n    bool operator<(const Edge &e) const {\r\n        return cost <\
    \ e.cost;\r\n    }\r\n    bool operator>(const Edge &e) const {\r\n        return\
    \ cost > e.cost;\r\n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nusing Graph\
    \ = vector< vector< Edge<T> > >;\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_000_basic.cpp
  requiredBy:
  - algorithm/cartesian_tree.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/yosupo/tree/cartesian_tree.test.cpp
documentation_of: graph/graph_000_basic.cpp
layout: document
redirect_from:
- /library/graph/graph_000_basic.cpp
- /library/graph/graph_000_basic.cpp.html
title: graph/graph_000_basic.cpp
---
