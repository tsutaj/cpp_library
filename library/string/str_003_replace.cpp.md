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


# :warning: string/str_003_replace.cpp
<a href="../../index.html">Back to top page</a>

* category: string
* <a href="{{ site.github.repository_url }}/blob/master/string/str_003_replace.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52 +0900




## Code
{% raw %}
```cpp
// s に含まれている t を全て u に変える
// (find しまくるよりは高速のはず)
string replace_user(string s, string t, string u) {
    reverse(t.begin(), t.end());
    size_t N = s.length(), M = t.length();
    if(N < M) return s;

    string ret = "", temp = "";
    for(size_t i=0; i<N; i++) {
        if(temp.length() == M) {
            ret += temp.back();
            temp.pop_back();
        }
        temp = s[i] + temp;
        if(temp == t) {
            ret += u;
            temp = "";
        }
    }
    reverse(temp.begin(), temp.end());
    s = ret + temp;
    return s;
}
```
{% endraw %}

<a href="../../index.html">Back to top page</a>

