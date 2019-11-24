<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_003\_digit.cpp
---

## Code

```cpp
// 整数の桁数を調べる (10進数)
template <typename T_digit>
int digit(T_digit n) {
    int ans = 0;
    while(n != 0) {n /= 10; ans++;}
    return ans;
}

// 整数の桁数を調べる (k進数)
template <typename T_digit>
template <typename U_digit>
int digit(T_digit n, U_digit k) {
    int ans = 0;
    while(n != 0) {n /= k; ans++;}
    return ans;
}

// インデックス (10進数)
template <typename T_numIndex>
int numIndex(T_numIndex n, int k) {
    rep(i,0,k) n /= 10;
    return n % 10;
}
```

[トップページに戻る](../index.html)
