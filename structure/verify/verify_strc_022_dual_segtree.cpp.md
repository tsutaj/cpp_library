---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/strc_022_dual_segtree.cpp
    title: "\u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/verify/verify_strc_022_dual_segtree.cpp\"\n#include\
    \ <vector>\n#include <iostream>\n#include <algorithm>\n#include <functional>\n\
    #include <climits>\n#include <map>\nusing namespace std;\n#line 1 \"structure/strc_022_dual_segtree.cpp\"\
    \n// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u53CC\u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)\n// \u53CC\
    \u5BFE\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dual Segment Tree)\n// ref: https://kimiyuki.net/blog/2019/02/22/dual-segment-tree/\n\
    template <typename MonoidType, typename OperatorType>\nstruct DualSegmentTree\
    \ {\n    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;\n   \
    \ using OOtoO = function< OperatorType(OperatorType, OperatorType) >;\n\n    int\
    \ n;\n    vector<MonoidType> bottom;\n    vector<OperatorType> lazy;\n    OperatorType\
    \ E;\n\n    // update / lazy function\n    MOtoM upd_f;\n    OOtoO lzy_f;\n\n\
    \    inline void build(const vector<MonoidType> &v) {\n        int m = v.size();\n\
    \        n = 1; while(n < m) n *= 2;\n        bottom = v; bottom.resize(n);\n\
    \        lazy.resize(n - 1, E);\n    }\n\n    DualSegmentTree() {}\n    DualSegmentTree(OperatorType\
    \ E_,\n                    MOtoM upd_f_, OOtoO lzy_f_,\n                    vector<MonoidType>\
    \ v = vector<MonoidType>()) :\n        E(E_), upd_f(upd_f_), lzy_f(lzy_f_) {\n\
    \        build(v);\n    }\n\n    void update(int a, int b, OperatorType x, int\
    \ l, int r, size_t k) {\n        if(b <= l or r <= a) return;\n        if(a <=\
    \ l and r <= b) {\n            if(k < lazy.size())\n                lazy[k] =\
    \ lzy_f(lazy[k], x);\n            else\n                bottom[k-n+1] = upd_f(bottom[k-n+1],\
    \ x);\n        }\n        else {\n            int mid = (l + r) >> 1;\n      \
    \      update(0, n, lazy[k], l, mid, 2*k+1);\n            update(0, n, lazy[k],\
    \ mid, r, 2*k+2);\n            lazy[k] = E;\n            update(a, b, x, l, mid,\
    \ 2*k+1);\n            update(a, b, x, mid, r, 2*k+2);\n        }\n    }\n\n \
    \   void update(int a, int b, OperatorType x) {\n        update(a, b, x, 0, n,\
    \ 0);\n    }\n\n    MonoidType query(int k) {\n        MonoidType res = bottom[k];\n\
    \        for(k = (k+n)>>1; k>0; k>>=1) { // 1-indexed\n            res = upd_f(res,\
    \ lazy[k-1]);\n        }\n        return res;\n    }\n};\n#line 9 \"structure/verify/verify_strc_022_dual_segtree.cpp\"\
    \n\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n    using Pair = pair<int,\
    \ int>;\n    DualSegmentTree<int, Pair> seg(make_pair(0, 0),\n               \
    \                    [](int x, Pair p) {\n                                   \
    \    if(p.second == 0) return x;\n                                       return\
    \ p.first;\n                                   },\n                          \
    \         [](Pair a, Pair b) {\n                                       return\
    \ b.second ? b : a;\n                                   },\n                 \
    \                  vector<int>(N, INT_MAX));\n\n    int indexed = 0;\n    for(int\
    \ i=0; i<Q; i++) {\n        int q; cin >> q;\n        if(q == 0) {\n         \
    \   int s, t, x; cin >> s >> t >> x;\n            s -= indexed, t -= indexed,\
    \ t++;\n            seg.update(s, t, make_pair(x, 1));\n        }\n        if(q\
    \ == 1) {\n            int x; cin >> x; x -= indexed;\n            cout << seg.query(x)\
    \ << endl;\n        }\n    }\n}\n\nvoid DSL_2_E() {\n    int N, Q; cin >> N >>\
    \ Q;\n    DualSegmentTree<int, int> seg(0,\n                                 \
    \ [](int a, int b) { return a + b; },\n                                  [](int\
    \ a, int b) { return a + b; },\n                                  vector<int>(N,\
    \ 0));\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n        int\
    \ query_type; cin >> query_type;\n        if(query_type == 0) {\n            int\
    \ s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s; cin >> s;\n            s -= indexed;\n            cout <<\
    \ seg.query(s) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\nvoid\
    \ ABC128_E() {\n    int N, Q; cin >> N >> Q;\n\n    map<int, int> cmp; int id\
    \ = 0;\n    vector<int> s(N), t(N), x(N), p(Q);\n    for(int i=0; i<N; i++) {\n\
    \        cin >> s[i] >> t[i] >> x[i];\n        s[i] = max(0, s[i] - x[i]);\n \
    \       t[i] = max(0, t[i] - x[i]);\n        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[\
    \ t[i] - 1 ]++;\n    }\n    for(int i=0; i<Q; i++) {\n        cin >> p[i];\n \
    \       cmp[ p[i] ]++;\n    }\n    for(auto &e : cmp) e.second = id++;\n    for(int\
    \ i=0; i<N; i++) {\n        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];\n    }\n \
    \   for(int i=0; i<Q; i++) {\n        p[i] = cmp[ p[i] ];\n    }\n    \n    DualSegmentTree<int,\
    \ int> seg(INT_MAX,\n                                  [](int a, int b) { return\
    \ min(a, b); },\n                                  [](int a, int b) { return min(a,\
    \ b); },\n                                  vector<int>(id, INT_MAX));\n    \n\
    \    for(int i=0; i<N; i++) {\n        seg.update(s[i], t[i], x[i]);\n    }\n\
    \    for(int i=0; i<Q; i++) {\n        int res = seg.query(p[i]);\n        if(res\
    \ == INT_MAX) cout << -1 << endl;\n        else cout << res << endl;\n    }\n\
    }\n\nint main() {\n    DSL_2_D();\n    // DSL_2_E();\n    // ABC128_E();\n}\n"
  code: "#include <vector>\n#include <iostream>\n#include <algorithm>\n#include <functional>\n\
    #include <climits>\n#include <map>\nusing namespace std;\n#include \"../strc_022_dual_segtree.cpp\"\
    \n\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n    using Pair = pair<int,\
    \ int>;\n    DualSegmentTree<int, Pair> seg(make_pair(0, 0),\n               \
    \                    [](int x, Pair p) {\n                                   \
    \    if(p.second == 0) return x;\n                                       return\
    \ p.first;\n                                   },\n                          \
    \         [](Pair a, Pair b) {\n                                       return\
    \ b.second ? b : a;\n                                   },\n                 \
    \                  vector<int>(N, INT_MAX));\n\n    int indexed = 0;\n    for(int\
    \ i=0; i<Q; i++) {\n        int q; cin >> q;\n        if(q == 0) {\n         \
    \   int s, t, x; cin >> s >> t >> x;\n            s -= indexed, t -= indexed,\
    \ t++;\n            seg.update(s, t, make_pair(x, 1));\n        }\n        if(q\
    \ == 1) {\n            int x; cin >> x; x -= indexed;\n            cout << seg.query(x)\
    \ << endl;\n        }\n    }\n}\n\nvoid DSL_2_E() {\n    int N, Q; cin >> N >>\
    \ Q;\n    DualSegmentTree<int, int> seg(0,\n                                 \
    \ [](int a, int b) { return a + b; },\n                                  [](int\
    \ a, int b) { return a + b; },\n                                  vector<int>(N,\
    \ 0));\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n        int\
    \ query_type; cin >> query_type;\n        if(query_type == 0) {\n            int\
    \ s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s; cin >> s;\n            s -= indexed;\n            cout <<\
    \ seg.query(s) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\nvoid\
    \ ABC128_E() {\n    int N, Q; cin >> N >> Q;\n\n    map<int, int> cmp; int id\
    \ = 0;\n    vector<int> s(N), t(N), x(N), p(Q);\n    for(int i=0; i<N; i++) {\n\
    \        cin >> s[i] >> t[i] >> x[i];\n        s[i] = max(0, s[i] - x[i]);\n \
    \       t[i] = max(0, t[i] - x[i]);\n        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[\
    \ t[i] - 1 ]++;\n    }\n    for(int i=0; i<Q; i++) {\n        cin >> p[i];\n \
    \       cmp[ p[i] ]++;\n    }\n    for(auto &e : cmp) e.second = id++;\n    for(int\
    \ i=0; i<N; i++) {\n        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];\n    }\n \
    \   for(int i=0; i<Q; i++) {\n        p[i] = cmp[ p[i] ];\n    }\n    \n    DualSegmentTree<int,\
    \ int> seg(INT_MAX,\n                                  [](int a, int b) { return\
    \ min(a, b); },\n                                  [](int a, int b) { return min(a,\
    \ b); },\n                                  vector<int>(id, INT_MAX));\n    \n\
    \    for(int i=0; i<N; i++) {\n        seg.update(s[i], t[i], x[i]);\n    }\n\
    \    for(int i=0; i<Q; i++) {\n        int res = seg.query(p[i]);\n        if(res\
    \ == INT_MAX) cout << -1 << endl;\n        else cout << res << endl;\n    }\n\
    }\n\nint main() {\n    DSL_2_D();\n    // DSL_2_E();\n    // ABC128_E();\n}\n"
  dependsOn:
  - structure/strc_022_dual_segtree.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_022_dual_segtree.cpp
  requiredBy: []
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_022_dual_segtree.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_022_dual_segtree.cpp
- /library/structure/verify/verify_strc_022_dual_segtree.cpp.html
title: structure/verify/verify_strc_022_dual_segtree.cpp
---
