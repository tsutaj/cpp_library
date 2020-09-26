---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_006_TSP.cpp\"\n// \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\
    \u30DE\u30F3\u554F\u984C (\u91CD\u307F\u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\
    \u306B\u3064\u3044\u3066\u3001\u6B21\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\
    \u6700\u77ED\u7D4C\u8DEF\u306E\u8DDD\u96E2)\n// \u30FB\u3042\u308B\u9802\u70B9\
    \u304B\u3089\u51FA\u767A\u3057\u3066\u3001\u51FA\u767A\u70B9\u3078\u623B\u308B\
    \u9589\u8DEF\n// \u30FB\u5404\u9802\u70B9\u3092\u3061\u3087\u3046\u3069 1 \u5EA6\
    \u901A\u308B\n// -> \u9589\u8DEF\u306A\u306E\u3067\u3001\u51FA\u767A\u70B9\u306F\
    \u3069\u3053\u3067\u3082\u3088\u3044\u3002\u3053\u306E\u5B9F\u88C5\u3067\u306F\
    \ 0 \u3092\u30B9\u30BF\u30FC\u30C8\u3068\u3057\u3066\u3044\u308B\u3002\n// Verified:\
    \ AOJ DPL_2_A: Traveling Salesman Problem\n\n// (to, cost)\nvector<pii> G[20];\n\
    int dp[1 << 15][15];\n\nvoid solve() {\n    int V, E; cin >> V >> E;\n    rep(i,0,E)\
    \ {\n        int s, t, d; cin >> s >> t >> d;\n        G[s].push_back(pii(t, d));\n\
    \    }\n\n    // \u51FA\u767A\u70B9\u3060\u3051\u521D\u671F\u5024 0 \u306B\u3059\
    \u308B\n    rep(i,0,1<<V) rep(j,0,V) dp[i][j] = INF;\n    dp[0][0] = 0;\n    \n\
    \    rep(bit,0,1<<V) rep(i,0,V) {\n        for(auto x : G[i]) {\n            if(bit\
    \ >> x.first & 1) continue;\n            int nbit = bit | (1 << x.first);\n  \
    \          chmin(dp[nbit][x.first], dp[bit][i] + x.second);\n        }\n    }\n\
    \    int ans = (dp[(1<<V)-1][0] == INF ? -1 : dp[(1<<V)-1][0]);\n    cout << ans\
    \ << endl;\n}\n"
  code: "// \u5DE1\u56DE\u30BB\u30FC\u30EB\u30B9\u30DE\u30F3\u554F\u984C (\u91CD\u307F\
    \u4ED8\u304D\u6709\u5411\u30B0\u30E9\u30D5\u306B\u3064\u3044\u3066\u3001\u6B21\
    \u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u6700\u77ED\u7D4C\u8DEF\u306E\u8DDD\
    \u96E2)\n// \u30FB\u3042\u308B\u9802\u70B9\u304B\u3089\u51FA\u767A\u3057\u3066\
    \u3001\u51FA\u767A\u70B9\u3078\u623B\u308B\u9589\u8DEF\n// \u30FB\u5404\u9802\u70B9\
    \u3092\u3061\u3087\u3046\u3069 1 \u5EA6\u901A\u308B\n// -> \u9589\u8DEF\u306A\u306E\
    \u3067\u3001\u51FA\u767A\u70B9\u306F\u3069\u3053\u3067\u3082\u3088\u3044\u3002\
    \u3053\u306E\u5B9F\u88C5\u3067\u306F 0 \u3092\u30B9\u30BF\u30FC\u30C8\u3068\u3057\
    \u3066\u3044\u308B\u3002\n// Verified: AOJ DPL_2_A: Traveling Salesman Problem\n\
    \n// (to, cost)\nvector<pii> G[20];\nint dp[1 << 15][15];\n\nvoid solve() {\n\
    \    int V, E; cin >> V >> E;\n    rep(i,0,E) {\n        int s, t, d; cin >> s\
    \ >> t >> d;\n        G[s].push_back(pii(t, d));\n    }\n\n    // \u51FA\u767A\
    \u70B9\u3060\u3051\u521D\u671F\u5024 0 \u306B\u3059\u308B\n    rep(i,0,1<<V) rep(j,0,V)\
    \ dp[i][j] = INF;\n    dp[0][0] = 0;\n    \n    rep(bit,0,1<<V) rep(i,0,V) {\n\
    \        for(auto x : G[i]) {\n            if(bit >> x.first & 1) continue;\n\
    \            int nbit = bit | (1 << x.first);\n            chmin(dp[nbit][x.first],\
    \ dp[bit][i] + x.second);\n        }\n    }\n    int ans = (dp[(1<<V)-1][0] ==\
    \ INF ? -1 : dp[(1<<V)-1][0]);\n    cout << ans << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_006_TSP.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_006_TSP.cpp
layout: document
redirect_from:
- /library/dp/dp_006_TSP.cpp
- /library/dp/dp_006_TSP.cpp.html
title: dp/dp_006_TSP.cpp
---
