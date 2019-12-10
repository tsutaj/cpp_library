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


# :warning: math/verify/verify_math_020_combination.cpp
<a href="../../../index.html">Back to top page</a>

* category: math/verify
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_020_combination.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Dependencies
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_020_combination.cpp.html">math/math_020_combination.cpp</a>


## Code
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_020_combination.cpp"

// Verified on Apr 23, 2019
// DPL_5: A, B, C, D, E, F, G, I, J, L (写像 12 相)
// Judge: http://judge.u-aizu.ac.jp/onlinejudge/finder.jsp?course=DPL
using mint = ModInt<1000000007>;
const int lim = 2000010;

void DPL_5_A() {
    int N, K; cin >> N >> K;
    mint ans(K);
    cout << ans.pow(N) << endl;
}

void DPL_5_B() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.P(K, N) << endl;
}

void DPL_5_C() {
    int N, K; cin >> N >> K;

    Combination<mint> comb(lim);
    mint ans = comb.S(N, K) * comb.fact(K);
    cout << ans << endl;
}

void DPL_5_D() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.H(K, N) << endl;
}

void DPL_5_E() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(K, N) << endl;
}

void DPL_5_F() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.C(N-1, K-1) << endl;
}

void DPL_5_G() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.B(N, K) << endl;
}

void DPL_5_I() {
    int N, K; cin >> N >> K;
    Combination<mint> comb(lim);
    cout << comb.S(N, K) << endl;
}

void DPL_5_J() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N, K) << endl;
}

void DPL_5_L() {
    int N, K; cin >> N >> K;
    Partition<mint> part;
    cout << part.get(N-K, K) << endl;
}

int main() {
    // DPL_5_A();
    // DPL_5_B();
    // DPL_5_C();
    // DPL_5_D();
    // DPL_5_E();
    // DPL_5_F();
    // DPL_5_G();
    // DPL_5_I();
    // DPL_5_J();
    // DPL_5_L();
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

