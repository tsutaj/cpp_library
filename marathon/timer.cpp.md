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
  bundledCode: "#line 1 \"marathon/timer.cpp\"\nclass Timer {\n    chrono::high_resolution_clock::time_point\
    \ start, end;\n    double limit;\n\npublic:\n    Timer() {\n        start = chrono::high_resolution_clock::now();\n\
    \    }\n    Timer(double l) {\n        start = chrono::high_resolution_clock::now();\n\
    \        limit = l;\n    }\n\n    double getTime() {\n        end = chrono::high_resolution_clock::now();\n\
    \        return chrono::duration<double>(end - start).count();\n    }\n\n    bool\
    \ isTimeOver() {\n        if (getTime() > limit) {\n            return true;\n\
    \        }\n        return false;\n    }\n\n    double getLimit() { return limit;\
    \ }\n    void setLimit(double l) {\n        limit = l;\n    }\n    void setStart()\
    \ { start = chrono::high_resolution_clock::now(); }\n};\n"
  code: "class Timer {\n    chrono::high_resolution_clock::time_point start, end;\n\
    \    double limit;\n\npublic:\n    Timer() {\n        start = chrono::high_resolution_clock::now();\n\
    \    }\n    Timer(double l) {\n        start = chrono::high_resolution_clock::now();\n\
    \        limit = l;\n    }\n\n    double getTime() {\n        end = chrono::high_resolution_clock::now();\n\
    \        return chrono::duration<double>(end - start).count();\n    }\n\n    bool\
    \ isTimeOver() {\n        if (getTime() > limit) {\n            return true;\n\
    \        }\n        return false;\n    }\n\n    double getLimit() { return limit;\
    \ }\n    void setLimit(double l) {\n        limit = l;\n    }\n    void setStart()\
    \ { start = chrono::high_resolution_clock::now(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/timer.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/timer.cpp
layout: document
redirect_from:
- /library/marathon/timer.cpp
- /library/marathon/timer.cpp.html
title: marathon/timer.cpp
---
