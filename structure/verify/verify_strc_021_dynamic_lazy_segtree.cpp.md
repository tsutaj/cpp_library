---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: structure/strc_021_dynamic_lazy_segtree.cpp
    title: "\u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic\
      \ Lazy Segment Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp\"\
    \n#include <iostream>\n#include <cstdio>\n#include <algorithm>\n#include <climits>\n\
    #include <functional>\nusing namespace std;\n#line 1 \"structure/strc_021_dynamic_lazy_segtree.cpp\"\
    \n// @category \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title\
    \ \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Dynamic Lazy Segment\
    \ Tree)\n// \u52D5\u7684\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (\u5FC5\
    \u8981\u306A\u3068\u3053\u308D\u3060\u3051\u30CE\u30FC\u30C9\u3092\u4F5C\u308B\
    )\n\ntemplate <typename MonoidType, typename OperatorType>\nstruct LazySegNode\
    \ {\n    MonoidType value;\n    OperatorType lazy_value;\n    bool need_update;\n\
    \    LazySegNode *ch[2];\n    \n    LazySegNode() {}\n    LazySegNode(MonoidType\
    \ value_, OperatorType lazy_value_) :\n        value(value_), lazy_value(lazy_value_)\
    \ {\n        need_update = false;\n        ch[0] = ch[1] = nullptr;\n    }\n};\n\
    \ntemplate <typename MonoidType, typename OperatorType, typename IdxType = int>\n\
    struct DynamicLazySegmentTree {\n    using MMtoM = function< MonoidType(MonoidType,\
    \ MonoidType) >;\n    using OOtoO = function< OperatorType(OperatorType, OperatorType)\
    \ >;\n    using MOtoM = function< MonoidType(MonoidType, OperatorType) >;\n  \
    \  using OItoO = function< OperatorType(OperatorType, int) >;\n    using LNode\
    \ = LazySegNode<MonoidType, OperatorType>;\n\n    // node, identity element\n\
    \    IdxType n;\n    LNode *root;\n    MonoidType E0;\n    OperatorType E1;\n\n\
    \    // update / combine / lazy / accumulate function\n    MOtoM upd_f;\n    MMtoM\
    \ cmb_f;\n    OOtoO lzy_f;\n    OItoO acc_f;\n\n    DynamicLazySegmentTree() {}\n\
    \    DynamicLazySegmentTree(IdxType n_, MonoidType E0_, OperatorType E1_,\n  \
    \                         MOtoM upd_f_, MMtoM cmb_f_, OOtoO lzy_f_, OItoO acc_f_)\
    \ :\n        E0(E0_), E1(E1_),\n        upd_f(upd_f_), cmb_f(cmb_f_), lzy_f(lzy_f_),\
    \ acc_f(acc_f_) {\n        root = new LNode(E0_, E1_);\n        n = 1; while(n\
    \ < n_) n *= 2;\n    }\n\n    void eval(LNode *node, IdxType l, IdxType r) {\n\
    \        if(!node->need_update) return;\n        node->value = upd_f(node->value,\
    \ acc_f(node->lazy_value, r - l));\n        if(r - l > 1) {\n            if(!node->ch[0])\
    \ node->ch[0] = new LNode(E0, E1);\n            if(!node->ch[1]) node->ch[1] =\
    \ new LNode(E0, E1);\n            node->ch[0]->lazy_value = lzy_f(node->ch[0]->lazy_value,\
    \ node->lazy_value);\n            node->ch[1]->lazy_value = lzy_f(node->ch[1]->lazy_value,\
    \ node->lazy_value);\n            node->ch[0]->need_update = node->ch[1]->need_update\
    \ = true;\n        }\n        node->lazy_value = E1;\n        node->need_update\
    \ = false;\n    }\n\n    void update(LNode *node, IdxType a, IdxType b, OperatorType\
    \ x,\n                IdxType l, IdxType r) {\n        eval(node, l, r);\n   \
    \     if(b <= l or r <= a) return;\n        if(a <= l and r <= b) {\n        \
    \    node->lazy_value = lzy_f(node->lazy_value, x);\n            node->need_update\
    \ = true;\n            eval(node, l, r);\n        }\n        else {\n        \
    \    IdxType mid = (l + r) / 2;\n            if(!node->ch[0]) node->ch[0] = new\
    \ LNode(E0, E1);\n            if(!node->ch[1]) node->ch[1] = new LNode(E0, E1);\n\
    \            update(node->ch[0], a, b, x, l, mid);\n            update(node->ch[1],\
    \ a, b, x, mid, r);\n            node->value = cmb_f(node->ch[0]->value, node->ch[1]->value);\n\
    \        }\n    }\n\n    MonoidType query(LNode *node, IdxType a, IdxType b, IdxType\
    \ l, IdxType r) {\n        if(b <= l or r <= a) return E0;\n        eval(node,\
    \ l, r);\n        if(a <= l and r <= b) return node->value;\n        IdxType mid\
    \ = (l + r) / 2;\n        MonoidType vl = (node->ch[0] ? query(node->ch[0], a,\
    \ b, l, mid) : E0);\n        MonoidType vr = (node->ch[1] ? query(node->ch[1],\
    \ a, b, mid, r) : E0);\n        return cmb_f(vl, vr);\n    }\n\n    // update\
    \ [a, b)-th element (applied value: x)\n    void update(IdxType a, IdxType b,\
    \ OperatorType x) {\n        update(root, a, b, x, 0, n);\n    }\n\n    // range\
    \ query for [a, b)\n    MonoidType query(IdxType a, IdxType b) {\n        return\
    \ query(root, a, b, 0, n);\n    }\n};\n#line 8 \"structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp\"\
    \n\n// Verified on May 28, 2019\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n\
    \    DynamicLazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,\n             \
    \                            [](int a, int b) { return b; },\n               \
    \                          [](int a, int b) { return min(a, b); },\n         \
    \                                [](int a, int b) { return b; },\n           \
    \                              [](int a, int b) { return a; });\n\n    int indexed\
    \ = 0;\n    for(int i=0; i<Q; i++) {\n        int q; cin >> q;\n        if(q ==\
    \ 0) {\n            int s, t, x; cin >> s >> t >> x;\n            s -= indexed;\
    \ t -= indexed; t++;\n            seg.update(s, t, x);\n        }\n        if(q\
    \ == 1) {\n            int k; cin >> k;\n            k -= indexed;\n         \
    \   cout << seg.query(k, k+1) << endl;\n        }\n    }\n}\n\n// Verified on\
    \ May 28, 2019\nvoid DSL_2_E() {\n    int N, Q; cin >> N >> Q;\n    DynamicLazySegmentTree<int,\
    \ int> seg(N, 0, 0,\n                                         [](int a, int b)\
    \ { return a + b; },  // upd\n                                         [](int\
    \ a, int b) { return a + b; },  // cmb\n                                     \
    \    [](int a, int b) { return a + b; },  // lzy\n                           \
    \              [](int a, int x) { return a * x; }); // acc\n    \n    int indexed\
    \ = 1;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n\
    \        if(query_type == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n\
    \            s -= indexed, t -= indexed;\n            seg.update(s, t, x);\n \
    \       }\n        if(query_type == 1) {\n            int s; cin >> s;\n     \
    \       s -= indexed;\n            cout << seg.query(s, s+1) << endl;\n      \
    \  }\n        // seg.dump();\n    }    \n}\n\n// Verified on May 28, 2019\nvoid\
    \ DSL_2_F() {\n    int N, Q; cin >> N >> Q;\n    DynamicLazySegmentTree<int, int>\
    \ seg(N, INT_MAX, 0,\n                                         [](int a, int b)\
    \ { return b;         },  // upd\n                                         [](int\
    \ a, int b) { return min(a, b); },  // cmb\n                                 \
    \        [](int a, int b) { return b;         },  // lzy\n                   \
    \                      [](int a, int x) { return a;         }); // acc\n    \n\
    \    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin\
    \ >> query_type;\n        if(query_type == 0) {\n            int s, t, x; cin\
    \ >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n            seg.update(s,\
    \ t, x);\n        }\n        if(query_type == 1) {\n            int s, t; cin\
    \ >> s >> t; t++;\n            s -= indexed; t -= indexed;\n            cout <<\
    \ seg.query(s, t) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n\
    // Verified on May 28, 2019\nvoid DSL_2_G() {\n    int N, Q; cin >> N >> Q;\n\
    \    using ll = long long int;\n    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,\n\
    \                                       [](ll a, ll  b) { return a + b; },  //\
    \ upd\n                                       [](ll a, ll  b) { return a + b;\
    \ },  // cmb\n                                       [](ll a, ll  b) { return\
    \ a + b; },  // lzy\n                                       [](ll a, int x) {\
    \ return a * x; }); // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q;\
    \ i++) {\n        int query_type; cin >> query_type;\n        if(query_type ==\
    \ 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed,\
    \ t -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s, t; cin >> s >> t; t++;\n            s -= indexed;\
    \ t -= indexed;\n            cout << seg.query(s, t) << endl;\n        }\n   \
    \     // seg.dump();\n    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H_simple()\
    \ {\n    int N, Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair\
    \ = pair<ll, ll>;\n    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0,\
    \ 1),\n                                         [](ll   a, Pair b) { return a\
    \ * b.second + b.first; },  // upd\n                                         [](ll\
    \   a, ll   b) { return min(a, b); },  // cmb\n                              \
    \           [](Pair a, Pair b) { return make_pair(a.first * b.second + b.first,\
    \ a.second & b.second); },  // lzy\n                                         [](Pair\
    \ a, int  x) { return a; }); // acc\n\n    seg.update(0, N, make_pair(0, 0));\n\
    \    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin\
    \ >> query_type;\n        if(query_type == 0) {\n            int s, t, x; cin\
    \ >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n            seg.update(s,\
    \ t, make_pair(x, 1));\n        }\n        if(query_type == 1) {\n           \
    \ int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n   \
    \         cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on May 28, 2019\nvoid DSL_2_H_pair() {\n    int N,\
    \ Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair = pair<ll,\
    \ ll>;\n    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 0),\n\
    \                                       [](ll a, Pair b) {\n                 \
    \                            if(b.second == 1) {\n                           \
    \                      return b.first;\n                                     \
    \        }\n                                             else {\n            \
    \                                     return a + b.first;\n                  \
    \                           }\n                                         },  //\
    \ upd\n                                       [](ll a, ll  b) { return min(a,\
    \ b); },  // cmb\n                                       [](Pair a, Pair b) {\n\
    \                                           if(a.second == 0 and b.second == 0)\
    \ {\n                                               return make_pair(a.first +\
    \ b.first, 0LL);\n                                           }\n             \
    \                              if(a.second == 0 and b.second == 1) {\n       \
    \                                        return b;\n                         \
    \                  }\n                                           if(a.second ==\
    \ 1 and b.second == 0) {\n                                               return\
    \ make_pair(a.first + b.first, 1LL);\n                                       \
    \    }\n                                           if(a.second == 1 and b.second\
    \ == 1) {\n                                               return b;\n        \
    \                                   }\n                                      \
    \ },\n                                       [](Pair a, int x) { return a;   \
    \      }); // acc\n    \n    int indexed = 0;\n    seg.update(0, N, make_pair(0,\
    \ 1));\n    for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n\
    \        if(query_type == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n\
    \            s -= indexed, t -= indexed;\n            seg.update(s, t, make_pair(x,\
    \ 0));\n        }\n        if(query_type == 1) {\n            int s, t; cin >>\
    \ s >> t; t++;\n            s -= indexed; t -= indexed;\n            cout << seg.query(s,\
    \ t) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n// Verified\
    \ on May 28, 2019\nvoid DSL_2_I() {\n    int N, Q; cin >> N >> Q;\n    using ll\
    \ = long long int;\n    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,\n        \
    \                               [](ll a, ll  b) { return b;     },  // upd\n \
    \                                      [](ll a, ll  b) { return a + b; },  //\
    \ cmb\n                                       [](ll a, ll  b) { return b;    \
    \ },  // lzy\n                                       [](ll a, int x) { return\
    \ a * x; }); // acc\n    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n\
    \        int query_type; cin >> query_type;\n        if(query_type == 0) {\n \
    \           int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t\
    \ -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s, t; cin >> s >> t; t++;\n            s -= indexed;\
    \ t -= indexed;\n            cout << seg.query(s, t) << endl;\n        }\n   \
    \     // seg.dump();\n    }    \n}\n\n// TLE\nvoid ABC128_E() {\n    const int\
    \ RANGE = 1 << 30;\n    int N, Q; cin >> N >> Q;\n\n    DynamicLazySegmentTree<int,\
    \ int> seg(RANGE, INT_MAX, INT_MAX,\n                                        \
    \ [](int a, int b) { return min(a, b); },\n                                  \
    \       [](int a, int b) { return min(a, b); },\n                            \
    \             [](int a, int b) { return min(a, b); },\n                      \
    \                   [](int a, int b) { return a; });\n\n    for(int i=0; i<N;\
    \ i++) {\n        int s, t, x; cin >> s >> t >> x;\n        s = max(0, s-x), t\
    \ = max(0, t-x);\n        seg.update(s, t, x);\n    }\n    for(int i=0; i<Q; i++)\
    \ {\n        int x; cin >> x;\n        int res = seg.query(x, x+1);\n        if(res\
    \ == INT_MAX) cout << -1 << endl;\n        else cout << res << endl;\n    }\n\
    }\n\nint main() {\n    // DSL_2_D();\n    // DSL_2_E();\n    // DSL_2_F();\n \
    \   // DSL_2_G();\n    DSL_2_H_simple();\n    // DSL_2_H_pair();\n    // DSL_2_I();\n\
    \    // ABC128_E();\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <algorithm>\n#include <climits>\n\
    #include <functional>\nusing namespace std;\n#include \"../strc_021_dynamic_lazy_segtree.cpp\"\
    \n\n// Verified on May 28, 2019\nvoid DSL_2_D() {\n    int N, Q; cin >> N >> Q;\n\
    \    DynamicLazySegmentTree<int, int> seg(N, INT_MAX, INT_MAX,\n             \
    \                            [](int a, int b) { return b; },\n               \
    \                          [](int a, int b) { return min(a, b); },\n         \
    \                                [](int a, int b) { return b; },\n           \
    \                              [](int a, int b) { return a; });\n\n    int indexed\
    \ = 0;\n    for(int i=0; i<Q; i++) {\n        int q; cin >> q;\n        if(q ==\
    \ 0) {\n            int s, t, x; cin >> s >> t >> x;\n            s -= indexed;\
    \ t -= indexed; t++;\n            seg.update(s, t, x);\n        }\n        if(q\
    \ == 1) {\n            int k; cin >> k;\n            k -= indexed;\n         \
    \   cout << seg.query(k, k+1) << endl;\n        }\n    }\n}\n\n// Verified on\
    \ May 28, 2019\nvoid DSL_2_E() {\n    int N, Q; cin >> N >> Q;\n    DynamicLazySegmentTree<int,\
    \ int> seg(N, 0, 0,\n                                         [](int a, int b)\
    \ { return a + b; },  // upd\n                                         [](int\
    \ a, int b) { return a + b; },  // cmb\n                                     \
    \    [](int a, int b) { return a + b; },  // lzy\n                           \
    \              [](int a, int x) { return a * x; }); // acc\n    \n    int indexed\
    \ = 1;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n\
    \        if(query_type == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n\
    \            s -= indexed, t -= indexed;\n            seg.update(s, t, x);\n \
    \       }\n        if(query_type == 1) {\n            int s; cin >> s;\n     \
    \       s -= indexed;\n            cout << seg.query(s, s+1) << endl;\n      \
    \  }\n        // seg.dump();\n    }    \n}\n\n// Verified on May 28, 2019\nvoid\
    \ DSL_2_F() {\n    int N, Q; cin >> N >> Q;\n    DynamicLazySegmentTree<int, int>\
    \ seg(N, INT_MAX, 0,\n                                         [](int a, int b)\
    \ { return b;         },  // upd\n                                         [](int\
    \ a, int b) { return min(a, b); },  // cmb\n                                 \
    \        [](int a, int b) { return b;         },  // lzy\n                   \
    \                      [](int a, int x) { return a;         }); // acc\n    \n\
    \    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin\
    \ >> query_type;\n        if(query_type == 0) {\n            int s, t, x; cin\
    \ >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n            seg.update(s,\
    \ t, x);\n        }\n        if(query_type == 1) {\n            int s, t; cin\
    \ >> s >> t; t++;\n            s -= indexed; t -= indexed;\n            cout <<\
    \ seg.query(s, t) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n\
    // Verified on May 28, 2019\nvoid DSL_2_G() {\n    int N, Q; cin >> N >> Q;\n\
    \    using ll = long long int;\n    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,\n\
    \                                       [](ll a, ll  b) { return a + b; },  //\
    \ upd\n                                       [](ll a, ll  b) { return a + b;\
    \ },  // cmb\n                                       [](ll a, ll  b) { return\
    \ a + b; },  // lzy\n                                       [](ll a, int x) {\
    \ return a * x; }); // acc\n    \n    int indexed = 1;\n    for(int i=0; i<Q;\
    \ i++) {\n        int query_type; cin >> query_type;\n        if(query_type ==\
    \ 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed,\
    \ t -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s, t; cin >> s >> t; t++;\n            s -= indexed;\
    \ t -= indexed;\n            cout << seg.query(s, t) << endl;\n        }\n   \
    \     // seg.dump();\n    }    \n}\n\n// Verified on Apr 27, 2019\nvoid DSL_2_H_simple()\
    \ {\n    int N, Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair\
    \ = pair<ll, ll>;\n    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0,\
    \ 1),\n                                         [](ll   a, Pair b) { return a\
    \ * b.second + b.first; },  // upd\n                                         [](ll\
    \   a, ll   b) { return min(a, b); },  // cmb\n                              \
    \           [](Pair a, Pair b) { return make_pair(a.first * b.second + b.first,\
    \ a.second & b.second); },  // lzy\n                                         [](Pair\
    \ a, int  x) { return a; }); // acc\n\n    seg.update(0, N, make_pair(0, 0));\n\
    \    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n        int query_type; cin\
    \ >> query_type;\n        if(query_type == 0) {\n            int s, t, x; cin\
    \ >> s >> t >> x; t++;\n            s -= indexed, t -= indexed;\n            seg.update(s,\
    \ t, make_pair(x, 1));\n        }\n        if(query_type == 1) {\n           \
    \ int s, t; cin >> s >> t; t++;\n            s -= indexed; t -= indexed;\n   \
    \         cout << seg.query(s, t) << endl;\n        }\n        // seg.dump();\n\
    \    }    \n}\n\n// Verified on May 28, 2019\nvoid DSL_2_H_pair() {\n    int N,\
    \ Q; cin >> N >> Q;\n    using ll = long long int;\n    using Pair = pair<ll,\
    \ ll>;\n    DynamicLazySegmentTree<ll, Pair> seg(N, INT_MAX, make_pair(0, 0),\n\
    \                                       [](ll a, Pair b) {\n                 \
    \                            if(b.second == 1) {\n                           \
    \                      return b.first;\n                                     \
    \        }\n                                             else {\n            \
    \                                     return a + b.first;\n                  \
    \                           }\n                                         },  //\
    \ upd\n                                       [](ll a, ll  b) { return min(a,\
    \ b); },  // cmb\n                                       [](Pair a, Pair b) {\n\
    \                                           if(a.second == 0 and b.second == 0)\
    \ {\n                                               return make_pair(a.first +\
    \ b.first, 0LL);\n                                           }\n             \
    \                              if(a.second == 0 and b.second == 1) {\n       \
    \                                        return b;\n                         \
    \                  }\n                                           if(a.second ==\
    \ 1 and b.second == 0) {\n                                               return\
    \ make_pair(a.first + b.first, 1LL);\n                                       \
    \    }\n                                           if(a.second == 1 and b.second\
    \ == 1) {\n                                               return b;\n        \
    \                                   }\n                                      \
    \ },\n                                       [](Pair a, int x) { return a;   \
    \      }); // acc\n    \n    int indexed = 0;\n    seg.update(0, N, make_pair(0,\
    \ 1));\n    for(int i=0; i<Q; i++) {\n        int query_type; cin >> query_type;\n\
    \        if(query_type == 0) {\n            int s, t, x; cin >> s >> t >> x; t++;\n\
    \            s -= indexed, t -= indexed;\n            seg.update(s, t, make_pair(x,\
    \ 0));\n        }\n        if(query_type == 1) {\n            int s, t; cin >>\
    \ s >> t; t++;\n            s -= indexed; t -= indexed;\n            cout << seg.query(s,\
    \ t) << endl;\n        }\n        // seg.dump();\n    }    \n}\n\n// Verified\
    \ on May 28, 2019\nvoid DSL_2_I() {\n    int N, Q; cin >> N >> Q;\n    using ll\
    \ = long long int;\n    DynamicLazySegmentTree<ll, ll> seg(N, 0, 0,\n        \
    \                               [](ll a, ll  b) { return b;     },  // upd\n \
    \                                      [](ll a, ll  b) { return a + b; },  //\
    \ cmb\n                                       [](ll a, ll  b) { return b;    \
    \ },  // lzy\n                                       [](ll a, int x) { return\
    \ a * x; }); // acc\n    \n    int indexed = 0;\n    for(int i=0; i<Q; i++) {\n\
    \        int query_type; cin >> query_type;\n        if(query_type == 0) {\n \
    \           int s, t, x; cin >> s >> t >> x; t++;\n            s -= indexed, t\
    \ -= indexed;\n            seg.update(s, t, x);\n        }\n        if(query_type\
    \ == 1) {\n            int s, t; cin >> s >> t; t++;\n            s -= indexed;\
    \ t -= indexed;\n            cout << seg.query(s, t) << endl;\n        }\n   \
    \     // seg.dump();\n    }    \n}\n\n// TLE\nvoid ABC128_E() {\n    const int\
    \ RANGE = 1 << 30;\n    int N, Q; cin >> N >> Q;\n\n    DynamicLazySegmentTree<int,\
    \ int> seg(RANGE, INT_MAX, INT_MAX,\n                                        \
    \ [](int a, int b) { return min(a, b); },\n                                  \
    \       [](int a, int b) { return min(a, b); },\n                            \
    \             [](int a, int b) { return min(a, b); },\n                      \
    \                   [](int a, int b) { return a; });\n\n    for(int i=0; i<N;\
    \ i++) {\n        int s, t, x; cin >> s >> t >> x;\n        s = max(0, s-x), t\
    \ = max(0, t-x);\n        seg.update(s, t, x);\n    }\n    for(int i=0; i<Q; i++)\
    \ {\n        int x; cin >> x;\n        int res = seg.query(x, x+1);\n        if(res\
    \ == INT_MAX) cout << -1 << endl;\n        else cout << res << endl;\n    }\n\
    }\n\nint main() {\n    // DSL_2_D();\n    // DSL_2_E();\n    // DSL_2_F();\n \
    \   // DSL_2_G();\n    DSL_2_H_simple();\n    // DSL_2_H_pair();\n    // DSL_2_I();\n\
    \    // ABC128_E();\n    return 0;\n}\n"
  dependsOn:
  - structure/strc_021_dynamic_lazy_segtree.cpp
  isVerificationFile: false
  path: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
  requiredBy: []
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
layout: document
redirect_from:
- /library/structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
- /library/structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp.html
title: structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp
---
