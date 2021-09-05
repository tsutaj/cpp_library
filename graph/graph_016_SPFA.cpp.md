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
  bundledCode: "#line 1 \"graph/graph_016_SPFA.cpp\"\n// Shortest Path Faster Algorithm\
    \ (SPFA)\n// \u5E73\u5747\u8A08\u7B97\u91CF O(|E|)\u3001\u6700\u60AA\u8A08\u7B97\
    \u91CF O(|V||E|)\n// Verified: AOJ GRL_1_A, GRL_1_B\n\n// \u30FB\u9802\u70B9\u304C\
    \u30AD\u30E5\u30FC\u306B\u5165\u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\
    \u3092\u8A18\u61B6\u3059\u308B\u914D\u5217\u304C\u5FC5\u8981\n// \u30FB\u66F4\u65B0\
    \u6642\u306B\u9802\u70B9\u304C\u3059\u3067\u306B\u5165\u3063\u3066\u3044\u308B\
    \u306A\u3089 push \u3057\u306A\u3044\u304C\u3001\u9802\u70B9\u304C\u5165\u3063\
    \u3066\u3044\u306A\u3051\u308C\u3070 push \u3059\u308B\u3060\u3051\n// \u30FB\u8CA0\
    \u9589\u8DEF\u304C\u306A\u3044\u5834\u5408\u3001\u5404\u9802\u70B9\u306B\u5BFE\
    \u3057\u3066\u66F4\u65B0\u306F V-1 \u56DE\u3057\u304B\u8D77\u3053\u3089\u306A\u3044\
    \u304C\u3001\n//   \u8CA0\u9589\u8DEF\u306E\u5834\u5408\u306F\u305D\u308C\u3092\
    \u8D85\u3048\u3066\u66F4\u65B0\u3055\u308C\u308B\u305F\u3081\u3001\u8CA0\u306E\
    \u9589\u8DEF\u306E\u691C\u51FA\u304C\u53EF\u80FD\u3067\u3042\u308B\n// \u30FB\u9802\
    \u70B9 1 \u304B\u3089 N \u307E\u3067\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\
    \u3081\u308B SPFA \u306E\u6700\u60AA\u30B1\u30FC\u30B9\n//   -> \u30E9\u30F3\u30C0\
    \u30E0\u306B\u5927\u304D\u3044\u8FBA\u3092 4N \u672C\u307B\u3069\u5F35\u308B\n\
    //   -> 1 to 2, 2 to 3, ..., N-1 to N \u306B\u30B3\u30B9\u30C8\u306E\u5C0F\u3055\
    \u3044\u8FBA\u3092\u5F35\u308B\n//      (\u8981\u3059\u308B\u306B\u3001\u6700\u77ED\
    \u7D4C\u8DEF\u304C N-1 \u672C\u306E\u8FBA\u304B\u3089\u306A\u308B\u3088\u3046\u306B\
    \u3059\u308B)\n//   -> \u3053\u3046\u3059\u308B\u3053\u3068\u3067\u66F4\u65B0\u304C\
    \u591A\u6570\u8D77\u3053\u308A\u3001O(|V||E|) \u306B\u8FD1\u3065\u304F\u3089\u3057\
    \u3044\n\nvector<int> m(V, 0);\nvector<bool> inq(V, false);\nqueue<int> que;\n\
    vector<int> rec(V, 1 << 30);\nque.push(start);\ninq[start] = true;\nrec[start]\
    \ = 0;\n\nwhile(!que.empty()) {\n    int point = que.front(); que.pop();\n   \
    \ inq[point] = false;\n    for(size_t i=0; i<G[point].size(); i++) {\n       \
    \ Edge<int> next = G[point][i];\n        int to = next.to, cost = next.cost;\n\
    \        if(rec[to] > rec[point] + cost) {\n            rec[to] = rec[point] +\
    \ cost;\n            if(!inq[to]) {\n                /*\n                if(++m[to]\
    \ >= V) {\n                    cout << \"NEGATIVE CYCLE\" << endl;\n         \
    \           return 0;\n                }\n                */\n               \
    \ inq[to] = true;\n                que.push(to);\n            }\n        }\n \
    \   }\n}\n"
  code: "// Shortest Path Faster Algorithm (SPFA)\n// \u5E73\u5747\u8A08\u7B97\u91CF\
    \ O(|E|)\u3001\u6700\u60AA\u8A08\u7B97\u91CF O(|V||E|)\n// Verified: AOJ GRL_1_A,\
    \ GRL_1_B\n\n// \u30FB\u9802\u70B9\u304C\u30AD\u30E5\u30FC\u306B\u5165\u3063\u3066\
    \u3044\u308B\u304B\u3069\u3046\u304B\u3092\u8A18\u61B6\u3059\u308B\u914D\u5217\
    \u304C\u5FC5\u8981\n// \u30FB\u66F4\u65B0\u6642\u306B\u9802\u70B9\u304C\u3059\u3067\
    \u306B\u5165\u3063\u3066\u3044\u308B\u306A\u3089 push \u3057\u306A\u3044\u304C\
    \u3001\u9802\u70B9\u304C\u5165\u3063\u3066\u3044\u306A\u3051\u308C\u3070 push\
    \ \u3059\u308B\u3060\u3051\n// \u30FB\u8CA0\u9589\u8DEF\u304C\u306A\u3044\u5834\
    \u5408\u3001\u5404\u9802\u70B9\u306B\u5BFE\u3057\u3066\u66F4\u65B0\u306F V-1 \u56DE\
    \u3057\u304B\u8D77\u3053\u3089\u306A\u3044\u304C\u3001\n//   \u8CA0\u9589\u8DEF\
    \u306E\u5834\u5408\u306F\u305D\u308C\u3092\u8D85\u3048\u3066\u66F4\u65B0\u3055\
    \u308C\u308B\u305F\u3081\u3001\u8CA0\u306E\u9589\u8DEF\u306E\u691C\u51FA\u304C\
    \u53EF\u80FD\u3067\u3042\u308B\n// \u30FB\u9802\u70B9 1 \u304B\u3089 N \u307E\u3067\
    \u306E\u6700\u77ED\u7D4C\u8DEF\u3092\u6C42\u3081\u308B SPFA \u306E\u6700\u60AA\
    \u30B1\u30FC\u30B9\n//   -> \u30E9\u30F3\u30C0\u30E0\u306B\u5927\u304D\u3044\u8FBA\
    \u3092 4N \u672C\u307B\u3069\u5F35\u308B\n//   -> 1 to 2, 2 to 3, ..., N-1 to\
    \ N \u306B\u30B3\u30B9\u30C8\u306E\u5C0F\u3055\u3044\u8FBA\u3092\u5F35\u308B\n\
    //      (\u8981\u3059\u308B\u306B\u3001\u6700\u77ED\u7D4C\u8DEF\u304C N-1 \u672C\
    \u306E\u8FBA\u304B\u3089\u306A\u308B\u3088\u3046\u306B\u3059\u308B)\n//   -> \u3053\
    \u3046\u3059\u308B\u3053\u3068\u3067\u66F4\u65B0\u304C\u591A\u6570\u8D77\u3053\
    \u308A\u3001O(|V||E|) \u306B\u8FD1\u3065\u304F\u3089\u3057\u3044\n\nvector<int>\
    \ m(V, 0);\nvector<bool> inq(V, false);\nqueue<int> que;\nvector<int> rec(V, 1\
    \ << 30);\nque.push(start);\ninq[start] = true;\nrec[start] = 0;\n\nwhile(!que.empty())\
    \ {\n    int point = que.front(); que.pop();\n    inq[point] = false;\n    for(size_t\
    \ i=0; i<G[point].size(); i++) {\n        Edge<int> next = G[point][i];\n    \
    \    int to = next.to, cost = next.cost;\n        if(rec[to] > rec[point] + cost)\
    \ {\n            rec[to] = rec[point] + cost;\n            if(!inq[to]) {\n  \
    \              /*\n                if(++m[to] >= V) {\n                    cout\
    \ << \"NEGATIVE CYCLE\" << endl;\n                    return 0;\n            \
    \    }\n                */\n                inq[to] = true;\n                que.push(to);\n\
    \            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_016_SPFA.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_016_SPFA.cpp
layout: document
redirect_from:
- /library/graph/graph_016_SPFA.cpp
- /library/graph/graph_016_SPFA.cpp.html
title: graph/graph_016_SPFA.cpp
---
