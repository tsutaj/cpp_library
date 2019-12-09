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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: math/verify/verify_math_019_specific_ragrange_polynomial.cpp
* category: math/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [math/math_017_modint.cpp](../math_017_modint.cpp.html)
* :warning: [math/math_019_specific_ragrange_polynomial.cpp](../math_019_specific_ragrange_polynomial.cpp.html)
* :warning: [math/math_020_combination.cpp](../math_020_combination.cpp.html)


## Code
{% raw %}
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_020_combination.cpp"
#include "../math_019_specific_ragrange_polynomial.cpp"

// Verified on Apr 23, 2019
// Educational Codeforces Round 63 E: Guess the Root
// Judge: https://codeforces.com/contest/1155/problem/E
// TLE が厳しいので逆元は前計算しないと通りません
// あと f(0) から f(N) までわかっていれば O(N) でできるのでそちらの戦略のほうがよいかも
void ECR065_E() {
    const int MOD = 1000003;
    using mint = ModInt<MOD>;

    const int DEG = 11;
    auto eval_expr = [&](vector<mint> &expr, mint x) {
        mint base(1), res(0);
        for(int i=0; i<DEG; i++) {
            res += expr[i] * base;
            base *= x;
        }
        return res;
    };
    
    vector<mint> x, y, expr;
    vector<int> raw_expr = {1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};
    for(int i=0; i<DEG; i++) {
        expr.emplace_back(mint(raw_expr[i]));
    }
    
    for(int i=0; i<DEG; i++) {
        x.push_back(mint(i));
        cout << "? " << i << endl;
        int res;
        cin >> res;
        // res = eval_expr(expr, i).v;
        y.push_back(mint(res));
    }

    SpecificLagrangePolynomial<mint> lp(y, MOD);
    for(int i=0; i<MOD; i++) {
        if(lp.interpolate(i) == mint(0)) {
            cout << "! " << i << endl;
            return;
        }
    }
    cout << "! " << -1 << endl;
}

// Verified on Apr 23, 2019
// AtCoder Regular Contest 033 F (旧 D): 見たことのない多項式
// Judge: https://arc033.contest.atcoder.jp/tasks/arc033_4
void ARC033_F() {
    const int MOD = 1000000007;
    using mint = ModInt<MOD>;

    int N; cin >> N;
    vector<mint> y(N+1);
    for(int i=0; i<=N; i++) cin >> y[i];

    int T; cin >> T;
    SpecificLagrangePolynomial<mint> lp(y);
    cout << lp.interpolate(T) << endl;
}

int main() {
    // ECR065_E();
    ARC033_F();
    return 0;
}

```
{% endraw %}

[Back to top page](../../../index.html)

