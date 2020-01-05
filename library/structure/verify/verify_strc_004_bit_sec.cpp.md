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


# :warning: structure/verify/verify_strc_004_bit_sec.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_004_bit_sec.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../strc_002_bit.cpp.html">structure/strc_002_bit.cpp</a>
* :warning: <a href="../strc_004_bit_sec.cpp.html">structure/strc_004_bit_sec.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "../strc_002_bit.cpp"
#include "../strc_004_bit_sec.cpp"

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;

    using ll = long long int;
    BIT_sec<ll> bit(N);
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x;
            bit.add(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t;
            cout << bit.sum(s, t) << endl;
        }
    }
}

int main() {
    DSL_2_G();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_004_bit_sec.cpp"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#line 1 "structure/verify/../strc_002_bit.cpp"
// Binary Indexed Tree (BIT)
// Verified: AOJ DSL_2_B: Range Sum Query (intのみ)

template <typename T>
struct BIT{
private:
    vector<T> array;
    int n;

public:
    // 初期化
    BIT() {}
    BIT(int _n) : array(_n + 1, 0), n(_n) {}

    // 1番目から i番目までの累積和を求める
    T sum(int i) {
        T s = 0;
        while(i > 0) {
            s += array[i];
            i -= i & -i;      // LSB 減算
        }
        return s;
    }

    // [i, j] の要素の総和
    T sum(int i, int j) {
        T ret_i = sum(i-1);
        T ret_j = sum(j);
        return ret_j - ret_i;
    }

    // i 番目に 要素 x を追加
    void add(int i, T x) {
        while(i <= n) {
            array[i] += x;
            i += i & -i;      // LSB 加算
        }
    }
};
#line 1 "structure/verify/../strc_004_bit_sec.cpp"
// 次の2つのクエリに対応するBIT
// ・[a, b) の要素全てに x を加えるクエリ
// ・[a, b) の和を計算するクエリ
// Verified: POJ 3468 (A Simple Problem with Integers)

template <typename U>
class BIT_sec {
public:
    int n;
    BIT<U> bit0, bit1;
    BIT_sec(int n_) {
        n = n_;
        bit0 = BIT<U>(n);
        bit1 = BIT<U>(n);
    }

    // 最初に要素を追加するときはこっち
    void add(int i, int x) {
        bit0.add(i, x);
    }

    // [l, r] の全要素に x を加える
    void add(int l, int r, U x) {
        bit0.add(l, -x * (l-1));
        bit1.add(l, x);
        bit0.add(r+1, x*r);
        bit1.add(r+1, -x);
    }

    U sum(int l, int r) {
        U res = 0;
        res += bit0.sum(r) + bit1.sum(r) * r;
        res -= bit0.sum(l-1) + bit1.sum(l-1) * (l-1);
        return res;
    }
};
#line 7 "structure/verify/verify_strc_004_bit_sec.cpp"

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;

    using ll = long long int;
    BIT_sec<ll> bit(N);
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x;
            bit.add(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t;
            cout << bit.sum(s, t) << endl;
        }
    }
}

int main() {
    DSL_2_G();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

