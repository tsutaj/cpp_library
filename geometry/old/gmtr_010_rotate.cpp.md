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
  bundledCode: "#line 1 \"geometry/old/gmtr_010_rotate.cpp\"\n// \u9802\u70B9\u3092\
    \u56DE\u8EE2\u3055\u305B\u308B\u7CFB\n\n// \u5EA6\u6570\u6CD5 \u2192 \u5F27\u5EA6\
    \u6CD5\ndouble deg2rad(double x) {return x * M_PI / 180.0;}\n\n// \u70B9 a \u3092\
    \u4E2D\u5FC3\u3068\u3057\u3066\u3001\u70B9 b \u3092 z \u5EA6\u56DE\u8EE2\u3055\
    \u305B\u305F\u3068\u304D\u306E\u4F4D\u7F6E\nPoint rotatePoint(Point a, Point b,\
    \ double z) {\n    // \u5EA6\u6570\u6CD5\u306E\u5834\u5408\u306F\u5909\u63DB\n\
    \    z = deg2rad(z);\n\n    b -= a;\n    double rx = b.real() * cos(z) - b.imag()\
    \ * sin(z);\n    double ry = b.real() * sin(z) + b.imag() * cos(z);\n    Point\
    \ ret(rx, ry); ret += a;\n    return ret;\n}\n"
  code: "// \u9802\u70B9\u3092\u56DE\u8EE2\u3055\u305B\u308B\u7CFB\n\n// \u5EA6\u6570\
    \u6CD5 \u2192 \u5F27\u5EA6\u6CD5\ndouble deg2rad(double x) {return x * M_PI /\
    \ 180.0;}\n\n// \u70B9 a \u3092\u4E2D\u5FC3\u3068\u3057\u3066\u3001\u70B9 b \u3092\
    \ z \u5EA6\u56DE\u8EE2\u3055\u305B\u305F\u3068\u304D\u306E\u4F4D\u7F6E\nPoint\
    \ rotatePoint(Point a, Point b, double z) {\n    // \u5EA6\u6570\u6CD5\u306E\u5834\
    \u5408\u306F\u5909\u63DB\n    z = deg2rad(z);\n\n    b -= a;\n    double rx =\
    \ b.real() * cos(z) - b.imag() * sin(z);\n    double ry = b.real() * sin(z) +\
    \ b.imag() * cos(z);\n    Point ret(rx, ry); ret += a;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_010_rotate.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_010_rotate.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_010_rotate.cpp
- /library/geometry/old/gmtr_010_rotate.cpp.html
title: geometry/old/gmtr_010_rotate.cpp
---
