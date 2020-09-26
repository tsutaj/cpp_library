---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_000_split.cpp\"\n// split\u95A2\u6570 (1\u6587\
    \u5B57\u30D0\u30FC\u30B8\u30E7\u30F3\u3002\u6307\u5B9A\u3055\u308C\u305F\u6587\
    \u5B57\u3067\u6587\u5B57\u5217\u3092\u5206\u5272)\r\nvector<string> split(string\
    \ s, char c) {\r\n    vector<string> ret;\r\n    string temp;\r\n    replace(s.begin(),\
    \ s.end(), c, ' ');\r\n    stringstream ss(s);\r\n    while(ss >> temp) ret.pb(temp);\r\
    \n    return ret;\r\n}\r\n\r\n// split\u95A2\u6570 (1\u6587\u5B57\u30FB delimiter\
    \ \u3092\u5F15\u6570\u306B\u6307\u5B9A\u3057\u306A\u3044\u30D0\u30FC\u30B8\u30E7\
    \u30F3)\r\n// \u203B delimiter \u304C\u8907\u6570\u3042\u308C\u3070\u305D\u306E\
    \u90FD\u5EA6 replace \u95A2\u6570\u3092\u5897\u3084\u3059(\u3067\u3082\u9045\u304F\
    \u306A\u308B\u304B\u3082)\r\nvector<string> split(string s) {\r\n    vector<string>\
    \ ret;\r\n    string temp;\r\n    replace(s.begin(), s.end(), ',', ' ');\r\n \
    \   replace(s.begin(), s.end(), '/', ' ');\r\n    stringstream ss(s);\r\n    while(ss\
    \ >> temp) ret.pb(temp);\r\n    return ret;\r\n}\r\n\r\n// split\u95A2\u6570 (2\u6587\
    \u5B57\u4EE5\u4E0A\u30D0\u30FC\u30B8\u30E7\u30F3\u3002\u6307\u5B9A\u3055\u308C\
    \u305F\u6587\u5B57\u5217\u3067\u6587\u5B57\u5217\u3092\u5206\u5272)\r\nvector<string>\
    \ split(string s, string c) {\r\n    vector<string> ret;\r\n    string temp;\r\
    \n    for(int pos = s.find(c); pos != string::npos; pos = s.find(c, pos)) {\r\n\
    \        s.replace(pos, c.size(), \" \");\r\n    }\r\n    stringstream ss(s);\r\
    \n    while(ss >> temp) ret.pb(temp);\r\n    return ret;\r\n}\n"
  code: "// split\u95A2\u6570 (1\u6587\u5B57\u30D0\u30FC\u30B8\u30E7\u30F3\u3002\u6307\
    \u5B9A\u3055\u308C\u305F\u6587\u5B57\u3067\u6587\u5B57\u5217\u3092\u5206\u5272\
    )\r\nvector<string> split(string s, char c) {\r\n    vector<string> ret;\r\n \
    \   string temp;\r\n    replace(s.begin(), s.end(), c, ' ');\r\n    stringstream\
    \ ss(s);\r\n    while(ss >> temp) ret.pb(temp);\r\n    return ret;\r\n}\r\n\r\n\
    // split\u95A2\u6570 (1\u6587\u5B57\u30FB delimiter \u3092\u5F15\u6570\u306B\u6307\
    \u5B9A\u3057\u306A\u3044\u30D0\u30FC\u30B8\u30E7\u30F3)\r\n// \u203B delimiter\
    \ \u304C\u8907\u6570\u3042\u308C\u3070\u305D\u306E\u90FD\u5EA6 replace \u95A2\u6570\
    \u3092\u5897\u3084\u3059(\u3067\u3082\u9045\u304F\u306A\u308B\u304B\u3082)\r\n\
    vector<string> split(string s) {\r\n    vector<string> ret;\r\n    string temp;\r\
    \n    replace(s.begin(), s.end(), ',', ' ');\r\n    replace(s.begin(), s.end(),\
    \ '/', ' ');\r\n    stringstream ss(s);\r\n    while(ss >> temp) ret.pb(temp);\r\
    \n    return ret;\r\n}\r\n\r\n// split\u95A2\u6570 (2\u6587\u5B57\u4EE5\u4E0A\u30D0\
    \u30FC\u30B8\u30E7\u30F3\u3002\u6307\u5B9A\u3055\u308C\u305F\u6587\u5B57\u5217\
    \u3067\u6587\u5B57\u5217\u3092\u5206\u5272)\r\nvector<string> split(string s,\
    \ string c) {\r\n    vector<string> ret;\r\n    string temp;\r\n    for(int pos\
    \ = s.find(c); pos != string::npos; pos = s.find(c, pos)) {\r\n        s.replace(pos,\
    \ c.size(), \" \");\r\n    }\r\n    stringstream ss(s);\r\n    while(ss >> temp)\
    \ ret.pb(temp);\r\n    return ret;\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/str_000_split.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_000_split.cpp
layout: document
redirect_from:
- /library/string/str_000_split.cpp
- /library/string/str_000_split.cpp.html
title: string/str_000_split.cpp
---
