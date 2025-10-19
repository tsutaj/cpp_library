---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: marathon/trace.cpp
    title: "Trace\uFF08\u7D4C\u8DEF\u5FA9\u5143\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1227
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1227
  bundledCode: "#line 1 \"verifying_test/AOJ/1227/trace.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1227\"\n\n#include\
    \ <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace std;\n\n\
    #define call_from_test\n#line 1 \"marathon/trace.cpp\"\ntemplate <typename Tp>\n\
    class Trace {\npublic:\n    Trace() = default;\n\n    int add(const Tp& value,\
    \ int parent) {\n        log_.emplace_back(value, parent);\n        return (int)log_.size()\
    \ - 1;\n    }\n\n    vector<Tp> get(int index) const {\n        vector<Tp> result;\n\
    \        while (index >= 0) {\n            result.emplace_back(log_[index].first);\n\
    \            index = log_[index].second;\n        }\n        reverse(result.begin(),\
    \ result.end());\n        return result;\n    }\n\nprivate:\n    vector<pair<Tp,\
    \ int>> log_;\n};\n#line 10 \"verifying_test/AOJ/1227/trace.test.cpp\"\n#undef\
    \ call_from_test\n\nstring char_to_digit = \"22233344455566677778889999\";\n\n\
    int solve_testcases() {\n    int N; cin >> N;\n    if (N == 0) return 1;\n   \
    \ vector<string> words(N);\n    for(auto &e : words) cin >> e;\n    string seq;\
    \ cin >> seq;\n\n    vector<string> word_digits(N);\n    for(int i=0; i<N; i++)\
    \ {\n        string digits = \"\";\n        for(char c : words[i]) {\n       \
    \     digits += char_to_digit[c - 'a'];\n        }\n        word_digits[i] = digits;\n\
    \    }\n    \n    Trace<string> trace;\n    vector<int> terminals;\n    auto go\
    \ = [&](auto &&self, int pos, int id) -> void {\n        if (pos == seq.size())\
    \ {\n            terminals.emplace_back(id);\n            return;\n        }\n\
    \        for(int i=0; i<N; i++) {\n            if (pos + word_digits[i].size()\
    \ > seq.size()) continue;\n            if (seq.substr(pos, word_digits[i].size())\
    \ == word_digits[i]) {\n                int nxt = pos + word_digits[i].size();\n\
    \                self(self, nxt, trace.add(words[i], id));\n            }\n  \
    \      }\n    };\n    go(go, 0, -1);\n    for(int id : terminals) {\n        vector<string>\
    \ words = trace.get(id);\n        for(int i=0; i<(int)words.size(); i++) {\n \
    \           cout << words[i];\n            if (i + 1 < (int)words.size()) cout\
    \ << \" \";\n            else cout << \".\\n\";\n        }\n    }\n    cout <<\
    \ \"--\" << endl;\n    return 0;\n}\n\nint main() {\n    while(!solve_testcases());\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1227\"\
    \n\n#include <iostream>\n#include <vector>\n#include <algorithm>\nusing namespace\
    \ std;\n\n#define call_from_test\n#include \"../../../marathon/trace.cpp\"\n#undef\
    \ call_from_test\n\nstring char_to_digit = \"22233344455566677778889999\";\n\n\
    int solve_testcases() {\n    int N; cin >> N;\n    if (N == 0) return 1;\n   \
    \ vector<string> words(N);\n    for(auto &e : words) cin >> e;\n    string seq;\
    \ cin >> seq;\n\n    vector<string> word_digits(N);\n    for(int i=0; i<N; i++)\
    \ {\n        string digits = \"\";\n        for(char c : words[i]) {\n       \
    \     digits += char_to_digit[c - 'a'];\n        }\n        word_digits[i] = digits;\n\
    \    }\n    \n    Trace<string> trace;\n    vector<int> terminals;\n    auto go\
    \ = [&](auto &&self, int pos, int id) -> void {\n        if (pos == seq.size())\
    \ {\n            terminals.emplace_back(id);\n            return;\n        }\n\
    \        for(int i=0; i<N; i++) {\n            if (pos + word_digits[i].size()\
    \ > seq.size()) continue;\n            if (seq.substr(pos, word_digits[i].size())\
    \ == word_digits[i]) {\n                int nxt = pos + word_digits[i].size();\n\
    \                self(self, nxt, trace.add(words[i], id));\n            }\n  \
    \      }\n    };\n    go(go, 0, -1);\n    for(int id : terminals) {\n        vector<string>\
    \ words = trace.get(id);\n        for(int i=0; i<(int)words.size(); i++) {\n \
    \           cout << words[i];\n            if (i + 1 < (int)words.size()) cout\
    \ << \" \";\n            else cout << \".\\n\";\n        }\n    }\n    cout <<\
    \ \"--\" << endl;\n    return 0;\n}\n\nint main() {\n    while(!solve_testcases());\n\
    \    return 0;\n}\n"
  dependsOn:
  - marathon/trace.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/1227/trace.test.cpp
  requiredBy: []
  timestamp: '2025-10-19 18:29:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifying_test/AOJ/1227/trace.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/1227/trace.test.cpp
- /verify/verifying_test/AOJ/1227/trace.test.cpp.html
title: verifying_test/AOJ/1227/trace.test.cpp
---
