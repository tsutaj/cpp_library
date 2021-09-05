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
  bundledCode: "#line 1 \"geometry/old/gmtr_008_circle_points.cpp\"\n// \u4E09\u89D2\
    \u5F62\u306E\u5916\u5FC3\u3002\u70B9 a, b, c \u306F\u540C\u4E00\u7DDA\u4E0A\u306B\
    \u3042\u3063\u3066\u306F\u306A\u3089\u306A\u3044\r\nPoint circumcenter(Point a,\
    \ Point b, Point c) {\r\n    a = (a-c) * 0.5;\r\n    b = (b-c) * 0.5;\r\n    return\
    \ c + crossp_ll(a, a*Point(1,1), b, b*Point(1,1));\r\n}\r\n\r\n// \u4E09\u89D2\
    \u5F62\u306E\u5185\u5FC3\r\nPoint InnerCenter(Point a, Point b, Point c) {\r\n\
    \    double p = abs(b-c), q = abs(c-a), r = abs(a-b);\r\n    return (p*a + q*b\
    \ + r*c) / (p + q + r);\r\n}\r\n\r\n// \u4E09\u89D2\u5F62\u306E\u91CD\u5FC3\r\n\
    Point CenterOfGravity(Point a, Point b, Point c) {\r\n    return (a + b + c) /\
    \ 3.0;\r\n}\r\n\r\n// \u4E09\u89D2\u5F62\u306E\u5782\u5FC3\r\nPoint Orthocenter(Point\
    \ a, Point b, Point c) {\r\n    Point x = circumcenter(a, b, c);\r\n    Point\
    \ ret = (a-x) + (b-x) + (c-x);\r\n    return ret-x;\r\n}\r\n\r\n// \u70B9 a \u3068\
    \ \u70B9 b \u3092\u901A\u308A\u3001\u534A\u5F84\u304C r \u306E\u5186\u306E\u4E2D\
    \u5FC3\u3092\u8FD4\u3059\r\nvector<Point> circlesPointsRadius(Point a, Point b,\
    \ double r) {\r\n    vector<Point> cs;\r\n    Point abH = (b-a) * 0.5;\r\n   \
    \ double d = abs(abH);\r\n\r\n    if(d == 0 || d > r) return cs; // \u5FC5\u8981\
    \u306A\u3089 !LE(d,r) \u3068\u3057\u3066\u51861\u3064\u306B\u306A\u308B\u5074\u3078\
    \u4E38\u3081\u308B\r\n    double dN = sqrt(r*r - d*d);   // \u5FC5\u8981\u306A\
    \u3089 max(r*r - d*d, 0) \u3068\u3059\u308B\r\n    Point n = abH * Point(0,1)\
    \ * (dN / d);\r\n    cs.push_back(a + abH + n);\r\n    if(dN > 0) cs.push_back(a\
    \ + abH - n);\r\n    return cs;\r\n}\r\n\r\n// \u70B9 a \u3068\u70B9 b \u3092\u901A\
    \u308A\u3001\u76F4\u7DDA l \u306B\u63A5\u3059\u308B\u5186\u306E\u4E2D\u5FC3\r\n\
    vector<Point> circlesPointsTangent(Point a, Point b, Point l1, Point l2) {\r\n\
    \    Point n = (l2-l1) * Point(0,1);\r\n    Point m = (b-a) * Point(0,0.5);\r\n\
    \    double rC = dot((a+b)*0.5-l1, n);\r\n    double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);\r\
    \n    double qb = -rC * dot(n,m);\r\n    double qc = norm(n)*norm(m) - rC*rC;\r\
    \n    double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0\r\n\r\n    vector<Point>\
    \ cs;\r\n    if(qd < -EPS) return cs;\r\n    if(EQ(qa, 0)) {\r\n        if(!EQ(qb,0))\
    \ cs.push_back((a+b)*0.5 - m * (qc/qb/2));\r\n        return cs;\r\n    }\r\n\
    \    double t = -1*qb/qa;\r\n    cs.push_back( (a+b)*0.5 + m * (t + sqrt(max(qd,\
    \ 0.0)) / qa ));\r\n    if(qd > EPS) cs.push_back( (a+b)*0.5 + m * (t - sqrt(max(qd,\
    \ 0.0)) / qa));\r\n    return cs;\r\n}\r\n\r\n// \u70B9\u96C6\u5408\u3092\u542B\
    \u3080\u6700\u5C0F\u306E\u5186\u306E\u4E2D\u5FC3\r\nPoint minEnclosingCircle(const\
    \ vector<Point> &ps) {\r\n    Point c;\r\n    double move = 0.5;\r\n    for(int\
    \ i=0; i<39; i++) { // 2^(-39-1) \\approx 0.9e-12\r\n        for(int t=0; t<50;\
    \ t++) {\r\n            double max = 0;\r\n            int k = 0;\r\n        \
    \    for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c)) {\r\n       \
    \         max = norm(ps[j] - c);\r\n                k = j;\r\n            }\r\n\
    \            c += (ps[k] - c) * move;\r\n        }\r\n        move /= 2;\r\n \
    \   }\r\n    return c;\r\n}\r\n"
  code: "// \u4E09\u89D2\u5F62\u306E\u5916\u5FC3\u3002\u70B9 a, b, c \u306F\u540C\u4E00\
    \u7DDA\u4E0A\u306B\u3042\u3063\u3066\u306F\u306A\u3089\u306A\u3044\r\nPoint circumcenter(Point\
    \ a, Point b, Point c) {\r\n    a = (a-c) * 0.5;\r\n    b = (b-c) * 0.5;\r\n \
    \   return c + crossp_ll(a, a*Point(1,1), b, b*Point(1,1));\r\n}\r\n\r\n// \u4E09\
    \u89D2\u5F62\u306E\u5185\u5FC3\r\nPoint InnerCenter(Point a, Point b, Point c)\
    \ {\r\n    double p = abs(b-c), q = abs(c-a), r = abs(a-b);\r\n    return (p*a\
    \ + q*b + r*c) / (p + q + r);\r\n}\r\n\r\n// \u4E09\u89D2\u5F62\u306E\u91CD\u5FC3\
    \r\nPoint CenterOfGravity(Point a, Point b, Point c) {\r\n    return (a + b +\
    \ c) / 3.0;\r\n}\r\n\r\n// \u4E09\u89D2\u5F62\u306E\u5782\u5FC3\r\nPoint Orthocenter(Point\
    \ a, Point b, Point c) {\r\n    Point x = circumcenter(a, b, c);\r\n    Point\
    \ ret = (a-x) + (b-x) + (c-x);\r\n    return ret-x;\r\n}\r\n\r\n// \u70B9 a \u3068\
    \ \u70B9 b \u3092\u901A\u308A\u3001\u534A\u5F84\u304C r \u306E\u5186\u306E\u4E2D\
    \u5FC3\u3092\u8FD4\u3059\r\nvector<Point> circlesPointsRadius(Point a, Point b,\
    \ double r) {\r\n    vector<Point> cs;\r\n    Point abH = (b-a) * 0.5;\r\n   \
    \ double d = abs(abH);\r\n\r\n    if(d == 0 || d > r) return cs; // \u5FC5\u8981\
    \u306A\u3089 !LE(d,r) \u3068\u3057\u3066\u51861\u3064\u306B\u306A\u308B\u5074\u3078\
    \u4E38\u3081\u308B\r\n    double dN = sqrt(r*r - d*d);   // \u5FC5\u8981\u306A\
    \u3089 max(r*r - d*d, 0) \u3068\u3059\u308B\r\n    Point n = abH * Point(0,1)\
    \ * (dN / d);\r\n    cs.push_back(a + abH + n);\r\n    if(dN > 0) cs.push_back(a\
    \ + abH - n);\r\n    return cs;\r\n}\r\n\r\n// \u70B9 a \u3068\u70B9 b \u3092\u901A\
    \u308A\u3001\u76F4\u7DDA l \u306B\u63A5\u3059\u308B\u5186\u306E\u4E2D\u5FC3\r\n\
    vector<Point> circlesPointsTangent(Point a, Point b, Point l1, Point l2) {\r\n\
    \    Point n = (l2-l1) * Point(0,1);\r\n    Point m = (b-a) * Point(0,0.5);\r\n\
    \    double rC = dot((a+b)*0.5-l1, n);\r\n    double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);\r\
    \n    double qb = -rC * dot(n,m);\r\n    double qc = norm(n)*norm(m) - rC*rC;\r\
    \n    double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0\r\n\r\n    vector<Point>\
    \ cs;\r\n    if(qd < -EPS) return cs;\r\n    if(EQ(qa, 0)) {\r\n        if(!EQ(qb,0))\
    \ cs.push_back((a+b)*0.5 - m * (qc/qb/2));\r\n        return cs;\r\n    }\r\n\
    \    double t = -1*qb/qa;\r\n    cs.push_back( (a+b)*0.5 + m * (t + sqrt(max(qd,\
    \ 0.0)) / qa ));\r\n    if(qd > EPS) cs.push_back( (a+b)*0.5 + m * (t - sqrt(max(qd,\
    \ 0.0)) / qa));\r\n    return cs;\r\n}\r\n\r\n// \u70B9\u96C6\u5408\u3092\u542B\
    \u3080\u6700\u5C0F\u306E\u5186\u306E\u4E2D\u5FC3\r\nPoint minEnclosingCircle(const\
    \ vector<Point> &ps) {\r\n    Point c;\r\n    double move = 0.5;\r\n    for(int\
    \ i=0; i<39; i++) { // 2^(-39-1) \\approx 0.9e-12\r\n        for(int t=0; t<50;\
    \ t++) {\r\n            double max = 0;\r\n            int k = 0;\r\n        \
    \    for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c)) {\r\n       \
    \         max = norm(ps[j] - c);\r\n                k = j;\r\n            }\r\n\
    \            c += (ps[k] - c) * move;\r\n        }\r\n        move /= 2;\r\n \
    \   }\r\n    return c;\r\n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_008_circle_points.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_008_circle_points.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_008_circle_points.cpp
- /library/geometry/old/gmtr_008_circle_points.cpp.html
title: geometry/old/gmtr_008_circle_points.cpp
---
