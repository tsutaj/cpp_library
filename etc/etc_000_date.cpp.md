---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"etc/etc_000_date.cpp\"\n// \u3088\u304F\u4F7F\u3046\u914D\
    \u5217\r\nstring dayname[] = {\"\u65E5\u66DC\u65E5\", \"\u6708\u66DC\u65E5\",\
    \ \"\u706B\u66DC\u65E5\", \"\u6C34\u66DC\u65E5\", \"\u6728\u66DC\u65E5\", \"\u91D1\
    \u66DC\u65E5\", \"\u571F\u66DC\u65E5\"};\r\nstring dayname[] = {\"\u65E5\", \"\
    \u6708\", \"\u706B\", \"\u6C34\", \"\u6728\", \"\u91D1\", \"\u571F\"};\r\nstring\
    \ dayname[] = {\"Sunday\", \"Monday\", \"Tuesday\", \"Wednesday\", \"Thursday\"\
    , \"Friday\", \"Saturday\"};\r\nstring dayname[] = {\"Sun\", \"Mon\", \"Tue\"\
    , \"Wed\", \"Thu\", \"Fri\", \"Sat\"};\r\n\r\nint daynum[] = {31, 28, 31, 30,\
    \ 31, 30, 31, 31, 30, 31, 30, 31};\r\n\r\n// \u5E74\u6708\u65E5\u306E\u60C5\u5831\
    \u304B\u3089\u66DC\u65E5\u3092\u6C42\u3081\u308B (\u30C4\u30A7\u30E9\u30FC\u306E\
    \u516C\u5F0F\u3001 Zeller's congruence)\r\nint dayOfTheWeek( int y, int m, int\
    \ d ) {\r\n    if( m < 3 ) {\r\n        y--; m += 12;\r\n    }\r\n    return (\
    \ y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d ) % 7;\r\n}\r\n\r\n// \u5099\u8003\
    \ ... \u6570\u5B57\u3068\u66DC\u65E5\u306E\u95A2\u4FC2\u4E00\u89A7\r\n// 0 ...\
    \ \u65E5\u66DC\u65E5\r\n// 1 ... \u6708\u66DC\u65E5\r\n// 2 ... \u706B\u66DC\u65E5\
    \r\n// 3 ... \u6C34\u66DC\u65E5\r\n// 4 ... \u6728\u66DC\u65E5\r\n// 5 ... \u91D1\
    \u66DC\u65E5\r\n// 6 ... \u571F\u66DC\u65E5\r\n\r\n// \u3046\u308B\u3046\u5E74\
    \u3067\u3042\u308B\u304B\u3069\u3046\u304B\u3092\u5224\u5B9A\u3059\u308B (Verified:\
    \ ARC002 A\u554F\u984C)\r\nbool isLeapYear( int y ) {\r\n    if     (y % 400 ==\
    \ 0) return true;\r\n    else if(y % 100 == 0) return false;\r\n    else if(y\
    \ % 4   == 0) return true;\r\n    else                  return false;\r\n}\r\n\
    \r\n// 1\u65E5\u305A\u3064\u5168\u63A2\u7D22\u3059\u308B (Verified: ARC002 B\u554F\
    \u984C)\r\n// \u6CE8\u610F: \u914D\u5217 daynum \u3068 \u95A2\u6570 isLeapYear\
    \ \u304C\u5FC5\u8981\u3067\u3059\r\nvoid BForceDate(int y, int m, int d) {\r\n\
    \    if(\u51E6\u7406\u3092\u5B9F\u884C) return;\r\n    \r\n    if(d >= daynum[m-1])\
    \ {\r\n        if(m == 12) BForceDate(y+1, 1, 1);\r\n        else if(m == 2) {\r\
    \n            if(isLeapYear(y) && d == 28) BForceDate(y, m, d+1);\r\n        \
    \    else BForceDate(y, m+1, 1);\r\n        }\r\n        else BForceDate(y, m+1,\
    \ 1);\r\n    }\r\n    else BForceDate(y, m, d+1);\r\n}\n"
  code: "// \u3088\u304F\u4F7F\u3046\u914D\u5217\r\nstring dayname[] = {\"\u65E5\u66DC\
    \u65E5\", \"\u6708\u66DC\u65E5\", \"\u706B\u66DC\u65E5\", \"\u6C34\u66DC\u65E5\
    \", \"\u6728\u66DC\u65E5\", \"\u91D1\u66DC\u65E5\", \"\u571F\u66DC\u65E5\"};\r\
    \nstring dayname[] = {\"\u65E5\", \"\u6708\", \"\u706B\", \"\u6C34\", \"\u6728\
    \", \"\u91D1\", \"\u571F\"};\r\nstring dayname[] = {\"Sunday\", \"Monday\", \"\
    Tuesday\", \"Wednesday\", \"Thursday\", \"Friday\", \"Saturday\"};\r\nstring dayname[]\
    \ = {\"Sun\", \"Mon\", \"Tue\", \"Wed\", \"Thu\", \"Fri\", \"Sat\"};\r\n\r\nint\
    \ daynum[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};\r\n\r\n// \u5E74\
    \u6708\u65E5\u306E\u60C5\u5831\u304B\u3089\u66DC\u65E5\u3092\u6C42\u3081\u308B\
    \ (\u30C4\u30A7\u30E9\u30FC\u306E\u516C\u5F0F\u3001 Zeller's congruence)\r\nint\
    \ dayOfTheWeek( int y, int m, int d ) {\r\n    if( m < 3 ) {\r\n        y--; m\
    \ += 12;\r\n    }\r\n    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d\
    \ ) % 7;\r\n}\r\n\r\n// \u5099\u8003 ... \u6570\u5B57\u3068\u66DC\u65E5\u306E\u95A2\
    \u4FC2\u4E00\u89A7\r\n// 0 ... \u65E5\u66DC\u65E5\r\n// 1 ... \u6708\u66DC\u65E5\
    \r\n// 2 ... \u706B\u66DC\u65E5\r\n// 3 ... \u6C34\u66DC\u65E5\r\n// 4 ... \u6728\
    \u66DC\u65E5\r\n// 5 ... \u91D1\u66DC\u65E5\r\n// 6 ... \u571F\u66DC\u65E5\r\n\
    \r\n// \u3046\u308B\u3046\u5E74\u3067\u3042\u308B\u304B\u3069\u3046\u304B\u3092\
    \u5224\u5B9A\u3059\u308B (Verified: ARC002 A\u554F\u984C)\r\nbool isLeapYear(\
    \ int y ) {\r\n    if     (y % 400 == 0) return true;\r\n    else if(y % 100 ==\
    \ 0) return false;\r\n    else if(y % 4   == 0) return true;\r\n    else     \
    \             return false;\r\n}\r\n\r\n// 1\u65E5\u305A\u3064\u5168\u63A2\u7D22\
    \u3059\u308B (Verified: ARC002 B\u554F\u984C)\r\n// \u6CE8\u610F: \u914D\u5217\
    \ daynum \u3068 \u95A2\u6570 isLeapYear \u304C\u5FC5\u8981\u3067\u3059\r\nvoid\
    \ BForceDate(int y, int m, int d) {\r\n    if(\u51E6\u7406\u3092\u5B9F\u884C)\
    \ return;\r\n    \r\n    if(d >= daynum[m-1]) {\r\n        if(m == 12) BForceDate(y+1,\
    \ 1, 1);\r\n        else if(m == 2) {\r\n            if(isLeapYear(y) && d ==\
    \ 28) BForceDate(y, m, d+1);\r\n            else BForceDate(y, m+1, 1);\r\n  \
    \      }\r\n        else BForceDate(y, m+1, 1);\r\n    }\r\n    else BForceDate(y,\
    \ m, d+1);\r\n}"
  dependsOn: []
  isVerificationFile: false
  path: etc/etc_000_date.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: etc/etc_000_date.cpp
layout: document
redirect_from:
- /library/etc/etc_000_date.cpp
- /library/etc/etc_000_date.cpp.html
title: etc/etc_000_date.cpp
---
