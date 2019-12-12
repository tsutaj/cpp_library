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


# :warning: math/verify/verify_math_023_matrix_utils_modp.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a171886c06d04ba11b1e6cabfe6b499">math/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_023_matrix_utils_modp.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="../math_023_matrix_utils_modp.cpp.html">math/math_023_matrix_utils_modp.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
#include "../math_017_modint.cpp"
#include "../math_004_matrix.cpp"
#include "../math_023_matrix_utils_modp.cpp"


void ARC054_C() {
    using mint = ModInt<2>;
    int N; cin >> N;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = mint(1);
        }
    }

    mint d = detModp(mat);
    if(d == mint(0)) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    using mint = ModInt<2>;
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    Matrix<mint> mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = mint(p);
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = mint(p);
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationModp(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != mint(0)) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank;
    cout << ModInt<1000000007>(2).pow(p) << endl;
}

int main() {
    // ARC054_C(); // detModp
    yuki_803(); // gaussianEliminationModp
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

