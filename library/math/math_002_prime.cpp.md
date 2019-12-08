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


# :warning: math/math_002_prime.cpp
* category: math


[Back to top page](../../index.html)



## Code
```cpp
// エラトステネスの篩
// [0,n) の範囲の i について、primes[i] != 0 ⇔ i は素数
vector<int> erat(int n) {
    vector<int> primes(n);
    for (int i = 2; i < n; ++i) primes[i] = i;
    for (int i = 2; i*i < n; ++i)
        if (primes[i])
            for (int j = i*i; j < n; j+=i) primes[j] = 0;
    // 素数のみをvectorに格納する場合は以下の行を追加 (0 である要素を全削除)
    // primes.erase(remove(primes.begin(), primes.end(), 0), primes.end());
    return primes;
}

// 素数判定
bool isprime(int n) { //素数ならばtrue
    for(int i=2; i*i <= n; i++) {
        if(n%i==0) return false;
    }
    return n != 1;
}

// 素因数分解
vector<int> primeFactorization(int n) {
    int k = n;
    vector<int> ret;
    repq(i,2,sqrt(n)) {
        while(k % i == 0) {
            ret.pb(i);
            k /= i; // 重複を許さないならここを while に
        }
    }
    if(k > 1) ret.pb(k);
    return ret;
}

// ガウス素数判定
// ※複素整数(実部も虚部も整数の複素数) a + bi がガウス素数であるとは、
// これを割り切る非自明な複素整数が存在しないことを言う。

// 例: 5は素数だがガウス素数ではない ( 5 = (2+i)(2-i) )
bool isGaussianprime(Int a, Int b) {
  if (a < 0) a = -a;
  if (b < 0) b = -b;
  if (a == 0) return b % 4 == 3 && isprime(b);
  if (b == 0) return a % 4 == 3 && isprime(a);
  return isprime(a*a+b*b);
}

// 素数表の作成 (nまでの素数を配列vに格納)
int main() {
    int n;
    vector<int> v;

    cin >> n;
    v.pb(2);
    for(int i=3;i<=n;i+=2) {
        bool add = true;
        rep(j,0,v.size()) {
            if(v[j] * v[j] > i) break;
            if(i % v[j] == 0) {
                add = false;
                break;
            }
        }
        if(add) v.pb(i);
    }

    //rep(i,0,v.size()) cout << v[i] << endl;
    return 0;
}

// 約数全列挙
vector<ll> OutDivisor(ll n) {
    vector<ll> ret;
    for(ll i=1; i*i<=n; i++) {
        if(n % i == 0) {
            ret.push_back(i);
            if(i*i!=n) ret.push_back(n / i);
        }
    }
    return ret;
}
```

[Back to top page](../../index.html)

