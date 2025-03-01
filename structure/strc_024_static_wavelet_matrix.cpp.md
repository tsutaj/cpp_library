---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/strc_023_compact_bitvector.cpp
    title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB (compact bit vector)"
  _extendedRequiredBy:
  - icon: ':warning:'
    path: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
    title: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
    title: verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp
    title: verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_less.test.cpp
    title: "AOJ ALDS_1_5_D: \u53CD\u8EE2\u6570"
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_more.test.cpp
    title: "AOJ ALDS_1_5_D: \u53CD\u8EE2\u6570"
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp
    title: verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp
    title: verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp
    title: verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/structure/strc_024_static_wavelet_matrix.md
    document_title: "Wavelet \u884C\u5217 (wavelet matrix)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.2/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ structure/strc_024_static_wavelet_matrix.cpp: line 7: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#pragma once\n\n// @title Wavelet \u884C\u5217 (wavelet matrix)\n// @docs\
    \ docs/structure/strc_024_static_wavelet_matrix.md\n\n#ifndef call_from_test\n\
    #include \"strc_023_compact_bitvector.cpp\"\n#endif\n\n// \u30A6\u30A7\u30FC\u30D6\
    \u30EC\u30C3\u30C8\u884C\u5217 (Wavelet Matrix)\n// w \u306F \u30D3\u30C3\u30C8\
    \u5E45, 30 bit \u3067\u8868\u73FE\u3067\u304D\u308B\u6574\u6570\u306A\u3089 30\n\
    template <uint64_t word_size = 30, typename value_type = int,\n          uint64_t\
    \ ln_big = 10, uint64_t ln_sml = 4>\nstruct WaveletMatrix {\nprivate:\n    using\
    \ BitVector = CompactBitVector<value_type, ln_big, ln_sml>;\n    array<BitVector,\
    \ word_size> vecs;\n\n    // \u8981\u7D20\u6570\n    int n;\n    // k \u30D3\u30C3\
    \u30C8\u76EE\u3092\u57FA\u6E96\u306B\u5B89\u5B9A\u30BD\u30FC\u30C8\n    vector<value_type>\
    \ sort_kth_bit(const vector<value_type>& vec, int k) const;\n\n    // [l, r) \u306E\
    \u7BC4\u56F2\u5185\u306B\u3042\u308B x \u3068\u7B49\u3057\u3044\u8981\u7D20\u306F\
    \u6700\u4E0B\u6BB5\u306E\u3069\u306E\u7BC4\u56F2\u306B\u76F8\u5F53\uFF1F\n   \
    \ // select \u3059\u308B\u3068\u304D\u306B\u5229\u7528\n    pair<int, int> rank_range(int\
    \ l, int r, value_type x) const;    \n\npublic:\n    // \u30AF\u30A8\u30EA\u306F\
    \u7279\u306B\u6CE8\u91C8\u304C\u306A\u3044\u9650\u308A 0-indexed\n    // \u69CB\
    \u7BC9: O(N w)\n    WaveletMatrix(vector<value_type> vec);\n\n    // k \u756A\u76EE\
    \u306E\u5024\u3092\u5FA9\u5143: O(w)\n    // <verified> ITP1_6_A (Reversing Numbers)\n\
    \    value_type at(int k) const;\n    value_type operator[](int k) const;\n\n\
    \    // [l, r) \u306E\u7BC4\u56F2\u5185\u306B\u4EE5\u4E0B\u304C\u4F55\u500B\u5B58\
    \u5728\u3059\u308B\u304B: O(w)\n    // \u30FBx \u3088\u308A\u5C0F\u3055\u3044\u8981\
    \u7D20\n    // \u30FBx \u3068\u7B49\u3057\u3044\u8981\u7D20\n    // \u30FBx \u3088\
    \u308A\u5927\u304D\u3044\u8981\u7D20\n    tuple<int, int, int> rank_tuple(int\
    \ l, int r, value_type x) const;\n    tuple<int, int, int> rank_tuple(value_type\
    \ x) const;\n    \n    // [l, r) \u306E\u7BC4\u56F2\u5185\u3067 k \u756A\u76EE\
    \ (1-indexed) \u306B\u5C0F\u3055\u3044\u8981\u7D20\u304C\u4F55\u304B: O(w)\n \
    \   // <verified> AOJ ALDS1_6_A (Count Sort)\n    value_type quantile(int l, int\
    \ r, value_type mi, value_type ma, int k) const;\n    value_type quantile(int\
    \ l, int r, int k) const;\n    value_type quantile(int k) const;\n\n    // [l,\
    \ r) \u306E\u7BC4\u56F2\u5185\u306E m \u672A\u6E80 / m \u3092\u8D85\u3048\u308B\
    \ \u8981\u7D20\u306F\u3044\u304F\u3064\u304B: O(w)\n    // <verified> AOJ ALDS1_5_D\
    \ (The Number of Inversions)\n    int freq_less(int l, int r, value_type m) const;\n\
    \    int freq_less(value_type m) const;\n    int freq_greater(int l, int r, value_type\
    \ m) const;\n    int freq_greater(value_type m) const;\n    \n    // [l, r) \u306E\
    \u7BC4\u56F2\u5185\u306B x \\in [mi, ma] \u3092\u6E80\u305F\u3059 x \u304C\u3044\
    \u304F\u3064\u51FA\u3066\u304D\u305F\u304B: O(w)\n    // [mi, ma] \u306F\u9589\
    \u533A\u9593\uFF01\uFF01\n    // <verified> AOJ 1549 (Hard Beans)\n    // <verified>\
    \ AOJ 2426 (Treasure Hunt)\n    int freq(int l, int r, value_type mi, value_type\
    \ ma) const;\n    int freq(int l, int r, value_type x) const;\n    int freq(value_type\
    \ mi, value_type ma) const;\n    \n    // [l, r) \u306E\u7BC4\u56F2\u5185\u306B\
    \u3042\u308B\u8981\u7D20\u306E\u6700\u5C0F\u5024 (quantile \u518D\u5229\u7528\
    ): O(w)\n    // <verified> AOJ DSL_3_D (Sliding Minimum Elements)\n    value_type\
    \ min_value(int l, int r, value_type mi, value_type ma) const;\n    value_type\
    \ min_value(int l, int r) const;\n    value_type min_value() const;\n\n    //\
    \ [l, r) \u306E\u7BC4\u56F2\u5185\u306B\u3042\u308B\u8981\u7D20\u306E\u6700\u5927\
    \u5024 (quantile \u518D\u5229\u7528): O(w)\n    value_type max_value(int l, int\
    \ r, value_type mi, value_type ma) const;\n    value_type max_value(int l, int\
    \ r) const;\n    value_type max_value() const;\n\n    // [l, r) \u306E\u7BC4\u56F2\
    \u5185\u306B\u3042\u308B k \u756A\u76EE (1-indexed) \u306E x \u306E\u4F4D\u7F6E\
    : O(w log N)\n    int select(int l, int r, int k, value_type x) const;\n    int\
    \ select(int k, value_type x) const;\n\n    // k \u756A\u76EE\u306E\u8981\u7D20\
    \u3068\u5024\u304C\u7B49\u3057\u3044\u3082\u306E\u3067\u3001k \u756A\u76EE\u306E\
    \u76F4\u5F8C / \u76F4\u524D\u306E\u8981\u7D20 idx: O(w log N)\n    int next_idx(int\
    \ k) const;\n    int prev_idx(int k) const;\n\n    // [l, r) \u306E\u7BC4\u56F2\
    \u5185\u306B\u3042\u308B\u3001x \u672A\u6E80 / x \u3092\u8D85\u3048\u308B\u8981\
    \u7D20\u306E\u3046\u3061 \u6700\u5927 / \u6700\u5C0F \u3067\u3042\u308B\u3082\u306E\
    : O(w)\n    // <verified> AOJ 1549 (Hard Beans)\n    value_type next_val(int l,\
    \ int r, value_type x) const;\n    value_type prev_val(int l, int r, value_type\
    \ x) const;\n};\n\ntemplate <uint64_t word_size, typename value_type,\n      \
    \    uint64_t ln_big, uint64_t ln_sml>\nvector<value_type> WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::sort_kth_bit(const vector<value_type>& vec, int\
    \ k) const {\n    vector<value_type> v0, v1;\n    v0.reserve(vec.size()), v1.reserve(vec.size());\n\
    \    for(size_t i=0; i<vec.size(); i++) {\n        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);\n\
    \    }\n    v0.insert(v0.end(), v1.begin(), v1.end());\n    return v0;\n}\n\n\
    template <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\npair<int, int> WaveletMatrix<word_size, value_type, ln_big,\
    \ ln_sml>::rank_range(int l, int r, value_type x) const {\n    for(size_t i=0;\
    \ i<word_size; i++) {\n        int all1 = vecs[i].rank(n-1), all0 = n - all1;\n\
    \        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;\n\
    \        if(x >> (word_size - i - 1) & 1) {\n            l = all0 + vecs[i].rank(l-1),\
    \ r = l + cnt1;\n        }\n        else {\n            l = l - vecs[i].rank(l-1),\
    \ r = l + cnt0;\n        }\n    }\n    return make_pair(l, r);\n}\n\ntemplate\
    \ <uint64_t word_size, typename value_type,\n          uint64_t ln_big, uint64_t\
    \ ln_sml>\nWaveletMatrix<word_size, value_type, ln_big, ln_sml>::WaveletMatrix(vector<value_type>\
    \ vec) : n(vec.size()) {\n    vecs[0] = BitVector(vec, word_size - 1);\n    for(size_t\
    \ i=1; i<word_size; i++) {\n        vec = sort_kth_bit(vec, word_size - i);\n\
    \        vecs[i] = BitVector(vec, word_size - i - 1);\n    }\n}\n\ntemplate <uint64_t\
    \ word_size, typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\n\
    value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::at(int k) const\
    \ {\n    int b = k; value_type res = 0;\n    for(size_t i=0; i<word_size; i++)\
    \ {\n        int all1 = vecs[i].rank(n-1), all0 = n - all1;\n        int cnt1\
    \ = vecs[i].rank(b), cnt0 = b + 1 - cnt1;\n        if(vecs[i][b] == 1) {\n   \
    \         res |= (1ULL << (word_size - 1 - i));\n            b = all0 + cnt1 -\
    \ 1;\n        }\n        else {\n            b = cnt0 - 1;\n        }\n    }\n\
    \    return res;\n}\n\ntemplate <uint64_t word_size, typename value_type,\n  \
    \        uint64_t ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::operator[](int k) const {\n    return at(k);\n\
    }\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\ntuple<int, int, int> WaveletMatrix<word_size, value_type,\
    \ ln_big, ln_sml>::rank_tuple(int l, int r, value_type x) const {\n    int small\
    \ = 0, equal = 0, big = 0;\n    for(size_t i=0; i<word_size; i++) {\n        int\
    \ all1 = vecs[i].rank(n-1), all0 = n - all1;\n        int cnt1 = vecs[i].rank(r-1)\
    \ - vecs[i].rank(l-1), cnt0 = r - l - cnt1;\n        if(x >> (word_size - i -\
    \ 1) & 1) {\n            small += cnt0;\n            l = all0 + vecs[i].rank(l-1),\
    \ r = l + cnt1;\n        }\n        else {\n            big += cnt1;\n       \
    \     l = l - vecs[i].rank(l-1), r = l + cnt0;\n        }\n    }\n    equal =\
    \ r - l;\n    return make_tuple(small, equal, big);\n}\n\ntemplate <uint64_t word_size,\
    \ typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\ntuple<int,\
    \ int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(value_type\
    \ x) const {\n    return rank_tuple(0, n, x);\n}\n\ntemplate <uint64_t word_size,\
    \ typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nvalue_type\
    \ WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r,\
    \ value_type mi, value_type ma, int k) const {\n    int cnt_less = freq_less(l,\
    \ r, mi), cnt_greater = freq_greater(l, r, ma);\n    if(r - l - cnt_less - cnt_greater\
    \ < k) return -1;\n    return quantile(l, r, k + cnt_less);\n}\n\ntemplate <uint64_t\
    \ word_size, typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\n\
    value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int\
    \ l, int r, int k) const {\n    if(r - l < k) return -1;\n    value_type res =\
    \ 0;\n    for(size_t i=0; i<word_size; i++) {\n        int all1 = vecs[i].rank(n-1),\
    \ all0 = n - all1;\n        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1),\
    \ cnt0 = r - l - cnt1;\n        if(cnt0 >= k) {\n            l = l - vecs[i].rank(l-1),\
    \ r = l + cnt0;\n        }\n        else {\n            k -= cnt0;\n         \
    \   res |= 1ULL << (word_size - 1 - i);\n            l = all0 + vecs[i].rank(l-1),\
    \ r = l + cnt1;\n        }\n    }\n    return res;\n}\n\ntemplate <uint64_t word_size,\
    \ typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nvalue_type\
    \ WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int k) const\
    \ {\n    return quantile(0, n, k);\n}\n\ntemplate <uint64_t word_size, typename\
    \ value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::freq_less(int l, int r, value_type m) const {\n\
    \    int res = 0;\n    for(size_t i=0; i<word_size; i++) {\n        int all1 =\
    \ vecs[i].rank(n-1), all0 = n - all1;\n        int cnt1 = vecs[i].rank(r-1) -\
    \ vecs[i].rank(l-1), cnt0 = r - l - cnt1;\n        if(m >> (word_size - 1 - i)\
    \ & 1) {\n            res += cnt0;\n            l = all0 + vecs[i].rank(l-1),\
    \ r = l + cnt1;\n        }\n        else {\n            l = l - vecs[i].rank(l-1),\
    \ r = l + cnt0;\n        }\n    }\n    return res;\n}\n\ntemplate <uint64_t word_size,\
    \ typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::freq_less(value_type m) const {\n    return freq_less(0,\
    \ n, m);\n}\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t\
    \ ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(int\
    \ l, int r, value_type m) const {\n    int res = 0;\n    for(size_t i=0; i<word_size;\
    \ i++) {\n        int all1 = vecs[i].rank(n-1), all0 = n - all1;\n        int\
    \ cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;\n       \
    \ if(m >> (word_size - 1 - i) & 1) {\n            l = all0 + vecs[i].rank(l-1),\
    \ r = l + cnt1;\n        }\n        else {\n            res += cnt1;\n       \
    \     l = l - vecs[i].rank(l-1), r = l + cnt0;\n        }\n    }\n    return res;\n\
    }\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(value_type\
    \ m) const {\n    return freq_greater(0, n, m);\n}\n\ntemplate <uint64_t word_size,\
    \ typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::freq(int l, int r, value_type mi, value_type ma)\
    \ const {\n    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);\n\
    }\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int\
    \ l, int r, value_type x) const {\n    return freq(l, r, x, x);\n}\n\ntemplate\
    \ <uint64_t word_size, typename value_type,\n          uint64_t ln_big, uint64_t\
    \ ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(value_type\
    \ mi, value_type ma) const {\n    return freq(0, n, mi, ma);\n}\n\ntemplate <uint64_t\
    \ word_size, typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\n\
    value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int\
    \ l, int r, value_type mi, value_type ma) const {\n    return quantile(l, r, mi,\
    \ ma, 1);\n}\n\ntemplate <uint64_t word_size, typename value_type,\n         \
    \ uint64_t ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size, value_type,\
    \ ln_big, ln_sml>::min_value(int l, int r) const {\n    return quantile(l, r,\
    \ 1);\n}\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t\
    \ ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size, value_type, ln_big,\
    \ ln_sml>::min_value() const {\n    return min_value(0, n);\n}\n\ntemplate <uint64_t\
    \ word_size, typename value_type,\n          uint64_t ln_big, uint64_t ln_sml>\n\
    value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int\
    \ l, int r, value_type mi, value_type ma) const {\n    return quantile(l, r, mi,\
    \ ma, freq(l, r, mi, ma));\n}\n\ntemplate <uint64_t word_size, typename value_type,\n\
    \          uint64_t ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::max_value(int l, int r) const {\n    return quantile(l,\
    \ r, r - l);\n}\n\ntemplate <uint64_t word_size, typename value_type,\n      \
    \    uint64_t ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size, value_type,\
    \ ln_big, ln_sml>::max_value() const {\n    return max_value(0, n);\n}\n\ntemplate\
    \ <uint64_t word_size, typename value_type,\n          uint64_t ln_big, uint64_t\
    \ ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int\
    \ l, int r, int k, value_type x) const {\n    if(k <= 0) return -1;\n    tie(l,\
    \ r) = rank_range(l, r, x);\n    if(r - l < k) return -1;\n\n    int pos = l +\
    \ k - 1;\n    for(size_t i=0; i<word_size; i++) {\n        int b = x >> i & 1;\n\
    \        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;\n    \
    \    if(b == 0) {\n            int m = pos;\n            pos = vecs[word_size\
    \ - 1 - i].select0(m, n);\n        }\n        else {\n            int m = pos\
    \ - cnt0;\n            pos = vecs[word_size - 1 - i].select1(m, n);\n        }\n\
    \    }\n    return pos;\n}\n\ntemplate <uint64_t word_size, typename value_type,\n\
    \          uint64_t ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type,\
    \ ln_big, ln_sml>::select(int k, value_type x) const {\n    return select(0, n,\
    \ k, x);\n}\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t\
    \ ln_big, uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_idx(int\
    \ k) const {\n    int m = freq(0, k+1, at(k));\n    return select(m+1, at(k));\n\
    }\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\nint WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_idx(int\
    \ k) const {\n    int m = freq(0, k+1, at(k));\n    return select(m-1, at(k));\n\
    }\n\ntemplate <uint64_t word_size, typename value_type,\n          uint64_t ln_big,\
    \ uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_val(int\
    \ l, int r, value_type x) const {\n    int k = r - l - freq_greater(l, r, x) +\
    \ 1;\n    return quantile(l, r, k);\n}\n\ntemplate <uint64_t word_size, typename\
    \ value_type,\n          uint64_t ln_big, uint64_t ln_sml>\nvalue_type WaveletMatrix<word_size,\
    \ value_type, ln_big, ln_sml>::prev_val(int l, int r, value_type x) const {\n\
    \    return quantile(l, r, freq_less(l, r, x));\n}\n"
  dependsOn:
  - structure/strc_023_compact_bitvector.cpp
  isVerificationFile: false
  path: structure/strc_024_static_wavelet_matrix.cpp
  requiredBy:
  - structure/verify/verify_strc_024_static_wavelet_matrix.cpp
  timestamp: '2022-01-28 02:17:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp
  - verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp
  - verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp
  - verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
  - verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_more.test.cpp
  - verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_less.test.cpp
  - verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp
