---
layout: default
---

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


# :warning: KMP 法 (Knuth-Morris-Pratt Algorithm) <small>(string/str_007_kmp.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/str_007_kmp.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-11 16:10:37+09:00


* 文字列 $p[0:i-1]$ の接頭辞と接尾辞は最大何文字一致する？ (ただし、$|p[0:i-1]|$ 文字未満のみ考慮)
* MP 法に比べ、失敗時の遷移が log 回に改善されている
* 文字列 $s$ における $p$ の出現位置 (開始位置) のリスト
* see: <a href="http://www-igm.univ-mlv.fr/~lecroq/string/node8.html">http://www-igm.univ-mlv.fr/~lecroq/string/node8.html</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// @brief KMP 法 (Knuth-Morris-Pratt Algorithm)
template <typename Tp>
struct KMP {
    Tp p; int len;
    vector<int> fail;
    KMP() {}
    KMP(Tp p_) : p(p_), len(p_.size()) {
        // @brief 文字列 $p[0:i-1]$ の接頭辞と接尾辞は最大何文字一致する？ (ただし、$|p[0:i-1]|$ 文字未満のみ考慮)
        // @brief MP 法に比べ、失敗時の遷移が log 回に改善されている
        // @see http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
        fail.resize(len + 1, -1);
        for(int i=0, j=-1; i<len; i++) {
            // その時点で一致しなければ fail[j] 文字以下の一致となる
            // j を fail[j] に変更
            while(j >= 0 and p[j] != p[i]) j = fail[j];
            j++;
            fail[i+1] = (i+1 < len and p[i+1] == p[j] ? fail[j] : j);
        }
    }

    // @brief 文字列 $s$ における $p$ の出現位置 (開始位置) のリスト
    vector<int> match(Tp s) {
        int N = s.size();
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
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/str_007_kmp.cpp"
// @brief KMP 法 (Knuth-Morris-Pratt Algorithm)
template <typename Tp>
struct KMP {
    Tp p; int len;
    vector<int> fail;
    KMP() {}
    KMP(Tp p_) : p(p_), len(p_.size()) {
        // @brief 文字列 $p[0:i-1]$ の接頭辞と接尾辞は最大何文字一致する？ (ただし、$|p[0:i-1]|$ 文字未満のみ考慮)
        // @brief MP 法に比べ、失敗時の遷移が log 回に改善されている
        // @see http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
        fail.resize(len + 1, -1);
        for(int i=0, j=-1; i<len; i++) {
            // その時点で一致しなければ fail[j] 文字以下の一致となる
            // j を fail[j] に変更
            while(j >= 0 and p[j] != p[i]) j = fail[j];
            j++;
            fail[i+1] = (i+1 < len and p[i+1] == p[j] ? fail[j] : j);
        }
    }

    // @brief 文字列 $s$ における $p$ の出現位置 (開始位置) のリスト
    vector<int> match(Tp s) {
        int N = s.size();
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
{% endraw %}

<a href="../../index.html">Back to top page</a>

