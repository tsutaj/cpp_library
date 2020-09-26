---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_005_circle_crossp.cpp\"\n// \u76F4\u7DDA\
    \ a1, a2 \u3068\u5186 C \u3068\u306E\u4EA4\u70B9\r\n// Verified: AOJ CGL_7_D:\
    \ Cross Points of a Circle and a Line\r\nvector<Point> crossp_lc(Point a1, Point\
    \ a2, Circle c) {\r\n    vector<Point> ps;\r\n    double r = c.second;\r\n   \
    \ Point ft = projection(a1, a2, c.first);\r\n    if(!GEQ(r*r, norm(ft-c.first)))\
    \ return ps;\r\n\r\n    Point dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1)\
    \ * (a2-a1);\r\n    ps.push_back(ft + dir);\r\n    if(!EQ(r*r, norm(ft-c.first)))\
    \ ps.push_back(ft - dir);\r\n    return ps;\r\n}\r\n\r\n// \u5186 x \u3068\u5186\
    \ y \u306E\u4EA4\u70B9\r\n// Verified: AOJ CGL_7_E: Cross Points of Circles\r\n\
    vector<Point> crossp_cc(Circle x, Circle y) {\r\n    vector<Point> ps;\r\n   \
    \ Point a = x.first, b = y.first;\r\n    double ar = x.second, br = y.second;\r\
    \n\r\n    Point ab = b-a;\r\n    double d = abs(ab);\r\n    double crL = (norm(ab)\
    \ + ar * ar - br * br) / (2 * d);\r\n    if(EQ(d,0) || ar < abs(crL)) return ps;\r\
    \n\r\n    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);\r\n    Point cp\
    \ = a + crL/d * ab;\r\n    ps.push_back(cp + abN);\r\n    if(!EQ(norm(abN), 0))\
    \ ps.push_back(cp - abN);\r\n    return ps;\r\n}\r\n"
  code: "// \u76F4\u7DDA a1, a2 \u3068\u5186 C \u3068\u306E\u4EA4\u70B9\r\n// Verified:\
    \ AOJ CGL_7_D: Cross Points of a Circle and a Line\r\nvector<Point> crossp_lc(Point\
    \ a1, Point a2, Circle c) {\r\n    vector<Point> ps;\r\n    double r = c.second;\r\
    \n    Point ft = projection(a1, a2, c.first);\r\n    if(!GEQ(r*r, norm(ft-c.first)))\
    \ return ps;\r\n\r\n    Point dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1)\
    \ * (a2-a1);\r\n    ps.push_back(ft + dir);\r\n    if(!EQ(r*r, norm(ft-c.first)))\
    \ ps.push_back(ft - dir);\r\n    return ps;\r\n}\r\n\r\n// \u5186 x \u3068\u5186\
    \ y \u306E\u4EA4\u70B9\r\n// Verified: AOJ CGL_7_E: Cross Points of Circles\r\n\
    vector<Point> crossp_cc(Circle x, Circle y) {\r\n    vector<Point> ps;\r\n   \
    \ Point a = x.first, b = y.first;\r\n    double ar = x.second, br = y.second;\r\
    \n\r\n    Point ab = b-a;\r\n    double d = abs(ab);\r\n    double crL = (norm(ab)\
    \ + ar * ar - br * br) / (2 * d);\r\n    if(EQ(d,0) || ar < abs(crL)) return ps;\r\
    \n\r\n    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);\r\n    Point cp\
    \ = a + crL/d * ab;\r\n    ps.push_back(cp + abN);\r\n    if(!EQ(norm(abN), 0))\
    \ ps.push_back(cp - abN);\r\n    return ps;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_005_circle_crossp.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_005_circle_crossp.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_005_circle_crossp.cpp
- /library/geometry/old/gmtr_005_circle_crossp.cpp.html
title: geometry/old/gmtr_005_circle_crossp.cpp
---
