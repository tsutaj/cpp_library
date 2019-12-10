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


# :warning: math/verify/verify_math_022_matrix_utils_real.cpp
<a href="../../../index.html">Back to top page</a>

* category: math/verify
* <a href="{{ site.github.repository_url }}/blob/master/math/verify/verify_math_022_matrix_utils_real.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Dependencies
* :warning: <a href="../math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="../math_022_matrix_utils_real.cpp.html">math/math_022_matrix_utils_real.cpp</a>


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
#include "../math_004_matrix.cpp"
#include "../math_022_matrix_utils_real.cpp"

void tiny_test() {
    int N, M; cin >> N >> M;
    Matrix<double> mat(N, M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> mat[i][j];
        }
    }

    cout << fixed << setprecision(12) << detReal(mat) << endl;

    vector<double> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];
    auto ans = linearEquationReal(mat, vec);
    for(auto e : ans) cout << e << " ";
    cout << endl;
}

void AOJ1328() {
    int d;
    using ld = long double;
    const ld EPS = 9e-5;
    while(cin >> d, d) {
        vector<ld> v(d+3);
        for(int i=0; i<d+3; i++) cin >> v[i];

        int row = d+3, col = d+1;
        Matrix<ld> mat(row, col);
        for(int i=0; i<row; i++) {
            ld p = 1;
            for(int j=0; j<col; j++) {
                mat[i][j] = p;
                p *= i;
            }
        }

        for(int i=0; i<row; i++) {
            vector<ld> tm = mat[i];
            ld tv = v[i];
            for(int j=0; j<col; j++) mat[i][j] = 0;
            v[i] = 0;

            auto res = linearEquationReal(mat, v, EPS);
            if(res.size()) {
                cout << i << endl;
                i = d + 5;
            }
            else {
                for(int j=0; j<col; j++) mat[i][j] = tm[j];
                v[i] = tv;
            }
        }
    }
}

int main() {
    tiny_test();
    // AOJ1328(); // linear equation
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

