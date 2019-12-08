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


# :warning: structure/verify/verify_strc_024_static_wavelet_matrix.cpp
* category: structure/verify


[Back to top page](../../../index.html)



## Dependencies
* :heavy_check_mark: [structure/strc_023_compact_bitvector.cpp](../strc_023_compact_bitvector.cpp.html)
* :heavy_check_mark: [structure/strc_024_static_wavelet_matrix.cpp](../strc_024_static_wavelet_matrix.cpp.html)


## Code
```cpp
#include <vector>
#include <array>
#include <algorithm>
#include <cinttypes>
#include <iostream>
#include <tuple>
#include <utility>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"
#include "../strc_024_static_wavelet_matrix.cpp"

int main() {
    vector<int> vec = {2, 10, 2, 3, 2, 5, 4, 4};
    WaveletMatrix<4> wm(vec);
    
    for(size_t i=0; i<vec.size(); i++) {
        cerr << wm[i] << " ";
    }
    cerr << endl;

    while(true) {
        // int k, x; cin >> k >> x; k--;
        // cout << wm.rank_idx(k, x) << endl;
        int l, r, k, x; cin >> l >> r >> k >> x; l--;
        cout << wm.select(l, r, k, x) << endl;
        // cout << res << endl;
    }
    return 0;
}

```

[Back to top page](../../../index.html)

