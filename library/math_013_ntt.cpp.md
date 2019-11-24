<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_013\_ntt.cpp
---

## Code

```cpp
// NTT (剰余環を用いた FFT)
// 任意 mod でやるなら、garner のアルゴリズム + ライブラリ下部が必須
// mod 998244353 なら NTT<998244353, 5> ntt; とかで十分です

template<ll mod, ll primitive_root>
struct NTT {
    int get_mod() { return mod; }

    vector<ll> dft(vector<ll> A, int N, int sgn = 1) {
        for(int i=0, j=1; j<N-1; j++) {
            for(int k=N >> 1; k>(i ^= k); k >>= 1);
            if(j < i) swap(A[i], A[j]);
        }

        for(int m=2; m<=N; m*=2) {
            ll zeta = mod_pow(primitive_root, (mod - 1) / m, mod);
            if(sgn < 0) zeta = mod_pow(zeta, mod - 2, mod);

            for(int i=0; i<N; i+=m) {
                ll zeta_pow = 1LL;
                for(int u=i, v=i+m/2; v<i+m; u++, v++) {
                    ll vl = A[u], vr = zeta_pow * A[v] % mod;
                    A[u] = vl + vr;
                    A[v] = vl - vr + mod;
                    while(A[u] >= mod) A[u] -= mod;
                    while(A[v] >= mod) A[v] -= mod;
                    zeta_pow = zeta_pow * zeta % mod;
                }
            }
        }
        return A;
    }

    vector<ll> inv_dft(vector<ll> A, int N) {
        A = dft(A, N, -1);
        ll inv_N = mod_pow(N, mod-2, mod);
        for(int i=0; i<N; i++) {
            (A[i] *= inv_N) %= mod;
        }
        return A;
    }

    vector<ll> multiply(vector<ll> A, vector<ll> B) {
        int sz = A.size() + B.size() + 1;
        int N = 1; while(N < sz) N *= 2;

        A.resize(N), B.resize(N);
        A = dft(A, N), B = dft(B, N);

        vector<ll> F(N);
        for(int i=0; i<N; i++) {
            F[i] = (A[i] * B[i]) % mod;
        }
        return inv_dft(F, N);
    }
};

// 以下、任意 mod 用
using NTT_1 = NTT< 167772161, 3>;
using NTT_2 = NTT< 469762049, 3>;
using NTT_3 = NTT<1224736769, 3>;

vector<ll> convolution_using_ntt(vector<ll> A, vector<ll> B, ll mod) {
    for(auto &x : A) x %= mod;
    for(auto &x : B) x %= mod;

    NTT_1 ntt_1; NTT_2 ntt_2; NTT_3 ntt_3;
    vector< vector<ll> > convo(3);
    convo[0] = ntt_1.multiply(A, B);
    convo[1] = ntt_2.multiply(A, B);
    convo[2] = ntt_3.multiply(A, B);

    int N = convo[0].size();
    vector<ll> ret(N), mods(3);
    mods[0] = ntt_1.get_mod();
    mods[1] = ntt_2.get_mod();
    mods[2] = ntt_3.get_mod();

    for(int i=0; i<N; i++) {
        vector<ll> values(3);
        for(int k=0; k<3; k++) {
            values[k] = convo[k][i];
        }
        ret[i] = garner(values, mods, mod);
    }
    return ret;
}

```

[トップページに戻る](../index.html)
