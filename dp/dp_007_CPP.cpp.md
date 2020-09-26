---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_007_CPP.cpp\"\n// \u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\
    \u9054\u554F\u984C (\u91CD\u307F\u4ED8\u304D\u7121\u5411\u30B0\u30E9\u30D5\u306B\
    \u3064\u3044\u3066\u3001\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\
    \u77ED\u7D4C\u8DEF\u306E\u8DDD\u96E2)\n// \u30FB\u3042\u308B\u9802\u70B9\u304B\
    \u3089\u51FA\u767A\u3057\u3001\u51FA\u767A\u70B9\u3078\u623B\u308B\u9589\u8DEF\
    \n// \u30FB\u5404\u8FBA\u3092\u5C11\u306A\u304F\u3068\u3082 1 \u5EA6\u306F\u901A\
    \u308B\n// -> \u30AA\u30A4\u30E9\u30FC\u9589\u8DEF (\u30B0\u30E9\u30D5\u4E2D\u306E\
    \u3059\u3079\u3066\u306E\u8FBA\u3092 1 \u5EA6\u305A\u3064\u901A\u308B\u3088\u3046\
    \u306A\u9589\u8DEF) \u3092\u6301\u3064\u3088\u3046\u306B\n//    \u30B0\u30E9\u30D5\
    \u3092\u5909\u5F62\u3059\u308B\u3002\u30AA\u30A4\u30E9\u30FC\u9589\u8DEF\u3092\
    \u6301\u3064\u306A\u3089\u3070\u3001\u5168\u3066\u306E\u9802\u70B9\u306E\u6B21\
    \u6570\u304C\u5076\u6570\u3067\u3042\u308B\u3002\n//    \u3088\u3063\u3066\u3001\
    \u6B21\u6570\u304C\u5947\u6570\u3067\u3042\u308B\u4EFB\u610F\u306E 2 \u9802\u70B9\
    \u306B\u8FBA\u3092\u5F35\u308A (\u91CD\u307F\u306F\u5143\u306E\u30B0\u30E9\u30D5\
    \u306B\u304A\u3051\u308B\u6700\u77ED\u7D4C\u8DEF)\n//    \u4E00\u822C\u30DE\u30C3\
    \u30C1\u30F3\u30B0\u3092\u884C\u3048\u3070\u3088\u3044\u3002\u4E00\u822C\u30DE\
    \u30C3\u30C1\u30F3\u30B0\u306B\u306F bit DP \u3092\u7528\u3044\u308B\u3002\n//\
    \    \u7B54\u3048\u306F\u3001\u5143\u306E\u30B0\u30E9\u30D5\u306E\u5168\u3066\u306E\
    \u8FBA\u306E\u91CD\u307F\u7DCF\u548C + \u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\
    \u306E\u7D50\u679C \u3068\u306A\u308B\u3002\n// Verified: AOJ DPL_2_B: Chinese\
    \ Postman Problem (\u591A\u91CD\u8FBA\u306B\u6CE8\u610F\uFF01\uFF01\uFF01)\n\n\
    // (to, cost)\nvector<pii> G[20];\nint deg[20], dist[20][20], w[20][20], dp[1\
    \ << 15];\n\nvoid solve() {\n    int total = 0;\n    int V, E; cin >> V >> E;\n\
    \    rep(i,0,V) rep(j,0,V) {\n        if(i == j) dist[i][j] = 0;\n        else\
    \ dist[i][j] = INF;\n    }\n    rep(i,0,E) {\n        int s, t, d; cin >> s >>\
    \ t >> d;\n        G[s].push_back(pii(t, d));\n        G[t].push_back(pii(s, d));\n\
    \        chmin(dist[s][t], d);\n        chmin(dist[t][s], d);\n        total +=\
    \ d;\n        deg[s]++; deg[t]++;\n    }\n\n    vector<int> odds;\n    rep(i,0,V)\
    \ if(deg[i] % 2) odds.push_back(i);\n    int M = odds.size();\n\n    rep(k,0,V)\
    \ rep(i,0,V) rep(j,0,V) {\n        chmin(dist[i][j], dist[i][k] + dist[k][j]);\n\
    \    }\n    rep(i,0,M) rep(j,0,M) w[i][j] = dist[ odds[i] ][ odds[j] ];\n\n  \
    \  rep(i,1,1<<M) dp[i] = INF;\n    rep(bit,0,1<<M) rep(i,0,M) rep(j,i+1,M) {\n\
    \        if((bit >> i & 1) || (bit >> j & 1)) continue;\n        chmin(dp[bit\
    \ | (1 << i) | (1 << j)], dp[bit] + w[i][j]);\n    }\n    cout << total + dp[(1<<M)-1]\
    \ << endl;\n}\n"
  code: "// \u4E2D\u56FD\u4EBA\u90F5\u4FBF\u914D\u9054\u554F\u984C (\u91CD\u307F\u4ED8\
    \u304D\u7121\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u6B21\u306E\
    \u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u77ED\u7D4C\u8DEF\u306E\u8DDD\u96E2\
    )\n// \u30FB\u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u767A\u3057\u3001\u51FA\
    \u767A\u70B9\u3078\u623B\u308B\u9589\u8DEF\n// \u30FB\u5404\u8FBA\u3092\u5C11\u306A\
    \u304F\u3068\u3082 1 \u5EA6\u306F\u901A\u308B\n// -> \u30AA\u30A4\u30E9\u30FC\u9589\
    \u8DEF (\u30B0\u30E9\u30D5\u4E2D\u306E\u3059\u3079\u3066\u306E\u8FBA\u3092 1 \u5EA6\
    \u305A\u3064\u901A\u308B\u3088\u3046\u306A\u9589\u8DEF) \u3092\u6301\u3064\u3088\
    \u3046\u306B\n//    \u30B0\u30E9\u30D5\u3092\u5909\u5F62\u3059\u308B\u3002\u30AA\
    \u30A4\u30E9\u30FC\u9589\u8DEF\u3092\u6301\u3064\u306A\u3089\u3070\u3001\u5168\
    \u3066\u306E\u9802\u70B9\u306E\u6B21\u6570\u304C\u5076\u6570\u3067\u3042\u308B\
    \u3002\n//    \u3088\u3063\u3066\u3001\u6B21\u6570\u304C\u5947\u6570\u3067\u3042\
    \u308B\u4EFB\u610F\u306E 2 \u9802\u70B9\u306B\u8FBA\u3092\u5F35\u308A (\u91CD\u307F\
    \u306F\u5143\u306E\u30B0\u30E9\u30D5\u306B\u304A\u3051\u308B\u6700\u77ED\u7D4C\
    \u8DEF)\n//    \u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\u3092\u884C\u3048\u3070\
    \u3088\u3044\u3002\u4E00\u822C\u30DE\u30C3\u30C1\u30F3\u30B0\u306B\u306F bit DP\
    \ \u3092\u7528\u3044\u308B\u3002\n//    \u7B54\u3048\u306F\u3001\u5143\u306E\u30B0\
    \u30E9\u30D5\u306E\u5168\u3066\u306E\u8FBA\u306E\u91CD\u307F\u7DCF\u548C + \u4E00\
    \u822C\u30DE\u30C3\u30C1\u30F3\u30B0\u306E\u7D50\u679C \u3068\u306A\u308B\u3002\
    \n// Verified: AOJ DPL_2_B: Chinese Postman Problem (\u591A\u91CD\u8FBA\u306B\u6CE8\
    \u610F\uFF01\uFF01\uFF01)\n\n// (to, cost)\nvector<pii> G[20];\nint deg[20], dist[20][20],\
    \ w[20][20], dp[1 << 15];\n\nvoid solve() {\n    int total = 0;\n    int V, E;\
    \ cin >> V >> E;\n    rep(i,0,V) rep(j,0,V) {\n        if(i == j) dist[i][j] =\
    \ 0;\n        else dist[i][j] = INF;\n    }\n    rep(i,0,E) {\n        int s,\
    \ t, d; cin >> s >> t >> d;\n        G[s].push_back(pii(t, d));\n        G[t].push_back(pii(s,\
    \ d));\n        chmin(dist[s][t], d);\n        chmin(dist[t][s], d);\n       \
    \ total += d;\n        deg[s]++; deg[t]++;\n    }\n\n    vector<int> odds;\n \
    \   rep(i,0,V) if(deg[i] % 2) odds.push_back(i);\n    int M = odds.size();\n\n\
    \    rep(k,0,V) rep(i,0,V) rep(j,0,V) {\n        chmin(dist[i][j], dist[i][k]\
    \ + dist[k][j]);\n    }\n    rep(i,0,M) rep(j,0,M) w[i][j] = dist[ odds[i] ][\
    \ odds[j] ];\n\n    rep(i,1,1<<M) dp[i] = INF;\n    rep(bit,0,1<<M) rep(i,0,M)\
    \ rep(j,i+1,M) {\n        if((bit >> i & 1) || (bit >> j & 1)) continue;\n   \
    \     chmin(dp[bit | (1 << i) | (1 << j)], dp[bit] + w[i][j]);\n    }\n    cout\
    \ << total + dp[(1<<M)-1] << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_007_CPP.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_007_CPP.cpp
layout: document
redirect_from:
- /library/dp/dp_007_CPP.cpp
- /library/dp/dp_007_CPP.cpp.html
title: dp/dp_007_CPP.cpp
---
