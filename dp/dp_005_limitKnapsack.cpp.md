---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_005_limitKnapsack.cpp\"\n// \u500B\u6570\u5236\u9650\
    \u4ED8\u304D\u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u554F\u984C\n// \u4FA1\u5024\
    \ v_i \u3067\u91CD\u3055 w_i \u306E\u54C1\u7269\u304C m_i \u500B\u3042\u308B\u72B6\
    \u614B\u3067\n// \u5BB9\u91CF\u5236\u9650 W \u306E\u30CA\u30C3\u30D7\u30B6\u30C3\
    \u30AF\u5185\u306E\u4FA1\u5024\u6700\u5927\u5316\n// -> \u500B\u6570\u306E\u90E8\
    \u5206\u3092 2^k \u500B\u305A\u3064\u51E6\u7406\u3059\u308B\u3053\u3068\u3067\
    \ O(NW log max m_i) \u304F\u3089\u3044\u3067\u51E6\u7406\u53EF\u80FD\n// Verified:\
    \ DPL_1_G: Knapsack Problem with Limitations\n\n// dp[i] := (weight) -> value\n\
    int dp[10010];\nint v[110], w[110], m[110];\n\nvoid solve() {\n    int N, W; cin\
    \ >> N >> W;\n    rep(i,0,N) cin >> v[i] >> w[i] >> m[i];\n\n    rep(i,0,N) {\n\
    \        int rest = m[i], k = 0;\n        while(rest > 0) {\n            int take\
    \ = min(rest, 1LL << k++);\n            rest -= take;\n\n            repr(j,W,0)\
    \ {\n                if(j-take*w[i] < 0) continue;\n                chmax(dp[j],\
    \ dp[j-take*w[i]] + take*v[i]);\n            }\n        }\n    }\n    cout <<\
    \ *max_element(dp, dp+W+1) << endl;\n}\n"
  code: "// \u500B\u6570\u5236\u9650\u4ED8\u304D\u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\
    \u554F\u984C\n// \u4FA1\u5024 v_i \u3067\u91CD\u3055 w_i \u306E\u54C1\u7269\u304C\
    \ m_i \u500B\u3042\u308B\u72B6\u614B\u3067\n// \u5BB9\u91CF\u5236\u9650 W \u306E\
    \u30CA\u30C3\u30D7\u30B6\u30C3\u30AF\u5185\u306E\u4FA1\u5024\u6700\u5927\u5316\
    \n// -> \u500B\u6570\u306E\u90E8\u5206\u3092 2^k \u500B\u305A\u3064\u51E6\u7406\
    \u3059\u308B\u3053\u3068\u3067 O(NW log max m_i) \u304F\u3089\u3044\u3067\u51E6\
    \u7406\u53EF\u80FD\n// Verified: DPL_1_G: Knapsack Problem with Limitations\n\n\
    // dp[i] := (weight) -> value\nint dp[10010];\nint v[110], w[110], m[110];\n\n\
    void solve() {\n    int N, W; cin >> N >> W;\n    rep(i,0,N) cin >> v[i] >> w[i]\
    \ >> m[i];\n\n    rep(i,0,N) {\n        int rest = m[i], k = 0;\n        while(rest\
    \ > 0) {\n            int take = min(rest, 1LL << k++);\n            rest -= take;\n\
    \n            repr(j,W,0) {\n                if(j-take*w[i] < 0) continue;\n \
    \               chmax(dp[j], dp[j-take*w[i]] + take*v[i]);\n            }\n  \
    \      }\n    }\n    cout << *max_element(dp, dp+W+1) << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_005_limitKnapsack.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_005_limitKnapsack.cpp
layout: document
redirect_from:
- /library/dp/dp_005_limitKnapsack.cpp
- /library/dp/dp_005_limitKnapsack.cpp.html
title: dp/dp_005_limitKnapsack.cpp
---
