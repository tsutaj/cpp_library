---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/graph_012_maxflow_ford.cpp\"\n// Ford-Fulkerson \u6CD5\
    \u306B\u3088\u308B \u6700\u5927\u6D41 O( F |E| )\n// Bellman-Ford \u6CD5\u306B\
    \u3088\u308B \u6700\u5C0F\u8CBB\u7528\u6D41 O( F |V| |E| )\n// [\u6761\u4EF6\u306B\
    \u6CE8\u610F] Dijkstra \u6CD5\u306B\u3088\u308B \u6700\u5C0F\u8CBB\u7528\u6D41\
    \ O( F |E| log |V| )\n\ntemplate <typename CapTp=int, typename CostTp=int>\nstruct\
    \ Edge {\n    int to, rev;\n    CapTp cap; CostTp cost;\n    bool is_rev;\n  \
    \  Edge(int t, bool f, int r, CapTp ca, CostTp co=0)\n        : to(t), rev(r),\
    \ cap(ca), cost(co), is_rev(f) {}\n};\n\ntemplate <typename CapTp=int, typename\
    \ CostTp=int>\nstruct Flow {\n    using Graph = vector< vector< Edge<CapTp, CostTp>\
    \ > >;\n    Graph G; const CapTp IA; const CostTp IO;\n    vector< pair<int, int>\
    \ > r_edges;\n    Flow(int N_, CapTp IA_=1<<29, CostTp IO_=1<<29)\n        : G(N_),\
    \ IA(IA_), IO(IO_), r_edges() {}\n    // \u8FBA\u3092\u8FFD\u52A0 (from -> to\
    \ \u306B\u6D41\u91CF ca, \u30B3\u30B9\u30C8 co)\n    void add_edge(int from, int\
    \ to, CapTp ca, CostTp co=0) {\n        G[from].emplace_back(to, false, G[to].size(),\
    \ ca, co);\n        G[to].emplace_back(from, true, G[from].size() - 1, 0, -co);\n\
    \        r_edges.emplace_back(to, G[to].size() - 1);\n    }\n    // k \u756A\u76EE\
    \u306E\u8FBA\u306B\u3044\u304F\u3064\u6D41\u308C\u305F\u304B\n    CapTp get_flowed_cap(size_t\
    \ k) {\n        if(r_edges.size() <= k) return -1;\n        int v, i; tie(v, i)\
    \ = r_edges[k];\n        return G[v][i].cap;\n    }\n    // s -> t \u6700\u5927\
    \u6D41\n    CapTp max_flow(int s, int t) {\n        vector<bool> used(G.size());\n\
    \        auto dfs = [&](auto &&func, int v, int t, CapTp f) -> CapTp {\n     \
    \       if(v == t) return f;\n            used[v] = true;\n            for(auto\
    \ &e : G[v]) {\n                if(used[e.to] or e.cap == 0) continue;\n     \
    \           CapTp d = func(func, e.to, t, min(f, e.cap));\n                if(d\
    \ == 0) continue;\n                e.cap -= d; G[e.to][e.rev].cap += d;\n    \
    \            return d;\n            }\n            return 0;\n        };\n\n \
    \       CapTp res(0);\n        while(true) {\n            fill(used.begin(), used.end(),\
    \ false);\n            CapTp delta = dfs(dfs, s, t, IA);\n            if(delta\
    \ == 0) return res;\n            res += delta;\n        }\n    }\n    // \u30D9\
    \u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u3092\u3064\u304B\u3063\u3066\u6700\
    \u5C0F\u8CBB\u7528\u6D41\n    CostTp mincost_flow(int s, int t, CapTp f) {\n \
    \       vector<CostTp> dist(G.size()); CostTp res(0);\n        vector<int> prevv(G.size()),\
    \ preve(G.size());\n        while(f > 0) {\n            fill(dist.begin(), dist.end(),\
    \ IO);\n            dist[s] = 0;\n            while(1) {\n                bool\
    \ upd = false;\n                for(int v=0; v<(int)G.size(); v++) {\n       \
    \             if(dist[v] == IO) continue;\n                    for(size_t i=0;\
    \ i<G[v].size(); i++) {\n                        auto &e = G[v][i];\n        \
    \                if(e.cap == 0 or dist[e.to] <= dist[v] + e.cost) continue;\n\
    \                        dist[e.to] = dist[v] + e.cost;\n                    \
    \    prevv[e.to] = v, preve[e.to] = i;\n                        upd = true;\n\
    \                    }\n                }\n                if(!upd) break;\n \
    \           }\n\n            if(dist[t] == IO) return -1;\n            CapTp d\
    \ = f;\n            for(int v=t; v!=s; v=prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            f -= d; res += d * dist[t];\n            for(int v=t; v!=s; v=prevv[v])\
    \ {\n                auto &e = G[prevv[v]][preve[v]];\n                e.cap -=\
    \ d, G[v][e.rev].cap += d;\n            }\n        }\n        return res;\n  \
    \  }\n    // \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u5C0E\u5165\u306B\u3088\
    \u308A\u3001\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u6700\u5C0F\u8CBB\
    \u7528\u6D41\u3092\u89E3\u304F\n    // [\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u6761\
    \u4EF6]\n    //     1. \u30B0\u30E9\u30D5\u306B\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\
    \u5728\u3057\u306A\u3044 (\u6D41\u91CF\u306E 0 \u521D\u671F\u5316\u306E\u305F\u3081\
    )\n    //        \u3082\u3057\u5B58\u5728\u3059\u308B\u306A\u3089\u30D9\u30EB\u30DE\
    \u30F3\u30D5\u30A9\u30FC\u30C9\u3067\u8CA0\u306E\u9589\u8DEF\u3092\u898B\u3064\
    \u3051\n    //        \u305D\u3053\u306B\u6D41\u305B\u308B\u3060\u3051\u6D41\u3057\
    \u3066\u30B9\u30BF\u30FC\u30C8\n    //     2. \u30B0\u30E9\u30D5\u306B\u8CA0\u306E\
    \u8FBA\u304C\u5B58\u5728\u3057\u306A\u3044 (pot_0 \u306E\u8A08\u7B97\u53EF\u80FD\
    \u6027)\n    //        \u3082\u3057\u5B58\u5728\u3059\u308B\u5834\u5408\u306F\u6700\
    \u521D\u306E\u307F\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u3092\u4F7F\
    \u3046\u5FC5\u8981\u3042\u308A\n    CostTp fast_mincost_flow(int s, int t, CapTp\
    \ f) {\n        CostTp res = 0;\n        vector<CostTp> dist(G.size()), pot(G.size());\n\
    \        vector<int> prevv(G.size()), preve(G.size());\n        while(f > 0) {\n\
    \            using PT = pair<CostTp, int>;\n            priority_queue< PT, vector<PT>,\
    \ greater<PT> > que;\n            fill(dist.begin(), dist.end(), IO);\n\n    \
    \        dist[s] = 0;\n            que.push(make_pair(0, s));\n            while(!que.empty())\
    \ {\n                PT cur = que.top(); que.pop();\n                int v = cur.second;\n\
    \                if(dist[v] < cur.first) continue;\n                for(size_t\
    \ i=0; i<G[v].size(); i++) {\n                    auto& e = G[v][i];\n       \
    \             if(e.cap > 0 and dist[e.to] > dist[v] + e.cost + pot[v] - pot[e.to])\
    \ {\n                        dist[e.to] = dist[v] + e.cost + pot[v] - pot[e.to];\n\
    \                        prevv[e.to] = v;\n                        preve[e.to]\
    \ = i;\n                        que.push(make_pair(dist[e.to], e.to));\n     \
    \               }\n                }\n            }\n            if(dist[t] ==\
    \ IO) {\n                return -1;\n            }\n            for(int v=0; v<(int)G.size();\
    \ v++) pot[v] += dist[v];\n\n            CapTp d = f;\n            for(int v=t;\
    \ v!=s; v=prevv[v]) {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            }\n            f -= d;\n            res += d * pot[t];\n        \
    \    for(int v=t; v!=s; v=prevv[v]) {\n                auto& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return res;\n    }    \n};\n"
  code: "// Ford-Fulkerson \u6CD5\u306B\u3088\u308B \u6700\u5927\u6D41 O( F |E| )\n\
    // Bellman-Ford \u6CD5\u306B\u3088\u308B \u6700\u5C0F\u8CBB\u7528\u6D41 O( F |V|\
    \ |E| )\n// [\u6761\u4EF6\u306B\u6CE8\u610F] Dijkstra \u6CD5\u306B\u3088\u308B\
    \ \u6700\u5C0F\u8CBB\u7528\u6D41 O( F |E| log |V| )\n\ntemplate <typename CapTp=int,\
    \ typename CostTp=int>\nstruct Edge {\n    int to, rev;\n    CapTp cap; CostTp\
    \ cost;\n    bool is_rev;\n    Edge(int t, bool f, int r, CapTp ca, CostTp co=0)\n\
    \        : to(t), rev(r), cap(ca), cost(co), is_rev(f) {}\n};\n\ntemplate <typename\
    \ CapTp=int, typename CostTp=int>\nstruct Flow {\n    using Graph = vector< vector<\
    \ Edge<CapTp, CostTp> > >;\n    Graph G; const CapTp IA; const CostTp IO;\n  \
    \  vector< pair<int, int> > r_edges;\n    Flow(int N_, CapTp IA_=1<<29, CostTp\
    \ IO_=1<<29)\n        : G(N_), IA(IA_), IO(IO_), r_edges() {}\n    // \u8FBA\u3092\
    \u8FFD\u52A0 (from -> to \u306B\u6D41\u91CF ca, \u30B3\u30B9\u30C8 co)\n    void\
    \ add_edge(int from, int to, CapTp ca, CostTp co=0) {\n        G[from].emplace_back(to,\
    \ false, G[to].size(), ca, co);\n        G[to].emplace_back(from, true, G[from].size()\
    \ - 1, 0, -co);\n        r_edges.emplace_back(to, G[to].size() - 1);\n    }\n\
    \    // k \u756A\u76EE\u306E\u8FBA\u306B\u3044\u304F\u3064\u6D41\u308C\u305F\u304B\
    \n    CapTp get_flowed_cap(size_t k) {\n        if(r_edges.size() <= k) return\
    \ -1;\n        int v, i; tie(v, i) = r_edges[k];\n        return G[v][i].cap;\n\
    \    }\n    // s -> t \u6700\u5927\u6D41\n    CapTp max_flow(int s, int t) {\n\
    \        vector<bool> used(G.size());\n        auto dfs = [&](auto &&func, int\
    \ v, int t, CapTp f) -> CapTp {\n            if(v == t) return f;\n          \
    \  used[v] = true;\n            for(auto &e : G[v]) {\n                if(used[e.to]\
    \ or e.cap == 0) continue;\n                CapTp d = func(func, e.to, t, min(f,\
    \ e.cap));\n                if(d == 0) continue;\n                e.cap -= d;\
    \ G[e.to][e.rev].cap += d;\n                return d;\n            }\n       \
    \     return 0;\n        };\n\n        CapTp res(0);\n        while(true) {\n\
    \            fill(used.begin(), used.end(), false);\n            CapTp delta =\
    \ dfs(dfs, s, t, IA);\n            if(delta == 0) return res;\n            res\
    \ += delta;\n        }\n    }\n    // \u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\
    \u30C9\u3092\u3064\u304B\u3063\u3066\u6700\u5C0F\u8CBB\u7528\u6D41\n    CostTp\
    \ mincost_flow(int s, int t, CapTp f) {\n        vector<CostTp> dist(G.size());\
    \ CostTp res(0);\n        vector<int> prevv(G.size()), preve(G.size());\n    \
    \    while(f > 0) {\n            fill(dist.begin(), dist.end(), IO);\n       \
    \     dist[s] = 0;\n            while(1) {\n                bool upd = false;\n\
    \                for(int v=0; v<(int)G.size(); v++) {\n                    if(dist[v]\
    \ == IO) continue;\n                    for(size_t i=0; i<G[v].size(); i++) {\n\
    \                        auto &e = G[v][i];\n                        if(e.cap\
    \ == 0 or dist[e.to] <= dist[v] + e.cost) continue;\n                        dist[e.to]\
    \ = dist[v] + e.cost;\n                        prevv[e.to] = v, preve[e.to] =\
    \ i;\n                        upd = true;\n                    }\n           \
    \     }\n                if(!upd) break;\n            }\n\n            if(dist[t]\
    \ == IO) return -1;\n            CapTp d = f;\n            for(int v=t; v!=s;\
    \ v=prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n            f -= d; res\
    \ += d * dist[t];\n            for(int v=t; v!=s; v=prevv[v]) {\n            \
    \    auto &e = G[prevv[v]][preve[v]];\n                e.cap -= d, G[v][e.rev].cap\
    \ += d;\n            }\n        }\n        return res;\n    }\n    // \u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u306E\u5C0E\u5165\u306B\u3088\u308A\u3001\u30C0\u30A4\
    \u30AF\u30B9\u30C8\u30E9\u6CD5\u3067\u6700\u5C0F\u8CBB\u7528\u6D41\u3092\u89E3\
    \u304F\n    // [\u4EEE\u5B9A\u3057\u3066\u3044\u308B\u6761\u4EF6]\n    //    \
    \ 1. \u30B0\u30E9\u30D5\u306B\u8CA0\u306E\u9589\u8DEF\u304C\u5B58\u5728\u3057\u306A\
    \u3044 (\u6D41\u91CF\u306E 0 \u521D\u671F\u5316\u306E\u305F\u3081)\n    //   \
    \     \u3082\u3057\u5B58\u5728\u3059\u308B\u306A\u3089\u30D9\u30EB\u30DE\u30F3\
    \u30D5\u30A9\u30FC\u30C9\u3067\u8CA0\u306E\u9589\u8DEF\u3092\u898B\u3064\u3051\
    \n    //        \u305D\u3053\u306B\u6D41\u305B\u308B\u3060\u3051\u6D41\u3057\u3066\
    \u30B9\u30BF\u30FC\u30C8\n    //     2. \u30B0\u30E9\u30D5\u306B\u8CA0\u306E\u8FBA\
    \u304C\u5B58\u5728\u3057\u306A\u3044 (pot_0 \u306E\u8A08\u7B97\u53EF\u80FD\u6027\
    )\n    //        \u3082\u3057\u5B58\u5728\u3059\u308B\u5834\u5408\u306F\u6700\u521D\
    \u306E\u307F\u30D9\u30EB\u30DE\u30F3\u30D5\u30A9\u30FC\u30C9\u3092\u4F7F\u3046\
    \u5FC5\u8981\u3042\u308A\n    CostTp fast_mincost_flow(int s, int t, CapTp f)\
    \ {\n        CostTp res = 0;\n        vector<CostTp> dist(G.size()), pot(G.size());\n\
    \        vector<int> prevv(G.size()), preve(G.size());\n        while(f > 0) {\n\
    \            using PT = pair<CostTp, int>;\n            priority_queue< PT, vector<PT>,\
    \ greater<PT> > que;\n            fill(dist.begin(), dist.end(), IO);\n\n    \
    \        dist[s] = 0;\n            que.push(make_pair(0, s));\n            while(!que.empty())\
    \ {\n                PT cur = que.top(); que.pop();\n                int v = cur.second;\n\
    \                if(dist[v] < cur.first) continue;\n                for(size_t\
    \ i=0; i<G[v].size(); i++) {\n                    auto& e = G[v][i];\n       \
    \             if(e.cap > 0 and dist[e.to] > dist[v] + e.cost + pot[v] - pot[e.to])\
    \ {\n                        dist[e.to] = dist[v] + e.cost + pot[v] - pot[e.to];\n\
    \                        prevv[e.to] = v;\n                        preve[e.to]\
    \ = i;\n                        que.push(make_pair(dist[e.to], e.to));\n     \
    \               }\n                }\n            }\n            if(dist[t] ==\
    \ IO) {\n                return -1;\n            }\n            for(int v=0; v<(int)G.size();\
    \ v++) pot[v] += dist[v];\n\n            CapTp d = f;\n            for(int v=t;\
    \ v!=s; v=prevv[v]) {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            }\n            f -= d;\n            res += d * pot[t];\n        \
    \    for(int v=t; v!=s; v=prevv[v]) {\n                auto& e = G[prevv[v]][preve[v]];\n\
    \                e.cap -= d;\n                G[v][e.rev].cap += d;\n        \
    \    }\n        }\n        return res;\n    }    \n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_012_maxflow_ford.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_012_maxflow_ford.cpp
layout: document
redirect_from:
- /library/graph/graph_012_maxflow_ford.cpp
- /library/graph/graph_012_maxflow_ford.cpp.html
title: graph/graph_012_maxflow_ford.cpp
---
