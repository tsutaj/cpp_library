---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/strc_023_compact_bitvector.cpp
    title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB (compact bit vector)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/verify/verify_strc_023_compact_bitvector.cpp\"\
    \n#include <cinttypes>\n#include <iostream>\n#include <cstdio>\n#include <vector>\n\
    #include <algorithm>\nusing namespace std;\n#line 2 \"structure/strc_023_compact_bitvector.cpp\"\
    \n\n// @title \u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB (compact\
    \ bit vector)\n// \u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB (\u6570\
    \u5217\u306E\u9577\u3055\u3092 N \u3068\u3059\u308B)\n// n_big <- log^2(N)   (N\
    \ = 2^32 \u3068\u3057\u305F\u3068\u304D\u3001n_big = 32^2 = 1024 = 2^10)\n// n_sml\
    \ <- log(N) / 2 (N = 2^32 \u3068\u3057\u305F\u3068\u304D\u3001n_sml = 32/2 = 16\
    \ = 2^4)\n// n_blk <- n_big \u3092 n_sml \u3067\u5272\u3063\u305F\u3082\u306E\n\
    // ln_big, ln_sml \u306B\u306F\u3001\u305D\u308C\u305E\u308C log(n_big), log(n_sml)\
    \ \u3092\u3044\u308C\u308B\n\ntemplate <typename value_type = int,\n         \
    \ uint64_t ln_big = 10, uint64_t ln_sml = 4>\nstruct CompactBitVector {\nprivate:\n\
    \    size_t n, n_big, n_sml, n_blk, ln_blk;\n    vector<value_type> big, sml,\
    \ bit;\n    \n    int popcount(value_type b) const {\n        return __builtin_popcountll(b);\
    \ // GCC builtin function\n    }\n    void build(vector<value_type> vec);\n\n\
    public:\n    // \u69CB\u7BC9: O(N)\n    CompactBitVector();\n    CompactBitVector(vector<value_type>\
    \ vec);\n    CompactBitVector(vector<value_type> vec, int k);\n    // \u6570\u5217\
    \u306E\u30B5\u30A4\u30BA: O(1)\n    size_t size() const;\n    // \u5168\u4F53\u306E\
    \ 1 \u306E\u500B\u6570: O(1)\n    int count() const;\n    // k \u756A\u76EE\u306E\
    \u5024: O(1)\n    int value(size_t k) const;\n    // [0, k] \u306B\u5B58\u5728\
    \u3059\u308B 1 \u306E\u500B\u6570: O(1)\n    int rank(size_t k) const;\n    //\
    \ [l, r) \u306B\u5B58\u5728\u3059\u308B 1 \u306E\u500B\u6570: O(1)\n    int rank(size_t\
    \ l, size_t r) const;\n    // 1 / 0 \u306E\u500B\u6570 \u304C r \u3092\u8D85\u3048\
    \u308B\u3001\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 k \u672A\u6E80\u6700\u5C0F\u306E\
    \u8981\u7D20\u3092\u8FD4\u3059: O(log N)\n    int select1(int r, int k) const;\n\
    \    int select0(int r, int k) const;\n    // k \u756A\u76EE\u306E\u6B21\u306B\
    \u5B58\u5728\u3059\u308B 1 / 0 \u306F\u4F55\u304B: O(log N)\n    int select1_nxt(size_t\
    \ k) const;\n    int select0_nxt(size_t k) const;\n    // k \u756A\u76EE\u306E\
    \u524D\u306B\u5B58\u5728\u3059\u308B 1 / 0 \u306F\u4F55\u304B: O(log N)\n    int\
    \ select1_pre(size_t k) const;\n    int select0_pre(size_t k) const;\n    // \u30D3\
    \u30C3\u30C8\u30D9\u30AF\u30C8\u30EB\u306E k \u756A\u76EE\u306B\u30A2\u30AF\u30BB\
    \u30B9\n    int at(size_t k) const;\n    int operator[](size_t k) const;\n\n \
    \   // \u51FA\u529B\u3059\u308B\u3060\u3051\n    void show() const {\n       \
    \ cerr << \"# big \";\n        for(size_t i=0; i<big.size(); i++) {\n        \
    \    cerr << big[i] << \" \";\n        }\n        cerr << endl;\n        cerr\
    \ << \"# sml \";\n        for(size_t i=0; i<sml.size(); i++) {\n            cerr\
    \ << sml[i] << \" \";\n        }\n        cerr << endl;\n        cerr << \"# bit\
    \ \";\n        for(size_t i=0; i<bit.size(); i++) {\n            cerr << bit[i]\
    \ << \" \";\n        }\n        cerr << endl;\n    }\n};\n\ntemplate <typename\
    \ value_type, uint64_t ln_big, uint64_t ln_sml>\nvoid CompactBitVector<value_type,\
    \ ln_big, ln_sml>::build(vector<value_type> vec) {\n    big.resize(((n + n_big\
    \ - 1) >> ln_big) + 1); // O(N / log^2 N) memory\n    sml.resize(big.size() <<\
    \ ln_blk); // O(N / log N) memory\n    bit.resize(big.size() << ln_blk); // O(N\
    \ / log N) memory\n    for(size_t i=0; i<n; i++) {\n        size_t b = i >> ln_big;\n\
    \        big[b+1] += vec[i];\n        size_t s = i >> ln_sml, m = i & (n_sml -\
    \ 1);\n        sml[s] += vec[i];\n        bit[s] |= (static_cast<value_type>(vec[i])\
    \ << m);\n    }\n\n    // accumulate\n    for(size_t i=1; i<big.size(); i++) big[i]\
    \ += big[i-1];\n    for(size_t i=0; i<big.size(); i++) {\n        for(size_t j=1;\
    \ j<n_blk; j++) {\n            sml[(i << ln_blk) + j] += sml[(i << ln_blk) + j\
    \ - 1];\n        }\n    }\n}\n\ntemplate <typename value_type, uint64_t ln_big,\
    \ uint64_t ln_sml>\nCompactBitVector<value_type, ln_big, ln_sml>::CompactBitVector()\
    \ {}\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nCompactBitVector<value_type,\
    \ ln_big, ln_sml>::CompactBitVector(vector<value_type> vec)\n    : n(vec.size()),\
    \ n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),\n      n_blk(n_big >> ln_sml),\
    \ ln_blk(ln_big - ln_sml) {\n    build(vec);\n}\n\ntemplate <typename value_type,\
    \ uint64_t ln_big, uint64_t ln_sml>\nCompactBitVector<value_type, ln_big, ln_sml>::CompactBitVector(vector<value_type>\
    \ vec, int k)\n    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),\n\
    \      n_blk(n_big >> ln_sml), ln_blk(ln_big - ln_sml) {\n    vector<value_type>\
    \ n_vec;\n    for(auto e : vec) n_vec.emplace_back(e >> k & 1);\n    build(n_vec);\n\
    }\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nsize_t\
    \ CompactBitVector<value_type, ln_big, ln_sml>::size() const {\n    return n;\n\
    }\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::count() const {\n    return rank(n-1);\n}\n\ntemplate <typename\
    \ value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::value(size_t k) const {\n    if(k >= n) return 0;\n    size_t\
    \ m = k & (n_sml - 1);\n    return bit[k >> ln_sml] >> m & 1;\n}\n\ntemplate <typename\
    \ value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::rank(size_t k) const {\n    if(k >= n) return 0; // for range\
    \ query\n    size_t m = k & (n_sml - 1), mask = (1ULL << n_sml) - (1ULL << (m+1));\n\
    \    return big[k >> ln_big] + sml[k >> ln_sml] - popcount(bit[k >> ln_sml] &\
    \ mask);\n}\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\n\
    int CompactBitVector<value_type, ln_big, ln_sml>::rank(size_t l, size_t r) const\
    \ {\n    if(l >= r) return 0;\n    return rank(r-1) - rank(l-1);\n}\n\ntemplate\
    \ <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::select1(int r, int k) const {\n    int ub = n+1, lb = -1;\n\
    \    while(ub - lb > 1) {\n        int mid = (ub + lb) / 2;\n        if(rank(mid)\
    \ > r) ub = mid;\n        else lb = mid;\n    }\n    return (ub < k) ? ub : -1;\n\
    }\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::select0(int r, int k) const {\n    int ub = n+1, lb = -1;\n\
    \    while(ub - lb > 1) {\n        int mid = (ub + lb) / 2;\n        if(mid +\
    \ 1 - rank(mid) > r) ub = mid;\n        else lb = mid;\n    }\n    return (ub\
    \ < k) ? ub : -1;\n}\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t\
    \ ln_sml>\nint CompactBitVector<value_type, ln_big, ln_sml>::select1_nxt(size_t\
    \ k) const {\n    return select1(rank(k), n);\n}\n\ntemplate <typename value_type,\
    \ uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type, ln_big,\
    \ ln_sml>::select0_nxt(size_t k) const {\n    return select0(rank(k), n);\n}\n\
    \ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::select1_pre(size_t k) const {\n    return select1(rank(k) -\
    \ 1 - value(k), k);\n}\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t\
    \ ln_sml>\nint CompactBitVector<value_type, ln_big, ln_sml>::select0_pre(size_t\
    \ k) const {\n    return select0(rank(k) - 1 - value(k), k);\n}\n\ntemplate <typename\
    \ value_type, uint64_t ln_big, uint64_t ln_sml>\nint CompactBitVector<value_type,\
    \ ln_big, ln_sml>::at(size_t k) const {\n    return bit[k >> ln_sml] >> (k & (n_sml\
    \ - 1)) & 1;\n}\n\ntemplate <typename value_type, uint64_t ln_big, uint64_t ln_sml>\n\
    int CompactBitVector<value_type, ln_big, ln_sml>::operator[](size_t k) const {\n\
    \    return at(k);\n}\n#line 8 \"structure/verify/verify_strc_023_compact_bitvector.cpp\"\
    \n\nint main() {\n    int N; cin >> N;\n    vector<int> vec(N);\n    for(int i=0;\
    \ i<N; i++) cin >> vec[i];\n\n    SuccinctBitVector<> sb(vec);\n    for(int i=0;\
    \ i<N; i++) {\n        cout << sb.rank(i) << \" \";\n    }\n    cout << endl;\n\
    \    for(int i=0; i<N; i++) {\n        int a = sb.select_nxt(i);\n        cout\
    \ << (a < 0 ? -1 : a + 1) << \" \";\n    }\n    cout << endl;\n    for(int i=0;\
    \ i<N; i++) {\n        int a = sb.select_pre(i);\n        cout << (a < 0 ? -1\
    \ : a + 1) << \" \";\n    }\n    cout << endl;\n\n    cout << \"count: \" << sb.count()\
    \ << \", size = \" << sb.size() << endl;\n    \n/*\n    while(true) {\n      \
    \  int q; cin >> q;\n        if(q == 1) {\n            int k; cin >> k; k--;\n\
    \            cout << sb.rank(k) << endl;\n        }\n        if(q == 2) {\n  \
    \          int k; cin >> k; k--;\n            int a = sb.select_nxt(k);\n    \
    \        cout << (a < 0 ? -1 : a + 1) << endl;\n        }\n        if(q == 3)\
    \ {\n            int k; cin >> k; k--;\n            int a = sb.select_pre(k);\n\
    \            cout << (a < 0 ? -1 : a + 1) << endl;\n        }\n        if(q ==\
    \ 4) {\n            int l, r; cin >> l >> r; l--;\n            cout << sb.rank(l,\
    \ r) << endl;\n        }\n    }\n*/\n    return 0;\n}\n"
  code: "#include <cinttypes>\n#include <iostream>\n#include <cstdio>\n#include <vector>\n\
    #include <algorithm>\nusing namespace std;\n#include \"../strc_023_compact_bitvector.cpp\"\
    \n\nint main() {\n    int N; cin >> N;\n    vector<int> vec(N);\n    for(int i=0;\
    \ i<N; i++) cin >> vec[i];\n\n    SuccinctBitVector<> sb(vec);\n    for(int i=0;\
    \ i<N; i++) {\n        cout << sb.rank(i) << \" \";\n    }\n    cout << endl;\n\
    \    for(int i=0; i<N; i++) {\n        int a = sb.select_nxt(i);\n        cout\
    \ << (a < 0 ? -1 : a + 1) << \" \";\n    }\n    cout << endl;\n    for(int i=0;\
    \ i<N; i++) {\n        int a = sb.select_pre(i);\n        cout << (a < 0 ? -1\
    \ : a + 1) << \" \";\n    }\n    cout << endl;\n\n    cout << \"count: \" << sb.count()\
    \ << \", size = \" << sb.size() << endl;\n    \n/*\n    while(true) {\n      \
    \  int q; cin >> q;\n        if(q == 1) {\n            int k; cin >> k; k--;\n\
    \            cout << sb.rank(k) << endl;\n        }\n        if(q == 2) {\n  \
    \          int k; cin >> k; k--;\n            int a = sb.select_nxt(k);\n    \
    \        cout << (a < 0 ? -1 : a + 1) << endl;\n        }\n        if(q == 3)\
    \ {\n            int k; cin >> k; k--;\n            int a = sb.select_pre(k);\n\
    \            cout << (a < 0 ? -1 : a + 1) << endl;\n        }\n        if(q ==\
    \ 4) {\n            int l, r; cin >> l >> r; l--;\n            cout << sb.rank(l,\
    \ r) << endl;\n        }\n    }\n*/\n    return 0;\n}\n"
  dependsOn:
  - structure/strc_023_compact_bitvector.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_023_compact_bitvector.cpp
  requiredBy: []
  timestamp: '2020-04-07 00:18:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_023_compact_bitvector.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_023_compact_bitvector.cpp
- /library/structure/verify/verify_strc_023_compact_bitvector.cpp.html
title: structure/verify/verify_strc_023_compact_bitvector.cpp
---
