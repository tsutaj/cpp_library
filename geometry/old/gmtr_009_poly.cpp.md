---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"geometry/old/gmtr_009_poly.cpp\"\n// (\u57FA\u672C) \u9802\
    \u70B9\u306E\u9806\u5E8F (sort\u3084max_element\u306B\u5FC5\u8981)\r\nnamespace\
    \ std {\r\n    bool operator<(const Point a, const Point b) {\r\n        return\
    \ a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();\r\n    }\r\
    \n}\r\n\r\n// \u51F8\u5305\r\n// Verified: AOJ CGL_4_A: Convex Hull\r\n// y\u5EA7\
    \u6A19\u512A\u5148\u3067\u30BD\u30FC\u30C8(\u5FC5\u8981\u304C\u3042\u308C\u3070\
    )\r\nbool cmp_y(const Point &a, const Point& b) {\r\n    return a.imag() != b.imag()\
    \ ? a.imag() < b.imag() : a.real() < b.real();\r\n}\r\n\r\nvector<Point> convexHull(vector<Point>\
    \ ps) {\r\n    int n = ps.size();\r\n    // sort(ps.begin(),ps.end(), cmp_y);\r\
    \n    sort(ps.begin(),ps.end());\r\n    int k = 0;\r\n    vector<Point> convex(n*2);\r\
    \n    for(int i=0; i<n; i++) {\r\n        while (k >= 2 && ccw(convex[k-2], convex[k-1],\
    \ ps[i]) == -1 ) k--;\r\n        convex[ k++ ] = ps[i];\r\n    }\r\n    for(int\
    \ i=n-2, t=k; i>=0; i--) {\r\n        while (k > t && ccw(convex[k-2], convex[k-1],\
    \ ps[i]) == -1 ) k--;\r\n        convex[ k++ ] = ps[i];\r\n    }\r\n    convex.resize(k-1);\r\
    \n    return convex;\r\n}\r\n\r\n/* \u3053\u308C\u306F\u30D0\u30B0\u308B\u306E\
    \u3067\u4F7F\u7528\u7981\u6B62\u3002\u5F8C\u3067\u76F4\u3057\u305F\u3044\r\nvector<Point>\
    \ convexHull(vector<Point> ps) { // \u5143\u306E\u70B9\u96C6\u5408\u304C\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u3044\u3044\u306A\u3089 vector<Point> & \u306B\r\
    \n    int n = ps.size(), k = 0;\r\n    sort(ps.begin(), ps.end());\r\n    vector<Point>\
    \ ch(2 * n);\r\n    for(int i=0; i<n; ch[k++] = ps[i++]) // lower-hull\r\n   \
    \     while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k; // \u4F59\u8A08\u306A\
    \u70B9\u3082\u542B\u3080\u306A\u3089-1\u3068\u3059\u308B\r\n    for(int i=n-2,\
    \ t=k+1; i>=0; ch[k++] = ps[i--]) //upper-hull\r\n        while(k >= t && ccw(ch[k-2],\
    \ ch[k-1], ps[i]) <= 0) --k;\r\n    ch.resize(k-1);\r\n    return ch;\r\n}\r\n\
    */\r\n\r\n// \u51F8\u5224\u5B9A\u3002\u7E2E\u9000\u3092\u8A8D\u3081\u306A\u3044\
    \u306A\u3089 ccw \u306E\u5224\u5B9A\u90E8\u5206\u3092 != 1 \u3068\u3059\u308B\r\
    \n// Verified: CGL_3_B: Is-Convex\r\nbool isCcwConvex(const vector<Point> &ps)\
    \ {\r\n    int n = ps.size();\r\n    for(int i=0; i<n; i++) if(ccw(ps[i], ps[(i+1)\
    \ % n], ps[(i+2) % n]) == -1) return false;\r\n    return true;\r\n}\r\n\r\n//\
    \ \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(n)\r\n// \u70B9\u304C\
    \u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u30892\u3001\
    \u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\r\nint inConvex(Point p, const vector<Point>\
    \ &ps) {\r\n    int n = ps.size();\r\n    int dir = ccw(ps[0], ps[1], p);\r\n\
    \    for(int i=0; i<n; i++) {\r\n        int ccwc = ccw(ps[i], ps[(i+1) % n],\
    \ p);\r\n        if(!ccwc) return 2;\r\n        if(ccwc != dir) return 0;\r\n\
    \    }\r\n    return 1;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\
    \u5224\u5B9A O(log n)\r\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\
    \u5883\u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\
    \r\nint inCcwConvex(Point p, const vector<Point> &ps) {\r\n    int n = ps.size();\r\
    \n    Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;\r\n    if(g == p) return\
    \ 1;\r\n    Point gp = p - g;\r\n\r\n    int l = 0, r = n;\r\n    while(l + 1\
    \ < r) {\r\n        int mid = (l + r) / 2;\r\n        Point gl = ps[l] - g;\r\n\
    \        Point gm = ps[mid] - g;\r\n        if(cross(gl,gm) > 0) {\r\n       \
    \     if(cross(gl,gp) >= 0 && cross(gm,gp) <= 0) r = mid;\r\n            else\
    \ l = mid;\r\n        }\r\n        else {\r\n            if(cross(gl,gp) <= 0\
    \ && cross(gm,gp) >= 0) l = mid;\r\n            else r = mid;\r\n        }\r\n\
    \    }\r\n    r %= n;\r\n    double cr = cross(ps[l] - p, ps[r] - p);\r\n    return\
    \ EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u5185\
    \u90E8\u5224\u5B9A\r\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\
    \u5883\u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\
    \r\n// Verified: AOJ CGL_3_C: Polygon-Point Containment\r\nint inPolygon(Point\
    \ p, const vector<Point> &ps) {\r\n    int n = ps.size();\r\n    bool in = false;\r\
    \n    for(int i=0; i<n; i++) {\r\n        Point a = ps[i] - p;\r\n        Point\
    \ b = ps[(i+1) % n] - p;\r\n        if(EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return\
    \ 2;\r\n        if(a.imag() > b.imag()) swap(a,b);\r\n        if((a.imag() * b.imag()\
    \ < 0 || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0))\
    \ in = !in;\r\n    }\r\n    return in;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\
    \u30AF\u30EA\u30C3\u30D4\u30F3\u30B0\r\n// Verified: AOJ CGL_4_C: Convex Cut\r\
    \nvector<Point> convexCut(Point a1, Point a2, const vector<Point> &ps) {\r\n \
    \   int n = ps.size();\r\n    vector<Point> ret;\r\n    for(int i=0; i<n; i++)\
    \ {\r\n        int ccwc = ccw(a1, a2, ps[i]);\r\n        if(ccwc != -1) ret.push_back(ps[i]);\r\
    \n        int ccwn = ccw(a1, a2, ps[(i + 1) % n]);\r\n        if(ccwc * ccwn ==\
    \ -1) ret.push_back(crossp_ll(a1, a2, ps[i], ps[(i + 1) % n]));\r\n    }\r\n \
    \   return ret;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84 (\u6700\
    \u9060\u70B9\u5BFE)\r\n// Verified: AOJ CGL_4_B: Diameter of a Convex Polygon\r\
    \npair<int, int> convexDiameter(const vector<Point> &ps) {\r\n    int n = ps.size();\r\
    \n    int i = min_element(ps.begin(), ps.end()) - ps.begin();\r\n    int j = max_element(ps.begin(),\
    \ ps.end()) - ps.begin();\r\n    int maxI, maxJ;\r\n    double maxD = 0;\r\n \
    \   for(int _=0; _<2*n; _++) {\r\n        if(maxD < norm(ps[i] - ps[j])) {\r\n\
    \            maxD = norm(ps[i] - ps[j]);\r\n            maxI = i;\r\n        \
    \    maxJ = j;\r\n        }\r\n        if(cross(ps[i] - ps[(i+1) % n], ps[(j+1)\
    \ % n] - ps[j]) <= 0) j = (j+1) % n;\r\n        else i = (i+1) % n;\r\n    }\r\
    \n    return make_pair(maxI, maxJ);\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u7B26\
    \u53F7\u4ED8\u9762\u7A4D\r\n// Verified: AOJ CGL_3_A: Area\r\ndouble area(const\
    \ vector<Point> &ps) {\r\n    double a = 0;\r\n    for(size_t i=0; i<ps.size();\
    \ i++) a += cross(ps[i], ps[(i+1) % ps.size()]);\r\n    return a / 2;\r\n}\r\n\
    \r\n// \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u306A\u3057\u9762\u7A4D\r\ndouble\
    \ area_n(const vector<Point> &v) {\r\n    double ans = 0;\r\n    double x, y,\
    \ z;\r\n    Point init = v[0];\r\n    for(size_t i=2; i<v.size(); i++) {\r\n \
    \       x = sqrt(norm(v[i] - init));\r\n        y = sqrt(norm(v[i-1] - init));\r\
    \n        z = sqrt(norm(v[i] - v[i-1]));\r\n\r\n        double s = (x + y + z)\
    \ / 2;\r\n        ans += sqrt(s * (s-x) * (s-y) * (s-z));\r\n    }\r\n    return\
    \ ans;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u5E7E\u4F55\u5B66\u7684\u91CD\u5FC3\
    \r\nPoint centroid(const vector<Point> &ps) {\r\n    int n = ps.size();\r\n  \
    \  double aSum = 0;\r\n    Point c;\r\n    for(int i=0; i<n; i++) {\r\n      \
    \  double a = cross(ps[i], ps[(i+1) % n]);\r\n        aSum += a;\r\n        c\
    \ += (ps[i] + ps[(i+1) % n]) * a;\r\n    }\r\n    return 1 / aSum / 3 * c;\r\n\
    }\r\n\r\n// \u30DC\u30ED\u30CE\u30A4\u9818\u57DF\r\nvector<Point> voronoiCell(Point\
    \ p, const vector<Point> &ps, const vector<Point> &outer) {\r\n    vector<Point>\
    \ cl = outer;\r\n    for(size_t i=0; i<ps.size(); i++) {\r\n        if(EQ(norm(ps[i]\
    \ - p), 0)) continue;\r\n        Point h = (p + ps[i]) * 0.5;\r\n        cl =\
    \ convexCut(cl, h, h + (ps[i] - h) * Point(0,1));\r\n    }\r\n    return cl;\r\
    \n}\r\n"
  code: "// (\u57FA\u672C) \u9802\u70B9\u306E\u9806\u5E8F (sort\u3084max_element\u306B\
    \u5FC5\u8981)\r\nnamespace std {\r\n    bool operator<(const Point a, const Point\
    \ b) {\r\n        return a.real() != b.real() ? a.real() < b.real() : a.imag()\
    \ < b.imag();\r\n    }\r\n}\r\n\r\n// \u51F8\u5305\r\n// Verified: AOJ CGL_4_A:\
    \ Convex Hull\r\n// y\u5EA7\u6A19\u512A\u5148\u3067\u30BD\u30FC\u30C8(\u5FC5\u8981\
    \u304C\u3042\u308C\u3070)\r\nbool cmp_y(const Point &a, const Point& b) {\r\n\
    \    return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();\r\
    \n}\r\n\r\nvector<Point> convexHull(vector<Point> ps) {\r\n    int n = ps.size();\r\
    \n    // sort(ps.begin(),ps.end(), cmp_y);\r\n    sort(ps.begin(),ps.end());\r\
    \n    int k = 0;\r\n    vector<Point> convex(n*2);\r\n    for(int i=0; i<n; i++)\
    \ {\r\n        while (k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;\r\
    \n        convex[ k++ ] = ps[i];\r\n    }\r\n    for(int i=n-2, t=k; i>=0; i--)\
    \ {\r\n        while (k > t && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;\r\
    \n        convex[ k++ ] = ps[i];\r\n    }\r\n    convex.resize(k-1);\r\n    return\
    \ convex;\r\n}\r\n\r\n/* \u3053\u308C\u306F\u30D0\u30B0\u308B\u306E\u3067\u4F7F\
    \u7528\u7981\u6B62\u3002\u5F8C\u3067\u76F4\u3057\u305F\u3044\r\nvector<Point>\
    \ convexHull(vector<Point> ps) { // \u5143\u306E\u70B9\u96C6\u5408\u304C\u30BD\
    \u30FC\u30C8\u3055\u308C\u3066\u3044\u3044\u306A\u3089 vector<Point> & \u306B\r\
    \n    int n = ps.size(), k = 0;\r\n    sort(ps.begin(), ps.end());\r\n    vector<Point>\
    \ ch(2 * n);\r\n    for(int i=0; i<n; ch[k++] = ps[i++]) // lower-hull\r\n   \
    \     while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k; // \u4F59\u8A08\u306A\
    \u70B9\u3082\u542B\u3080\u306A\u3089-1\u3068\u3059\u308B\r\n    for(int i=n-2,\
    \ t=k+1; i>=0; ch[k++] = ps[i--]) //upper-hull\r\n        while(k >= t && ccw(ch[k-2],\
    \ ch[k-1], ps[i]) <= 0) --k;\r\n    ch.resize(k-1);\r\n    return ch;\r\n}\r\n\
    */\r\n\r\n// \u51F8\u5224\u5B9A\u3002\u7E2E\u9000\u3092\u8A8D\u3081\u306A\u3044\
    \u306A\u3089 ccw \u306E\u5224\u5B9A\u90E8\u5206\u3092 != 1 \u3068\u3059\u308B\r\
    \n// Verified: CGL_3_B: Is-Convex\r\nbool isCcwConvex(const vector<Point> &ps)\
    \ {\r\n    int n = ps.size();\r\n    for(int i=0; i<n; i++) if(ccw(ps[i], ps[(i+1)\
    \ % n], ps[(i+2) % n]) == -1) return false;\r\n    return true;\r\n}\r\n\r\n//\
    \ \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\u5224\u5B9A O(n)\r\n// \u70B9\u304C\
    \u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\u5883\u754C\u4E0A\u306A\u30892\u3001\
    \u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\r\nint inConvex(Point p, const vector<Point>\
    \ &ps) {\r\n    int n = ps.size();\r\n    int dir = ccw(ps[0], ps[1], p);\r\n\
    \    for(int i=0; i<n; i++) {\r\n        int ccwc = ccw(ps[i], ps[(i+1) % n],\
    \ p);\r\n        if(!ccwc) return 2;\r\n        if(ccwc != dir) return 0;\r\n\
    \    }\r\n    return 1;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\u306E\u5185\u90E8\
    \u5224\u5B9A O(log n)\r\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\
    \u5883\u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\
    \r\nint inCcwConvex(Point p, const vector<Point> &ps) {\r\n    int n = ps.size();\r\
    \n    Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;\r\n    if(g == p) return\
    \ 1;\r\n    Point gp = p - g;\r\n\r\n    int l = 0, r = n;\r\n    while(l + 1\
    \ < r) {\r\n        int mid = (l + r) / 2;\r\n        Point gl = ps[l] - g;\r\n\
    \        Point gm = ps[mid] - g;\r\n        if(cross(gl,gm) > 0) {\r\n       \
    \     if(cross(gl,gp) >= 0 && cross(gm,gp) <= 0) r = mid;\r\n            else\
    \ l = mid;\r\n        }\r\n        else {\r\n            if(cross(gl,gp) <= 0\
    \ && cross(gm,gp) >= 0) l = mid;\r\n            else r = mid;\r\n        }\r\n\
    \    }\r\n    r %= n;\r\n    double cr = cross(ps[l] - p, ps[r] - p);\r\n    return\
    \ EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u5185\
    \u90E8\u5224\u5B9A\r\n// \u70B9\u304C\u9818\u57DF\u5185\u90E8\u306A\u30891\u3001\
    \u5883\u754C\u4E0A\u306A\u30892\u3001\u5916\u90E8\u306A\u30890\u3092\u8FD4\u3059\
    \r\n// Verified: AOJ CGL_3_C: Polygon-Point Containment\r\nint inPolygon(Point\
    \ p, const vector<Point> &ps) {\r\n    int n = ps.size();\r\n    bool in = false;\r\
    \n    for(int i=0; i<n; i++) {\r\n        Point a = ps[i] - p;\r\n        Point\
    \ b = ps[(i+1) % n] - p;\r\n        if(EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return\
    \ 2;\r\n        if(a.imag() > b.imag()) swap(a,b);\r\n        if((a.imag() * b.imag()\
    \ < 0 || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0))\
    \ in = !in;\r\n    }\r\n    return in;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\
    \u30AF\u30EA\u30C3\u30D4\u30F3\u30B0\r\n// Verified: AOJ CGL_4_C: Convex Cut\r\
    \nvector<Point> convexCut(Point a1, Point a2, const vector<Point> &ps) {\r\n \
    \   int n = ps.size();\r\n    vector<Point> ret;\r\n    for(int i=0; i<n; i++)\
    \ {\r\n        int ccwc = ccw(a1, a2, ps[i]);\r\n        if(ccwc != -1) ret.push_back(ps[i]);\r\
    \n        int ccwn = ccw(a1, a2, ps[(i + 1) % n]);\r\n        if(ccwc * ccwn ==\
    \ -1) ret.push_back(crossp_ll(a1, a2, ps[i], ps[(i + 1) % n]));\r\n    }\r\n \
    \   return ret;\r\n}\r\n\r\n// \u51F8\u591A\u89D2\u5F62\u306E\u76F4\u5F84 (\u6700\
    \u9060\u70B9\u5BFE)\r\n// Verified: AOJ CGL_4_B: Diameter of a Convex Polygon\r\
    \npair<int, int> convexDiameter(const vector<Point> &ps) {\r\n    int n = ps.size();\r\
    \n    int i = min_element(ps.begin(), ps.end()) - ps.begin();\r\n    int j = max_element(ps.begin(),\
    \ ps.end()) - ps.begin();\r\n    int maxI, maxJ;\r\n    double maxD = 0;\r\n \
    \   for(int _=0; _<2*n; _++) {\r\n        if(maxD < norm(ps[i] - ps[j])) {\r\n\
    \            maxD = norm(ps[i] - ps[j]);\r\n            maxI = i;\r\n        \
    \    maxJ = j;\r\n        }\r\n        if(cross(ps[i] - ps[(i+1) % n], ps[(j+1)\
    \ % n] - ps[j]) <= 0) j = (j+1) % n;\r\n        else i = (i+1) % n;\r\n    }\r\
    \n    return make_pair(maxI, maxJ);\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u7B26\
    \u53F7\u4ED8\u9762\u7A4D\r\n// Verified: AOJ CGL_3_A: Area\r\ndouble area(const\
    \ vector<Point> &ps) {\r\n    double a = 0;\r\n    for(size_t i=0; i<ps.size();\
    \ i++) a += cross(ps[i], ps[(i+1) % ps.size()]);\r\n    return a / 2;\r\n}\r\n\
    \r\n// \u591A\u89D2\u5F62\u306E\u7B26\u53F7\u306A\u3057\u9762\u7A4D\r\ndouble\
    \ area_n(const vector<Point> &v) {\r\n    double ans = 0;\r\n    double x, y,\
    \ z;\r\n    Point init = v[0];\r\n    for(size_t i=2; i<v.size(); i++) {\r\n \
    \       x = sqrt(norm(v[i] - init));\r\n        y = sqrt(norm(v[i-1] - init));\r\
    \n        z = sqrt(norm(v[i] - v[i-1]));\r\n\r\n        double s = (x + y + z)\
    \ / 2;\r\n        ans += sqrt(s * (s-x) * (s-y) * (s-z));\r\n    }\r\n    return\
    \ ans;\r\n}\r\n\r\n// \u591A\u89D2\u5F62\u306E\u5E7E\u4F55\u5B66\u7684\u91CD\u5FC3\
    \r\nPoint centroid(const vector<Point> &ps) {\r\n    int n = ps.size();\r\n  \
    \  double aSum = 0;\r\n    Point c;\r\n    for(int i=0; i<n; i++) {\r\n      \
    \  double a = cross(ps[i], ps[(i+1) % n]);\r\n        aSum += a;\r\n        c\
    \ += (ps[i] + ps[(i+1) % n]) * a;\r\n    }\r\n    return 1 / aSum / 3 * c;\r\n\
    }\r\n\r\n// \u30DC\u30ED\u30CE\u30A4\u9818\u57DF\r\nvector<Point> voronoiCell(Point\
    \ p, const vector<Point> &ps, const vector<Point> &outer) {\r\n    vector<Point>\
    \ cl = outer;\r\n    for(size_t i=0; i<ps.size(); i++) {\r\n        if(EQ(norm(ps[i]\
    \ - p), 0)) continue;\r\n        Point h = (p + ps[i]) * 0.5;\r\n        cl =\
    \ convexCut(cl, h, h + (ps[i] - h) * Point(0,1));\r\n    }\r\n    return cl;\r\
    \n}\r\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/old/gmtr_009_poly.cpp
  requiredBy: []
  timestamp: '2019-11-24 02:02:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/old/gmtr_009_poly.cpp
layout: document
redirect_from:
- /library/geometry/old/gmtr_009_poly.cpp
- /library/geometry/old/gmtr_009_poly.cpp.html
title: geometry/old/gmtr_009_poly.cpp
---
