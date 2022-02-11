---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
    title: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/linear_system_incidence.md
    document_title: "\u63A5\u7D9A\u884C\u5217\u3092\u4FC2\u6570\u306B\u6301\u3064\u7DDA\
      \u5F62\u65B9\u7A0B\u5F0F\u306E\u30BD\u30EB\u30D0"
    links: []
  bundledCode: "#line 2 \"graph/linear_system_incidence.cpp\"\n\n/**\n * @brief \u63A5\
    \u7D9A\u884C\u5217\u3092\u4FC2\u6570\u306B\u6301\u3064\u7DDA\u5F62\u65B9\u7A0B\
    \u5F0F\u306E\u30BD\u30EB\u30D0\n * @docs docs/graph/linear_system_incidence.md\n\
    \ */\n\n#include <vector>\n#include <utility>\n#include <tuple>\n#include <cassert>\n\
    \ntemplate <typename Tp>\nclass LinearSystemIncidence {\npublic:\n    struct Edge\
    \ {\n        int id, to;\n        bool is_forward;\n        Edge(int id, int to,\
    \ int is_forward) : id(id), to(to), is_forward(is_forward) {}\n    };\n\n    LinearSystemIncidence(int\
    \ N, const vector< pair<int, int> >& edges) : N(N), M(edges.size()), G(N) {\n\
    \        for(int i=0; i<M; i++) {\n            int u, v; tie(u, v) = edges[i];\n\
    \            G[u].emplace_back(i, v, true);\n            G[v].emplace_back(i,\
    \ u, false);\n        }\n    }\n\n    Tp dfs(int u, const vector<Tp> &b) {\n \
    \       assert(!used[u]);\n        used[u] = true;\n        Tp res = b[u];\n \
    \       for(const auto &e : G[u]) {\n            if(used[e.to]) continue;\n  \
    \          Tp res_to = dfs(e.to, b);\n            if(e.is_forward) x[e.id] = res_to;\n\
    \            else x[e.id] = -res_to;\n            res += res_to;\n        }\n\
    \        return res;\n    }\n\n    pair< bool, vector<Tp> > solve(vector<Tp> &b)\
    \ {\n        assert(static_cast<int>(b.size()) == N);\n        used.assign(N,\
    \ false);\n        x.assign(M, Tp(0));\n        for(int i=0; i<N; i++) {\n   \
    \         if(used[i]) continue;\n            Tp v = dfs(i, b);\n            if(v\
    \ != Tp(0)) return make_pair(false, vector<Tp>());\n        }\n        return\
    \ {true, move(x)};\n    }\n\nprivate:\n    int N, M;\n    vector< vector<Edge>\
    \ > G;\n    vector<bool> used;\n    vector<Tp> x; // Ax = b\n};\n"
  code: "#pragma once\n\n/**\n * @brief \u63A5\u7D9A\u884C\u5217\u3092\u4FC2\u6570\
    \u306B\u6301\u3064\u7DDA\u5F62\u65B9\u7A0B\u5F0F\u306E\u30BD\u30EB\u30D0\n * @docs\
    \ docs/graph/linear_system_incidence.md\n */\n\n#include <vector>\n#include <utility>\n\
    #include <tuple>\n#include <cassert>\n\ntemplate <typename Tp>\nclass LinearSystemIncidence\
    \ {\npublic:\n    struct Edge {\n        int id, to;\n        bool is_forward;\n\
    \        Edge(int id, int to, int is_forward) : id(id), to(to), is_forward(is_forward)\
    \ {}\n    };\n\n    LinearSystemIncidence(int N, const vector< pair<int, int>\
    \ >& edges) : N(N), M(edges.size()), G(N) {\n        for(int i=0; i<M; i++) {\n\
    \            int u, v; tie(u, v) = edges[i];\n            G[u].emplace_back(i,\
    \ v, true);\n            G[v].emplace_back(i, u, false);\n        }\n    }\n\n\
    \    Tp dfs(int u, const vector<Tp> &b) {\n        assert(!used[u]);\n       \
    \ used[u] = true;\n        Tp res = b[u];\n        for(const auto &e : G[u]) {\n\
    \            if(used[e.to]) continue;\n            Tp res_to = dfs(e.to, b);\n\
    \            if(e.is_forward) x[e.id] = res_to;\n            else x[e.id] = -res_to;\n\
    \            res += res_to;\n        }\n        return res;\n    }\n\n    pair<\
    \ bool, vector<Tp> > solve(vector<Tp> &b) {\n        assert(static_cast<int>(b.size())\
    \ == N);\n        used.assign(N, false);\n        x.assign(M, Tp(0));\n      \
    \  for(int i=0; i<N; i++) {\n            if(used[i]) continue;\n            Tp\
    \ v = dfs(i, b);\n            if(v != Tp(0)) return make_pair(false, vector<Tp>());\n\
    \        }\n        return {true, move(x)};\n    }\n\nprivate:\n    int N, M;\n\
    \    vector< vector<Edge> > G;\n    vector<bool> used;\n    vector<Tp> x; // Ax\
    \ = b\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/linear_system_incidence.cpp
  requiredBy: []
  timestamp: '2022-02-11 15:15:07+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
documentation_of: graph/linear_system_incidence.cpp
layout: document
redirect_from:
- /library/graph/linear_system_incidence.cpp
- /library/graph/linear_system_incidence.cpp.html
title: "\u63A5\u7D9A\u884C\u5217\u3092\u4FC2\u6570\u306B\u6301\u3064\u7DDA\u5F62\u65B9\
  \u7A0B\u5F0F\u306E\u30BD\u30EB\u30D0"
---
## Summary

グラフ $G$ の接続行列 $B \in \mathbb{R}^{V \times E}$ とは、頂点を行に・辺を列に対応させ、グラフの接続関係を要素で表したような行列である。有向・無向どちらでも定義できる。

接続行列を係数に持つ線形方程式は線形時間 $O( \lvert V \rvert + \lvert E \rvert )$ で解ける。方針としては、全域木を作って葉から値を決定していく。途中で矛盾するような結果になれば解なし。

詳しくは下記資料を参考のこと。なお、問題によっては $\bmod 2$ で解を求めることを要求されるが、`ModInt<2>` 型で与えれば問題ないと思う。

## Reference

- [「接続行列を係数にもつ線形方程式」の競プロでの応用](https://drive.google.com/file/d/1GYxjvoEIn_j9i9AEWP5zQ4yyCQCLysrn/view) (opt さん)