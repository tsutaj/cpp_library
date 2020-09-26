---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/strc_023_compact_bitvector.cpp
    title: "\u7C21\u6F54\u30D3\u30C3\u30C8\u30D9\u30AF\u30C8\u30EB (compact bit vector)"
  - icon: ':heavy_check_mark:'
    path: structure/strc_024_static_wavelet_matrix.cpp
    title: "Wavelet \u884C\u5217 (wavelet matrix)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 398, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ structure/strc_024_static_wavelet_matrix.cpp: line 7: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#include <vector>\n#include <array>\n#include <algorithm>\n#include <cinttypes>\n\
    #include <iostream>\n#include <tuple>\n#include <utility>\nusing namespace std;\n\
    #include \"../strc_023_compact_bitvector.cpp\"\n#include \"../strc_024_static_wavelet_matrix.cpp\"\
    \n\nint main() {\n    vector<int> vec = {2, 10, 2, 3, 2, 5, 4, 4};\n    WaveletMatrix<4>\
    \ wm(vec);\n    \n    for(size_t i=0; i<vec.size(); i++) {\n        cerr << wm[i]\
    \ << \" \";\n    }\n    cerr << endl;\n\n    while(true) {\n        // int k,\
    \ x; cin >> k >> x; k--;\n        // cout << wm.rank_idx(k, x) << endl;\n    \
    \    int l, r, k, x; cin >> l >> r >> k >> x; l--;\n        cout << wm.select(l,\
    \ r, k, x) << endl;\n        // cout << res << endl;\n    }\n    return 0;\n}\n"
  dependsOn:
  - structure/strc_023_compact_bitvector.cpp
  - structure/strc_024_static_wavelet_matrix.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2020-07-13 09:29:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_024_static_wavelet_matrix.cpp
- /library/structure/verify/verify_strc_024_static_wavelet_matrix.cpp.html
title: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
---
