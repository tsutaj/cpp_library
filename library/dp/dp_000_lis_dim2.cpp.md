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


# :warning: dp/dp_000_lis_dim2.cpp
<a href="../../index.html">Back to top page</a>

* category: dp
* <a href="{{ site.github.repository_url }}/blob/master/dp/dp_000_lis_dim2.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Code
{% raw %}
```cpp
// 2次元LIS (最長増加部分列)
// Verified: ABC038 D問題
// http://abc038.contest.atcoder.jp/tasks/abc038_d

int n;
pair<int, int> ab[100000];
int dp[100010];

int main(){
  cin >> n;
  rep(i,0,n) cin >> ab[i].fr >> ab[i].sc;

  // h を昇順、w を降順にソート
  rep(i,0,n) ab[i].sc *= -1;
  sort(ab, ab + n);
  rep(i,0,n) ab[i].sc *= -1;

  // w の要素について普通に LIS をやる
  // w が等しいものを単調増加列に入れないようにするために、降順ソートをしている
  rep(i,0,100010) dp[i] = 10000000;
  rep(i,0,n){
    *lower_bound(dp, dp + n, ab[i].sc) = ab[i].sc;
  }
  cout << lower_bound(dp, dp + n, 10000000) - dp << endl;
}

// ※lower_boundは指定された要素「以上」の値が現れる最初の位置の検索
// ※upper_boundは指定された要素「よりも大きい」値の値が現れる最初の位置の検索
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

