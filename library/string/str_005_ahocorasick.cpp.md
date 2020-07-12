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


# :warning: string/str_005_ahocorasick.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/str_005_ahocorasick.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Aho-Corasick 法
// 入力文字列に対してマッチするパターンを検索
// N := 入力文字列の長さ、M := パターンの文字列の長さの合計とするとき、
// 計算量は O(N + M)
// Verified: JOI 2010 春合宿 Day2: DNA の合成

struct Elem {
    int wordidx, lidx, ridx;
};

const int SIZE = 256;
struct PMA {
    PMA* node[SIZE + 1];
    vector<int> matched;
    PMA() { memset(node, 0, sizeof(node)); }

    vector<int> unite(const vector<int> &a, const vector<int> &b) {
        vector<int> res;
        set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        return res;
    }

    void build(vector<string> pattern) {
        PMA* root = this;
        root -> node[SIZE] = root;
        for(size_t i=0; i<pattern.size(); i++) {
            // 入力文字を絞るときはここも変えよう
            PMA* now = root;
            for(size_t j=0; j<pattern[i].length(); j++) {
                if(!now -> node[ (int)pattern[i][j] ]) {
                    now -> node[ (int)pattern[i][j] ] = new PMA;
                }
                now = now -> node[ (int)pattern[i][j] ];
            }
            now -> matched.push_back(i);
        }

        queue<PMA*> que;
        for(int i=0; i<SIZE; i++) {
            if(!root -> node[i]) root -> node[i] = root;
            else {
                root -> node[i] -> node[SIZE] = root;
                que.push(root -> node[i]);
            }
        }

        while(!que.empty()) {
            PMA* now = que.front(); que.pop();
            for(int i=0; i<SIZE; i++) {
                if(now -> node[i]) {
                    PMA *next = now -> node[SIZE];
                    while(!next -> node[i]) next = next -> node[SIZE];
                    now -> node[i] -> node[SIZE] = next -> node[i];
                    now -> node[i] -> matched = unite(now -> node[i] -> matched, next -> node[i] -> matched);
                    que.push(now -> node[i]);
                }
            }
        }
    }

    // 検索対象の文字列から、どのパターン文字列がどのインデックスで現れたか (半開)
    vector<Elem> match(const string s, vector<string> pattern) {
        vector<Elem> res;
        PMA* pma = this;
        for(size_t i=0; i<s.length(); i++) {
            // 入力文字を絞るときはここも変えよう
            int c = s[i];
            while(!pma -> node[c]) pma = pma -> node[SIZE];
            pma = pma -> node[c];
            for(size_t j=0; j<pma -> matched.size(); j++) {
                int r = i+1, l = r - pattern[ pma -> matched[j] ].length();
                res.push_back(Elem{pma -> matched[j], l, r});
            }
        }
        return res;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/str_005_ahocorasick.cpp"
// Aho-Corasick 法
// 入力文字列に対してマッチするパターンを検索
// N := 入力文字列の長さ、M := パターンの文字列の長さの合計とするとき、
// 計算量は O(N + M)
// Verified: JOI 2010 春合宿 Day2: DNA の合成

struct Elem {
    int wordidx, lidx, ridx;
};

const int SIZE = 256;
struct PMA {
    PMA* node[SIZE + 1];
    vector<int> matched;
    PMA() { memset(node, 0, sizeof(node)); }

    vector<int> unite(const vector<int> &a, const vector<int> &b) {
        vector<int> res;
        set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(res));
        return res;
    }

    void build(vector<string> pattern) {
        PMA* root = this;
        root -> node[SIZE] = root;
        for(size_t i=0; i<pattern.size(); i++) {
            // 入力文字を絞るときはここも変えよう
            PMA* now = root;
            for(size_t j=0; j<pattern[i].length(); j++) {
                if(!now -> node[ (int)pattern[i][j] ]) {
                    now -> node[ (int)pattern[i][j] ] = new PMA;
                }
                now = now -> node[ (int)pattern[i][j] ];
            }
            now -> matched.push_back(i);
        }

        queue<PMA*> que;
        for(int i=0; i<SIZE; i++) {
            if(!root -> node[i]) root -> node[i] = root;
            else {
                root -> node[i] -> node[SIZE] = root;
                que.push(root -> node[i]);
            }
        }

        while(!que.empty()) {
            PMA* now = que.front(); que.pop();
            for(int i=0; i<SIZE; i++) {
                if(now -> node[i]) {
                    PMA *next = now -> node[SIZE];
                    while(!next -> node[i]) next = next -> node[SIZE];
                    now -> node[i] -> node[SIZE] = next -> node[i];
                    now -> node[i] -> matched = unite(now -> node[i] -> matched, next -> node[i] -> matched);
                    que.push(now -> node[i]);
                }
            }
        }
    }

    // 検索対象の文字列から、どのパターン文字列がどのインデックスで現れたか (半開)
    vector<Elem> match(const string s, vector<string> pattern) {
        vector<Elem> res;
        PMA* pma = this;
        for(size_t i=0; i<s.length(); i++) {
            // 入力文字を絞るときはここも変えよう
            int c = s[i];
            while(!pma -> node[c]) pma = pma -> node[SIZE];
            pma = pma -> node[c];
            for(size_t j=0; j<pma -> matched.size(); j++) {
                int r = i+1, l = r - pattern[ pma -> matched[j] ].length();
                res.push_back(Elem{pma -> matched[j], l, r});
            }
        }
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
