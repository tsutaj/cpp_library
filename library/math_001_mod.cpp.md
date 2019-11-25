<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_001\_mod.cpp

## Code

```cpp
/***** 最大公約数・最小公倍数 *****/
// gcd (2つの整数に関して、最大公約数)
int gcd(int a, int b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    return gcd(b, a%b);
}

// lcm (2つの整数に関して、最小公倍数) ※gcd実装前提
int lcm(int a, int b) {
    return a * b / gcd(a,b);
}

// extgcd (ax + by = gcd(a,b) を満たすx,yを求める)
// xとyで参照を使用している
// (実引数で指定した変数の中身が関数によって書き換わる)
int extgcd(int a, int b, int& x, int& y) {
    int d = a;
    if(b!=0) {
        d = extgcd(b, a%b, y, x);
        y -= (a / b) * x;
    }
    else {
        x = 1; y = 0;
    }
    return d;
}

// 逆元を求める (ax ≡ 1 (mod m) に対して、xを求める。) ※extgcd実装前提
int mod_inverse(int a, int m) {
    int x,y;
    extgcd(a,m,x,y);
    return (m + x % m) % m; //正の整数を保証
}

/***** 組み合わせ関係 *****/
// combination O(N)

const int MAXN = 100010;
long long int fact[MAXN], inv[MAXN];

void init_fact() {
    fact[0] = 1;
    for(int i=1; i<MAXN; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
    }

    inv[MAXN - 1] = mod_pow(fact[MAXN - 1], MOD-2);
    for(int i=MAXN - 2; i>=0; i--) {
        inv[i] = (inv[i+1] * (i+1)) % MOD;
    }
}

long long int comb(int n, int r) {
    if(r < 0 || n < r) return 0;
    return fact[n] * inv[n-r] % MOD * inv[r] % MOD;
}

// 繰り返し二乗法 (modの世界での累乗)
// ※modが素数の場合、この関数で(mod - 2)乗したら、mod割り算ができるよ！
// (参考問題: ABC034 C問題など)
ll mod_pow(ll x, ll n) {
    ll res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

// 繰り返し二乗法 (再帰バージョン)
// typedef long long ll;
ll mod_pow(ll x, ll n) {
    if(n == 0) return 1;
    ll res = mod_pow((x * x) % MOD, n / 2);
    if(n & 1) res = (res * x) % MOD;
    return res;
}

// 組み合わせ nCr mod p を求める
ll combination_mod(ll n, ll r) {
    if(n < r) return 0;
    if(r == 0 || r == n) return 1;
    ll a = fact[n];
    ll b = fact[n-r];
    ll c = fact[r];

    ll x = a, y = (b * c) % MOD;
    return ( x * mod_pow(y, MOD-2) ) % MOD;
}

// 組み合わせを求める (DP、パスカルの三角形)
const int SIZE = 5000;
ll comb[SIZE+10][SIZE+10];

comb[0][0] = 1;
for(int i=0; i<SIZE; i++) {
    for(int j=0; j<SIZE; j++) {
        (comb[i+1][j] += comb[i][j]) %= MOD;
        (comb[i][j+1] += comb[i][j]) %= MOD;
    }
}

```

[トップページに戻る](../index.html)
