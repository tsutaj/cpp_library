---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_000_basic.cpp\"\n/***** \u57FA\u672C\u7684\
    \u6E96\u5099 *****/\r\n\r\n// xy\u5E73\u9762\u4E0A\u306E\u70B9(\u30D9\u30AF\u30C8\
    \u30EB)\u3092\u8868\u73FE\u3059\u308B\u306B\u306F\u3001complex\u578B\u3092\u5229\
    \u7528\u3059\u308B\u3068\u3088\u3044\r\ntypedef complex<double> Point;\r\n\r\n\
    // \u8FBA\u306E\u8868\u73FE (\u5EA7\u6A19\u30922\u3064 pair \u3067\u3082\u3064\
    )\r\ntypedef pair<Point, Point> Line;\r\n\r\n// \u5186\u306E\u8868\u73FE (\u5EA7\
    \u6A19 P \u3068 \u534A\u5F84 d \u3067\u8868\u73FE\u3059\u308B)\r\ntypedef pair<Point,\
    \ double> Circle;\r\n\r\n// \u8AA4\u5DEE(epsilon)\u306E\u5B9A\u7FA9\r\nconst double\
    \ EPS = 1e-10;\r\n\r\n// 2\u3064\u306E\u8981\u7D20\u304C\u7B49\u3057\u3044\u304B\
    \u3069\u3046\u304B\r\ntemplate <typename float_type>\r\nbool EQ(float_type a,\
    \ float_type b) { return abs(a - b) < EPS; }\r\n\r\n// 2\u3064\u306E\u30D9\u30AF\
    \u30C8\u30EB\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\r\ntemplate <typename\
    \ complex_type>\r\nbool EQV(complex_type a, complex_type b) { return EQ(a.real(),\
    \ b.real()) && EQ(a.imag(), b.imag()); }\r\n\r\n// m \u306F n \u3088\u308A\u5927\
    \u304D\u3044(\u4EE5\u4E0A)\u304B\u3069\u3046\u304B\r\ntemplate <typename float_type>\r\
    \nbool LE(float_type n, float_type m) { return n < m + EPS; }\r\ntemplate <typename\
    \ float_type>\r\nbool LEQ(float_type n, float_type m) { return n <= m + EPS; }\r\
    \n\r\n// m \u306F n \u3088\u308A\u5C0F\u3055\u3044(\u4EE5\u4E0B)\u304B\u3069\u3046\
    \u304B\r\ntemplate <typename float_type>\r\nbool GE(float_type n, float_type m)\
    \ { return n + EPS > m; }\r\nbool GEQ(float_type n, float_type m) { return n +\
    \ EPS >= m; }\r\n\r\n// 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u306E\u5185\u7A4D\
    \u3092\u6C42\u3081\u308B\r\ndouble dot(Point a, Point b) {\r\n    return (a.real()\
    \ * b.real() + a.imag() * b.imag());\r\n}\r\n\r\n// 2\u3064\u306E\u30D9\u30AF\u30C8\
    \u30EB\u306E\u5916\u7A4D\u3092\u6C42\u3081\u308B\r\ndouble cross(Point a, Point\
    \ b) {\r\n    return (a.real() * b.imag() - a.imag() * b.real());\r\n}\r\n\r\n\
    // ccw (c \u304C\u76F4\u7DDA(\u7DDA\u5206) ab \u306B\u5BFE\u3057\u3066\u3069\u306E\
    \u3088\u3046\u306A\u4F4D\u7F6E\u95A2\u4FC2\u304B\uFF1F)\r\n// Verified: AOJ CGL_1_C:\
    \ Counter-Clockwise\r\n// +1 ... a \u2192 b \u3067\u534A\u6642\u8A08\u65B9\u5411\
    \u306B\u6298\u308C\u3066 b \u2192 c (COUNTER_CLOCKWISE)\r\n// -1 ... a \u2192\
    \ b \u3067\u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066 b \u2192 c (CLOCKWISE)\r\
    \n// +2 ... c, a, b \u304C\u3053\u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\
    \u306B\u3042\u308B\u5834\u5408 (ONLINE_BACK)\r\n// -2 ... a, b, c \u304C\u3053\
    \u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\u306B\u3042\u308B\u5834\u5408\
    \ ( or a == b ) (ONLINE_FRONT)\r\n//  0 ... c \u304C\u7DDA\u5206 ab \u4E0A\u306B\
    \u3042\u308B\u5834\u5408 (\u70B9 a, b \u4E0A\u3092\u542B\u3080) (ON_SEGMENT)\r\
    \nint ccw(Point a, Point b, Point c) {\r\n    b -= a; c -= a;\r\n    if( cross(b,c)\
    \ > EPS ) return +1;\r\n    if( cross(b,c) < -EPS ) return -1;\r\n    if( dot(b,c)\
    \ < 0 ) return +2;\r\n    if( norm(b) < norm(c) ) return -2;\r\n    return 0;\r\
    \n}\r\n\r\n/***** \u30C6\u30AF\u30CB\u30C3\u30AF\u7DE8 *****/\r\n\r\n/*\r\n//\
    \ \u30D9\u30AF\u30C8\u30EB a \u306E\u7D76\u5BFE\u5024\u3092\u6C42\u3081\u308B\
    \ (complex\u578B)\r\ndouble len = abs(a);\r\n\r\n// 2\u70B9 a,b \u9593\u306E\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B (complex\u578B)\r\ndouble dist = abs(a-b);\r\n\r\
    \n// 2\u70B9\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\
    \r\nif(abs(a-b) < EPS)\r\n\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u5358\u4F4D\
    \u30D9\u30AF\u30C8\u30EB b \u3092\u6C42\u3081\u308B\r\nPoint b = a / abs(a);\r\
    \n\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB\
    \ n1, n2 \u3092\u6C42\u3081\u308B\r\nPoint n1 = a * Point(0, 1);\r\nPoint n2 =\
    \ a * Point(0, -1);\r\n\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u5358\u4F4D\u6CD5\
    \u7DDA\u30D9\u30AF\u30C8\u30EB un1, un2 \u3092\u6C42\u3081\u308B\r\nPoint un1\
    \ = (a * Point(0, 1)) / abs(a);\r\nPoint un2 = (a * Point(0, -1)) / abs(a);\r\n\
    */\r\n"
  code: "/***** \u57FA\u672C\u7684\u6E96\u5099 *****/\r\n\r\n// xy\u5E73\u9762\u4E0A\
    \u306E\u70B9(\u30D9\u30AF\u30C8\u30EB)\u3092\u8868\u73FE\u3059\u308B\u306B\u306F\
    \u3001complex\u578B\u3092\u5229\u7528\u3059\u308B\u3068\u3088\u3044\r\ntypedef\
    \ complex<double> Point;\r\n\r\n// \u8FBA\u306E\u8868\u73FE (\u5EA7\u6A19\u3092\
    2\u3064 pair \u3067\u3082\u3064)\r\ntypedef pair<Point, Point> Line;\r\n\r\n//\
    \ \u5186\u306E\u8868\u73FE (\u5EA7\u6A19 P \u3068 \u534A\u5F84 d \u3067\u8868\u73FE\
    \u3059\u308B)\r\ntypedef pair<Point, double> Circle;\r\n\r\n// \u8AA4\u5DEE(epsilon)\u306E\
    \u5B9A\u7FA9\r\nconst double EPS = 1e-10;\r\n\r\n// 2\u3064\u306E\u8981\u7D20\u304C\
    \u7B49\u3057\u3044\u304B\u3069\u3046\u304B\r\ntemplate <typename float_type>\r\
    \nbool EQ(float_type a, float_type b) { return abs(a - b) < EPS; }\r\n\r\n// 2\u3064\
    \u306E\u30D9\u30AF\u30C8\u30EB\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\
    \r\ntemplate <typename complex_type>\r\nbool EQV(complex_type a, complex_type\
    \ b) { return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()); }\r\n\r\n// m\
    \ \u306F n \u3088\u308A\u5927\u304D\u3044(\u4EE5\u4E0A)\u304B\u3069\u3046\u304B\
    \r\ntemplate <typename float_type>\r\nbool LE(float_type n, float_type m) { return\
    \ n < m + EPS; }\r\ntemplate <typename float_type>\r\nbool LEQ(float_type n, float_type\
    \ m) { return n <= m + EPS; }\r\n\r\n// m \u306F n \u3088\u308A\u5C0F\u3055\u3044\
    (\u4EE5\u4E0B)\u304B\u3069\u3046\u304B\r\ntemplate <typename float_type>\r\nbool\
    \ GE(float_type n, float_type m) { return n + EPS > m; }\r\nbool GEQ(float_type\
    \ n, float_type m) { return n + EPS >= m; }\r\n\r\n// 2\u3064\u306E\u30D9\u30AF\
    \u30C8\u30EB\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B\r\ndouble dot(Point a,\
    \ Point b) {\r\n    return (a.real() * b.real() + a.imag() * b.imag());\r\n}\r\
    \n\r\n// 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u306E\u5916\u7A4D\u3092\u6C42\u3081\
    \u308B\r\ndouble cross(Point a, Point b) {\r\n    return (a.real() * b.imag()\
    \ - a.imag() * b.real());\r\n}\r\n\r\n// ccw (c \u304C\u76F4\u7DDA(\u7DDA\u5206\
    ) ab \u306B\u5BFE\u3057\u3066\u3069\u306E\u3088\u3046\u306A\u4F4D\u7F6E\u95A2\u4FC2\
    \u304B\uFF1F)\r\n// Verified: AOJ CGL_1_C: Counter-Clockwise\r\n// +1 ... a \u2192\
    \ b \u3067\u534A\u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066 b \u2192 c (COUNTER_CLOCKWISE)\r\
    \n// -1 ... a \u2192 b \u3067\u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066\
    \ b \u2192 c (CLOCKWISE)\r\n// +2 ... c, a, b \u304C\u3053\u306E\u9806\u3067\u540C\
    \u4E00\u76F4\u7DDA\u72B6\u306B\u3042\u308B\u5834\u5408 (ONLINE_BACK)\r\n// -2\
    \ ... a, b, c \u304C\u3053\u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\u306B\
    \u3042\u308B\u5834\u5408 ( or a == b ) (ONLINE_FRONT)\r\n//  0 ... c \u304C\u7DDA\
    \u5206 ab \u4E0A\u306B\u3042\u308B\u5834\u5408 (\u70B9 a, b \u4E0A\u3092\u542B\
    \u3080) (ON_SEGMENT)\r\nint ccw(Point a, Point b, Point c) {\r\n    b -= a; c\
    \ -= a;\r\n    if( cross(b,c) > EPS ) return +1;\r\n    if( cross(b,c) < -EPS\
    \ ) return -1;\r\n    if( dot(b,c) < 0 ) return +2;\r\n    if( norm(b) < norm(c)\
    \ ) return -2;\r\n    return 0;\r\n}\r\n\r\n/***** \u30C6\u30AF\u30CB\u30C3\u30AF\
    \u7DE8 *****/\r\n\r\n/*\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u7D76\u5BFE\u5024\
    \u3092\u6C42\u3081\u308B (complex\u578B)\r\ndouble len = abs(a);\r\n\r\n// 2\u70B9\
    \ a,b \u9593\u306E\u8DDD\u96E2\u3092\u6C42\u3081\u308B (complex\u578B)\r\ndouble\
    \ dist = abs(a-b);\r\n\r\n// 2\u70B9\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\
    \u304B\u306E\u5224\u5B9A\r\nif(abs(a-b) < EPS)\r\n\r\n// \u30D9\u30AF\u30C8\u30EB\
    \ a \u306E\u5358\u4F4D\u30D9\u30AF\u30C8\u30EB b \u3092\u6C42\u3081\u308B\r\n\
    Point b = a / abs(a);\r\n\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u6CD5\u7DDA\u30D9\
    \u30AF\u30C8\u30EB n1, n2 \u3092\u6C42\u3081\u308B\r\nPoint n1 = a * Point(0,\
    \ 1);\r\nPoint n2 = a * Point(0, -1);\r\n\r\n// \u30D9\u30AF\u30C8\u30EB a \u306E\
    \u5358\u4F4D\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB un1, un2 \u3092\u6C42\u3081\u308B\
    \r\nPoint un1 = (a * Point(0, 1)) / abs(a);\r\nPoint un2 = (a * Point(0, -1))\
    \ / abs(a);\r\n*/\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_000_basic.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_000_basic.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_000_basic.cpp
- /library/geometry/old/gmtr_000_basic.cpp.html
title: geometry/old/gmtr_000_basic.cpp
---
