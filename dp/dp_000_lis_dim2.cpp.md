---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - http://abc038.contest.atcoder.jp/tasks/abc038_d
  bundledCode: "#line 1 \"dp/dp_000_lis_dim2.cpp\"\n// 2\u6B21\u5143LIS (\u6700\u9577\
    \u5897\u52A0\u90E8\u5206\u5217)\r\n// Verified: ABC038 D\u554F\u984C\r\n// http://abc038.contest.atcoder.jp/tasks/abc038_d\r\
    \n\r\nint n;\r\npair<int, int> ab[100000];\r\nint dp[100010];\r\n\r\nint main(){\r\
    \n  cin >> n;\r\n  rep(i,0,n) cin >> ab[i].fr >> ab[i].sc;\r\n\r\n  // h \u3092\
    \u6607\u9806\u3001w \u3092\u964D\u9806\u306B\u30BD\u30FC\u30C8\r\n  rep(i,0,n)\
    \ ab[i].sc *= -1;\r\n  sort(ab, ab + n);\r\n  rep(i,0,n) ab[i].sc *= -1;\r\n\r\
    \n  // w \u306E\u8981\u7D20\u306B\u3064\u3044\u3066\u666E\u901A\u306B LIS \u3092\
    \u3084\u308B\r\n  // w \u304C\u7B49\u3057\u3044\u3082\u306E\u3092\u5358\u8ABF\u5897\
    \u52A0\u5217\u306B\u5165\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u305F\
    \u3081\u306B\u3001\u964D\u9806\u30BD\u30FC\u30C8\u3092\u3057\u3066\u3044\u308B\
    \r\n  rep(i,0,100010) dp[i] = 10000000;\r\n  rep(i,0,n){\r\n    *lower_bound(dp,\
    \ dp + n, ab[i].sc) = ab[i].sc;\r\n  }\r\n  cout << lower_bound(dp, dp + n, 10000000)\
    \ - dp << endl;\r\n}\r\n\r\n// \u203Blower_bound\u306F\u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u300C\u4EE5\u4E0A\u300D\u306E\u5024\u304C\u73FE\u308C\u308B\
    \u6700\u521D\u306E\u4F4D\u7F6E\u306E\u691C\u7D22\r\n// \u203Bupper_bound\u306F\
    \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u300C\u3088\u308A\u3082\u5927\u304D\
    \u3044\u300D\u5024\u306E\u5024\u304C\u73FE\u308C\u308B\u6700\u521D\u306E\u4F4D\
    \u7F6E\u306E\u691C\u7D22\n"
  code: "// 2\u6B21\u5143LIS (\u6700\u9577\u5897\u52A0\u90E8\u5206\u5217)\r\n// Verified:\
    \ ABC038 D\u554F\u984C\r\n// http://abc038.contest.atcoder.jp/tasks/abc038_d\r\
    \n\r\nint n;\r\npair<int, int> ab[100000];\r\nint dp[100010];\r\n\r\nint main(){\r\
    \n  cin >> n;\r\n  rep(i,0,n) cin >> ab[i].fr >> ab[i].sc;\r\n\r\n  // h \u3092\
    \u6607\u9806\u3001w \u3092\u964D\u9806\u306B\u30BD\u30FC\u30C8\r\n  rep(i,0,n)\
    \ ab[i].sc *= -1;\r\n  sort(ab, ab + n);\r\n  rep(i,0,n) ab[i].sc *= -1;\r\n\r\
    \n  // w \u306E\u8981\u7D20\u306B\u3064\u3044\u3066\u666E\u901A\u306B LIS \u3092\
    \u3084\u308B\r\n  // w \u304C\u7B49\u3057\u3044\u3082\u306E\u3092\u5358\u8ABF\u5897\
    \u52A0\u5217\u306B\u5165\u308C\u306A\u3044\u3088\u3046\u306B\u3059\u308B\u305F\
    \u3081\u306B\u3001\u964D\u9806\u30BD\u30FC\u30C8\u3092\u3057\u3066\u3044\u308B\
    \r\n  rep(i,0,100010) dp[i] = 10000000;\r\n  rep(i,0,n){\r\n    *lower_bound(dp,\
    \ dp + n, ab[i].sc) = ab[i].sc;\r\n  }\r\n  cout << lower_bound(dp, dp + n, 10000000)\
    \ - dp << endl;\r\n}\r\n\r\n// \u203Blower_bound\u306F\u6307\u5B9A\u3055\u308C\
    \u305F\u8981\u7D20\u300C\u4EE5\u4E0A\u300D\u306E\u5024\u304C\u73FE\u308C\u308B\
    \u6700\u521D\u306E\u4F4D\u7F6E\u306E\u691C\u7D22\r\n// \u203Bupper_bound\u306F\
    \u6307\u5B9A\u3055\u308C\u305F\u8981\u7D20\u300C\u3088\u308A\u3082\u5927\u304D\
    \u3044\u300D\u5024\u306E\u5024\u304C\u73FE\u308C\u308B\u6700\u521D\u306E\u4F4D\
    \u7F6E\u306E\u691C\u7D22"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_000_lis_dim2.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_000_lis_dim2.cpp
layout: document
redirect_from:
- /library/dp/dp_000_lis_dim2.cpp
- /library/dp/dp_000_lis_dim2.cpp.html
title: dp/dp_000_lis_dim2.cpp
---
