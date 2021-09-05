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
  bundledCode: "#line 1 \"graph/graph_006_bridge_points.cpp\"\n// \u95A2\u7BC0\u70B9\
    \u3092\u6C42\u3081\u308B (artPoints)\n// \u6A4B\u3092\u6C42\u3081\u308B (bridges)\n\
    // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\u89E3\u3092\u3059\u308B (BICC)\n\
    \n// \u95A2\u7BC0\u70B9\u306F\u3001\u53D6\u308A\u9664\u3044\u305F\u3068\u304D\u306B\
    \u9023\u7D50\u3067\u306A\u304F\u306A\u3063\u3066\u3057\u307E\u3046\u3088\u3046\
    \u306A\u9802\u70B9\u306E\u3053\u3068\n// \u6A4B\u306F\u3001\u53D6\u308A\u9664\u3044\
    \u305F\u6642\u306B\u9023\u7D50\u3067\u306A\u304F\u306A\u3063\u3066\u3057\u307E\
    \u3046\u3088\u3046\u306A\u8FBA\u306E\u3053\u3068\n\ntemplate <typename T>\nstruct\
    \ graphLink {\n    vector<int> ord, low, parent, cmp;\n    vector< vector< Edge<T>\
    \ > > G, H;\n\n    // \u6A4B\u306E\u60C5\u5831 (first < second \u3068\u306A\u308B\
    \u3088\u3046\u306B\u683C\u7D0D)\n    vector< pair<int, int> > bridges;\n    int\
    \ cnt, v;\n\n    // init\n    graphLink(vector< vector< Edge<T> > > &S, int root=0)\
    \ {\n        int n = S.size();\n        ord.resize(n, -1), low.resize(n, 0),\n\
    \        parent.resize(n, -1), cmp.resize(n, -1);\n        cnt = 0, v = n;\n \
    \       G = S;\n        dfs(root);\n    }\n\n    // \u6A4B\u3067\u3042\u308B\u304B\
    \u306E\u5224\u5B9A\n    bool is_bridge(int x, int y) {\n        if(ord[x] > ord[y])\
    \ swap(x, y);\n        return ord[x] < low[y];\n    }\n\n    // dfs \u6728\u306E\
    \u4F5C\u6210\u3068\u6A4B\u306E\u5217\u6319 (\u521D\u671F\u5316\u3068\u540C\u6642\
    \u306B\u3084\u308B)\n    // usage: dfs(root);\n    void dfs(int cur, int prev=-1)\
    \ {\n        low[cur] = cnt;\n        ord[cur] = cnt++;\n\n        for(auto x\
    \ : G[cur]) {\n            if(x.to == prev) continue;\n            if(ord[x.to]\
    \ < 0) {\n                parent[x.to] = cur;\n                dfs(x.to, cur);\n\
    \n                low[cur] = min(low[cur], low[x.to]);\n            }\n      \
    \      else {\n                low[cur] = min(low[cur], ord[x.to]);\n        \
    \    }\n            if(is_bridge(cur, x.to)) {\n                int a = min(cur,\
    \ x.to);\n                int b = max(cur, x.to);\n                bridges.emplace_back(make_pair(a,\
    \ b));\n            }\n        }\n    }\n\n    // \u95A2\u7BC0\u70B9\u3092\u6C42\
    \u3081\u308B (root \u306F dfs \u6728\u306E root \u3068\u4E00\u81F4\u3055\u305B\
    \u308B)\n    // root \u306F\u5B50\u3092 2 \u3064\u6301\u3063\u3066\u3044\u308C\
    \u3070\u95A2\u7BC0\u70B9\u306B\u306A\u308B\n    // \u305D\u308C\u4EE5\u5916\u306E\
    \u9802\u70B9\u306B\u95A2\u3057\u3066\u306F ord[parent] <= low[i] \u306E\u3068\u304D\
    \u95A2\u7BC0\u70B9\u306B\u306A\u308B\n    // (lowlink \u3067\u3082\u89AA\u3088\
    \u308A\u6DF1\u3055\u304C\u4F4E\u3044\u9802\u70B9\u306B\u305F\u3069\u308A\u7740\
    \u3051\u306A\u3044\u305F\u3081)\n    set<int> artPoints(int root) {\n        set<int>\
    \ se;\n        int num = 0;\n        for(int i=0; i<v; i++) {\n            if(parent[i]\
    \ < 0) continue;\n            if(parent[i] == root) num++;\n            else if(ord[parent[i]]\
    \ <= low[i]) se.insert(parent[i]);\n        }\n        if(num >= 2) se.insert(0);\n\
    \        return se;\n    }\n\n    // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 (\u6A4B\u3068\u306A\u308B\u8FBA\u3092\u4F7F\u308F\u306A\u3044\u3088\
    \u3046\u306B DFS)\n    // Verified: AtCoder Regular Contest D: \u65C5\u884C\u4F1A\
    \u793E\u9AD8\u6A4B\u541B\n    void BICC() {\n        int k = 0;\n        // point,\
    \ number\n        stack<pii> S;\n        for(int i=0; i<v; i++) {\n          \
    \  if(cmp[i] >= 0) continue;\n            cmp[i] = k;\n            S.push(make_pair(i,\
    \ k++));\n            while(!S.empty()) {\n                pii cur = S.top();\
    \ S.pop();\n                for(auto x : G[cur.first]) {\n                   \
    \ if(cmp[x.to] >= 0) continue;\n                    if(is_bridge(cur.first, x.to))\
    \ continue;\n                    cmp[x.to] = cur.second;\n                   \
    \ S.push(make_pair(x.to, cmp[x.to]));\n                }\n            }\n    \
    \    }\n\n        set< pair<int, int> > edge_set;\n        H.resize(k);\n    \
    \    for(int i=0; i<v; i++) {\n            for(auto x : G[i]) {\n            \
    \    int ca = cmp[i], cb = cmp[x.to];\n                if(ca == cb) continue;\n\
    \                if(ca > cb) swap(ca, cb);\n                if(edge_set.count(make_pair(ca,\
    \ cb))) continue;\n                edge_set.insert(make_pair(ca, cb));\n     \
    \           H[ca].push_back(Edge<T>(cb, 1));\n                H[cb].push_back(Edge<T>(ca,\
    \ 1));\n            }\n        }\n    }\n};\n"
  code: "// \u95A2\u7BC0\u70B9\u3092\u6C42\u3081\u308B (artPoints)\n// \u6A4B\u3092\
    \u6C42\u3081\u308B (bridges)\n// \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\u5206\
    \u89E3\u3092\u3059\u308B (BICC)\n\n// \u95A2\u7BC0\u70B9\u306F\u3001\u53D6\u308A\
    \u9664\u3044\u305F\u3068\u304D\u306B\u9023\u7D50\u3067\u306A\u304F\u306A\u3063\
    \u3066\u3057\u307E\u3046\u3088\u3046\u306A\u9802\u70B9\u306E\u3053\u3068\n// \u6A4B\
    \u306F\u3001\u53D6\u308A\u9664\u3044\u305F\u6642\u306B\u9023\u7D50\u3067\u306A\
    \u304F\u306A\u3063\u3066\u3057\u307E\u3046\u3088\u3046\u306A\u8FBA\u306E\u3053\
    \u3068\n\ntemplate <typename T>\nstruct graphLink {\n    vector<int> ord, low,\
    \ parent, cmp;\n    vector< vector< Edge<T> > > G, H;\n\n    // \u6A4B\u306E\u60C5\
    \u5831 (first < second \u3068\u306A\u308B\u3088\u3046\u306B\u683C\u7D0D)\n   \
    \ vector< pair<int, int> > bridges;\n    int cnt, v;\n\n    // init\n    graphLink(vector<\
    \ vector< Edge<T> > > &S, int root=0) {\n        int n = S.size();\n        ord.resize(n,\
    \ -1), low.resize(n, 0),\n        parent.resize(n, -1), cmp.resize(n, -1);\n \
    \       cnt = 0, v = n;\n        G = S;\n        dfs(root);\n    }\n\n    // \u6A4B\
    \u3067\u3042\u308B\u304B\u306E\u5224\u5B9A\n    bool is_bridge(int x, int y) {\n\
    \        if(ord[x] > ord[y]) swap(x, y);\n        return ord[x] < low[y];\n  \
    \  }\n\n    // dfs \u6728\u306E\u4F5C\u6210\u3068\u6A4B\u306E\u5217\u6319 (\u521D\
    \u671F\u5316\u3068\u540C\u6642\u306B\u3084\u308B)\n    // usage: dfs(root);\n\
    \    void dfs(int cur, int prev=-1) {\n        low[cur] = cnt;\n        ord[cur]\
    \ = cnt++;\n\n        for(auto x : G[cur]) {\n            if(x.to == prev) continue;\n\
    \            if(ord[x.to] < 0) {\n                parent[x.to] = cur;\n      \
    \          dfs(x.to, cur);\n\n                low[cur] = min(low[cur], low[x.to]);\n\
    \            }\n            else {\n                low[cur] = min(low[cur], ord[x.to]);\n\
    \            }\n            if(is_bridge(cur, x.to)) {\n                int a\
    \ = min(cur, x.to);\n                int b = max(cur, x.to);\n               \
    \ bridges.emplace_back(make_pair(a, b));\n            }\n        }\n    }\n\n\
    \    // \u95A2\u7BC0\u70B9\u3092\u6C42\u3081\u308B (root \u306F dfs \u6728\u306E\
    \ root \u3068\u4E00\u81F4\u3055\u305B\u308B)\n    // root \u306F\u5B50\u3092 2\
    \ \u3064\u6301\u3063\u3066\u3044\u308C\u3070\u95A2\u7BC0\u70B9\u306B\u306A\u308B\
    \n    // \u305D\u308C\u4EE5\u5916\u306E\u9802\u70B9\u306B\u95A2\u3057\u3066\u306F\
    \ ord[parent] <= low[i] \u306E\u3068\u304D\u95A2\u7BC0\u70B9\u306B\u306A\u308B\
    \n    // (lowlink \u3067\u3082\u89AA\u3088\u308A\u6DF1\u3055\u304C\u4F4E\u3044\
    \u9802\u70B9\u306B\u305F\u3069\u308A\u7740\u3051\u306A\u3044\u305F\u3081)\n  \
    \  set<int> artPoints(int root) {\n        set<int> se;\n        int num = 0;\n\
    \        for(int i=0; i<v; i++) {\n            if(parent[i] < 0) continue;\n \
    \           if(parent[i] == root) num++;\n            else if(ord[parent[i]] <=\
    \ low[i]) se.insert(parent[i]);\n        }\n        if(num >= 2) se.insert(0);\n\
    \        return se;\n    }\n\n    // \u4E8C\u91CD\u8FBA\u9023\u7D50\u6210\u5206\
    \u5206\u89E3 (\u6A4B\u3068\u306A\u308B\u8FBA\u3092\u4F7F\u308F\u306A\u3044\u3088\
    \u3046\u306B DFS)\n    // Verified: AtCoder Regular Contest D: \u65C5\u884C\u4F1A\
    \u793E\u9AD8\u6A4B\u541B\n    void BICC() {\n        int k = 0;\n        // point,\
    \ number\n        stack<pii> S;\n        for(int i=0; i<v; i++) {\n          \
    \  if(cmp[i] >= 0) continue;\n            cmp[i] = k;\n            S.push(make_pair(i,\
    \ k++));\n            while(!S.empty()) {\n                pii cur = S.top();\
    \ S.pop();\n                for(auto x : G[cur.first]) {\n                   \
    \ if(cmp[x.to] >= 0) continue;\n                    if(is_bridge(cur.first, x.to))\
    \ continue;\n                    cmp[x.to] = cur.second;\n                   \
    \ S.push(make_pair(x.to, cmp[x.to]));\n                }\n            }\n    \
    \    }\n\n        set< pair<int, int> > edge_set;\n        H.resize(k);\n    \
    \    for(int i=0; i<v; i++) {\n            for(auto x : G[i]) {\n            \
    \    int ca = cmp[i], cb = cmp[x.to];\n                if(ca == cb) continue;\n\
    \                if(ca > cb) swap(ca, cb);\n                if(edge_set.count(make_pair(ca,\
    \ cb))) continue;\n                edge_set.insert(make_pair(ca, cb));\n     \
    \           H[ca].push_back(Edge<T>(cb, 1));\n                H[cb].push_back(Edge<T>(ca,\
    \ 1));\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_006_bridge_points.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_006_bridge_points.cpp
layout: document
redirect_from:
- /library/graph/graph_006_bridge_points.cpp
- /library/graph/graph_006_bridge_points.cpp.html
title: graph/graph_006_bridge_points.cpp
---
