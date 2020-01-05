---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: algorithm/verify/verify_algo_002_accumulation.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#cdafa30741d8345b8ca44ea7cf563c14">algorithm/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/verify/verify_algo_002_accumulation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../algo_002_accumulation.cpp.html">algorithm/algo_002_accumulation.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
#include "../algo_002_accumulation.cpp"

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

// Verified on Apr 28, 2019 (prefix, suffix のみ)
// Judge: https://atcoder.jp/contests/abc125/tasks/abc125_c
void ABC125_C() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return gcd(a, b); });

    int ans = 0;
    for(int i=0; i<N; i++) {
        int vl = acc.get_prefix(i), vr = acc.get_suffix(i+1);
        ans = max(ans, gcd(vl, vr));
    }
    cout << ans << endl;
}

// Verified on Apr 28, 2019 (subseq のみ)
// Judge: https://atcoder.jp/contests/abc122/tasks/abc122_c
void ABC122_C() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    vector<int> A(N);
    for(int i=1; i<N; i++) {
        A[i] = (s[i-1] == 'A' and s[i] == 'C');
    }

    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return a + b; },
                          [](int a, int b) { return a - b; });

    for(int i=0; i<Q; i++) {
        int l, r; cin >> l >> r;
        cout << acc.get_subseq(l, r) << endl;
    }
}

int main() {
    // ABC125_C();
    ABC122_C();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algorithm/verify/verify_algo_002_accumulation.cpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
using namespace std;
#line 1 "algorithm/verify/../algo_002_accumulation.cpp"
// 累積演算 (0-indexed・prefix, suffix, 任意連続部分列)
// 任意連続部分列は逆演算があるときのみできる？

template <typename MonoidType>
struct Accumulation {
    int n;
    vector<MonoidType> pre, suf;
    MonoidType E;
    
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void build(int m, vector<MonoidType> vec) {
        pre = suf = vector<MonoidType>(m+1, E);
        for(int i=0; i<m; i++) {
            pre[i+1] = op(pre[i], vec[i]);
        }
        for(int i=m-1; i>=0; i--) {
            suf[i] = op(suf[i+1], vec[i]);
        }
    }

    Accumulation() {}
    Accumulation(vector<MonoidType> val_array, MonoidType E_,
                 MMtoM op_, MMtoM rop_ = MMtoM()) :
        E(E_), op(op_), rop(rop_) {
        n = val_array.size();
        build(n, val_array);
    }

    // [0, k)
    inline MonoidType get_prefix(int k) { return 0 <= k and k <= n ? pre[k] : E; }
    // [k, n)
    inline MonoidType get_suffix(int k) { return 0 <= k and k <= n ? suf[k] : E; }
    // [l, r) (rop が定義されてるときのみ)
    inline MonoidType get_subseq(int l, int r) {
        return rop(get_prefix(r), get_prefix(l));
    }
};
#line 8 "algorithm/verify/verify_algo_002_accumulation.cpp"

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

// Verified on Apr 28, 2019 (prefix, suffix のみ)
// Judge: https://atcoder.jp/contests/abc125/tasks/abc125_c
void ABC125_C() {
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return gcd(a, b); });

    int ans = 0;
    for(int i=0; i<N; i++) {
        int vl = acc.get_prefix(i), vr = acc.get_suffix(i+1);
        ans = max(ans, gcd(vl, vr));
    }
    cout << ans << endl;
}

// Verified on Apr 28, 2019 (subseq のみ)
// Judge: https://atcoder.jp/contests/abc122/tasks/abc122_c
void ABC122_C() {
    int N, Q; cin >> N >> Q;
    string s; cin >> s;

    vector<int> A(N);
    for(int i=1; i<N; i++) {
        A[i] = (s[i-1] == 'A' and s[i] == 'C');
    }

    Accumulation<int> acc(A, 0,
                          [](int a, int b) { return a + b; },
                          [](int a, int b) { return a - b; });

    for(int i=0; i<Q; i++) {
        int l, r; cin >> l >> r;
        cout << acc.get_subseq(l, r) << endl;
    }
}

int main() {
    // ABC125_C();
    ABC122_C();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

