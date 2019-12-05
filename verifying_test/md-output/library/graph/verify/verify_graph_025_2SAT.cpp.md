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


# :warning: ../../graph/verify/verify_graph_025_2SAT.cpp
* category: ../../graph/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../graph/graph_000_basic.cpp](../graph_000_basic.cpp.html)
* :warning: [../../graph/graph_010_scc.cpp](../graph_010_scc.cpp.html)
* :warning: [../../graph/graph_025_2SAT.cpp](../graph_025_2SAT.cpp.html)


## Code
```cpp
#include <vector>
#include <iostream>
#include <cstdio>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
#include "../graph_000_basic.cpp"
#include "../graph_010_scc.cpp"
#include "../graph_025_2SAT.cpp"

void yuki_274() {
    int N, M; scanf("%d%d", &N, &M);
    vector<int> L(N), R(N);

    auto flip = [&](int l, int r) {
        return make_pair(M - 1 - r, M - 1 - l);
    };

    auto intersect = [&](int al, int ar, int bl, int br) {
        return !(ar < bl or br < al);
    };
    
    for(int i=0; i<N; i++) {
        scanf("%d%d", &L[i], &R[i]);
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                int al = L[i], ar = R[i];
                int bl = L[j], br = R[j];
                if(bit & 1) tie(al, ar) = flip(al, ar);
                if(bit & 2) tie(bl, br) = flip(bl, br);

                if(intersect(al, ar, bl, br)) {
                    switch(bit) {
                    case 0:
                        // A and B はダメ -> NA or NB
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        // NA and B はダメ -> A or NB
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        // A and NB はダメ -> NA or B
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        // NA and NB はダメ -> A or B
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }
    auto res = tsat.build();
    if(res.size() == N) puts("YES");
    else puts("NO");
}

void yuki_470() {
    int N; cin >> N;
    vector<string> U(N);
    for(int i=0; i<N; i++) cin >> U[i];

    if(N > 52) {
        cout << "Impossible" << endl;
        return;
    }

    TwoSAT tsat(N);
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            for(int bit=0; bit<4; bit++) {
                string sa, sb, ta, tb;
                if(bit & 1) sa = U[i].substr(0, 1), sb = U[i].substr(1); // NA, NB
                else sa = U[i].substr(0, 2), sb = U[i].substr(2); // A, B
                if(bit & 2) ta = U[j].substr(0, 1), tb = U[j].substr(1);
                else ta = U[j].substr(0, 2), tb = U[j].substr(2);

                if(sa == ta or sb == tb or sa == tb or sb == ta) {
                    switch(bit) {
                    case 0:
                        tsat.add_NAorNB(i, j);
                        break;
                    case 1:
                        tsat.add_AorNB(i, j);
                        break;
                    case 2:
                        tsat.add_NAorB(i, j);
                        break;
                    case 3:
                        tsat.add_AorB(i, j);
                        break;
                    }
                }
            }
        }
    }

    vector<int> res = tsat.build();
    if(res.empty()) cout << "Impossible" << endl;
    else {
        vector<string> pre(N), suf(N);
        for(int i=0; i<N; i++) {
            if(res[i]) pre[i] = U[i].substr(0, 2), suf[i] = U[i].substr(2);
            else pre[i] = U[i].substr(0, 1), suf[i] = U[i].substr(1);
            cout << pre[i] << " " << suf[i] << endl;
        }
    }
}

int main() {
    // yuki_274();
    yuki_470();
    return 0;
}

```

[Back to top page](../../../index.html)

