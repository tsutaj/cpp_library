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
  bundledCode: "#line 1 \"string/str_001_technique.cpp\"\n// \u5927\u4E8B\u306A\u30C6\
    \u30AF\u30CB\u30C3\u30AF\u96C6\uFF01\n\n// int \u3084 double \u304B\u3089 string\
    \ \u306B\u5909\u63DB\u3059\u308B\n// \u2192 C++11 \u6A19\u6E96\u30E9\u30A4\u30D6\
    \u30E9\u30EA\u306B\u306F std::to_string \u95A2\u6570\u304C\u5B58\u5728\u3059\u308B\
    \u3002\nto_string(42); // result: \"42\"\n\n// string \u304B\u3089 int \u306B\u5909\
    \u63DB\u3059\u308B\n// \u2192 atoi \u95A2\u6570\u306F char \u578B\u306E\u6587\u5B57\
    \u5217\u3092 int \u306B\u5909\u63DB\u3059\u308B\n// \u2192 string \u3092 char\
    \ \u578B\u306E\u6587\u5B57\u5217\u306B\u5909\u63DB\u3057\u3066\u304B\u3089 int\
    \ \u306B\u3057\u3088\u3046\n// \u2192 atoi(s.c_str()) \u306E\u3088\u3046\u306B\
    \u66F8\u3051\u3070\u826F\u3044\natoi(\"42\".c_str()); // result: 42\n// \u30D5\
    \u30A1\u30DF\u30EA\u30FC\u3068\u3057\u3066\u3001atof, atol \u304C\u3042\u308B\u305E\
    \uFF01\n\n// string \u304B\u3089 int \u306B\u5909\u63DB\u3059\u308B \u305D\u306E\
    2\n// \u2192 \u5B9F\u306F stoi \u95A2\u6570\u3092\u4F7F\u3048\u3070 string \u578B\
    \u304B\u3089\u305D\u306E\u307E\u307E\u5909\u63DB\u3067\u304D\u308B\n// \u2192\
    \ \u3057\u304B\u3082\u57FA\u6570\u6307\u5B9A\u53EF\u80FD\uFF01\nint stoi(const\
    \ string& str, size_t* idx = nullptr, int base = 10);\nstoi(\"10\", nullptr, 16);\
    \ // result: 16\nstoi(\"10\", nullptr, 2); // result: 2\n// \u30D5\u30A1\u30DF\
    \u30EA\u30FC\u3068\u3057\u3066\u3001stol, stoll, stoul, stoull, stof, stod, stold\
    \ \u304C\u3042\u308B\u305E\uFF01\n\n// char\u578B\u6587\u5B57\u5217 \u304B\u3089\
    \ string \u306B\u5909\u63DB\u3059\u308B \u2192 \u5B9F\u306F\u305D\u306E\u307E\u307E\
    \u3044\u3051\u308B\nchar str[10];\nstring s = str; // \u3053\u308C\u3067 OK\n\n\
    // \u6587\u5B57\u3092\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u306B\n// \u2192 \u8D77\
    \u70B9\u3068\u3057\u305F\u3044\u6587\u5B57\u3067\u5F15\u3051\u3070\u826F\u3044\
    \n// \u2192 \u4F8B\u3048\u3070\u3001'A' \u3092\u8D77\u70B9\u3068\u3057\u3066\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u3092\u4ED8\u3051\u305F\u3044\u5834\u5408\u306F\
    \ s[i] - 'A' \u3068\u3059\u308B\nint idx1 = 'C' - 'A'; // result: 2\nint idx2\
    \ = 'b' - 'a'; // result: 1\nint idx3 = '9' - '0'; // result: 9\n\n// generate\
    \ binary string (not less than k-digit)\nstring to_binString(int n, int k) {\n\
    \    string ret = \"\";\n    while(n) ret += ('0' + (n&1)), n >>= 1;\n    while(ret.length()\
    \ < k) ret += '0';\n    reverse(ret.begin(), ret.end());\n    return ret;\n}\n"
  code: "// \u5927\u4E8B\u306A\u30C6\u30AF\u30CB\u30C3\u30AF\u96C6\uFF01\n\n// int\
    \ \u3084 double \u304B\u3089 string \u306B\u5909\u63DB\u3059\u308B\n// \u2192\
    \ C++11 \u6A19\u6E96\u30E9\u30A4\u30D6\u30E9\u30EA\u306B\u306F std::to_string\
    \ \u95A2\u6570\u304C\u5B58\u5728\u3059\u308B\u3002\nto_string(42); // result:\
    \ \"42\"\n\n// string \u304B\u3089 int \u306B\u5909\u63DB\u3059\u308B\n// \u2192\
    \ atoi \u95A2\u6570\u306F char \u578B\u306E\u6587\u5B57\u5217\u3092 int \u306B\
    \u5909\u63DB\u3059\u308B\n// \u2192 string \u3092 char \u578B\u306E\u6587\u5B57\
    \u5217\u306B\u5909\u63DB\u3057\u3066\u304B\u3089 int \u306B\u3057\u3088\u3046\n\
    // \u2192 atoi(s.c_str()) \u306E\u3088\u3046\u306B\u66F8\u3051\u3070\u826F\u3044\
    \natoi(\"42\".c_str()); // result: 42\n// \u30D5\u30A1\u30DF\u30EA\u30FC\u3068\
    \u3057\u3066\u3001atof, atol \u304C\u3042\u308B\u305E\uFF01\n\n// string \u304B\
    \u3089 int \u306B\u5909\u63DB\u3059\u308B \u305D\u306E2\n// \u2192 \u5B9F\u306F\
    \ stoi \u95A2\u6570\u3092\u4F7F\u3048\u3070 string \u578B\u304B\u3089\u305D\u306E\
    \u307E\u307E\u5909\u63DB\u3067\u304D\u308B\n// \u2192 \u3057\u304B\u3082\u57FA\
    \u6570\u6307\u5B9A\u53EF\u80FD\uFF01\nint stoi(const string& str, size_t* idx\
    \ = nullptr, int base = 10);\nstoi(\"10\", nullptr, 16); // result: 16\nstoi(\"\
    10\", nullptr, 2); // result: 2\n// \u30D5\u30A1\u30DF\u30EA\u30FC\u3068\u3057\
    \u3066\u3001stol, stoll, stoul, stoull, stof, stod, stold \u304C\u3042\u308B\u305E\
    \uFF01\n\n// char\u578B\u6587\u5B57\u5217 \u304B\u3089 string \u306B\u5909\u63DB\
    \u3059\u308B \u2192 \u5B9F\u306F\u305D\u306E\u307E\u307E\u3044\u3051\u308B\nchar\
    \ str[10];\nstring s = str; // \u3053\u308C\u3067 OK\n\n// \u6587\u5B57\u3092\u30A4\
    \u30F3\u30C7\u30C3\u30AF\u30B9\u306B\n// \u2192 \u8D77\u70B9\u3068\u3057\u305F\
    \u3044\u6587\u5B57\u3067\u5F15\u3051\u3070\u826F\u3044\n// \u2192 \u4F8B\u3048\
    \u3070\u3001'A' \u3092\u8D77\u70B9\u3068\u3057\u3066\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3092\u4ED8\u3051\u305F\u3044\u5834\u5408\u306F s[i] - 'A' \u3068\u3059\
    \u308B\nint idx1 = 'C' - 'A'; // result: 2\nint idx2 = 'b' - 'a'; // result: 1\n\
    int idx3 = '9' - '0'; // result: 9\n\n// generate binary string (not less than\
    \ k-digit)\nstring to_binString(int n, int k) {\n    string ret = \"\";\n    while(n)\
    \ ret += ('0' + (n&1)), n >>= 1;\n    while(ret.length() < k) ret += '0';\n  \
    \  reverse(ret.begin(), ret.end());\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/str_001_technique.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_001_technique.cpp
layout: document
redirect_from:
- /library/string/str_001_technique.cpp
- /library/string/str_001_technique.cpp.html
title: string/str_001_technique.cpp
---
