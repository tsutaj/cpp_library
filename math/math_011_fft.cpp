// FFT (高速フーリエ変換)
// Verified: 高速フーリエ変換 (ATC 001 C)
template < typename Tp = complex<double> >
struct FFT {
    static constexpr long double PI = acos(-1.0L);
    static constexpr int P = 22;
    Tp zs[P+1], zinvs[P+1];

    FFT () {
        for(int i=0, m=1; i<=P; i++, m<<=1) {
            long double rad = 2.0 * PI / m;
            long double cr = cos(rad), sr = sin(rad);
            zs[i] = Tp(cr, sr);
            zinvs[i] = Tp(cr, -sr);
        }
    }
    
    void dft(vector<Tp> &A, int K, int sgn = 1) {
        int N = 1 << K;
        for(int i=0, j=1; j<N-1; j++) {
            for(int k=N >> 1; k>(i ^= k); k >>= 1);
            if(j < i) swap(A[i], A[j]);
        }

        for(int m=2, k=1; m<=N; m<<=1, k++) {
            Tp zeta = (sgn < 0 ? zinvs[k] : zs[k]);

            for(int i=0; i<N; i+=m) {
                Tp zeta_pow = 1;
                for(int u=i, v=i+m/2; v<i+m; u++, v++) {
                    Tp vl = A[u], vr = zeta_pow * A[v];
                    A[u] = vl + vr;
                    A[v] = vl - vr;
                    zeta_pow = zeta_pow * zeta;
                }
            }
        }
    }

    vector<Tp> multiply(const vector<Tp> &x, const vector<Tp> &y) {
        int sz = x.size() + y.size() + 1;
        int N = 1, K = 0; while(N < sz) N <<= 1, K++;

        vector<Tp> X(N), Y(N);
        for(size_t i=0; i<x.size(); i++) X[i] = x[i];
        for(size_t i=0; i<y.size(); i++) Y[i] = y[i];
        dft(X, K), dft(Y, K);

        for(int i=0; i<N; i++) X[i] *= Y[i];
        dft(X, K, -1);
        for(int i=0; i<sz; i++) X[i] /= N;
        X.resize(sz);
        return X;
    }

    vector<Tp> multiply(const vector<Tp> &x) {
        int sz = x.size() + x.size() + 1;
        int N = 1, K = 0; while(N < sz) N <<= 1, K++;

        vector<Tp> X(N);
        for(size_t i=0; i<x.size(); i++) X[i] = x[i];
        dft(X, K);

        for(int i=0; i<N; i++) X[i] *= X[i];
        dft(X, K, -1);
        for(int i=0; i<sz; i++) X[i] /= N;
        X.resize(sz);
        return X;
    }
};
