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
  bundledCode: "#line 1 \"graph/graph_018_dinic.cpp\"\n// Dinic \u3092\u4FE1\u3058\
    \u308D\n\ntemplate <typename CapTp=int, typename CostTp=int>\nstruct Edge {\n\
    \    int to, rev;\n    CapTp cap; CostTp cost;\n    bool is_rev;\n    Edge(int\
    \ t, bool f, int r, CapTp ca, CostTp co=0)\n        : to(t), rev(r), cap(ca),\
    \ cost(co), is_rev(f) {}\n};\n\ntemplate<typename CapTp=int>\nstruct Dinic {\n\
    \    using Graph = vector< vector< Edge<CapTp> > >;\n    Graph G;\n    vector<int>\
    \ level, iter;\n    const CapTp IA;\n    vector< pair<int, int> > r_edges;\n \
    \   Dinic(int N, CapTp IA_=1<<29) : IA(IA_) {\n        G.resize(N);\n        level.resize(N);\n\
    \        iter.resize(N);\n    }\n    void add_edge(int from, int to, CapTp cap)\
    \ {\n        G[from].emplace_back(to, false, G[to].size(), cap);\n        G[to].emplace_back(from,\
    \ true, G[from].size() - 1, 0);\n        r_edges.emplace_back(to, G[to].size()\
    \ - 1);\n    }\n    CapTp get_flowed_cap(size_t k) {\n        if(r_edges.size()\
    \ <= k) return -1;\n        int v, i; tie(v, i) = r_edges[k];\n        return\
    \ G[v][i].cap;\n    }\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<int> que; que.push(s);\n        level[s] = 0;\n        while(!que.empty())\
    \ {\n            int temp = que.front(); que.pop();\n            for(size_t i=0;\
    \ i<G[temp].size(); i++) {\n                auto &e = G[temp][i];\n          \
    \      if(e.cap > 0 && level[e.to] < 0) {\n                    level[e.to] = level[temp]\
    \ + 1;\n                    que.push(e.to);\n                }\n            }\n\
    \        }\n    }\n    CapTp dfs(int v, int t, CapTp f) {\n        if(v == t)\
    \ return f;\n        for(int &i = iter[v]; i<(int)G[v].size(); i++) {\n      \
    \      auto &e = G[v][i];\n            if(e.cap > 0 && level[v] < level[e.to])\
    \ {\n                CapTp d = dfs(e.to, t, min(f, e.cap));\n                if(d\
    \ > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    CapTp max_flow(int s, int t) {\n      \
    \  CapTp flow = 0.0, f;\n        while(1) {\n            bfs(s);\n           \
    \ if(level[t] < 0) return flow;\n            fill(iter.begin(), iter.end(), 0);\n\
    \            while( (f = dfs(s, t, IA)) > 0 ) flow += f;\n        }\n    }\n};\n\
    \n// \u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u30D5\u30ED\u30FC\n// u\
    \ \u304B\u3089 v \u306B\u6700\u5C0F lb, \u6700\u5927 ub \u6D41\u3059\ntemplate<typename\
    \ flow_type>\nstruct Dinic_lr {\n    Dinic<flow_type> fl;\n    int S, T;\n   \
    \ flow_type sum_lb;\n\n    Dinic_lr() {}\n    Dinic_lr(int N) : fl(N+2, 0), S(N),\
    \ T(N+1), sum_lb(0) {}\n\n    void add_edge(int u, int v, flow_type lb, flow_type\
    \ ub) {\n        assert(0 <= lb && lb <= ub);\n        if(u == v || ub == 0) return;\n\
    \        fl.add_edge(u, v, ub - lb);\n        fl.add_edge(S, v, lb);\n       \
    \ fl.add_edge(u, T, lb);\n        sum_lb += lb;\n    }\n\n    flow_type max_flow(int\
    \ s, int t) {\n        flow_type a = fl.max_flow(S, T);\n        flow_type b =\
    \ fl.max_flow(s, T);\n        flow_type c = fl.max_flow(S, t);\n        flow_type\
    \ d = fl.max_flow(s, t);\n        return (a + c == sum_lb && a + b == sum_lb)\
    \ ? b + d : -1;\n    }\n};\n"
  code: "// Dinic \u3092\u4FE1\u3058\u308D\n\ntemplate <typename CapTp=int, typename\
    \ CostTp=int>\nstruct Edge {\n    int to, rev;\n    CapTp cap; CostTp cost;\n\
    \    bool is_rev;\n    Edge(int t, bool f, int r, CapTp ca, CostTp co=0)\n   \
    \     : to(t), rev(r), cap(ca), cost(co), is_rev(f) {}\n};\n\ntemplate<typename\
    \ CapTp=int>\nstruct Dinic {\n    using Graph = vector< vector< Edge<CapTp> >\
    \ >;\n    Graph G;\n    vector<int> level, iter;\n    const CapTp IA;\n    vector<\
    \ pair<int, int> > r_edges;\n    Dinic(int N, CapTp IA_=1<<29) : IA(IA_) {\n \
    \       G.resize(N);\n        level.resize(N);\n        iter.resize(N);\n    }\n\
    \    void add_edge(int from, int to, CapTp cap) {\n        G[from].emplace_back(to,\
    \ false, G[to].size(), cap);\n        G[to].emplace_back(from, true, G[from].size()\
    \ - 1, 0);\n        r_edges.emplace_back(to, G[to].size() - 1);\n    }\n    CapTp\
    \ get_flowed_cap(size_t k) {\n        if(r_edges.size() <= k) return -1;\n   \
    \     int v, i; tie(v, i) = r_edges[k];\n        return G[v][i].cap;\n    }\n\
    \    void bfs(int s) {\n        fill(level.begin(), level.end(), -1);\n      \
    \  queue<int> que; que.push(s);\n        level[s] = 0;\n        while(!que.empty())\
    \ {\n            int temp = que.front(); que.pop();\n            for(size_t i=0;\
    \ i<G[temp].size(); i++) {\n                auto &e = G[temp][i];\n          \
    \      if(e.cap > 0 && level[e.to] < 0) {\n                    level[e.to] = level[temp]\
    \ + 1;\n                    que.push(e.to);\n                }\n            }\n\
    \        }\n    }\n    CapTp dfs(int v, int t, CapTp f) {\n        if(v == t)\
    \ return f;\n        for(int &i = iter[v]; i<(int)G[v].size(); i++) {\n      \
    \      auto &e = G[v][i];\n            if(e.cap > 0 && level[v] < level[e.to])\
    \ {\n                CapTp d = dfs(e.to, t, min(f, e.cap));\n                if(d\
    \ > 0) {\n                    e.cap -= d;\n                    G[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    CapTp max_flow(int s, int t) {\n      \
    \  CapTp flow = 0.0, f;\n        while(1) {\n            bfs(s);\n           \
    \ if(level[t] < 0) return flow;\n            fill(iter.begin(), iter.end(), 0);\n\
    \            while( (f = dfs(s, t, IA)) > 0 ) flow += f;\n        }\n    }\n};\n\
    \n// \u6700\u5C0F\u6D41\u91CF\u5236\u7D04\u4ED8\u304D\u30D5\u30ED\u30FC\n// u\
    \ \u304B\u3089 v \u306B\u6700\u5C0F lb, \u6700\u5927 ub \u6D41\u3059\ntemplate<typename\
    \ flow_type>\nstruct Dinic_lr {\n    Dinic<flow_type> fl;\n    int S, T;\n   \
    \ flow_type sum_lb;\n\n    Dinic_lr() {}\n    Dinic_lr(int N) : fl(N+2, 0), S(N),\
    \ T(N+1), sum_lb(0) {}\n\n    void add_edge(int u, int v, flow_type lb, flow_type\
    \ ub) {\n        assert(0 <= lb && lb <= ub);\n        if(u == v || ub == 0) return;\n\
    \        fl.add_edge(u, v, ub - lb);\n        fl.add_edge(S, v, lb);\n       \
    \ fl.add_edge(u, T, lb);\n        sum_lb += lb;\n    }\n\n    flow_type max_flow(int\
    \ s, int t) {\n        flow_type a = fl.max_flow(S, T);\n        flow_type b =\
    \ fl.max_flow(s, T);\n        flow_type c = fl.max_flow(S, t);\n        flow_type\
    \ d = fl.max_flow(s, t);\n        return (a + c == sum_lb && a + b == sum_lb)\
    \ ? b + d : -1;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_018_dinic.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_018_dinic.cpp
layout: document
redirect_from:
- /library/graph/graph_018_dinic.cpp
- /library/graph/graph_018_dinic.cpp.html
title: graph/graph_018_dinic.cpp
---
