---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_008_shift_and_or.cpp\"\n// Shift And \u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0\u306B\u3088\u308B\u6587\u5B57\u5217\u691C\u7D22 (Verified:\
    \ AOJ ALDS1_14_B)\n// \u30D1\u30BF\u30FC\u30F3\u30FB\u30C6\u30AD\u30B9\u30C8\u3068\
    \u3082\u306B\u82F1\u5C0F\u6587\u5B57\u30FB\u82F1\u5927\u6587\u5B57\u30FB\u6570\
    \u5B57\u306E\u307F\u51FA\u73FE\u3059\u308B\u3053\u3068\u3092\u60F3\u5B9A (\u9069\
    \u5B9C getCharId \u3092\u5909\u66F4\u3057\u3066)\n// \u305F\u304F\u3055\u3093\u30D3\
    \u30C3\u30C8\u304C\u5FC5\u8981\u306A\u306E\u3067 bitset \u304C\u5FC5\u8981\n\n\
    // \u6700\u5927\u6587\u5B57\u5217\u9577 + 1\nconst int PATTERN_SIZE = 10001;\n\
    \n// \u6587\u5B57\u306E\u7A2E\u985E\u6570 (\u9069\u5B9C\u5909\u66F4\u304C\u5FC5\
    \u8981)\nconst int ALPH = 26 + 26 + 10;\n\nstruct BitParallel {\n    string s;\n\
    \    vector< bitset<PATTERN_SIZE> > mask;\n\n    // \u6587\u5B57\u306E id \u3092\
    \u53D6\u5F97\n    int getCharId(char c) {\n        if('a' <= c and c <= 'z') return\
    \ c - 'a';\n        if('A' <= c and c <= 'Z') return 26 + (c - 'A');\n       \
    \ return 26 + 26 + (c - '0');\n    }\n    \n    // \u30D1\u30BF\u30FC\u30F3\u6587\
    \u5B57\u5217\u3092\u53D7\u3051\u53D6\u308A\u3001mask \u3092\u4F5C\u6210\n    BitParallel(string\
    \ s_) : s(s_) {\n        mask.resize(ALPH);\n        for(size_t i=0; i<s.length();\
    \ i++) {\n            int c = getCharId(s[i]);\n            mask[c][i+1] = 1;\n\
    \        }\n    }\n\n    // \u30C6\u30AD\u30B9\u30C8\u6587\u5B57\u5217\u3092\u5165\
    \u529B\u3068\u3057\u3066\u4E0E\u3048\u308B\n    // \u51FA\u73FE\u4F4D\u7F6E (\u306E\
    \u5DE6\u7AEF) \u3092 0-indexed \u3067\u8FD4\u3059\n    vector<int> search(string\
    \ t) {\n        bitset<PATTERN_SIZE> bit;\n\n        vector<int> appeared;\n \
    \       int L = s.length();\n        for(size_t i=0; i<t.length(); i++) {\n  \
    \          int c = getCharId(t[i]);\n            bit[0] = 1;\n            bit\
    \ = (bit << 1) & mask[c];\n\n            // \u30D1\u30BF\u30FC\u30F3\u3068\u4E00\
    \u81F4\n            if(bit[L] == 1) {\n                appeared.push_back(i-L+1);\n\
    \            }\n        }\n        return appeared;\n    }\n};\n"
  code: "// Shift And \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u306B\u3088\u308B\u6587\
    \u5B57\u5217\u691C\u7D22 (Verified: AOJ ALDS1_14_B)\n// \u30D1\u30BF\u30FC\u30F3\
    \u30FB\u30C6\u30AD\u30B9\u30C8\u3068\u3082\u306B\u82F1\u5C0F\u6587\u5B57\u30FB\
    \u82F1\u5927\u6587\u5B57\u30FB\u6570\u5B57\u306E\u307F\u51FA\u73FE\u3059\u308B\
    \u3053\u3068\u3092\u60F3\u5B9A (\u9069\u5B9C getCharId \u3092\u5909\u66F4\u3057\
    \u3066)\n// \u305F\u304F\u3055\u3093\u30D3\u30C3\u30C8\u304C\u5FC5\u8981\u306A\
    \u306E\u3067 bitset \u304C\u5FC5\u8981\n\n// \u6700\u5927\u6587\u5B57\u5217\u9577\
    \ + 1\nconst int PATTERN_SIZE = 10001;\n\n// \u6587\u5B57\u306E\u7A2E\u985E\u6570\
    \ (\u9069\u5B9C\u5909\u66F4\u304C\u5FC5\u8981)\nconst int ALPH = 26 + 26 + 10;\n\
    \nstruct BitParallel {\n    string s;\n    vector< bitset<PATTERN_SIZE> > mask;\n\
    \n    // \u6587\u5B57\u306E id \u3092\u53D6\u5F97\n    int getCharId(char c) {\n\
    \        if('a' <= c and c <= 'z') return c - 'a';\n        if('A' <= c and c\
    \ <= 'Z') return 26 + (c - 'A');\n        return 26 + 26 + (c - '0');\n    }\n\
    \    \n    // \u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u3092\u53D7\u3051\u53D6\
    \u308A\u3001mask \u3092\u4F5C\u6210\n    BitParallel(string s_) : s(s_) {\n  \
    \      mask.resize(ALPH);\n        for(size_t i=0; i<s.length(); i++) {\n    \
    \        int c = getCharId(s[i]);\n            mask[c][i+1] = 1;\n        }\n\
    \    }\n\n    // \u30C6\u30AD\u30B9\u30C8\u6587\u5B57\u5217\u3092\u5165\u529B\u3068\
    \u3057\u3066\u4E0E\u3048\u308B\n    // \u51FA\u73FE\u4F4D\u7F6E (\u306E\u5DE6\u7AEF\
    ) \u3092 0-indexed \u3067\u8FD4\u3059\n    vector<int> search(string t) {\n  \
    \      bitset<PATTERN_SIZE> bit;\n\n        vector<int> appeared;\n        int\
    \ L = s.length();\n        for(size_t i=0; i<t.length(); i++) {\n            int\
    \ c = getCharId(t[i]);\n            bit[0] = 1;\n            bit = (bit << 1)\
    \ & mask[c];\n\n            // \u30D1\u30BF\u30FC\u30F3\u3068\u4E00\u81F4\n  \
    \          if(bit[L] == 1) {\n                appeared.push_back(i-L+1);\n   \
    \         }\n        }\n        return appeared;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_008_shift_and_or.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_008_shift_and_or.cpp
layout: document
redirect_from:
- /library/string/str_008_shift_and_or.cpp
- /library/string/str_008_shift_and_or.cpp.html
title: string/str_008_shift_and_or.cpp
---
