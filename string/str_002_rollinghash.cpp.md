---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_002_rollinghash.cpp\"\n// Rolling Hash\n// Verified:\
    \ AOJ 2444 (Substring)\n\nstruct RollingHash {\npublic:\n    using int_type =\
    \ long long int;\n    using hash_type = pair<int_type, int_type>;\n    int_type\
    \ base_1, base_2, mod_1, mod_2;\n    vector<int_type> hash1, hash2, pow1, pow2;\n\
    \n    // init (constructor)\n    RollingHash(string s, int_type bs_1 = 1013, int_type\
    \ bs_2 = 1007) :\n        base_1(bs_1), base_2(bs_2),\n        mod_1(1000000007),\
    \ mod_2(1000000009),\n        hash1(s.length()+1,0), hash2(s.length()+1,0),\n\
    \        pow1(s.length()+1,1), pow2(s.length()+1,1) {\n            for(size_t\
    \ i=0; i<s.length(); i++) {\n                hash1[i+1] = (hash1[i] + s[i]) *\
    \ base_1 % mod_1;\n                hash2[i+1] = (hash2[i] + s[i]) * base_2 % mod_2;\n\
    \                pow1[i+1] = pow1[i] * base_1 % mod_1;\n                pow2[i+1]\
    \ = pow2[i] * base_2 % mod_2;\n            }\n        }\n\n    // calc str[l,r)\
    \ hash (0-indexed)\n    // if get(i1,j1) == get(i2,j2) -> identical string\n \
    \   hash_type get(int l, int r) {\n        int_type t1 = ((hash1[r] - hash1[l]\
    \ * pow1[r-l]) % mod_1);\n        if(t1 < 0) t1 += mod_1;\n        int_type t2\
    \ = ((hash2[r] - hash2[l] * pow2[r-l]) % mod_2);\n        if(t2 < 0) t2 += mod_2;\n\
    \        return make_pair(t1, t2);\n    }\n};\n"
  code: "// Rolling Hash\n// Verified: AOJ 2444 (Substring)\n\nstruct RollingHash\
    \ {\npublic:\n    using int_type = long long int;\n    using hash_type = pair<int_type,\
    \ int_type>;\n    int_type base_1, base_2, mod_1, mod_2;\n    vector<int_type>\
    \ hash1, hash2, pow1, pow2;\n\n    // init (constructor)\n    RollingHash(string\
    \ s, int_type bs_1 = 1013, int_type bs_2 = 1007) :\n        base_1(bs_1), base_2(bs_2),\n\
    \        mod_1(1000000007), mod_2(1000000009),\n        hash1(s.length()+1,0),\
    \ hash2(s.length()+1,0),\n        pow1(s.length()+1,1), pow2(s.length()+1,1) {\n\
    \            for(size_t i=0; i<s.length(); i++) {\n                hash1[i+1]\
    \ = (hash1[i] + s[i]) * base_1 % mod_1;\n                hash2[i+1] = (hash2[i]\
    \ + s[i]) * base_2 % mod_2;\n                pow1[i+1] = pow1[i] * base_1 % mod_1;\n\
    \                pow2[i+1] = pow2[i] * base_2 % mod_2;\n            }\n      \
    \  }\n\n    // calc str[l,r) hash (0-indexed)\n    // if get(i1,j1) == get(i2,j2)\
    \ -> identical string\n    hash_type get(int l, int r) {\n        int_type t1\
    \ = ((hash1[r] - hash1[l] * pow1[r-l]) % mod_1);\n        if(t1 < 0) t1 += mod_1;\n\
    \        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod_2);\n        if(t2\
    \ < 0) t2 += mod_2;\n        return make_pair(t1, t2);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_002_rollinghash.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_002_rollinghash.cpp
layout: document
redirect_from:
- /library/string/str_002_rollinghash.cpp
- /library/string/str_002_rollinghash.cpp.html
title: string/str_002_rollinghash.cpp
---
