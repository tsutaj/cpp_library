---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_003_distance.cpp\"\n/***** \u5404\u7A2E\
    \u8DDD\u96E2 *****/\r\n\r\n// \u70B9 p \u306E\u76F4\u7DDA a1, a2 \u3078\u306E\u5C04\
    \u5F71\u70B9\u3092\u8FD4\u3059\r\n// Verified: AOJ CGL_1_A: Projection\r\nPoint\
    \ projection(Point a1, Point a2, Point p) {\r\n    return a1 + dot(a2-a1, p-a1)\
    \ / norm(a2-a1) * (a2-a1);\r\n}\r\n\r\n// \u70B9 p \u306E\u76F4\u7DDA a \u3078\
    \u306E\u53CD\u5C04\u70B9\u3092\u8FD4\u3059\r\n// Verified: AOJ CGL_1_B: Reflection\r\
    \nPoint reflection(Point a1, Point a2, Point p) {\r\n    return 2.0 * projection(a1,\
    \ a2, p) - p;\r\n}\r\n\r\n// \u70B9 a1, a2 \u3092\u901A\u308B\u76F4\u7DDA\u3068\
    \u70B9 b \u3068\u306E\u8DDD\u96E2\r\ndouble dist_lp(Point a1, Point a2, Point\
    \ b) {\r\n    return abs( cross(a2-a1, b-a1) ) / abs(a2-a1);\r\n}\r\n\r\n// \u76F4\
    \u7DDA a1, a2 \u3068 \u76F4\u7DDA b1, b2 \u3068\u306E\u8DDD\u96E2\r\ndouble dist_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\r\n    return isec_ll(a1, a2, b1, b2) ?\
    \ 0 : dist_lp(a1, a2, b1);\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068 \u7DDA\u5206\
    \ b1, b2 \u3068\u306E\u8DDD\u96E2\r\ndouble dist_ls(Point a1, Point a2, Point\
    \ b1, Point b2) {\r\n    return isec_ls(a1, a2, b1, b2) ? 0 : min( dist_lp(a1,\
    \ a2, b1), dist_lp(a1, a2, b2) );\r\n}\r\n\r\n// \u70B9 a1, a2 \u3092\u7AEF\u70B9\
    \u3068\u3059\u308B\u7DDA\u5206\u3068\u70B9 b \u3068\u306E\u8DDD\u96E2\r\ndouble\
    \ dist_sp(Point a1, Point a2, Point b) {\r\n    if( dot(a2-a1, b-a1) < EPS ) return\
    \ abs(b - a1);\r\n    if( dot(a1-a2, b-a2) < EPS ) return abs(b - a2);\r\n   \
    \ return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);\r\n}\r\n\r\n// \u7DDA\u5206\
    \ a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\u8DDD\u96E2\r\n// Verified: CGL_2_D:\
    \ Distance\r\n// isec_ss\u304C\u5FC5\u8981\u306A\u306E\u3067\u518D\u63B2\r\nbool\
    \ isec_ss(Point a1, Point a2, Point b1, Point b2) {\r\n    return ( ccw(a1,a2,b1)\
    \ * ccw(a1,a2,b2) <= 0 ) &&\r\n           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0\
    \ );\r\n}\r\n\r\ndouble dist_ss(Point a1, Point a2, Point b1, Point b2) {\r\n\
    \    if(isec_ss(a1, a2, b1, b2)) return 0;\r\n    return min( min(dist_sp(a1,\
    \ a2, b1), dist_sp(a1, a2, b2)),\r\n                min(dist_sp(b1, b2, a1), dist_sp(b1,\
    \ b2, a2)) );\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068\u76F4\u7DDAb1, b2\u306E\
    \u4EA4\u70B9\u3092\u6C42\u3081\u308B\r\n// Verified: AOJ CGL_2_C.cpp\r\nPoint\
    \ crossp_ll(Point a1, Point a2, Point b1, Point b2) {\r\n    double d1 = cross(b2-b1,\
    \ b1-a1);\r\n    double d2 = cross(b2-b1, a2-a1);\r\n    if( EQ(d1,0) && EQ(d2,0)\
    \ ) return a1; // same line\r\n    if( EQ(d2,0) ) assert(false); // precondition\
    \ not satisfied\r\n    return a1 + d1 / d2 * (a2 - a1);\r\n}\r\n"
  code: "/***** \u5404\u7A2E\u8DDD\u96E2 *****/\r\n\r\n// \u70B9 p \u306E\u76F4\u7DDA\
    \ a1, a2 \u3078\u306E\u5C04\u5F71\u70B9\u3092\u8FD4\u3059\r\n// Verified: AOJ\
    \ CGL_1_A: Projection\r\nPoint projection(Point a1, Point a2, Point p) {\r\n \
    \   return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);\r\n}\r\n\r\n// \u70B9\
    \ p \u306E\u76F4\u7DDA a \u3078\u306E\u53CD\u5C04\u70B9\u3092\u8FD4\u3059\r\n\
    // Verified: AOJ CGL_1_B: Reflection\r\nPoint reflection(Point a1, Point a2, Point\
    \ p) {\r\n    return 2.0 * projection(a1, a2, p) - p;\r\n}\r\n\r\n// \u70B9 a1,\
    \ a2 \u3092\u901A\u308B\u76F4\u7DDA\u3068\u70B9 b \u3068\u306E\u8DDD\u96E2\r\n\
    double dist_lp(Point a1, Point a2, Point b) {\r\n    return abs( cross(a2-a1,\
    \ b-a1) ) / abs(a2-a1);\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068 \u76F4\u7DDA\
    \ b1, b2 \u3068\u306E\u8DDD\u96E2\r\ndouble dist_ll(Point a1, Point a2, Point\
    \ b1, Point b2) {\r\n    return isec_ll(a1, a2, b1, b2) ? 0 : dist_lp(a1, a2,\
    \ b1);\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\
    \u8DDD\u96E2\r\ndouble dist_ls(Point a1, Point a2, Point b1, Point b2) {\r\n \
    \   return isec_ls(a1, a2, b1, b2) ? 0 : min( dist_lp(a1, a2, b1), dist_lp(a1,\
    \ a2, b2) );\r\n}\r\n\r\n// \u70B9 a1, a2 \u3092\u7AEF\u70B9\u3068\u3059\u308B\
    \u7DDA\u5206\u3068\u70B9 b \u3068\u306E\u8DDD\u96E2\r\ndouble dist_sp(Point a1,\
    \ Point a2, Point b) {\r\n    if( dot(a2-a1, b-a1) < EPS ) return abs(b - a1);\r\
    \n    if( dot(a1-a2, b-a2) < EPS ) return abs(b - a2);\r\n    return abs( cross(a2-a1,\
    \ b-a1) ) / abs(a2 - a1);\r\n}\r\n\r\n// \u7DDA\u5206 a1, a2 \u3068 \u7DDA\u5206\
    \ b1, b2 \u3068\u306E\u8DDD\u96E2\r\n// Verified: CGL_2_D: Distance\r\n// isec_ss\u304C\
    \u5FC5\u8981\u306A\u306E\u3067\u518D\u63B2\r\nbool isec_ss(Point a1, Point a2,\
    \ Point b1, Point b2) {\r\n    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&\r\
    \n           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );\r\n}\r\n\r\ndouble dist_ss(Point\
    \ a1, Point a2, Point b1, Point b2) {\r\n    if(isec_ss(a1, a2, b1, b2)) return\
    \ 0;\r\n    return min( min(dist_sp(a1, a2, b1), dist_sp(a1, a2, b2)),\r\n   \
    \             min(dist_sp(b1, b2, a1), dist_sp(b1, b2, a2)) );\r\n}\r\n\r\n//\
    \ \u76F4\u7DDA a1, a2 \u3068\u76F4\u7DDAb1, b2\u306E\u4EA4\u70B9\u3092\u6C42\u3081\
    \u308B\r\n// Verified: AOJ CGL_2_C.cpp\r\nPoint crossp_ll(Point a1, Point a2,\
    \ Point b1, Point b2) {\r\n    double d1 = cross(b2-b1, b1-a1);\r\n    double\
    \ d2 = cross(b2-b1, a2-a1);\r\n    if( EQ(d1,0) && EQ(d2,0) ) return a1; // same\
    \ line\r\n    if( EQ(d2,0) ) assert(false); // precondition not satisfied\r\n\
    \    return a1 + d1 / d2 * (a2 - a1);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_003_distance.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_003_distance.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_003_distance.cpp
- /library/geometry/old/gmtr_003_distance.cpp.html
title: geometry/old/gmtr_003_distance.cpp
---
