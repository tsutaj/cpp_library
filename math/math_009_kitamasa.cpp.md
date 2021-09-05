---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/math_009_kitamasa.cpp\"\n// Kitamasa \u6CD5 (M \u9805\
    \u6F38\u5316\u5F0F\u306E K \u9805\u76EE\u3092 O(M^2 log K) \u3067\u6C42\u3081\u308B\
    )\nconst int LOG_K = 60;\ntemplate <typename Type>\nstruct Kitamasa{\n    int\
    \ M; // \u521D\u9805\u306E\u6570\n    vector<Type> coefficient, first_term; //\
    \ \u4FC2\u6570\u30FB\u521D\u9805\n    vector< vector<Type> > log_table;\n    Type\
    \ zero, one;\n\n    // \u521D\u9805\u3068\u305D\u306E\u4FC2\u6570\u30010 (\u548C\
    \u306E\u5358\u4F4D\u5143) \u3068 1 (\u7A4D\u306E\u5358\u4F4D\u5143) \u306E\u5B9A\
    \u7FA9\n    Kitamasa(vector<Type> given_co, vector<Type> given_ft, Type given_z,\
    \ Type given_o) {\n        assert(given_co.size() == given_ft.size());\n     \
    \   coefficient = first_term = vector<Type>(1);\n        M = (int)given_ft.size();\n\
    \        copy(given_co.begin(), given_co.end(), back_inserter(coefficient));\n\
    \        copy(given_ft.begin(), given_ft.end(), back_inserter(first_term));\n\
    \        zero = given_z, one = given_o;\n\n        log_table = vector< vector<Type>\
    \ >(LOG_K, vector<Type>(M+1, zero));\n        log_table[0][1] = one;\n       \
    \ for(int i=1; i<LOG_K; i++) {\n            log_table[i] = add(log_table[i-1],\
    \ log_table[i-1]);\n        }\n    }\n\n    vector<Type> shrink(vector<Type> vec)\
    \ {\n        vector<Type> ret_vec(M+1);\n        for(int i=2*M; i>=M+1; i--) {\n\
    \            for(int k=1; k<=M; k++) {\n                vec[i-k] = vec[i-k] +\
    \ (coefficient[k] * vec[i]);\n            }\n        }\n        for(int i=1; i<=M;\
    \ i++) {\n            ret_vec[i] = vec[i];\n        }\n        return ret_vec;\n\
    \    }\n\n    vector<Type> add(const vector<Type> &a, const vector<Type> &b) {\n\
    \        assert(a.size() == M+1 && b.size() == M+1);\n        vector<Type> ret_vec(2*M+1);\n\
    \        for(int i=1; i<=M; i++) {\n            for(int j=1; j<=M; j++) {\n  \
    \              ret_vec[i+j] = ret_vec[i+j] + (a[i] * b[j]);\n            }\n \
    \       }\n        return shrink(ret_vec);\n    }\n\n    // K \u9805\u76EE (1-indexed)\
    \ \u3092\u6C42\u3081\u308B\n    Type get_value(ll K) {\n        K--; // K \u4E57\
    \u3092\u30011 \u4E57\u3068 (K-1) \u4E57\u306B\u5206\u3051\u3066\u51E6\u7406\n\
    \        vector<Type> vec = log_table[0];\n        for(int i=0; K>0; i++, K>>=1)\
    \ {\n            if(K & 1) {\n                vec = add(vec, log_table[i]);\n\
    \            }\n        }\n\n        Type ret_val = zero;\n        for(int i=1;\
    \ i<=M; i++) {\n            ret_val = ret_val + (vec[i] * first_term[i]);\n  \
    \      }\n        return ret_val;\n    }\n};\n\n// \u7A81\u3063\u8FBC\u3080\u69CB\
    \u9020\u4F53\u306E\u4F8B\n// =, +, * \u3092\u5B9A\u7FA9\u3057\u3001\u306A\u304A\
    \u304B\u3064\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3092\u5FC5\u8981\u3068\u3059\
    \u308B\nstruct Number {\n    ll num;\n    Number() {num = 0;}\n    Number(ll a)\
    \ : num(a) {}\n    ll operator=(const Number &b) {\n        return num = b.num;\n\
    \    }\n    ll operator+(const Number &b) const {\n        return (num + b.num)\
    \ % MOD;\n    }\n    ll operator*(const Number &b) const {\n        return (num\
    \ * b.num) % MOD;\n    }\n};\n\nsigned main() {\n    int K, N; cin >> K >> N;\n\
    \    vector<Number> co(K, Number(1)), val(K, Number(1));\n    Kitamasa<Number>\
    \ kt(co, val, Number(0), Number(1));\n    cout << kt.get_value(N).num << endl;\n\
    \    return 0;\n}\n"
  code: "// Kitamasa \u6CD5 (M \u9805\u6F38\u5316\u5F0F\u306E K \u9805\u76EE\u3092\
    \ O(M^2 log K) \u3067\u6C42\u3081\u308B)\nconst int LOG_K = 60;\ntemplate <typename\
    \ Type>\nstruct Kitamasa{\n    int M; // \u521D\u9805\u306E\u6570\n    vector<Type>\
    \ coefficient, first_term; // \u4FC2\u6570\u30FB\u521D\u9805\n    vector< vector<Type>\
    \ > log_table;\n    Type zero, one;\n\n    // \u521D\u9805\u3068\u305D\u306E\u4FC2\
    \u6570\u30010 (\u548C\u306E\u5358\u4F4D\u5143) \u3068 1 (\u7A4D\u306E\u5358\u4F4D\
    \u5143) \u306E\u5B9A\u7FA9\n    Kitamasa(vector<Type> given_co, vector<Type> given_ft,\
    \ Type given_z, Type given_o) {\n        assert(given_co.size() == given_ft.size());\n\
    \        coefficient = first_term = vector<Type>(1);\n        M = (int)given_ft.size();\n\
    \        copy(given_co.begin(), given_co.end(), back_inserter(coefficient));\n\
    \        copy(given_ft.begin(), given_ft.end(), back_inserter(first_term));\n\
    \        zero = given_z, one = given_o;\n\n        log_table = vector< vector<Type>\
    \ >(LOG_K, vector<Type>(M+1, zero));\n        log_table[0][1] = one;\n       \
    \ for(int i=1; i<LOG_K; i++) {\n            log_table[i] = add(log_table[i-1],\
    \ log_table[i-1]);\n        }\n    }\n\n    vector<Type> shrink(vector<Type> vec)\
    \ {\n        vector<Type> ret_vec(M+1);\n        for(int i=2*M; i>=M+1; i--) {\n\
    \            for(int k=1; k<=M; k++) {\n                vec[i-k] = vec[i-k] +\
    \ (coefficient[k] * vec[i]);\n            }\n        }\n        for(int i=1; i<=M;\
    \ i++) {\n            ret_vec[i] = vec[i];\n        }\n        return ret_vec;\n\
    \    }\n\n    vector<Type> add(const vector<Type> &a, const vector<Type> &b) {\n\
    \        assert(a.size() == M+1 && b.size() == M+1);\n        vector<Type> ret_vec(2*M+1);\n\
    \        for(int i=1; i<=M; i++) {\n            for(int j=1; j<=M; j++) {\n  \
    \              ret_vec[i+j] = ret_vec[i+j] + (a[i] * b[j]);\n            }\n \
    \       }\n        return shrink(ret_vec);\n    }\n\n    // K \u9805\u76EE (1-indexed)\
    \ \u3092\u6C42\u3081\u308B\n    Type get_value(ll K) {\n        K--; // K \u4E57\
    \u3092\u30011 \u4E57\u3068 (K-1) \u4E57\u306B\u5206\u3051\u3066\u51E6\u7406\n\
    \        vector<Type> vec = log_table[0];\n        for(int i=0; K>0; i++, K>>=1)\
    \ {\n            if(K & 1) {\n                vec = add(vec, log_table[i]);\n\
    \            }\n        }\n\n        Type ret_val = zero;\n        for(int i=1;\
    \ i<=M; i++) {\n            ret_val = ret_val + (vec[i] * first_term[i]);\n  \
    \      }\n        return ret_val;\n    }\n};\n\n// \u7A81\u3063\u8FBC\u3080\u69CB\
    \u9020\u4F53\u306E\u4F8B\n// =, +, * \u3092\u5B9A\u7FA9\u3057\u3001\u306A\u304A\
    \u304B\u3064\u30C7\u30D5\u30A9\u30EB\u30C8\u5024\u3092\u5FC5\u8981\u3068\u3059\
    \u308B\nstruct Number {\n    ll num;\n    Number() {num = 0;}\n    Number(ll a)\
    \ : num(a) {}\n    ll operator=(const Number &b) {\n        return num = b.num;\n\
    \    }\n    ll operator+(const Number &b) const {\n        return (num + b.num)\
    \ % MOD;\n    }\n    ll operator*(const Number &b) const {\n        return (num\
    \ * b.num) % MOD;\n    }\n};\n\nsigned main() {\n    int K, N; cin >> K >> N;\n\
    \    vector<Number> co(K, Number(1)), val(K, Number(1));\n    Kitamasa<Number>\
    \ kt(co, val, Number(0), Number(1));\n    cout << kt.get_value(N).num << endl;\n\
    \    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/math_009_kitamasa.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_009_kitamasa.cpp
layout: document
redirect_from:
- /library/math/math_009_kitamasa.cpp
- /library/math/math_009_kitamasa.cpp.html
title: math/math_009_kitamasa.cpp
---
