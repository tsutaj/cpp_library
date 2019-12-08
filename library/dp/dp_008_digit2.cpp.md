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


# :warning: dp/dp_008_digit2.cpp
* category: dp


[Back to top page](../../index.html)



## Code
```cpp
// TTPC2015 F: レシート
// 太郎君は A 円の買い物をした。 太郎君は X \geq A を満たす任意の X 円を支払うことができる。
// 買い物の金額 A 、支払額 X 、お釣り (X − A) の 3 つの整数について 10 進数表記にしたとき、
// 3 つの数字が揃う桁の数を最大にしたい。

// dp[i][j] := 下から i 桁目までみて、繰り上がりが (起こらない / 起こる)
//             ときの桁揃い最大値
ll dp[110][2];

int main() {
    string s; cin >> s;
    int N = s.length();
    // 下の桁から見たいため、文字列を反転させる
    reverse(s.begin(), s.end());

    rep(i,0,110) rep(j,0,2) dp[i][j] = -INF;

    dp[0][0] = 0;
    // i 桁目を k にする、繰り下がりが起こっているかどうかが j
    rep(i,0,N) rep(j,0,2) rep(k,0,10) {
        if(dp[i][j] == -INF) continue;
        int v = s[i] - '0';
        int digit = (k - v - j + 20) % 10;
        int borrow = (k - v - j < 0) ? 1 : 0;
        // 元の数の i 桁目、計算結果、入れた数 が全て等しければ足す
        chmax(dp[i+1][borrow], dp[i][j] + ((v == digit && digit == k) ? 1 : 0));
    }
    cout << max(dp[N][0], dp[N][1]) << endl;
}
```

[Back to top page](../../index.html)

