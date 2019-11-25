<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: str\_002\_rollinghash.cpp

## Code

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

[トップページに戻る](../index.html)
