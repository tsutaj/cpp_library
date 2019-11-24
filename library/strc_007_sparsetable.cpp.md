<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# strc\_007\_sparsetable.cpp
---

## Code

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

[トップページに戻る](../index.html)
