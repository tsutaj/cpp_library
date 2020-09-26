---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_019_eulertour.cpp\"\n// Euler-tour (Verified:\
    \ Codeforces Round #225 Div.1: Propagating Tree)\n// \u9802\u70B9 i \u3092\u6839\
    \u3068\u3057\u305F\u90E8\u5206\u6728\u306E\u60C5\u5831\u306F [ etbegin[i], etend[i]\
    \ ) \u3092\u53C2\u7167\nconstexpr int MAXN = 200010;\nvector<int> G[MAXN];\nint\
    \ k=0, euler_tour[2*MAXN], etbegin[MAXN], etend[MAXN];\n\n// usage: make_et(root)\n\
    void make_et(int v, int par=-1) {\n    euler_tour[k] = v;\n    etbegin[v] = k++;\n\
    \    for(size_t i=0; i<G[v].size(); i++) {\n        int to = G[v][i];\n      \
    \  if(to == par) continue;\n        make_et(to, v);\n        euler_tour[k++] =\
    \ v;\n    }\n    etend[v] = k;\n}\n"
  code: "// Euler-tour (Verified: Codeforces Round #225 Div.1: Propagating Tree)\n\
    // \u9802\u70B9 i \u3092\u6839\u3068\u3057\u305F\u90E8\u5206\u6728\u306E\u60C5\
    \u5831\u306F [ etbegin[i], etend[i] ) \u3092\u53C2\u7167\nconstexpr int MAXN =\
    \ 200010;\nvector<int> G[MAXN];\nint k=0, euler_tour[2*MAXN], etbegin[MAXN], etend[MAXN];\n\
    \n// usage: make_et(root)\nvoid make_et(int v, int par=-1) {\n    euler_tour[k]\
    \ = v;\n    etbegin[v] = k++;\n    for(size_t i=0; i<G[v].size(); i++) {\n   \
    \     int to = G[v][i];\n        if(to == par) continue;\n        make_et(to,\
    \ v);\n        euler_tour[k++] = v;\n    }\n    etend[v] = k;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_019_eulertour.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_019_eulertour.cpp
layout: document
redirect_from:
- /library/graph/graph_019_eulertour.cpp
- /library/graph/graph_019_eulertour.cpp.html
title: graph/graph_019_eulertour.cpp
---
