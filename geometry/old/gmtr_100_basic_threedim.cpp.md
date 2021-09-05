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
  bundledCode: "#line 1 \"geometry/old/gmtr_100_basic_threedim.cpp\"\n// 3 \u6B21\u5143\
    \u306E\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC (\u6700\u4F4E\u9650\u306E\u3082\u306E\
    \u306E\u307F)\n// AOJ 2641 \u3067\u3061\u3087\u3063\u3068\u5FC5\u8981\u306B\u306A\
    \u3063\u305F\u306E\u3067\u4F5C\u308A\u307E\u3057\u305F\n\nstruct Point3D {\n \
    \   double x, y, z;\n};\n\nPoint3D operator+(Point3D a, Point3D b) {\n    return\
    \ Point3D{a.x+b.x, a.y+b.y, a.z+b.z};\n}\n\nPoint3D operator-(Point3D a, Point3D\
    \ b) {\n    return Point3D{a.x-b.x, a.y-b.y, a.z-b.z};\n}\n\nPoint3D operator*(double\
    \ a, Point3D b) {\n    return Point3D{a*b.x, a*b.y, a*b.z};\n}\n\ndouble abs(Point3D\
    \ a) {\n    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);\n}\n\ndouble cross(Point3D\
    \ a, Point3D b) {\n    double ra = a.y * b.z - a.z * b.y;\n    double rb = a.z\
    \ * b.x - a.x * b.z;\n    double rc = a.x * b.y - a.y * b.x;\n    return sqrt(ra*ra\
    \ + rb*rb + rc*rc);\n}\n\ndouble dot(Point3D a, Point3D b) {\n    return a.x*b.x\
    \ + a.y*b.y + a.z*b.z;\n}\n"
  code: "// 3 \u6B21\u5143\u306E\u5E7E\u4F55\u30C6\u30F3\u30D7\u30EC (\u6700\u4F4E\
    \u9650\u306E\u3082\u306E\u306E\u307F)\n// AOJ 2641 \u3067\u3061\u3087\u3063\u3068\
    \u5FC5\u8981\u306B\u306A\u3063\u305F\u306E\u3067\u4F5C\u308A\u307E\u3057\u305F\
    \n\nstruct Point3D {\n    double x, y, z;\n};\n\nPoint3D operator+(Point3D a,\
    \ Point3D b) {\n    return Point3D{a.x+b.x, a.y+b.y, a.z+b.z};\n}\n\nPoint3D operator-(Point3D\
    \ a, Point3D b) {\n    return Point3D{a.x-b.x, a.y-b.y, a.z-b.z};\n}\n\nPoint3D\
    \ operator*(double a, Point3D b) {\n    return Point3D{a*b.x, a*b.y, a*b.z};\n\
    }\n\ndouble abs(Point3D a) {\n    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);\n\
    }\n\ndouble cross(Point3D a, Point3D b) {\n    double ra = a.y * b.z - a.z * b.y;\n\
    \    double rb = a.z * b.x - a.x * b.z;\n    double rc = a.x * b.y - a.y * b.x;\n\
    \    return sqrt(ra*ra + rb*rb + rc*rc);\n}\n\ndouble dot(Point3D a, Point3D b)\
    \ {\n    return a.x*b.x + a.y*b.y + a.z*b.z;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_100_basic_threedim.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_100_basic_threedim.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_100_basic_threedim.cpp
- /library/geometry/old/gmtr_100_basic_threedim.cpp.html
title: geometry/old/gmtr_100_basic_threedim.cpp
---
