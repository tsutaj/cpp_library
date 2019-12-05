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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../algorithm/algo_000_sum.cpp
* category: ../../algorithm


[Back to top page](../../index.html)



## Code
```cpp
// 2次元配列の部分和最大 (AOJ 0098)
int n;
int a[110][110];

int solve(){
    rep(i,1,n+1) rep(j,1,n+1) {
        cin >> a[i][j];
        a[i][j] += (a[i-1][j] + a[i][j-1] - a[i-1][j-1]);
    }

    int ans = -INF;
    rep(i,0,n) rep(j,0,n) rep(k,i+1,n+1) rep(l,j+1,n+1) {
        ans = max(ans, a[k][l] - a[k][j] - a[i][l] + a[i][j]);
    }
    return ans;
}

int main() {
    cin >> n;
    cout << solve() << endl;
}


```

[Back to top page](../../index.html)
