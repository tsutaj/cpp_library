---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "KMP \u6CD5 (Knuth-Morris-Pratt Algorithm)"
    links:
    - http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
  bundledCode: "#line 1 \"string/str_007_kmp.cpp\"\n// @brief KMP \u6CD5 (Knuth-Morris-Pratt\
    \ Algorithm)\ntemplate <typename Tp>\nstruct KMP {\n    Tp p; int len;\n    vector<int>\
    \ fail;\n    KMP() {}\n    KMP(Tp p_) : p(p_), len(p_.size()) {\n        // @brief\
    \ \u6587\u5B57\u5217 $p[0:i-1]$ \u306E\u63A5\u982D\u8F9E\u3068\u63A5\u5C3E\u8F9E\
    \u306F\u6700\u5927\u4F55\u6587\u5B57\u4E00\u81F4\u3059\u308B\uFF1F (\u305F\u3060\
    \u3057\u3001$|p[0:i-1]|$ \u6587\u5B57\u672A\u6E80\u306E\u307F\u8003\u616E)\n \
    \       // @brief MP \u6CD5\u306B\u6BD4\u3079\u3001\u5931\u6557\u6642\u306E\u9077\
    \u79FB\u304C log \u56DE\u306B\u6539\u5584\u3055\u308C\u3066\u3044\u308B\n    \
    \    // @see http://www-igm.univ-mlv.fr/~lecroq/string/node8.html\n        fail.resize(len\
    \ + 1, -1);\n        for(int i=0, j=-1; i<len; i++) {\n            // \u305D\u306E\
    \u6642\u70B9\u3067\u4E00\u81F4\u3057\u306A\u3051\u308C\u3070 fail[j] \u6587\u5B57\
    \u4EE5\u4E0B\u306E\u4E00\u81F4\u3068\u306A\u308B\n            // j \u3092 fail[j]\
    \ \u306B\u5909\u66F4\n            while(j >= 0 and p[j] != p[i]) j = fail[j];\n\
    \            j++;\n            fail[i+1] = (i+1 < len and p[i+1] == p[j] ? fail[j]\
    \ : j);\n        }\n    }\n\n    // @brief \u6587\u5B57\u5217 $s$ \u306B\u304A\
    \u3051\u308B $p$ \u306E\u51FA\u73FE\u4F4D\u7F6E (\u958B\u59CB\u4F4D\u7F6E) \u306E\
    \u30EA\u30B9\u30C8\n    vector<int> match(Tp s) {\n        int N = s.size();\n\
    \        vector<int> occur;\n        for(int i=0, k=0; i<N; i++) {\n         \
    \   while(k >= 0 and s[i] != p[k]) k = fail[k];\n            if(++k == len) {\n\
    \                occur.push_back(i-len+1);\n                k = fail[k];\n   \
    \         }\n        }\n        return occur;\n    }\n};\n"
  code: "// @brief KMP \u6CD5 (Knuth-Morris-Pratt Algorithm)\ntemplate <typename Tp>\n\
    struct KMP {\n    Tp p; int len;\n    vector<int> fail;\n    KMP() {}\n    KMP(Tp\
    \ p_) : p(p_), len(p_.size()) {\n        // @brief \u6587\u5B57\u5217 $p[0:i-1]$\
    \ \u306E\u63A5\u982D\u8F9E\u3068\u63A5\u5C3E\u8F9E\u306F\u6700\u5927\u4F55\u6587\
    \u5B57\u4E00\u81F4\u3059\u308B\uFF1F (\u305F\u3060\u3057\u3001$|p[0:i-1]|$ \u6587\
    \u5B57\u672A\u6E80\u306E\u307F\u8003\u616E)\n        // @brief MP \u6CD5\u306B\
    \u6BD4\u3079\u3001\u5931\u6557\u6642\u306E\u9077\u79FB\u304C log \u56DE\u306B\u6539\
    \u5584\u3055\u308C\u3066\u3044\u308B\n        // @see http://www-igm.univ-mlv.fr/~lecroq/string/node8.html\n\
    \        fail.resize(len + 1, -1);\n        for(int i=0, j=-1; i<len; i++) {\n\
    \            // \u305D\u306E\u6642\u70B9\u3067\u4E00\u81F4\u3057\u306A\u3051\u308C\
    \u3070 fail[j] \u6587\u5B57\u4EE5\u4E0B\u306E\u4E00\u81F4\u3068\u306A\u308B\n\
    \            // j \u3092 fail[j] \u306B\u5909\u66F4\n            while(j >= 0\
    \ and p[j] != p[i]) j = fail[j];\n            j++;\n            fail[i+1] = (i+1\
    \ < len and p[i+1] == p[j] ? fail[j] : j);\n        }\n    }\n\n    // @brief\
    \ \u6587\u5B57\u5217 $s$ \u306B\u304A\u3051\u308B $p$ \u306E\u51FA\u73FE\u4F4D\
    \u7F6E (\u958B\u59CB\u4F4D\u7F6E) \u306E\u30EA\u30B9\u30C8\n    vector<int> match(Tp\
    \ s) {\n        int N = s.size();\n        vector<int> occur;\n        for(int\
    \ i=0, k=0; i<N; i++) {\n            while(k >= 0 and s[i] != p[k]) k = fail[k];\n\
    \            if(++k == len) {\n                occur.push_back(i-len+1);\n   \
    \             k = fail[k];\n            }\n        }\n        return occur;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_007_kmp.cpp
  requiredBy: []
  timestamp: '2020-01-11 16:10:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_007_kmp.cpp
layout: document
redirect_from:
- /library/string/str_007_kmp.cpp
- /library/string/str_007_kmp.cpp.html
title: "KMP \u6CD5 (Knuth-Morris-Pratt Algorithm)"
---
