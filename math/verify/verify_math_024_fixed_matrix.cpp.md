---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  - icon: ':warning:'
    path: math/math_024_fixed_matrix.cpp
    title: math/math_024_fixed_matrix.cpp
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
  bundledCode: "#line 1 \"math/verify/verify_math_024_fixed_matrix.cpp\"\n#include\
    \ <iostream>\n#include <cstdio>\n#include <valarray>\n#include <vector>\n#include\
    \ <functional>\nusing namespace std;\n#line 1 \"math/math_024_fixed_matrix.cpp\"\
    \n// \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n\n// \u6F14\u7B97\u5B50: \u8907\
    \u5408\u4EE3\u5165 (+=, -=), \u5358\u9805 (-), \u4E8C\u9805 (+, -, *, ==)\n//\
    \ eigen(N): N*N \u5358\u4F4D\u884C\u5217\u3092\u8FD4\u3059\n// pow(mat, k): mat\
    \ \u306E k \u4E57\u3092\u8FD4\u3059\n\ntemplate <typename T, int h, int w>\nstruct\
    \ FixedMatrix {\n    using array_type = array<T, h * w>;\n    array_type mat;\n\
    \n    FixedMatrix(T val = T(0)) { mat.fill(val); }\n    \n    const T& at(int\
    \ i, int j) const { return mat[i*w + j]; }\n    T& at(int i, int j) { return mat[i*w\
    \ + j]; }\n\n    FixedMatrix<T, h, w> &operator+=(const FixedMatrix<T, h, w>&\
    \ rhs) {\n        for(size_t i=0; i<h; i++) {\n            for(size_t j=0; j<w;\
    \ j++) {\n                this->at(i, j) += rhs.at(i, j);\n            }\n   \
    \     }\n        return *this;\n    }\n\n    FixedMatrix<T, h, w> operator-()\
    \ const {\n        FixedMatrix<T, h, w> res(*this);\n        for(size_t i=0; i<h;\
    \ i++) {\n            for(size_t j=0; j<w; j++) {\n                res.at(i, j)\
    \ *= T(-1);\n            }\n        }\n        return res;\n    }\n\n    FixedMatrix<T,\
    \ h, w> &operator-=(const FixedMatrix<T, h, w>& rhs) {\n        return (FixedMatrix<T,\
    \ h, w>(*this) += -rhs);\n    }\n\n    template <int wr>\n    FixedMatrix<T, h,\
    \ wr> operator*(const FixedMatrix<T, w, wr>& rhs) {\n        size_t H = h, W =\
    \ wr, C = w;\n        FixedMatrix<T, h, wr> res;\n        for(size_t i=0; i<H;\
    \ i++) {\n            for(size_t j=0; j<W; j++) {\n                for(size_t\
    \ k=0; k<C; k++) {\n                    res.at(i, j) += this->at(i, k) * rhs.at(k,\
    \ j);\n                }\n            }\n        }\n        return res;\n    }\n\
    \n    FixedMatrix<T, h, w> operator+(const FixedMatrix<T, h, w>& rhs) {\n    \
    \    return (FixedMatrix<T, h, w>(*this) += rhs);\n    }\n\n    FixedMatrix<T,\
    \ h, w> operator-(const FixedMatrix<T, h, w> &rhs) {\n        return (FixedMatrix<T,\
    \ h, w>(*this) -= rhs);\n    }\n\n    bool operator==(const FixedMatrix<T, h,\
    \ w> &rhs) const {\n        return this->mat == rhs.mat;\n    }\n    bool operator!=(const\
    \ FixedMatrix<T, h, w> &rhs) const {\n        return !(*this == rhs);\n    }\n\
    };\n\ntemplate <typename T, int h, int w>\nFixedMatrix<T, h, w> eigen() {\n  \
    \  FixedMatrix<T, h, w> res(0);\n    for(size_t i=0; i<h; i++) res.at(i, i) =\
    \ T(1);\n    return res;\n}\n\ntemplate <typename T, int h, int w>\nFixedMatrix<T,\
    \ h, w> pow(FixedMatrix<T, h, w> mat, long long int k) {\n    FixedMatrix<T, h,\
    \ w> res = eigen<T, h, w>();\n    for(; k>0; k>>=1) {\n        if(k & 1) res =\
    \ res * mat;\n        mat = mat * mat;\n    }\n    return res;\n}\n\ntemplate\
    \ <typename T, int h, int w>\nostream& operator<< (ostream& out, FixedMatrix<T,\
    \ h, w> mat) {\n    int H = mat.h, W = mat.w;\n    out << \"[\" << endl;\n   \
    \ for(int i=0; i<H; i++) {\n        out << \"  [ \";\n        for(int j=0; j<W;\
    \ j++) out << mat.at(i, j) << \" \";\n        out << \"]\" << endl;\n    }\n \
    \   out << \"]\" << endl;\n    return out;\n}\n#line 1 \"math/math_017_modint.cpp\"\
    \n// ModInt begin\r\n\r\nusing ll = long long;\r\ntemplate<ll mod>\r\nstruct ModInt\
    \ {\r\n    ll v;\r\n    ll mod_pow(ll x, ll n) const {\r\n        return (!n)\
    \ ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;\r\n    }\r\n    ModInt(ll\
    \ a = 0) : v((a %= mod) < 0 ? a + mod : a) {}\r\n    ModInt operator+ ( const\
    \ ModInt& b ) const {\r\n        return (v + b.v >= mod ? ModInt(v + b.v - mod)\
    \ : ModInt(v + b.v));\r\n    }\r\n    ModInt operator- () const {\r\n        return\
    \ ModInt(-v);\r\n    }\r\n    ModInt operator- ( const ModInt& b ) const {\r\n\
    \        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));\r\n \
    \   }\r\n    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}\r\
    \n    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2))\
    \ % mod;}\r\n    \r\n    bool operator== ( const ModInt &b ) const {return v ==\
    \ b.v;}\r\n    bool operator!= ( const ModInt &b ) const {return !(*this == b);\
    \ }\r\n    ModInt& operator+= ( const ModInt &b ) {\r\n        v += b.v;\r\n \
    \       if(v >= mod) v -= mod;\r\n        return *this;\r\n    }\r\n    ModInt&\
    \ operator-= ( const ModInt &b ) {\r\n        v -= b.v;\r\n        if(v < 0) v\
    \ += mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator*= ( const\
    \ ModInt &b ) {\r\n        (v *= b.v) %= mod;\r\n        return *this;\r\n   \
    \ }\r\n    ModInt& operator/= ( const ModInt &b ) {\r\n        (v *= mod_pow(b.v,\
    \ mod-2)) %= mod;\r\n        return *this;\r\n    }\r\n    ModInt pow(ll x) {\
    \ return ModInt(mod_pow(v, x)); }\r\n    // operator int() const { return int(v);\
    \ }\r\n    // operator long long int() const { return v; }\r\n};\r\n\r\ntemplate<ll\
    \ mod>\r\nModInt<mod> pow(ModInt<mod> n, ll k) {\r\n    return ModInt<mod>(n.mod_pow(n.v,\
    \ k));\r\n}\r\n\r\ntemplate<ll mod>\r\nostream& operator<< (ostream& out, ModInt<mod>\
    \ a) {return out << a.v;}\r\ntemplate<ll mod>\r\nistream& operator>> (istream&\
    \ in, ModInt<mod>& a) {\r\n    in >> a.v;\r\n    return in;\r\n}\r\n\r\n// ModInt\
    \ end\r\n#line 1 \"structure/strc_009_abst_lazy_segtree.cpp\"\n// @category \u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728 (Segment Tree)\n// @title \u9045\u5EF6\u4F1D\u64AD\
    \u30BB\u30B0\u30E1\u30F3\u30C8\u6728 (Lazy Segment Tree)\ntemplate <typename MonoidType,\
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
    \       fprintf(stderr, \"\\n\");\n    }\n};\n#line 10 \"math/verify/verify_math_024_fixed_matrix.cpp\"\
    \n\nvoid CF373_div2_E() {\n    using mint = ModInt<1000000007>;\n    using Mat\
    \ = FixedMatrix<mint, 2, 2>;\n    using Vec = FixedMatrix<mint, 2, 1>;\n \n  \
    \  auto f = [](Vec a, Mat b) { return b * a; };\n    auto g = [](Vec a, Vec b)\
    \ {\n        return a + b;\n    };\n    auto h = [](Mat a, Mat b) {\n        return\
    \ a * b;\n    };\n    auto p = [](Mat a, int x) {\n        return a;\n    };\n\
    \ \n    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;\n    Mat E1 = eigen<mint, 2,\
    \ 2>();\n        \n    Mat fib;\n    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0)\
    \ = 1;\n    fib.at(1, 1) = 0;\n    \n    Vec vec;\n    vec.at(0, 0) = 1, vec.at(1,\
    \ 0) = 0;\n    \n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    vector<Vec> matrices(N);\n\
    \    for(int i=0; i<N; i++) {\n        int v; scanf(\"%d\", &v);\n        Mat\
    \ pow_fib = pow(fib, v - 1);\n        matrices[i] = pow_fib * vec;\n    }\n  \
    \  \n    LazySegmentTree<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);\n   \
    \ \n    while(Q--) {\n        int type; scanf(\"%d\", &type);\n        if(type\
    \ == 1) {\n            int l, r, x; scanf(\"%d%d%d\", &l, &r, &x); l--;\n    \
    \        Mat pow_fib = pow(fib, x);\n            seg.update(l, r, pow_fib);\n\
    \        }\n        if(type == 2) {\n            int l, r; scanf(\"%d%d\", &l,\
    \ &r); l--;\n            auto res = seg.query(l, r);\n            printf(\"%lld\\\
    n\", res.at(0, 0).v);\n        }\n    }\n}\n\nint main() {\n    CF373_div2_E();\n\
    }\n"
  code: "#include <iostream>\n#include <cstdio>\n#include <valarray>\n#include <vector>\n\
    #include <functional>\nusing namespace std;\n#include \"../math_024_fixed_matrix.cpp\"\
    \n#include \"../math_017_modint.cpp\"\n#include \"../../structure/strc_009_abst_lazy_segtree.cpp\"\
    \n\nvoid CF373_div2_E() {\n    using mint = ModInt<1000000007>;\n    using Mat\
    \ = FixedMatrix<mint, 2, 2>;\n    using Vec = FixedMatrix<mint, 2, 1>;\n \n  \
    \  auto f = [](Vec a, Mat b) { return b * a; };\n    auto g = [](Vec a, Vec b)\
    \ {\n        return a + b;\n    };\n    auto h = [](Mat a, Mat b) {\n        return\
    \ a * b;\n    };\n    auto p = [](Mat a, int x) {\n        return a;\n    };\n\
    \ \n    Vec E0; E0.at(0, 0) = 0, E0.at(1, 0) = 0;\n    Mat E1 = eigen<mint, 2,\
    \ 2>();\n        \n    Mat fib;\n    fib.at(0, 0) = fib.at(0, 1) = fib.at(1, 0)\
    \ = 1;\n    fib.at(1, 1) = 0;\n    \n    Vec vec;\n    vec.at(0, 0) = 1, vec.at(1,\
    \ 0) = 0;\n    \n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    vector<Vec> matrices(N);\n\
    \    for(int i=0; i<N; i++) {\n        int v; scanf(\"%d\", &v);\n        Mat\
    \ pow_fib = pow(fib, v - 1);\n        matrices[i] = pow_fib * vec;\n    }\n  \
    \  \n    LazySegmentTree<Vec, Mat> seg(N, E0, E1, f, g, h, p, matrices);\n   \
    \ \n    while(Q--) {\n        int type; scanf(\"%d\", &type);\n        if(type\
    \ == 1) {\n            int l, r, x; scanf(\"%d%d%d\", &l, &r, &x); l--;\n    \
    \        Mat pow_fib = pow(fib, x);\n            seg.update(l, r, pow_fib);\n\
    \        }\n        if(type == 2) {\n            int l, r; scanf(\"%d%d\", &l,\
    \ &r); l--;\n            auto res = seg.query(l, r);\n            printf(\"%lld\\\
    n\", res.at(0, 0).v);\n        }\n    }\n}\n\nint main() {\n    CF373_div2_E();\n\
    }\n"
  dependsOn:
  - math/math_024_fixed_matrix.cpp
  - math/math_017_modint.cpp
  - structure/strc_009_abst_lazy_segtree.cpp
  isVerificationFile: false
  path: math/verify/verify_math_024_fixed_matrix.cpp
  requiredBy: []
  timestamp: '2020-01-06 07:57:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/verify/verify_math_024_fixed_matrix.cpp
layout: document
redirect_from:
- /library/math/verify/verify_math_024_fixed_matrix.cpp
- /library/math/verify/verify_math_024_fixed_matrix.cpp.html
title: math/verify/verify_math_024_fixed_matrix.cpp
---
