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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: math/math_012_garner.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_012_garner.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Garner のアルゴリズム ( 計算量 O(N^2) )
// x ≡ a_1 (mod m_1), ..., x ≡ a_N (mod m_N) を満たす最小の x を返す
// m_1, m_2, ... m_N は相異なる素数である必要がある

// x = k_0 + k_1*m_1 + k_2*(m_1*m_2) + ... k_{N-1}*(m_1*m_2* ... *m_{N-1}) として、
// 1 つ目の式から順に操作することで係数 k_i を下から決定していく

ll mod_pow(ll X, ll N, ll mod) {
    ll ret = 1;
    for(; N>0; N>>=1) {
        if(N & 1) (ret *= X) %= mod;
        (X *= X) %= mod;
    }
    return ret;
}

ll garner(vector<ll> values, vector<ll> mods, ll mod) {
    assert(values.size() == mods.size());
    int N = values.size();
    vector<ll> coeff(N);

    for(int i=0; i<N; i++) {
        ll val_A = values[i] % mods[i];
        ll val_B = 0, mod_acc = 1;
        for(int j=0; j<i; j++) {
            (val_B += mod_acc * coeff[j]) %= mods[i];
            (mod_acc *= mods[j]) %= mods[i];
        }

        ll val = (val_A - val_B + mods[i]) % mods[i];
        (val *= mod_pow(mod_acc, mods[i]-2, mods[i])) %= mods[i];
        coeff[i] = val;
    }

    ll ans = 0, mod_acc = 1;
    for(int i=0; i<N; i++) {
        (ans += (mod_acc * coeff[i]) % mod) %= mod;
        (mod_acc *= mods[i]) %= mod;
    }
    return ans;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/math_012_garner.cpp"
// Garner のアルゴリズム ( 計算量 O(N^2) )
// x ≡ a_1 (mod m_1), ..., x ≡ a_N (mod m_N) を満たす最小の x を返す
// m_1, m_2, ... m_N は相異なる素数である必要がある

// x = k_0 + k_1*m_1 + k_2*(m_1*m_2) + ... k_{N-1}*(m_1*m_2* ... *m_{N-1}) として、
// 1 つ目の式から順に操作することで係数 k_i を下から決定していく

ll mod_pow(ll X, ll N, ll mod) {
    ll ret = 1;
    for(; N>0; N>>=1) {
        if(N & 1) (ret *= X) %= mod;
        (X *= X) %= mod;
    }
    return ret;
}

ll garner(vector<ll> values, vector<ll> mods, ll mod) {
    assert(values.size() == mods.size());
    int N = values.size();
    vector<ll> coeff(N);

    for(int i=0; i<N; i++) {
        ll val_A = values[i] % mods[i];
        ll val_B = 0, mod_acc = 1;
        for(int j=0; j<i; j++) {
            (val_B += mod_acc * coeff[j]) %= mods[i];
            (mod_acc *= mods[j]) %= mods[i];
        }

        ll val = (val_A - val_B + mods[i]) % mods[i];
        (val *= mod_pow(mod_acc, mods[i]-2, mods[i])) %= mods[i];
        coeff[i] = val;
    }

    ll ans = 0, mod_acc = 1;
    for(int i=0; i<N; i++) {
        (ans += (mod_acc * coeff[i]) % mod) %= mod;
        (mod_acc *= mods[i]) %= mod;
    }
    return ans;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

