---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/yosupo/SegmentAddGetMin.test.cpp
    title: verifying_test/yosupo/SegmentAddGetMin.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Convex Hull Trick (Li-Chao Tree)
    links: []
  bundledCode: "#line 1 \"math/math_010_convexhulltrick.cpp\"\n// @brief Convex Hull\
    \ Trick (Li-Chao Tree) \ntemplate <typename X_Tp, typename Y_Tp>\nstruct LiChaoTree\
    \ {\nprivate:\n    vector<X_Tp> X_pos;\n    Y_Tp E;\n    function<bool(Y_Tp, Y_Tp)>\
    \ comp;\n    int N;\n\n    // @brief Line: \u76F4\u7DDA\u306E\u30AF\u30E9\u30B9\
    \n    struct Line {\n        bool is_empty;\n        Y_Tp a, b; int index;\n\n\
    \        Line() { is_empty = true; }\n        Line(Y_Tp a_, Y_Tp b_, int index_)\n\
    \            : a(a_), b(b_), index(index_) { is_empty = false; }\n        \n \
    \       bool empty() const { return is_empty; }\n        Y_Tp f(X_Tp x) const\
    \ { return a*x + b; }\n    };\n\n    vector<Line> node;\n\n    void node_update(Line\
    \ line, int t1, int t2, int l, int r, int k) {\n        int mid = (l + r) / 2;\n\
    \        if(t2 <= l or r <= t1) return;\n        if(t1 <= l and r <= t2) {\n \
    \           if(node[k].empty()) {\n                node[k] = line;\n         \
    \       return;\n            }\n\n            if(comp(line.f(X_pos[l]), node[k].f(X_pos[l]))\
    \ and\n               comp(line.f(X_pos[r-1]), node[k].f(X_pos[r-1]))) return;\n\
    \n            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l])) and\n           \
    \    comp(node[k].f(X_pos[r-1]), line.f(X_pos[r-1]))) {\n                node[k]\
    \ = line;\n                return;\n            }\n\n            if(r - l == 1)\
    \ return;\n            if(comp(node[k].f(X_pos[mid]), line.f(X_pos[mid]))) {\n\
    \                swap(line, node[k]);\n            }\n                \n     \
    \       if(comp(node[k].f(X_pos[l]), line.f(X_pos[l]))) {\n                node_update(line,\
    \ t1, t2, l, mid, 2*k+1);\n            }\n            else {\n               \
    \ node_update(line, t1, t2, mid, r, 2*k+2);\n            }\n        }\n      \
    \  else {\n            node_update(line, t1, t2, l, mid, 2*k+1);\n           \
    \ node_update(line, t1, t2, mid, r, 2*k+2);\n        }\n    }\n\n    pair<Y_Tp,\
    \ int> search_line(int t) const {\n        pair<Y_Tp, int> result(E, -1);\n  \
    \      int l = 0, r = N, k = 0;\n        while(true) {\n            if(!node[k].empty())\
    \ {\n                pair<Y_Tp, int> cand(node[k].f(X_pos[t]), node[k].index);\n\
    \                if(comp(result.first, cand.first)) result = cand;\n         \
    \   }\n\n            if(r - l == 1) break;\n            int mid = (l + r) / 2;\n\
    \            if(t < mid) r = mid, k = 2*k + 1;\n            else l = mid, k =\
    \ 2*k + 2;\n        }\n        return result;\n    }\n    \npublic:\n    // @brief\
    \ \u30AF\u30A8\u30EA\u304C\u4E0E\u3048\u3089\u308C\u308B\u5EA7\u6A19\u30FB\u5358\
    \u4F4D\u5143\u30FB\u6BD4\u8F03\u95A2\u6570\u3092\u6E21\u3059\n    LiChaoTree(vector<X_Tp>\
    \ X_pos_, Y_Tp E_,\n               function<bool(Y_Tp, Y_Tp)> comp_)\n       \
    \ : X_pos(X_pos_), E(E_), comp(comp_) {\n        sort(X_pos.begin(), X_pos.end());\n\
    \        X_pos.erase(unique(X_pos.begin(), X_pos.end()), X_pos.end());\n     \
    \   N = 1; while(N < X_pos.size()) N <<= 1;\n        while(X_pos.size() < N) X_pos.emplace_back(X_pos.back());\n\
    \        node.resize(2*N-1, Line());\n    }\n\n    // @brief \u76F4\u7DDA $y =\
    \ ax + b$ \u3092\u96C6\u5408\u306B\u52A0\u3048\u308B (\u76F4\u7DDA\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u756A\u53F7\u3092\u4E0E\u3048\u3066\u3082\u3088\
    \u3044)\n    void insert(Y_Tp a, Y_Tp b, int k=-1) {\n        Line line(a, b,\
    \ k);\n        node_update(line, 0, N, 0, N, 0);\n    }\n\n    // @brief \u7DDA\
    \u5206 $y = ax + b$ ($x_1 \\leq x \\leq x_2$) \u3092\u96C6\u5408\u306B\u52A0\u3048\
    \u308B (\u7DDA\u5206\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u756A\u53F7\u3092\
    \u4E0E\u3048\u3066\u3082\u3088\u3044)\n    void insert(Y_Tp a, Y_Tp b, X_Tp x1,\
    \ X_Tp x2, int k=-1) {\n        Line line(a, b, k);\n        int t1 = lower_bound(X_pos.begin(),\
    \ X_pos.end(), x1) - X_pos.begin();\n        int t2 = lower_bound(X_pos.begin(),\
    \ X_pos.end(), x2) - X_pos.begin();\n        assert(t1 < X_pos.size() and X_pos[t1]\
    \ == x1);\n        assert(t2 < X_pos.size() and X_pos[t2] == x2); t2++;\n    \
    \    node_update(line, t1, t2, 0, N, 0);\n    }\n\n    // @brief $x$ \u3092\u5F15\
    \u6570\u306B\u4E0E\u3048\u3001\u6BD4\u8F03\u95A2\u6570 comp \u306B\u3088\u308A\
    \u9806\u5E8F\u304C\u6700\u4E0A\u3068\u306A\u308B\u76F4\u7DDA $f$ \u306B\u304A\u3051\
    \u308B\u5024 $f(x)$ \u3068\u3001\u305D\u306E\u76F4\u7DDA\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n    pair<Y_Tp, int> query_pair(X_Tp x) const\
    \ {\n        int t = lower_bound(X_pos.begin(), X_pos.end(), x) - X_pos.begin();\n\
    \        assert(t < X_pos.size() and X_pos[t] == x);\n        return search_line(t);\n\
    \    }\n\n    // @brief `query_pair` \u3067\u5024\u3060\u3051\u53D6\u3063\u3066\
    \u304F\u308B\u30D0\u30FC\u30B8\u30E7\u30F3\n    Y_Tp query(X_Tp x) const {\n \
    \       return query_pair(x).first;\n    }\n};\n"
  code: "// @brief Convex Hull Trick (Li-Chao Tree) \ntemplate <typename X_Tp, typename\
    \ Y_Tp>\nstruct LiChaoTree {\nprivate:\n    vector<X_Tp> X_pos;\n    Y_Tp E;\n\
    \    function<bool(Y_Tp, Y_Tp)> comp;\n    int N;\n\n    // @brief Line: \u76F4\
    \u7DDA\u306E\u30AF\u30E9\u30B9\n    struct Line {\n        bool is_empty;\n  \
    \      Y_Tp a, b; int index;\n\n        Line() { is_empty = true; }\n        Line(Y_Tp\
    \ a_, Y_Tp b_, int index_)\n            : a(a_), b(b_), index(index_) { is_empty\
    \ = false; }\n        \n        bool empty() const { return is_empty; }\n    \
    \    Y_Tp f(X_Tp x) const { return a*x + b; }\n    };\n\n    vector<Line> node;\n\
    \n    void node_update(Line line, int t1, int t2, int l, int r, int k) {\n   \
    \     int mid = (l + r) / 2;\n        if(t2 <= l or r <= t1) return;\n       \
    \ if(t1 <= l and r <= t2) {\n            if(node[k].empty()) {\n             \
    \   node[k] = line;\n                return;\n            }\n\n            if(comp(line.f(X_pos[l]),\
    \ node[k].f(X_pos[l])) and\n               comp(line.f(X_pos[r-1]), node[k].f(X_pos[r-1])))\
    \ return;\n\n            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l])) and\n\
    \               comp(node[k].f(X_pos[r-1]), line.f(X_pos[r-1]))) {\n         \
    \       node[k] = line;\n                return;\n            }\n\n          \
    \  if(r - l == 1) return;\n            if(comp(node[k].f(X_pos[mid]), line.f(X_pos[mid])))\
    \ {\n                swap(line, node[k]);\n            }\n                \n \
    \           if(comp(node[k].f(X_pos[l]), line.f(X_pos[l]))) {\n              \
    \  node_update(line, t1, t2, l, mid, 2*k+1);\n            }\n            else\
    \ {\n                node_update(line, t1, t2, mid, r, 2*k+2);\n            }\n\
    \        }\n        else {\n            node_update(line, t1, t2, l, mid, 2*k+1);\n\
    \            node_update(line, t1, t2, mid, r, 2*k+2);\n        }\n    }\n\n \
    \   pair<Y_Tp, int> search_line(int t) const {\n        pair<Y_Tp, int> result(E,\
    \ -1);\n        int l = 0, r = N, k = 0;\n        while(true) {\n            if(!node[k].empty())\
    \ {\n                pair<Y_Tp, int> cand(node[k].f(X_pos[t]), node[k].index);\n\
    \                if(comp(result.first, cand.first)) result = cand;\n         \
    \   }\n\n            if(r - l == 1) break;\n            int mid = (l + r) / 2;\n\
    \            if(t < mid) r = mid, k = 2*k + 1;\n            else l = mid, k =\
    \ 2*k + 2;\n        }\n        return result;\n    }\n    \npublic:\n    // @brief\
    \ \u30AF\u30A8\u30EA\u304C\u4E0E\u3048\u3089\u308C\u308B\u5EA7\u6A19\u30FB\u5358\
    \u4F4D\u5143\u30FB\u6BD4\u8F03\u95A2\u6570\u3092\u6E21\u3059\n    LiChaoTree(vector<X_Tp>\
    \ X_pos_, Y_Tp E_,\n               function<bool(Y_Tp, Y_Tp)> comp_)\n       \
    \ : X_pos(X_pos_), E(E_), comp(comp_) {\n        sort(X_pos.begin(), X_pos.end());\n\
    \        X_pos.erase(unique(X_pos.begin(), X_pos.end()), X_pos.end());\n     \
    \   N = 1; while(N < X_pos.size()) N <<= 1;\n        while(X_pos.size() < N) X_pos.emplace_back(X_pos.back());\n\
    \        node.resize(2*N-1, Line());\n    }\n\n    // @brief \u76F4\u7DDA $y =\
    \ ax + b$ \u3092\u96C6\u5408\u306B\u52A0\u3048\u308B (\u76F4\u7DDA\u306E\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u756A\u53F7\u3092\u4E0E\u3048\u3066\u3082\u3088\
    \u3044)\n    void insert(Y_Tp a, Y_Tp b, int k=-1) {\n        Line line(a, b,\
    \ k);\n        node_update(line, 0, N, 0, N, 0);\n    }\n\n    // @brief \u7DDA\
    \u5206 $y = ax + b$ ($x_1 \\leq x \\leq x_2$) \u3092\u96C6\u5408\u306B\u52A0\u3048\
    \u308B (\u7DDA\u5206\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u756A\u53F7\u3092\
    \u4E0E\u3048\u3066\u3082\u3088\u3044)\n    void insert(Y_Tp a, Y_Tp b, X_Tp x1,\
    \ X_Tp x2, int k=-1) {\n        Line line(a, b, k);\n        int t1 = lower_bound(X_pos.begin(),\
    \ X_pos.end(), x1) - X_pos.begin();\n        int t2 = lower_bound(X_pos.begin(),\
    \ X_pos.end(), x2) - X_pos.begin();\n        assert(t1 < X_pos.size() and X_pos[t1]\
    \ == x1);\n        assert(t2 < X_pos.size() and X_pos[t2] == x2); t2++;\n    \
    \    node_update(line, t1, t2, 0, N, 0);\n    }\n\n    // @brief $x$ \u3092\u5F15\
    \u6570\u306B\u4E0E\u3048\u3001\u6BD4\u8F03\u95A2\u6570 comp \u306B\u3088\u308A\
    \u9806\u5E8F\u304C\u6700\u4E0A\u3068\u306A\u308B\u76F4\u7DDA $f$ \u306B\u304A\u3051\
    \u308B\u5024 $f(x)$ \u3068\u3001\u305D\u306E\u76F4\u7DDA\u306E\u30A4\u30F3\u30C7\
    \u30C3\u30AF\u30B9\u3092\u8FD4\u3059\n    pair<Y_Tp, int> query_pair(X_Tp x) const\
    \ {\n        int t = lower_bound(X_pos.begin(), X_pos.end(), x) - X_pos.begin();\n\
    \        assert(t < X_pos.size() and X_pos[t] == x);\n        return search_line(t);\n\
    \    }\n\n    // @brief `query_pair` \u3067\u5024\u3060\u3051\u53D6\u3063\u3066\
    \u304F\u308B\u30D0\u30FC\u30B8\u30E7\u30F3\n    Y_Tp query(X_Tp x) const {\n \
    \       return query_pair(x).first;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_010_convexhulltrick.cpp
  requiredBy: []
  timestamp: '2020-01-07 01:10:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/yosupo/SegmentAddGetMin.test.cpp
documentation_of: math/math_010_convexhulltrick.cpp
layout: document
redirect_from:
- /library/math/math_010_convexhulltrick.cpp
- /library/math/math_010_convexhulltrick.cpp.html
title: Convex Hull Trick (Li-Chao Tree)
---
