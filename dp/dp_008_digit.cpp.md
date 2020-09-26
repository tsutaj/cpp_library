---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_008_digit.cpp\"\n// 1 \u4EE5\u4E0A 10^n \u4EE5\u4E0B\
    \u306E\u6574\u6570\u306E\u3046\u3061\u3001 3 \u306E\u500D\u6570\u304A\u3088\u3073\
    \ 3 \u306E\u3064\u304F\u500B\u6570\u3092\u6C42\u3081\u308B\n// -> \u6841 DP \u3067\
    \ \"\u6841\u6570\", \"mod 3\", \"3 \u3092\u6301\u3064\u304B\", \"\u5143\u306E\u6570\
    \u672A\u6E80\u3067\u3042\u308B\u3053\u3068\u304C\u78BA\u5B9A\u3057\u3066\u3044\
    \u308B\u304B\"\n// \u3092\u7BA1\u7406\u3057\u3066\u3044\u3051\u3070\u3088\u3044\
    \u3002\n\n// digit, mod, has3, flag\nll dp[25][3][2][2];\n\nint main() {\n   \
    \ // 10^n \u3092\u8868\u3059\u6587\u5B57\u5217\u3092\u4F5C\u6210\u3059\u308B\n\
    \    int n; cin >> n;\n    string s(n, '0');\n    s = '1' + s;\n\n    int m =\
    \ s.length();\n    dp[0][0][0][0] = 1;\n    rep(i,0,m) rep(j,0,3) rep(k,0,2) rep(l,0,2)\
    \ {\n        // i+1 \u6841\u76EE\u3067\u4F7F\u3046\u6570\u5B57\u306E\u5019\u88DC\
    \u306F\u30010 \u304B\u3089 lim \u307E\u3067\n        // flag == true \u306A\u3089\
    \u3070\u6570\u5B57\u306F\u4F55\u3067\u3082\u4F7F\u3048\u308B\u304C\u3001\n   \
    \     // \u305D\u3046\u3067\u306A\u3051\u308C\u3070 (\u5143\u306E\u6570\u672A\u6E80\
    \u304C\u78BA\u5B9A\u3057\u3066\u306A\u3051\u308C\u3070)\n        // \u5143\u306E\
    \u6570\u306E i+1 \u6841\u76EE\u306E\u6570\u5B57\u4EE5\u4E0B\u306E\u307F\u304C\u4F7F\
    \u3048\u308B\u3002\n        int lim = (l == 1 ? 9 : s[i] - '0');\n\n        rep(x,0,lim\
    \ + 1) {\n            // 3 \u306E\u500D\u6570\u306E\u5224\u5B9A\u306F\u3001\u5404\
    \u6841\u306E\u6570\u5B57\u306E\u548C\u3067\u884C\u3048\u308B\n            // \u3088\
    \u3063\u3066 mod 3 \u306E\u90E8\u5206\u306F\u5358\u7D14\u306B\u4ECA\u4F7F\u3046\
    \u6570\u5B57\u3092\u8DB3\u3057\u3066\u4F59\u308A\u3092\u53D6\u308B\n         \
    \   int mo = (j + x) % 3;\n            // mo = (j*10 + x) % 3; <- \u3053\u308C\
    \u3067\u3082\u3067\u304D\u308B\u3002\u3053\u306E\u65B9\u6CD5\u3060\u3068 3 \u306B\
    \u9650\u3089\u305A\u500D\u6570\u5224\u5B9A\u304C\u3067\u304D\u308B\n\n       \
    \     // has3 -> \u5143\u3005 true \u307E\u305F\u306F \u4ECA 3 \u3092\u4F7F\u3063\
    \u305F\n            // flag -> \u5143\u3005 true \u307E\u305F\u306F\u5143\u306E\
    \u6570\u306E i+1 \u6841\u76EE\u306E\u6570\u5B57\u672A\u6E80\u3092\u4F7F\u3063\u305F\
    \n            dp[i+1][mo][k || (x == 3)][l || x < lim] += dp[i][j][k][l];\n  \
    \      }\n    }\n\n    ll ans = 0;\n    rep(j,0,3) rep(k,0,2) rep(l,0,2) {\n \
    \       // mod3 == 0 \u307E\u305F\u306F has3 == 1 \u304C\u6761\u4EF6\u306B\u5408\
    \u81F4\u3059\u308B\n        if(j == 0 || k == 1) ans += dp[m][j][k][l];\n    }\n\
    \n    // \u3053\u306E DP \u3067\u306F 0 \u3082 valid \u3068\u3057\u3066\u6271\u3063\
    \u3066\u3044\u308B\u306E\u3067\u3001\n    // \u300C1 \u4EE5\u4E0A 10^n \u4EE5\u4E0B\
    \u300D\u306B\u304A\u3051\u308B\u7B54\u3048\u3092\u77E5\u308B\u305F\u3081\u306B\
    \ ans - 1 \u3059\u308B\n    cout << ans - 1 << endl;\n    return 0;\n}\n"
  code: "// 1 \u4EE5\u4E0A 10^n \u4EE5\u4E0B\u306E\u6574\u6570\u306E\u3046\u3061\u3001\
    \ 3 \u306E\u500D\u6570\u304A\u3088\u3073 3 \u306E\u3064\u304F\u500B\u6570\u3092\
    \u6C42\u3081\u308B\n// -> \u6841 DP \u3067 \"\u6841\u6570\", \"mod 3\", \"3 \u3092\
    \u6301\u3064\u304B\", \"\u5143\u306E\u6570\u672A\u6E80\u3067\u3042\u308B\u3053\
    \u3068\u304C\u78BA\u5B9A\u3057\u3066\u3044\u308B\u304B\"\n// \u3092\u7BA1\u7406\
    \u3057\u3066\u3044\u3051\u3070\u3088\u3044\u3002\n\n// digit, mod, has3, flag\n\
    ll dp[25][3][2][2];\n\nint main() {\n    // 10^n \u3092\u8868\u3059\u6587\u5B57\
    \u5217\u3092\u4F5C\u6210\u3059\u308B\n    int n; cin >> n;\n    string s(n, '0');\n\
    \    s = '1' + s;\n\n    int m = s.length();\n    dp[0][0][0][0] = 1;\n    rep(i,0,m)\
    \ rep(j,0,3) rep(k,0,2) rep(l,0,2) {\n        // i+1 \u6841\u76EE\u3067\u4F7F\u3046\
    \u6570\u5B57\u306E\u5019\u88DC\u306F\u30010 \u304B\u3089 lim \u307E\u3067\n  \
    \      // flag == true \u306A\u3089\u3070\u6570\u5B57\u306F\u4F55\u3067\u3082\u4F7F\
    \u3048\u308B\u304C\u3001\n        // \u305D\u3046\u3067\u306A\u3051\u308C\u3070\
    \ (\u5143\u306E\u6570\u672A\u6E80\u304C\u78BA\u5B9A\u3057\u3066\u306A\u3051\u308C\
    \u3070)\n        // \u5143\u306E\u6570\u306E i+1 \u6841\u76EE\u306E\u6570\u5B57\
    \u4EE5\u4E0B\u306E\u307F\u304C\u4F7F\u3048\u308B\u3002\n        int lim = (l ==\
    \ 1 ? 9 : s[i] - '0');\n\n        rep(x,0,lim + 1) {\n            // 3 \u306E\u500D\
    \u6570\u306E\u5224\u5B9A\u306F\u3001\u5404\u6841\u306E\u6570\u5B57\u306E\u548C\
    \u3067\u884C\u3048\u308B\n            // \u3088\u3063\u3066 mod 3 \u306E\u90E8\
    \u5206\u306F\u5358\u7D14\u306B\u4ECA\u4F7F\u3046\u6570\u5B57\u3092\u8DB3\u3057\
    \u3066\u4F59\u308A\u3092\u53D6\u308B\n            int mo = (j + x) % 3;\n    \
    \        // mo = (j*10 + x) % 3; <- \u3053\u308C\u3067\u3082\u3067\u304D\u308B\
    \u3002\u3053\u306E\u65B9\u6CD5\u3060\u3068 3 \u306B\u9650\u3089\u305A\u500D\u6570\
    \u5224\u5B9A\u304C\u3067\u304D\u308B\n\n            // has3 -> \u5143\u3005 true\
    \ \u307E\u305F\u306F \u4ECA 3 \u3092\u4F7F\u3063\u305F\n            // flag ->\
    \ \u5143\u3005 true \u307E\u305F\u306F\u5143\u306E\u6570\u306E i+1 \u6841\u76EE\
    \u306E\u6570\u5B57\u672A\u6E80\u3092\u4F7F\u3063\u305F\n            dp[i+1][mo][k\
    \ || (x == 3)][l || x < lim] += dp[i][j][k][l];\n        }\n    }\n\n    ll ans\
    \ = 0;\n    rep(j,0,3) rep(k,0,2) rep(l,0,2) {\n        // mod3 == 0 \u307E\u305F\
    \u306F has3 == 1 \u304C\u6761\u4EF6\u306B\u5408\u81F4\u3059\u308B\n        if(j\
    \ == 0 || k == 1) ans += dp[m][j][k][l];\n    }\n\n    // \u3053\u306E DP \u3067\
    \u306F 0 \u3082 valid \u3068\u3057\u3066\u6271\u3063\u3066\u3044\u308B\u306E\u3067\
    \u3001\n    // \u300C1 \u4EE5\u4E0A 10^n \u4EE5\u4E0B\u300D\u306B\u304A\u3051\u308B\
    \u7B54\u3048\u3092\u77E5\u308B\u305F\u3081\u306B ans - 1 \u3059\u308B\n    cout\
    \ << ans - 1 << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_008_digit.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_008_digit.cpp
layout: document
redirect_from:
- /library/dp/dp_008_digit.cpp
- /library/dp/dp_008_digit.cpp.html
title: dp/dp_008_digit.cpp
---
