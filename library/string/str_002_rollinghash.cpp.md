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


# :warning: string/str_002_rollinghash.cpp
* category: string


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
// Rolling Hash
// Verified: AOJ 2444 (Substring)

struct RollingHash {
public:
    using int_type = long long int;
    using hash_type = pair<int_type, int_type>;
    int_type base_1, base_2, mod_1, mod_2;
    vector<int_type> hash1, hash2, pow1, pow2;

    // init (constructor)
    RollingHash(string s, int_type bs_1 = 1013, int_type bs_2 = 1007) :
        base_1(bs_1), base_2(bs_2),
        mod_1(1000000007), mod_2(1000000009),
        hash1(s.length()+1,0), hash2(s.length()+1,0),
        pow1(s.length()+1,1), pow2(s.length()+1,1) {
            for(size_t i=0; i<s.length(); i++) {
                hash1[i+1] = (hash1[i] + s[i]) * base_1 % mod_1;
                hash2[i+1] = (hash2[i] + s[i]) * base_2 % mod_2;
                pow1[i+1] = pow1[i] * base_1 % mod_1;
                pow2[i+1] = pow2[i] * base_2 % mod_2;
            }
        }

    // calc str[l,r) hash (0-indexed)
    // if get(i1,j1) == get(i2,j2) -> identical string
    hash_type get(int l, int r) {
        int_type t1 = ((hash1[r] - hash1[l] * pow1[r-l]) % mod_1);
        if(t1 < 0) t1 += mod_1;
        int_type t2 = ((hash2[r] - hash2[l] * pow2[r-l]) % mod_2);
        if(t2 < 0) t2 += mod_2;
        return make_pair(t1, t2);
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

