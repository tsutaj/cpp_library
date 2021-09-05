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
  bundledCode: "#line 1 \"graph/graph_009_tpsort.cpp\"\n// \u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8 \u5404\u7A2E\r\n\r\n// 2016/12/27 \u8FFD\u8A18\
    : \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\u691C\u67FB\u306F\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\u5BB9\u6613\u306B\u884C\u3048\
    \u308B\u3002\r\n// \u2192 \u9589\u8DEF\u304C\u3042\u308C\u3070\u5165\u6B21\u6570\
    \ 0 \u306B\u306A\u308A\u3048\u306A\u3044\u9802\u70B9\u304C\u5B58\u5728\u3059\u308B\
    \r\n// \u2192 \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3057\u305F\
    \u7D50\u679C\u306E vector \u306E size \u304C\u9802\u70B9\u6570\u3068\u7B49\u3057\
    \u304F\u306A\u3051\u308C\u3070\u9589\u8DEF\u304C\u5B58\u5728\r\n\r\n// Kahn\u306E\
    \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 (Verified: AOJ GRL_4_B: Topological Sort)\r\ntemplate <typename T>\r\
    \nvector<int> tpsort_Kahn(const vector< vector< Edge<T> > > &g) {\r\n    const\
    \ int V = g.size();\r\n    vector<int> indeg(V, 0);\r\n    stack<int> S;\r\n\r\
    \n    for(size_t i=0; i<V; i++) {\r\n        for(size_t j=0; j<g[i].size(); j++)\
    \ {\r\n            indeg[ g[i][j].to ]++;\r\n        }\r\n    }\r\n    for(int\
    \ i=0; i<V; i++) {\r\n        if(indeg[i] == 0) S.push(i);\r\n    }\r\n    \r\n\
    \    vector<int> ans;\r\n    while(S.size() > 0) {\r\n        int u = S.top();\
    \ S.pop();\r\n        ans.push_back(u);\r\n        for(size_t i=0; i<g[u].size();\
    \ i++) {\r\n            indeg[ g[u][i].to ]--;\r\n            if(indeg[ g[u][i].to\
    \ ] ==  0)\r\n                S.push( g[u][i].to );\r\n        }\r\n    }\r\n\
    \    return ans;\r\n}\r\n\r\n// Tarjan\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Verified: AOJ GRL_4_B:\
    \ Topological Sort)\r\ntemplate <typename T>\r\nvoid tpTarjanVisit(const vector<\
    \ vector< Edge<T> > > &g, int u, vector<bool> &used, vector<int> &ans) {\r\n \
    \   if(used[u] == false) {\r\n        used[u] = true;\r\n        for(size_t i=0;\
    \ i<g[u].size(); i++) \r\n            tpTarjanVisit(g, g[u][i].to, used, ans);\r\
    \n        ans.push_back(u);\r\n    }\r\n}\r\n\r\ntemplate <typename T>\r\nvector<int>\
    \ tpsort_Tarjan(const vector< vector< Edge<T> > > &g) {\r\n    const int V = g.size();\r\
    \n    vector<bool> used(V, false);\r\n    vector<int> ans;\r\n    for(int i=0;\
    \ i<V; i++) tpTarjanVisit(g, i, used, ans);\r\n    reverse(ans.begin(), ans.end());\r\
    \n    return ans;\r\n}\r\n\r\n// bit DP \u306B\u3088\u308B\u30C8\u30DD\u30ED\u30B8\
    \u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u7D44\u307F\u5408\u308F\u305B\u5217\u6319\
    \ (ABC041 D)\r\n\r\nint const MAX_N = 16;\r\nvector<int> p[MAX_N];\r\nll dp[1\
    \ << MAX_N];\r\nint N, M;\r\n\r\n// \u524D\u304B\u3089\u9802\u70B9\u306E\u30D1\
    \u30BF\u30FC\u30F3\u3092\u6C7A\u5B9A\u3057\u3066\u3044\u304D\u3001\u7D44\u307F\
    \u5408\u308F\u305B\u306E\u6570\u3092\u8FD4\u3059\r\nll dfs(int x) {\r\n    ll\
    \ &ret = dp[x];\r\n    // \u3059\u3067\u306B\u5024\u304C\u66F8\u304D\u8FBC\u3093\
    \u3067\u3042\u308C\u3070\u305D\u308C\u3092\u8FD4\u3059\r\n    if(ret >= 0) return\
    \ ret;\r\n    // \u6700\u5F8C\u307E\u3067\u3044\u3063\u305F\u30891\u901A\u308A\
    \u3057\u304B\u306A\u3044\r\n    if(x == (1 << N) - 1) return ret = 1;\r\n\r\n\
    \    ret = 0;\r\n    for(int i=0; i<N; i++) {\r\n        // \u307E\u3060\u4F7F\
    \u3063\u3066\u306A\u3044\u9802\u70B9\u3092\u4F7F\u3046\r\n        if(((x >> i)\
    \ & 1) == 0) {\r\n            bool ng = false;\r\n\r\n            // j \u306F\
    \ p[i] \u306E\u4E2D\u306E\u8981\u7D20\r\n            for(int j : p[i]) {\r\n \
    \               // \u9802\u70B9\u96C6\u5408\u306E\u4E2D\u306B\u884C\u5148\u304C\
    \u3059\u3067\u306B\u3042\u308B\u3068\u3044\u3046\u3053\u3068\u306F\u3001\r\n \
    \               // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\
    \u4E00\u756A\u53F3\u306B\u306A\u308A\u3048\u306A\u3044 \u2192 NG\r\n         \
    \       if(((x >> j) & 1) == 0) {\r\n                    ng = true;\r\n      \
    \              break;\r\n                }\r\n            }\r\n            if(ng)\
    \ continue;\r\n\r\n            // \u9802\u70B9 i \u3092\u4F7F\u3063\u305F\u306E\
    \u3067\u3001\u305D\u308C\u3092\u542B\u3081\u305F\u96C6\u5408\u3067 dfs \u3059\u308B\
    \r\n            ret += dfs(x | (1 << i));\r\n        }\r\n    }\r\n    return\
    \ ret;\r\n}\r\n"
  code: "// \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8 \u5404\u7A2E\r\n\
    \r\n// 2016/12/27 \u8FFD\u8A18: \u6709\u5411\u30B0\u30E9\u30D5\u306E\u9589\u8DEF\
    \u691C\u67FB\u306F\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u3067\
    \u5BB9\u6613\u306B\u884C\u3048\u308B\u3002\r\n// \u2192 \u9589\u8DEF\u304C\u3042\
    \u308C\u3070\u5165\u6B21\u6570 0 \u306B\u306A\u308A\u3048\u306A\u3044\u9802\u70B9\
    \u304C\u5B58\u5728\u3059\u308B\r\n// \u2192 \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\
    \u30BD\u30FC\u30C8\u3057\u305F\u7D50\u679C\u306E vector \u306E size \u304C\u9802\
    \u70B9\u6570\u3068\u7B49\u3057\u304F\u306A\u3051\u308C\u3070\u9589\u8DEF\u304C\
    \u5B58\u5728\r\n\r\n// Kahn\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\
    \u30C8\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (Verified: AOJ GRL_4_B: Topological\
    \ Sort)\r\ntemplate <typename T>\r\nvector<int> tpsort_Kahn(const vector< vector<\
    \ Edge<T> > > &g) {\r\n    const int V = g.size();\r\n    vector<int> indeg(V,\
    \ 0);\r\n    stack<int> S;\r\n\r\n    for(size_t i=0; i<V; i++) {\r\n        for(size_t\
    \ j=0; j<g[i].size(); j++) {\r\n            indeg[ g[i][j].to ]++;\r\n       \
    \ }\r\n    }\r\n    for(int i=0; i<V; i++) {\r\n        if(indeg[i] == 0) S.push(i);\r\
    \n    }\r\n    \r\n    vector<int> ans;\r\n    while(S.size() > 0) {\r\n     \
    \   int u = S.top(); S.pop();\r\n        ans.push_back(u);\r\n        for(size_t\
    \ i=0; i<g[u].size(); i++) {\r\n            indeg[ g[u][i].to ]--;\r\n       \
    \     if(indeg[ g[u][i].to ] ==  0)\r\n                S.push( g[u][i].to );\r\
    \n        }\r\n    }\r\n    return ans;\r\n}\r\n\r\n// Tarjan\u306E\u30C8\u30DD\
    \u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \ (Verified: AOJ GRL_4_B: Topological Sort)\r\ntemplate <typename T>\r\nvoid tpTarjanVisit(const\
    \ vector< vector< Edge<T> > > &g, int u, vector<bool> &used, vector<int> &ans)\
    \ {\r\n    if(used[u] == false) {\r\n        used[u] = true;\r\n        for(size_t\
    \ i=0; i<g[u].size(); i++) \r\n            tpTarjanVisit(g, g[u][i].to, used,\
    \ ans);\r\n        ans.push_back(u);\r\n    }\r\n}\r\n\r\ntemplate <typename T>\r\
    \nvector<int> tpsort_Tarjan(const vector< vector< Edge<T> > > &g) {\r\n    const\
    \ int V = g.size();\r\n    vector<bool> used(V, false);\r\n    vector<int> ans;\r\
    \n    for(int i=0; i<V; i++) tpTarjanVisit(g, i, used, ans);\r\n    reverse(ans.begin(),\
    \ ans.end());\r\n    return ans;\r\n}\r\n\r\n// bit DP \u306B\u3088\u308B\u30C8\
    \u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u7D44\u307F\u5408\u308F\
    \u305B\u5217\u6319 (ABC041 D)\r\n\r\nint const MAX_N = 16;\r\nvector<int> p[MAX_N];\r\
    \nll dp[1 << MAX_N];\r\nint N, M;\r\n\r\n// \u524D\u304B\u3089\u9802\u70B9\u306E\
    \u30D1\u30BF\u30FC\u30F3\u3092\u6C7A\u5B9A\u3057\u3066\u3044\u304D\u3001\u7D44\
    \u307F\u5408\u308F\u305B\u306E\u6570\u3092\u8FD4\u3059\r\nll dfs(int x) {\r\n\
    \    ll &ret = dp[x];\r\n    // \u3059\u3067\u306B\u5024\u304C\u66F8\u304D\u8FBC\
    \u3093\u3067\u3042\u308C\u3070\u305D\u308C\u3092\u8FD4\u3059\r\n    if(ret >=\
    \ 0) return ret;\r\n    // \u6700\u5F8C\u307E\u3067\u3044\u3063\u305F\u30891\u901A\
    \u308A\u3057\u304B\u306A\u3044\r\n    if(x == (1 << N) - 1) return ret = 1;\r\n\
    \r\n    ret = 0;\r\n    for(int i=0; i<N; i++) {\r\n        // \u307E\u3060\u4F7F\
    \u3063\u3066\u306A\u3044\u9802\u70B9\u3092\u4F7F\u3046\r\n        if(((x >> i)\
    \ & 1) == 0) {\r\n            bool ng = false;\r\n\r\n            // j \u306F\
    \ p[i] \u306E\u4E2D\u306E\u8981\u7D20\r\n            for(int j : p[i]) {\r\n \
    \               // \u9802\u70B9\u96C6\u5408\u306E\u4E2D\u306B\u884C\u5148\u304C\
    \u3059\u3067\u306B\u3042\u308B\u3068\u3044\u3046\u3053\u3068\u306F\u3001\r\n \
    \               // \u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\
    \u4E00\u756A\u53F3\u306B\u306A\u308A\u3048\u306A\u3044 \u2192 NG\r\n         \
    \       if(((x >> j) & 1) == 0) {\r\n                    ng = true;\r\n      \
    \              break;\r\n                }\r\n            }\r\n            if(ng)\
    \ continue;\r\n\r\n            // \u9802\u70B9 i \u3092\u4F7F\u3063\u305F\u306E\
    \u3067\u3001\u305D\u308C\u3092\u542B\u3081\u305F\u96C6\u5408\u3067 dfs \u3059\u308B\
    \r\n            ret += dfs(x | (1 << i));\r\n        }\r\n    }\r\n    return\
    \ ret;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_009_tpsort.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_009_tpsort.cpp
layout: document
redirect_from:
- /library/graph/graph_009_tpsort.cpp
- /library/graph/graph_009_tpsort.cpp.html
title: graph/graph_009_tpsort.cpp
---
