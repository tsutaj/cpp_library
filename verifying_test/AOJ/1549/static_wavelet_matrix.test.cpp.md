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
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.2/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ structure/strc_024_static_wavelet_matrix.cpp: line 7: unable to process #include\
    \ in #if / #ifdef / #ifndef other than include guards\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549\"\
    \n#define DESCRIPTION \"\\\"\u9589\u533A\u9593\\\" $\\left[ l, r \\right]$ \u306B\
    \u3042\u308B\u6574\u6570\u306E\u4E2D\u3067 $D$ \u306B\u6700\u3082\u8FD1\u3044\u3082\
    \u306E\u3092\u6C42\u3081\u308B\"\n\n// #define _GLIBCXX_DEBUG // for STL debug\
    \ (optional)\n#include <iostream>\n#include <iomanip>\n#include <cstdio>\n#include\
    \ <string>\n#include <cstring>\n#include <deque>\n#include <list>\n#include <queue>\n\
    #include <stack>\n#include <vector>\n#include <utility>\n#include <algorithm>\n\
    #include <map>\n#include <set>\n#include <complex>\n#include <cmath>\n#include\
    \ <limits>\n#include <cfloat>\n#include <climits>\n#include <ctime>\n#include\
    \ <cassert>\n#include <numeric>\n#include <fstream>\n#include <functional>\n#include\
    \ <bitset>\nusing namespace std;\nusing ll = long long int;\nusing int64 = long\
    \ long int;\n \ntemplate<typename T> void chmax(T &a, T b) {a = max(a, b);}\n\
    template<typename T> void chmin(T &a, T b) {a = min(a, b);}\ntemplate<typename\
    \ T> void chadd(T &a, T b) {a = a + b;}\n \nint dx[] = {0, 0, 1, -1};\nint dy[]\
    \ = {1, -1, 0, 0};\nconst int INF = 1LL << 29;\nconst ll LONGINF = 1LL << 60;\n\
    const ll MOD = 1000000007LL;\n\n#define call_from_test\n#include \"../../../structure/strc_023_compact_bitvector.cpp\"\
    \n#include \"../../../structure/strc_024_static_wavelet_matrix.cpp\"\n#undef call_from_test\n\
    \nint main() {\n    int N; scanf(\"%d\", &N);\n\n    int ofs = 1 << 20;\n    vector<int>\
    \ A(N);\n    for(int i=0; i<N; i++) scanf(\"%d\", &A[i]), A[i] += ofs;\n    WaveletMatrix<25>\
    \ wm(A);\n\n    int Q; scanf(\"%d\", &Q);\n    for(int i=0; i<Q; i++) {\n    \
    \    int l, r, d; scanf(\"%d%d%d\", &l, &r, &d);\n        r++; d += ofs;\n   \
    \     if(wm.freq(l, r, d) > 0) printf(\"0\\n\");\n        else {\n           \
    \ int vu = wm.next_val(l, r, d);\n            int vd = wm.prev_val(l, r, d);\n\
    \            int ans = ofs;\n            if(vu != -1) ans = min(ans, vu - d);\n\
    \            if(vd != -1) ans = min(ans, d - vd);\n            printf(\"%d\\n\"\
    , ans);\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - structure/strc_023_compact_bitvector.cpp
  - structure/strc_024_static_wavelet_matrix.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
  requiredBy: []
  timestamp: '2020-07-13 09:29:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
- /verify/verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp.html
title: verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp
---
