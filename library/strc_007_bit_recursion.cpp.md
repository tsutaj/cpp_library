<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
MathJax.Hub.Config({
  jax: ["input/TeX", "output/HTML-CSS"],
  tex2jax: {
    inlineMath: [ ['$', '$'] ],
    displayMath: [ ['$$', '$$']],
    processEscapes: true,
    skipTags: ['script', 'noscript', 'style', 'textarea', 'pre', 'code']
  },
  messageStyle: "none",
  "HTML-CSS": { preferredFont: "TeX", availableFonts: ["STIX","TeX"] }
});
</script>
<script src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML" type="text/javascript"></script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_007\_bit\_recursion.cpp

## Code

```cpp
// BIT 略
// Verified: ALDS1_5_D (反転数)
signed main() {
    int n; cin >> n;
    BIT<int> b(n);
    vector<int> a(n);
    map<int, int> m;
    rep(i,0,n) {
        cin >> a[i];
        m[a[i]];
    }

    int newnum = 1;
    for(auto &x : m) x.second = newnum++;
    rep(i,0,n) a[i] = m[a[i]];

    int ans = 0;
    rep(j,0,n) {
        ans += j - b.sum(a[j]);
        b.add(a[j], 1);
    }
    cout << ans << endl;
    return 0;
}
```

[トップページに戻る](../index.html)
