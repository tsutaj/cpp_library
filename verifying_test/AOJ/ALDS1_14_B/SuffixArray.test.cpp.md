---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/str_006_suffixarray.cpp
    title: 'Suffix Array: $O(N \log N)$'
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n// #define _GLIBCXX_DEBUG // for STL debug (optional)\n#include <iostream>\n\
    #include <iomanip>\n#include <cstdio>\n#include <string>\n#include <cstring>\n\
    #include <deque>\n#include <list>\n#include <queue>\n#include <stack>\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n#include <map>\n#include\
    \ <set>\n#include <complex>\n#include <cmath>\n#include <limits>\n#include <cfloat>\n\
    #include <climits>\n#include <ctime>\n#include <cassert>\n#include <numeric>\n\
    #include <fstream>\n#include <functional>\n#include <bitset>\nusing namespace\
    \ std;\nusing ll = long long int;\nusing int64 = long long int;\n \ntemplate<typename\
    \ T> void chmax(T &a, T b) {a = max(a, b);}\ntemplate<typename T> void chmin(T\
    \ &a, T b) {a = min(a, b);}\ntemplate<typename T> void chadd(T &a, T b) {a = a\
    \ + b;}\n \nint dx[] = {0, 0, 1, -1};\nint dy[] = {1, -1, 0, 0};\nconst int INF\
    \ = 1LL << 29;\nconst ll LONGINF = 1LL << 60;\nconst ll MOD = 1000000007LL;\n\n\
    #line 1 \"string/str_006_suffixarray.cpp\"\n// @brief Suffix Array: $O(N \\log\
    \ N)$\ntemplate <typename ArrayTp, typename ElemTp>\nstruct SuffixArray {\nprivate:\n\
    \    ArrayTp s;\n    vector<int> cmp_s;\n    ElemTp dummy;\n    vector<int> rec,\
    \ rev, lcp, cnt;\n    int len, sigma;\n\npublic:\n    // @brief dummy \u306F\u3001\
    t \u306E\u3069\u306E\u8981\u7D20\u3088\u308A\u3082\u5C0F\u3055\u3044\n    SuffixArray(ArrayTp\
    \ s_, ElemTp dummy_ = '$') : s(s_), dummy(dummy_) {\n        s.push_back(dummy);\n\
    \        len = s.size();\n\n        vector<ElemTp> seq;\n        for(const auto&\
    \ e : s) seq.emplace_back(e);\n        sort(seq.begin(), seq.end());\n       \
    \ seq.erase(unique(seq.begin(), seq.end()), seq.end());\n        sigma = seq.size();\n\
    \n        for(const auto &e : s) cmp_s.emplace_back(lower_bound(seq.begin(), seq.end(),\
    \ e) - seq.begin());\n\n        rec = get_Array();\n        rev.resize(len);\n\
    \        for(int i=0; i<len; i++) rev[ rec[i] ] = i;\n        lcp = get_LCPArray();\n\
    \    }\n\n    void dump_array(const vector<int> &indices,\n                  \
    \  const vector<int> &classes) const {\n        fprintf(stderr, \"# debug\\n\"\
    );\n        fprintf(stderr, \"# indices:\");\n        for(int i=0; i<len; i++)\
    \ fprintf(stderr, \" %d\", indices[i]);\n        fprintf(stderr, \"\\n\");\n \
    \       fprintf(stderr, \"# classes:\");\n        for(int i=0; i<len; i++) fprintf(stderr,\
    \ \" %d\", classes[i]);\n        fprintf(stderr, \"\\n\");\n    }\n    \n    vector<int>\
    \ get_Array() {\n        cnt.resize(len);\n        vector<int> indices(len), prev_idx(len);\n\
    \        vector<int> classes(len), prev_cls(len);\n        vector<int> tmp_val(len);\n\
    \n        // k == 0 \u306F\u30AB\u30A6\u30F3\u30C8\u30BD\u30FC\u30C8\u306E\u307F\
    \n        for(int i=0; i<len; i++) {\n            cnt[ cmp_s[i] ]++;\n       \
    \ }\n        for(int i=1; i<len; i++) {\n            cnt[i] += cnt[i-1];\n   \
    \     }\n        for(int i=len-1; i>=0; i--) {\n            indices[ --cnt[ cmp_s[i]\
    \ ] ] = i;\n        }\n        for(int i=1; i<len; i++) {\n            int pena\
    \ = (s[ indices[i] ] != s[ indices[i-1] ]);\n            classes[ indices[i] ]\
    \ = classes[ indices[i-1] ] + pena;\n        }\n        \n        for(int k=0;\
    \ (1 << k) < len; k++) {\n            swap(indices, prev_idx);\n            swap(classes,\
    \ prev_cls);\n            for(int i=0; i<len; i++) {\n                // \u5F8C\
    \u534A\u3060\u3051\u30BD\u30FC\u30C8\u6E08\u307F\u306B\u3057\u305F\u3082\u306E\
    \u3092 indices \u306B\u4EE3\u5165\n                prev_idx[i] = prev_idx[i] -\
    \ (1 << k);\n                if(prev_idx[i] < 0) prev_idx[i] += len;\n       \
    \         tmp_val[i] = prev_cls[ prev_idx[i] ];\n            }\n\n           \
    \ // \u524D\u534A\u306B\u3064\u3044\u3066\u30AB\u30A6\u30F3\u30C8\u30BD\u30FC\u30C8\
    \n            fill(cnt.begin(), cnt.end(), (int)0);\n            for(int i=0;\
    \ i<len; i++) {\n                cnt[ tmp_val[i] ]++;\n            }\n       \
    \     for(int i=1; i<len; i++) {\n                cnt[i] += cnt[i-1];\n      \
    \      }\n            for(int i=len-1; i>=0; i--) {\n                indices[\
    \ --cnt[ tmp_val[i] ] ] = prev_idx[i];\n            }\n            classes[ indices[0]\
    \ ] = 0;\n            for(int i=1; i<len; i++) {\n                int shift =\
    \ (1 << k);\n                pair<int, int> pre(prev_cls[ indices[i-1] ], prev_cls[\
    \ (indices[i-1] + shift) % len ]);\n                pair<int, int> cur(prev_cls[\
    \ indices[i  ] ], prev_cls[ (indices[i  ] + shift) % len ]);\n               \
    \ int pena = (pre != cur);\n                classes[ indices[i] ] = classes[ indices[i-1]\
    \ ] + pena;\n            }\n        }\n        return indices;\n    }\n\n    int\
    \ size() const {\n        return rec.size();\n    }\n    // @brief get_SA2Str:\
    \ SA \u914D\u5217\u306E idx \u756A\u76EE\u306F\u5143\u306E\u6587\u5B57\u5217\u306E\
    \u4F55\u756A\u76EE\uFF1F\n    int get_SA2Str(int idx) const {\n        assert(0\
    \ <= idx and idx < size());\n        return rec[idx];\n    }\n    // @brief get_Str2SA:\
    \ \u5143\u306E\u6587\u5B57\u5217\u306E idx \u756A\u76EE\u306F SA \u914D\u5217\u306E\
    \u4F55\u756A\u76EE\uFF1F\n    int get_Str2SA(int idx) const {\n        assert(0\
    \ <= idx and idx < size());\n        return rev[idx];\n    }\n    // @brief get_LCP:\
    \ SA \u914D\u5217\u4E0A\u306E idx, idx+1 \u756A\u76EE\u306E\u8981\u7D20\u306E\
    \ LCP \u306F\u3044\u304F\u3089\u304B\uFF1F\n    int get_LCP(int idx) const {\n\
    \        assert(0 <= idx and idx < size());\n        return lcp[idx];\n    }\n\
    \    \n    // SA \u914D\u5217\u4E0A idx \u756A\u76EE\u4EE5\u964D\u306E\u63A5\u5C3E\
    \u8F9E\u306F\u3001\u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217 p \u306B\u6BD4\u3079\
    \u3066\u5927\u304D\u3044\u304B\uFF1F\n    bool is_greater(const ArrayTp &p, int\
    \ idx) const {\n        idx = get_SA2Str(idx);\n        int N = size(), M = p.size(),\
    \ x, y;\n        for(x=idx, y=0; x<N and y<M; x++, y++) {\n            if(s[x]\
    \ > p[y]) return true;\n            if(s[x] < p[y]) return false;\n        }\n\
    \        return y >= M and x < N;\n    }\n\n    // SA \u914D\u5217\u4E0A idx \u756A\
    \u76EE\u4EE5\u964D\u306E\u63A5\u5C3E\u8F9E\u306F\u3001\u30D1\u30BF\u30FC\u30F3\
    \u6587\u5B57\u5217 p \u306B\u6BD4\u3079\u3066\u5C0F\u3055\u3044\u304B\uFF1F\n\
    \    bool is_less(const ArrayTp &p, int idx) const {\n        idx = get_SA2Str(idx);\n\
    \        int N = size(), M = p.size(), x, y;\n        for(x=idx, y=0; x<N and\
    \ y<M; x++, y++) {\n            if(s[x] < p[y]) return true;\n            if(s[x]\
    \ > p[y]) return false;\n        }\n        return x >= N and y < M;\n    }\n\n\
    \    // @brief SA \u914D\u5217\u4E0A\u306E\u3001\u30D1\u30BF\u30FC\u30F3\u6587\
    \u5B57\u5217\u3092\u8D85\u3048\u308B\u6700\u5C0F\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9: $O(|T| \\log |S|)$\n    // SA \u914D\u5217\u4E0A\u3067\u3001p \u3088\u308A\
    \u5927\u304D\u304F\u306A\u308B\u8981\u7D20\u3067\u3042\u3063\u3066\u6700\u5C0F\
    \u306E\u3082\u306E (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070 -1)\n    int binary_search_greater(const\
    \ ArrayTp &p) const {\n        int lb = -1, ub = len;\n        while(ub - lb >\
    \ 1) {\n            int mid = (ub + lb) / 2;\n            if(is_greater(p, mid))\
    \ ub = mid;\n            else lb = mid;\n        }\n\n        if(ub == len) return\
    \ -1;\n        return ub;\n    }\n\n    // @brief SA \u914D\u5217\u4E0A\u306E\u3001\
    \u30D1\u30BF\u30FC\u30F3\u6587\u5B57\u5217\u672A\u6E80\u6700\u5927\u30A4\u30F3\
    \u30C7\u30C3\u30AF\u30B9: $O(|T| \\log |S|)$\n    // SA \u914D\u5217\u4E0A\u3067\
    \u3001p \u3088\u308A\u5C0F\u3055\u304F\u306A\u308B\u8981\u7D20\u3067\u3042\u3063\
    \u3066\u6700\u5927\u306E\u3082\u306E (\u5B58\u5728\u3057\u306A\u3051\u308C\u3070\
    \ -1)\n    int binary_search_less(const ArrayTp &p) const {\n        int lb =\
    \ -1, ub = len;\n        while(ub - lb > 1) {\n            int mid = (ub + lb)\
    \ / 2;\n            if(is_less(p, mid)) lb = mid;\n            else ub = mid;\n\
    \        }\n        if(lb == -1) return -1;\n        return lb;\n    }\n\n   \
    \ // @brief LCP (SA \u914D\u5217\u4E0A\u306E i \u756A\u76EE\u3068 i+1 \u756A\u76EE\
    \u306E\u6700\u9577\u5171\u901A\u63A5\u982D\u8F9E): $O(|S|)$\n    vector<int> get_LCPArray()\
    \ {\n        vector<int> rank(len);\n        for(int i=0; i<len; i++) {\n    \
    \        rank[ rec[i] ] = i;\n        }\n\n        vector<int> res(len, -1);\n\
    \        int cons = 0;\n        // \u7A7A\u6587\u5B57\u5217\u306B\u95A2\u3057\u3066\
    \u306F\u63A2\u7D22\u3057\u306A\u3044\uFF01\n        for(int i=0; i+1<len; i++)\
    \ {\n            // i \u6587\u5B57\u76EE\u304B\u3089\u59CB\u307E\u308B\u63A5\u5C3E\
    \u8F9E\u306B\u5BFE\u3057\u3066\n            // SA \u914D\u5217\u4E0A\u3067\u76F4\
    \u524D\u306E\u8981\u7D20\u3092\u3082\u3063\u3066\u304F\u308B\n            int\
    \ pre = rec[ rank[i] - 1 ], cur = i;\n\n            while(s[cur + cons] == s[pre\
    \ + cons]) cons++;\n            res[ rank[i] - 1 ] = cons;\n            cons =\
    \ max<int>(0, cons - 1);\n        }\n        return res;\n    }\n\n    // @brief\
    \ \u6587\u5B57\u5217\u691C\u7D22: $O(|T| \\log |S|)$\n    // - \u30D1\u30BF\u30FC\
    \u30F3\u6587\u5B57\u5217\u672A\u6E80\u306B\u306A\u308B\u5834\u6240\u3092\u7279\
    \u5B9A\n    // - \u5883\u754C\u306B\u3064\u3044\u3066\u30D1\u30BF\u30FC\u30F3\u6587\
    \u5B57\u5217\u3068\u4E00\u81F4\u3059\u308B\u304B\u5224\u5B9A\n    // - LCP \u304C\
    \u5341\u5206\u5927\u304D\u3044\u9650\u308A\u9806\u756A\u306B\u964D\u308A\u3066\
    \u3044\u304F\uFF1F\n    vector<int> match(const ArrayTp &p) const {\n        int\
    \ t = binary_search_less(p) + 1;\n        int k = (t < len ? get_SA2Str(t) : len\
    \ + 1);\n\n        int N = p.size();\n        bool match_first = (k+N <= len);\n\
    \        for(int i=0; i<N and match_first; i++) match_first &= (p[i] == s[k+i]);\n\
    \        if(!match_first) return {};\n\n        vector<int> res;\n        while(t\
    \ < len) {\n            res.emplace_back(get_SA2Str(t));\n            if(get_LCP(t)\
    \ < static_cast<int>(p.size())) break;\n            t++;\n        }\n        sort(res.begin(),\
    \ res.end());\n        return res;\n    }\n};\n#line 44 \"verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp\"\
    \n\nchar buf[1 << 20];\nint main() {\n    string s, t;\n    scanf(\"%s\", buf);\
    \ s = buf;\n    scanf(\"%s\", buf); t = buf;\n    SuffixArray<string, char> sa(s,\
    \ '$');\n\n    auto ans = sa.match(t);\n    for(auto e : ans) printf(\"%d\\n\"\
    , e);\n    return 0;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n// #define _GLIBCXX_DEBUG // for STL debug (optional)\n#include <iostream>\n\
    #include <iomanip>\n#include <cstdio>\n#include <string>\n#include <cstring>\n\
    #include <deque>\n#include <list>\n#include <queue>\n#include <stack>\n#include\
    \ <vector>\n#include <utility>\n#include <algorithm>\n#include <map>\n#include\
    \ <set>\n#include <complex>\n#include <cmath>\n#include <limits>\n#include <cfloat>\n\
    #include <climits>\n#include <ctime>\n#include <cassert>\n#include <numeric>\n\
    #include <fstream>\n#include <functional>\n#include <bitset>\nusing namespace\
    \ std;\nusing ll = long long int;\nusing int64 = long long int;\n \ntemplate<typename\
    \ T> void chmax(T &a, T b) {a = max(a, b);}\ntemplate<typename T> void chmin(T\
    \ &a, T b) {a = min(a, b);}\ntemplate<typename T> void chadd(T &a, T b) {a = a\
    \ + b;}\n \nint dx[] = {0, 0, 1, -1};\nint dy[] = {1, -1, 0, 0};\nconst int INF\
    \ = 1LL << 29;\nconst ll LONGINF = 1LL << 60;\nconst ll MOD = 1000000007LL;\n\n\
    #include \"../../../string/str_006_suffixarray.cpp\"\n\nchar buf[1 << 20];\nint\
    \ main() {\n    string s, t;\n    scanf(\"%s\", buf); s = buf;\n    scanf(\"%s\"\
    , buf); t = buf;\n    SuffixArray<string, char> sa(s, '$');\n\n    auto ans =\
    \ sa.match(t);\n    for(auto e : ans) printf(\"%d\\n\", e);\n    return 0;\n}\n"
  dependsOn:
  - string/str_006_suffixarray.cpp
  isVerificationFile: true
  path: verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp
  requiredBy: []
  timestamp: '2020-01-11 16:26:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp
- /verify/verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp.html
title: verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp
---
