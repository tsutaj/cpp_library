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


# :warning: math/verify/verify_math_005_matrix_mod2.cpp
<a href="../../../index.html">Back to top page</a>

* category: math/verify
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_005_matrix_mod2.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Depends On
* :warning: <a href="../math_005_matrix_mod2.cpp.html">math/math_005_matrix_mod2.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#include "../math_005_matrix_mod2.cpp"

void ARC054_C() {
    int N; cin >> N;
    BinaryMatrix mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char c; cin >> c;
            if(c == '1') mat[i][j] = 1;
        }
    }

    int d = detBinary(mat);
    if(d == 0) cout << "Even" << endl;
    else cout << "Odd" << endl;
}

void yuki_803() {
    const int B = 30;
    int N, M, X; cin >> N >> M >> X;
    BinaryMatrix mat(B+M, N+1);

    for(int j=0; j<B; j++) {
        int p = X & 1;
        mat[j][N] = p;
        X >>= 1;
    }

    for(int i=0; i<N; i++) {
        int val; cin >> val;
        for(int j=0; j<B; j++) {
            int p = val & 1;
            mat[j][i] = p;
            val >>= 1;
        }
    }

    for(int i=0; i<M; i++) {
        int t, l, r; cin >> t >> l >> r; l--;
        mat[B+i][N] = t;
        for(int x=l; x<r; x++) mat[B+i][x] = 1;
    }

    int rank = gaussianEliminationBinary(mat, true);
    for(int i=rank; i<B+M; i++) {
        if(mat[i][N] != 0) {
            cout << 0 << endl;
            return;
        }
    }

    int p = N - rank, ans = 1, MOD = 1000000007;
    for(int i=0; i<p; i++) (ans *= 2) %= MOD;
    cout << ans << endl;
}

int main() {
    // ARC054_C(); // detBinary
    // yuki_803(); // gaussianEliminationBinary
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

