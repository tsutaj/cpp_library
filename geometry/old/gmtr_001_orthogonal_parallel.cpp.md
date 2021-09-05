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
  bundledCode: "#line 1 \"geometry/old/gmtr_001_orthogonal_parallel.cpp\"\n/*****\
    \ \u76F4\u4EA4\u30FB\u5E73\u884C\u5224\u5B9A *****/\r\n// Verified: AOJ CGL_2_A:\
    \ Parallel/Orthogonal\r\n\r\n// 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A (\u5185\
    \u7A4D\u304C0\u3067\u3042\u308B\u3053\u3068)\r\nbool is_orthogonal(Point a1, Point\
    \ a2, Point b1, Point b2) {\r\n    return EQ( dot(a1-a2, b1-b2), 0.0 );\r\n}\r\
    \n\r\n// 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A (\u5916\u7A4D\u304C0\u3067\
    \u3042\u308B\u3053\u3068)\r\nbool is_parallel(Point a1, Point a2, Point b1, Point\
    \ b2) {\r\n    return EQ( cross(a1-a2, b1-b2), 0.0 );\r\n}\r\n"
  code: "/***** \u76F4\u4EA4\u30FB\u5E73\u884C\u5224\u5B9A *****/\r\n// Verified:\
    \ AOJ CGL_2_A: Parallel/Orthogonal\r\n\r\n// 2\u76F4\u7DDA\u306E\u76F4\u4EA4\u5224\
    \u5B9A (\u5185\u7A4D\u304C0\u3067\u3042\u308B\u3053\u3068)\r\nbool is_orthogonal(Point\
    \ a1, Point a2, Point b1, Point b2) {\r\n    return EQ( dot(a1-a2, b1-b2), 0.0\
    \ );\r\n}\r\n\r\n// 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A (\u5916\u7A4D\u304C\
    0\u3067\u3042\u308B\u3053\u3068)\r\nbool is_parallel(Point a1, Point a2, Point\
    \ b1, Point b2) {\r\n    return EQ( cross(a1-a2, b1-b2), 0.0 );\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_001_orthogonal_parallel.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_001_orthogonal_parallel.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_001_orthogonal_parallel.cpp
- /library/geometry/old/gmtr_001_orthogonal_parallel.cpp.html
title: geometry/old/gmtr_001_orthogonal_parallel.cpp
---
