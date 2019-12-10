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


# :warning: string/str_008_shift_and_or.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/str_008_shift_and_or.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Code
{% raw %}
```cpp
// Shift And アルゴリズムによる文字列検索 (Verified: AOJ ALDS1_14_B)
// パターン・テキストともに英小文字・英大文字・数字のみ出現することを想定 (適宜 getCharId を変更して)
// たくさんビットが必要なので bitset が必要

// 最大文字列長 + 1
const int PATTERN_SIZE = 10001;

// 文字の種類数 (適宜変更が必要)
const int ALPH = 26 + 26 + 10;

struct BitParallel {
    string s;
    vector< bitset<PATTERN_SIZE> > mask;

    // 文字の id を取得
    int getCharId(char c) {
        if('a' <= c and c <= 'z') return c - 'a';
        if('A' <= c and c <= 'Z') return 26 + (c - 'A');
        return 26 + 26 + (c - '0');
    }
    
    // パターン文字列を受け取り、mask を作成
    BitParallel(string s_) : s(s_) {
        mask.resize(ALPH);
        for(size_t i=0; i<s.length(); i++) {
            int c = getCharId(s[i]);
            mask[c][i+1] = 1;
        }
    }

    // テキスト文字列を入力として与える
    // 出現位置 (の左端) を 0-indexed で返す
    vector<int> search(string t) {
        bitset<PATTERN_SIZE> bit;

        vector<int> appeared;
        int L = s.length();
        for(size_t i=0; i<t.length(); i++) {
            int c = getCharId(t[i]);
            bit[0] = 1;
            bit = (bit << 1) & mask[c];

            // パターンと一致
            if(bit[L] == 1) {
                appeared.push_back(i-L+1);
            }
        }
        return appeared;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

