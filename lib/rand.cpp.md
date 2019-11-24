[トップページに戻る](../index.html)

# rand.cpp
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
*/```

[トップページに戻る](../index.html)
