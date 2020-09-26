---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_006_circle_tangent.cpp\"\n// \u70B9 p\
    \ \u304B\u3089\u5186 x \u3078\u306E\u63A5\u7DDA\u306E\u63A5\u70B9\r\n// Verified:\
    \ AOJ CGL_7_F: Tangent to a Circle\r\nvector<Point> tangentPoints(Point p, Circle\
    \ x) {\r\n    vector<Point> ps;\r\n    Point a = x.first; double ar = x.second;\r\
    \n    double sin = ar / abs(p-a);\r\n    if(!LE(sin, 1)) return ps; // \u3053\u3053\
    \u3067 NaN \u3082\u306F\u3058\u304B\u308C\u308B\r\n\r\n    double t = M_PI_2 -\
    \ asin(min(sin, 1.0));\r\n    ps.push_back(a + (p-a) * polar(sin, t));\r\n   \
    \ if(!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));\r\n    return ps;\r\n\
    }\r\n\r\n// \u5186 x \u3068\u5186 y \u306E\u5171\u901A\u63A5\u7DDA\u3002\u8FD4\
    \u3055\u308C\u308B\u5404\u76F4\u7DDA\u306B\u542B\u307E\u308C\u308B\u9802\u70B9\
    \u306F\u5186\u3068\u306E\u63A5\u70B9\u3068\u306A\u308B\r\n// Verified: AOJ CGL_7_G:\
    \ Common Tangent\r\n// \u203B \u3084\u308B\u3053\u3068: -0.0000000\u306B\u306A\
    \u308B\u554F\u984C\u3092\u76F4\u3057\u305F\u3044\u30FB\u30FB\u30FB\r\nvector<L>\
    \ tangentLines(Circle x, Circle y) {\r\n    Point a = x.first, b = y.first;\r\n\
    \    double ar = x.second, br = y.second;\r\n    vector<L> ls;\r\n    double d\
    \ = abs(b-a);\r\n\r\n    for(int i=0; i<2; i++) {\r\n        double sin = (ar\
    \ - (1-i*2)*br) / d;\r\n        if(!LE(sin*sin, 1)) break;\r\n\r\n        double\
    \ cos = sqrt(max(1 - sin*sin, 0.0));\r\n        for(int j=0; j<2; j++) {\r\n \
    \           Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;\r\n            ls.push_back(L(a\
    \ + ar*n, b + (1-i+2)*br*n));\r\n            if(cos < EPS) break; // \u91CD\u8907\
    \u3059\u308B\u63A5\u7DDA\u3092\u7121\u8996 (\u91CD\u8907\u3057\u3066\u3088\u3044\
    \u306A\u3089\u3053\u306E\u884C\u306F\u4E0D\u8981)\r\n        }\r\n    }\r\n  \
    \  return ls;\r\n}\r\n"
  code: "// \u70B9 p \u304B\u3089\u5186 x \u3078\u306E\u63A5\u7DDA\u306E\u63A5\u70B9\
    \r\n// Verified: AOJ CGL_7_F: Tangent to a Circle\r\nvector<Point> tangentPoints(Point\
    \ p, Circle x) {\r\n    vector<Point> ps;\r\n    Point a = x.first; double ar\
    \ = x.second;\r\n    double sin = ar / abs(p-a);\r\n    if(!LE(sin, 1)) return\
    \ ps; // \u3053\u3053\u3067 NaN \u3082\u306F\u3058\u304B\u308C\u308B\r\n\r\n \
    \   double t = M_PI_2 - asin(min(sin, 1.0));\r\n    ps.push_back(a + (p-a) * polar(sin,\
    \ t));\r\n    if(!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));\r\n    return\
    \ ps;\r\n}\r\n\r\n// \u5186 x \u3068\u5186 y \u306E\u5171\u901A\u63A5\u7DDA\u3002\
    \u8FD4\u3055\u308C\u308B\u5404\u76F4\u7DDA\u306B\u542B\u307E\u308C\u308B\u9802\
    \u70B9\u306F\u5186\u3068\u306E\u63A5\u70B9\u3068\u306A\u308B\r\n// Verified: AOJ\
    \ CGL_7_G: Common Tangent\r\n// \u203B \u3084\u308B\u3053\u3068: -0.0000000\u306B\
    \u306A\u308B\u554F\u984C\u3092\u76F4\u3057\u305F\u3044\u30FB\u30FB\u30FB\r\nvector<L>\
    \ tangentLines(Circle x, Circle y) {\r\n    Point a = x.first, b = y.first;\r\n\
    \    double ar = x.second, br = y.second;\r\n    vector<L> ls;\r\n    double d\
    \ = abs(b-a);\r\n\r\n    for(int i=0; i<2; i++) {\r\n        double sin = (ar\
    \ - (1-i*2)*br) / d;\r\n        if(!LE(sin*sin, 1)) break;\r\n\r\n        double\
    \ cos = sqrt(max(1 - sin*sin, 0.0));\r\n        for(int j=0; j<2; j++) {\r\n \
    \           Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;\r\n            ls.push_back(L(a\
    \ + ar*n, b + (1-i+2)*br*n));\r\n            if(cos < EPS) break; // \u91CD\u8907\
    \u3059\u308B\u63A5\u7DDA\u3092\u7121\u8996 (\u91CD\u8907\u3057\u3066\u3088\u3044\
    \u306A\u3089\u3053\u306E\u884C\u306F\u4E0D\u8981)\r\n        }\r\n    }\r\n  \
    \  return ls;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_006_circle_tangent.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_006_circle_tangent.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_006_circle_tangent.cpp
- /library/geometry/old/gmtr_006_circle_tangent.cpp.html
title: geometry/old/gmtr_006_circle_tangent.cpp
---
