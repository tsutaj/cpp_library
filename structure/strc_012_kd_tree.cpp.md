---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_012_kd_tree.cpp\"\n// \u9818\u57DF\u63A2\u7D22\
    \ (kD \u6728\u30FB2 \u6B21\u5143\u30D0\u30FC\u30B8\u30E7\u30F3)\n// Verified:\
    \ AOJ DSL_2_C: Range Search (kD Tree)\nstruct Node {\n    int loc, l, r;\n};\n\
    \nstruct Point {\n    int id, x, y;\n};\n\nNode T[500010];\nPoint P[500010];\n\
    int np = 0, NIL = -1;\n\n// [l, r) \u306E\u7BC4\u56F2\u306B\u3042\u308B\u70B9\u306B\
    \u3064\u3044\u3066\u69CB\u7BC9\u3002\u305D\u306E\u7BC4\u56F2\u306B\u304A\u3051\
    \u308B\u6839\u3092\u8FD4\u3059\nint make(int l, int r, int depth=0) {\n    if(l\
    \ >= r) return NIL;\n    int mid = (l + r) / 2, t = np++;\n    if(depth % 2 ==\
    \ 0) {\n        sort(P+l, P+r, [](const Point &a, const Point &b){return a.x <\
    \ b.x;});\n    }\n    else {\n        sort(P+l, P+r, [](const Point &a, const\
    \ Point &b){return a.y < b.y;});\n    }\n    T[t].loc = mid;\n    T[t].l = make(l,\
    \ mid,   depth+1);\n    T[t].r = make(mid+1, r, depth+1);\n    return t;\n}\n\n\
    // \u5DE6\u4E0A (sx, ty)\u3001\u53F3\u4E0B (tx, sy) \u306E\u9577\u65B9\u5F62\u9818\
    \u57DF\u306B\u3042\u308B\u70B9\u3092\u5217\u6319\n// v \u306F kD-tree \u306B\u304A\
    \u3051\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n// find(root, sx, tx, sy, ty,\
    \ ans) \u306E\u3088\u3046\u306B\u4F7F\u304A\u3046\nvoid find(int v, int sx, int\
    \ tx, int sy, int ty, vector<int> &ans, int depth=0) {\n    int x = P[T[v].loc].x,\
    \ y = P[T[v].loc].y;\n    if(sx <= x && x <= tx && sy <= y && y <= ty) {\n   \
    \     // ans.push_back(Point{x, y});\n        ans.push_back(P[T[v].loc].id);\n\
    \    }\n\n    if(depth % 2 == 0) {\n        if(T[v].l != NIL && sx <= x) find(T[v].l,\
    \ sx, tx, sy, ty, ans, depth+1);\n        if(T[v].r != NIL && x <= tx) find(T[v].r,\
    \ sx, tx, sy, ty, ans, depth+1);\n    }\n    else {\n        if(T[v].l != NIL\
    \ && sy <= y) find(T[v].l, sx, tx, sy, ty, ans, depth+1);\n        if(T[v].r !=\
    \ NIL && y <= ty) find(T[v].r, sx, tx, sy, ty, ans, depth+1);\n    }\n}\n\n//\
    \ kD-tree end\n"
  code: "// \u9818\u57DF\u63A2\u7D22 (kD \u6728\u30FB2 \u6B21\u5143\u30D0\u30FC\u30B8\
    \u30E7\u30F3)\n// Verified: AOJ DSL_2_C: Range Search (kD Tree)\nstruct Node {\n\
    \    int loc, l, r;\n};\n\nstruct Point {\n    int id, x, y;\n};\n\nNode T[500010];\n\
    Point P[500010];\nint np = 0, NIL = -1;\n\n// [l, r) \u306E\u7BC4\u56F2\u306B\u3042\
    \u308B\u70B9\u306B\u3064\u3044\u3066\u69CB\u7BC9\u3002\u305D\u306E\u7BC4\u56F2\
    \u306B\u304A\u3051\u308B\u6839\u3092\u8FD4\u3059\nint make(int l, int r, int depth=0)\
    \ {\n    if(l >= r) return NIL;\n    int mid = (l + r) / 2, t = np++;\n    if(depth\
    \ % 2 == 0) {\n        sort(P+l, P+r, [](const Point &a, const Point &b){return\
    \ a.x < b.x;});\n    }\n    else {\n        sort(P+l, P+r, [](const Point &a,\
    \ const Point &b){return a.y < b.y;});\n    }\n    T[t].loc = mid;\n    T[t].l\
    \ = make(l, mid,   depth+1);\n    T[t].r = make(mid+1, r, depth+1);\n    return\
    \ t;\n}\n\n// \u5DE6\u4E0A (sx, ty)\u3001\u53F3\u4E0B (tx, sy) \u306E\u9577\u65B9\
    \u5F62\u9818\u57DF\u306B\u3042\u308B\u70B9\u3092\u5217\u6319\n// v \u306F kD-tree\
    \ \u306B\u304A\u3051\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n// find(root,\
    \ sx, tx, sy, ty, ans) \u306E\u3088\u3046\u306B\u4F7F\u304A\u3046\nvoid find(int\
    \ v, int sx, int tx, int sy, int ty, vector<int> &ans, int depth=0) {\n    int\
    \ x = P[T[v].loc].x, y = P[T[v].loc].y;\n    if(sx <= x && x <= tx && sy <= y\
    \ && y <= ty) {\n        // ans.push_back(Point{x, y});\n        ans.push_back(P[T[v].loc].id);\n\
    \    }\n\n    if(depth % 2 == 0) {\n        if(T[v].l != NIL && sx <= x) find(T[v].l,\
    \ sx, tx, sy, ty, ans, depth+1);\n        if(T[v].r != NIL && x <= tx) find(T[v].r,\
    \ sx, tx, sy, ty, ans, depth+1);\n    }\n    else {\n        if(T[v].l != NIL\
    \ && sy <= y) find(T[v].l, sx, tx, sy, ty, ans, depth+1);\n        if(T[v].r !=\
    \ NIL && y <= ty) find(T[v].r, sx, tx, sy, ty, ans, depth+1);\n    }\n}\n\n//\
    \ kD-tree end\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_012_kd_tree.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_012_kd_tree.cpp
layout: document
redirect_from:
- /library/structure/strc_012_kd_tree.cpp
- /library/structure/strc_012_kd_tree.cpp.html
title: structure/strc_012_kd_tree.cpp
---
