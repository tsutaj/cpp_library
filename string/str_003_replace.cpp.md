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
  bundledCode: "#line 1 \"string/str_003_replace.cpp\"\n// s \u306B\u542B\u307E\u308C\
    \u3066\u3044\u308B t \u3092\u5168\u3066 u \u306B\u5909\u3048\u308B\n// (find \u3057\
    \u307E\u304F\u308B\u3088\u308A\u306F\u9AD8\u901F\u306E\u306F\u305A)\nstring replace_user(string\
    \ s, string t, string u) {\n    reverse(t.begin(), t.end());\n    size_t N = s.length(),\
    \ M = t.length();\n    if(N < M) return s;\n\n    string ret = \"\", temp = \"\
    \";\n    for(size_t i=0; i<N; i++) {\n        if(temp.length() == M) {\n     \
    \       ret += temp.back();\n            temp.pop_back();\n        }\n       \
    \ temp = s[i] + temp;\n        if(temp == t) {\n            ret += u;\n      \
    \      temp = \"\";\n        }\n    }\n    reverse(temp.begin(), temp.end());\n\
    \    s = ret + temp;\n    return s;\n}\n"
  code: "// s \u306B\u542B\u307E\u308C\u3066\u3044\u308B t \u3092\u5168\u3066 u \u306B\
    \u5909\u3048\u308B\n// (find \u3057\u307E\u304F\u308B\u3088\u308A\u306F\u9AD8\u901F\
    \u306E\u306F\u305A)\nstring replace_user(string s, string t, string u) {\n   \
    \ reverse(t.begin(), t.end());\n    size_t N = s.length(), M = t.length();\n \
    \   if(N < M) return s;\n\n    string ret = \"\", temp = \"\";\n    for(size_t\
    \ i=0; i<N; i++) {\n        if(temp.length() == M) {\n            ret += temp.back();\n\
    \            temp.pop_back();\n        }\n        temp = s[i] + temp;\n      \
    \  if(temp == t) {\n            ret += u;\n            temp = \"\";\n        }\n\
    \    }\n    reverse(temp.begin(), temp.end());\n    s = ret + temp;\n    return\
    \ s;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/str_003_replace.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_003_replace.cpp
layout: document
redirect_from:
- /library/string/str_003_replace.cpp
- /library/string/str_003_replace.cpp.html
title: string/str_003_replace.cpp
---
