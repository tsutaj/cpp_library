---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_001_maxSquare.cpp\"\n// \u6700\u5927\u6B63\u65B9\u5F62\
    \u554F\u984C (\u7DBA\u9E97\u306A\u30BF\u30A4\u30EB\u306E\u307F\u3092\u4F7F\u3063\
    \u3066\u3067\u304D\u308B\u6B63\u65B9\u5F62\u306E\u9762\u7A4D\u6700\u5927)\n//\
    \ 0 -> \u7DBA\u9E97\u306A\u30BF\u30A4\u30EB\u3001 1 -> \u6C5A\u308C\u3066\u3044\
    \u308B\u30BF\u30A4\u30EB\n// Verified: AOJ DPL_3_A: Largest Square\n\nint maxSquare(vector<\
    \ vector<int> > board) {\n    int H = board.size(), W = board[0].size();\n   \
    \ vector< vector<int> > dp(H, vector<int>(W));\n\n    int ret = 0;\n    rep(i,0,H)\
    \ rep(j,0,W) {\n        if(board[i][j] == 1) continue;\n        if(i == 0 || j\
    \ == 0) dp[i][j] = 1;\n        else {\n            int mi = min(dp[i-1][j-1],\
    \ min(dp[i][j-1], dp[i-1][j]));\n            dp[i][j] = mi + 1;\n        }\n \
    \       chmax(ret, dp[i][j] * dp[i][j]);\n    }\n    return ret;\n}\n"
  code: "// \u6700\u5927\u6B63\u65B9\u5F62\u554F\u984C (\u7DBA\u9E97\u306A\u30BF\u30A4\
    \u30EB\u306E\u307F\u3092\u4F7F\u3063\u3066\u3067\u304D\u308B\u6B63\u65B9\u5F62\
    \u306E\u9762\u7A4D\u6700\u5927)\n// 0 -> \u7DBA\u9E97\u306A\u30BF\u30A4\u30EB\u3001\
    \ 1 -> \u6C5A\u308C\u3066\u3044\u308B\u30BF\u30A4\u30EB\n// Verified: AOJ DPL_3_A:\
    \ Largest Square\n\nint maxSquare(vector< vector<int> > board) {\n    int H =\
    \ board.size(), W = board[0].size();\n    vector< vector<int> > dp(H, vector<int>(W));\n\
    \n    int ret = 0;\n    rep(i,0,H) rep(j,0,W) {\n        if(board[i][j] == 1)\
    \ continue;\n        if(i == 0 || j == 0) dp[i][j] = 1;\n        else {\n    \
    \        int mi = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));\n          \
    \  dp[i][j] = mi + 1;\n        }\n        chmax(ret, dp[i][j] * dp[i][j]);\n \
    \   }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_001_maxSquare.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_001_maxSquare.cpp
layout: document
redirect_from:
- /library/dp/dp_001_maxSquare.cpp
- /library/dp/dp_001_maxSquare.cpp.html
title: dp/dp_001_maxSquare.cpp
---
