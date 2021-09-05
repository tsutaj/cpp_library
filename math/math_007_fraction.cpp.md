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
  bundledCode: "#line 1 \"math/math_007_fraction.cpp\"\n// fraction library (use C++11)\n\
    struct fraction{\n    // init (nume / deno)\n    int numerator, denominator;\n\
    \    fraction(int i) : numerator(i), denominator(1) {}\n    fraction(int i, int\
    \ j) : numerator(i), denominator(j) {}\n    fraction(string s) {\n        int\
    \ i = s.find('/');\n        if(i != string::npos) {\n            numerator = atoi(s.substr(0,i).c_str());\n\
    \            denominator = atoi(s.substr(i+1).c_str());\n        }\n        else\
    \ {\n            numerator = atoi(s.c_str());\n            denominator = 1;\n\
    \        }\n    }\n\n    fraction fixshape(fraction A) {\n        int p = A.denominator,\
    \ q = A.numerator;\n        if(p < 0) {p *= -1; q *= -1;}\n        int k = gcd(abs(p),\
    \ abs(q));\n        p /= k, q /= k;\n        A.denominator = p, A.numerator =\
    \ q;\n        return A;\n    }\n};\n\n// print fraction\nstring printfrac(fraction\
    \ A, int n) {\n    if(!n) return to_string(A.numerator) + \"/\" + to_string(A.denominator);\n\
    \    else {\n        if(A.denominator == 1) return to_string(A.numerator);\n \
    \       else return printfrac(A, 0);\n    }\n}\n\nstring printfrac(fraction A)\
    \ {\n    if(A.denominator == 1) return to_string(A.numerator);\n    else return\
    \ printfrac(A, 0);\n}\n\nvoid simplify(fraction &A, fraction &B) {\n    int k\
    \ = lcm(A.denominator, B.denominator);\n    A.numerator *= (k / A.denominator);\n\
    \    B.numerator *= (k / B.denominator);\n    A.denominator = k; B.denominator\
    \ = k;\n}\n\n// overloading the arithmetic operators\nfraction operator+(const\
    \ fraction &A, const fraction &B) {\n    int q = lcm(A.denominator, B.denominator);\n\
    \    int p = A.numerator * (q / A.denominator) + B.numerator * (q / B.denominator);\n\
    \    fraction ret = ret.fixshape(fraction(p, q));\n    return ret;\n}\n\nfraction\
    \ operator-(const fraction &A, const fraction &B) {\n    int q = lcm(A.denominator,\
    \ B.denominator);\n    int p = A.numerator * (q / A.denominator) - B.numerator\
    \ * (q / B.denominator);\n    fraction ret = ret.fixshape(fraction(p, q));\n \
    \   return ret;\n}\n\nfraction operator*(const fraction &A, const fraction &B)\
    \ {\n    int p = A.numerator * B.numerator;\n    int q = A.denominator * B.denominator;\n\
    \    int k = gcd(abs(p), abs(q));\n    p /= k, q /= k;\n    fraction ret = ret.fixshape(fraction(p,\
    \ q));\n    return ret;\n}\n\nfraction operator/(const fraction &A, const fraction\
    \ &B) {\n    fraction C = C.fixshape(fraction(B.denominator, B.numerator));\n\
    \    fraction ret = ret.fixshape(A*C);\n    return ret;\n}\n\nbool operator<(const\
    \ fraction &A, const fraction &B) {\n    fraction C = A, D = B;\n    simplify(C,\
    \ D);\n    return C.numerator < D.numerator;\n}\n\nbool operator>(const fraction\
    \ &A, const fraction &B) {\n    fraction C = A, D = B;\n    simplify(C, D);\n\
    \    return C.numerator > D.numerator;\n}\n// fraction library end\n"
  code: "// fraction library (use C++11)\nstruct fraction{\n    // init (nume / deno)\n\
    \    int numerator, denominator;\n    fraction(int i) : numerator(i), denominator(1)\
    \ {}\n    fraction(int i, int j) : numerator(i), denominator(j) {}\n    fraction(string\
    \ s) {\n        int i = s.find('/');\n        if(i != string::npos) {\n      \
    \      numerator = atoi(s.substr(0,i).c_str());\n            denominator = atoi(s.substr(i+1).c_str());\n\
    \        }\n        else {\n            numerator = atoi(s.c_str());\n       \
    \     denominator = 1;\n        }\n    }\n\n    fraction fixshape(fraction A)\
    \ {\n        int p = A.denominator, q = A.numerator;\n        if(p < 0) {p *=\
    \ -1; q *= -1;}\n        int k = gcd(abs(p), abs(q));\n        p /= k, q /= k;\n\
    \        A.denominator = p, A.numerator = q;\n        return A;\n    }\n};\n\n\
    // print fraction\nstring printfrac(fraction A, int n) {\n    if(!n) return to_string(A.numerator)\
    \ + \"/\" + to_string(A.denominator);\n    else {\n        if(A.denominator ==\
    \ 1) return to_string(A.numerator);\n        else return printfrac(A, 0);\n  \
    \  }\n}\n\nstring printfrac(fraction A) {\n    if(A.denominator == 1) return to_string(A.numerator);\n\
    \    else return printfrac(A, 0);\n}\n\nvoid simplify(fraction &A, fraction &B)\
    \ {\n    int k = lcm(A.denominator, B.denominator);\n    A.numerator *= (k / A.denominator);\n\
    \    B.numerator *= (k / B.denominator);\n    A.denominator = k; B.denominator\
    \ = k;\n}\n\n// overloading the arithmetic operators\nfraction operator+(const\
    \ fraction &A, const fraction &B) {\n    int q = lcm(A.denominator, B.denominator);\n\
    \    int p = A.numerator * (q / A.denominator) + B.numerator * (q / B.denominator);\n\
    \    fraction ret = ret.fixshape(fraction(p, q));\n    return ret;\n}\n\nfraction\
    \ operator-(const fraction &A, const fraction &B) {\n    int q = lcm(A.denominator,\
    \ B.denominator);\n    int p = A.numerator * (q / A.denominator) - B.numerator\
    \ * (q / B.denominator);\n    fraction ret = ret.fixshape(fraction(p, q));\n \
    \   return ret;\n}\n\nfraction operator*(const fraction &A, const fraction &B)\
    \ {\n    int p = A.numerator * B.numerator;\n    int q = A.denominator * B.denominator;\n\
    \    int k = gcd(abs(p), abs(q));\n    p /= k, q /= k;\n    fraction ret = ret.fixshape(fraction(p,\
    \ q));\n    return ret;\n}\n\nfraction operator/(const fraction &A, const fraction\
    \ &B) {\n    fraction C = C.fixshape(fraction(B.denominator, B.numerator));\n\
    \    fraction ret = ret.fixshape(A*C);\n    return ret;\n}\n\nbool operator<(const\
    \ fraction &A, const fraction &B) {\n    fraction C = A, D = B;\n    simplify(C,\
    \ D);\n    return C.numerator < D.numerator;\n}\n\nbool operator>(const fraction\
    \ &A, const fraction &B) {\n    fraction C = A, D = B;\n    simplify(C, D);\n\
    \    return C.numerator > D.numerator;\n}\n// fraction library end"
  dependsOn: []
  isVerificationFile: false
  path: math/math_007_fraction.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/math_007_fraction.cpp
layout: document
redirect_from:
- /library/math/math_007_fraction.cpp
- /library/math/math_007_fraction.cpp.html
title: math/math_007_fraction.cpp
---
