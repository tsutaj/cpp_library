---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/old/strc_007_bit_recursion.cpp\"\n// BIT \u7565\
    \n// Verified: ALDS1_5_D (\u53CD\u8EE2\u6570)\nsigned main() {\n    int n; cin\
    \ >> n;\n    BIT<int> b(n);\n    vector<int> a(n);\n    map<int, int> m;\n   \
    \ rep(i,0,n) {\n        cin >> a[i];\n        m[a[i]];\n    }\n\n    int newnum\
    \ = 1;\n    for(auto &x : m) x.second = newnum++;\n    rep(i,0,n) a[i] = m[a[i]];\n\
    \n    int ans = 0;\n    rep(j,0,n) {\n        ans += j - b.sum(a[j]);\n      \
    \  b.add(a[j], 1);\n    }\n    cout << ans << endl;\n    return 0;\n}\n"
  code: "// BIT \u7565\n// Verified: ALDS1_5_D (\u53CD\u8EE2\u6570)\nsigned main()\
    \ {\n    int n; cin >> n;\n    BIT<int> b(n);\n    vector<int> a(n);\n    map<int,\
    \ int> m;\n    rep(i,0,n) {\n        cin >> a[i];\n        m[a[i]];\n    }\n\n\
    \    int newnum = 1;\n    for(auto &x : m) x.second = newnum++;\n    rep(i,0,n)\
    \ a[i] = m[a[i]];\n\n    int ans = 0;\n    rep(j,0,n) {\n        ans += j - b.sum(a[j]);\n\
    \        b.add(a[j], 1);\n    }\n    cout << ans << endl;\n    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: structure/old/strc_007_bit_recursion.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/old/strc_007_bit_recursion.cpp
layout: document
redirect_from:
- /library/structure/old/strc_007_bit_recursion.cpp
- /library/structure/old/strc_007_bit_recursion.cpp.html
title: structure/old/strc_007_bit_recursion.cpp
---
