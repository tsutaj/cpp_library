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