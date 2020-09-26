---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"dp/dp_003_histogram.cpp\"\n// \u9577\u3055 N \u306E\u30D2\
    \u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u9577\u65B9\u5F62\u9818\u57DF\u6700\u5927\
    \n// Verified: AOJ DPL_3_C: Largest Rectangle in a Histogram\n\nint histArea(vector<int>\
    \ h) {\n    // \u756A\u5175\n    int N = h.size();\n    h.push_back(0); N++;\n\
    \n    // height, position\n    int ans = 0;\n    stack<pii> S;\n    rep(i,0,N+1)\
    \ {\n        if(S.empty()) S.push(pii(h[i], i));\n\n        if     (S.top().first\
    \ < h[i])\n            S.push(pii(h[i], i));\n        else if(S.top().first >\
    \ h[i]) {\n            int lastpos = 0;\n            while(!S.empty() && S.top().first\
    \ >= h[i]) {\n                lastpos = S.top().second;\n                chmax(ans,\
    \ S.top().first * (i-lastpos));\n                S.pop();\n            }\n   \
    \         S.push(pii(h[i], lastpos));\n        }\n    }\n    return ans;\n}\n"
  code: "// \u9577\u3055 N \u306E\u30D2\u30B9\u30C8\u30B0\u30E9\u30E0\u306E\u9577\u65B9\
    \u5F62\u9818\u57DF\u6700\u5927\n// Verified: AOJ DPL_3_C: Largest Rectangle in\
    \ a Histogram\n\nint histArea(vector<int> h) {\n    // \u756A\u5175\n    int N\
    \ = h.size();\n    h.push_back(0); N++;\n\n    // height, position\n    int ans\
    \ = 0;\n    stack<pii> S;\n    rep(i,0,N+1) {\n        if(S.empty()) S.push(pii(h[i],\
    \ i));\n\n        if     (S.top().first < h[i])\n            S.push(pii(h[i],\
    \ i));\n        else if(S.top().first > h[i]) {\n            int lastpos = 0;\n\
    \            while(!S.empty() && S.top().first >= h[i]) {\n                lastpos\
    \ = S.top().second;\n                chmax(ans, S.top().first * (i-lastpos));\n\
    \                S.pop();\n            }\n            S.push(pii(h[i], lastpos));\n\
    \        }\n    }\n    return ans;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/dp_003_histogram.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/dp_003_histogram.cpp
layout: document
redirect_from:
- /library/dp/dp_003_histogram.cpp
- /library/dp/dp_003_histogram.cpp.html
title: dp/dp_003_histogram.cpp
---
