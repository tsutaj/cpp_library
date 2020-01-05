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


# :warning: structure/old/strc_007_bit_recursion.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ea7b7b53f881f37feb2f447585bbcf5b">structure/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/old/strc_007_bit_recursion.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/old/strc_007_bit_recursion.cpp"
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
{% endraw %}

<a href="../../../index.html">Back to top page</a>

