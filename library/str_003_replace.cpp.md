<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


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
