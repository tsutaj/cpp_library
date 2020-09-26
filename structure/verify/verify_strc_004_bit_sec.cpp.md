---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/strc_002_bit.cpp
    title: structure/strc_002_bit.cpp
  - icon: ':warning:'
    path: structure/strc_004_bit_sec.cpp
    title: structure/strc_004_bit_sec.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/verify/verify_strc_004_bit_sec.cpp\"\n#include\
    \ <vector>\n#include <algorithm>\n#include <iostream>\nusing namespace std;\n\
    #line 1 \"structure/strc_002_bit.cpp\"\n// Binary Indexed Tree (BIT)\n// Verified:\
    \ AOJ DSL_2_B: Range Sum Query (int\u306E\u307F)\n\ntemplate <typename T>\nstruct\
    \ BIT{\nprivate:\n    vector<T> array;\n    int n;\n\npublic:\n    // \u521D\u671F\
    \u5316\n    BIT() {}\n    BIT(int _n) : array(_n + 1, 0), n(_n) {}\n\n    // 1\u756A\
    \u76EE\u304B\u3089 i\u756A\u76EE\u307E\u3067\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\
    \u3081\u308B\n    T sum(int i) {\n        T s = 0;\n        while(i > 0) {\n \
    \           s += array[i];\n            i -= i & -i;      // LSB \u6E1B\u7B97\n\
    \        }\n        return s;\n    }\n\n    // [i, j] \u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\n    T sum(int i, int j) {\n        T ret_i = sum(i-1);\n       \
    \ T ret_j = sum(j);\n        return ret_j - ret_i;\n    }\n\n    // i \u756A\u76EE\
    \u306B \u8981\u7D20 x \u3092\u8FFD\u52A0\n    void add(int i, T x) {\n       \
    \ while(i <= n) {\n            array[i] += x;\n            i += i & -i;      //\
    \ LSB \u52A0\u7B97\n        }\n    }\n};\n#line 1 \"structure/strc_004_bit_sec.cpp\"\
    \n// \u6B21\u306E2\u3064\u306E\u30AF\u30A8\u30EA\u306B\u5BFE\u5FDC\u3059\u308B\
    BIT\n// \u30FB[a, b) \u306E\u8981\u7D20\u5168\u3066\u306B x \u3092\u52A0\u3048\
    \u308B\u30AF\u30A8\u30EA\n// \u30FB[a, b) \u306E\u548C\u3092\u8A08\u7B97\u3059\
    \u308B\u30AF\u30A8\u30EA\n// Verified: POJ 3468 (A Simple Problem with Integers)\n\
    \ntemplate <typename U>\nclass BIT_sec {\npublic:\n    int n;\n    BIT<U> bit0,\
    \ bit1;\n    BIT_sec(int n_) {\n        n = n_;\n        bit0 = BIT<U>(n);\n \
    \       bit1 = BIT<U>(n);\n    }\n\n    // \u6700\u521D\u306B\u8981\u7D20\u3092\
    \u8FFD\u52A0\u3059\u308B\u3068\u304D\u306F\u3053\u3063\u3061\n    void add(int\
    \ i, int x) {\n        bit0.add(i, x);\n    }\n\n    // [l, r] \u306E\u5168\u8981\
    \u7D20\u306B x \u3092\u52A0\u3048\u308B\n    void add(int l, int r, U x) {\n \
    \       bit0.add(l, -x * (l-1));\n        bit1.add(l, x);\n        bit0.add(r+1,\
    \ x*r);\n        bit1.add(r+1, -x);\n    }\n\n    U sum(int l, int r) {\n    \
    \    U res = 0;\n        res += bit0.sum(r) + bit1.sum(r) * r;\n        res -=\
    \ bit0.sum(l-1) + bit1.sum(l-1) * (l-1);\n        return res;\n    }\n};\n#line\
    \ 7 \"structure/verify/verify_strc_004_bit_sec.cpp\"\n\n// Verified on Apr 27,\
    \ 2019\nvoid DSL_2_G() {\n    int N, Q; cin >> N >> Q;\n\n    using ll = long\
    \ long int;\n    BIT_sec<ll> bit(N);\n    for(int i=0; i<Q; i++) {\n        int\
    \ query_type; cin >> query_type;\n        if(query_type == 0) {\n            int\
    \ s, t, x; cin >> s >> t >> x;\n            bit.add(s, t, x);\n        }\n   \
    \     if(query_type == 1) {\n            int s, t; cin >> s >> t;\n          \
    \  cout << bit.sum(s, t) << endl;\n        }\n    }\n}\n\nint main() {\n    DSL_2_G();\n\
    \    return 0;\n}\n"
  code: "#include <vector>\n#include <algorithm>\n#include <iostream>\nusing namespace\
    \ std;\n#include \"../strc_002_bit.cpp\"\n#include \"../strc_004_bit_sec.cpp\"\
    \n\n// Verified on Apr 27, 2019\nvoid DSL_2_G() {\n    int N, Q; cin >> N >> Q;\n\
    \n    using ll = long long int;\n    BIT_sec<ll> bit(N);\n    for(int i=0; i<Q;\
    \ i++) {\n        int query_type; cin >> query_type;\n        if(query_type ==\
    \ 0) {\n            int s, t, x; cin >> s >> t >> x;\n            bit.add(s, t,\
    \ x);\n        }\n        if(query_type == 1) {\n            int s, t; cin >>\
    \ s >> t;\n            cout << bit.sum(s, t) << endl;\n        }\n    }\n}\n\n\
    int main() {\n    DSL_2_G();\n    return 0;\n}\n"
  dependsOn:
  - structure/strc_002_bit.cpp
  - structure/strc_004_bit_sec.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_004_bit_sec.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_004_bit_sec.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_004_bit_sec.cpp
- /library/structure/verify/verify_strc_004_bit_sec.cpp.html
title: structure/verify/verify_strc_004_bit_sec.cpp
---
