<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: str\_001\_technique.cpp
---

## Code

```cpp
// 大事なテクニック集！

// int や double から string に変換する
// → C++11 標準ライブラリには std::to_string 関数が存在する。
to_string(42); // result: "42"

// string から int に変換する
// → atoi 関数は char 型の文字列を int に変換する
// → string を char 型の文字列に変換してから int にしよう
// → atoi(s.c_str()) のように書けば良い
atoi("42".c_str()); // result: 42
// ファミリーとして、atof, atol があるぞ！

// string から int に変換する その2
// → 実は stoi 関数を使えば string 型からそのまま変換できる
// → しかも基数指定可能！
int stoi(const string& str, size_t* idx = nullptr, int base = 10);
stoi("10", nullptr, 16); // result: 16
stoi("10", nullptr, 2); // result: 2
// ファミリーとして、stol, stoll, stoul, stoull, stof, stod, stold があるぞ！

// char型文字列 から string に変換する → 実はそのままいける
char str[10];
string s = str; // これで OK

// 文字をインデックスに
// → 起点としたい文字で引けば良い
// → 例えば、'A' を起点としてインデックスを付けたい場合は s[i] - 'A' とする
int idx1 = 'C' - 'A'; // result: 2
int idx2 = 'b' - 'a'; // result: 1
int idx3 = '9' - '0'; // result: 9

// generate binary string (not less than k-digit)
string to_binString(int n, int k) {
    string ret = "";
    while(n) ret += ('0' + (n&1)), n >>= 1;
    while(ret.length() < k) ret += '0';
    reverse(ret.begin(), ret.end());
    return ret;
}
```

[トップページに戻る](../index.html)
