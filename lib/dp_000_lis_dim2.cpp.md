[トップページに戻る](../index.html)

# dp\_000\_lis\_dim2.cpp
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
// ※upper_boundは指定された要素「よりも大きい」値の値が現れる最初の位置の検索```

[トップページに戻る](../index.html)
