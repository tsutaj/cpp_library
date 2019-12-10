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


# :warning: marathon/rand.cpp
<a href="../../index.html">Back to top page</a>

* category: marathon
* <a href="{{ site.github.repository_url }}/blob/master/marathon/rand.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Code
{% raw %}
```cpp
// [lb, ub] の閉区間内の値をランダムに返す構造体
// #include <random> しよう

struct Rand {
public:
    Rand() = default;
    Rand(std::mt19937::result_type seed) : eng(seed) {}
    int NextInt(int lb, int ub) {
        return std::uniform_int_distribution<int>{lb, ub}(eng);
    }
    ll NextLong(ll lb, ll ub) {
        return std::uniform_int_distribution<ll>{lb, ub}(eng);
    }
    double NextDouble(double lb, double ub) {
        return std::uniform_real_distribution<double>{lb, ub}(eng);
    }
private:
    std::mt19937 eng{std::random_device{}()};
};

/* 
// example.
int main() {
    Rand rnd(114514);
    int l, r; scanf("%d%d", &l, &r);
    printf("l = %d, r = %d, value = %d\n", l, r, rnd.NextInt(l, r));

    double L, R; scanf("%lf%lf", &L, &R);
    printf("L = %.12f, R = %.12f, value = %.12f\n", L, R, rnd.NextDouble(L, R));

    long long int a, b; scanf("%lld%lld", &a, &b);
    printf("a = %lld, b = %lld, value = %lld\n", a, b, rnd.NextLong(a, b));
    return 0;
}
*/
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

