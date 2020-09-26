---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/str_009_manacher.cpp
    title: string/str_009_manacher.cpp
  - icon: ':warning:'
    path: structure/strc_008_abst_segtree.cpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/verify/verify_str_009_manacher.cpp\"\n#include <string>\n\
    #include <vector>\n#include <algorithm>\n#include <iostream>\n#include <cstdio>\n\
    using namespace std;\n#line 1 \"string/str_009_manacher.cpp\"\n// Manacher \u306E\
    \u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\n// \u5404\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \u306B\u3064\u3044\u3066\u56DE\u6587\u534A\u5F84\u3092\u7DDA\u5F62\u6642\u9593\
    \u3067\u6C42\u3081\u308B\n// \u30C0\u30DF\u30FC\u6587\u5B57\u3092\u631F\u3080\u3053\
    \u3068\u306B\u3088\u308A\u5076\u6570\u9577\u56DE\u6587\u306B\u3082\u5BFE\u5FDC\
    \ntemplate <typename ArrayType, typename ElemType>\nstruct Manacher {\n    ArrayType\
    \ v;\n    ElemType dummy;\n    vector<int> rad;\n\n    ArrayType insert_dummy_elem(ArrayType\
    \ vec, ElemType dummy) {\n        int N = vec.size();\n        ArrayType res(2*N\
    \ - 1, dummy);\n        for(int i=0; i<N; i++) res[2*i] = vec[i];\n        return\
    \ res;\n    }\n\n    void build() {\n        int N = v.size(), i, j;\n       \
    \ rad = vector<int>(N);\n        for(i=j=0; i<N; ) {\n            while(i-j >=\
    \ 0 and i+j < N and v[i-j] == v[i+j]) j++;\n            rad[i] = j;\n\n      \
    \      int k;\n            for(k=1; i-k >= 0 and rad[i]-k > rad[i-k]; k++) rad[i+k]\
    \ = rad[i-k];\n\n            i += k;\n            j = max(0, j-k);\n        }\n\
    \    }\n\n    Manacher(ArrayType v_, ElemType dummy_) :\n        v(v_), dummy(dummy_)\
    \ {\n        v = insert_dummy_elem(v, dummy);\n        build();\n    }\n\n   \
    \ // idx \u3092\u4E2D\u5FC3\u3068\u3059\u308B\u56DE\u6587\u534A\u5F84 (0-indexed)\n\
    \    int get_rad(int idx) {\n        return (rad[2*idx] + 1) / 2;\n    }\n\n \
    \   // \u90E8\u5206\u6587\u5B57\u5217 [l, r) \u304C\u56DE\u6587\u304B\u3069\u3046\
    \u304B (0-indexed) \n    bool is_palindrome(int l, int r) {\n        if(l == r)\
    \ return true;\n        int idx = l + r - 1, len = r - l;\n        return rad[idx]\
    \ >= len;\n    }\n};\n#line 1 \"structure/strc_008_abst_segtree.cpp\"\n// @category\
    \ \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728 (Segment Tree)\n// \u62BD\u8C61 SegmentTree (0-indexed\u30FB\
    \u4E00\u70B9\u66F4\u65B0\u30FB\u533A\u9593\u53D6\u5F97)\ntemplate <typename MonoidType>\n\
    struct SegmentTree {\n    using Function = function< MonoidType(MonoidType, MonoidType)\
    \ >;\n\n    // node, identity element\n    int n;\n    vector<MonoidType> node;\n\
    \    MonoidType E0;\n\n    // update / combine function\n    Function upd_f, cmb_f;\n\
    \n    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {\n     \
    \   if(v != vector<MonoidType>()) m = v.size();\n        n = 1; while(n < m) n\
    \ *= 2;\n\n        node = vector<MonoidType>(2*n-1, E0);\n        if(v != vector<MonoidType>())\
    \ {\n            for(int i=0; i<m; i++) {\n                node[n-1+i] = v[i];\n\
    \            }\n            for(int i=n-2; i>=0; i--) {\n                node[i]\
    \ = cmb_f(node[2*i+1], node[2*i+2]);\n            }\n        }\n    }\n\n    //\
    \ initialize\n    SegmentTree() {}\n    SegmentTree(int n_, MonoidType E0_,\n\
    \                Function upd_f_, Function cmb_f_,\n                vector<MonoidType>\
    \ v = vector<MonoidType>()) :\n        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {\n\
    \        build(n_, v);\n    }\n\n    // update k-th element (applied value: x)\n\
    \    void update(int k, MonoidType x) {\n        k += n - 1;\n        node[k]\
    \ = upd_f(node[k], x);\n        while(k > 0) {\n            k = (k - 1) / 2;\n\
    \            node[k] = cmb_f(node[2*k+1], node[2*k+2]);\n        }\n    }\n\n\
    \    // range query for [a, b)\n    // \u975E\u518D\u5E30\u306E\u30A2\u30A4\u30C7\
    \u30A2: http://d.hatena.ne.jp/komiyam/20131202/1385992406\n    MonoidType query(int\
    \ a, int b) {\n        MonoidType vl = E0, vr = E0;\n        for(int l=a+n, r=b+n;\
    \ l<r; l>>=1, r>>=1) {\n            if(l & 1) vl = cmb_f(vl, node[(l++)-1]);\n\
    \            if(r & 1) vr = cmb_f(node[(--r)-1], vr);\n        }\n        return\
    \ cmb_f(vl, vr);\n    }\n};\n#line 9 \"string/verify/verify_str_009_manacher.cpp\"\
    \n\nvoid tiny_test_str() {\n    string s; cin >> s;\n    char dummy = '$';\n\n\
    \    Manacher<string, char> man(s, dummy);\n    man.dump();\n}\n\nvoid tiny_test_int()\
    \ {\n    int N; cin >> N;\n    vector<int> v(N);\n    for(int i=0; i<N; i++) cin\
    \ >> v[i];\n    int dummy = 0;\n\n    Manacher< vector<int>, int > man(v, dummy);\n\
    \    man.dump(false);\n}\n\nvoid yuki_464() {\n    string s; cin >> s;\n    int\
    \ N = s.size();\n    Manacher<string, char> man(s, '$');\n\n    long long int\
    \ dp[5010][5] = {};\n    dp[0][0] = 1;\n    for(int i=0; i<N; i++) {\n       \
    \ for(int j=i+1; j<=N; j++) {\n            for(int k=0; k<4; k++) {\n        \
    \        if(k != 2) {\n                    if(!man.is_palindrome(i, j)) continue;\n\
    \                    dp[j][k+1] += dp[i][k];\n                }\n            \
    \    else {\n                    dp[j][k+1] += dp[i][k];\n                }\n\
    \            }\n        }\n    }\n    cout << dp[N][4] << endl;\n}\n\nvoid WUPC2019_E()\
    \ {\n    int N, M; cin >> N >> M;\n    vector<int> row(N), col(M);\n    for(int\
    \ i=0; i<N; i++) {\n        for(int j=0; j<M; j++) {\n            char c; cin\
    \ >> c;\n            if(c == '1') row[i]++, col[j]++;\n        }\n    }\n\n  \
    \  int dummy = -1, ans = 0;\n    Manacher< vector<int>, int > mr(row, dummy),\
    \ mc(col, dummy);\n    for(int i=0; i<N-1; i++) {\n        for(int j=0; j<M-1;\
    \ j++) {\n            bool ok = true;\n            ok &= mr.is_palindrome(0, i+1);\n\
    \            ok &= mr.is_palindrome(i+1, N);\n            ok &= mc.is_palindrome(0,\
    \ j+1);\n            ok &= mc.is_palindrome(j+1, M);\n            if(ok) ans++;\n\
    \        }\n    }\n    cout << ans << endl;\n}\n\nvoid ukuku09_D() {\n    struct\
    \ SegFunc {\n        static int update(int a, int b) { return max(a, b); }\n \
    \       static int combine(int a, int b) { return max(a, b); }\n    };\n    \n\
    \    int N, Q; cin >> N >> Q;\n    string s; cin >> s;\n    Manacher< string,\
    \ char > man(s, '$');\n    SegmentTree< int, SegFunc > seg(N, -1);\n\n    for(int\
    \ i=0; i<N; i++) {\n        int rad = man.get_rad(i);\n        seg.update(i, rad);\n\
    \    }\n    \n    while(Q--) {\n        int ql, qr; cin >> ql >> qr; ql--;\n\n\
    \        int ub = (N + 1) / 2 + 1, lb = -1;\n        while(ub - lb > 1) {\n  \
    \          int mid = (ub + lb) / 2;\n            int l = ql + mid - 1;\n     \
    \       int r = qr - mid + 1;\n\n            bool ok = true;\n            if(l\
    \ >= r) ok = false;\n            else {\n                int val = seg.query(l,\
    \ r);\n                ok = (val >= mid);\n            }\n\n            if(ok)\
    \ lb = mid;\n            else ub = mid;\n        }\n        int ans = lb * 2 -\
    \ 1;\n        cout << ans << endl;\n    }\n}\n\nint main() {\n    // tiny_test_str();\n\
    \    // tiny_test_int();\n    // yuki_464();\n    // WUPC2019_E();\n    ukuku09_D();\n\
    \    return 0;\n}\n"
  code: "#include <string>\n#include <vector>\n#include <algorithm>\n#include <iostream>\n\
    #include <cstdio>\nusing namespace std;\n#include \"../str_009_manacher.cpp\"\n\
    #include \"../../structure/strc_008_abst_segtree.cpp\"\n\nvoid tiny_test_str()\
    \ {\n    string s; cin >> s;\n    char dummy = '$';\n\n    Manacher<string, char>\
    \ man(s, dummy);\n    man.dump();\n}\n\nvoid tiny_test_int() {\n    int N; cin\
    \ >> N;\n    vector<int> v(N);\n    for(int i=0; i<N; i++) cin >> v[i];\n    int\
    \ dummy = 0;\n\n    Manacher< vector<int>, int > man(v, dummy);\n    man.dump(false);\n\
    }\n\nvoid yuki_464() {\n    string s; cin >> s;\n    int N = s.size();\n    Manacher<string,\
    \ char> man(s, '$');\n\n    long long int dp[5010][5] = {};\n    dp[0][0] = 1;\n\
    \    for(int i=0; i<N; i++) {\n        for(int j=i+1; j<=N; j++) {\n         \
    \   for(int k=0; k<4; k++) {\n                if(k != 2) {\n                 \
    \   if(!man.is_palindrome(i, j)) continue;\n                    dp[j][k+1] +=\
    \ dp[i][k];\n                }\n                else {\n                    dp[j][k+1]\
    \ += dp[i][k];\n                }\n            }\n        }\n    }\n    cout <<\
    \ dp[N][4] << endl;\n}\n\nvoid WUPC2019_E() {\n    int N, M; cin >> N >> M;\n\
    \    vector<int> row(N), col(M);\n    for(int i=0; i<N; i++) {\n        for(int\
    \ j=0; j<M; j++) {\n            char c; cin >> c;\n            if(c == '1') row[i]++,\
    \ col[j]++;\n        }\n    }\n\n    int dummy = -1, ans = 0;\n    Manacher< vector<int>,\
    \ int > mr(row, dummy), mc(col, dummy);\n    for(int i=0; i<N-1; i++) {\n    \
    \    for(int j=0; j<M-1; j++) {\n            bool ok = true;\n            ok &=\
    \ mr.is_palindrome(0, i+1);\n            ok &= mr.is_palindrome(i+1, N);\n   \
    \         ok &= mc.is_palindrome(0, j+1);\n            ok &= mc.is_palindrome(j+1,\
    \ M);\n            if(ok) ans++;\n        }\n    }\n    cout << ans << endl;\n\
    }\n\nvoid ukuku09_D() {\n    struct SegFunc {\n        static int update(int a,\
    \ int b) { return max(a, b); }\n        static int combine(int a, int b) { return\
    \ max(a, b); }\n    };\n    \n    int N, Q; cin >> N >> Q;\n    string s; cin\
    \ >> s;\n    Manacher< string, char > man(s, '$');\n    SegmentTree< int, SegFunc\
    \ > seg(N, -1);\n\n    for(int i=0; i<N; i++) {\n        int rad = man.get_rad(i);\n\
    \        seg.update(i, rad);\n    }\n    \n    while(Q--) {\n        int ql, qr;\
    \ cin >> ql >> qr; ql--;\n\n        int ub = (N + 1) / 2 + 1, lb = -1;\n     \
    \   while(ub - lb > 1) {\n            int mid = (ub + lb) / 2;\n            int\
    \ l = ql + mid - 1;\n            int r = qr - mid + 1;\n\n            bool ok\
    \ = true;\n            if(l >= r) ok = false;\n            else {\n          \
    \      int val = seg.query(l, r);\n                ok = (val >= mid);\n      \
    \      }\n\n            if(ok) lb = mid;\n            else ub = mid;\n       \
    \ }\n        int ans = lb * 2 - 1;\n        cout << ans << endl;\n    }\n}\n\n\
    int main() {\n    // tiny_test_str();\n    // tiny_test_int();\n    // yuki_464();\n\
    \    // WUPC2019_E();\n    ukuku09_D();\n    return 0;\n}\n"
  dependsOn:
  - string/str_009_manacher.cpp
  - structure/strc_008_abst_segtree.cpp
  isVerificationFile: false
  path: string/verify/verify_str_009_manacher.cpp
  requiredBy: []
  timestamp: '2019-12-09 17:27:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/verify/verify_str_009_manacher.cpp
layout: document
redirect_from:
- /library/string/verify/verify_str_009_manacher.cpp
- /library/string/verify/verify_str_009_manacher.cpp.html
title: string/verify/verify_str_009_manacher.cpp
---
