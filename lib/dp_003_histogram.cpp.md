[トップページに戻る](../index.html)

# dp\_003\_histogram.cpp
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
// 長さ N のヒストグラムの長方形領域最大
// Verified: AOJ DPL_3_C: Largest Rectangle in a Histogram

int histArea(vector<int> h) {
    // 番兵
    int N = h.size();
    h.push_back(0); N++;

    // height, position
    int ans = 0;
    stack<pii> S;
    rep(i,0,N+1) {
        if(S.empty()) S.push(pii(h[i], i));

        if     (S.top().first < h[i])
            S.push(pii(h[i], i));
        else if(S.top().first > h[i]) {
            int lastpos = 0;
            while(!S.empty() && S.top().first >= h[i]) {
                lastpos = S.top().second;
                chmax(ans, S.top().first * (i-lastpos));
                S.pop();
            }
            S.push(pii(h[i], lastpos));
        }
    }
    return ans;
}```

[トップページに戻る](../index.html)
