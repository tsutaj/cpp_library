<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# math\_006\_eulerphi.cpp
---

## Code

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

[トップページに戻る](../index.html)
