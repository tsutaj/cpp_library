<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: dp\_003\_histogram.cpp

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
}
```

[トップページに戻る](../index.html)
