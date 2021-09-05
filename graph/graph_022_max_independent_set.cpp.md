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
  bundledCode: "#line 1 \"graph/graph_022_max_independent_set.cpp\"\n// \u7121\u5411\
    \u975E\u9023\u7D50\u30B0\u30E9\u30D5\u306E\u6700\u5927\u72EC\u7ACB\u96C6\u5408\
    \ (maximal independent set)\n// \u9802\u70B9\u306E\u96C6\u5408 V \u3067\u3042\u3063\
    \u3066\u3001V \u306E\u4EFB\u610F\u306E 2 \u3064\u3092\u3064\u306A\u3050\u8FBA\u304C\
    \u5B58\u5728\u3057\u306A\u3044\u5834\u5408\n// \u6B21\u6570 1 \u3067\u3042\u308C\
    \u3070\u5FC5\u305A\u63A1\u7528\u30FB\u305D\u3046\u3067\u306A\u3051\u308C\u3070\
    \u6B21\u6570\u304C\u5927\u304D\u3044\u3082\u306E\u304B\u3089\u8A66\u3059\u3001\
    \n// \u3068\u3059\u308B\u3068\u679D\u5208\u308A\u304C\u304D\u3044\u3066\u9AD8\u901F\
    \u306B\u306A\u308B\n\nconst int GRAPH_SIZE = 40;\nusing gbit = bitset<GRAPH_SIZE>;\n\
    \n// bitset \u306B\u306F\u6BD4\u8F03\u6F14\u7B97\u5B50\u304C\u306A\u3044\u306E\
    \u3067\u30FB\u30FB\u30FB\nnamespace std {\n    bool operator<(const gbit &a, const\
    \ gbit &b) {\n        gbit ab = a ^ b;\n        int k = ab._Find_first();\n  \
    \      return k < GRAPH_SIZE and b[k] == 1;\n    }\n}\n\ntemplate <typename CostType\
    \ = int>\nstruct MaximalIndependentSet {   \n    Graph<int> G;\n    int N; vector<CostType>\
    \ costs;\n    gbit alive;\n    vector<gbit> adj;\n    bool weighted;\n    map<gbit,\
    \ CostType> rec;\n\n    // \u7121\u5411\u30B0\u30E9\u30D5\u3092\u5165\u529B\u3068\
    \u3057\u3066\u4E0E\u3048\u308B\n    MaximalIndependentSet(Graph<int> G_,\n   \
    \                       vector<CostType> costs_ = vector<CostType>())\n      \
    \  : G(G_), costs(costs_) {\n\n        N = G_.size();\n        if(costs.size()\
    \ != N) {\n            costs = vector<CostType>(N, 1);\n            weighted =\
    \ false;\n        }\n        else weighted = true;\n   \n        alive = gbit();\n\
    \        adj = vector<gbit>(N);\n\n        for(int i=0; i<N; i++) {\n        \
    \    alive[i] = true;\n            for(auto e : G[i]) adj[i][e.to] = 1;\n    \
    \    }\n    }\n\n    inline int deg(int v) {\n        return (alive & adj[v]).count();\n\
    \    }\n\n    // \u305D\u306E\u6642\u70B9\u3067\u6B21\u6570\u6700\u5927\u306E\u9802\
    \u70B9\u3092\u898B\u3064\u3051\u308B\n    int argmax_deg() {\n        int max_deg\
    \ = -1, res = -1;\n        for(int i=0; i<N; i++) {\n            if(!alive[i])\
    \ continue;\n            int d = deg(i);\n            if(d > max_deg) max_deg\
    \ = d, res = i;\n        }\n        return res;\n    }\n\n    pair< CostType,\
    \ gbit > solve_part1() {\n        CostType d = 0; gbit res;\n        // \u6B21\
    \u6570 0 \u307E\u305F\u306F 1 \u306E\u9802\u70B9\u3092\u5168\u90E8\u898B\u3064\
    \u3051\u308B\n        // \u91CD\u307F\u304C\u3042\u308B\u5834\u5408\u306F 0 \u306E\
    \u307F\n        for(int i=0; i<N; i++) {\n            if(alive[i] and !res[i]\
    \ and deg(i) <= !weighted) {\n                res[i] = true; d += costs[i];\n\
    \                res |= (alive & adj[i]);\n            }\n        }\n        return\
    \ make_pair(d, res);\n    }\n\n    CostType solve_part2() {\n        int v = argmax_deg();\
    \ CostType res = 0;\n        if(v < 0) return CostType(0);\n        \n       \
    \ // v \u3092\u4F7F\u308F\u306A\u3044\n        alive[v] = false;\n        res\
    \ = max(res, solve());\n\n        // v \u3092\u4F7F\u3046\n        gbit vs = alive\
    \ & adj[v];\n        alive ^= vs;\n        res = max(res, solve() + costs[v]);\n\
    \        alive ^= vs;\n\n        alive[v] = true;\n        return res;\n    }\n\
    \n    CostType solve() {\n        if(rec.count(alive)) return rec[alive];\n  \
    \      \n        CostType v1; gbit vs;\n        tie(v1, vs) = solve_part1();\n\
    \        alive ^= vs;\n        CostType v2 = solve_part2();\n        alive ^=\
    \ vs;\n        return rec[alive] = v1 + v2;\n    }\n};\n"
  code: "// \u7121\u5411\u975E\u9023\u7D50\u30B0\u30E9\u30D5\u306E\u6700\u5927\u72EC\
    \u7ACB\u96C6\u5408 (maximal independent set)\n// \u9802\u70B9\u306E\u96C6\u5408\
    \ V \u3067\u3042\u3063\u3066\u3001V \u306E\u4EFB\u610F\u306E 2 \u3064\u3092\u3064\
    \u306A\u3050\u8FBA\u304C\u5B58\u5728\u3057\u306A\u3044\u5834\u5408\n// \u6B21\u6570\
    \ 1 \u3067\u3042\u308C\u3070\u5FC5\u305A\u63A1\u7528\u30FB\u305D\u3046\u3067\u306A\
    \u3051\u308C\u3070\u6B21\u6570\u304C\u5927\u304D\u3044\u3082\u306E\u304B\u3089\
    \u8A66\u3059\u3001\n// \u3068\u3059\u308B\u3068\u679D\u5208\u308A\u304C\u304D\u3044\
    \u3066\u9AD8\u901F\u306B\u306A\u308B\n\nconst int GRAPH_SIZE = 40;\nusing gbit\
    \ = bitset<GRAPH_SIZE>;\n\n// bitset \u306B\u306F\u6BD4\u8F03\u6F14\u7B97\u5B50\
    \u304C\u306A\u3044\u306E\u3067\u30FB\u30FB\u30FB\nnamespace std {\n    bool operator<(const\
    \ gbit &a, const gbit &b) {\n        gbit ab = a ^ b;\n        int k = ab._Find_first();\n\
    \        return k < GRAPH_SIZE and b[k] == 1;\n    }\n}\n\ntemplate <typename\
    \ CostType = int>\nstruct MaximalIndependentSet {   \n    Graph<int> G;\n    int\
    \ N; vector<CostType> costs;\n    gbit alive;\n    vector<gbit> adj;\n    bool\
    \ weighted;\n    map<gbit, CostType> rec;\n\n    // \u7121\u5411\u30B0\u30E9\u30D5\
    \u3092\u5165\u529B\u3068\u3057\u3066\u4E0E\u3048\u308B\n    MaximalIndependentSet(Graph<int>\
    \ G_,\n                          vector<CostType> costs_ = vector<CostType>())\n\
    \        : G(G_), costs(costs_) {\n\n        N = G_.size();\n        if(costs.size()\
    \ != N) {\n            costs = vector<CostType>(N, 1);\n            weighted =\
    \ false;\n        }\n        else weighted = true;\n   \n        alive = gbit();\n\
    \        adj = vector<gbit>(N);\n\n        for(int i=0; i<N; i++) {\n        \
    \    alive[i] = true;\n            for(auto e : G[i]) adj[i][e.to] = 1;\n    \
    \    }\n    }\n\n    inline int deg(int v) {\n        return (alive & adj[v]).count();\n\
    \    }\n\n    // \u305D\u306E\u6642\u70B9\u3067\u6B21\u6570\u6700\u5927\u306E\u9802\
    \u70B9\u3092\u898B\u3064\u3051\u308B\n    int argmax_deg() {\n        int max_deg\
    \ = -1, res = -1;\n        for(int i=0; i<N; i++) {\n            if(!alive[i])\
    \ continue;\n            int d = deg(i);\n            if(d > max_deg) max_deg\
    \ = d, res = i;\n        }\n        return res;\n    }\n\n    pair< CostType,\
    \ gbit > solve_part1() {\n        CostType d = 0; gbit res;\n        // \u6B21\
    \u6570 0 \u307E\u305F\u306F 1 \u306E\u9802\u70B9\u3092\u5168\u90E8\u898B\u3064\
    \u3051\u308B\n        // \u91CD\u307F\u304C\u3042\u308B\u5834\u5408\u306F 0 \u306E\
    \u307F\n        for(int i=0; i<N; i++) {\n            if(alive[i] and !res[i]\
    \ and deg(i) <= !weighted) {\n                res[i] = true; d += costs[i];\n\
    \                res |= (alive & adj[i]);\n            }\n        }\n        return\
    \ make_pair(d, res);\n    }\n\n    CostType solve_part2() {\n        int v = argmax_deg();\
    \ CostType res = 0;\n        if(v < 0) return CostType(0);\n        \n       \
    \ // v \u3092\u4F7F\u308F\u306A\u3044\n        alive[v] = false;\n        res\
    \ = max(res, solve());\n\n        // v \u3092\u4F7F\u3046\n        gbit vs = alive\
    \ & adj[v];\n        alive ^= vs;\n        res = max(res, solve() + costs[v]);\n\
    \        alive ^= vs;\n\n        alive[v] = true;\n        return res;\n    }\n\
    \n    CostType solve() {\n        if(rec.count(alive)) return rec[alive];\n  \
    \      \n        CostType v1; gbit vs;\n        tie(v1, vs) = solve_part1();\n\
    \        alive ^= vs;\n        CostType v2 = solve_part2();\n        alive ^=\
    \ vs;\n        return rec[alive] = v1 + v2;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_022_max_independent_set.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_022_max_independent_set.cpp
layout: document
redirect_from:
- /library/graph/graph_022_max_independent_set.cpp
- /library/graph/graph_022_max_independent_set.cpp.html
title: graph/graph_022_max_independent_set.cpp
---
