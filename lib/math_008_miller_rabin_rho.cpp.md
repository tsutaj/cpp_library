[トップページに戻る](../index.html)

# math\_008\_miller\_rabin\_rho.cpp
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
// ・ミラーラビン (高速な素数判定)
// ・ロー法 (高速な素因数分解)
// ・どちらも確率的なアルゴリズムであるため、小さいものは通常の素数判定で処理したほうが確実
// Verified: POJ 2429 (GCD & LCM Inverse)

int gcd(int a, int b) {
    assert(a >= 0 && b >= 0);
    if(a < b) swap(a, b);
    return (b == 0 ? a : gcd(b, a%b));
}

// 小さい数字は通常通りの素数判定で処理する (高速化のため)
const int MAX_PRIME = 300000;
const int MINI_PRIME = 40;
bool is_prime[MAX_PRIME + 10];
vector<int> primes, mini_primes;

void init_primes() {
    fill(is_prime, is_prime + MAX_PRIME + 10, true);
    is_prime[0] = is_prime[1] = false;
    for(int i=0; i<=MAX_PRIME; i++) {
        if(is_prime[i]) {
            if(i < MINI_PRIME) mini_primes.push_back(i);
            primes.push_back(i);
            for(int k=i+i; k<=MAX_PRIME; k+=i) {
                is_prime[k] = false;
            }
        }
    }
}

// ミラーラビン素数判定法 (Miller-Rabin Primality Test)
// 普通に掛け算するとオーバーフローで死ぬため、バイナリ法で処理
template<typename T>
struct MLPT {
    MLPT() {}

    T mod_mul(T a, T b, T mod) {
        T res = 0; a %= mod;
        while(b) {
            if(b & 1) (res += a) %= mod;
            a = (a + a) % mod;
            b >>= 1;
        }
        return res;
    }

    T mod_pow(T x, T n, T mod) {
        x %= mod;
        if(n == 0) return 1;
        T res = mod_pow(mod_mul(x, x, mod), n / 2, mod);
        if(n & 1) res = mod_mul(res, x, mod);
        return res;
    }

    // 小さい数なら素数判定テーブルをそのまま使う
    // 大きければしょうがないのでミラーラビンで
    bool solve(T N) {
        if(N <= MAX_PRIME) return is_prime[N];
        for(size_t i=0; i<mini_primes.size(); i++) {
            T a = mini_primes[i];
            if(N == a) return true;
            if(N % a == 0) return false;

            T d = N-1, s = 0;
            while(d % 2 == 0) d >>= 1, s++;

            if(mod_pow(a, d, N) == 1) continue;
            bool pbprime = false;
            for(int r=0; r<s; r++) {
                if(mod_pow(a, d*(1LL << r), N) == N-1) {
                    pbprime = true;
                    break;
                }
            }
            if(!pbprime) return false;
        }
        return true;
    }
};

// ロー法による素因数分解
// 対象となる数が素数の場合は常に failure -> Miller Rabin と併用しよう
template<typename T>
struct Rho {
    vector<int> pat;
    Rho() {}

    MLPT<T> ml;
    T func(T x, T c, T mod) {
        return (ml.mod_mul(x, x, mod) + c) % mod;
    }

    T check(T N, int c) {
        T x = 2, y = 2, d = 1;
        while(d == 1) {
            x = func(x, c, N);
            y = func(func(y, c, N), c, N);
            d = gcd((x-y>0 ? x-y : y-x), N);
        }
        return (d == N ? check(N, c+1) : d);
    }

    // ソートされてないので、必要だったら別途ソートしてね
    vector<T> factor(T N) {
        if(N < 2) return vector<T>();
        if(ml.solve(N)) return vector<T>(1, N);

        vector<T> res;
        // 小さい素因数は普通に素因数分解
        for(size_t i=0; i<primes.size(); i++) {
            T a = primes[i];
            if(a > N) break;
            while(N % a == 0) {
                res.push_back(a);
                N /= a;
            }
        }

        // 残ったやつはしょうがないのでロー法で
        if(N != 1) {
            if(ml.solve(N)) res.push_back(N);
            else {
                T D = check(N, 1);
                vector<T> va = factor(D), vb = factor(N / D);
                res.insert(res.end(), va.begin(), va.end());
                res.insert(res.end(), vb.begin(), vb.end());
            }
        }
        return res;
    }
};```

[トップページに戻る](../index.html)
