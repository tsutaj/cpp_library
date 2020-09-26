---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: math/verify/verify_math_021_crt.cpp
    title: math/verify/verify_math_021_crt.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_021_crt.cpp\"\n// \u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\n// x = b_1 (mod_1), ..., x = b_k (mod_k), ... \u3092\u6E80\u305F\u3059\
    \ x \u3092\n// 0 <= x < lcm(mod_1, mod_2, ..., mod_k, ...) \u306E\u7BC4\u56F2\u3067\
    \u6C42\u3081\u308B\n\ntemplate <typename NumType, NumType LIMIT = NumType(1e10)>\n\
    struct CRT {\n    pair<NumType, NumType> NIL;\n    CRT() : NIL(-1, -1) {}\n  \
    \  \n    NumType extgcd(NumType a, NumType b, NumType &p, NumType &q) {\n    \
    \    if(b == 0) {\n            p = 1, q = 0;\n            return a;\n        }\n\
    \        NumType d = extgcd(b, a%b, q, p);\n        q -= a / b * p;\n        return\
    \ d;\n    }\n\n    pair<NumType, NumType> solve(NumType b1, NumType mod1, NumType\
    \ b2, NumType mod2) {\n        NumType p, q;\n        NumType d = extgcd(mod1,\
    \ mod2, p, q);\n        \n        if((b2 - b1) % d != 0) return NIL;\n       \
    \ NumType s = (b2 - b1) / d;\n        NumType t = (s * p % (mod2 / d));\n\n  \
    \      // get lcm\n        NumType lc = mod1 / d * mod2;\n        NumType so =\
    \ (b1 + mod1 * t) % lc;\n        (so += lc) %= lc;\n        return make_pair(so,\
    \ lc);\n    }\n\n    // m, mod \u306E vector \u3092\u3082\u3089\u3063\u3066\u3001\
    \n    // CRT \u306E\u89E3\u3092 (x, lcm(mod_1, mod_2, ..., mod_k, ...)) \u306E\
    \u5F62\u3067\u8FD4\u3059\n    pair<NumType, NumType> solve(vector<NumType> m,\
    \ vector<NumType> mod) {\n        assert(m.size() == mod.size());\n        NumType\
    \ so = 0, lc = 1;\n        for(size_t i=0; i<m.size(); i++) {\n            tie(so,\
    \ lc) = solve(so, lc, m[i], mod[i]);\n            if(so > LIMIT or so < 0) {\n\
    \                return NIL;\n            }\n        }\n        return make_pair(so,\
    \ lc);\n    }\n};\n"
  code: "// \u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\n// x = b_1 (mod_1), ..., x = b_k\
    \ (mod_k), ... \u3092\u6E80\u305F\u3059 x \u3092\n// 0 <= x < lcm(mod_1, mod_2,\
    \ ..., mod_k, ...) \u306E\u7BC4\u56F2\u3067\u6C42\u3081\u308B\n\ntemplate <typename\
    \ NumType, NumType LIMIT = NumType(1e10)>\nstruct CRT {\n    pair<NumType, NumType>\
    \ NIL;\n    CRT() : NIL(-1, -1) {}\n    \n    NumType extgcd(NumType a, NumType\
    \ b, NumType &p, NumType &q) {\n        if(b == 0) {\n            p = 1, q = 0;\n\
    \            return a;\n        }\n        NumType d = extgcd(b, a%b, q, p);\n\
    \        q -= a / b * p;\n        return d;\n    }\n\n    pair<NumType, NumType>\
    \ solve(NumType b1, NumType mod1, NumType b2, NumType mod2) {\n        NumType\
    \ p, q;\n        NumType d = extgcd(mod1, mod2, p, q);\n        \n        if((b2\
    \ - b1) % d != 0) return NIL;\n        NumType s = (b2 - b1) / d;\n        NumType\
    \ t = (s * p % (mod2 / d));\n\n        // get lcm\n        NumType lc = mod1 /\
    \ d * mod2;\n        NumType so = (b1 + mod1 * t) % lc;\n        (so += lc) %=\
    \ lc;\n        return make_pair(so, lc);\n    }\n\n    // m, mod \u306E vector\
    \ \u3092\u3082\u3089\u3063\u3066\u3001\n    // CRT \u306E\u89E3\u3092 (x, lcm(mod_1,\
    \ mod_2, ..., mod_k, ...)) \u306E\u5F62\u3067\u8FD4\u3059\n    pair<NumType, NumType>\
    \ solve(vector<NumType> m, vector<NumType> mod) {\n        assert(m.size() ==\
    \ mod.size());\n        NumType so = 0, lc = 1;\n        for(size_t i=0; i<m.size();\
    \ i++) {\n            tie(so, lc) = solve(so, lc, m[i], mod[i]);\n           \
    \ if(so > LIMIT or so < 0) {\n                return NIL;\n            }\n   \
    \     }\n        return make_pair(so, lc);\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_021_crt.cpp
  requiredBy:
  - math/verify/verify_math_021_crt.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_021_crt.cpp
layout: document
redirect_from:
- /library/math/math_021_crt.cpp
- /library/math/math_021_crt.cpp.html
title: math/math_021_crt.cpp
---
