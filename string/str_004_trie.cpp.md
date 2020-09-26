---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/verify/verify_str_004_trie.cpp
    title: string/verify/verify_str_004_trie.cpp
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"string/str_004_trie.cpp\"\n// \u30C8\u30E9\u30A4\u6728\n\
    // Vefiried: \u5929\u4E0B\u4E00\u30D7\u30ED\u30B0\u30E9\u30DE\u30FC\u30B3\u30F3\
    \u30C6\u30B9\u30C8 2016 \u672C\u6226 C: \u305F\u3093\u3054\u305F\u304F\u3055\u3093\
    \n\ntemplate <int char_size>\nstruct trie_node {\n    int nxt_node[char_size];\n\
    \    size_t child;\n    vector<int> accept;\n\n    trie_node() : child(0), accept()\
    \ {\n        fill(nxt_node, nxt_node + char_size, -1);\n    }\n    size_t size()\
    \ const { return child + accept.size(); }\n};\n\ntemplate <int char_size, int\
    \ margin>\nstruct trie {\n    using node = trie_node<char_size>;\n    vector<node>\
    \ nodes;\n    int root;\n\n    void terminate(int node_idx, int id) {\n      \
    \  nodes[node_idx].accept.emplace_back(id);\n    }\n\n    void add(const string\
    \ &s, int node_idx, size_t str_idx, int id) {\n        if(str_idx == s.size())\
    \ {\n            terminate(node_idx, id);\n        }\n        else {\n       \
    \     nodes[node_idx].child++;         \n            const int c = s[str_idx]\
    \ - margin;\n            if(nodes[node_idx].nxt_node[c] == -1) {\n           \
    \     nodes[node_idx].nxt_node[c] = nodes.size();\n                nodes.emplace_back(node());\n\
    \            }\n            add(s, nodes[node_idx].nxt_node[c], str_idx + 1, id);\n\
    \        }\n    }\n\n    void query(const string &s, function< void(int) > &f,\n\
    \               int node_idx, int str_idx, bool only_complete_match) {\n     \
    \   if(str_idx == s.size() or !only_complete_match) {\n            for(auto k\
    \ : nodes[node_idx].accept) f(k);\n        }\n        if(str_idx == s.size())\
    \ return;\n        const int c = s[str_idx] - margin;\n        if(nodes[node_idx].nxt[c]\
    \ == -1) return;\n        query(s, f, nodes[node_idx].nxt[c], str_idx + 1, only_complete_match);\n\
    \    }\n    \n    trie() : root(0) {\n        nodes.emplace_back(node());\n  \
    \  }\n\n    // \u6587\u5B57\u5217\u306E\u8FFD\u52A0 O(|S|)\n    // \u91CD\u8907\
    \u306B\u3088\u308B\u7279\u5225\u6271\u3044\u306F\u3057\u306A\u3044\u306E\u3067\
    \u3001\u8907\u6570\u56DE\u5165\u308C\u305F\u3089\u8907\u6570\u56DE\u53CD\u6620\
    \u3055\u308C\u308B\n    void add(const string &s, int id) {\n        add(s, root,\
    \ 0, id);\n    }\n\n    void add(const string &s) {\n        add(s, nodes[root].child);\n\
    \    }\n\n    // 1-indexed, O(k \u756A\u76EE\u306E\u6587\u5B57\u5217\u306E\u9577\
    \u3055 * \\sigma) \u304F\u3089\u3044\n    string kth_string(size_t k) {\n    \
    \    assert(1 <= k and k <= nodes[root].child);\n        int node_idx = root;\n\
    \        string res = \"\";\n        \n        while(k > 0) {\n            if(k\
    \ <= nodes[node_idx].accept.size()) break;\n            k -= nodes[node_idx].accept.size();\n\
    \            for(size_t i=0; i<char_size; i++) {\n                int c = nodes[node_idx].nxt_node[i];\n\
    \                if(c < 0) continue;\n                if(nodes[c].size() >= k)\
    \ {\n                    res += (char)(margin + i);\n                    node_idx\
    \ = c;\n                    break;\n                }\n                else {\n\
    \                    k -= nodes[c].size();\n                }\n            }\n\
    \        }\n        return res;\n    }\n\n    // \u6587\u5B57\u5217 s \u306E prefix\
    \ \u306B match \u3059\u308B\u6587\u5B57\u5217\u305D\u308C\u305E\u308C\u306B\u3064\
    \u3044\u3066\u3001\u4F55\u304B\u4F5C\u7528\u3055\u305B\u308B\n    // \u5B8C\u5168\
    \u4E00\u81F4\u3057\u304B\u8A31\u3055\u306A\u3044\u5834\u5408\u306F true \u3082\
    \u5F15\u6570\u306B\u4E0E\u3048\u308B\n    void query(const string &s, const function<\
    \ void(int) > &f,\n               bool only_complete_match = false) {\n      \
    \  query(s, f, 0, 0, only_complete_match);\n    }\n\n    // \u767B\u9332\u3055\
    \u308C\u3066\u3044\u308B\u6587\u5B57\u5217\u304C\u3044\u304F\u3064\u304B\n   \
    \ size_t count() const { return nodes[root].child; }\n    // \u30CE\u30FC\u30C9\
    \u6570\n    size_t size() const { return nodes.size(); }\n};\n"
  code: "// \u30C8\u30E9\u30A4\u6728\n// Vefiried: \u5929\u4E0B\u4E00\u30D7\u30ED\u30B0\
    \u30E9\u30DE\u30FC\u30B3\u30F3\u30C6\u30B9\u30C8 2016 \u672C\u6226 C: \u305F\u3093\
    \u3054\u305F\u304F\u3055\u3093\n\ntemplate <int char_size>\nstruct trie_node {\n\
    \    int nxt_node[char_size];\n    size_t child;\n    vector<int> accept;\n\n\
    \    trie_node() : child(0), accept() {\n        fill(nxt_node, nxt_node + char_size,\
    \ -1);\n    }\n    size_t size() const { return child + accept.size(); }\n};\n\
    \ntemplate <int char_size, int margin>\nstruct trie {\n    using node = trie_node<char_size>;\n\
    \    vector<node> nodes;\n    int root;\n\n    void terminate(int node_idx, int\
    \ id) {\n        nodes[node_idx].accept.emplace_back(id);\n    }\n\n    void add(const\
    \ string &s, int node_idx, size_t str_idx, int id) {\n        if(str_idx == s.size())\
    \ {\n            terminate(node_idx, id);\n        }\n        else {\n       \
    \     nodes[node_idx].child++;         \n            const int c = s[str_idx]\
    \ - margin;\n            if(nodes[node_idx].nxt_node[c] == -1) {\n           \
    \     nodes[node_idx].nxt_node[c] = nodes.size();\n                nodes.emplace_back(node());\n\
    \            }\n            add(s, nodes[node_idx].nxt_node[c], str_idx + 1, id);\n\
    \        }\n    }\n\n    void query(const string &s, function< void(int) > &f,\n\
    \               int node_idx, int str_idx, bool only_complete_match) {\n     \
    \   if(str_idx == s.size() or !only_complete_match) {\n            for(auto k\
    \ : nodes[node_idx].accept) f(k);\n        }\n        if(str_idx == s.size())\
    \ return;\n        const int c = s[str_idx] - margin;\n        if(nodes[node_idx].nxt[c]\
    \ == -1) return;\n        query(s, f, nodes[node_idx].nxt[c], str_idx + 1, only_complete_match);\n\
    \    }\n    \n    trie() : root(0) {\n        nodes.emplace_back(node());\n  \
    \  }\n\n    // \u6587\u5B57\u5217\u306E\u8FFD\u52A0 O(|S|)\n    // \u91CD\u8907\
    \u306B\u3088\u308B\u7279\u5225\u6271\u3044\u306F\u3057\u306A\u3044\u306E\u3067\
    \u3001\u8907\u6570\u56DE\u5165\u308C\u305F\u3089\u8907\u6570\u56DE\u53CD\u6620\
    \u3055\u308C\u308B\n    void add(const string &s, int id) {\n        add(s, root,\
    \ 0, id);\n    }\n\n    void add(const string &s) {\n        add(s, nodes[root].child);\n\
    \    }\n\n    // 1-indexed, O(k \u756A\u76EE\u306E\u6587\u5B57\u5217\u306E\u9577\
    \u3055 * \\sigma) \u304F\u3089\u3044\n    string kth_string(size_t k) {\n    \
    \    assert(1 <= k and k <= nodes[root].child);\n        int node_idx = root;\n\
    \        string res = \"\";\n        \n        while(k > 0) {\n            if(k\
    \ <= nodes[node_idx].accept.size()) break;\n            k -= nodes[node_idx].accept.size();\n\
    \            for(size_t i=0; i<char_size; i++) {\n                int c = nodes[node_idx].nxt_node[i];\n\
    \                if(c < 0) continue;\n                if(nodes[c].size() >= k)\
    \ {\n                    res += (char)(margin + i);\n                    node_idx\
    \ = c;\n                    break;\n                }\n                else {\n\
    \                    k -= nodes[c].size();\n                }\n            }\n\
    \        }\n        return res;\n    }\n\n    // \u6587\u5B57\u5217 s \u306E prefix\
    \ \u306B match \u3059\u308B\u6587\u5B57\u5217\u305D\u308C\u305E\u308C\u306B\u3064\
    \u3044\u3066\u3001\u4F55\u304B\u4F5C\u7528\u3055\u305B\u308B\n    // \u5B8C\u5168\
    \u4E00\u81F4\u3057\u304B\u8A31\u3055\u306A\u3044\u5834\u5408\u306F true \u3082\
    \u5F15\u6570\u306B\u4E0E\u3048\u308B\n    void query(const string &s, const function<\
    \ void(int) > &f,\n               bool only_complete_match = false) {\n      \
    \  query(s, f, 0, 0, only_complete_match);\n    }\n\n    // \u767B\u9332\u3055\
    \u308C\u3066\u3044\u308B\u6587\u5B57\u5217\u304C\u3044\u304F\u3064\u304B\n   \
    \ size_t count() const { return nodes[root].child; }\n    // \u30CE\u30FC\u30C9\
    \u6570\n    size_t size() const { return nodes.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: string/str_004_trie.cpp
  requiredBy:
  - string/verify/verify_str_004_trie.cpp
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/str_004_trie.cpp
layout: document
redirect_from:
- /library/string/str_004_trie.cpp
- /library/string/str_004_trie.cpp.html
title: string/str_004_trie.cpp
---
