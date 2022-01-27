---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/cartesian_tree.cpp
    title: Cartesian Tree
  - icon: ':heavy_check_mark:'
    path: graph/graph_000_basic.cpp
    title: graph/graph_000_basic.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"verifying_test/yosupo/tree/cartesian_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include <cstdio>\n\
    #include <queue>\n#include <cassert>\n#line 2 \"algorithm/cartesian_tree.cpp\"\
    \n\n/**\n * @brief Cartesian Tree\n * @docs docs/algorithm/cartesian_tree.md\n\
    \ */\n\n#include <vector>\n#include <stack>\n#include <utility>\n#include <functional>\n\
    using namespace std;\n\n#line 1 \"graph/graph_000_basic.cpp\"\n// \u79FB\u52D5\
    \u5143\u3068\u884C\u5148\u3068\u8FBA\u306E\u30B3\u30B9\u30C8\u3092\u8A18\u9332\
    \u3059\u308B\u69CB\u9020\u4F53\r\ntemplate <typename T = int>\r\nstruct Edge {\r\
    \n    int from, to;\r\n    T cost;\r\n    Edge(int s, T d = 1) : to(s), cost(d)\
    \ {}\r\n    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}\r\n\r\n    bool\
    \ operator<(const Edge &e) const {\r\n        return cost < e.cost;\r\n    }\r\
    \n    bool operator>(const Edge &e) const {\r\n        return cost > e.cost;\r\
    \n    }\r\n};\r\n\r\ntemplate <typename T = int>\r\nusing Graph = vector< vector<\
    \ Edge<T> > >;\r\n#line 15 \"algorithm/cartesian_tree.cpp\"\n\ntemplate <typename\
    \ Tp = int>\npair< Graph<>, int > getCartesianTree(const vector<Tp> &A,\n    function<bool(Tp,\
    \ Tp)> cmp = [](Tp a, Tp b) {\n        return a < b; // min\n    }\n) {\n    int\
    \ N = A.size();\n    vector<int> par(N, -1), st;\n    st.reserve(N);\n    for(int\
    \ i=0; i<N; i++) {\n        int prev_idx = -1;\n        while(st.size() and cmp(A[i],\
    \ A[st.back()])) {\n            prev_idx = st.back(); st.pop_back();\n       \
    \ }\n        if(prev_idx >= 0) {\n            par[ prev_idx ] = i;\n        }\n\
    \        if(st.size()) {\n            par[i] = st.back();\n        }\n       \
    \ st.emplace_back(i);\n    }\n\n    int root = -1;\n    Graph<> G(N);\n    for(int\
    \ i=0; i<N; i++) {\n        if(par[i] < 0) {\n            root = i;\n        }\n\
    \        else {\n            G[ par[i] ].emplace_back(i);\n        }\n    }\n\
    \    return make_pair(G, root);\n}\n#line 7 \"verifying_test/yosupo/tree/cartesian_tree.test.cpp\"\
    \n\nint main() {\n    int N; scanf(\"%d\", &N);\n\n    vector<int> A(N);\n   \
    \ for(auto &e : A) scanf(\"%d\", &e);\n\n    auto [G, root] = getCartesianTree(A);\n\
    \    vector<bool> visited(N);\n    vector<int> ans(N, root);\n    queue<int> que;\n\
    \    que.emplace(root);\n    visited[root] = true;\n    while(que.size()) {\n\
    \        int u = que.front(); que.pop();\n        for(auto e : G[u]) {\n     \
    \       int v = e.to;\n            assert(!visited[v]);\n            ans[v] =\
    \ u;\n            visited[v] = true;\n            que.emplace(v);\n        }\n\
    \    }\n\n    for(int i=0; i<N; i++) printf(\"%d%c\", ans[i], \" \\n\"[i + 1 ==\
    \ N]);\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ <cstdio>\n#include <queue>\n#include <cassert>\n#include \"../../../algorithm/cartesian_tree.cpp\"\
    \n\nint main() {\n    int N; scanf(\"%d\", &N);\n\n    vector<int> A(N);\n   \
    \ for(auto &e : A) scanf(\"%d\", &e);\n\n    auto [G, root] = getCartesianTree(A);\n\
    \    vector<bool> visited(N);\n    vector<int> ans(N, root);\n    queue<int> que;\n\
    \    que.emplace(root);\n    visited[root] = true;\n    while(que.size()) {\n\
    \        int u = que.front(); que.pop();\n        for(auto e : G[u]) {\n     \
    \       int v = e.to;\n            assert(!visited[v]);\n            ans[v] =\
    \ u;\n            visited[v] = true;\n            que.emplace(v);\n        }\n\
    \    }\n\n    for(int i=0; i<N; i++) printf(\"%d%c\", ans[i], \" \\n\"[i + 1 ==\
    \ N]);\n    return 0;\n}"
  dependsOn:
  - algorithm/cartesian_tree.cpp
  - graph/graph_000_basic.cpp
  isVerificationFile: true
  path: verifying_test/yosupo/tree/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2022-01-28 02:17:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/yosupo/tree/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/yosupo/tree/cartesian_tree.test.cpp
- /verify/verifying_test/yosupo/tree/cartesian_tree.test.cpp.html
title: verifying_test/yosupo/tree/cartesian_tree.test.cpp
---
