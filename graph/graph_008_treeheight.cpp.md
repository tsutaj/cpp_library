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
  bundledCode: "#line 1 \"graph/graph_008_treeheight.cpp\"\n// \u6728\u306E\u9AD8\u3055\
    \u3092\u6C42\u3081\u308B\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 O(E log |V|)\n//\
    \ \u3042\u308B\u9802\u70B9\u306B\u5BFE\u3057\u3066\u6700\u9060\u306E\u9802\u70B9\
    \u306F\u3001\u6728\u306E\u76F4\u5F84\u3068\u306A\u308B\u4E21\u9802\u70B9\u306E\
    \u3046\u3061\u3001\n// \u3042\u308B\u9802\u70B9\u304B\u3089\u306E\u8DDD\u96E2\u304C\
    \u5927\u304D\u3044\u65B9\u3068\u306A\u308B\n\n// \u2192 \u6728\u306E\u76F4\u5F84\
    \u3068\u306A\u308B\u30D1\u30B9\u306F\u5FC5\u305A\u6728\u306E\u4E2D\u5FC3\u3092\
    \u901A\u308B\u306E\u3067\u3001\u4E2D\u5FC3\u3092\u6839\u3068\u3059\u308B\u6839\
    \u4ED8\u304D\u6728\u3092\u8003\u3048\u305F\u6642\u306B\u3001\n// \u6728\u306E\u9AD8\
    \u3055\u306F\u3001\u300C\u4E2D\u5FC3\u307E\u3067\u767B\u308A\u3001\u3042\u308B\
    \u9802\u70B9\u304C\u5C5E\u3057\u3066\u3044\u306A\u3044\u65B9\u306E\u90E8\u5206\
    \u6728\u3092\u4E0B\u308B\u300D\u304B\n// \u300C\u3042\u308B\u9802\u70B9\u304C\u5C5E\
    \u3057\u3066\u3044\u308B\u306E\u65B9\u306E\u90E8\u5206\u6728\u3092\u4E0B\u308B\
    \u300D\u307B\u3046\u306E\u3069\u3061\u3089\u304B\u3068\u306A\u308B\u3002\n\n//\
    \ \u2192 \u3057\u305F\u304C\u3063\u3066\u3001\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u30923\u56DE\u56DE\u305B\u3070\u6728\u306E\u9AD8\u3055\u304C\u6C42\u3081\u3089\
    \u308C\u308B\u3002\n\ntemplate <typename T>\nvector<T> treeHeight(vector< vector<\
    \ Edge<T> > > &G) {\n    int n = G.size();\n    vector<T> v1, v2, v3, ret(n);\n\
    \    int p1, p2;\n    v1 = dijkstra<T>(G, 0);\n    p1 = max_element(v1.begin(),\
    \ v1.end()) - v1.begin();\n\n    v2 = dijkstra<T>(G, p1);\n    p2 = max_element(v2.begin(),\
    \ v2.end()) - v2.begin();\n\n    v3 = dijkstra<T>(G, p2);\n    for(int i=0; i<n;\
    \ i++) ret[i] = max(v2[i], v3[i]);\n    return ret;\n}\n"
  code: "// \u6728\u306E\u9AD8\u3055\u3092\u6C42\u3081\u308B\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 O(E log |V|)\n// \u3042\u308B\u9802\u70B9\u306B\u5BFE\u3057\u3066\
    \u6700\u9060\u306E\u9802\u70B9\u306F\u3001\u6728\u306E\u76F4\u5F84\u3068\u306A\
    \u308B\u4E21\u9802\u70B9\u306E\u3046\u3061\u3001\n// \u3042\u308B\u9802\u70B9\u304B\
    \u3089\u306E\u8DDD\u96E2\u304C\u5927\u304D\u3044\u65B9\u3068\u306A\u308B\n\n//\
    \ \u2192 \u6728\u306E\u76F4\u5F84\u3068\u306A\u308B\u30D1\u30B9\u306F\u5FC5\u305A\
    \u6728\u306E\u4E2D\u5FC3\u3092\u901A\u308B\u306E\u3067\u3001\u4E2D\u5FC3\u3092\
    \u6839\u3068\u3059\u308B\u6839\u4ED8\u304D\u6728\u3092\u8003\u3048\u305F\u6642\
    \u306B\u3001\n// \u6728\u306E\u9AD8\u3055\u306F\u3001\u300C\u4E2D\u5FC3\u307E\u3067\
    \u767B\u308A\u3001\u3042\u308B\u9802\u70B9\u304C\u5C5E\u3057\u3066\u3044\u306A\
    \u3044\u65B9\u306E\u90E8\u5206\u6728\u3092\u4E0B\u308B\u300D\u304B\n// \u300C\u3042\
    \u308B\u9802\u70B9\u304C\u5C5E\u3057\u3066\u3044\u308B\u306E\u65B9\u306E\u90E8\
    \u5206\u6728\u3092\u4E0B\u308B\u300D\u307B\u3046\u306E\u3069\u3061\u3089\u304B\
    \u3068\u306A\u308B\u3002\n\n// \u2192 \u3057\u305F\u304C\u3063\u3066\u3001\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u30923\u56DE\u56DE\u305B\u3070\u6728\u306E\u9AD8\
    \u3055\u304C\u6C42\u3081\u3089\u308C\u308B\u3002\n\ntemplate <typename T>\nvector<T>\
    \ treeHeight(vector< vector< Edge<T> > > &G) {\n    int n = G.size();\n    vector<T>\
    \ v1, v2, v3, ret(n);\n    int p1, p2;\n    v1 = dijkstra<T>(G, 0);\n    p1 =\
    \ max_element(v1.begin(), v1.end()) - v1.begin();\n\n    v2 = dijkstra<T>(G, p1);\n\
    \    p2 = max_element(v2.begin(), v2.end()) - v2.begin();\n\n    v3 = dijkstra<T>(G,\
    \ p2);\n    for(int i=0; i<n; i++) ret[i] = max(v2[i], v3[i]);\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_008_treeheight.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_008_treeheight.cpp
layout: document
redirect_from:
- /library/graph/graph_008_treeheight.cpp
- /library/graph/graph_008_treeheight.cpp.html
title: graph/graph_008_treeheight.cpp
---
