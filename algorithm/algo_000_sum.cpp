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

