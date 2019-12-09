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


# :warning: string/str_009_manacher.cpp
* category: string


[Back to top page](../../index.html)



## Required
* :warning: [string/verify/verify_str_009_manacher.cpp](verify/verify_str_009_manacher.cpp.html)


## Code
{% raw %}
```cpp
// Manacher のアルゴリズム
// 各インデックスについて回文半径を線形時間で求める
// ダミー文字を挟むことにより偶数長回文にも対応
template <typename ArrayType, typename ElemType>
struct Manacher {
    ArrayType v;
    ElemType dummy;
    vector<int> rad;

    ArrayType insert_dummy_elem(ArrayType vec, ElemType dummy) {
        int N = vec.size();
        ArrayType res(2*N - 1, dummy);
        for(int i=0; i<N; i++) res[2*i] = vec[i];
        return res;
    }

    void build() {
        int N = v.size(), i, j;
        rad = vector<int>(N);
        for(i=j=0; i<N; ) {
            while(i-j >= 0 and i+j < N and v[i-j] == v[i+j]) j++;
            rad[i] = j;

            int k;
            for(k=1; i-k >= 0 and rad[i]-k > rad[i-k]; k++) rad[i+k] = rad[i-k];

            i += k;
            j = max(0, j-k);
        }
    }

    Manacher(ArrayType v_, ElemType dummy_) :
        v(v_), dummy(dummy_) {
        v = insert_dummy_elem(v, dummy);
        build();
    }

    // idx を中心とする回文半径 (0-indexed)
    int get_rad(int idx) {
        return (rad[2*idx] + 1) / 2;
    }

    // 部分文字列 [l, r) が回文かどうか (0-indexed) 
    bool is_palindrome(int l, int r) {
        if(l == r) return true;
        int idx = l + r - 1, len = r - l;
        return rad[idx] >= len;
    }
};

```
{% endraw %}

[Back to top page](../../index.html)

