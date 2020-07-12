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


# :warning: structure/strc_007_sparsetable.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_007_sparsetable.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// Sparse Table 構築 O(N log N), クエリ O(1)
// 配列で init することでテーブルを構築し、
// [l, r) のクエリに O(1) でこたえられる
// Verified: Codeforces #361 Div.2 D: Friends and Subsequences

constexpr int SIZE = 200010;
constexpr int LOGS = 20;

template <typename T>
struct SparseTable_max {
    T a[SIZE];
    int table[SIZE][LOGS], log_table[SIZE];
    int n;
    void init(vector<T> p) {
        n = (int)p.size();
        for(int i=0; i<n; i++) {
            a[i] = p[i];
            table[i][0] = i;
        }
        for(int i=2; i<=n; i++) {
            log_table[i] = log_table[i>>1] + 1;
        }

        for(int k=1; (1<<k)<=n; k++) {
            for(int i=0; i+(1<<(k-1))<=n; i++) {
                int x = table[i           ][k-1];
                int y = table[i+(1<<(k-1))][k-1];
                if(a[x] <= a[y]) table[i][k] = y;
                else table[i][k] = x;
            }
        }
    }

    // 半開区間 [l, r) における最大値のインデックスを返す
    int query(int l, int r) {
        int d = log_table[r - l];
        int x = table[l       ][d];
        int y = table[r-(1<<d)][d];
        if(a[x] <= a[y]) return y;
        else return x;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/strc_007_sparsetable.cpp"
// Sparse Table 構築 O(N log N), クエリ O(1)
// 配列で init することでテーブルを構築し、
// [l, r) のクエリに O(1) でこたえられる
// Verified: Codeforces #361 Div.2 D: Friends and Subsequences

constexpr int SIZE = 200010;
constexpr int LOGS = 20;

template <typename T>
struct SparseTable_max {
    T a[SIZE];
    int table[SIZE][LOGS], log_table[SIZE];
    int n;
    void init(vector<T> p) {
        n = (int)p.size();
        for(int i=0; i<n; i++) {
            a[i] = p[i];
            table[i][0] = i;
        }
        for(int i=2; i<=n; i++) {
            log_table[i] = log_table[i>>1] + 1;
        }

        for(int k=1; (1<<k)<=n; k++) {
            for(int i=0; i+(1<<(k-1))<=n; i++) {
                int x = table[i           ][k-1];
                int y = table[i+(1<<(k-1))][k-1];
                if(a[x] <= a[y]) table[i][k] = y;
                else table[i][k] = x;
            }
        }
    }

    // 半開区間 [l, r) における最大値のインデックスを返す
    int query(int l, int r) {
        int d = log_table[r - l];
        int x = table[l       ][d];
        int y = table[r-(1<<d)][d];
        if(a[x] <= a[y]) return y;
        else return x;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
