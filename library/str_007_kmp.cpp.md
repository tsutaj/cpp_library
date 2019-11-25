<!-- mathjax config similar to math.stackexchange -->
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({ tex2jax: { inlineMath: [ ['$','$'] ] } });
</script>
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS_HTML">
</script>
<meta http-equiv="X-UA-Compatible" CONTENT="IE=EmulateIE7" />

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: str\_007\_kmp.cpp

## Code

```cpp
// KMP 法 (Knuth-Morris-Pratt Algorithm)
struct KMP {
    string p; int len;
    vector<int> fail;
    KMP() {}
    KMP(string p_) : p(p_), len(p_.length()) {
        // 文字列 p[0:i-1] の接頭辞と接尾辞は最大何文字一致する？
        // ただし、|p[0:i-1]| 文字未満のみ考慮
        // MP 法に比べ、失敗時の遷移が log 回に改善されている
        // see also: http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
        fail.resize(len + 1, -1);
        for(int i=1, j=-1; i<=len; i++) {
            // その時点で一致しなければ fail[j] 文字以下の一致となる
            // j を fail[j] に変更
            int step = 0;
            while(j >= 0 and p[j] != p[i-1]) j = fail[j], step++;
            fail[i] = (p[i] == p[++j] ? fail[j] : j);
        }
    }

    // 文字列 s における p の出現位置 (開始位置) のリスト
    vector<int> match(string s) {
        int N = s.length();
        vector<int> occur;
        for(int i=0, k=0; i<N; i++) {
            while(k >= 0 and s[i] != p[k]) k = fail[k];
            if(++k == len) {
                occur.push_back(i-len+1);
                k = fail[k];
            }
        }
        return occur;
    }
};

```

[トップページに戻る](../index.html)
