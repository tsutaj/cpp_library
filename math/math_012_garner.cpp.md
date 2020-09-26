---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_012_garner.cpp\"\n// Garner \u306E\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0 ( \u8A08\u7B97\u91CF O(N^2) )\n// x \u2261 a_1 (mod m_1),\
    \ ..., x \u2261 a_N (mod m_N) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E x \u3092\
    \u8FD4\u3059\n// m_1, m_2, ... m_N \u306F\u76F8\u7570\u306A\u308B\u7D20\u6570\u3067\
    \u3042\u308B\u5FC5\u8981\u304C\u3042\u308B\n\n// x = k_0 + k_1*m_1 + k_2*(m_1*m_2)\
    \ + ... k_{N-1}*(m_1*m_2* ... *m_{N-1}) \u3068\u3057\u3066\u3001\n// 1 \u3064\u76EE\
    \u306E\u5F0F\u304B\u3089\u9806\u306B\u64CD\u4F5C\u3059\u308B\u3053\u3068\u3067\
    \u4FC2\u6570 k_i \u3092\u4E0B\u304B\u3089\u6C7A\u5B9A\u3057\u3066\u3044\u304F\n\
    \nll mod_pow(ll X, ll N, ll mod) {\n    ll ret = 1;\n    for(; N>0; N>>=1) {\n\
    \        if(N & 1) (ret *= X) %= mod;\n        (X *= X) %= mod;\n    }\n    return\
    \ ret;\n}\n\nll garner(vector<ll> values, vector<ll> mods, ll mod) {\n    assert(values.size()\
    \ == mods.size());\n    int N = values.size();\n    vector<ll> coeff(N);\n\n \
    \   for(int i=0; i<N; i++) {\n        ll val_A = values[i] % mods[i];\n      \
    \  ll val_B = 0, mod_acc = 1;\n        for(int j=0; j<i; j++) {\n            (val_B\
    \ += mod_acc * coeff[j]) %= mods[i];\n            (mod_acc *= mods[j]) %= mods[i];\n\
    \        }\n\n        ll val = (val_A - val_B + mods[i]) % mods[i];\n        (val\
    \ *= mod_pow(mod_acc, mods[i]-2, mods[i])) %= mods[i];\n        coeff[i] = val;\n\
    \    }\n\n    ll ans = 0, mod_acc = 1;\n    for(int i=0; i<N; i++) {\n       \
    \ (ans += (mod_acc * coeff[i]) % mod) %= mod;\n        (mod_acc *= mods[i]) %=\
    \ mod;\n    }\n    return ans;\n}\n"
  code: "// Garner \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 ( \u8A08\u7B97\u91CF\
    \ O(N^2) )\n// x \u2261 a_1 (mod m_1), ..., x \u2261 a_N (mod m_N) \u3092\u6E80\
    \u305F\u3059\u6700\u5C0F\u306E x \u3092\u8FD4\u3059\n// m_1, m_2, ... m_N \u306F\
    \u76F8\u7570\u306A\u308B\u7D20\u6570\u3067\u3042\u308B\u5FC5\u8981\u304C\u3042\
    \u308B\n\n// x = k_0 + k_1*m_1 + k_2*(m_1*m_2) + ... k_{N-1}*(m_1*m_2* ... *m_{N-1})\
    \ \u3068\u3057\u3066\u3001\n// 1 \u3064\u76EE\u306E\u5F0F\u304B\u3089\u9806\u306B\
    \u64CD\u4F5C\u3059\u308B\u3053\u3068\u3067\u4FC2\u6570 k_i \u3092\u4E0B\u304B\u3089\
    \u6C7A\u5B9A\u3057\u3066\u3044\u304F\n\nll mod_pow(ll X, ll N, ll mod) {\n   \
    \ ll ret = 1;\n    for(; N>0; N>>=1) {\n        if(N & 1) (ret *= X) %= mod;\n\
    \        (X *= X) %= mod;\n    }\n    return ret;\n}\n\nll garner(vector<ll> values,\
    \ vector<ll> mods, ll mod) {\n    assert(values.size() == mods.size());\n    int\
    \ N = values.size();\n    vector<ll> coeff(N);\n\n    for(int i=0; i<N; i++) {\n\
    \        ll val_A = values[i] % mods[i];\n        ll val_B = 0, mod_acc = 1;\n\
    \        for(int j=0; j<i; j++) {\n            (val_B += mod_acc * coeff[j]) %=\
    \ mods[i];\n            (mod_acc *= mods[j]) %= mods[i];\n        }\n\n      \
    \  ll val = (val_A - val_B + mods[i]) % mods[i];\n        (val *= mod_pow(mod_acc,\
    \ mods[i]-2, mods[i])) %= mods[i];\n        coeff[i] = val;\n    }\n\n    ll ans\
    \ = 0, mod_acc = 1;\n    for(int i=0; i<N; i++) {\n        (ans += (mod_acc *\
    \ coeff[i]) % mod) %= mod;\n        (mod_acc *= mods[i]) %= mod;\n    }\n    return\
    \ ans;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_012_garner.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_012_garner.cpp
layout: document
redirect_from:
- /library/math/math_012_garner.cpp
- /library/math/math_012_garner.cpp.html
title: math/math_012_garner.cpp
---
