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


# :warning: string/verify/verify_str_010_z_algorithm.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c28df84862218769fd49d15963eb43">string/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/verify/verify_str_010_z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Depends on

* :warning: <a href="../str_010_z_algorithm.cpp.html">string/str_010_z_algorithm.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/verify/verify_str_010_z_algorithm.cpp"
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
#line 1 "string/verify/../str_010_z_algorithm.cpp"
// Z-algorithm
// 各 Suffix と元の文字列との LCP を求める
template <typename ArrayType>
struct Z_algorithm {
    ArrayType v;
    vector<int> Z;

    void build() {
        int N = v.size(), i, j;
        Z = vector<int>(N);

        for(i=1,j=0; i<N; i++) {
            int l = i - j;
            if(i + Z[l] < j + Z[j]) {
                Z[i] = Z[l];
            }
            else {
                int k = max(0, j + Z[j] - i);
                while(i + k < N and v[k] == v[i+k]) k++;
                Z[i] = k;
                j = i;
            }
        }
        Z[0] = N;
    }

    Z_algorithm(ArrayType v_) : v(v_) {
        build();
    }

    // idx から切り出した Suffix と文字列全体との LCP
    int get_lcp(int idx) {
        return Z[idx];
    }
};
#line 7 "string/verify/verify_str_010_z_algorithm.cpp"

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
{% endraw %}

<a href="../../../index.html">Back to top page</a>

