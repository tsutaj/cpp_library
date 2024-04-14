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
  bundledCode: "#line 1 \"marathon/rand.cpp\"\n// [lb, ub] \u306E\u9589\u533A\u9593\
    \u5185\u306E\u5024\u3092\u30E9\u30F3\u30C0\u30E0\u306B\u8FD4\u3059\u69CB\u9020\
    \u4F53\n#include <random>\n#include <limits>\n\nstruct Rand {\npublic:\n    Rand()\
    \ = default;\n    Rand(std::mt19937::result_type seed) : eng(seed) {}\n\n    uint32_t\
    \ NextUInt(uint32_t lb, uint32_t ub) {\n        return std::uniform_int_distribution<uint32_t>{lb,\
    \ ub}(eng);\n    }\n    uint32_t NextUInt() {\n        return std::uniform_int_distribution<uint32_t>{0,\
    \ std::numeric_limits<uint32_t>::max()}(eng);\n    }\n\n    int32_t NextInt(int32_t\
    \ lb, int32_t ub) {\n        return std::uniform_int_distribution<int32_t>{lb,\
    \ ub}(eng);\n    }\n    int32_t NextInt() {\n        return std::uniform_int_distribution<int32_t>{0,\
    \ std::numeric_limits<int32_t>::max()}(eng);\n    }\n\n    uint64_t NextULong(uint64_t\
    \ lb, uint64_t ub) {\n        return std::uniform_int_distribution<uint64_t>{lb,\
    \ ub}(eng);\n    }\n    uint64_t NextULong() {\n        return std::uniform_int_distribution<uint64_t>{0,\
    \ std::numeric_limits<uint64_t>::max()}(eng);\n    }\n\n    int64_t NextLong(int64_t\
    \ lb, int64_t ub) {\n        return std::uniform_int_distribution<int64_t>{lb,\
    \ ub}(eng);\n    }\n    int64_t NextLong() {\n        return std::uniform_int_distribution<int64_t>{0,\
    \ std::numeric_limits<int64_t>::max()}(eng);\n    }\n\n    double NextDouble(double\
    \ lb = 0.0, double ub = 1.0) {\n        return std::uniform_real_distribution<double>{lb,\
    \ ub}(eng);\n    }\nprivate:\n    std::mt19937 eng{std::random_device{}()};\n\
    };\n"
  code: "// [lb, ub] \u306E\u9589\u533A\u9593\u5185\u306E\u5024\u3092\u30E9\u30F3\u30C0\
    \u30E0\u306B\u8FD4\u3059\u69CB\u9020\u4F53\n#include <random>\n#include <limits>\n\
    \nstruct Rand {\npublic:\n    Rand() = default;\n    Rand(std::mt19937::result_type\
    \ seed) : eng(seed) {}\n\n    uint32_t NextUInt(uint32_t lb, uint32_t ub) {\n\
    \        return std::uniform_int_distribution<uint32_t>{lb, ub}(eng);\n    }\n\
    \    uint32_t NextUInt() {\n        return std::uniform_int_distribution<uint32_t>{0,\
    \ std::numeric_limits<uint32_t>::max()}(eng);\n    }\n\n    int32_t NextInt(int32_t\
    \ lb, int32_t ub) {\n        return std::uniform_int_distribution<int32_t>{lb,\
    \ ub}(eng);\n    }\n    int32_t NextInt() {\n        return std::uniform_int_distribution<int32_t>{0,\
    \ std::numeric_limits<int32_t>::max()}(eng);\n    }\n\n    uint64_t NextULong(uint64_t\
    \ lb, uint64_t ub) {\n        return std::uniform_int_distribution<uint64_t>{lb,\
    \ ub}(eng);\n    }\n    uint64_t NextULong() {\n        return std::uniform_int_distribution<uint64_t>{0,\
    \ std::numeric_limits<uint64_t>::max()}(eng);\n    }\n\n    int64_t NextLong(int64_t\
    \ lb, int64_t ub) {\n        return std::uniform_int_distribution<int64_t>{lb,\
    \ ub}(eng);\n    }\n    int64_t NextLong() {\n        return std::uniform_int_distribution<int64_t>{0,\
    \ std::numeric_limits<int64_t>::max()}(eng);\n    }\n\n    double NextDouble(double\
    \ lb = 0.0, double ub = 1.0) {\n        return std::uniform_real_distribution<double>{lb,\
    \ ub}(eng);\n    }\nprivate:\n    std::mt19937 eng{std::random_device{}()};\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/rand.cpp
  requiredBy: []
  timestamp: '2024-04-14 15:27:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/rand.cpp
layout: document
redirect_from:
- /library/marathon/rand.cpp
- /library/marathon/rand.cpp.html
title: marathon/rand.cpp
---
