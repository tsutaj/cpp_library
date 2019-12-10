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


# :warning: string/str_000_split.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/str_000_split.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// split関数 (1文字バージョン。指定された文字で文字列を分割)
vector<string> split(string s, char c) {
    vector<string> ret;
    string temp;
    replace(s.begin(), s.end(), c, ' ');
    stringstream ss(s);
    while(ss >> temp) ret.pb(temp);
    return ret;
}

// split関数 (1文字・ delimiter を引数に指定しないバージョン)
// ※ delimiter が複数あればその都度 replace 関数を増やす(でも遅くなるかも)
vector<string> split(string s) {
    vector<string> ret;
    string temp;
    replace(s.begin(), s.end(), ',', ' ');
    replace(s.begin(), s.end(), '/', ' ');
    stringstream ss(s);
    while(ss >> temp) ret.pb(temp);
    return ret;
}

// split関数 (2文字以上バージョン。指定された文字列で文字列を分割)
vector<string> split(string s, string c) {
    vector<string> ret;
    string temp;
    for(int pos = s.find(c); pos != string::npos; pos = s.find(c, pos)) {
        s.replace(pos, c.size(), " ");
    }
    stringstream ss(s);
    while(ss >> temp) ret.pb(temp);
    return ret;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

