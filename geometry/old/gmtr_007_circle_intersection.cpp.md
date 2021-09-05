---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_007_circle_intersection.cpp\"\n// \u5186\
    \ c1 \u3068\u5186 c2 \u306E\u4F4D\u7F6E\u95A2\u4FC2\r\n// Verified: AOJ CGL_7_A:\
    \ Intersection\r\nint intersectCC(Circle c1, Circle c2){\r\n    Point c1p = c1.first,\
    \ c2p = c2.first;\r\n    double c1r = c1.second, c2r = c2.second;\r\n    long\
    \ double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;\r\n    if(r1 + r2 < d)      \
    \      return  0; // \u96E2\u308C\u3066\u3044\u308B\r\n    if(abs(r1 + r2 - d)\
    \ < EPS) return -2; // \u5916\u63A5\r\n    if(abs(d + r1 - r2) < EPS) return +1;\
    \ // c1 \u304C c2 \u306E\u4E2D\u3067\u5185\u63A5\r\n    if(abs(d + r2 - r1) <\
    \ EPS) return -1; // c2 \u304C c1 \u306E\u4E2D\u3067\u5185\u63A5\r\n    if(d +\
    \ r1 < r2)            return +3; // c1 \u304C c2 \u306E\u4E2D\r\n    if(d + r2\
    \ < r1)            return -3; // c2 \u304C c1 \u306E\u4E2D\r\n    return 2; //\
    \ 2\u3064\u306E\u4EA4\u70B9\u3092\u6301\u3064\r\n}\r\n"
  code: "// \u5186 c1 \u3068\u5186 c2 \u306E\u4F4D\u7F6E\u95A2\u4FC2\r\n// Verified:\
    \ AOJ CGL_7_A: Intersection\r\nint intersectCC(Circle c1, Circle c2){\r\n    Point\
    \ c1p = c1.first, c2p = c2.first;\r\n    double c1r = c1.second, c2r = c2.second;\r\
    \n    long double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;\r\n    if(r1 + r2 <\
    \ d)            return  0; // \u96E2\u308C\u3066\u3044\u308B\r\n    if(abs(r1\
    \ + r2 - d) < EPS) return -2; // \u5916\u63A5\r\n    if(abs(d + r1 - r2) < EPS)\
    \ return +1; // c1 \u304C c2 \u306E\u4E2D\u3067\u5185\u63A5\r\n    if(abs(d +\
    \ r2 - r1) < EPS) return -1; // c2 \u304C c1 \u306E\u4E2D\u3067\u5185\u63A5\r\n\
    \    if(d + r1 < r2)            return +3; // c1 \u304C c2 \u306E\u4E2D\r\n  \
    \  if(d + r2 < r1)            return -3; // c2 \u304C c1 \u306E\u4E2D\r\n    return\
    \ 2; // 2\u3064\u306E\u4EA4\u70B9\u3092\u6301\u3064\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_007_circle_intersection.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_007_circle_intersection.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_007_circle_intersection.cpp
- /library/geometry/old/gmtr_007_circle_intersection.cpp.html
title: geometry/old/gmtr_007_circle_intersection.cpp
---
