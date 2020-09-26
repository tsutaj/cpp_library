---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_004_circle_dist.cpp\"\n/***** \u5186\u306B\
    \u95A2\u3059\u308B\u554F\u984C *****/\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068 \u5186\
    \ C \u3068\u306E\u8DDD\u96E2\r\ndouble dist_lc(Point a1, Point a2, Circle c) {\r\
    \n    return max(dist_lp(a1, a2, c.first) - c.second, 0.0);\r\n}\r\n\r\n// \u7DDA\
    \u5206 a1, a2 \u3068 \u5186 C \u3068\u306E\u8DDD\u96E2\r\ndouble dist_sc(Point\
    \ a1, Point a2, Circle c) {\r\n    double dSqr1 = norm(c.first - a1), dSqr2 =\
    \ norm(c.first - a2);\r\n    double r = c.second;\r\n    if(dSqr1 < r*r ^ dSqr2\
    \ < r*r) return 0; //\u5186\u304C\u7DDA\u5206\u3092\u5305\u542B\u3059\u308B\u3068\
    \u304D\u8DDD\u96E20\u306A\u3089\u3070\u3053\u3053\u3092OR\u306B\u5909\u3048\u308B\
    \r\n    if(dSqr1 < r*r & dSqr2 < r*r) return r - sqrt(max(dSqr1, dSqr2));\r\n\
    \    return max(dist_sp(a1, a2, c.first) - r, 0.0);\r\n}\r\n\r\n// \u5186 x \u3068\
    \u5186 y \u3068\u306E\u8DDD\u96E2\r\ndouble dist_cc(Circle x, Circle y) {\r\n\
    \    Point a = x.first, b = y.first;\r\n    double ar = x.second, br = y.second;\r\
    \n\r\n    double d = abs(a-b);\r\n    return GE(d, abs(ar-br)) ? max(d-ar-br,\
    \ 0.0) : abs(ar-br) - d;\r\n}\r\n\r\n"
  code: "/***** \u5186\u306B\u95A2\u3059\u308B\u554F\u984C *****/\r\n\r\n// \u76F4\
    \u7DDA a1, a2 \u3068 \u5186 C \u3068\u306E\u8DDD\u96E2\r\ndouble dist_lc(Point\
    \ a1, Point a2, Circle c) {\r\n    return max(dist_lp(a1, a2, c.first) - c.second,\
    \ 0.0);\r\n}\r\n\r\n// \u7DDA\u5206 a1, a2 \u3068 \u5186 C \u3068\u306E\u8DDD\u96E2\
    \r\ndouble dist_sc(Point a1, Point a2, Circle c) {\r\n    double dSqr1 = norm(c.first\
    \ - a1), dSqr2 = norm(c.first - a2);\r\n    double r = c.second;\r\n    if(dSqr1\
    \ < r*r ^ dSqr2 < r*r) return 0; //\u5186\u304C\u7DDA\u5206\u3092\u5305\u542B\u3059\
    \u308B\u3068\u304D\u8DDD\u96E20\u306A\u3089\u3070\u3053\u3053\u3092OR\u306B\u5909\
    \u3048\u308B\r\n    if(dSqr1 < r*r & dSqr2 < r*r) return r - sqrt(max(dSqr1, dSqr2));\r\
    \n    return max(dist_sp(a1, a2, c.first) - r, 0.0);\r\n}\r\n\r\n// \u5186 x \u3068\
    \u5186 y \u3068\u306E\u8DDD\u96E2\r\ndouble dist_cc(Circle x, Circle y) {\r\n\
    \    Point a = x.first, b = y.first;\r\n    double ar = x.second, br = y.second;\r\
    \n\r\n    double d = abs(a-b);\r\n    return GE(d, abs(ar-br)) ? max(d-ar-br,\
    \ 0.0) : abs(ar-br) - d;\r\n}\r\n\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_004_circle_dist.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_004_circle_dist.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_004_circle_dist.cpp
- /library/geometry/old/gmtr_004_circle_dist.cpp.html
title: geometry/old/gmtr_004_circle_dist.cpp
---
