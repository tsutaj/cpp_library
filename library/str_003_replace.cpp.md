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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: str\_003\_replace.cpp

## Code

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

[トップページに戻る](../index.html)
