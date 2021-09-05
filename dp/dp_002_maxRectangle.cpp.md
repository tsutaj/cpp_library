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
  bundledCode: "#line 1 \"dp/dp_002_maxRectangle.cpp\"\n// \u6700\u5927\u9577\u65B9\
    \u5F62\u554F\u984C (\u7DBA\u9E97\u306A\u30BF\u30A4\u30EB\u306E\u307F\u3092\u4F7F\
    \u3063\u3066\u3067\u304D\u308B\u9577\u65B9\u5F62\u306E\u9762\u7A4D\u6700\u5927\
    )\n// \u203B dp_003_histogram.cpp \u3092\u547C\u3073\u51FA\u3059\u306E\u3067\u6CE8\
    \u610F\uFF01\n// 0 -> \u7DBA\u9E97\u306A\u30BF\u30A4\u30EB\u3001 1 -> \u6C5A\u308C\
    \u3066\u3044\u308B\u30BF\u30A4\u30EB\n// Verified: AOJ DPL_3_B: Largest Rectangle\n\
    \nint maxRectangle(vector< vector<int> > board) {\n    int H = board.size(), W\
    \ = board[0].size();\n    vector< vector<int> > sum(H, vector<int>(W));\n    rep(i,0,H)\
    \ rep(j,0,W) {\n        if(board[i][j] == 1) continue;\n        sum[i][j] = (i\
    \ > 0 ? sum[i-1][j] : 0) + 1;\n    }\n    int ret = 0;\n    rep(i,0,H) chmax(ret,\
    \ histArea(sum[i]));\n    return ret;\n}\n"
  code: "// \u6700\u5927\u9577\u65B9\u5F62\u554F\u984C (\u7DBA\u9E97\u306A\u30BF\u30A4\
    \u30EB\u306E\u307F\u3092\u4F7F\u3063\u3066\u3067\u304D\u308B\u9577\u65B9\u5F62\
    \u306E\u9762\u7A4D\u6700\u5927)\n// \u203B dp_003_histogram.cpp \u3092\u547C\u3073\
    \u51FA\u3059\u306E\u3067\u6CE8\u610F\uFF01\n// 0 -> \u7DBA\u9E97\u306A\u30BF\u30A4\
    \u30EB\u3001 1 -> \u6C5A\u308C\u3066\u3044\u308B\u30BF\u30A4\u30EB\n// Verified:\
    \ AOJ DPL_3_B: Largest Rectangle\n\nint maxRectangle(vector< vector<int> > board)\
    \ {\n    int H = board.size(), W = board[0].size();\n    vector< vector<int> >\
    \ sum(H, vector<int>(W));\n    rep(i,0,H) rep(j,0,W) {\n        if(board[i][j]\
    \ == 1) continue;\n        sum[i][j] = (i > 0 ? sum[i-1][j] : 0) + 1;\n    }\n\
    \    int ret = 0;\n    rep(i,0,H) chmax(ret, histArea(sum[i]));\n    return ret;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_002_maxRectangle.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_002_maxRectangle.cpp
layout: document
redirect_from:
- /library/dp/dp_002_maxRectangle.cpp
- /library/dp/dp_002_maxRectangle.cpp.html
title: dp/dp_002_maxRectangle.cpp
---
