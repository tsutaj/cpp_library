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
  bundledCode: "#line 1 \"graph/graph_013_rootedtreeiso.cpp\"\n// \u6839\u4ED8\u304D\
    \u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\
    \ O(|V|)\n// \u30FB\u8449\u306E\u5024\u3092 1 \u3068\u3059\u308B\n// \u30FB\u89AA\
    \u306F\u5B50\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u7D50\u679C\u3092\u30BD\u30FC\
    \u30C8\u3057\u3066\u8DB3\u3057\u3042\u308F\u305B\u305F\u3082\u306E\u3092\u30CF\
    \u30C3\u30B7\u30E5\u306B\u5165\u308C\u305F\u5024\u3067\u3042\u308B\n// \u30FB\u6839\
    \u306E\u30CF\u30C3\u30B7\u30E5\u5024\u304C\u4E00\u81F4\u3057\u3066\u3044\u308C\
    \u3070\u3001\u6728\u306F\u540C\u578B\u3067\u3042\u308B\n// \u30FB\u6839\u306A\u3057\
    \u6728\u3067\u540C\u578B\u6027\u5224\u5B9A\u3092\u884C\u3046\u306B\u306F\u3001\
    \u6728\u306E\u4E2D\u5FC3\u3092\u6839\u306B\u3057\u3066\u540C\u578B\u6027\u5224\
    \u5B9A\u3092\u884C\u3048\u3070\u826F\u3044\n//   -> \u540C\u578B\u306A\u6728\u3067\
    \u3042\u308C\u3070\u3001\u4E2D\u5FC3\u3092\u6839\u3068\u3057\u3066\u5224\u5B9A\
    \u3057\u3066\u3082\u7D50\u679C\u304C\u540C\u3058\u306A\u306E\u306F\u81EA\u660E\
    \n//   -> \u6728\u306E\u4E2D\u5FC3\u306F\u9AD8\u3005 2 \u500B (\u76F4\u5F84\u304C\
    \u5947\u6570\u9577\u306A\u3089 1 \u500B\u3001\u5076\u6570\u9577\u306A\u3089 2\
    \ \u500B)\n//   -> \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97\u3092\u9AD8\u3005\
    \ 2 * 2 = 4 \u56DE\u3084\u308B\u3060\u3051\u3067\u6E08\u3080\u305F\u3081\u3001\
    \u5341\u5206\u9AD8\u901F\u3067\u3042\u308B\n// \u30FB\u6CE8\u610F: \u6728\u306E\
    \u4E2D\u5FC3\u306E\u500B\u6570\u304C\u4E00\u81F4\u3057\u306A\u3051\u308C\u3070\
    \u540C\u578B\u3067\u306A\u3044\u3053\u3068\u306F\u660E\u3089\u304B\u306A\u306E\
    \u3067\u3001\n//   \u30CF\u30C3\u30B7\u30E5\u306B\u7A81\u3063\u8FBC\u3080\u524D\
    \u306B\u4E2D\u5FC3\u306E\u500B\u6570\u3092\u5148\u306B\u30C1\u30A7\u30C3\u30AF\
    \u3059\u3079\u304D (\u304B\u3082\u3057\u308C\u306A\u3044)\n\nmap<string, ll> HASHMAP;\n\
    ll cntPattern = 1; // you must write in main: cntPattern = 1;\n\ntemplate <typename\
    \ T>\nll getHash(vector< vector< Edge<T> > > &G, int point, int parent = -1) {\n\
    \    // leaf\n    if(G[point].size() == 1 && parent != -1)\n        return HASHMAP[\"\
    0\"] = 1;\n\n    vector<string> rec;\n    for(size_t i=0; i<G[point].size(); i++)\
    \ {\n        int to = G[point][i].to;\n        if(to == parent) continue;\n  \
    \      ll temp = getHash(G, to, point);\n        rec.push_back(to_string(temp));\n\
    \    }\n    sort(rec.begin(), rec.end());\n    string pat = \"\";\n    for(size_t\
    \ i=0; i<rec.size(); i++) pat += rec[i];\n    if(!HASHMAP.count(pat)) HASHMAP[pat]\
    \ = ++cntPattern;\n    return HASHMAP[pat];\n}\n"
  code: "// \u6839\u4ED8\u304D\u6728\u306E\u540C\u578B\u6027\u5224\u5B9A\u30A2\u30EB\
    \u30B4\u30EA\u30BA\u30E0 O(|V|)\n// \u30FB\u8449\u306E\u5024\u3092 1 \u3068\u3059\
    \u308B\n// \u30FB\u89AA\u306F\u5B50\u306E\u30CF\u30C3\u30B7\u30E5\u306E\u7D50\u679C\
    \u3092\u30BD\u30FC\u30C8\u3057\u3066\u8DB3\u3057\u3042\u308F\u305B\u305F\u3082\
    \u306E\u3092\u30CF\u30C3\u30B7\u30E5\u306B\u5165\u308C\u305F\u5024\u3067\u3042\
    \u308B\n// \u30FB\u6839\u306E\u30CF\u30C3\u30B7\u30E5\u5024\u304C\u4E00\u81F4\u3057\
    \u3066\u3044\u308C\u3070\u3001\u6728\u306F\u540C\u578B\u3067\u3042\u308B\n// \u30FB\
    \u6839\u306A\u3057\u6728\u3067\u540C\u578B\u6027\u5224\u5B9A\u3092\u884C\u3046\
    \u306B\u306F\u3001\u6728\u306E\u4E2D\u5FC3\u3092\u6839\u306B\u3057\u3066\u540C\
    \u578B\u6027\u5224\u5B9A\u3092\u884C\u3048\u3070\u826F\u3044\n//   -> \u540C\u578B\
    \u306A\u6728\u3067\u3042\u308C\u3070\u3001\u4E2D\u5FC3\u3092\u6839\u3068\u3057\
    \u3066\u5224\u5B9A\u3057\u3066\u3082\u7D50\u679C\u304C\u540C\u3058\u306A\u306E\
    \u306F\u81EA\u660E\n//   -> \u6728\u306E\u4E2D\u5FC3\u306F\u9AD8\u3005 2 \u500B\
    \ (\u76F4\u5F84\u304C\u5947\u6570\u9577\u306A\u3089 1 \u500B\u3001\u5076\u6570\
    \u9577\u306A\u3089 2 \u500B)\n//   -> \u30CF\u30C3\u30B7\u30E5\u306E\u8A08\u7B97\
    \u3092\u9AD8\u3005 2 * 2 = 4 \u56DE\u3084\u308B\u3060\u3051\u3067\u6E08\u3080\u305F\
    \u3081\u3001\u5341\u5206\u9AD8\u901F\u3067\u3042\u308B\n// \u30FB\u6CE8\u610F\
    : \u6728\u306E\u4E2D\u5FC3\u306E\u500B\u6570\u304C\u4E00\u81F4\u3057\u306A\u3051\
    \u308C\u3070\u540C\u578B\u3067\u306A\u3044\u3053\u3068\u306F\u660E\u3089\u304B\
    \u306A\u306E\u3067\u3001\n//   \u30CF\u30C3\u30B7\u30E5\u306B\u7A81\u3063\u8FBC\
    \u3080\u524D\u306B\u4E2D\u5FC3\u306E\u500B\u6570\u3092\u5148\u306B\u30C1\u30A7\
    \u30C3\u30AF\u3059\u3079\u304D (\u304B\u3082\u3057\u308C\u306A\u3044)\n\nmap<string,\
    \ ll> HASHMAP;\nll cntPattern = 1; // you must write in main: cntPattern = 1;\n\
    \ntemplate <typename T>\nll getHash(vector< vector< Edge<T> > > &G, int point,\
    \ int parent = -1) {\n    // leaf\n    if(G[point].size() == 1 && parent != -1)\n\
    \        return HASHMAP[\"0\"] = 1;\n\n    vector<string> rec;\n    for(size_t\
    \ i=0; i<G[point].size(); i++) {\n        int to = G[point][i].to;\n        if(to\
    \ == parent) continue;\n        ll temp = getHash(G, to, point);\n        rec.push_back(to_string(temp));\n\
    \    }\n    sort(rec.begin(), rec.end());\n    string pat = \"\";\n    for(size_t\
    \ i=0; i<rec.size(); i++) pat += rec[i];\n    if(!HASHMAP.count(pat)) HASHMAP[pat]\
    \ = ++cntPattern;\n    return HASHMAP[pat];\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_013_rootedtreeiso.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_013_rootedtreeiso.cpp
layout: document
redirect_from:
- /library/graph/graph_013_rootedtreeiso.cpp
- /library/graph/graph_013_rootedtreeiso.cpp.html
title: graph/graph_013_rootedtreeiso.cpp
---
