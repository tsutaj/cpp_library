// NTT (剰余環を用いた FFT)
// 任意 mod でやるなら、garner のアルゴリズム + ライブラリ下部が必須
// mod 998244353 なら NTT<998244353, 5> ntt; とかで十分です

template<ll mod, ll primitive_root>
struct NTT {
    int get_mod() const { return mod; }
    static const int P = 22;
    ll zs[P+1], zinvs[P+1];

    ll mod_pow(ll n, ll k) const {
        ll res = 1;
        for(; k>0; k>>=1) {
            if(k & 1) (res *= n) %= mod;
            (n *= n) %= mod;
        }
        return res;
    }
    
    NTT() {
        zs[P] = mod_pow(primitive_root, (mod - 1) >> P);
        zinvs[P] = mod_pow(zs[P], mod - 2);
        for(int k=P-1; k>=1; k--) {
            zs[k] = zs[k+1] * zs[k+1] % mod;
            zinvs[k] = zinvs[k+1] * zinvs[k+1] % mod;
        }
    }

    void dft(vector<ll> &A, int K, int sgn = 1) {
        int N = 1 << K;
        for(int i=0, j=1; j<N-1; j++) {
            for(int k=N >> 1; k>(i ^= k); k >>= 1);
            if(j < i) swap(A[i], A[j]);
        }
        
        for(int m=2, k=1; m<=N; m <<= 1, k++) {
            ll zeta = (sgn < 0 ? zinvs[k] : zs[k]);
            for(int i=0; i<N; i+=m) {
                ll zeta_pow = 1LL;
                for(int u=i, v=i+(m>>1); v<i+m; u++, v++) {
                    ll vl = A[u];
                    ll vr = zeta_pow * A[v] % mod;
                    A[u] = vl + vr;
                    A[v] = vl - vr + mod;
                    if(A[u] >= mod) A[u] -= mod;
                    if(A[v] >= mod) A[v] -= mod;
                    (zeta_pow *= zeta) %= mod;
                }
            }
        }
    }

    vector<ll> multiply(const vector<ll> &x, const vector<ll> &y) {
        if(x == y) return multiply(x);
        int sz = x.size() + y.size() - 1;
        int N = 1, K = 0; while(N < sz) N <<= 1, K++;
        ll inv_N = mod_pow(N, mod-2);

        vector<ll> X(N), Y(N);
        for(size_t i=0; i<x.size(); i++) X[i] = x[i];
        for(size_t i=0; i<y.size(); i++) Y[i] = y[i];
        dft(X, K), dft(Y, K);
        
        for(int i=0; i<N; i++) (X[i] *= Y[i]) %= mod;
        dft(X, K, -1);

        for(int i=0; i<sz; i++) (X[i] *= inv_N) %= mod;
        X.resize(sz);
        return X;
    }

    vector<ll> multiply(const vector<ll> &x) {
        int sz = x.size() + x.size() - 1;
        int N = 1, K = 0; while(N < sz) N <<= 1, K++;
        ll inv_N = mod_pow(N, mod-2);

        vector<ll> X(N);
        for(size_t i=0; i<x.size(); i++) X[i] = x[i];
        dft(X, K);

        for(int i=0; i<N; i++) (X[i] *= X[i]) %= mod;
        dft(X, K, -1);

        for(int i=0; i<sz; i++) (X[i] *= inv_N) %= mod;
        X.resize(sz);
        return X;
    }
};

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