documentation_of: structure/strc_024_static_wavelet_matrix.cpp
layout: document
redirect_from:
- /library/structure/strc_024_static_wavelet_matrix.cpp
- /library/structure/strc_024_static_wavelet_matrix.cpp.html
title: "Wavelet \u884C\u5217 (wavelet matrix)"
---
### 静的ウェーブレット行列 (Wavelet Matrix)

簡潔ビットベクトルにより非負整数列に対する各種クエリを高速に処理可能

#### Usage

* 注釈が特にないものは 0-indexed
* 変数について
  * $N$: 数列の長さ
  * $\sigma$: 値域
* **Usage、ソースコードの中身は間違っているかもしれません: 指摘があれば教えてください**

| メソッド                                                                        | 説明                                                                                                                                         | 計算量               |
|---------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------|----------------------|
| `WaveletMatrix(vec)`                                        | vector から Wavelet 行列を構築                                                                                                                           | $O(N \log \sigma)$ |
| `at(k)`                                                   | 列のインデックス $k$ 番目 (0-indexed) にアクセス                                                                                                                    | $O(\log \sigma)$   |
| `operator[](k)`                                           | 列のインデックス $k$ 番目 (0-indexed) にアクセス                                                                                                                                         | $O(\log \sigma)$                 |
| `rank_tuple(l, r, x)`            | インデックス $\left[ l, r \right)$ の範囲内に ($x$ 未満、$x$ と等しい、$x$ を超える) 要素がそれぞれいくつ存在するか答える                         | $O(\log \sigma)$   |
| `rank_tuple(x)`                          | 数列全体で ($x$ 未満、$x$ と等しい、$x$ を超える) 要素がそれぞれいくつ存在するか答える                                                                                                               | $O(\log \sigma)$                 |
| `quantile(l, r, mi, ma, k)` | インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち、$k$ 番目 (1-indexed) に小さいものを答える | $O(\log \sigma)$   |
|`quantile(l, r, k)`| インデックス $\left[ l, r \right)$ の範囲内にある要素のうち、$k$ 番目 (1-indexed) に小さいものを答える | $O(\log \sigma)$ |
|`quantile(k)`|数列全体で $k$ 番目 (1-indexed) に小さいものを答える| $O(\log \sigma)$ |
|`freq_less(l, r, m)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $m$ 未満の要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq_less(m)`|数列全体に値が $m$ 未満の要素がいくつ存在するか答える|$O(\log \sigma)$|
|`freq_greater(l, r, m)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $m$ を超える要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq_greater(m)`|数列全体に値が $m$ を超える要素がいくつ存在するか答える|$O(\log \sigma)$|
|`freq(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ と等しい要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`freq(mi, ma)`|数列全体に値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素がいくつ存在するか答える | $O(\log \sigma)$ |
|`min_value(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち最小値を答える| $O(\log \sigma)$|
|`min_value(l, r)`|インデックス $\left[ l, r \right)$ の範囲内にある要素のうち最小値を答える| $O(\log \sigma)$|
|`min_value()`|数列全体の要素の最小値を答える| $O(\log \sigma)$|
|`max_value(l, r, mi, ma)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $\left[ \mathrm{mi}, \mathrm{ma} \right]$ に収まる要素のうち最大値を答える| $O(\log \sigma)$|
|`max_value(l, r)`|インデックス $\left[ l, r \right)$ の範囲内にある要素のうち最大値を答える| $O(\log \sigma)$|
|`max_value()`|数列全体の要素の最大値を答える| $O(\log \sigma)$|
|`select(l, r, k, x)`|インデックス $\left[ l, r \right)$ の範囲内にある $x$ と等しい要素のうち $k$ 番目 (1-indexed) にある値のインデックスを答える| $O(\log \sigma \log N)$ |
|`select(k, x)`|数列全体で $x$ と等しい要素のうち $k$ 番目 (1-indexed) にある値のインデックスを答える| $O(\log \sigma \log N)$ |
|`next_val(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ を超える要素の中で最小のものを答える| $O(\log \sigma \log N)$ |
|`prev_val(l, r, x)`|インデックス $\left[ l, r \right)$ の範囲内にあって値が $x$ 未満の要素の中で最小のものを答える| $O(\log \sigma \log N)$ |
