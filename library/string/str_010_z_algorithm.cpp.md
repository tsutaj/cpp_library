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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: string/str_010_z_algorithm.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/str_010_z_algorithm.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Required By
* :warning: <a href="verify/verify_str_010_z_algorithm.cpp.html">string/verify/verify_str_010_z_algorithm.cpp</a>


## Code
{% raw %}
```cpp
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

