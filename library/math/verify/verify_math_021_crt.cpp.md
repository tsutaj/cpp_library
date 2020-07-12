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


# :warning: math/verify/verify_math_021_crt.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_021_crt.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../math_021_crt.cpp.html">math/math_021_crt.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>
using namespace std;
#include "../math_021_crt.cpp"

void yuki_186() {
    using ll = long long int;
    vector<ll> b(3), mod(3);
    for(int i=0; i<3; i++) {
        cin >> b[i] >> mod[i];
    }

    CRT<ll, (ll)2e18> crt;
    auto ans = crt.solve(b, mod);
    cout << ans.first + (ans.first == 0 ? ans.second : 0) << endl;
}

void AOJ2659() {
    using ll = long long int;
    ll N, M, D; cin >> N >> M >> D;
    vector<int> A(M);
    for(int i=0; i<M; i++) {
        cin >> A[i];
    }

    CRT<ll, (ll)1e10> crt;
    for(int i=0; i<D; i++) {
        vector<ll> b, mod;
        for(int j=0; j<M; j++) {
            int val; cin >> val;
            if(val < 0) continue;
            b.push_back(val);
            mod.push_back(A[j]);
        }
        ll so, lc; tie(so, lc) = crt.solve(b, mod);
        if(so < 0 or so > N) {
            cout << -1 << endl;
            return;
        }
        N = (N - so) / lc * lc + so;
    }
    cout << N << endl;
}

int main() {
    // yuki_186();
    AOJ2659();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/verify/verify_math_021_crt.cpp"
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>
using namespace std;
#line 1 "math/math_021_crt.cpp"
// 中国剰余定理
// x = b_1 (mod_1), ..., x = b_k (mod_k), ... を満たす x を
// 0 <= x < lcm(mod_1, mod_2, ..., mod_k, ...) の範囲で求める

template <typename NumType, NumType LIMIT = NumType(1e10)>
struct CRT {
    pair<NumType, NumType> NIL;
    CRT() : NIL(-1, -1) {}
    
    NumType extgcd(NumType a, NumType b, NumType &p, NumType &q) {
        if(b == 0) {
            p = 1, q = 0;
            return a;
        }
        NumType d = extgcd(b, a%b, q, p);
        q -= a / b * p;
        return d;
    }

    pair<NumType, NumType> solve(NumType b1, NumType mod1, NumType b2, NumType mod2) {
        NumType p, q;
        NumType d = extgcd(mod1, mod2, p, q);
        
        if((b2 - b1) % d != 0) return NIL;
        NumType s = (b2 - b1) / d;
        NumType t = (s * p % (mod2 / d));

        // get lcm
        NumType lc = mod1 / d * mod2;
        NumType so = (b1 + mod1 * t) % lc;
        (so += lc) %= lc;
        return make_pair(so, lc);
    }

    // m, mod の vector をもらって、
    // CRT の解を (x, lcm(mod_1, mod_2, ..., mod_k, ...)) の形で返す
    pair<NumType, NumType> solve(vector<NumType> m, vector<NumType> mod) {
        assert(m.size() == mod.size());
        NumType so = 0, lc = 1;
        for(size_t i=0; i<m.size(); i++) {
            tie(so, lc) = solve(so, lc, m[i], mod[i]);
            if(so > LIMIT or so < 0) {
                return NIL;
            }
        }
        return make_pair(so, lc);
    }
};
#line 9 "math/verify/verify_math_021_crt.cpp"

void yuki_186() {
    using ll = long long int;
    vector<ll> b(3), mod(3);
    for(int i=0; i<3; i++) {
        cin >> b[i] >> mod[i];
    }

    CRT<ll, (ll)2e18> crt;
    auto ans = crt.solve(b, mod);
    cout << ans.first + (ans.first == 0 ? ans.second : 0) << endl;
}

void AOJ2659() {
    using ll = long long int;
    ll N, M, D; cin >> N >> M >> D;
    vector<int> A(M);
    for(int i=0; i<M; i++) {
        cin >> A[i];
    }

    CRT<ll, (ll)1e10> crt;
    for(int i=0; i<D; i++) {
        vector<ll> b, mod;
        for(int j=0; j<M; j++) {
            int val; cin >> val;
            if(val < 0) continue;
            b.push_back(val);
            mod.push_back(A[j]);
        }
        ll so, lc; tie(so, lc) = crt.solve(b, mod);
        if(so < 0 or so > N) {
            cout << -1 << endl;
            return;
        }
        N = (N - so) / lc * lc + so;
    }
    cout << N << endl;
}

int main() {
    // yuki_186();
    AOJ2659();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
