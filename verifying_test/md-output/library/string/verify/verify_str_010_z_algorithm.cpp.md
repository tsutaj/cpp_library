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


# :warning: ../../string/verify/verify_str_010_z_algorithm.cpp
* category: ../../string/verify


[Back to top page](../../../index.html)



## Dependencies
* :warning: [../../string/str_010_z_algorithm.cpp](../str_010_z_algorithm.cpp.html)


## Code
```cpp
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#include "../str_010_z_algorithm.cpp"

void tiny_test() {
    string s; cin >> s;
    Z_algorithm<string> za(s);
    for(size_t i=0; i<s.length(); i++) {
        fprintf(stderr, "Z[%zu] = %d\n", i, za.get_lcp(i));
    }
}

void yuki_599() {
    const int MOD = 1000000007;
    string s; cin >> s; int N = s.size();
    vector<int> dp(N + 1);

    dp[0] = 1;
    for(int i=0; i<N; i++) {
        int l = i, r = N - i, len = N - 2*i;
        if(len <= 0) continue;
        Z_algorithm<string> za(s.substr(l, len));
        for(int j=1; j<=len; j++) {
            // [ll, lr)
            int ll = 0, lr = j;
            // [rl, rr)
            int rl = len - j, rr = len;

            if(lr > rl) break;
            if(za.get_lcp(rl) >= j) {
                (dp[i+j] += dp[i]) %= MOD;
            }
        }
    }

    int ans = 0;
    for(int i=0; i<=N; i++) (ans += dp[i]) %= MOD;
    cout << ans << endl;
}

int main() {
    // tiny_test();
    yuki_599();
}

```

[Back to top page](../../../index.html)

