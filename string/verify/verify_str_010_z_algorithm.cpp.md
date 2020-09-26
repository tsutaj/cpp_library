---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: string/str_010_z_algorithm.cpp
    title: string/str_010_z_algorithm.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/verify/verify_str_010_z_algorithm.cpp\"\n#include\
    \ <string>\n#include <cstdio>\n#include <iostream>\n#include <vector>\nusing namespace\
    \ std;\n#line 1 \"string/str_010_z_algorithm.cpp\"\n// Z-algorithm\n// \u5404\
    \ Suffix \u3068\u5143\u306E\u6587\u5B57\u5217\u3068\u306E LCP \u3092\u6C42\u3081\
    \u308B\ntemplate <typename ArrayType>\nstruct Z_algorithm {\n    ArrayType v;\n\
    \    vector<int> Z;\n\n    void build() {\n        int N = v.size(), i, j;\n \
    \       Z = vector<int>(N);\n\n        for(i=1,j=0; i<N; i++) {\n            int\
    \ l = i - j;\n            if(i + Z[l] < j + Z[j]) {\n                Z[i] = Z[l];\n\
    \            }\n            else {\n                int k = max(0, j + Z[j] -\
    \ i);\n                while(i + k < N and v[k] == v[i+k]) k++;\n            \
    \    Z[i] = k;\n                j = i;\n            }\n        }\n        Z[0]\
    \ = N;\n    }\n\n    Z_algorithm(ArrayType v_) : v(v_) {\n        build();\n \
    \   }\n\n    // idx \u304B\u3089\u5207\u308A\u51FA\u3057\u305F Suffix \u3068\u6587\
    \u5B57\u5217\u5168\u4F53\u3068\u306E LCP\n    int get_lcp(int idx) {\n       \
    \ return Z[idx];\n    }\n};\n#line 7 \"string/verify/verify_str_010_z_algorithm.cpp\"\
    \n\nvoid tiny_test() {\n    string s; cin >> s;\n    Z_algorithm<string> za(s);\n\
    \    for(size_t i=0; i<s.length(); i++) {\n        fprintf(stderr, \"Z[%zu] =\
    \ %d\\n\", i, za.get_lcp(i));\n    }\n}\n\nvoid yuki_599() {\n    const int MOD\
    \ = 1000000007;\n    string s; cin >> s; int N = s.size();\n    vector<int> dp(N\
    \ + 1);\n\n    dp[0] = 1;\n    for(int i=0; i<N; i++) {\n        int l = i, r\
    \ = N - i, len = N - 2*i;\n        if(len <= 0) continue;\n        Z_algorithm<string>\
    \ za(s.substr(l, len));\n        for(int j=1; j<=len; j++) {\n            // [ll,\
    \ lr)\n            int ll = 0, lr = j;\n            // [rl, rr)\n            int\
    \ rl = len - j, rr = len;\n\n            if(lr > rl) break;\n            if(za.get_lcp(rl)\
    \ >= j) {\n                (dp[i+j] += dp[i]) %= MOD;\n            }\n       \
    \ }\n    }\n\n    int ans = 0;\n    for(int i=0; i<=N; i++) (ans += dp[i]) %=\
    \ MOD;\n    cout << ans << endl;\n}\n\nint main() {\n    // tiny_test();\n   \
    \ yuki_599();\n}\n"
  code: "#include <string>\n#include <cstdio>\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n#include \"../str_010_z_algorithm.cpp\"\n\nvoid tiny_test()\
    \ {\n    string s; cin >> s;\n    Z_algorithm<string> za(s);\n    for(size_t i=0;\
    \ i<s.length(); i++) {\n        fprintf(stderr, \"Z[%zu] = %d\\n\", i, za.get_lcp(i));\n\
    \    }\n}\n\nvoid yuki_599() {\n    const int MOD = 1000000007;\n    string s;\
    \ cin >> s; int N = s.size();\n    vector<int> dp(N + 1);\n\n    dp[0] = 1;\n\
    \    for(int i=0; i<N; i++) {\n        int l = i, r = N - i, len = N - 2*i;\n\
    \        if(len <= 0) continue;\n        Z_algorithm<string> za(s.substr(l, len));\n\
    \        for(int j=1; j<=len; j++) {\n            // [ll, lr)\n            int\
    \ ll = 0, lr = j;\n            // [rl, rr)\n            int rl = len - j, rr =\
    \ len;\n\n            if(lr > rl) break;\n            if(za.get_lcp(rl) >= j)\
    \ {\n                (dp[i+j] += dp[i]) %= MOD;\n            }\n        }\n  \
    \  }\n\n    int ans = 0;\n    for(int i=0; i<=N; i++) (ans += dp[i]) %= MOD;\n\
    \    cout << ans << endl;\n}\n\nint main() {\n    // tiny_test();\n    yuki_599();\n\
    }\n"
  dependsOn:
  - string/str_010_z_algorithm.cpp
  isVerificationFile: false
  path: string/verify/verify_str_010_z_algorithm.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/verify/verify_str_010_z_algorithm.cpp
layout: document
redirect_from:
- /library/string/verify/verify_str_010_z_algorithm.cpp
- /library/string/verify/verify_str_010_z_algorithm.cpp.html
title: string/verify/verify_str_010_z_algorithm.cpp
---
