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


# :warning: ../../structure/verify/verify_strc_004_bit_sec.cpp
* category: ../../structure/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../structure/strc_002_bit.cpp](../strc_002_bit.cpp.html)
* :warning: [../../structure/strc_004_bit_sec.cpp](../strc_004_bit_sec.cpp.html)


## Code
```cpp
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#include "../strc_002_bit.cpp"
#include "../strc_004_bit_sec.cpp"

// Verified on Apr 27, 2019
void DSL_2_G() {
    int N, Q; cin >> N >> Q;

    using ll = long long int;
    BIT_sec<ll> bit(N);
    for(int i=0; i<Q; i++) {
        int query_type; cin >> query_type;
        if(query_type == 0) {
            int s, t, x; cin >> s >> t >> x;
            bit.add(s, t, x);
        }
        if(query_type == 1) {
            int s, t; cin >> s >> t;
            cout << bit.sum(s, t) << endl;
        }
    }
}

int main() {
    DSL_2_G();
    return 0;
}

```

[Back to top page](../../../index.html)

