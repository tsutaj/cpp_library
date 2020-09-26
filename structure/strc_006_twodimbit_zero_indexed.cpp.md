---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_006_twodimbit_zero_indexed.cpp\"\n// 0-indexed\
    \ 2\u6B21\u5143BIT\n// Verified: JOI 10 \u672C\u9078 Planetary Exploration\ntemplate\
    \ <typename T>\nstruct zeroIndexedTwodimBIT{\nprivate:\n    vector< vector<T>\
    \ > array;\n    const int n;\n    const int m;\n\npublic:\n    // \u521D\u671F\
    \u5316\n    zeroIndexedTwodimBIT(int _n, int _m) : array(_n+1, vector<T>(_m+1,\
    \ 0)), n(_n), m(_m) {}\n\n    // (0, 0) \u304B\u3089 (x, y) \u307E\u3067\u306E\
    \u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int x, int y) {\n      \
    \  T s = 0;\n        for(int i=x; i>=0; i = (i&(i+1))-1)\n            for(int\
    \ j=y; j>=0; j = (j&(j+1))-1)\n                s += array[i][j];\n        return\
    \ s;\n    }\n\n    // [(x1, y1), (x2, y2)]\u306E\u8981\u7D20\u306E\u7DCF\u548C\
    \n    T sum(int x1, int y1, int x2, int y2) {\n        return sum(x2, y2) - sum(x1-1,\
    \ y2) - sum(x2, y1-1) + sum(x1-1, y1-1);\n    }\n\n    // (x, y) \u306B \u8981\
    \u7D20 k \u3092\u8FFD\u52A0\n    void add(int x, int y, T k) {\n        for(int\
    \ i=x; i<n; i |= i+1)\n            for(int j=y; j<m; j |= j+1)\n             \
    \   array[i][j] += k;\n    }\n};\n"
  code: "// 0-indexed 2\u6B21\u5143BIT\n// Verified: JOI 10 \u672C\u9078 Planetary\
    \ Exploration\ntemplate <typename T>\nstruct zeroIndexedTwodimBIT{\nprivate:\n\
    \    vector< vector<T> > array;\n    const int n;\n    const int m;\n\npublic:\n\
    \    // \u521D\u671F\u5316\n    zeroIndexedTwodimBIT(int _n, int _m) : array(_n+1,\
    \ vector<T>(_m+1, 0)), n(_n), m(_m) {}\n\n    // (0, 0) \u304B\u3089 (x, y) \u307E\
    \u3067\u306E\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\n    T sum(int x, int y)\
    \ {\n        T s = 0;\n        for(int i=x; i>=0; i = (i&(i+1))-1)\n         \
    \   for(int j=y; j>=0; j = (j&(j+1))-1)\n                s += array[i][j];\n \
    \       return s;\n    }\n\n    // [(x1, y1), (x2, y2)]\u306E\u8981\u7D20\u306E\
    \u7DCF\u548C\n    T sum(int x1, int y1, int x2, int y2) {\n        return sum(x2,\
    \ y2) - sum(x1-1, y2) - sum(x2, y1-1) + sum(x1-1, y1-1);\n    }\n\n    // (x,\
    \ y) \u306B \u8981\u7D20 k \u3092\u8FFD\u52A0\n    void add(int x, int y, T k)\
    \ {\n        for(int i=x; i<n; i |= i+1)\n            for(int j=y; j<m; j |= j+1)\n\
    \                array[i][j] += k;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_006_twodimbit_zero_indexed.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_006_twodimbit_zero_indexed.cpp
layout: document
redirect_from:
- /library/structure/strc_006_twodimbit_zero_indexed.cpp
- /library/structure/strc_006_twodimbit_zero_indexed.cpp.html
title: structure/strc_006_twodimbit_zero_indexed.cpp
---
