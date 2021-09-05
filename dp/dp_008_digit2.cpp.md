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
  bundledCode: "#line 1 \"dp/dp_008_digit2.cpp\"\n// TTPC2015 F: \u30EC\u30B7\u30FC\
    \u30C8\n// \u592A\u90CE\u541B\u306F A \u5186\u306E\u8CB7\u3044\u7269\u3092\u3057\
    \u305F\u3002 \u592A\u90CE\u541B\u306F X \\geq A \u3092\u6E80\u305F\u3059\u4EFB\
    \u610F\u306E X \u5186\u3092\u652F\u6255\u3046\u3053\u3068\u304C\u3067\u304D\u308B\
    \u3002\n// \u8CB7\u3044\u7269\u306E\u91D1\u984D A \u3001\u652F\u6255\u984D X \u3001\
    \u304A\u91E3\u308A (X \u2212 A) \u306E 3 \u3064\u306E\u6574\u6570\u306B\u3064\u3044\
    \u3066 10 \u9032\u6570\u8868\u8A18\u306B\u3057\u305F\u3068\u304D\u3001\n// 3 \u3064\
    \u306E\u6570\u5B57\u304C\u63C3\u3046\u6841\u306E\u6570\u3092\u6700\u5927\u306B\
    \u3057\u305F\u3044\u3002\n\n// dp[i][j] := \u4E0B\u304B\u3089 i \u6841\u76EE\u307E\
    \u3067\u307F\u3066\u3001\u7E70\u308A\u4E0A\u304C\u308A\u304C (\u8D77\u3053\u3089\
    \u306A\u3044 / \u8D77\u3053\u308B)\n//             \u3068\u304D\u306E\u6841\u63C3\
    \u3044\u6700\u5927\u5024\nll dp[110][2];\n\nint main() {\n    string s; cin >>\
    \ s;\n    int N = s.length();\n    // \u4E0B\u306E\u6841\u304B\u3089\u898B\u305F\
    \u3044\u305F\u3081\u3001\u6587\u5B57\u5217\u3092\u53CD\u8EE2\u3055\u305B\u308B\
    \n    reverse(s.begin(), s.end());\n\n    rep(i,0,110) rep(j,0,2) dp[i][j] = -INF;\n\
    \n    dp[0][0] = 0;\n    // i \u6841\u76EE\u3092 k \u306B\u3059\u308B\u3001\u7E70\
    \u308A\u4E0B\u304C\u308A\u304C\u8D77\u3053\u3063\u3066\u3044\u308B\u304B\u3069\
    \u3046\u304B\u304C j\n    rep(i,0,N) rep(j,0,2) rep(k,0,10) {\n        if(dp[i][j]\
    \ == -INF) continue;\n        int v = s[i] - '0';\n        int digit = (k - v\
    \ - j + 20) % 10;\n        int borrow = (k - v - j < 0) ? 1 : 0;\n        // \u5143\
    \u306E\u6570\u306E i \u6841\u76EE\u3001\u8A08\u7B97\u7D50\u679C\u3001\u5165\u308C\
    \u305F\u6570 \u304C\u5168\u3066\u7B49\u3057\u3051\u308C\u3070\u8DB3\u3059\n  \
    \      chmax(dp[i+1][borrow], dp[i][j] + ((v == digit && digit == k) ? 1 : 0));\n\
    \    }\n    cout << max(dp[N][0], dp[N][1]) << endl;\n}\n"
  code: "// TTPC2015 F: \u30EC\u30B7\u30FC\u30C8\n// \u592A\u90CE\u541B\u306F A \u5186\
    \u306E\u8CB7\u3044\u7269\u3092\u3057\u305F\u3002 \u592A\u90CE\u541B\u306F X \\\
    geq A \u3092\u6E80\u305F\u3059\u4EFB\u610F\u306E X \u5186\u3092\u652F\u6255\u3046\
    \u3053\u3068\u304C\u3067\u304D\u308B\u3002\n// \u8CB7\u3044\u7269\u306E\u91D1\u984D\
    \ A \u3001\u652F\u6255\u984D X \u3001\u304A\u91E3\u308A (X \u2212 A) \u306E 3\
    \ \u3064\u306E\u6574\u6570\u306B\u3064\u3044\u3066 10 \u9032\u6570\u8868\u8A18\
    \u306B\u3057\u305F\u3068\u304D\u3001\n// 3 \u3064\u306E\u6570\u5B57\u304C\u63C3\
    \u3046\u6841\u306E\u6570\u3092\u6700\u5927\u306B\u3057\u305F\u3044\u3002\n\n//\
    \ dp[i][j] := \u4E0B\u304B\u3089 i \u6841\u76EE\u307E\u3067\u307F\u3066\u3001\u7E70\
    \u308A\u4E0A\u304C\u308A\u304C (\u8D77\u3053\u3089\u306A\u3044 / \u8D77\u3053\u308B\
    )\n//             \u3068\u304D\u306E\u6841\u63C3\u3044\u6700\u5927\u5024\nll dp[110][2];\n\
    \nint main() {\n    string s; cin >> s;\n    int N = s.length();\n    // \u4E0B\
    \u306E\u6841\u304B\u3089\u898B\u305F\u3044\u305F\u3081\u3001\u6587\u5B57\u5217\
    \u3092\u53CD\u8EE2\u3055\u305B\u308B\n    reverse(s.begin(), s.end());\n\n   \
    \ rep(i,0,110) rep(j,0,2) dp[i][j] = -INF;\n\n    dp[0][0] = 0;\n    // i \u6841\
    \u76EE\u3092 k \u306B\u3059\u308B\u3001\u7E70\u308A\u4E0B\u304C\u308A\u304C\u8D77\
    \u3053\u3063\u3066\u3044\u308B\u304B\u3069\u3046\u304B\u304C j\n    rep(i,0,N)\
    \ rep(j,0,2) rep(k,0,10) {\n        if(dp[i][j] == -INF) continue;\n        int\
    \ v = s[i] - '0';\n        int digit = (k - v - j + 20) % 10;\n        int borrow\
    \ = (k - v - j < 0) ? 1 : 0;\n        // \u5143\u306E\u6570\u306E i \u6841\u76EE\
    \u3001\u8A08\u7B97\u7D50\u679C\u3001\u5165\u308C\u305F\u6570 \u304C\u5168\u3066\
    \u7B49\u3057\u3051\u308C\u3070\u8DB3\u3059\n        chmax(dp[i+1][borrow], dp[i][j]\
    \ + ((v == digit && digit == k) ? 1 : 0));\n    }\n    cout << max(dp[N][0], dp[N][1])\
    \ << endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_008_digit2.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_008_digit2.cpp
layout: document
redirect_from:
- /library/dp/dp_008_digit2.cpp
- /library/dp/dp_008_digit2.cpp.html
title: dp/dp_008_digit2.cpp
---
