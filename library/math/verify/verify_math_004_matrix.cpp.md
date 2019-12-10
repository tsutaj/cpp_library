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


# :warning: math/verify/verify_math_004_matrix.cpp
<a href="../../../index.html">Back to top page</a>

* category: math/verify
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_004_matrix.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Dependencies
* :warning: <a href="../math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../math_017_modint.cpp.html">math/math_017_modint.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <cassert>
using namespace std;
#include "../math_004_matrix.cpp"
#include "../math_017_modint.cpp"

void EDPC_R() {
    using mint = ModInt<1000000007>;
    long long int N, K; cin >> N >> K;
    Matrix<mint> mat(N, N);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> mat[i][j];
        }
    }

    mat = pow(mat, K);
    mint ans(0);
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            ans += mat[i][j];
        }
    }
    cout << ans << endl;
}

// https://codeforces.com/contest/1117/problem/D
void ECR060_D() {
    long long int N, M; cin >> N >> M;
    
}

// https://codeforces.com/contest/691/problem/E
void ECR014_E() {

}

int main() {
    EDPC_R();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

