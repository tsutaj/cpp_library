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

# :warning: dp\_008\_digit.cpp

## Code

```cpp
// 1 以上 10^n 以下の整数のうち、 3 の倍数および 3 のつく個数を求める
// -> 桁 DP で "桁数", "mod 3", "3 を持つか", "元の数未満であることが確定しているか"
// を管理していけばよい。

// digit, mod, has3, flag
ll dp[25][3][2][2];

int main() {
    // 10^n を表す文字列を作成する
    int n; cin >> n;
    string s(n, '0');
    s = '1' + s;

    int m = s.length();
    dp[0][0][0][0] = 1;
    rep(i,0,m) rep(j,0,3) rep(k,0,2) rep(l,0,2) {
        // i+1 桁目で使う数字の候補は、0 から lim まで
        // flag == true ならば数字は何でも使えるが、
        // そうでなければ (元の数未満が確定してなければ)
        // 元の数の i+1 桁目の数字以下のみが使える。
        int lim = (l == 1 ? 9 : s[i] - '0');

        rep(x,0,lim + 1) {
            // 3 の倍数の判定は、各桁の数字の和で行える
            // よって mod 3 の部分は単純に今使う数字を足して余りを取る
            int mo = (j + x) % 3;
            // mo = (j*10 + x) % 3; <- これでもできる。この方法だと 3 に限らず倍数判定ができる

            // has3 -> 元々 true または 今 3 を使った
            // flag -> 元々 true または元の数の i+1 桁目の数字未満を使った
            dp[i+1][mo][k || (x == 3)][l || x < lim] += dp[i][j][k][l];
        }
    }

    ll ans = 0;
    rep(j,0,3) rep(k,0,2) rep(l,0,2) {
        // mod3 == 0 または has3 == 1 が条件に合致する
        if(j == 0 || k == 1) ans += dp[m][j][k][l];
    }

    // この DP では 0 も valid として扱っているので、
    // 「1 以上 10^n 以下」における答えを知るために ans - 1 する
    cout << ans - 1 << endl;
    return 0;
}
```

[トップページに戻る](../index.html)
