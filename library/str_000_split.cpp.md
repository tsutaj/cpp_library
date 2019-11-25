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

# :warning: str\_000\_split.cpp

## Code

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

[トップページに戻る](../index.html)
