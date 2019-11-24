[トップページに戻る](../index.html)

# math\_012\_garner.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

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

[トップページに戻る](../index.html)
