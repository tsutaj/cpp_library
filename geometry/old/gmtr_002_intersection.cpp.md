---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_002_intersection.cpp\"\n/***** \u5404\u7A2E\
    \u4EA4\u5DEE\u5224\u5B9A (intersection) *****/\r\n// \u8C46\u77E5\u8B58: \u7DDA\
    \u5206 ... line segment (\u82F1)\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068\u70B9 b\
    \ \u306E\u4EA4\u5DEE\u5224\u5B9A (\u76F4\u7DDA\u4E0A\u306B\u70B9\u304C\u3042\u308B\
    \u304B\u306E\u5224\u5B9A)\r\n// ccw\u3067\u7D76\u5BFE\u5024\u304C1 (\u4E00\u76F4\
    \u7DDA\u3067\u7DDA\u5206\u4E0A\u306B\u306A\u3044) \u3067\u306A\u3051\u308C\u3070\
    \u4EA4\u5DEE\u3057\u3066\u3044\u308B\r\nbool isec_lp(Point a1, Point a2, Point\
    \ b) {\r\n    return abs( ccw(a1, a2, b) ) != 1;\r\n}\r\n\r\n// \u76F4\u7DDA a1,\
    \ a2 \u3068\u76F4\u7DDA b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\r\nbool isec_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\r\n    return !isec_lp(a2-a1, b2-b1, 0)\
    \ || isec_lp(a1, b1, b2);\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068\u7DDA\u5206\
    \ b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\r\nbool isec_ls(Point a1, Point a2, Point\
    \ b1, Point b2) {\r\n    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;\r\
    \n}\r\n\r\n// \u7DDA\u5206 a1, a2 \u3068\u7DDA\u5206 b1, b2 \u306E\u4EA4\u5DEE\
    \u5224\u5B9A\r\n// Verified: CGL_2_B: Intersection\r\nbool isec_ss(Point a1, Point\
    \ a2, Point b1, Point b2) {\r\n    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0\
    \ ) &&\r\n           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );\r\n}\r\n\r\n// \u7DDA\
    \u5206 a1, a2 \u3068\u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u7DDA\u5206\u4E0A\
    \u306B\u70B9\u304C\u3042\u308B\u304B\u306E\u5224\u5B9A)\r\nbool isec_sp(Point\
    \ a1, Point a2, Point b) {\r\n    return !ccw(a1, a2, b);\r\n}\r\n"
  code: "/***** \u5404\u7A2E\u4EA4\u5DEE\u5224\u5B9A (intersection) *****/\r\n// \u8C46\
    \u77E5\u8B58: \u7DDA\u5206 ... line segment (\u82F1)\r\n\r\n// \u76F4\u7DDA a1,\
    \ a2 \u3068\u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u76F4\u7DDA\u4E0A\u306B\u70B9\
    \u304C\u3042\u308B\u304B\u306E\u5224\u5B9A)\r\n// ccw\u3067\u7D76\u5BFE\u5024\u304C\
    1 (\u4E00\u76F4\u7DDA\u3067\u7DDA\u5206\u4E0A\u306B\u306A\u3044) \u3067\u306A\u3051\
    \u308C\u3070\u4EA4\u5DEE\u3057\u3066\u3044\u308B\r\nbool isec_lp(Point a1, Point\
    \ a2, Point b) {\r\n    return abs( ccw(a1, a2, b) ) != 1;\r\n}\r\n\r\n// \u76F4\
    \u7DDA a1, a2 \u3068\u76F4\u7DDA b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\r\nbool\
    \ isec_ll(Point a1, Point a2, Point b1, Point b2) {\r\n    return !isec_lp(a2-a1,\
    \ b2-b1, 0) || isec_lp(a1, b1, b2);\r\n}\r\n\r\n// \u76F4\u7DDA a1, a2 \u3068\u7DDA\
    \u5206 b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\r\nbool isec_ls(Point a1, Point a2,\
    \ Point b1, Point b2) {\r\n    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1)\
    \ < EPS;\r\n}\r\n\r\n// \u7DDA\u5206 a1, a2 \u3068\u7DDA\u5206 b1, b2 \u306E\u4EA4\
    \u5DEE\u5224\u5B9A\r\n// Verified: CGL_2_B: Intersection\r\nbool isec_ss(Point\
    \ a1, Point a2, Point b1, Point b2) {\r\n    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2)\
    \ <= 0 ) &&\r\n           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );\r\n}\r\n\r\n\
    // \u7DDA\u5206 a1, a2 \u3068\u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u7DDA\u5206\
    \u4E0A\u306B\u70B9\u304C\u3042\u308B\u304B\u306E\u5224\u5B9A)\r\nbool isec_sp(Point\
    \ a1, Point a2, Point b) {\r\n    return !ccw(a1, a2, b);\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_002_intersection.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_002_intersection.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_002_intersection.cpp
- /library/geometry/old/gmtr_002_intersection.cpp.html
title: geometry/old/gmtr_002_intersection.cpp
---
