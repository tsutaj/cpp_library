---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: structure/strc_009_abst_lazy_segtree.cpp
    title: "\u9045\u5EF6\u4F1D\u64AD\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment\
      \ Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/verify/verify_strc_009_abst_lazy_segtree.cpp\"\
    \n#include <vector>\n#include <functional>\n#include <algorithm>\n#include <iostream>\n\
    #include <climits>\n#include <map>\n#include <utility>\nusing namespace std;\n\
    #line 1 \"structure/strc_009_abst_lazy_segtree.cpp\"\n// @category \u30BB\u30B0\
    \u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u9045\u5EF6\u4F1D\u64AD\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)\ntemplate <typename MonoidType,\
    \ typename OperatorType>\nstruct LazySegmentTree {\n    using MMtoM = function<\
    \ MonoidType(MonoidType, MonoidType) >;\n    using OOtoO = function< OperatorType(OperatorType,\
    \ OperatorType) >;\n    using MOtoM = function< MonoidType(MonoidType, OperatorType)\
    \ >;\n    using OItoO = function< OperatorType(OperatorType, int) >;\n\n    //\
    \ node, lazy, update flag (for lazy), identity element\n    int n;\n    vector<MonoidType>\
    \ node;\n    vector<OperatorType> lazy;\n    vector<bool> need_update;\n    MonoidType\
    \ E0;\n    OperatorType E1;\n\n    // update / combine / lazy / accumulate function\n\
    \    MOtoM upd_f;\n    MMtoM cmb_f;\n    OOtoO lzy_f;\n    OItoO acc_f;\n\n  \
    \  void build(int m, vector<MonoidType> v = vector<MonoidType>()) {\n        if(v\
    \ != vector<MonoidType>()) m = v.size();\n        n = 1; while(n < m) n *= 2;\n\
    \n        node = vector<MonoidType>(2*n-1, E0);\n        lazy = vector<OperatorType>(2*n-1,\
    \ E1);\n        need_update = vector<bool>(2*n-1, false);\n        if(v != vector<MonoidType>())\
    \ {\n            for(int i=0; i<m; i++) {\n                node[n-1+i] = v[i];\n\
    \            }\n            for(int i=n-2; i>=0; i--) {\n                node[i]\
    \ = cmb_f(node[2*i+1], node[2*i+2]);\n            }\n        }\n    }\n\n    //\
    \ initialize\n    LazySegmentTree() {}\n    LazySegmentTree(int n_, MonoidType\
    \ E0_, OperatorType E1_,\n                    MOtoM upd_f_, MMtoM cmb_f_, OOtoO\
    \ lzy_f_, OItoO acc_f_,\n                    vector<MonoidType> v = vector<MonoidType>())\
    \ :\n        E0(E0_), E1(E1_),\n        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_),\
    \ acc_f(acc_f_) {\n        build(n_, v);\n    }\n\n    void eval(int k, int l,\
    \ int r) {\n        if(!need_update[k]) return;\n        node[k] = upd_f(node[k],\
    \ acc_f(lazy[k], r - l));\n        if(r - l > 1) {\n            lazy[2*k+1] =\
    \ lzy_f(lazy[2*k+1], lazy[k]);\n            lazy[2*k+2] = lzy_f(lazy[2*k+2], lazy[k]);\n\
    \            need_update[2*k+1] = need_update[2*k+2] = true;\n        }\n    \
    \    lazy[k] = E1;\n        need_update[k] = false;\n    }\n\n    void update(int\
    \ a, int b, OperatorType x, int l, int r, int k) {\n        eval(k, l, r);\n \
    \       if(b <= l or  r <= a) return;\n        if(a <= l and r <= b) {\n     \
    \       lazy[k] = lzy_f(lazy[k], x);\n            need_update[k] = true;\n   \
    \         eval(k, l, r);\n        }\n        else {\n            int mid = (l\
    \ + r) / 2;\n            update(a, b, x, l, mid, 2*k+1);\n            update(a,\
    \ b, x, mid, r, 2*k+2);\n            node[k] = cmb_f(node[2*k+1], node[2*k+2]);\n\
    \        }\n    }\n\n    MonoidType query(int a, int b, int l, int r, int k) {\n\
    \        if(b <= l or  r <= a) return E0;\n        eval(k, l, r);\n        if(a\
    \ <= l and r <= b) return node[k];\n        int mid = (l + r) / 2;\n        MonoidType\
    \ vl = query(a, b, l, mid, 2*k+1);\n        MonoidType vr = query(a, b, mid, r,\
    \ 2*k+2);\n        return cmb_f(vl, vr);\n    }\n\n    // update [a, b)-th element\
    \ (applied value, x)\n    void update(int a, int b, OperatorType x) {\n      \
    \  update(a, b, x, 0, n, 0);\n    }\n\n    // range query for [a, b)\n    MonoidType\
    \ query(int a, int b) {\n        return query(a, b, 0, n, 0);\n    }\n\n    void\
    \ dump() {\n        fprintf(stderr, \"[lazy]\\n\");\n        for(int i=0; i<2*n-1;\
    \ i++) {\n            if(i == n-1) fprintf(stderr, \"xxx \");\n            if(lazy[i]\
    \ == E1) fprintf(stderr, \"  E \");\n            else fprintf(stderr, \"%3d \"\
    , lazy[i]);\n        }\n        fprintf(stderr, \"\\n\");\n\n        fprintf(stderr,\
    \ \"[node]\\n\");\n        for(int i=0; i<2*n-1; i++) {\n            if(i == n-1)\
    \ fprintf(stderr, \"xxx \");\n            if(node[i] == E0) fprintf(stderr, \"\
    \  E \");\n            else fprintf(stderr, \"%3d \", node[i]);\n        }\n \
    \       fprintf(stderr, \"\\n\");\n    }\n};\n#line 10 \"structure/verify/verify_strc_009_abst_lazy_segtree.cpp\"\
    \n\n// Verified on Apr 27, 2019\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n\
    \    LazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,\n                    \
    \              [](int a, int b) { return b;         },  // upd\n             \
    \                     [](int a, int b) { return min(a, b); },  // cmb\n      \
    \                            [](int a, int b) { return b;         },  // lzy\n\
    \                                  [](int a, int x) { return a;         }); //\
    \ acc\n    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type;\
    \ cin >> query_type;\n        if(query_type == 0) {\n            int s, t, x;\
    \ cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n        \
    \    seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n        \
    \    int s; cin >> s;\n            s -= indexed;\n            cout << seg.query(s,\
    \ s+1) << endl;\n        }\n        // seg.dump();\n    }\n}\n\nvoid DSL_2_D_pair()\
    \ {\n    int N, Q; cin >> N >> Q;\n    using Pair = pair<int, int>;\n    LazySegmentTree<int,\
    \ Pair> seg(N, INT_MAX, make_pair(0, 0),\n                                   [](int\
    \ x, Pair p) {\n                                       if(p.second == 0) return\
    \ x;\n                                       return p.first;\n               \
    \                    },\n                                   [](int a, int b) {\
    \ return min(a, b); },\n                                   [](Pair a, Pair b)\
    \ {\n                                       return b.second ? b : a;\n       \
    \                            },\n                                   [](Pair a,\
    \ int x) { return a; },\n                                   vector<int>(N, INT_MAX));\n\
    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int q; cin >> q;\n\
    \        if(q == 0) {\n            int s, t, x; cin >> s >> t >> x;\n        \
    \    s -= indexed, t -= indexed, t++;\n            seg.update(s, t, make_pair(x,\
    \ 1));\n        }\n        if(q == 1) {\n            int x; cin >> x; x -= indexed;\n\
    \            cout << seg.query(x, x+1) << endl;\n        }\n    }\n}\n\n// Verified\
    \ on Apr 27, 2019\nvoid DSL_2_E() {\n    int N, Q; cin >> N >> Q;\n    LazySegmentTree<int,\
    \ int> seg(N, 0, 0,\n                                  [](int a, int b) { return\
    \ a + b; },  // upd\n                                  [](int a, int b) { return\
    \ a + b; },  // cmb\n                                  [](int a, int b) { return\
    \ a + b; },  // lzy\n                                  [](int a, int x) { return\
    \ a * x; }); // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n\
    \        int query_type; cin >> query_type;\n        if(query_type == 0) {\n \
    \           int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t\
    \ -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s; cin >> s;\n            s -= indexed;\n         \
    \   cout << seg.query(s, s+1) << endl;\n        }\n        // seg.dump();\n  \
    \  }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_F() {\n    int N, Q; cin\
    \ >> N >> Q;\n    LazySegmentTree<int, int> seg(N, INT_MAX, 0,\n             \
    \                     [](int a, int b) { return b;         },  // upd\n      \
    \                            [](int a, int b) { return min(a, b); },  // cmb\n\
    \                                  [](int a, int b) { return b;         },  //\
    \ lzy\n                                  [](int a, int x) { return a;        \
    \ }); // acc\n    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n     \
    \   int query_type; cin >> query_type;\n        if(query_type == 0) {\n      \
    \      int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_G() {\n    int N, Q;\
    \ cin >> N >> Q;\n    using ll = long long int;\n    LazySegmentTree<ll, ll> seg(N,\
    \ 0, 0,\n                                  [](ll a, ll  b) { return a + b; },\
    \  // upd\n                                  [](ll a, ll  b) { return a + b; },\
    \  // cmb\n                                  [](ll a, ll  b) { return a + b; },\
    \  // lzy\n                                  [](ll a, int x) { return a * x; });\
    \ // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n        int\
    \ query_type; cin >> query_type;\n        if(query_type == 0) {\n            int\
    \ s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H() {\n    int N, Q;\
    \ cin >> N >> Q;\n    using ll = long long int;\n    LazySegmentTree<ll, ll> seg(N,\
    \ INT_MAX, 0,\n                                [](ll a, ll  b) { return a + b;\
    \     },  // upd\n                                [](ll a, ll  b) { return min(a,\
    \ b); },  // cmb\n                                [](ll a, ll  b) { return a +\
    \ b;     },  // lzy\n                                [](ll a, int x) { return\
    \ a;         },  // acc\n                                vector<ll>(N));\n   \
    \ \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type;\
    \ cin >> query_type;\n        if(query_type == 0) {\n            int s, t, x;\
    \ cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n        \
    \    seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n        \
    \    int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H_simple() {\n    int\
    \ N, Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair = pair<ll,\
    \ ll>;\n    LazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 1),\n     \
    \                             [](ll   a, Pair b) { return a * b.second + b.first;\
    \ },  // upd\n                                  [](ll   a, ll   b) { return min(a,\
    \ b); },  // cmb\n                                  [](Pair a, Pair b) { return\
    \ make_pair(a.first * b.second + b.first, a.second & b.second); },  // lzy\n \
    \                                 [](Pair a, int  x) { return a; }); // acc\n\n\
    \    seg.update(0, N, make_pair(0, 0));\n    int indexed = 0;\n    for(int i=0;\
    \ i<Q; i++) {\n        int query_type; cin >> query_type;\n        if(query_type\
    \ == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -=\
    \ indexed, t -= indexed;\n            seg.update(s, t, make_pair(x, 1));\n   \
    \     }\n        if(query_type == 1) {\n            int s, t; cin >> s >> t; t++;\n\
    \            s -= indexed; t -= indexed;\n            cout << seg.query(s, t)\
    \ << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n\n// Verified on\
    \ Apr 27, 2019\nvoid DSL_2_I() {\n    int N, Q; cin >> N >> Q;\n    using ll =\
    \ long long int;\n    LazySegmentTree<ll, ll> seg(N, 0, 0,\n                 \
    \               [](ll a, ll  b) { return b;     },  // upd\n                 \
    \               [](ll a, ll  b) { return a + b; },  // cmb\n                 \
    \               [](ll a, ll  b) { return b;     },  // lzy\n                 \
    \               [](ll a, int x) { return a * x; },  // acc\n                 \
    \               vector<ll>(N));\n    \n    int indexed = 0;\n    for(int i=0;\
    \ i<Q; i++) {\n        int query_type; cin >> query_type;\n        if(query_type\
    \ == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -=\
    \ indexed, t -= indexed;\n            seg.update(s, t, x);\n        }\n      \
    \  if(query_type == 1) {\n            int s, t; cin >> s >> t; t++;\n        \
    \    s -= indexed; t -= indexed;\n            cout << seg.query(s, t) << endl;\n\
    \        }\n        // seg.dump();\n    }    \n}\n\n// Verified on May 31, 2019\n\
    void ABC128_E() {\n    int N, Q; cin >> N >> Q;\n\n    map<int, int> cmp; int\
    \ id = 0;\n    vector<int> s(N), t(N), x(N), p(Q);\n    for(int i=0; i<N; i++)\
    \ {\n        cin >> s[i] >> t[i] >> x[i];\n        s[i] = max(0, s[i] - x[i]);\n\
    \        t[i] = max(0, t[i] - x[i]);\n        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[\
    \ t[i] - 1 ]++;\n    }\n    for(int i=0; i<Q; i++) {\n        cin >> p[i];\n \
    \       cmp[ p[i] ]++;\n    }\n    for(auto &e : cmp) e.second = id++;\n    for(int\
    \ i=0; i<N; i++) {\n        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];\n    }\n \
    \   for(int i=0; i<Q; i++) {\n        p[i] = cmp[ p[i] ];\n    }\n    \n    LazySegmentTree<int,\
    \ int> seg(id, INT_MAX, INT_MAX,\n                                  [](int a,\
    \ int b) { return min(a, b); },\n                                  [](int a, int\
    \ b) { return min(a, b); },\n                                  [](int a, int b)\
    \ { return min(a, b); },\n                                  [](int a, int x) {\
    \ return a; });\n    \n    for(int i=0; i<N; i++) {\n        seg.update(s[i],\
    \ t[i], x[i]);\n    }\n    for(int i=0; i<Q; i++) {\n        int res = seg.query(p[i],\
    \ p[i]+1);\n        if(res == INT_MAX) cout << -1 << endl;\n        else cout\
    \ << res << endl;\n    }\n}\n\n/*\nvoid yuki_749() {\n    int N, Q; cin >> N >>\
    \ Q;\n\n    \n    \n}\n*/\n\nint main() {\n    // DSL_2_D();\n    // DSL_2_D_pair();\n\
    \    // DSL_2_E();\n    // DSL_2_F();\n    // DSL_2_G();\n    // DSL_2_H();\n\
    \    DSL_2_H_simple();\n    // DSL_2_I();\n    // ABC128_E();\n    return 0;\n\
    }\n"
  code: "#include <vector>\n#include <functional>\n#include <algorithm>\n#include\
    \ <iostream>\n#include <climits>\n#include <map>\n#include <utility>\nusing namespace\
    \ std;\n#include \"../strc_009_abst_lazy_segtree.cpp\"\n\n// Verified on Apr 27,\
    \ 2019\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n    LazySegmentTree<int,\
    \ int> seg(N, INT_MAX, INT_MAX,\n                                  [](int a, int\
    \ b) { return b;         },  // upd\n                                  [](int\
    \ a, int b) { return min(a, b); },  // cmb\n                                 \
    \ [](int a, int b) { return b;         },  // lzy\n                          \
    \        [](int a, int x) { return a;         }); // acc\n    \n    int indexed\
    \ = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n\
    \        if(query_type == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n\
    \            s -= indexed, t -= indexed;\n            seg.update(s, t, x);\n \
    \       }\n        if(query_type == 1) {\n            int s; cin >> s;\n     \
    \       s -= indexed;\n            cout << seg.query(s, s+1) << endl;\n      \
    \  }\n        // seg.dump();\n    }\n}\n\nvoid DSL_2_D_pair() {\n    int N, Q;\
    \ cin >> N >> Q;\n    using Pair = pair<int, int>;\n    LazySegmentTree<int, Pair>\
    \ seg(N, INT_MAX, make_pair(0, 0),\n                                   [](int\
    \ x, Pair p) {\n                                       if(p.second == 0) return\
    \ x;\n                                       return p.first;\n               \
    \                    },\n                                   [](int a, int b) {\
    \ return min(a, b); },\n                                   [](Pair a, Pair b)\
    \ {\n                                       return b.second ? b : a;\n       \
    \                            },\n                                   [](Pair a,\
    \ int x) { return a; },\n                                   vector<int>(N, INT_MAX));\n\
    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int q; cin >> q;\n\
    \        if(q == 0) {\n            int s, t, x; cin >> s >> t >> x;\n        \
    \    s -= indexed, t -= indexed, t++;\n            seg.update(s, t, make_pair(x,\
    \ 1));\n        }\n        if(q == 1) {\n            int x; cin >> x; x -= indexed;\n\
    \            cout << seg.query(x, x+1) << endl;\n        }\n    }\n}\n\n// Verified\
    \ on Apr 27, 2019\nvoid DSL_2_E() {\n    int N, Q; cin >> N >> Q;\n    LazySegmentTree<int,\
    \ int> seg(N, 0, 0,\n                                  [](int a, int b) { return\
    \ a + b; },  // upd\n                                  [](int a, int b) { return\
    \ a + b; },  // cmb\n                                  [](int a, int b) { return\
    \ a + b; },  // lzy\n                                  [](int a, int x) { return\
    \ a * x; }); // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n\
    \        int query_type; cin >> query_type;\n        if(query_type == 0) {\n \
    \           int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t\
    \ -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s; cin >> s;\n            s -= indexed;\n         \
    \   cout << seg.query(s, s+1) << endl;\n        }\n        // seg.dump();\n  \
    \  }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_F() {\n    int N, Q; cin\
    \ >> N >> Q;\n    LazySegmentTree<int, int> seg(N, INT_MAX, 0,\n             \
    \                     [](int a, int b) { return b;         },  // upd\n      \
    \                            [](int a, int b) { return min(a, b); },  // cmb\n\
    \                                  [](int a, int b) { return b;         },  //\
    \ lzy\n                                  [](int a, int x) { return a;        \
    \ }); // acc\n    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n     \
    \   int query_type; cin >> query_type;\n        if(query_type == 0) {\n      \
    \      int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_G() {\n    int N, Q;\
    \ cin >> N >> Q;\n    using ll = long long int;\n    LazySegmentTree<ll, ll> seg(N,\
    \ 0, 0,\n                                  [](ll a, ll  b) { return a + b; },\
    \  // upd\n                                  [](ll a, ll  b) { return a + b; },\
    \  // cmb\n                                  [](ll a, ll  b) { return a + b; },\
    \  // lzy\n                                  [](ll a, int x) { return a * x; });\
    \ // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q; i++) {\n        int\
    \ query_type; cin >> query_type;\n        if(query_type == 0) {\n            int\
    \ s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n\
    \            seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n\
    \            int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H() {\n    int N, Q;\
    \ cin >> N >> Q;\n    using ll = long long int;\n    LazySegmentTree<ll, ll> seg(N,\
    \ INT_MAX, 0,\n                                [](ll a, ll  b) { return a + b;\
    \     },  // upd\n                                [](ll a, ll  b) { return min(a,\
    \ b); },  // cmb\n                                [](ll a, ll  b) { return a +\
    \ b;     },  // lzy\n                                [](ll a, int x) { return\
    \ a;         },  // acc\n                                vector<ll>(N));\n   \
    \ \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type;\
    \ cin >> query_type;\n        if(query_type == 0) {\n            int s, t, x;\
    \ cin >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n        \
    \    seg.update(s, t, x);\n        }\n        if(query_type == 1) {\n        \
    \    int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n\
    \            cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H_simple() {\n    int\
    \ N, Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair = pair<ll,\
    \ ll>;\n    LazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 1),\n     \
    \                             [](ll   a, Pair b) { return a * b.second + b.first;\
    \ },  // upd\n                                  [](ll   a, ll   b) { return min(a,\
    \ b); },  // cmb\n                                  [](Pair a, Pair b) { return\
    \ make_pair(a.first * b.second + b.first, a.second & b.second); },  // lzy\n \
    \                                 [](Pair a, int  x) { return a; }); // acc\n\n\
    \    seg.update(0, N, make_pair(0, 0));\n    int indexed = 0;\n    for(int i=0;\
    \ i<Q; i++) {\n        int query_type; cin >> query_type;\n        if(query_type\
    \ == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -=\
    \ indexed, t -= indexed;\n            seg.update(s, t, make_pair(x, 1));\n   \
    \     }\n        if(query_type == 1) {\n            int s, t; cin >> s >> t; t++;\n\
    \            s -= indexed; t -= indexed;\n            cout << seg.query(s, t)\
    \ << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n\n// Verified on\
    \ Apr 27, 2019\nvoid DSL_2_I() {\n    int N, Q; cin >> N >> Q;\n    using ll =\
    \ long long int;\n    LazySegmentTree<ll, ll> seg(N, 0, 0,\n                 \
    \               [](ll a, ll  b) { return b;     },  // upd\n                 \
    \               [](ll a, ll  b) { return a + b; },  // cmb\n                 \
    \               [](ll a, ll  b) { return b;     },  // lzy\n                 \
    \               [](ll a, int x) { return a * x; },  // acc\n                 \
    \               vector<ll>(N));\n    \n    int indexed = 0;\n    for(int i=0;\
    \ i<Q; i++) {\n        int query_type; cin >> query_type;\n        if(query_type\
    \ == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -=\
    \ indexed, t -= indexed;\n            seg.update(s, t, x);\n        }\n      \
    \  if(query_type == 1) {\n            int s, t; cin >> s >> t; t++;\n        \
    \    s -= indexed; t -= indexed;\n            cout << seg.query(s, t) << endl;\n\
    \        }\n        // seg.dump();\n    }    \n}\n\n// Verified on May 31, 2019\n\
    void ABC128_E() {\n    int N, Q; cin >> N >> Q;\n\n    map<int, int> cmp; int\
    \ id = 0;\n    vector<int> s(N), t(N), x(N), p(Q);\n    for(int i=0; i<N; i++)\
    \ {\n        cin >> s[i] >> t[i] >> x[i];\n        s[i] = max(0, s[i] - x[i]);\n\
    \        t[i] = max(0, t[i] - x[i]);\n        cmp[ s[i] ]++; cmp[ t[i] ]++; cmp[\
    \ t[i] - 1 ]++;\n    }\n    for(int i=0; i<Q; i++) {\n        cin >> p[i];\n \
    \       cmp[ p[i] ]++;\n    }\n    for(auto &e : cmp) e.second = id++;\n    for(int\
    \ i=0; i<N; i++) {\n        s[i] = cmp[ s[i] ], t[i] = cmp[ t[i] ];\n    }\n \
    \   for(int i=0; i<Q; i++) {\n        p[i] = cmp[ p[i] ];\n    }\n    \n    LazySegmentTree<int,\
    \ int> seg(id, INT_MAX, INT_MAX,\n                                  [](int a,\
    \ int b) { return min(a, b); },\n                                  [](int a, int\
    \ b) { return min(a, b); },\n                                  [](int a, int b)\
    \ { return min(a, b); },\n                                  [](int a, int x) {\
    \ return a; });\n    \n    for(int i=0; i<N; i++) {\n        seg.update(s[i],\
    \ t[i], x[i]);\n    }\n    for(int i=0; i<Q; i++) {\n        int res = seg.query(p[i],\
    \ p[i]+1);\n        if(res == INT_MAX) cout << -1 << endl;\n        else cout\
    \ << res << endl;\n    }\n}\n\n/*\nvoid yuki_749() {\n    int N, Q; cin >> N >>\
    \ Q;\n\n    \n    \n}\n*/\n\nint main() {\n    // DSL_2_D();\n    // DSL_2_D_pair();\n\
    \    // DSL_2_E();\n    // DSL_2_F();\n    // DSL_2_G();\n    // DSL_2_H();\n\
    \    DSL_2_H_simple();\n    // DSL_2_I();\n    // ABC128_E();\n    return 0;\n\
    }\n"
  dependsOn:
  - structure/strc_009_abst_lazy_segtree.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_009_abst_lazy_segtree.cpp
  requiredBy: []
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_009_abst_lazy_segtree.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_009_abst_lazy_segtree.cpp
- /library/structure/verify/verify_strc_009_abst_lazy_segtree.cpp.html
title: structure/verify/verify_strc_009_abst_lazy_segtree.cpp
---
