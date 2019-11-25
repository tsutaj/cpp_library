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

# :warning: str\_010\_z\_algorithm.cpp

## Code

```cpp
// Z-algorithm
// 各 Suffix と元の文字列との LCP を求める
template <typename ArrayType>
struct Z_algorithm {
    ArrayType v;
    vector<int> Z;

    void build() {
        int N = v.size(), i, j;
        Z = vector<int>(N);

        for(i=1,j=0; i<N; i++) {
            int l = i - j;
            if(i + Z[l] < j + Z[j]) {
                Z[i] = Z[l];
            }
            else {
                int k = max(0, j + Z[j] - i);
                while(i + k < N and v[k] == v[i+k]) k++;
                Z[i] = k;
                j = i;
            }
        }
        Z[0] = N;
    }

    Z_algorithm(ArrayType v_) : v(v_) {
        build();
    }

    // idx から切り出した Suffix と文字列全体との LCP
    int get_lcp(int idx) {
        return Z[idx];
    }
};

```

[トップページに戻る](../index.html)
