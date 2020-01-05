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


# :warning: math/math_006_eulerphi.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_006_eulerphi.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// オイラーの φ 関数 (n 以下の自然数のうち n と互いに素なものの個数)
// \phi(n) = n \times \prod_{i=1}^{k} (1 - \frac{1}{p_i}) を使おう
// (ただし、 p_i は n の素因数)
// Complexity: O(sqrt n)
// Vefiried: AOJ NTL_1_D: Euler's Phi Function

int Euler_phi(int n) {
    int ret = n;
    for(int i=2; i*i <= n; i++) {
        if(n % i == 0) {
            ret -= ret / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ret -= ret / n;
    return ret;
}

// カーマイケル関数 (n と互いに素な数 p それぞれに対して、p^x ≡ 1 を満たす最小の x)
long long int Carmichael(long long int n, long long int prime=0, int pow_cnt=0) {
    if(prime == 2) {
        // n = 2^x
        if(pow_cnt == 1) return 1;
        if(pow_cnt == 2) return 2;
        return 1LL << (pow_cnt - 2);
    }
    else if(prime > 0) {
        // n = p^x (p is odd-prime number)
        return n / prime * (prime - 1);
    }
    else {
        long long int ans = 1;
        std::map<long long int, int> primes;
        for(long long int i=2; i*i<=n; i++) {
            while(n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
        if(n != 1) primes[n]++;

        for(auto x : primes) {
            long long int m = 1;
            for(int i=0; i<x.second; i++) m *= x.first;
            ans = lcm(ans, Carmichael(m, x.first, x.second));
        }
        return ans;
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/math_006_eulerphi.cpp"
// オイラーの φ 関数 (n 以下の自然数のうち n と互いに素なものの個数)
// \phi(n) = n \times \prod_{i=1}^{k} (1 - \frac{1}{p_i}) を使おう
// (ただし、 p_i は n の素因数)
// Complexity: O(sqrt n)
// Vefiried: AOJ NTL_1_D: Euler's Phi Function

int Euler_phi(int n) {
    int ret = n;
    for(int i=2; i*i <= n; i++) {
        if(n % i == 0) {
            ret -= ret / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n != 1) ret -= ret / n;
    return ret;
}

// カーマイケル関数 (n と互いに素な数 p それぞれに対して、p^x ≡ 1 を満たす最小の x)
long long int Carmichael(long long int n, long long int prime=0, int pow_cnt=0) {
    if(prime == 2) {
        // n = 2^x
        if(pow_cnt == 1) return 1;
        if(pow_cnt == 2) return 2;
        return 1LL << (pow_cnt - 2);
    }
    else if(prime > 0) {
        // n = p^x (p is odd-prime number)
        return n / prime * (prime - 1);
    }
    else {
        long long int ans = 1;
        std::map<long long int, int> primes;
        for(long long int i=2; i*i<=n; i++) {
            while(n % i == 0) {
                primes[i]++;
                n /= i;
            }
        }
        if(n != 1) primes[n]++;

        for(auto x : primes) {
            long long int m = 1;
            for(int i=0; i<x.second; i++) m *= x.first;
            ans = lcm(ans, Carmichael(m, x.first, x.second));
        }
        return ans;
    }
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

