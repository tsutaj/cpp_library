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
  bundledCode: "#line 1 \"graph/graph_025_2SAT.cpp\"\n// \u30AF\u30ED\u30FC\u30B8\u30E3\
    \u5185\u306B\u3042\u308B\u30EA\u30C6\u30E9\u30EB\u306E\u6570\u304C\u9AD8\u3005\
    \ 2 \u3067\u3042\u308B\u3068\u304D\u306E\u5145\u8DB3\u53EF\u80FD\u6027\u554F\u984C\
    \ (2-SAT)\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\u30E9\u30EA: SCC (graph_010_scc.cpp)\n\
    struct TwoSAT {\n    int N; Graph<> G;\n    TwoSAT(int N_) : N(N_), G(2*N_) {}\n\
    \    int neg(int k) { return (k+N) % (2*N); }\n    void add_edge(int u, int v)\
    \ {\n        G[u].emplace_back(v);\n    }\n    void add_AorB(int a, int b) {\n\
    \        // (a or b) -> (na => b) and (nb => a)\n        add_edge(neg(a), b);\n\
    \        add_edge(neg(b), a);\n    }\n    void add_NAorB(int a, int b) {\n   \
    \     // (na or b) -> (a => b) and (nb => na)\n        add_edge(a, b);\n     \
    \   add_edge(neg(b), neg(a));\n    }\n    void add_AorNB(int a, int b) {\n   \
    \     // (a or nb) -> (na => nb) and (b => a)\n        add_edge(neg(a), neg(b));\n\
    \        add_edge(b, a);\n    }\n    void add_NAorNB(int a, int b) {\n       \
    \ // not (a and b) -> (na or nb)\n        // (na or nb) -> (a => nb) and (b =>\
    \ na)\n        add_edge(a, neg(b));\n        add_edge(b, neg(a));\n    }\n   \
    \ void add_AnandB(int a, int b) {\n        add_NAorNB(neg(a), neg(b));\n    }\n\
    \    vector<int> build() {\n        GraphSCC<> scc(G);\n        vector<int> group,\
    \ res(N); int K;\n        tie(group, K) = scc.scc();\n        for(int i=0; i<N;\
    \ i++) {\n            if(group[i] == group[N+i]) return {};\n            res[i]\
    \ = (group[i] > group[N+i]);\n        }\n        return res;\n    }\n};\n"
  code: "// \u30AF\u30ED\u30FC\u30B8\u30E3\u5185\u306B\u3042\u308B\u30EA\u30C6\u30E9\
    \u30EB\u306E\u6570\u304C\u9AD8\u3005 2 \u3067\u3042\u308B\u3068\u304D\u306E\u5145\
    \u8DB3\u53EF\u80FD\u6027\u554F\u984C (2-SAT)\n// \u4F9D\u5B58\u30E9\u30A4\u30D6\
    \u30E9\u30EA: SCC (graph_010_scc.cpp)\nstruct TwoSAT {\n    int N; Graph<> G;\n\
    \    TwoSAT(int N_) : N(N_), G(2*N_) {}\n    int neg(int k) { return (k+N) % (2*N);\
    \ }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n    }\n\
    \    void add_AorB(int a, int b) {\n        // (a or b) -> (na => b) and (nb =>\
    \ a)\n        add_edge(neg(a), b);\n        add_edge(neg(b), a);\n    }\n    void\
    \ add_NAorB(int a, int b) {\n        // (na or b) -> (a => b) and (nb => na)\n\
    \        add_edge(a, b);\n        add_edge(neg(b), neg(a));\n    }\n    void add_AorNB(int\
    \ a, int b) {\n        // (a or nb) -> (na => nb) and (b => a)\n        add_edge(neg(a),\
    \ neg(b));\n        add_edge(b, a);\n    }\n    void add_NAorNB(int a, int b)\
    \ {\n        // not (a and b) -> (na or nb)\n        // (na or nb) -> (a => nb)\
    \ and (b => na)\n        add_edge(a, neg(b));\n        add_edge(b, neg(a));\n\
    \    }\n    void add_AnandB(int a, int b) {\n        add_NAorNB(neg(a), neg(b));\n\
    \    }\n    vector<int> build() {\n        GraphSCC<> scc(G);\n        vector<int>\
    \ group, res(N); int K;\n        tie(group, K) = scc.scc();\n        for(int i=0;\
    \ i<N; i++) {\n            if(group[i] == group[N+i]) return {};\n           \
    \ res[i] = (group[i] > group[N+i]);\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_025_2SAT.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_025_2SAT.cpp
layout: document
redirect_from:
- /library/graph/graph_025_2SAT.cpp
- /library/graph/graph_025_2SAT.cpp.html
title: graph/graph_025_2SAT.cpp
---
