[トップページに戻る](../index.html)

# strc\_007\_bit\_recursion.cpp
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
}```

[トップページに戻る](../index.html)
