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


# :warning: etc/etc_000_date.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#e80f17310109447772dca82b45ef35a5">etc</a>
* <a href="{{ site.github.repository_url }}/blob/master/etc/etc_000_date.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// よく使う配列
string dayname[] = {"日曜日", "月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日"};
string dayname[] = {"日", "月", "火", "水", "木", "金", "土"};
string dayname[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string dayname[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int daynum[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 年月日の情報から曜日を求める (ツェラーの公式、 Zeller's congruence)
int dayOfTheWeek( int y, int m, int d ) {
    if( m < 3 ) {
        y--; m += 12;
    }
    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d ) % 7;
}

// 備考 ... 数字と曜日の関係一覧
// 0 ... 日曜日
// 1 ... 月曜日
// 2 ... 火曜日
// 3 ... 水曜日
// 4 ... 木曜日
// 5 ... 金曜日
// 6 ... 土曜日

// うるう年であるかどうかを判定する (Verified: ARC002 A問題)
bool isLeapYear( int y ) {
    if     (y % 400 == 0) return true;
    else if(y % 100 == 0) return false;
    else if(y % 4   == 0) return true;
    else                  return false;
}

// 1日ずつ全探索する (Verified: ARC002 B問題)
// 注意: 配列 daynum と 関数 isLeapYear が必要です
void BForceDate(int y, int m, int d) {
    if(処理を実行) return;
    
    if(d >= daynum[m-1]) {
        if(m == 12) BForceDate(y+1, 1, 1);
        else if(m == 2) {
            if(isLeapYear(y) && d == 28) BForceDate(y, m, d+1);
            else BForceDate(y, m+1, 1);
        }
        else BForceDate(y, m+1, 1);
    }
    else BForceDate(y, m, d+1);
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "etc/etc_000_date.cpp"
// よく使う配列
string dayname[] = {"日曜日", "月曜日", "火曜日", "水曜日", "木曜日", "金曜日", "土曜日"};
string dayname[] = {"日", "月", "火", "水", "木", "金", "土"};
string dayname[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string dayname[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

int daynum[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 年月日の情報から曜日を求める (ツェラーの公式、 Zeller's congruence)
int dayOfTheWeek( int y, int m, int d ) {
    if( m < 3 ) {
        y--; m += 12;
    }
    return ( y + y/4 - y/100 + y/400 + ( 13*m + 8 )/5 + d ) % 7;
}

// 備考 ... 数字と曜日の関係一覧
// 0 ... 日曜日
// 1 ... 月曜日
// 2 ... 火曜日
// 3 ... 水曜日
// 4 ... 木曜日
// 5 ... 金曜日
// 6 ... 土曜日

// うるう年であるかどうかを判定する (Verified: ARC002 A問題)
bool isLeapYear( int y ) {
    if     (y % 400 == 0) return true;
    else if(y % 100 == 0) return false;
    else if(y % 4   == 0) return true;
    else                  return false;
}

// 1日ずつ全探索する (Verified: ARC002 B問題)
// 注意: 配列 daynum と 関数 isLeapYear が必要です
void BForceDate(int y, int m, int d) {
    if(処理を実行) return;
    
    if(d >= daynum[m-1]) {
        if(m == 12) BForceDate(y+1, 1, 1);
        else if(m == 2) {
            if(isLeapYear(y) && d == 28) BForceDate(y, m, d+1);
            else BForceDate(y, m+1, 1);
        }
        else BForceDate(y, m+1, 1);
    }
    else BForceDate(y, m, d+1);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

