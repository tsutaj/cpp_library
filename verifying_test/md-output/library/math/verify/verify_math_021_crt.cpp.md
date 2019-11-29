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
<script type="text/javascript" src="../../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: ../../math/verify/verify_math_021_crt.cpp
* category: ../../math/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../math/math_021_crt.cpp](../math_021_crt.cpp.html)


## Code
```cpp
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cassert>
#include <tuple>
using namespace std;
#include "../math_021_crt.cpp"

void yuki_186() {
    using ll = long long int;
    vector<ll> b(3), mod(3);
    for(int i=0; i<3; i++) {
        cin >> b[i] >> mod[i];
    }

    CRT<ll, (ll)2e18> crt;
    auto ans = crt.solve(b, mod);
    cout << ans.first + (ans.first == 0 ? ans.second : 0) << endl;
}

void AOJ2659() {
    using ll = long long int;
    ll N, M, D; cin >> N >> M >> D;
    vector<int> A(M);
    for(int i=0; i<M; i++) {
        cin >> A[i];
    }

    CRT<ll, (ll)1e10> crt;
    for(int i=0; i<D; i++) {
        vector<ll> b, mod;
        for(int j=0; j<M; j++) {
            int val; cin >> val;
            if(val < 0) continue;
            b.push_back(val);
            mod.push_back(A[j]);
        }
        ll so, lc; tie(so, lc) = crt.solve(b, mod);
        if(so < 0 or so > N) {
            cout << -1 << endl;
            return;
        }
        N = (N - so) / lc * lc + so;
    }
    cout << N << endl;
}

int main() {
    // yuki_186();
    AOJ2659();
    return 0;
}

```

[Back to top page](../../../index.html)

