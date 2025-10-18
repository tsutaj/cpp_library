---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_1_A/geometry.test.cpp
    title: verifying_test/AOJ/CGL_1_A/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_1_B/geometry.test.cpp
    title: verifying_test/AOJ/CGL_1_B/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_1_C/geometry.test.cpp
    title: verifying_test/AOJ/CGL_1_C/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_2_A/geometry.test.cpp
    title: verifying_test/AOJ/CGL_2_A/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_2_B/geometry.test.cpp
    title: verifying_test/AOJ/CGL_2_B/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_2_C/geometry.test.cpp
    title: verifying_test/AOJ/CGL_2_C/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_2_D/geometry.test.cpp
    title: verifying_test/AOJ/CGL_2_D/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_3_A/geometry.test.cpp
    title: verifying_test/AOJ/CGL_3_A/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_3_C/geometry.test.cpp
    title: verifying_test/AOJ/CGL_3_C/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_4_A/geometry.test.cpp
    title: verifying_test/AOJ/CGL_4_A/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_4_B/geometry.test.cpp
    title: verifying_test/AOJ/CGL_4_B/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_4_C/geometry.test.cpp
    title: verifying_test/AOJ/CGL_4_C/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_7_A/geometry.test.cpp
    title: verifying_test/AOJ/CGL_7_A/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_7_D/geometry.test.cpp
    title: verifying_test/AOJ/CGL_7_D/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_7_E/geometry.test.cpp
    title: verifying_test/AOJ/CGL_7_E/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_7_F/geometry.test.cpp
    title: verifying_test/AOJ/CGL_7_F/geometry.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/CGL_7_G/geometry.test.cpp
    title: verifying_test/AOJ/CGL_7_G/geometry.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/geometry_2D.cpp\"\n/***** \u57FA\u672C\u7684\u6E96\
    \u5099 *****/\n\n// xy\u5E73\u9762\u4E0A\u306E\u70B9(\u30D9\u30AF\u30C8\u30EB\
    )\u3092\u8868\u73FE\u3059\u308B\u306B\u306F\u3001complex\u578B\u3092\u5229\u7528\
    \u3059\u308B\u3068\u3088\u3044\ntypedef complex<double> Point;\n\n// \u8FBA\u306E\
    \u8868\u73FE (\u5EA7\u6A19\u30922\u3064 pair \u3067\u3082\u3064)\ntypedef pair<Point,\
    \ Point> Line;\n\n// \u5186\u306E\u8868\u73FE (\u5EA7\u6A19 P \u3068 \u534A\u5F84\
    \ d \u3067\u8868\u73FE\u3059\u308B)\ntypedef pair<Point, double> Circle;\n\n//\
    \ \u8AA4\u5DEE(epsilon)\u306E\u5B9A\u7FA9\nconst double EPS = 1e-10;\n\n// 2\u3064\
    \u306E\u8981\u7D20\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\ntemplate <typename\
    \ float_type>\nbool EQ(float_type a, float_type b) { return abs(a - b) < EPS;\
    \ }\n\n// 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u304C\u7B49\u3057\u3044\u304B\u3069\
    \u3046\u304B\ntemplate <typename complex_type>\nbool EQV(complex_type a, complex_type\
    \ b) { return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()); }\n\n// m \u306F\
    \ n \u3088\u308A\u5927\u304D\u3044(\u4EE5\u4E0A)\u304B\u3069\u3046\u304B\ntemplate\
    \ <typename float_type>\nbool LE(float_type n, float_type m) { return n < m +\
    \ EPS; }\ntemplate <typename float_type>\nbool LEQ(float_type n, float_type m)\
    \ { return n <= m + EPS; }\n\n// m \u306F n \u3088\u308A\u5C0F\u3055\u3044(\u4EE5\
    \u4E0B)\u304B\u3069\u3046\u304B\ntemplate <typename float_type>\nbool GE(float_type\
    \ n, float_type m) { return n + EPS > m; }\ntemplate <typename float_type>\nbool\
    \ GEQ(float_type n, float_type m) { return n + EPS >= m; }\n\n// 2\u3064\u306E\
    \u30D9\u30AF\u30C8\u30EB\u306E\u5185\u7A4D\u3092\u6C42\u3081\u308B\ndouble dot(Point\
    \ a, Point b) {\n    return (a.real() * b.real() + a.imag() * b.imag());\n}\n\n\
    // 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u306E\u5916\u7A4D\u3092\u6C42\u3081\u308B\
    \ndouble cross(Point a, Point b) {\n    return (a.real() * b.imag() - a.imag()\
    \ * b.real());\n}\n\n// ccw (c \u304C\u76F4\u7DDA(\u7DDA\u5206) ab \u306B\u5BFE\
    \u3057\u3066\u3069\u306E\u3088\u3046\u306A\u4F4D\u7F6E\u95A2\u4FC2\u304B\uFF1F\
    )\n// Verified: AOJ CGL_1_C: Counter-Clockwise\n// +1 ... a \u2192 b \u3067\u534A\
    \u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066 b \u2192 c (COUNTER_CLOCKWISE)\n\
    // -1 ... a \u2192 b \u3067\u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066 b\
    \ \u2192 c (CLOCKWISE)\n// +2 ... c, a, b \u304C\u3053\u306E\u9806\u3067\u540C\
    \u4E00\u76F4\u7DDA\u72B6\u306B\u3042\u308B\u5834\u5408 (ONLINE_BACK)\n// -2 ...\
    \ a, b, c \u304C\u3053\u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\u306B\u3042\
    \u308B\u5834\u5408 ( or a == b ) (ONLINE_FRONT)\n//  0 ... c \u304C\u7DDA\u5206\
    \ ab \u4E0A\u306B\u3042\u308B\u5834\u5408 (\u70B9 a, b \u4E0A\u3092\u542B\u3080\
    ) (ON_SEGMENT)\nint ccw(Point a, Point b, Point c) {\n    b -= a; c -= a;\n  \
    \  if( cross(b,c) > EPS ) return +1;\n    if( cross(b,c) < -EPS ) return -1;\n\
    \    if( dot(b,c) < 0 ) return +2;\n    if( norm(b) < norm(c) ) return -2;\n \
    \   return 0;\n}\n\n/***** \u30C6\u30AF\u30CB\u30C3\u30AF\u7DE8 *****/\n\n/*\n\
    // \u30D9\u30AF\u30C8\u30EB a \u306E\u7D76\u5BFE\u5024\u3092\u6C42\u3081\u308B\
    \ (complex\u578B)\ndouble len = abs(a);\n\n// 2\u70B9 a,b \u9593\u306E\u8DDD\u96E2\
    \u3092\u6C42\u3081\u308B (complex\u578B)\ndouble dist = abs(a-b);\n\n// 2\u70B9\
    \u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\nif(abs(a-b)\
    \ < EPS)\n\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u5358\u4F4D\u30D9\u30AF\u30C8\
    \u30EB b \u3092\u6C42\u3081\u308B\nPoint b = a / abs(a);\n\n// \u30D9\u30AF\u30C8\
    \u30EB a \u306E\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB n1, n2 \u3092\u6C42\u3081\u308B\
    \nPoint n1 = a * Point(0, 1);\nPoint n2 = a * Point(0, -1);\n\n// \u30D9\u30AF\
    \u30C8\u30EB a \u306E\u5358\u4F4D\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB un1, un2\
    \ \u3092\u6C42\u3081\u308B\nPoint un1 = (a * Point(0, 1)) / abs(a);\nPoint un2\
    \ = (a * Point(0, -1)) / abs(a);\n*/\n\n/***** \u76F4\u4EA4\u30FB\u5E73\u884C\u5224\
    \u5B9A *****/\n// Verified: AOJ CGL_2_A: Parallel/Orthogonal\n\n// 2\u76F4\u7DDA\
    \u306E\u76F4\u4EA4\u5224\u5B9A (\u5185\u7A4D\u304C0\u3067\u3042\u308B\u3053\u3068\
    )\nbool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {\n    return EQ(\
    \ dot(a1-a2, b1-b2), 0.0 );\n}\n\n// 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\u5B9A\
    \ (\u5916\u7A4D\u304C0\u3067\u3042\u308B\u3053\u3068)\nbool is_parallel(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    return EQ( cross(a1-a2, b1-b2), 0.0\
    \ );\n}\n\n/***** \u5404\u7A2E\u4EA4\u5DEE\u5224\u5B9A (intersection) *****/\n\
    // \u8C46\u77E5\u8B58: \u7DDA\u5206 ... line segment (\u82F1)\n\n// \u76F4\u7DDA\
    \ a1, a2 \u3068\u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u76F4\u7DDA\u4E0A\u306B\
    \u70B9\u304C\u3042\u308B\u304B\u306E\u5224\u5B9A)\n// ccw\u3067\u7D76\u5BFE\u5024\
    \u304C1 (\u4E00\u76F4\u7DDA\u3067\u7DDA\u5206\u4E0A\u306B\u306A\u3044) \u3067\u306A\
    \u3051\u308C\u3070\u4EA4\u5DEE\u3057\u3066\u3044\u308B\nbool isec_lp(Point a1,\
    \ Point a2, Point b) {\n    return abs( ccw(a1, a2, b) ) != 1;\n}\n\n// \u76F4\
    \u7DDA a1, a2 \u3068\u76F4\u7DDA b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\nbool isec_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    return !isec_lp(a2-a1, b2-b1, 0) ||\
    \ isec_lp(a1, b1, b2);\n}\n\n// \u76F4\u7DDA a1, a2 \u3068\u7DDA\u5206 b1, b2\
    \ \u306E\u4EA4\u5DEE\u5224\u5B9A\nbool isec_ls(Point a1, Point a2, Point b1, Point\
    \ b2) {\n    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;\n}\n\n//\
    \ \u7DDA\u5206 a1, a2 \u3068\u7DDA\u5206 b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\
    \n// Verified: CGL_2_B: Intersection\nbool isec_ss(Point a1, Point a2, Point b1,\
    \ Point b2) {\n    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&\n        \
    \   ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );\n}\n\n// \u7DDA\u5206 a1, a2 \u3068\
    \u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u7DDA\u5206\u4E0A\u306B\u70B9\u304C\u3042\
    \u308B\u304B\u306E\u5224\u5B9A)\nbool isec_sp(Point a1, Point a2, Point b) {\n\
    \    return !ccw(a1, a2, b);\n}\n\n/***** \u5404\u7A2E\u8DDD\u96E2 *****/\n\n\
    // \u70B9 p \u306E\u76F4\u7DDA a1, a2 \u3078\u306E\u5C04\u5F71\u70B9\u3092\u8FD4\
    \u3059\n// Verified: AOJ CGL_1_A: Projection\nPoint projection(Point a1, Point\
    \ a2, Point p) {\n    return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);\n\
    }\n\n// \u70B9 p \u306E\u76F4\u7DDA a \u3078\u306E\u53CD\u5C04\u70B9\u3092\u8FD4\
    \u3059\n// Verified: AOJ CGL_1_B: Reflection\nPoint reflection(Point a1, Point\
    \ a2, Point p) {\n    return 2.0 * projection(a1, a2, p) - p;\n}\n\n// \u70B9\
    \ a1, a2 \u3092\u901A\u308B\u76F4\u7DDA\u3068\u70B9 b \u3068\u306E\u8DDD\u96E2\
    \ndouble dist_lp(Point a1, Point a2, Point b) {\n    return abs( cross(a2-a1,\
    \ b-a1) ) / abs(a2-a1);\n}\n\n// \u76F4\u7DDA a1, a2 \u3068 \u76F4\u7DDA b1, b2\
    \ \u3068\u306E\u8DDD\u96E2\ndouble dist_ll(Point a1, Point a2, Point b1, Point\
    \ b2) {\n    return isec_ll(a1, a2, b1, b2) ? 0 : dist_lp(a1, a2, b1);\n}\n\n\
    // \u76F4\u7DDA a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\u8DDD\u96E2\ndouble\
    \ dist_ls(Point a1, Point a2, Point b1, Point b2) {\n    return isec_ls(a1, a2,\
    \ b1, b2) ? 0 : min( dist_lp(a1, a2, b1), dist_lp(a1, a2, b2) );\n}\n\n// \u70B9\
    \ a1, a2 \u3092\u7AEF\u70B9\u3068\u3059\u308B\u7DDA\u5206\u3068\u70B9 b \u3068\
    \u306E\u8DDD\u96E2\ndouble dist_sp(Point a1, Point a2, Point b) {\n    if( dot(a2-a1,\
    \ b-a1) < EPS ) return abs(b - a1);\n    if( dot(a1-a2, b-a2) < EPS ) return abs(b\
    \ - a2);\n    return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);\n}\n\n// \u7DDA\
    \u5206 a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\u8DDD\u96E2\n// Verified:\
    \ CGL_2_D: Distance\ndouble dist_ss(Point a1, Point a2, Point b1, Point b2) {\n\
    \    if(isec_ss(a1, a2, b1, b2)) return 0;\n    return min( min(dist_sp(a1, a2,\
    \ b1), dist_sp(a1, a2, b2)),\n                min(dist_sp(b1, b2, a1), dist_sp(b1,\
    \ b2, a2)) );\n}\n\n// \u76F4\u7DDA a1, a2 \u3068\u76F4\u7DDAb1, b2\u306E\u4EA4\
    \u70B9\u3092\u6C42\u3081\u308B\n// Verified: AOJ CGL_2_C.cpp\nPoint crossp_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    double d1 = cross(b2-b1, b1-a1);\n\
    \    double d2 = cross(b2-b1, a2-a1);\n    if( EQ(d1,0.0) && EQ(d2,0.0) ) return\
    \ a1; // same line\n    if( EQ(d2,0.0) ) assert(false); // precondition not satisfied\n\
    \    return a1 + d1 / d2 * (a2 - a1);\n}\n\n/***** \u5186\u306B\u95A2\u3059\u308B\
    \u554F\u984C *****/\n\n// \u76F4\u7DDA a1, a2 \u3068 \u5186 C \u3068\u306E\u8DDD\
    \u96E2\ndouble dist_lc(Point a1, Point a2, Circle c) {\n    return max(dist_lp(a1,\
    \ a2, c.first) - c.second, 0.0);\n}\n\n// \u7DDA\u5206 a1, a2 \u3068 \u5186 C\
    \ \u3068\u306E\u8DDD\u96E2\ndouble dist_sc(Point a1, Point a2, Circle c) {\n \
    \   double dSqr1 = norm(c.first - a1), dSqr2 = norm(c.first - a2);\n    double\
    \ r = c.second;\n    if((dSqr1 < r*r) ^ (dSqr2 < r*r)) return 0; //\u5186\u304C\
    \u7DDA\u5206\u3092\u5305\u542B\u3059\u308B\u3068\u304D\u8DDD\u96E20\u306A\u3089\
    \u3070\u3053\u3053\u3092OR\u306B\u5909\u3048\u308B\n    if((dSqr1 < r*r) & (dSqr2\
    \ < r*r)) return r - sqrt(max(dSqr1, dSqr2));\n    return max(dist_sp(a1, a2,\
    \ c.first) - r, 0.0);\n}\n\n// \u5186 x \u3068\u5186 y \u3068\u306E\u8DDD\u96E2\
    \ndouble dist_cc(Circle x, Circle y) {\n    Point a = x.first, b = y.first;\n\
    \    double ar = x.second, br = y.second;\n\n    double d = abs(a-b);\n    return\
    \ GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;\n}\n\n// \u76F4\u7DDA\
    \ a1, a2 \u3068\u5186 C \u3068\u306E\u4EA4\u70B9\n// Verified: AOJ CGL_7_D: Cross\
    \ Points of a Circle and a Line\nvector<Point> crossp_lc(Point a1, Point a2, Circle\
    \ c) {\n    vector<Point> ps;\n    double r = c.second;\n    Point ft = projection(a1,\
    \ a2, c.first);\n    if(!GEQ(r*r, norm(ft-c.first))) return ps;\n\n    Point dir\
    \ = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);\n    ps.push_back(ft\
    \ + dir);\n    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);\n    return\
    \ ps;\n}\n\n// \u5186 x \u3068\u5186 y \u306E\u4EA4\u70B9\n// Verified: AOJ CGL_7_E:\
    \ Cross Points of Circles\nvector<Point> crossp_cc(Circle x, Circle y) {\n   \
    \ vector<Point> ps;\n    Point a = x.first, b = y.first;\n    double ar = x.second,\
    \ br = y.second;\n\n    Point ab = b-a;\n    double d = abs(ab);\n    double crL\
    \ = (norm(ab) + ar * ar - br * br) / (2 * d);\n    if(EQ(d,0.0) || ar < abs(crL))\
    \ return ps;\n\n    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);\n  \
    \  Point cp = a + crL/d * ab;\n    ps.push_back(cp + abN);\n    if(!EQ(norm(abN),\
    \ 0.0)) ps.push_back(cp - abN);\n    return ps;\n}\n\n// \u70B9 p \u304B\u3089\
    \u5186 x \u3078\u306E\u63A5\u7DDA\u306E\u63A5\u70B9\n// Verified: AOJ CGL_7_F:\
    \ Tangent to a Circle\nvector<Point> tangentPoints(Point p, Circle x) {\n    vector<Point>\
    \ ps;\n    Point a = x.first; double ar = x.second;\n    double sin = ar / abs(p-a);\n\
    \    if(!LE(sin, 1.0)) return ps; // \u3053\u3053\u3067 NaN \u3082\u306F\u3058\
    \u304B\u308C\u308B\n\n    double t = M_PI_2 - asin(min(sin, 1.0));\n    ps.push_back(a\
    \ + (p-a) * polar(sin, t));\n    if(!EQ(sin, 1.0)) ps.push_back(a + (p-a)*polar(sin,\
    \ -t));\n    return ps;\n}\n\n// \u5186 x \u3068\u5186 y \u306E\u5171\u901A\u63A5\
    \u7DDA\u3002\u8FD4\u3055\u308C\u308B\u5404\u76F4\u7DDA\u306B\u542B\u307E\u308C\
    \u308B\u9802\u70B9\u306F\u5186\u3068\u306E\u63A5\u70B9\u3068\u306A\u308B\n// Verified:\
    \ AOJ CGL_7_G: Common Tangent\n// \u203B \u3084\u308B\u3053\u3068: -0.0000000\u306B\
    \u306A\u308B\u554F\u984C\u3092\u76F4\u3057\u305F\u3044\u30FB\u30FB\u30FB\nvector<Line>\
    \ tangentLines(Circle x, Circle y) {\n    Point a = x.first, b = y.first;\n  \
    \  double ar = x.second, br = y.second;\n    vector<Line> ls;\n    double d =\
    \ abs(b-a);\n\n    for(int i=0; i<2; i++) {\n        double sin = (ar - (1-i*2)*br)\
    \ / d;\n        if(!LE(sin*sin, 1.0)) break;\n\n        double cos = sqrt(max(1\
    \ - sin*sin, 0.0));\n        for(int j=0; j<2; j++) {\n            Point n = (b-a)\
    \ * Point(sin, (1-j*2)*cos) / d;\n            ls.push_back(Line(a + ar*n, b +\
    \ (1-i+2)*br*n));\n            if(cos < EPS) break; // \u91CD\u8907\u3059\u308B\
    \u63A5\u7DDA\u3092\u7121\u8996 (\u91CD\u8907\u3057\u3066\u3088\u3044\u306A\u3089\
    \u3053\u306E\u884C\u306F\u4E0D\u8981)\n        }\n    }\n    return ls;\n}\n\n\
    // \u5186 c1 \u3068\u5186 c2 \u306E\u4F4D\u7F6E\u95A2\u4FC2\n// Verified: AOJ\
    \ CGL_7_A: Intersection\nint intersectCC(Circle c1, Circle c2){\n    Point c1p\
    \ = c1.first, c2p = c2.first;\n    double c1r = c1.second, c2r = c2.second;\n\
    \    long double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;\n    if(r1 + r2 < d)\
    \            return  0; // \u96E2\u308C\u3066\u3044\u308B\n    if(abs(r1 + r2\
    \ - d) < EPS) return -2; // \u5916\u63A5\n    if(abs(d + r1 - r2) < EPS) return\
    \ +1; // c1 \u304C c2 \u306E\u4E2D\u3067\u5185\u63A5\n    if(abs(d + r2 - r1)\
    \ < EPS) return -1; // c2 \u304C c1 \u306E\u4E2D\u3067\u5185\u63A5\n    if(d +\
    \ r1 < r2)            return +3; // c1 \u304C c2 \u306E\u4E2D\n    if(d + r2 <\
    \ r1)            return -3; // c2 \u304C c1 \u306E\u4E2D\n    return 2; // 2\u3064\
    \u306E\u4EA4\u70B9\u3092\u6301\u3064\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5916\u5FC3\
    \u3002\u70B9 a, b, c \u306F\u540C\u4E00\u7DDA\u4E0A\u306B\u3042\u3063\u3066\u306F\
    \u306A\u3089\u306A\u3044\nPoint circumcenter(Point a, Point b, Point c) {\n  \
    \  a = (a-c) * 0.5;\n    b = (b-c) * 0.5;\n    return c + crossp_ll(a, a*Point(1,1),\
    \ b, b*Point(1,1));\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5185\u5FC3\nPoint InnerCenter(Point\
    \ a, Point b, Point c) {\n    double p = abs(b-c), q = abs(c-a), r = abs(a-b);\n\
    \    return (p*a + q*b + r*c) / (p + q + r);\n}\n\n// \u4E09\u89D2\u5F62\u306E\
    \u91CD\u5FC3\nPoint CenterOfGravity(Point a, Point b, Point c) {\n    return (a\
    \ + b + c) / 3.0;\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5782\u5FC3\nPoint Orthocenter(Point\
    \ a, Point b, Point c) {\n    Point x = circumcenter(a, b, c);\n    Point ret\
    \ = (a-x) + (b-x) + (c-x);\n    return ret-x;\n}\n\n// \u70B9 a \u3068 \u70B9\
    \ b \u3092\u901A\u308A\u3001\u534A\u5F84\u304C r \u306E\u5186\u306E\u4E2D\u5FC3\
    \u3092\u8FD4\u3059\nvector<Point> circlesPointsRadius(Point a, Point b, double\
    \ r) {\n    vector<Point> cs;\n    Point abH = (b-a) * 0.5;\n    double d = abs(abH);\n\
    \n    if(d == 0 || d > r) return cs; // \u5FC5\u8981\u306A\u3089 !LE(d,r) \u3068\
    \u3057\u3066\u51861\u3064\u306B\u306A\u308B\u5074\u3078\u4E38\u3081\u308B\n  \
    \  double dN = sqrt(r*r - d*d);   // \u5FC5\u8981\u306A\u3089 max(r*r - d*d, 0)\
    \ \u3068\u3059\u308B\n    Point n = abH * Point(0,1) * (dN / d);\n    cs.push_back(a\
    \ + abH + n);\n    if(dN > 0) cs.push_back(a + abH - n);\n    return cs;\n}\n\n\
    // \u70B9 a \u3068\u70B9 b \u3092\u901A\u308A\u3001\u76F4\u7DDA l \u306B\u63A5\
    \u3059\u308B\u5186\u306E\u4E2D\u5FC3\nvector<Point> circlesPointsTangent(Point\
    \ a, Point b, Point l1, Point l2) {\n    Point n = (l2-l1) * Point(0,1);\n   \
    \ Point m = (b-a) * Point(0,0.5);\n    double rC = dot((a+b)*0.5-l1, n);\n   \
    \ double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);\n    double qb = -rC * dot(n,m);\n\
    \    double qc = norm(n)*norm(m) - rC*rC;\n    double qd = qb*qb - qa*qc;  //\
    \ qa*k^2 + 2*qb*k + qc = 0\n\n    vector<Point> cs;\n    if(qd < -EPS) return\
    \ cs;\n    if(EQ(qa, 0.0)) {\n        if(!EQ(qb,0.0)) cs.push_back((a+b)*0.5 -\
    \ m * (qc/qb/2));\n        return cs;\n    }\n    double t = -1*qb/qa;\n    cs.push_back(\
    \ (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0)) / qa ));\n    if(qd > EPS) cs.push_back(\
    \ (a+b)*0.5 + m * (t - sqrt(max(qd, 0.0)) / qa));\n    return cs;\n}\n\n// \u70B9\
    \u96C6\u5408\u3092\u542B\u3080\u6700\u5C0F\u306E\u5186\u306E\u4E2D\u5FC3\nPoint\
    \ minEnclosingCircle(const vector<Point> &ps) {\n    Point c;\n    double move\
    \ = 0.5;\n    for(int i=0; i<39; i++) { // 2^(-39-1) \\approx 0.9e-12\n      \
    \  for(int t=0; t<50; t++) {\n            double max = 0;\n            int k =\
    \ 0;\n            for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c))\
    \ {\n                max = norm(ps[j] - c);\n                k = j;\n        \
    \    }\n            c += (ps[k] - c) * move;\n        }\n        move /= 2;\n\
    \    }\n    return c;\n}\n\n// (\u57FA\u672C) \u9802\u70B9\u306E\u9806\u5E8F (sort\u3084\
    max_element\u306B\u5FC5\u8981)\nnamespace std {\n    bool operator<(const Point\
    \ a, const Point b) {\n        return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag();\n    }\n}\n\n// \u51F8\u5305\n// Verified: AOJ CGL_4_A:\
    \ Convex Hull\n// y\u5EA7\u6A19\u512A\u5148\u3067\u30BD\u30FC\u30C8(\u5FC5\u8981\
    \u304C\u3042\u308C\u3070)\nbool cmp_y(const Point &a, const Point& b) {\n    return\
    \ a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();\n}\n\nvector<Point>\
    \ convexHull(vector<Point> ps) {\n    int n = ps.size();\n    sort(ps.begin(),\
    \ ps.end(), cmp_y);\n\n    int k = 0;\n    vector<Point> convex(n*2);\n    for(int\
    \ i=0; i<n; i++) {\n        while (k >= 2 && ccw(convex[k-2], convex[k-1], ps[i])\
    \ == -1 ) k--;\n        convex[ k++ ] = ps[i];\n    }\n    for(int i=n-2, t=k;\
    \ i>=0; i--) {\n        while (k > t && ccw(convex[k-2], convex[k-1], ps[i]) ==\
    \ -1 ) k--;\n        convex[ k++ ] = ps[i];\n    }\n    convex.resize(k-1);\n\
    \    return convex;\n}\n\n/* \u3053\u308C\u306F\u30D0\u30B0\u308B\u306E\u3067\u4F7F\
    \u7528\u7981\u6B62\u3002\u5F8C\u3067\u76F4\u3057\u305F\u3044\nvector<Point> convexHull(vector<Point>\
    \ ps) { // \u5143\u306E\u70B9\u96C6\u5408\u304C\u30BD\u30FC\u30C8\u3055\u308C\u3066\
    \u3044\u3044\u306A\u3089 vector<Point> & \u306B\n    int n = ps.size(), k = 0;\n\
    \    sort(ps.begin(), ps.end());\n    vector<Point> ch(2 * n);\n    for(int i=0;\
    \ i<n; ch[k++] = ps[i++]) // lower-hull\n        while(k >= 2 && ccw(ch[k-2],\
    \ ch[k-1], ps[i]) <= 0) --k; // \u4F59\u8A08\u306A\u70B9\u3082\u542B\u3080\u306A\
    \u3089-1\u3068\u3059\u308B\n    for(int i=n-2, t=k+1; i>=0; ch[k++] = ps[i--])\
    \ //upper-hull\n        while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;\n\
    \    ch.resize(k-1);\n    return ch;\n}\n*/\n\n// \u51F8\u5224\u5B9A\u3002\u7E2E\
    \u9000\u3092\u8A8D\u3081\u306A\u3044\u306A\u3089 ccw \u306E\u5224\u5B9A\u90E8\u5206\
    \u3092 != 1 \u3068\u3059\u308B\n// Verified: CGL_3_B: Is-Convex\nbool isCcwConvex(const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    for(int i=0; i<n; i++) if(ccw(ps[i],\
    \ ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;\n    return true;\n}\n\n\
    // \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(n)\n// \u70B9\u304C\
    \u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u30892\u3001\
    \u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\nint inConvex(Point p, const vector<Point>\
    \ &ps) {\n    int n = ps.size();\n    int dir = ccw(ps[0], ps[1], p);\n    for(int\
    \ i=0; i<n; i++) {\n        int ccwc = ccw(ps[i], ps[(i+1) % n], p);\n       \
    \ if(!ccwc) return 2;\n        if(ccwc != dir) return 0;\n    }\n    return 1;\n\
    }\n\n// \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(log n)\n// \u70B9\
    \u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u3089\
    2\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\nint inCcwConvex(Point p, const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    Point g = (ps[0] + ps[n /\
    \ 3] + ps[n*2 / 3]) / 3.0;\n    if(g == p) return 1;\n    Point gp = p - g;\n\n\
    \    int l = 0, r = n;\n    while(l + 1 < r) {\n        int mid = (l + r) / 2;\n\
    \        Point gl = ps[l] - g;\n        Point gm = ps[mid] - g;\n        if(cross(gl,gm)\
    \ > 0) {\n            if(cross(gl,gp) >= 0 && cross(gm,gp) <= 0) r = mid;\n  \
    \          else l = mid;\n        }\n        else {\n            if(cross(gl,gp)\
    \ <= 0 && cross(gm,gp) >= 0) l = mid;\n            else r = mid;\n        }\n\
    \    }\n    r %= n;\n    double cr = cross(ps[l] - p, ps[r] - p);\n    return\
    \ EQ(cr, 0.0) ? 2 : cr < 0 ? 0 : 1;\n}\n\n// \u591A\u89D2\u5F62\u306E\u5185\u90E8\
    \u5224\u5B9A\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\
    \u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\n//\
    \ Verified: AOJ CGL_3_C: Polygon-Point Containment\nint inPolygon(Point p, const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    bool in = false;\n    for(int\
    \ i=0; i<n; i++) {\n        Point a = ps[i] - p;\n        Point b = ps[(i+1) %\
    \ n] - p;\n        if(EQ(cross(a,b), 0.0) && LE(dot(a,b), 0.0)) return 2;\n  \
    \      if(a.imag() > b.imag()) swap(a,b);\n        if((a.imag() * b.imag() < 0\
    \ || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0.0)) in\
    \ = !in;\n    }\n    return in;\n}\n\n// \u51F8\u591A\u89D2\u5F62\u30AF\u30EA\u30C3\
    \u30D4\u30F3\u30B0\n// Verified: AOJ CGL_4_C: Convex Cut\nvector<Point> convexCut(Point\
    \ a1, Point a2, const vector<Point> &ps) {\n    int n = ps.size();\n    vector<Point>\
    \ ret;\n    for(int i=0; i<n; i++) {\n        int ccwc = ccw(a1, a2, ps[i]);\n\
    \        if(ccwc != -1) ret.push_back(ps[i]);\n        int ccwn = ccw(a1, a2,\
    \ ps[(i + 1) % n]);\n        if(ccwc * ccwn == -1) ret.push_back(crossp_ll(a1,\
    \ a2, ps[i], ps[(i + 1) % n]));\n    }\n    return ret;\n}\n\n// \u51F8\u591A\u89D2\
    \u5F62\u306E\u76F4\u5F84 (\u6700\u9060\u70B9\u5BFE)\n// Verified: AOJ CGL_4_B:\
    \ Diameter of a Convex Polygon\npair<int, int> convexDiameter(const vector<Point>\
    \ &ps) {\n    int n = ps.size();\n    int i = min_element(ps.begin(), ps.end())\
    \ - ps.begin();\n    int j = max_element(ps.begin(), ps.end()) - ps.begin();\n\
    \    int maxI, maxJ;\n    double maxD = 0;\n    for(int _=0; _<2*n; _++) {\n \
    \       if(maxD < norm(ps[i] - ps[j])) {\n            maxD = norm(ps[i] - ps[j]);\n\
    \            maxI = i;\n            maxJ = j;\n        }\n        if(cross(ps[i]\
    \ - ps[(i+1) % n], ps[(j+1) % n] - ps[j]) <= 0) j = (j+1) % n;\n        else i\
    \ = (i+1) % n;\n    }\n    return make_pair(maxI, maxJ);\n}\n\n// \u591A\u89D2\
    \u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\n// Verified: AOJ CGL_3_A: Area\ndouble\
    \ area(const vector<Point> &ps) {\n    double a = 0;\n    for(size_t i=0; i<ps.size();\
    \ i++) a += cross(ps[i], ps[(i+1) % ps.size()]);\n    return a / 2;\n}\n\n// \u591A\
    \u89D2\u5F62\u306E\u7B26\u53F7\u306A\u3057\u9762\u7A4D\ndouble area_n(const vector<Point>\
    \ &v) {\n    double ans = 0;\n    double x, y, z;\n    Point init = v[0];\n  \
    \  for(size_t i=2; i<v.size(); i++) {\n        x = sqrt(norm(v[i] - init));\n\
    \        y = sqrt(norm(v[i-1] - init));\n        z = sqrt(norm(v[i] - v[i-1]));\n\
    \n        double s = (x + y + z) / 2;\n        ans += sqrt(s * (s-x) * (s-y) *\
    \ (s-z));\n    }\n    return ans;\n}\n\n// \u591A\u89D2\u5F62\u306E\u5E7E\u4F55\
    \u5B66\u7684\u91CD\u5FC3\nPoint centroid(const vector<Point> &ps) {\n    int n\
    \ = ps.size();\n    double aSum = 0;\n    Point c;\n    for(int i=0; i<n; i++)\
    \ {\n        double a = cross(ps[i], ps[(i+1) % n]);\n        aSum += a;\n   \
    \     c += (ps[i] + ps[(i+1) % n]) * a;\n    }\n    return 1 / aSum / 3 * c;\n\
    }\n\n// \u30DC\u30ED\u30CE\u30A4\u9818\u57DF\n/*\nvector<Point> voronoiCell(Point\
    \ p, const vector<Point> &ps, const vector<Point> &outer) {\n    vector<Point>\
    \ cl = outer;\n    for(size_t i=0; i<ps.size(); i++) {\n        if(EQ(norm(ps[i]\
    \ - p), 0.0)) continue;\n        Point h = (p + ps[i]) * 0.5;\n        cl = convexCut(cl,\
    \ h, h + (ps[i] - h) * Point(0,1));\n    }\n    return cl;\n}\n*/\n\n// \u9802\
    \u70B9\u3092\u56DE\u8EE2\u3055\u305B\u308B\u7CFB\n\n// \u5EA6\u6570\u6CD5 \u2192\
    \ \u5F27\u5EA6\u6CD5\ndouble deg2rad(double x) {return x * M_PI / 180.0;}\n\n\
    // \u70B9 a \u3092\u4E2D\u5FC3\u3068\u3057\u3066\u3001\u70B9 b \u3092 z \u5EA6\
    \u56DE\u8EE2\u3055\u305B\u305F\u3068\u304D\u306E\u4F4D\u7F6E\nPoint rotatePoint(Point\
    \ a, Point b, double z) {\n    // \u5EA6\u6570\u6CD5\u306E\u5834\u5408\u306F\u5909\
    \u63DB\n    z = deg2rad(z);\n\n    b -= a;\n    double rx = b.real() * cos(z)\
    \ - b.imag() * sin(z);\n    double ry = b.real() * sin(z) + b.imag() * cos(z);\n\
    \    Point ret(rx, ry); ret += a;\n    return ret;\n}\n"
  code: "/***** \u57FA\u672C\u7684\u6E96\u5099 *****/\n\n// xy\u5E73\u9762\u4E0A\u306E\
    \u70B9(\u30D9\u30AF\u30C8\u30EB)\u3092\u8868\u73FE\u3059\u308B\u306B\u306F\u3001\
    complex\u578B\u3092\u5229\u7528\u3059\u308B\u3068\u3088\u3044\ntypedef complex<double>\
    \ Point;\n\n// \u8FBA\u306E\u8868\u73FE (\u5EA7\u6A19\u30922\u3064 pair \u3067\
    \u3082\u3064)\ntypedef pair<Point, Point> Line;\n\n// \u5186\u306E\u8868\u73FE\
    \ (\u5EA7\u6A19 P \u3068 \u534A\u5F84 d \u3067\u8868\u73FE\u3059\u308B)\ntypedef\
    \ pair<Point, double> Circle;\n\n// \u8AA4\u5DEE(epsilon)\u306E\u5B9A\u7FA9\n\
    const double EPS = 1e-10;\n\n// 2\u3064\u306E\u8981\u7D20\u304C\u7B49\u3057\u3044\
    \u304B\u3069\u3046\u304B\ntemplate <typename float_type>\nbool EQ(float_type a,\
    \ float_type b) { return abs(a - b) < EPS; }\n\n// 2\u3064\u306E\u30D9\u30AF\u30C8\
    \u30EB\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\ntemplate <typename complex_type>\n\
    bool EQV(complex_type a, complex_type b) { return EQ(a.real(), b.real()) && EQ(a.imag(),\
    \ b.imag()); }\n\n// m \u306F n \u3088\u308A\u5927\u304D\u3044(\u4EE5\u4E0A)\u304B\
    \u3069\u3046\u304B\ntemplate <typename float_type>\nbool LE(float_type n, float_type\
    \ m) { return n < m + EPS; }\ntemplate <typename float_type>\nbool LEQ(float_type\
    \ n, float_type m) { return n <= m + EPS; }\n\n// m \u306F n \u3088\u308A\u5C0F\
    \u3055\u3044(\u4EE5\u4E0B)\u304B\u3069\u3046\u304B\ntemplate <typename float_type>\n\
    bool GE(float_type n, float_type m) { return n + EPS > m; }\ntemplate <typename\
    \ float_type>\nbool GEQ(float_type n, float_type m) { return n + EPS >= m; }\n\
    \n// 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u306E\u5185\u7A4D\u3092\u6C42\u3081\
    \u308B\ndouble dot(Point a, Point b) {\n    return (a.real() * b.real() + a.imag()\
    \ * b.imag());\n}\n\n// 2\u3064\u306E\u30D9\u30AF\u30C8\u30EB\u306E\u5916\u7A4D\
    \u3092\u6C42\u3081\u308B\ndouble cross(Point a, Point b) {\n    return (a.real()\
    \ * b.imag() - a.imag() * b.real());\n}\n\n// ccw (c \u304C\u76F4\u7DDA(\u7DDA\
    \u5206) ab \u306B\u5BFE\u3057\u3066\u3069\u306E\u3088\u3046\u306A\u4F4D\u7F6E\u95A2\
    \u4FC2\u304B\uFF1F)\n// Verified: AOJ CGL_1_C: Counter-Clockwise\n// +1 ... a\
    \ \u2192 b \u3067\u534A\u6642\u8A08\u65B9\u5411\u306B\u6298\u308C\u3066 b \u2192\
    \ c (COUNTER_CLOCKWISE)\n// -1 ... a \u2192 b \u3067\u6642\u8A08\u65B9\u5411\u306B\
    \u6298\u308C\u3066 b \u2192 c (CLOCKWISE)\n// +2 ... c, a, b \u304C\u3053\u306E\
    \u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\u306B\u3042\u308B\u5834\u5408 (ONLINE_BACK)\n\
    // -2 ... a, b, c \u304C\u3053\u306E\u9806\u3067\u540C\u4E00\u76F4\u7DDA\u72B6\
    \u306B\u3042\u308B\u5834\u5408 ( or a == b ) (ONLINE_FRONT)\n//  0 ... c \u304C\
    \u7DDA\u5206 ab \u4E0A\u306B\u3042\u308B\u5834\u5408 (\u70B9 a, b \u4E0A\u3092\
    \u542B\u3080) (ON_SEGMENT)\nint ccw(Point a, Point b, Point c) {\n    b -= a;\
    \ c -= a;\n    if( cross(b,c) > EPS ) return +1;\n    if( cross(b,c) < -EPS )\
    \ return -1;\n    if( dot(b,c) < 0 ) return +2;\n    if( norm(b) < norm(c) ) return\
    \ -2;\n    return 0;\n}\n\n/***** \u30C6\u30AF\u30CB\u30C3\u30AF\u7DE8 *****/\n\
    \n/*\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u7D76\u5BFE\u5024\u3092\u6C42\u3081\
    \u308B (complex\u578B)\ndouble len = abs(a);\n\n// 2\u70B9 a,b \u9593\u306E\u8DDD\
    \u96E2\u3092\u6C42\u3081\u308B (complex\u578B)\ndouble dist = abs(a-b);\n\n//\
    \ 2\u70B9\u304C\u7B49\u3057\u3044\u304B\u3069\u3046\u304B\u306E\u5224\u5B9A\n\
    if(abs(a-b) < EPS)\n\n// \u30D9\u30AF\u30C8\u30EB a \u306E\u5358\u4F4D\u30D9\u30AF\
    \u30C8\u30EB b \u3092\u6C42\u3081\u308B\nPoint b = a / abs(a);\n\n// \u30D9\u30AF\
    \u30C8\u30EB a \u306E\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB n1, n2 \u3092\u6C42\u3081\
    \u308B\nPoint n1 = a * Point(0, 1);\nPoint n2 = a * Point(0, -1);\n\n// \u30D9\
    \u30AF\u30C8\u30EB a \u306E\u5358\u4F4D\u6CD5\u7DDA\u30D9\u30AF\u30C8\u30EB un1,\
    \ un2 \u3092\u6C42\u3081\u308B\nPoint un1 = (a * Point(0, 1)) / abs(a);\nPoint\
    \ un2 = (a * Point(0, -1)) / abs(a);\n*/\n\n/***** \u76F4\u4EA4\u30FB\u5E73\u884C\
    \u5224\u5B9A *****/\n// Verified: AOJ CGL_2_A: Parallel/Orthogonal\n\n// 2\u76F4\
    \u7DDA\u306E\u76F4\u4EA4\u5224\u5B9A (\u5185\u7A4D\u304C0\u3067\u3042\u308B\u3053\
    \u3068)\nbool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {\n    return\
    \ EQ( dot(a1-a2, b1-b2), 0.0 );\n}\n\n// 2\u76F4\u7DDA\u306E\u5E73\u884C\u5224\
    \u5B9A (\u5916\u7A4D\u304C0\u3067\u3042\u308B\u3053\u3068)\nbool is_parallel(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    return EQ( cross(a1-a2, b1-b2), 0.0\
    \ );\n}\n\n/***** \u5404\u7A2E\u4EA4\u5DEE\u5224\u5B9A (intersection) *****/\n\
    // \u8C46\u77E5\u8B58: \u7DDA\u5206 ... line segment (\u82F1)\n\n// \u76F4\u7DDA\
    \ a1, a2 \u3068\u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u76F4\u7DDA\u4E0A\u306B\
    \u70B9\u304C\u3042\u308B\u304B\u306E\u5224\u5B9A)\n// ccw\u3067\u7D76\u5BFE\u5024\
    \u304C1 (\u4E00\u76F4\u7DDA\u3067\u7DDA\u5206\u4E0A\u306B\u306A\u3044) \u3067\u306A\
    \u3051\u308C\u3070\u4EA4\u5DEE\u3057\u3066\u3044\u308B\nbool isec_lp(Point a1,\
    \ Point a2, Point b) {\n    return abs( ccw(a1, a2, b) ) != 1;\n}\n\n// \u76F4\
    \u7DDA a1, a2 \u3068\u76F4\u7DDA b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\nbool isec_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    return !isec_lp(a2-a1, b2-b1, 0) ||\
    \ isec_lp(a1, b1, b2);\n}\n\n// \u76F4\u7DDA a1, a2 \u3068\u7DDA\u5206 b1, b2\
    \ \u306E\u4EA4\u5DEE\u5224\u5B9A\nbool isec_ls(Point a1, Point a2, Point b1, Point\
    \ b2) {\n    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;\n}\n\n//\
    \ \u7DDA\u5206 a1, a2 \u3068\u7DDA\u5206 b1, b2 \u306E\u4EA4\u5DEE\u5224\u5B9A\
    \n// Verified: CGL_2_B: Intersection\nbool isec_ss(Point a1, Point a2, Point b1,\
    \ Point b2) {\n    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&\n        \
    \   ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );\n}\n\n// \u7DDA\u5206 a1, a2 \u3068\
    \u70B9 b \u306E\u4EA4\u5DEE\u5224\u5B9A (\u7DDA\u5206\u4E0A\u306B\u70B9\u304C\u3042\
    \u308B\u304B\u306E\u5224\u5B9A)\nbool isec_sp(Point a1, Point a2, Point b) {\n\
    \    return !ccw(a1, a2, b);\n}\n\n/***** \u5404\u7A2E\u8DDD\u96E2 *****/\n\n\
    // \u70B9 p \u306E\u76F4\u7DDA a1, a2 \u3078\u306E\u5C04\u5F71\u70B9\u3092\u8FD4\
    \u3059\n// Verified: AOJ CGL_1_A: Projection\nPoint projection(Point a1, Point\
    \ a2, Point p) {\n    return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);\n\
    }\n\n// \u70B9 p \u306E\u76F4\u7DDA a \u3078\u306E\u53CD\u5C04\u70B9\u3092\u8FD4\
    \u3059\n// Verified: AOJ CGL_1_B: Reflection\nPoint reflection(Point a1, Point\
    \ a2, Point p) {\n    return 2.0 * projection(a1, a2, p) - p;\n}\n\n// \u70B9\
    \ a1, a2 \u3092\u901A\u308B\u76F4\u7DDA\u3068\u70B9 b \u3068\u306E\u8DDD\u96E2\
    \ndouble dist_lp(Point a1, Point a2, Point b) {\n    return abs( cross(a2-a1,\
    \ b-a1) ) / abs(a2-a1);\n}\n\n// \u76F4\u7DDA a1, a2 \u3068 \u76F4\u7DDA b1, b2\
    \ \u3068\u306E\u8DDD\u96E2\ndouble dist_ll(Point a1, Point a2, Point b1, Point\
    \ b2) {\n    return isec_ll(a1, a2, b1, b2) ? 0 : dist_lp(a1, a2, b1);\n}\n\n\
    // \u76F4\u7DDA a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\u8DDD\u96E2\ndouble\
    \ dist_ls(Point a1, Point a2, Point b1, Point b2) {\n    return isec_ls(a1, a2,\
    \ b1, b2) ? 0 : min( dist_lp(a1, a2, b1), dist_lp(a1, a2, b2) );\n}\n\n// \u70B9\
    \ a1, a2 \u3092\u7AEF\u70B9\u3068\u3059\u308B\u7DDA\u5206\u3068\u70B9 b \u3068\
    \u306E\u8DDD\u96E2\ndouble dist_sp(Point a1, Point a2, Point b) {\n    if( dot(a2-a1,\
    \ b-a1) < EPS ) return abs(b - a1);\n    if( dot(a1-a2, b-a2) < EPS ) return abs(b\
    \ - a2);\n    return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);\n}\n\n// \u7DDA\
    \u5206 a1, a2 \u3068 \u7DDA\u5206 b1, b2 \u3068\u306E\u8DDD\u96E2\n// Verified:\
    \ CGL_2_D: Distance\ndouble dist_ss(Point a1, Point a2, Point b1, Point b2) {\n\
    \    if(isec_ss(a1, a2, b1, b2)) return 0;\n    return min( min(dist_sp(a1, a2,\
    \ b1), dist_sp(a1, a2, b2)),\n                min(dist_sp(b1, b2, a1), dist_sp(b1,\
    \ b2, a2)) );\n}\n\n// \u76F4\u7DDA a1, a2 \u3068\u76F4\u7DDAb1, b2\u306E\u4EA4\
    \u70B9\u3092\u6C42\u3081\u308B\n// Verified: AOJ CGL_2_C.cpp\nPoint crossp_ll(Point\
    \ a1, Point a2, Point b1, Point b2) {\n    double d1 = cross(b2-b1, b1-a1);\n\
    \    double d2 = cross(b2-b1, a2-a1);\n    if( EQ(d1,0.0) && EQ(d2,0.0) ) return\
    \ a1; // same line\n    if( EQ(d2,0.0) ) assert(false); // precondition not satisfied\n\
    \    return a1 + d1 / d2 * (a2 - a1);\n}\n\n/***** \u5186\u306B\u95A2\u3059\u308B\
    \u554F\u984C *****/\n\n// \u76F4\u7DDA a1, a2 \u3068 \u5186 C \u3068\u306E\u8DDD\
    \u96E2\ndouble dist_lc(Point a1, Point a2, Circle c) {\n    return max(dist_lp(a1,\
    \ a2, c.first) - c.second, 0.0);\n}\n\n// \u7DDA\u5206 a1, a2 \u3068 \u5186 C\
    \ \u3068\u306E\u8DDD\u96E2\ndouble dist_sc(Point a1, Point a2, Circle c) {\n \
    \   double dSqr1 = norm(c.first - a1), dSqr2 = norm(c.first - a2);\n    double\
    \ r = c.second;\n    if((dSqr1 < r*r) ^ (dSqr2 < r*r)) return 0; //\u5186\u304C\
    \u7DDA\u5206\u3092\u5305\u542B\u3059\u308B\u3068\u304D\u8DDD\u96E20\u306A\u3089\
    \u3070\u3053\u3053\u3092OR\u306B\u5909\u3048\u308B\n    if((dSqr1 < r*r) & (dSqr2\
    \ < r*r)) return r - sqrt(max(dSqr1, dSqr2));\n    return max(dist_sp(a1, a2,\
    \ c.first) - r, 0.0);\n}\n\n// \u5186 x \u3068\u5186 y \u3068\u306E\u8DDD\u96E2\
    \ndouble dist_cc(Circle x, Circle y) {\n    Point a = x.first, b = y.first;\n\
    \    double ar = x.second, br = y.second;\n\n    double d = abs(a-b);\n    return\
    \ GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;\n}\n\n// \u76F4\u7DDA\
    \ a1, a2 \u3068\u5186 C \u3068\u306E\u4EA4\u70B9\n// Verified: AOJ CGL_7_D: Cross\
    \ Points of a Circle and a Line\nvector<Point> crossp_lc(Point a1, Point a2, Circle\
    \ c) {\n    vector<Point> ps;\n    double r = c.second;\n    Point ft = projection(a1,\
    \ a2, c.first);\n    if(!GEQ(r*r, norm(ft-c.first))) return ps;\n\n    Point dir\
    \ = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);\n    ps.push_back(ft\
    \ + dir);\n    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);\n    return\
    \ ps;\n}\n\n// \u5186 x \u3068\u5186 y \u306E\u4EA4\u70B9\n// Verified: AOJ CGL_7_E:\
    \ Cross Points of Circles\nvector<Point> crossp_cc(Circle x, Circle y) {\n   \
    \ vector<Point> ps;\n    Point a = x.first, b = y.first;\n    double ar = x.second,\
    \ br = y.second;\n\n    Point ab = b-a;\n    double d = abs(ab);\n    double crL\
    \ = (norm(ab) + ar * ar - br * br) / (2 * d);\n    if(EQ(d,0.0) || ar < abs(crL))\
    \ return ps;\n\n    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);\n  \
    \  Point cp = a + crL/d * ab;\n    ps.push_back(cp + abN);\n    if(!EQ(norm(abN),\
    \ 0.0)) ps.push_back(cp - abN);\n    return ps;\n}\n\n// \u70B9 p \u304B\u3089\
    \u5186 x \u3078\u306E\u63A5\u7DDA\u306E\u63A5\u70B9\n// Verified: AOJ CGL_7_F:\
    \ Tangent to a Circle\nvector<Point> tangentPoints(Point p, Circle x) {\n    vector<Point>\
    \ ps;\n    Point a = x.first; double ar = x.second;\n    double sin = ar / abs(p-a);\n\
    \    if(!LE(sin, 1.0)) return ps; // \u3053\u3053\u3067 NaN \u3082\u306F\u3058\
    \u304B\u308C\u308B\n\n    double t = M_PI_2 - asin(min(sin, 1.0));\n    ps.push_back(a\
    \ + (p-a) * polar(sin, t));\n    if(!EQ(sin, 1.0)) ps.push_back(a + (p-a)*polar(sin,\
    \ -t));\n    return ps;\n}\n\n// \u5186 x \u3068\u5186 y \u306E\u5171\u901A\u63A5\
    \u7DDA\u3002\u8FD4\u3055\u308C\u308B\u5404\u76F4\u7DDA\u306B\u542B\u307E\u308C\
    \u308B\u9802\u70B9\u306F\u5186\u3068\u306E\u63A5\u70B9\u3068\u306A\u308B\n// Verified:\
    \ AOJ CGL_7_G: Common Tangent\n// \u203B \u3084\u308B\u3053\u3068: -0.0000000\u306B\
    \u306A\u308B\u554F\u984C\u3092\u76F4\u3057\u305F\u3044\u30FB\u30FB\u30FB\nvector<Line>\
    \ tangentLines(Circle x, Circle y) {\n    Point a = x.first, b = y.first;\n  \
    \  double ar = x.second, br = y.second;\n    vector<Line> ls;\n    double d =\
    \ abs(b-a);\n\n    for(int i=0; i<2; i++) {\n        double sin = (ar - (1-i*2)*br)\
    \ / d;\n        if(!LE(sin*sin, 1.0)) break;\n\n        double cos = sqrt(max(1\
    \ - sin*sin, 0.0));\n        for(int j=0; j<2; j++) {\n            Point n = (b-a)\
    \ * Point(sin, (1-j*2)*cos) / d;\n            ls.push_back(Line(a + ar*n, b +\
    \ (1-i+2)*br*n));\n            if(cos < EPS) break; // \u91CD\u8907\u3059\u308B\
    \u63A5\u7DDA\u3092\u7121\u8996 (\u91CD\u8907\u3057\u3066\u3088\u3044\u306A\u3089\
    \u3053\u306E\u884C\u306F\u4E0D\u8981)\n        }\n    }\n    return ls;\n}\n\n\
    // \u5186 c1 \u3068\u5186 c2 \u306E\u4F4D\u7F6E\u95A2\u4FC2\n// Verified: AOJ\
    \ CGL_7_A: Intersection\nint intersectCC(Circle c1, Circle c2){\n    Point c1p\
    \ = c1.first, c2p = c2.first;\n    double c1r = c1.second, c2r = c2.second;\n\
    \    long double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;\n    if(r1 + r2 < d)\
    \            return  0; // \u96E2\u308C\u3066\u3044\u308B\n    if(abs(r1 + r2\
    \ - d) < EPS) return -2; // \u5916\u63A5\n    if(abs(d + r1 - r2) < EPS) return\
    \ +1; // c1 \u304C c2 \u306E\u4E2D\u3067\u5185\u63A5\n    if(abs(d + r2 - r1)\
    \ < EPS) return -1; // c2 \u304C c1 \u306E\u4E2D\u3067\u5185\u63A5\n    if(d +\
    \ r1 < r2)            return +3; // c1 \u304C c2 \u306E\u4E2D\n    if(d + r2 <\
    \ r1)            return -3; // c2 \u304C c1 \u306E\u4E2D\n    return 2; // 2\u3064\
    \u306E\u4EA4\u70B9\u3092\u6301\u3064\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5916\u5FC3\
    \u3002\u70B9 a, b, c \u306F\u540C\u4E00\u7DDA\u4E0A\u306B\u3042\u3063\u3066\u306F\
    \u306A\u3089\u306A\u3044\nPoint circumcenter(Point a, Point b, Point c) {\n  \
    \  a = (a-c) * 0.5;\n    b = (b-c) * 0.5;\n    return c + crossp_ll(a, a*Point(1,1),\
    \ b, b*Point(1,1));\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5185\u5FC3\nPoint InnerCenter(Point\
    \ a, Point b, Point c) {\n    double p = abs(b-c), q = abs(c-a), r = abs(a-b);\n\
    \    return (p*a + q*b + r*c) / (p + q + r);\n}\n\n// \u4E09\u89D2\u5F62\u306E\
    \u91CD\u5FC3\nPoint CenterOfGravity(Point a, Point b, Point c) {\n    return (a\
    \ + b + c) / 3.0;\n}\n\n// \u4E09\u89D2\u5F62\u306E\u5782\u5FC3\nPoint Orthocenter(Point\
    \ a, Point b, Point c) {\n    Point x = circumcenter(a, b, c);\n    Point ret\
    \ = (a-x) + (b-x) + (c-x);\n    return ret-x;\n}\n\n// \u70B9 a \u3068 \u70B9\
    \ b \u3092\u901A\u308A\u3001\u534A\u5F84\u304C r \u306E\u5186\u306E\u4E2D\u5FC3\
    \u3092\u8FD4\u3059\nvector<Point> circlesPointsRadius(Point a, Point b, double\
    \ r) {\n    vector<Point> cs;\n    Point abH = (b-a) * 0.5;\n    double d = abs(abH);\n\
    \n    if(d == 0 || d > r) return cs; // \u5FC5\u8981\u306A\u3089 !LE(d,r) \u3068\
    \u3057\u3066\u51861\u3064\u306B\u306A\u308B\u5074\u3078\u4E38\u3081\u308B\n  \
    \  double dN = sqrt(r*r - d*d);   // \u5FC5\u8981\u306A\u3089 max(r*r - d*d, 0)\
    \ \u3068\u3059\u308B\n    Point n = abH * Point(0,1) * (dN / d);\n    cs.push_back(a\
    \ + abH + n);\n    if(dN > 0) cs.push_back(a + abH - n);\n    return cs;\n}\n\n\
    // \u70B9 a \u3068\u70B9 b \u3092\u901A\u308A\u3001\u76F4\u7DDA l \u306B\u63A5\
    \u3059\u308B\u5186\u306E\u4E2D\u5FC3\nvector<Point> circlesPointsTangent(Point\
    \ a, Point b, Point l1, Point l2) {\n    Point n = (l2-l1) * Point(0,1);\n   \
    \ Point m = (b-a) * Point(0,0.5);\n    double rC = dot((a+b)*0.5-l1, n);\n   \
    \ double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);\n    double qb = -rC * dot(n,m);\n\
    \    double qc = norm(n)*norm(m) - rC*rC;\n    double qd = qb*qb - qa*qc;  //\
    \ qa*k^2 + 2*qb*k + qc = 0\n\n    vector<Point> cs;\n    if(qd < -EPS) return\
    \ cs;\n    if(EQ(qa, 0.0)) {\n        if(!EQ(qb,0.0)) cs.push_back((a+b)*0.5 -\
    \ m * (qc/qb/2));\n        return cs;\n    }\n    double t = -1*qb/qa;\n    cs.push_back(\
    \ (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0)) / qa ));\n    if(qd > EPS) cs.push_back(\
    \ (a+b)*0.5 + m * (t - sqrt(max(qd, 0.0)) / qa));\n    return cs;\n}\n\n// \u70B9\
    \u96C6\u5408\u3092\u542B\u3080\u6700\u5C0F\u306E\u5186\u306E\u4E2D\u5FC3\nPoint\
    \ minEnclosingCircle(const vector<Point> &ps) {\n    Point c;\n    double move\
    \ = 0.5;\n    for(int i=0; i<39; i++) { // 2^(-39-1) \\approx 0.9e-12\n      \
    \  for(int t=0; t<50; t++) {\n            double max = 0;\n            int k =\
    \ 0;\n            for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c))\
    \ {\n                max = norm(ps[j] - c);\n                k = j;\n        \
    \    }\n            c += (ps[k] - c) * move;\n        }\n        move /= 2;\n\
    \    }\n    return c;\n}\n\n// (\u57FA\u672C) \u9802\u70B9\u306E\u9806\u5E8F (sort\u3084\
    max_element\u306B\u5FC5\u8981)\nnamespace std {\n    bool operator<(const Point\
    \ a, const Point b) {\n        return a.real() != b.real() ? a.real() < b.real()\
    \ : a.imag() < b.imag();\n    }\n}\n\n// \u51F8\u5305\n// Verified: AOJ CGL_4_A:\
    \ Convex Hull\n// y\u5EA7\u6A19\u512A\u5148\u3067\u30BD\u30FC\u30C8(\u5FC5\u8981\
    \u304C\u3042\u308C\u3070)\nbool cmp_y(const Point &a, const Point& b) {\n    return\
    \ a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();\n}\n\nvector<Point>\
    \ convexHull(vector<Point> ps) {\n    int n = ps.size();\n    sort(ps.begin(),\
    \ ps.end(), cmp_y);\n\n    int k = 0;\n    vector<Point> convex(n*2);\n    for(int\
    \ i=0; i<n; i++) {\n        while (k >= 2 && ccw(convex[k-2], convex[k-1], ps[i])\
    \ == -1 ) k--;\n        convex[ k++ ] = ps[i];\n    }\n    for(int i=n-2, t=k;\
    \ i>=0; i--) {\n        while (k > t && ccw(convex[k-2], convex[k-1], ps[i]) ==\
    \ -1 ) k--;\n        convex[ k++ ] = ps[i];\n    }\n    convex.resize(k-1);\n\
    \    return convex;\n}\n\n/* \u3053\u308C\u306F\u30D0\u30B0\u308B\u306E\u3067\u4F7F\
    \u7528\u7981\u6B62\u3002\u5F8C\u3067\u76F4\u3057\u305F\u3044\nvector<Point> convexHull(vector<Point>\
    \ ps) { // \u5143\u306E\u70B9\u96C6\u5408\u304C\u30BD\u30FC\u30C8\u3055\u308C\u3066\
    \u3044\u3044\u306A\u3089 vector<Point> & \u306B\n    int n = ps.size(), k = 0;\n\
    \    sort(ps.begin(), ps.end());\n    vector<Point> ch(2 * n);\n    for(int i=0;\
    \ i<n; ch[k++] = ps[i++]) // lower-hull\n        while(k >= 2 && ccw(ch[k-2],\
    \ ch[k-1], ps[i]) <= 0) --k; // \u4F59\u8A08\u306A\u70B9\u3082\u542B\u3080\u306A\
    \u3089-1\u3068\u3059\u308B\n    for(int i=n-2, t=k+1; i>=0; ch[k++] = ps[i--])\
    \ //upper-hull\n        while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;\n\
    \    ch.resize(k-1);\n    return ch;\n}\n*/\n\n// \u51F8\u5224\u5B9A\u3002\u7E2E\
    \u9000\u3092\u8A8D\u3081\u306A\u3044\u306A\u3089 ccw \u306E\u5224\u5B9A\u90E8\u5206\
    \u3092 != 1 \u3068\u3059\u308B\n// Verified: CGL_3_B: Is-Convex\nbool isCcwConvex(const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    for(int i=0; i<n; i++) if(ccw(ps[i],\
    \ ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;\n    return true;\n}\n\n\
    // \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(n)\n// \u70B9\u304C\
    \u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u30892\u3001\
    \u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\nint inConvex(Point p, const vector<Point>\
    \ &ps) {\n    int n = ps.size();\n    int dir = ccw(ps[0], ps[1], p);\n    for(int\
    \ i=0; i<n; i++) {\n        int ccwc = ccw(ps[i], ps[(i+1) % n], p);\n       \
    \ if(!ccwc) return 2;\n        if(ccwc != dir) return 0;\n    }\n    return 1;\n\
    }\n\n// \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(log n)\n// \u70B9\
    \u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u3089\
    2\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\nint inCcwConvex(Point p, const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    Point g = (ps[0] + ps[n /\
    \ 3] + ps[n*2 / 3]) / 3.0;\n    if(g == p) return 1;\n    Point gp = p - g;\n\n\
    \    int l = 0, r = n;\n    while(l + 1 < r) {\n        int mid = (l + r) / 2;\n\
    \        Point gl = ps[l] - g;\n        Point gm = ps[mid] - g;\n        if(cross(gl,gm)\
    \ > 0) {\n            if(cross(gl,gp) >= 0 && cross(gm,gp) <= 0) r = mid;\n  \
    \          else l = mid;\n        }\n        else {\n            if(cross(gl,gp)\
    \ <= 0 && cross(gm,gp) >= 0) l = mid;\n            else r = mid;\n        }\n\
    \    }\n    r %= n;\n    double cr = cross(ps[l] - p, ps[r] - p);\n    return\
    \ EQ(cr, 0.0) ? 2 : cr < 0 ? 0 : 1;\n}\n\n// \u591A\u89D2\u5F62\u306E\u5185\u90E8\
    \u5224\u5B9A\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\
    \u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\n//\
    \ Verified: AOJ CGL_3_C: Polygon-Point Containment\nint inPolygon(Point p, const\
    \ vector<Point> &ps) {\n    int n = ps.size();\n    bool in = false;\n    for(int\
    \ i=0; i<n; i++) {\n        Point a = ps[i] - p;\n        Point b = ps[(i+1) %\
    \ n] - p;\n        if(EQ(cross(a,b), 0.0) && LE(dot(a,b), 0.0)) return 2;\n  \
    \      if(a.imag() > b.imag()) swap(a,b);\n        if((a.imag() * b.imag() < 0\
    \ || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0.0)) in\
    \ = !in;\n    }\n    return in;\n}\n\n// \u51F8\u591A\u89D2\u5F62\u30AF\u30EA\u30C3\
    \u30D4\u30F3\u30B0\n// Verified: AOJ CGL_4_C: Convex Cut\nvector<Point> convexCut(Point\
    \ a1, Point a2, const vector<Point> &ps) {\n    int n = ps.size();\n    vector<Point>\
    \ ret;\n    for(int i=0; i<n; i++) {\n        int ccwc = ccw(a1, a2, ps[i]);\n\
    \        if(ccwc != -1) ret.push_back(ps[i]);\n        int ccwn = ccw(a1, a2,\
    \ ps[(i + 1) % n]);\n        if(ccwc * ccwn == -1) ret.push_back(crossp_ll(a1,\
    \ a2, ps[i], ps[(i + 1) % n]));\n    }\n    return ret;\n}\n\n// \u51F8\u591A\u89D2\
    \u5F62\u306E\u76F4\u5F84 (\u6700\u9060\u70B9\u5BFE)\n// Verified: AOJ CGL_4_B:\
    \ Diameter of a Convex Polygon\npair<int, int> convexDiameter(const vector<Point>\
    \ &ps) {\n    int n = ps.size();\n    int i = min_element(ps.begin(), ps.end())\
    \ - ps.begin();\n    int j = max_element(ps.begin(), ps.end()) - ps.begin();\n\
    \    int maxI, maxJ;\n    double maxD = 0;\n    for(int _=0; _<2*n; _++) {\n \
    \       if(maxD < norm(ps[i] - ps[j])) {\n            maxD = norm(ps[i] - ps[j]);\n\
    \            maxI = i;\n            maxJ = j;\n        }\n        if(cross(ps[i]\
    \ - ps[(i+1) % n], ps[(j+1) % n] - ps[j]) <= 0) j = (j+1) % n;\n        else i\
    \ = (i+1) % n;\n    }\n    return make_pair(maxI, maxJ);\n}\n\n// \u591A\u89D2\
    \u5F62\u306E\u7B26\u53F7\u4ED8\u9762\u7A4D\n// Verified: AOJ CGL_3_A: Area\ndouble\
    \ area(const vector<Point> &ps) {\n    double a = 0;\n    for(size_t i=0; i<ps.size();\
    \ i++) a += cross(ps[i], ps[(i+1) % ps.size()]);\n    return a / 2;\n}\n\n// \u591A\
    \u89D2\u5F62\u306E\u7B26\u53F7\u306A\u3057\u9762\u7A4D\ndouble area_n(const vector<Point>\
    \ &v) {\n    double ans = 0;\n    double x, y, z;\n    Point init = v[0];\n  \
    \  for(size_t i=2; i<v.size(); i++) {\n        x = sqrt(norm(v[i] - init));\n\
    \        y = sqrt(norm(v[i-1] - init));\n        z = sqrt(norm(v[i] - v[i-1]));\n\
    \n        double s = (x + y + z) / 2;\n        ans += sqrt(s * (s-x) * (s-y) *\
    \ (s-z));\n    }\n    return ans;\n}\n\n// \u591A\u89D2\u5F62\u306E\u5E7E\u4F55\
    \u5B66\u7684\u91CD\u5FC3\nPoint centroid(const vector<Point> &ps) {\n    int n\
    \ = ps.size();\n    double aSum = 0;\n    Point c;\n    for(int i=0; i<n; i++)\
    \ {\n        double a = cross(ps[i], ps[(i+1) % n]);\n        aSum += a;\n   \
    \     c += (ps[i] + ps[(i+1) % n]) * a;\n    }\n    return 1 / aSum / 3 * c;\n\
    }\n\n// \u30DC\u30ED\u30CE\u30A4\u9818\u57DF\n/*\nvector<Point> voronoiCell(Point\
    \ p, const vector<Point> &ps, const vector<Point> &outer) {\n    vector<Point>\
    \ cl = outer;\n    for(size_t i=0; i<ps.size(); i++) {\n        if(EQ(norm(ps[i]\
    \ - p), 0.0)) continue;\n        Point h = (p + ps[i]) * 0.5;\n        cl = convexCut(cl,\
    \ h, h + (ps[i] - h) * Point(0,1));\n    }\n    return cl;\n}\n*/\n\n// \u9802\
    \u70B9\u3092\u56DE\u8EE2\u3055\u305B\u308B\u7CFB\n\n// \u5EA6\u6570\u6CD5 \u2192\
    \ \u5F27\u5EA6\u6CD5\ndouble deg2rad(double x) {return x * M_PI / 180.0;}\n\n\
    // \u70B9 a \u3092\u4E2D\u5FC3\u3068\u3057\u3066\u3001\u70B9 b \u3092 z \u5EA6\
    \u56DE\u8EE2\u3055\u305B\u305F\u3068\u304D\u306E\u4F4D\u7F6E\nPoint rotatePoint(Point\
    \ a, Point b, double z) {\n    // \u5EA6\u6570\u6CD5\u306E\u5834\u5408\u306F\u5909\
    \u63DB\n    z = deg2rad(z);\n\n    b -= a;\n    double rx = b.real() * cos(z)\
    \ - b.imag() * sin(z);\n    double ry = b.real() * sin(z) + b.imag() * cos(z);\n\
    \    Point ret(rx, ry); ret += a;\n    return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry_2D.cpp
  requiredBy: []
  timestamp: '2019-11-24 03:10:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/CGL_1_C/geometry.test.cpp
  - verifying_test/AOJ/CGL_7_A/geometry.test.cpp
  - verifying_test/AOJ/CGL_4_A/geometry.test.cpp
  - verifying_test/AOJ/CGL_3_C/geometry.test.cpp
  - verifying_test/AOJ/CGL_2_B/geometry.test.cpp
  - verifying_test/AOJ/CGL_2_C/geometry.test.cpp
  - verifying_test/AOJ/CGL_2_A/geometry.test.cpp
  - verifying_test/AOJ/CGL_7_F/geometry.test.cpp
  - verifying_test/AOJ/CGL_7_D/geometry.test.cpp
  - verifying_test/AOJ/CGL_7_E/geometry.test.cpp
  - verifying_test/AOJ/CGL_3_A/geometry.test.cpp
  - verifying_test/AOJ/CGL_7_G/geometry.test.cpp
  - verifying_test/AOJ/CGL_2_D/geometry.test.cpp
  - verifying_test/AOJ/CGL_4_C/geometry.test.cpp
  - verifying_test/AOJ/CGL_1_A/geometry.test.cpp
  - verifying_test/AOJ/CGL_1_B/geometry.test.cpp
  - verifying_test/AOJ/CGL_4_B/geometry.test.cpp
documentation_of: geometry/geometry_2D.cpp
layout: document
redirect_from:
- /library/geometry/geometry_2D.cpp
- /library/geometry/geometry_2D.cpp.html
title: geometry/geometry_2D.cpp
---
