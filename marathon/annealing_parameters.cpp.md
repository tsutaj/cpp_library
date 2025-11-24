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
  bundledCode: "#line 1 \"marathon/annealing_parameters.cpp\"\ntemplate <int ITER_PERIOD\
    \ = 1 << 20>\nstruct AnnealingParameters {\n    const double start_temp;\n   \
    \ const double end_temp;\n    double cur_temp;\n    double ln_p[ITER_PERIOD];\n\
    \    AnnealingParameters(double start_temp, double end_temp, Rand& rnd)\n    \
    \    : start_temp(start_temp), end_temp(end_temp), cur_temp(start_temp) {\n  \
    \      for(int i=0; i<ITER_PERIOD; i++) {\n            ln_p[i] = log(rnd.NextDouble());\n\
    \        }\n    }\n\n    inline void update_temp_linear(double ratio) {\n    \
    \    cur_temp = start_temp + (end_temp - start_temp) * ratio;\n    }\n\n    inline\
    \ void update_temp_pow(double ratio) {\n        cur_temp = start_temp * pow(end_temp\
    \ / start_temp, ratio);\n    }\n\n    // p < exp(diff / temp) \u3092\u5909\u5F62\
    \u3059\u308B\u3068\u3001diff > temp * ln_p\n    // diff \u304C\u3053\u306E\u5024\
    \u3092\u8D85\u3048\u3066\u3044\u305F\u3089\u63A1\u7528\u3067\u304D\u308B\n   \
    \ inline bool is_acceptable(int iter, int diff) const {\n        return diff >\
    \ cur_temp * ln_p[iter % ITER_PERIOD];\n    }\n};\n"
  code: "template <int ITER_PERIOD = 1 << 20>\nstruct AnnealingParameters {\n    const\
    \ double start_temp;\n    const double end_temp;\n    double cur_temp;\n    double\
    \ ln_p[ITER_PERIOD];\n    AnnealingParameters(double start_temp, double end_temp,\
    \ Rand& rnd)\n        : start_temp(start_temp), end_temp(end_temp), cur_temp(start_temp)\
    \ {\n        for(int i=0; i<ITER_PERIOD; i++) {\n            ln_p[i] = log(rnd.NextDouble());\n\
    \        }\n    }\n\n    inline void update_temp_linear(double ratio) {\n    \
    \    cur_temp = start_temp + (end_temp - start_temp) * ratio;\n    }\n\n    inline\
    \ void update_temp_pow(double ratio) {\n        cur_temp = start_temp * pow(end_temp\
    \ / start_temp, ratio);\n    }\n\n    // p < exp(diff / temp) \u3092\u5909\u5F62\
    \u3059\u308B\u3068\u3001diff > temp * ln_p\n    // diff \u304C\u3053\u306E\u5024\
    \u3092\u8D85\u3048\u3066\u3044\u305F\u3089\u63A1\u7528\u3067\u304D\u308B\n   \
    \ inline bool is_acceptable(int iter, int diff) const {\n        return diff >\
    \ cur_temp * ln_p[iter % ITER_PERIOD];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/annealing_parameters.cpp
  requiredBy: []
  timestamp: '2025-11-24 22:45:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/annealing_parameters.cpp
layout: document
redirect_from:
- /library/marathon/annealing_parameters.cpp
- /library/marathon/annealing_parameters.cpp.html
title: marathon/annealing_parameters.cpp
---
