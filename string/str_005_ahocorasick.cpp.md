---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_005_ahocorasick.cpp\"\n// Aho-Corasick \u6CD5\
    \n// \u5165\u529B\u6587\u5B57\u5217\u306B\u5BFE\u3057\u3066\u30DE\u30C3\u30C1\u3059\
    \u308B\u30D1\u30BF\u30FC\u30F3\u3092\u691C\u7D22\n// N := \u5165\u529B\u6587\u5B57\
    \u5217\u306E\u9577\u3055\u3001M := \u30D1\u30BF\u30FC\u30F3\u306E\u6587\u5B57\u5217\
    \u306E\u9577\u3055\u306E\u5408\u8A08\u3068\u3059\u308B\u3068\u304D\u3001\n// \u8A08\
    \u7B97\u91CF\u306F O(N + M)\n// Verified: JOI 2010 \u6625\u5408\u5BBF Day2: DNA\
    \ \u306E\u5408\u6210\n\nstruct Elem {\n    int wordidx, lidx, ridx;\n};\n\nconst\
    \ int SIZE = 256;\nstruct PMA {\n    PMA* node[SIZE + 1];\n    vector<int> matched;\n\
    \    PMA() { memset(node, 0, sizeof(node)); }\n\n    vector<int> unite(const vector<int>\
    \ &a, const vector<int> &b) {\n        vector<int> res;\n        set_union(a.begin(),\
    \ a.end(), b.begin(), b.end(), back_inserter(res));\n        return res;\n   \
    \ }\n\n    void build(vector<string> pattern) {\n        PMA* root = this;\n \
    \       root -> node[SIZE] = root;\n        for(size_t i=0; i<pattern.size();\
    \ i++) {\n            // \u5165\u529B\u6587\u5B57\u3092\u7D5E\u308B\u3068\u304D\
    \u306F\u3053\u3053\u3082\u5909\u3048\u3088\u3046\n            PMA* now = root;\n\
    \            for(size_t j=0; j<pattern[i].length(); j++) {\n                if(!now\
    \ -> node[ (int)pattern[i][j] ]) {\n                    now -> node[ (int)pattern[i][j]\
    \ ] = new PMA;\n                }\n                now = now -> node[ (int)pattern[i][j]\
    \ ];\n            }\n            now -> matched.push_back(i);\n        }\n\n \
    \       queue<PMA*> que;\n        for(int i=0; i<SIZE; i++) {\n            if(!root\
    \ -> node[i]) root -> node[i] = root;\n            else {\n                root\
    \ -> node[i] -> node[SIZE] = root;\n                que.push(root -> node[i]);\n\
    \            }\n        }\n\n        while(!que.empty()) {\n            PMA* now\
    \ = que.front(); que.pop();\n            for(int i=0; i<SIZE; i++) {\n       \
    \         if(now -> node[i]) {\n                    PMA *next = now -> node[SIZE];\n\
    \                    while(!next -> node[i]) next = next -> node[SIZE];\n    \
    \                now -> node[i] -> node[SIZE] = next -> node[i];\n           \
    \         now -> node[i] -> matched = unite(now -> node[i] -> matched, next ->\
    \ node[i] -> matched);\n                    que.push(now -> node[i]);\n      \
    \          }\n            }\n        }\n    }\n\n    // \u691C\u7D22\u5BFE\u8C61\
    \u306E\u6587\u5B57\u5217\u304B\u3089\u3001\u3069\u306E\u30D1\u30BF\u30FC\u30F3\
    \u6587\u5B57\u5217\u304C\u3069\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3067\
    \u73FE\u308C\u305F\u304B (\u534A\u958B)\n    vector<Elem> match(const string s,\
    \ vector<string> pattern) {\n        vector<Elem> res;\n        PMA* pma = this;\n\
    \        for(size_t i=0; i<s.length(); i++) {\n            // \u5165\u529B\u6587\
    \u5B57\u3092\u7D5E\u308B\u3068\u304D\u306F\u3053\u3053\u3082\u5909\u3048\u3088\
    \u3046\n            int c = s[i];\n            while(!pma -> node[c]) pma = pma\
    \ -> node[SIZE];\n            pma = pma -> node[c];\n            for(size_t j=0;\
    \ j<pma -> matched.size(); j++) {\n                int r = i+1, l = r - pattern[\
    \ pma -> matched[j] ].length();\n                res.push_back(Elem{pma -> matched[j],\
    \ l, r});\n            }\n        }\n        return res;\n    }\n};\n"
  code: "// Aho-Corasick \u6CD5\n// \u5165\u529B\u6587\u5B57\u5217\u306B\u5BFE\u3057\
    \u3066\u30DE\u30C3\u30C1\u3059\u308B\u30D1\u30BF\u30FC\u30F3\u3092\u691C\u7D22\
    \n// N := \u5165\u529B\u6587\u5B57\u5217\u306E\u9577\u3055\u3001M := \u30D1\u30BF\
    \u30FC\u30F3\u306E\u6587\u5B57\u5217\u306E\u9577\u3055\u306E\u5408\u8A08\u3068\
    \u3059\u308B\u3068\u304D\u3001\n// \u8A08\u7B97\u91CF\u306F O(N + M)\n// Verified:\
    \ JOI 2010 \u6625\u5408\u5BBF Day2: DNA \u306E\u5408\u6210\n\nstruct Elem {\n\
    \    int wordidx, lidx, ridx;\n};\n\nconst int SIZE = 256;\nstruct PMA {\n   \
    \ PMA* node[SIZE + 1];\n    vector<int> matched;\n    PMA() { memset(node, 0,\
    \ sizeof(node)); }\n\n    vector<int> unite(const vector<int> &a, const vector<int>\
    \ &b) {\n        vector<int> res;\n        set_union(a.begin(), a.end(), b.begin(),\
    \ b.end(), back_inserter(res));\n        return res;\n    }\n\n    void build(vector<string>\
    \ pattern) {\n        PMA* root = this;\n        root -> node[SIZE] = root;\n\
    \        for(size_t i=0; i<pattern.size(); i++) {\n            // \u5165\u529B\
    \u6587\u5B57\u3092\u7D5E\u308B\u3068\u304D\u306F\u3053\u3053\u3082\u5909\u3048\
    \u3088\u3046\n            PMA* now = root;\n            for(size_t j=0; j<pattern[i].length();\
    \ j++) {\n                if(!now -> node[ (int)pattern[i][j] ]) {\n         \
    \           now -> node[ (int)pattern[i][j] ] = new PMA;\n                }\n\
    \                now = now -> node[ (int)pattern[i][j] ];\n            }\n   \
    \         now -> matched.push_back(i);\n        }\n\n        queue<PMA*> que;\n\
    \        for(int i=0; i<SIZE; i++) {\n            if(!root -> node[i]) root ->\
    \ node[i] = root;\n            else {\n                root -> node[i] -> node[SIZE]\
    \ = root;\n                que.push(root -> node[i]);\n            }\n       \
    \ }\n\n        while(!que.empty()) {\n            PMA* now = que.front(); que.pop();\n\
    \            for(int i=0; i<SIZE; i++) {\n                if(now -> node[i]) {\n\
    \                    PMA *next = now -> node[SIZE];\n                    while(!next\
    \ -> node[i]) next = next -> node[SIZE];\n                    now -> node[i] ->\
    \ node[SIZE] = next -> node[i];\n                    now -> node[i] -> matched\
    \ = unite(now -> node[i] -> matched, next -> node[i] -> matched);\n          \
    \          que.push(now -> node[i]);\n                }\n            }\n     \
    \   }\n    }\n\n    // \u691C\u7D22\u5BFE\u8C61\u306E\u6587\u5B57\u5217\u304B\u3089\
    \u3001\u3069\u306E\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u304C\u3069\u306E\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3067\u73FE\u308C\u305F\u304B (\u534A\u958B\
    )\n    vector<Elem> match(const string s, vector<string> pattern) {\n        vector<Elem>\
    \ res;\n        PMA* pma = this;\n        for(size_t i=0; i<s.length(); i++) {\n\
    \            // \u5165\u529B\u6587\u5B57\u3092\u7D5E\u308B\u3068\u304D\u306F\u3053\
    \u3053\u3082\u5909\u3048\u3088\u3046\n            int c = s[i];\n            while(!pma\
    \ -> node[c]) pma = pma -> node[SIZE];\n            pma = pma -> node[c];\n  \
    \          for(size_t j=0; j<pma -> matched.size(); j++) {\n                int\
    \ r = i+1, l = r - pattern[ pma -> matched[j] ].length();\n                res.push_back(Elem{pma\
    \ -> matched[j], l, r});\n            }\n        }\n        return res;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: string/str_005_ahocorasick.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_005_ahocorasick.cpp
layout: document
redirect_from:
- /library/string/str_005_ahocorasick.cpp
- /library/string/str_005_ahocorasick.cpp.html
title: string/str_005_ahocorasick.cpp
---
