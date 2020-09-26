---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_004_editDistance.cpp\"\n// \u7DE8\u96C6\u8DDD\u96E2\
    \ (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\u30F3\u8DDD\u96E2)\n// Verified:\
    \ DPL_1_E: Edit Distance (Levenshtein Distance)\n\nint dp[1010][1010];\nint editDistance(string\
    \ s, string t) {\n    int n = s.length(), m = t.length();\n    rep(i,0,n) dp[i+1][0]\
    \ = i+1;\n    rep(i,0,m) dp[0][i+1] = i+1;\n\n    rep(i,0,n) rep(j,0,m) {\n  \
    \      int cost = (s[i] != t[j]);\n        dp[i+1][j+1] = min(dp[i+1][j] + 1,\
    \ \n                       min(dp[i][j+1] + 1, dp[i][j] + cost));\n    }\n   \
    \ return dp[n][m];\n}\n"
  code: "// \u7DE8\u96C6\u8DDD\u96E2 (\u30EC\u30FC\u30D9\u30F3\u30B7\u30E5\u30BF\u30A4\
    \u30F3\u8DDD\u96E2)\n// Verified: DPL_1_E: Edit Distance (Levenshtein Distance)\n\
    \nint dp[1010][1010];\nint editDistance(string s, string t) {\n    int n = s.length(),\
    \ m = t.length();\n    rep(i,0,n) dp[i+1][0] = i+1;\n    rep(i,0,m) dp[0][i+1]\
    \ = i+1;\n\n    rep(i,0,n) rep(j,0,m) {\n        int cost = (s[i] != t[j]);\n\
    \        dp[i+1][j+1] = min(dp[i+1][j] + 1, \n                       min(dp[i][j+1]\
    \ + 1, dp[i][j] + cost));\n    }\n    return dp[n][m];\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_004_editDistance.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_004_editDistance.cpp
layout: document
redirect_from:
- /library/dp/dp_004_editDistance.cpp
- /library/dp/dp_004_editDistance.cpp.html
title: dp/dp_004_editDistance.cpp
---
