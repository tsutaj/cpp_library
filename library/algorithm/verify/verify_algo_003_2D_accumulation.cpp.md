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


# :warning: algorithm/verify/verify_algo_003_2D_accumulation.cpp
<a href="../../../index.html">Back to top page</a>

* category: algorithm/verify
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/verify/verify_algo_003_2D_accumulation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Dependencies
* :warning: <a href="../algo_003_2D_accumulation.cpp.html">algorithm/algo_003_2D_accumulation.cpp</a>


## Code
{% raw %}
```cpp
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cassert>
using namespace std;
#include "../algo_003_2D_accumulation.cpp"

void ARC025_B() {
    int H, W; cin >> H >> W;
    vector< vector<int> > mat(H, vector<int>(W));

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            int val; cin >> val;
            if((i + j) % 2) mat[i][j] += val;
            else mat[i][j] -= val;
        }
    }

    Accumulation2D<int> acc(mat, 0,
                            [](int a, int b) { return a + b; },
                            [](int a, int b) { return a - b; });

    int ans = 0;
    for(int lx=0; lx<H; lx++) {
        for(int rx=lx+1; rx<=H; rx++) {
            for(int ly=0; ly<W; ly++) {
                for(int ry=ly+1; ry<=W; ry++) {
                    if(acc.range_val(lx, ly, rx, ry) == 0) {
                        int cand = (rx - lx) * (ry - ly);
                        ans = max(ans, cand);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

void ARC025_B_alter() {
    int H, W; cin >> H >> W;
    Accumulation2D<int> acc(H, W, 0,
                            [](int a, int b) { return a + b; },
                            [](int a, int b) { return a - b; });

    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            int val; cin >> val;
            if((i + j) % 2) acc.range_add(i, j, i+1, j+1, val);
            else acc.range_add(i, j, i+1, j+1, -val);
        }
    }
    acc.build(); // imos
    acc.build(); // accumulation

    int ans = 0;
    for(int lx=0; lx<H; lx++) {
        for(int rx=lx+1; rx<=H; rx++) {
            for(int ly=0; ly<W; ly++) {
                for(int ry=ly+1; ry<=W; ry++) {
                    if(acc.range_val(lx, ly, rx, ry) == 0) {
                        int cand = (rx - lx) * (ry - ly);
                        ans = max(ans, cand);
                    }
                }
            }
        }
    }
    cout << ans << endl;
}

int main() {
    // ARC025_B();
    ARC025_B_alter();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

