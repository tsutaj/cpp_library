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
  bundledCode: "#line 1 \"marathon/rand_xorshift.cpp\"\n#include <cstdint>\n\nstruct\
    \ Rand {\n private:\n  constexpr static double R = 1.0 / 0xffffffff;\n  uint64_t\
    \ x;\n\n public:\n  Rand(uint64_t seed = 88172645463325252ull) : x(seed) {}\n\n\
    \  inline uint64_t nextULong() {  // [0, 2^64)\n    x ^= x << 7ull;\n    x ^=\
    \ x >> 9ull;\n    return x;\n  }\n\n  inline uint32_t nextUInt(uint32_t r) { \
    \ // [0, r)\n    return ((nextULong() >> 32ull) * r) >> 32ull;\n  }\n\n  inline\
    \ uint32_t nextUInt(uint32_t l, uint32_t r) {  // [l, r)\n    return l + nextUInt(r\
    \ - l);\n  }\n\n  inline double nextDouble() {  // [0.0, 1.0]\n    return ((uint32_t)nextULong())\
    \ * R;\n  }\n};\n"
  code: "#include <cstdint>\n\nstruct Rand {\n private:\n  constexpr static double\
    \ R = 1.0 / 0xffffffff;\n  uint64_t x;\n\n public:\n  Rand(uint64_t seed = 88172645463325252ull)\
    \ : x(seed) {}\n\n  inline uint64_t nextULong() {  // [0, 2^64)\n    x ^= x <<\
    \ 7ull;\n    x ^= x >> 9ull;\n    return x;\n  }\n\n  inline uint32_t nextUInt(uint32_t\
    \ r) {  // [0, r)\n    return ((nextULong() >> 32ull) * r) >> 32ull;\n  }\n\n\
    \  inline uint32_t nextUInt(uint32_t l, uint32_t r) {  // [l, r)\n    return l\
    \ + nextUInt(r - l);\n  }\n\n  inline double nextDouble() {  // [0.0, 1.0]\n \
    \   return ((uint32_t)nextULong()) * R;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/rand_xorshift.cpp
  requiredBy: []
  timestamp: '2025-11-25 00:44:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/rand_xorshift.cpp
layout: document
redirect_from:
- /library/marathon/rand_xorshift.cpp
- /library/marathon/rand_xorshift.cpp.html
title: marathon/rand_xorshift.cpp
---
