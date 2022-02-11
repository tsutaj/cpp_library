---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/linear_system_incidence.cpp
    title: "\u63A5\u7D9A\u884C\u5217\u3092\u4FC2\u6570\u306B\u6301\u3064\u7DDA\u5F62\
      \u65B9\u7A0B\u5F0F\u306E\u30BD\u30EB\u30D0"
  - icon: ':x:'
    path: math/math_017_modint.cpp
    title: math/math_017_modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    IGNORE: ''
    IGNORE_IF_CLANG: ''
    IGNORE_IF_GCC: ''
    links:
    - https://atcoder.jp/contests/abc155/tasks/abc155_f
  bundledCode: "#line 1 \"verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp\"\
    \n#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc155/tasks/abc155_f\"\
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
    #line 2 \"graph/linear_system_incidence.cpp\"\n\n/**\n * @brief \u63A5\u7D9A\u884C\
    \u5217\u3092\u4FC2\u6570\u306B\u6301\u3064\u7DDA\u5F62\u65B9\u7A0B\u5F0F\u306E\
    \u30BD\u30EB\u30D0\n * @docs docs/graph/linear_system_incidence.md\n */\n\n#line\
    \ 10 \"graph/linear_system_incidence.cpp\"\n#include <tuple>\n#line 12 \"graph/linear_system_incidence.cpp\"\
    \n\ntemplate <typename Tp>\nclass LinearSystemIncidence {\npublic:\n    struct\
    \ Edge {\n        int id, to;\n        bool is_forward;\n        Edge(int id,\
    \ int to, int is_forward) : id(id), to(to), is_forward(is_forward) {}\n    };\n\
    \n    LinearSystemIncidence(int N, const vector< pair<int, int> >& edges) : N(N),\
    \ M(edges.size()), G(N) {\n        for(int i=0; i<M; i++) {\n            int u,\
    \ v; tie(u, v) = edges[i];\n            G[u].emplace_back(i, v, true);\n     \
    \       G[v].emplace_back(i, u, false);\n        }\n    }\n\n    Tp dfs(int u,\
    \ const vector<Tp> &b) {\n        assert(!used[u]);\n        used[u] = true;\n\
    \        Tp res = b[u];\n        for(const auto &e : G[u]) {\n            if(used[e.to])\
    \ continue;\n            Tp res_to = dfs(e.to, b);\n            if(e.is_forward)\
    \ x[e.id] = res_to;\n            else x[e.id] = -res_to;\n            res += res_to;\n\
    \        }\n        return res;\n    }\n\n    pair< bool, vector<Tp> > solve(vector<Tp>\
    \ &b) {\n        assert(static_cast<int>(b.size()) == N);\n        used.assign(N,\
    \ false);\n        x.assign(M, Tp(0));\n        for(int i=0; i<N; i++) {\n   \
    \         if(used[i]) continue;\n            Tp v = dfs(i, b);\n            if(v\
    \ != Tp(0)) return make_pair(false, vector<Tp>());\n        }\n        return\
    \ {true, move(x)};\n    }\n\nprivate:\n    int N, M;\n    vector< vector<Edge>\
    \ > G;\n    vector<bool> used;\n    vector<Tp> x; // Ax = b\n};\n#line 1 \"math/math_017_modint.cpp\"\
    \n// ModInt begin\r\n\r\nusing ll = long long;\r\ntemplate<ll mod>\r\nstruct ModInt\
    \ {\r\n    ll v;\r\n    ll mod_pow(ll x, ll n) const {\r\n        return (!n)\
    \ ? 1 : (mod_pow((x*x)%mod,n/2) * ((n&1)?x:1)) % mod;\r\n    }\r\n    ModInt(ll\
    \ a = 0) : v((a %= mod) < 0 ? a + mod : a) {}\r\n    ModInt operator+ ( const\
    \ ModInt& b ) const {\r\n        return (v + b.v >= mod ? ModInt(v + b.v - mod)\
    \ : ModInt(v + b.v));\r\n    }\r\n    ModInt operator- () const {\r\n        return\
    \ ModInt(-v);\r\n    }\r\n    ModInt operator- ( const ModInt& b ) const {\r\n\
    \        return (v - b.v < 0 ? ModInt(v - b.v + mod) : ModInt(v - b.v));\r\n \
    \   }\r\n    ModInt operator* ( const ModInt& b ) const {return (v * b.v) % mod;}\r\
    \n    ModInt operator/ ( const ModInt& b ) const {return (v * mod_pow(b.v, mod-2))\
    \ % mod;}\r\n    \r\n    bool operator== ( const ModInt &b ) const {return v ==\
    \ b.v;}\r\n    bool operator!= ( const ModInt &b ) const {return !(*this == b);\
    \ }\r\n    ModInt& operator+= ( const ModInt &b ) {\r\n        v += b.v;\r\n \
    \       if(v >= mod) v -= mod;\r\n        return *this;\r\n    }\r\n    ModInt&\
    \ operator-= ( const ModInt &b ) {\r\n        v -= b.v;\r\n        if(v < 0) v\
    \ += mod;\r\n        return *this;\r\n    }\r\n    ModInt& operator*= ( const\
    \ ModInt &b ) {\r\n        (v *= b.v) %= mod;\r\n        return *this;\r\n   \
    \ }\r\n    ModInt& operator/= ( const ModInt &b ) {\r\n        (v *= mod_pow(b.v,\
    \ mod-2)) %= mod;\r\n        return *this;\r\n    }\r\n    ModInt pow(ll x) {\
    \ return ModInt(mod_pow(v, x)); }\r\n    // operator int() const { return int(v);\
    \ }\r\n    // operator long long int() const { return v; }\r\n};\r\n\r\ntemplate<ll\
    \ mod>\r\nModInt<mod> pow(ModInt<mod> n, ll k) {\r\n    return ModInt<mod>(n.mod_pow(n.v,\
    \ k));\r\n}\r\n\r\ntemplate<ll mod>\r\nostream& operator<< (ostream& out, ModInt<mod>\
    \ a) {return out << a.v;}\r\ntemplate<ll mod>\r\nistream& operator>> (istream&\
    \ in, ModInt<mod>& a) {\r\n    in >> a.v;\r\n    return in;\r\n}\r\n\r\n// ModInt\
    \ end\r\n#line 46 \"verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp\"\
    \nusing mint = ModInt<2>;\n \nint main() {\n    int N, M; cin >> N >> M;\n   \
    \ vector< pair<int, int> > bomb;\n    for(int i=0; i<N; i++) {\n        int A,\
    \ B; cin >> A >> B;\n        bomb.emplace_back(A, B);\n    }\n    sort(bomb.begin(),\
    \ bomb.end());\n\n    // \u96A3\u63A5 xor\n    vector<mint> b(N + 1);\n    b[0]\
    \ = mint(bomb.front().second);\n    for(int i=0; i+1<N; i++) {\n        b[i+1]\
    \ = mint(bomb[i].second ^ bomb[i+1].second);\n    }\n    b[N] = mint(bomb.back().second);\n\
    \n    vector< pair<int, int> > edges;\n    vector<int> ids;\n    for(int i=0;\
    \ i<M; i++) {\n        int L, R; cin >> L >> R;\n        // \u7BC4\u56F2\u5185\
    \u306B\u3042\u308B\u7206\u5F3E\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 [bl,\
    \ br)\n        int bl = lower_bound(bomb.begin(), bomb.end(), make_pair(L, 0))\
    \ - bomb.begin();\n        int br = upper_bound(bomb.begin(), bomb.end(), make_pair(R,\
    \ 1)) - bomb.begin();\n\n        if(bl >= br) continue;\n        edges.emplace_back(bl,\
    \ br);\n        ids.emplace_back(i);\n    }\n    M = edges.size();\n\n    // Ax\
    \ + b = 0 -> Ax = b (mod 2)\n    LinearSystemIncidence<mint> lsi(N+1, edges);\n\
    \    auto ans = lsi.solve(b);\n    if(!ans.first) cout << -1 << endl;\n    else\
    \ {\n        vector<int> vec;\n        for(int i=0; i<M; i++) {\n            if(ans.second[i]\
    \ == mint(1)) vec.emplace_back(ids[i]);\n        }\n\n        cout << vec.size()\
    \ << endl;\n        for(size_t i=0; i<vec.size(); i++) cout << vec[i] + 1 << \"\
    \ \\n\"[i + 1 == vec.size()];\n    }\n    return 0;\n}\n"
  code: "#define IGNORE\n#define PROBLEM \"https://atcoder.jp/contests/abc155/tasks/abc155_f\"\
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
    #include \"../../../graph/linear_system_incidence.cpp\"\n#include \"../../../math/math_017_modint.cpp\"\
    \nusing mint = ModInt<2>;\n \nint main() {\n    int N, M; cin >> N >> M;\n   \
    \ vector< pair<int, int> > bomb;\n    for(int i=0; i<N; i++) {\n        int A,\
    \ B; cin >> A >> B;\n        bomb.emplace_back(A, B);\n    }\n    sort(bomb.begin(),\
    \ bomb.end());\n\n    // \u96A3\u63A5 xor\n    vector<mint> b(N + 1);\n    b[0]\
    \ = mint(bomb.front().second);\n    for(int i=0; i+1<N; i++) {\n        b[i+1]\
    \ = mint(bomb[i].second ^ bomb[i+1].second);\n    }\n    b[N] = mint(bomb.back().second);\n\
    \n    vector< pair<int, int> > edges;\n    vector<int> ids;\n    for(int i=0;\
    \ i<M; i++) {\n        int L, R; cin >> L >> R;\n        // \u7BC4\u56F2\u5185\
    \u306B\u3042\u308B\u7206\u5F3E\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9 [bl,\
    \ br)\n        int bl = lower_bound(bomb.begin(), bomb.end(), make_pair(L, 0))\
    \ - bomb.begin();\n        int br = upper_bound(bomb.begin(), bomb.end(), make_pair(R,\
    \ 1)) - bomb.begin();\n\n        if(bl >= br) continue;\n        edges.emplace_back(bl,\
    \ br);\n        ids.emplace_back(i);\n    }\n    M = edges.size();\n\n    // Ax\
    \ + b = 0 -> Ax = b (mod 2)\n    LinearSystemIncidence<mint> lsi(N+1, edges);\n\
    \    auto ans = lsi.solve(b);\n    if(!ans.first) cout << -1 << endl;\n    else\
    \ {\n        vector<int> vec;\n        for(int i=0; i<M; i++) {\n            if(ans.second[i]\
    \ == mint(1)) vec.emplace_back(ids[i]);\n        }\n\n        cout << vec.size()\
    \ << endl;\n        for(size_t i=0; i<vec.size(); i++) cout << vec[i] + 1 << \"\
    \ \\n\"[i + 1 == vec.size()];\n    }\n    return 0;\n}\n"
  dependsOn:
  - graph/linear_system_incidence.cpp
  - math/math_017_modint.cpp
  isVerificationFile: true
  path: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
  requiredBy: []
  timestamp: '2022-02-11 15:15:07+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
layout: document
redirect_from:
- /verify/verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
- /verify/verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp.html
title: verifying_test/AtCoder/ABC155/linear_system_incidence.test.cpp
---
