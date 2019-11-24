[トップページに戻る](../index.html)

# algo\_000\_sum.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

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

[トップページに戻る](../index.html)
