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
  bundledCode: "#line 1 \"algorithm/algo_001_mo.cpp\"\n#include <cstdio>\n#include\
    \ <vector>\n#include <algorithm>\n#include <cmath>\n#include <numeric>\nusing\
    \ namespace std;\n\n// Mo \u306E\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0 (\u4EE5\u4E0B\
    \u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3068\u304D\u306B\u30AF\u30A8\u30EA\
    \u3092\u9AD8\u901F\u306B\u51E6\u7406\u53EF\u80FD)\n// \u30FB\u30AA\u30D5\u30E9\
    \u30A4\u30F3\u30AF\u30A8\u30EA\n// \u30FB\u30AF\u30A8\u30EA\u306E\u5BFE\u8C61\u3068\
    \u306A\u308B\u6570\u5217\u304C\u4E0D\u5909\n// \u30FB\u533A\u9593\u306E\u4F38\u7E2E\
    \u306B\u304B\u304B\u308B\u8A08\u7B97\u91CF\u304C\u5C0F\u3055\u3044\nstruct Mo\
    \ {\n    enum DIRECTION {\n        LEFT = 1,\n        RIGHT = 2\n    };\n\n  \
    \  int bucket, nl, nr, ptr;\n    vector<int> left, right, query_idx;\n    vector<bool>\
    \ state;\n\n    Mo(int N) : bucket(sqrt(N) + 1), nl(0), nr(0), ptr(0), state(N)\
    \ {\n        left = right = vector<int>();\n    }\n\n    // \u533A\u9593 [l, r)\
    \ \u3092\u8FFD\u52A0\n    void insert(int l, int r) {\n        left.push_back(l);\n\
    \        right.push_back(r);\n    }\n\n    // \u30BD\u30FC\u30C8\u3059\u308B (\u30D0\
    \u30B1\u30C3\u30C8\u3054\u3068\u306B\u3001\u30D0\u30B1\u30C3\u30C8\u540C\u3058\
    \u306A\u3089\u53F3\u7AEF\u5C0F\u3055\u3044\u9806)\n    void build() {\n      \
    \  query_idx = vector<int>(left.size());\n        iota(query_idx.begin(), query_idx.end(),\
    \ 0);\n        sort(query_idx.begin(), query_idx.end(), [&](int a, int b) {\n\
    \                if(left[a] / bucket != left[b] / bucket) return left[a] < left[b];\n\
    \                return right[a] < right[b];\n            });\n    }\n    \n \
    \   // \u30AF\u30A8\u30EA\u3092\u4E00\u3064\u3059\u3059\u3081\u3066\u3001\u305D\
    \u306E\u30AF\u30A8\u30EA id \u3092\u8FD4\u3059\n    int proceed() {\n        if(ptr\
    \ == query_idx.size()) return -1;\n        int id = query_idx[ptr];\n        while(nl\
    \ > left[id] ) operate(--nl, nr, LEFT);\n        while(nr < right[id]) operate(nl,\
    \ nr++, RIGHT);\n        while(nl < left[id] ) operate(nl++, nr, LEFT);\n    \
    \    while(nr > right[id]) operate(nl, --nr, RIGHT);\n        return query_idx[ptr++];\n\
    \    }\n\n    // [l, r)\n    void operate(int l, int r, DIRECTION dir) {\n   \
    \     int idx = (dir == LEFT ? l : r);\n        state[idx].flip();\n        if(state[idx])\
    \ add(l, r, dir);\n        else del(l, r, dir);\n    }\n\n    // [l, r)\n    void\
    \ add(int l, int r, DIRECTION dir);\n    void del(int l, int r, DIRECTION dir);\n\
    };\n\n/*\nint A[200010], cnt[1000010];\nlong long int res = 0;\nvoid Mo::add(int\
    \ idx, Mo::DIRECTION dir) {\n    long long int pre = cnt[ A[idx] ];\n    long\
    \ long int nxt = pre + 1;\n    res -= pre * pre * A[idx];\n    res += nxt * nxt\
    \ * A[idx];\n    cnt[ A[idx] ]++;\n}\n\nvoid Mo::del(int idx, Mo::DIRECTION dir)\
    \ {\n    long long int pre = cnt[ A[idx] ];\n    long long int nxt = pre - 1;\n\
    \    res -= pre * pre * A[idx];\n    res += nxt * nxt * A[idx];\n    cnt[ A[idx]\
    \ ]--;\n}\n\nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    for(int\
    \ i=0; i<N; i++) {\n        scanf(\"%d\", &A[i]);\n    }\n\n    Mo mo(N);\n  \
    \  for(int i=0; i<Q; i++) {\n        int l, r; scanf(\"%d%d\", &l, &r);\n    \
    \    mo.insert(--l, r);\n    }\n\n    mo.build();\n    vector<long long int> ans(Q);\n\
    \    for(int i=0; i<Q; i++) {\n        int idx = mo.proceed();\n        // fprintf(stderr,\
    \ \"idx = %lld\\n\", idx);\n        ans[idx] = res;\n    }\n\n    for(int i=0;\
    \ i<Q; i++) {\n        printf(\"%lld\\n\", ans[i]);\n    }\n    return 0;\n}\n\
    */\n"
  code: "#include <cstdio>\n#include <vector>\n#include <algorithm>\n#include <cmath>\n\
    #include <numeric>\nusing namespace std;\n\n// Mo \u306E\u30A2\u30EB\u30B4\u30EA\
    \u30BA\u30E0 (\u4EE5\u4E0B\u306E\u6761\u4EF6\u3092\u6E80\u305F\u3059\u3068\u304D\
    \u306B\u30AF\u30A8\u30EA\u3092\u9AD8\u901F\u306B\u51E6\u7406\u53EF\u80FD)\n//\
    \ \u30FB\u30AA\u30D5\u30E9\u30A4\u30F3\u30AF\u30A8\u30EA\n// \u30FB\u30AF\u30A8\
    \u30EA\u306E\u5BFE\u8C61\u3068\u306A\u308B\u6570\u5217\u304C\u4E0D\u5909\n// \u30FB\
    \u533A\u9593\u306E\u4F38\u7E2E\u306B\u304B\u304B\u308B\u8A08\u7B97\u91CF\u304C\
    \u5C0F\u3055\u3044\nstruct Mo {\n    enum DIRECTION {\n        LEFT = 1,\n   \
    \     RIGHT = 2\n    };\n\n    int bucket, nl, nr, ptr;\n    vector<int> left,\
    \ right, query_idx;\n    vector<bool> state;\n\n    Mo(int N) : bucket(sqrt(N)\
    \ + 1), nl(0), nr(0), ptr(0), state(N) {\n        left = right = vector<int>();\n\
    \    }\n\n    // \u533A\u9593 [l, r) \u3092\u8FFD\u52A0\n    void insert(int l,\
    \ int r) {\n        left.push_back(l);\n        right.push_back(r);\n    }\n\n\
    \    // \u30BD\u30FC\u30C8\u3059\u308B (\u30D0\u30B1\u30C3\u30C8\u3054\u3068\u306B\
    \u3001\u30D0\u30B1\u30C3\u30C8\u540C\u3058\u306A\u3089\u53F3\u7AEF\u5C0F\u3055\
    \u3044\u9806)\n    void build() {\n        query_idx = vector<int>(left.size());\n\
    \        iota(query_idx.begin(), query_idx.end(), 0);\n        sort(query_idx.begin(),\
    \ query_idx.end(), [&](int a, int b) {\n                if(left[a] / bucket !=\
    \ left[b] / bucket) return left[a] < left[b];\n                return right[a]\
    \ < right[b];\n            });\n    }\n    \n    // \u30AF\u30A8\u30EA\u3092\u4E00\
    \u3064\u3059\u3059\u3081\u3066\u3001\u305D\u306E\u30AF\u30A8\u30EA id \u3092\u8FD4\
    \u3059\n    int proceed() {\n        if(ptr == query_idx.size()) return -1;\n\
    \        int id = query_idx[ptr];\n        while(nl > left[id] ) operate(--nl,\
    \ nr, LEFT);\n        while(nr < right[id]) operate(nl, nr++, RIGHT);\n      \
    \  while(nl < left[id] ) operate(nl++, nr, LEFT);\n        while(nr > right[id])\
    \ operate(nl, --nr, RIGHT);\n        return query_idx[ptr++];\n    }\n\n    //\
    \ [l, r)\n    void operate(int l, int r, DIRECTION dir) {\n        int idx = (dir\
    \ == LEFT ? l : r);\n        state[idx].flip();\n        if(state[idx]) add(l,\
    \ r, dir);\n        else del(l, r, dir);\n    }\n\n    // [l, r)\n    void add(int\
    \ l, int r, DIRECTION dir);\n    void del(int l, int r, DIRECTION dir);\n};\n\n\
    /*\nint A[200010], cnt[1000010];\nlong long int res = 0;\nvoid Mo::add(int idx,\
    \ Mo::DIRECTION dir) {\n    long long int pre = cnt[ A[idx] ];\n    long long\
    \ int nxt = pre + 1;\n    res -= pre * pre * A[idx];\n    res += nxt * nxt * A[idx];\n\
    \    cnt[ A[idx] ]++;\n}\n\nvoid Mo::del(int idx, Mo::DIRECTION dir) {\n    long\
    \ long int pre = cnt[ A[idx] ];\n    long long int nxt = pre - 1;\n    res -=\
    \ pre * pre * A[idx];\n    res += nxt * nxt * A[idx];\n    cnt[ A[idx] ]--;\n\
    }\n\nint main() {\n    int N, Q; scanf(\"%d%d\", &N, &Q);\n    for(int i=0; i<N;\
    \ i++) {\n        scanf(\"%d\", &A[i]);\n    }\n\n    Mo mo(N);\n    for(int i=0;\
    \ i<Q; i++) {\n        int l, r; scanf(\"%d%d\", &l, &r);\n        mo.insert(--l,\
    \ r);\n    }\n\n    mo.build();\n    vector<long long int> ans(Q);\n    for(int\
    \ i=0; i<Q; i++) {\n        int idx = mo.proceed();\n        // fprintf(stderr,\
    \ \"idx = %lld\\n\", idx);\n        ans[idx] = res;\n    }\n\n    for(int i=0;\
    \ i<Q; i++) {\n        printf(\"%lld\\n\", ans[i]);\n    }\n    return 0;\n}\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/algo_001_mo.cpp
  requiredBy: []
  timestamp: '2022-01-28 01:38:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/algo_001_mo.cpp
layout: document
redirect_from:
- /library/algorithm/algo_001_mo.cpp
- /library/algorithm/algo_001_mo.cpp.html
title: algorithm/algo_001_mo.cpp
---
