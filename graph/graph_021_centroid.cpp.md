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
  bundledCode: "#line 1 \"graph/graph_021_centroid.cpp\"\n// \u6728\u306E\u91CD\u5FC3\
    \u5217\u6319 O(N)\n// \u91CD\u5FC3\u3092\u4E00\u3064\u6C42\u3081\u308B O(N) (\u5217\
    \u6319\u3088\u308A\u3082\u9AD8\u901F)\n// \u91CD\u5FC3\u5206\u89E3\u3059\u308B\
    \n\n#include <cstdio>\n#include <vector>\n#include <functional>\n#include <algorithm>\n\
    using namespace std;\nusing Graph = vector< vector<int> >;\nconst long long int\
    \ MOD = 1000000007;\n\n// \u6728\u306E\u91CD\u5FC3\u3092\u5217\u6319\u3059\u308B\
    \n// \u91CD\u5FC3 v \u2192 v \u3092\u6839\u3068\u3057\u305F\u6642\u306B\u3001\
    \ v \u306E\u5B50\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\
    \u30BA\u304C\u5168\u3066 N/2 \u4EE5\u4E0B\u3067\u3042\u308B\n// DFS \u3092\u3059\
    \u308B\u3053\u3068\u3067\u5BB9\u6613\u306B\u5224\u5B9A\u53EF\u80FD O(N)\nvector<int>\
    \ treeCentroid(Graph &G) {\n    int N = G.size();\n    vector<int> centroid, val(N);\n\
    \    function<void (int, int)> dfs = [&](int cur, int par) {\n        bool is_centroid\
    \ = true;\n        val[cur] = 1;\n        for(auto to : G[cur]) {\n          \
    \  if(to == par) continue;\n            dfs(to, cur);\n            val[cur] +=\
    \ val[to];\n            if(val[to] > N / 2) is_centroid = false;\n        }\n\
    \        if(N - val[cur] > N / 2) is_centroid = false;\n        if(is_centroid)\
    \ centroid.push_back(cur);\n    };\n\n    dfs(0, -1);\n    return centroid;\n\
    }\n\n// \u90E8\u5206\u6728\u306E\u91CD\u5FC3\u3092\u3072\u3068\u3064\u6C42\u3081\
    \u308B (\u901A\u884C\u3067\u304D\u306A\u3044\u9802\u70B9\u306F dead \u3067\u7BA1\
    \u7406)\n// \u5B50\u3092\u6839\u3068\u3057\u305F\u3068\u304D\u306E\u90E8\u5206\
    \u6728\u306E\u30B5\u30A4\u30BA\u304C N/2 \u3092\u8D85\u3048\u3066\u3044\u308C\u3070\
    \u3001\u305D\u306E\u5B50\u3092\u65B0\u305F\u306B\u6839\u3068\u3057\u3066\u63A2\
    \u7D22\nint oneCentroid(Graph &G, int root, vector<bool> &dead) {\n    // \u6BCE\
    \u56DE\u78BA\u4FDD\u3059\u308B\u3068\u9045\u3044\u306E\u3067\u5FC5\u305A static\
    \ \u306B\u3057\u3088\u3046\n    static vector<int> val((int)G.size());\n    function<void\
    \ (int, int)> get_size = [&](int cur, int par) {\n        val[cur] = 1;\n    \
    \    for(auto to : G[cur]) {\n            if(to == par || dead[to]) continue;\n\
    \            get_size(to, cur);\n            val[cur] += val[to];\n        }\n\
    \    };\n\n    get_size(root, -1);\n    int N = val[root];\n    function<int (int,\
    \ int)> dfs = [&](int cur, int par) {\n        for(auto to : G[cur]) {\n     \
    \       if(to == par || dead[to]) continue;\n            if(val[to] > N / 2) return\
    \ dfs(to, cur);\n        }\n        return cur;\n    };\n    return dfs(root,\
    \ -1);\n}\n\nint calc_pairs(vector<int> &paths, int k) {\n    sort(paths.begin(),\
    \ paths.end());\n\n    int N = paths.size(), idx = N - 1, ans = 0;\n    for(int\
    \ i=0; i<N; i++) {\n        while(idx >= 0 && paths[i] + paths[idx] > k) idx--;\n\
    \        ans += (idx + 1) - (idx >= i ? 1 : 0);\n    }\n    return ans / 2;\n\
    }\n\n// \u91CD\u5FC3\u5206\u89E3\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\nint centroidDecomposition(Graph\
    \ &G, int k) {\n    int N = G.size();\n\n    // \u5207\u3089\u308C\u305F\u5834\
    \u6240\n    vector<bool> dead(N, false);\n\n    int ans = 0;\n    function<void\
    \ (int)> rec = [&](int root) {\n        int c = oneCentroid(G, root, dead);\n\
    \        dead[c] = true; // \u91CD\u5FC3\u3068\u306A\u308B\u9802\u70B9\u3067\u6728\
    \u3092\u5206\u5272\u3059\u308B\n\n        // \u91CD\u5FC3\u3067\u5207\u3063\u305F\
    \u3068\u304D\u306B\u3067\u304D\u308B\u90E8\u5206\u6728\u306B\u5BFE\u3057\u3066\
    \u5024\u3092\u6C42\u3081\u308B\n        for(auto to : G[c]) {\n            if(dead[to])\
    \ continue;\n            rec(to);\n        }\n\n        // \u91CD\u5FC3\u3068\u90E8\
    \u5206\u6728\u3092\u4F7F\u3063\u3066\u30DE\u30FC\u30B8\n        // \u4E0B\u3067\
    \u306F\u3001\u9577\u3055 k \u4EE5\u4E0B\u306E\u30D1\u30B9\u306E\u6570\u3092\u6C42\
    \u3081\u3066\u3044\u308B\n\n        /*\n        vector<int> whole_paths;\n   \
    \     whole_paths.push_back(0);\n        for(auto to : G[c]) {\n            if(dead[to])\
    \ continue;\n            vector<int> paths;\n            function<void (int, int,\
    \ int)> enumerate_paths = [&](int cur, int pre, int dist) {\n                paths.push_back(dist);\n\
    \                for(auto nxt : G[cur]) {\n                    if(nxt == pre ||\
    \ dead[nxt]) continue;\n                    enumerate_paths(nxt, cur, dist + 1);\n\
    \                }\n            };\n            enumerate_paths(to, c, 1);\n \
    \           ans -= calc_pairs(paths, k);\n            ans += calc_pairs(paths,\
    \ k-1);\n            whole_paths.insert(whole_paths.end(), paths.begin(), paths.end());\n\
    \        }\n        ans += calc_pairs(whole_paths, k);\n        ans -= calc_pairs(whole_paths,\
    \ k-1);\n        */\n\n        dead[c] = false; // \u518D\u5E30\u306A\u306E\u3067\
    \u629C\u3051\u308B\u3068\u304D\u306F\u3082\u3068\u306B\u623B\u3059\n    };\n \
    \   rec(0);\n    return ans;\n}\n\nint main() {\n    int N, K; scanf(\"%d%d\"\
    , &N, &K);\n\n    Graph G(N);\n    for(int i=0; i<N-1; i++) {\n        int u,\
    \ v; scanf(\"%d%d\", &u, &v);\n        u--; v--;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    long long int val = centroidDecomposition(G,\
    \ K);\n    // cout << \"val: \" << val << endl;\n    long long int mul = ((long\
    \ long int)K * (K+1) / 2) % MOD;\n    printf(\"%lld\\n\", (val * mul) % MOD);\n\
    \    return 0;\n}\n"
  code: "// \u6728\u306E\u91CD\u5FC3\u5217\u6319 O(N)\n// \u91CD\u5FC3\u3092\u4E00\
    \u3064\u6C42\u3081\u308B O(N) (\u5217\u6319\u3088\u308A\u3082\u9AD8\u901F)\n//\
    \ \u91CD\u5FC3\u5206\u89E3\u3059\u308B\n\n#include <cstdio>\n#include <vector>\n\
    #include <functional>\n#include <algorithm>\nusing namespace std;\nusing Graph\
    \ = vector< vector<int> >;\nconst long long int MOD = 1000000007;\n\n// \u6728\
    \u306E\u91CD\u5FC3\u3092\u5217\u6319\u3059\u308B\n// \u91CD\u5FC3 v \u2192 v \u3092\
    \u6839\u3068\u3057\u305F\u6642\u306B\u3001 v \u306E\u5B50\u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u304C\u5168\u3066 N/2 \u4EE5\u4E0B\
    \u3067\u3042\u308B\n// DFS \u3092\u3059\u308B\u3053\u3068\u3067\u5BB9\u6613\u306B\
    \u5224\u5B9A\u53EF\u80FD O(N)\nvector<int> treeCentroid(Graph &G) {\n    int N\
    \ = G.size();\n    vector<int> centroid, val(N);\n    function<void (int, int)>\
    \ dfs = [&](int cur, int par) {\n        bool is_centroid = true;\n        val[cur]\
    \ = 1;\n        for(auto to : G[cur]) {\n            if(to == par) continue;\n\
    \            dfs(to, cur);\n            val[cur] += val[to];\n            if(val[to]\
    \ > N / 2) is_centroid = false;\n        }\n        if(N - val[cur] > N / 2) is_centroid\
    \ = false;\n        if(is_centroid) centroid.push_back(cur);\n    };\n\n    dfs(0,\
    \ -1);\n    return centroid;\n}\n\n// \u90E8\u5206\u6728\u306E\u91CD\u5FC3\u3092\
    \u3072\u3068\u3064\u6C42\u3081\u308B (\u901A\u884C\u3067\u304D\u306A\u3044\u9802\
    \u70B9\u306F dead \u3067\u7BA1\u7406)\n// \u5B50\u3092\u6839\u3068\u3057\u305F\
    \u3068\u304D\u306E\u90E8\u5206\u6728\u306E\u30B5\u30A4\u30BA\u304C N/2 \u3092\u8D85\
    \u3048\u3066\u3044\u308C\u3070\u3001\u305D\u306E\u5B50\u3092\u65B0\u305F\u306B\
    \u6839\u3068\u3057\u3066\u63A2\u7D22\nint oneCentroid(Graph &G, int root, vector<bool>\
    \ &dead) {\n    // \u6BCE\u56DE\u78BA\u4FDD\u3059\u308B\u3068\u9045\u3044\u306E\
    \u3067\u5FC5\u305A static \u306B\u3057\u3088\u3046\n    static vector<int> val((int)G.size());\n\
    \    function<void (int, int)> get_size = [&](int cur, int par) {\n        val[cur]\
    \ = 1;\n        for(auto to : G[cur]) {\n            if(to == par || dead[to])\
    \ continue;\n            get_size(to, cur);\n            val[cur] += val[to];\n\
    \        }\n    };\n\n    get_size(root, -1);\n    int N = val[root];\n    function<int\
    \ (int, int)> dfs = [&](int cur, int par) {\n        for(auto to : G[cur]) {\n\
    \            if(to == par || dead[to]) continue;\n            if(val[to] > N /\
    \ 2) return dfs(to, cur);\n        }\n        return cur;\n    };\n    return\
    \ dfs(root, -1);\n}\n\nint calc_pairs(vector<int> &paths, int k) {\n    sort(paths.begin(),\
    \ paths.end());\n\n    int N = paths.size(), idx = N - 1, ans = 0;\n    for(int\
    \ i=0; i<N; i++) {\n        while(idx >= 0 && paths[i] + paths[idx] > k) idx--;\n\
    \        ans += (idx + 1) - (idx >= i ? 1 : 0);\n    }\n    return ans / 2;\n\
    }\n\n// \u91CD\u5FC3\u5206\u89E3\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\nint centroidDecomposition(Graph\
    \ &G, int k) {\n    int N = G.size();\n\n    // \u5207\u3089\u308C\u305F\u5834\
    \u6240\n    vector<bool> dead(N, false);\n\n    int ans = 0;\n    function<void\
    \ (int)> rec = [&](int root) {\n        int c = oneCentroid(G, root, dead);\n\
    \        dead[c] = true; // \u91CD\u5FC3\u3068\u306A\u308B\u9802\u70B9\u3067\u6728\
    \u3092\u5206\u5272\u3059\u308B\n\n        // \u91CD\u5FC3\u3067\u5207\u3063\u305F\
    \u3068\u304D\u306B\u3067\u304D\u308B\u90E8\u5206\u6728\u306B\u5BFE\u3057\u3066\
    \u5024\u3092\u6C42\u3081\u308B\n        for(auto to : G[c]) {\n            if(dead[to])\
    \ continue;\n            rec(to);\n        }\n\n        // \u91CD\u5FC3\u3068\u90E8\
    \u5206\u6728\u3092\u4F7F\u3063\u3066\u30DE\u30FC\u30B8\n        // \u4E0B\u3067\
    \u306F\u3001\u9577\u3055 k \u4EE5\u4E0B\u306E\u30D1\u30B9\u306E\u6570\u3092\u6C42\
    \u3081\u3066\u3044\u308B\n\n        /*\n        vector<int> whole_paths;\n   \
    \     whole_paths.push_back(0);\n        for(auto to : G[c]) {\n            if(dead[to])\
    \ continue;\n            vector<int> paths;\n            function<void (int, int,\
    \ int)> enumerate_paths = [&](int cur, int pre, int dist) {\n                paths.push_back(dist);\n\
    \                for(auto nxt : G[cur]) {\n                    if(nxt == pre ||\
    \ dead[nxt]) continue;\n                    enumerate_paths(nxt, cur, dist + 1);\n\
    \                }\n            };\n            enumerate_paths(to, c, 1);\n \
    \           ans -= calc_pairs(paths, k);\n            ans += calc_pairs(paths,\
    \ k-1);\n            whole_paths.insert(whole_paths.end(), paths.begin(), paths.end());\n\
    \        }\n        ans += calc_pairs(whole_paths, k);\n        ans -= calc_pairs(whole_paths,\
    \ k-1);\n        */\n\n        dead[c] = false; // \u518D\u5E30\u306A\u306E\u3067\
    \u629C\u3051\u308B\u3068\u304D\u306F\u3082\u3068\u306B\u623B\u3059\n    };\n \
    \   rec(0);\n    return ans;\n}\n\nint main() {\n    int N, K; scanf(\"%d%d\"\
    , &N, &K);\n\n    Graph G(N);\n    for(int i=0; i<N-1; i++) {\n        int u,\
    \ v; scanf(\"%d%d\", &u, &v);\n        u--; v--;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    long long int val = centroidDecomposition(G,\
    \ K);\n    // cout << \"val: \" << val << endl;\n    long long int mul = ((long\
    \ long int)K * (K+1) / 2) % MOD;\n    printf(\"%lld\\n\", (val * mul) % MOD);\n\
    \    return 0;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/graph_021_centroid.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/graph_021_centroid.cpp
layout: document
redirect_from:
- /library/graph/graph_021_centroid.cpp
- /library/graph/graph_021_centroid.cpp.html
title: graph/graph_021_centroid.cpp
---
