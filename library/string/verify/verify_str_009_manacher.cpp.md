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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: string/verify/verify_str_009_manacher.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#26c28df84862218769fd49d15963eb43">string/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/verify/verify_str_009_manacher.cpp">View this file on GitHub</a>
    - Last commit date: 2019-12-09 17:27:28+09:00




## Depends on

* :warning: <a href="../str_009_manacher.cpp.html">string/str_009_manacher.cpp</a>
* :warning: <a href="../../structure/strc_008_abst_segtree.cpp.html">セグメント木 (Segment Tree)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#include "../str_009_manacher.cpp"
#include "../../structure/strc_008_abst_segtree.cpp"

void tiny_test_str() {
    string s; cin >> s;
    char dummy = '$';

    Manacher<string, char> man(s, dummy);
    man.dump();
}

void tiny_test_int() {
    int N; cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    int dummy = 0;

    Manacher< vector<int>, int > man(v, dummy);
    man.dump(false);
}

void yuki_464() {
    string s; cin >> s;
    int N = s.size();
    Manacher<string, char> man(s, '$');

    long long int dp[5010][5] = {};
    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            for(int k=0; k<4; k++) {
                if(k != 2) {
                    if(!man.is_palindrome(i, j)) continue;
                    dp[j][k+1] += dp[i][k];
                }
                else {
                    dp[j][k+1] += dp[i][k];
                }
            }
        }
    }
    cout << dp[N][4] << endl;
}

void WUPC2019_E() {
    int N, M; cin >> N >> M;
    vector<int> row(N), col(M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c; cin >> c;
            if(c == '1') row[i]++, col[j]++;
        }
    }

    int dummy = -1, ans = 0;
    Manacher< vector<int>, int > mr(row, dummy), mc(col, dummy);
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            bool ok = true;
            ok &= mr.is_palindrome(0, i+1);
            ok &= mr.is_palindrome(i+1, N);
            ok &= mc.is_palindrome(0, j+1);
            ok &= mc.is_palindrome(j+1, M);
            if(ok) ans++;
        }
    }
    cout << ans << endl;
}

void ukuku09_D() {
    struct SegFunc {
        static int update(int a, int b) { return max(a, b); }
        static int combine(int a, int b) { return max(a, b); }
    };
    
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    Manacher< string, char > man(s, '$');
    SegmentTree< int, SegFunc > seg(N, -1);

    for(int i=0; i<N; i++) {
        int rad = man.get_rad(i);
        seg.update(i, rad);
    }
    
    while(Q--) {
        int ql, qr; cin >> ql >> qr; ql--;

        int ub = (N + 1) / 2 + 1, lb = -1;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            int l = ql + mid - 1;
            int r = qr - mid + 1;

            bool ok = true;
            if(l >= r) ok = false;
            else {
                int val = seg.query(l, r);
                ok = (val >= mid);
            }

            if(ok) lb = mid;
            else ub = mid;
        }
        int ans = lb * 2 - 1;
        cout << ans << endl;
    }
}

int main() {
    // tiny_test_str();
    // tiny_test_int();
    // yuki_464();
    // WUPC2019_E();
    ukuku09_D();
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/verify/verify_str_009_manacher.cpp"
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#line 1 "string/verify/../str_009_manacher.cpp"
// Manacher のアルゴリズム
// 各インデックスについて回文半径を線形時間で求める
// ダミー文字を挟むことにより偶数長回文にも対応
template <typename ArrayType, typename ElemType>
struct Manacher {
    ArrayType v;
    ElemType dummy;
    vector<int> rad;

    ArrayType insert_dummy_elem(ArrayType vec, ElemType dummy) {
        int N = vec.size();
        ArrayType res(2*N - 1, dummy);
        for(int i=0; i<N; i++) res[2*i] = vec[i];
        return res;
    }

    void build() {
        int N = v.size(), i, j;
        rad = vector<int>(N);
        for(i=j=0; i<N; ) {
            while(i-j >= 0 and i+j < N and v[i-j] == v[i+j]) j++;
            rad[i] = j;

            int k;
            for(k=1; i-k >= 0 and rad[i]-k > rad[i-k]; k++) rad[i+k] = rad[i-k];

            i += k;
            j = max(0, j-k);
        }
    }

    Manacher(ArrayType v_, ElemType dummy_) :
        v(v_), dummy(dummy_) {
        v = insert_dummy_elem(v, dummy);
        build();
    }

    // idx を中心とする回文半径 (0-indexed)
    int get_rad(int idx) {
        return (rad[2*idx] + 1) / 2;
    }

    // 部分文字列 [l, r) が回文かどうか (0-indexed) 
    bool is_palindrome(int l, int r) {
        if(l == r) return true;
        int idx = l + r - 1, len = r - l;
        return rad[idx] >= len;
    }
};
#line 1 "string/verify/../../structure/strc_008_abst_segtree.cpp"
// @category セグメント木 (Segment Tree)
// @title セグメント木 (Segment Tree)
// 抽象 SegmentTree (0-indexed・一点更新・区間取得)
template <typename MonoidType>
struct SegmentTree {
    using Function = function< MonoidType(MonoidType, MonoidType) >;

    // node, identity element
    int n;
    vector<MonoidType> node;
    MonoidType E0;

    // update / combine function
    Function upd_f, cmb_f;

    void build(int m, vector<MonoidType> v = vector<MonoidType>()) {
        if(v != vector<MonoidType>()) m = v.size();
        n = 1; while(n < m) n *= 2;

        node = vector<MonoidType>(2*n-1, E0);
        if(v != vector<MonoidType>()) {
            for(int i=0; i<m; i++) {
                node[n-1+i] = v[i];
            }
            for(int i=n-2; i>=0; i--) {
                node[i] = cmb_f(node[2*i+1], node[2*i+2]);
            }
        }
    }

    // initialize
    SegmentTree() {}
    SegmentTree(int n_, MonoidType E0_,
                Function upd_f_, Function cmb_f_,
                vector<MonoidType> v = vector<MonoidType>()) :
        E0(E0_), upd_f(upd_f_), cmb_f(cmb_f_) {
        build(n_, v);
    }

    // update k-th element (applied value: x)
    void update(int k, MonoidType x) {
        k += n - 1;
        node[k] = upd_f(node[k], x);
        while(k > 0) {
            k = (k - 1) / 2;
            node[k] = cmb_f(node[2*k+1], node[2*k+2]);
        }
    }

    // range query for [a, b)
    // 非再帰のアイデア: http://d.hatena.ne.jp/komiyam/20131202/1385992406
    MonoidType query(int a, int b) {
        MonoidType vl = E0, vr = E0;
        for(int l=a+n, r=b+n; l<r; l>>=1, r>>=1) {
            if(l & 1) vl = cmb_f(vl, node[(l++)-1]);
            if(r & 1) vr = cmb_f(node[(--r)-1], vr);
        }
        return cmb_f(vl, vr);
    }
};
#line 9 "string/verify/verify_str_009_manacher.cpp"

void tiny_test_str() {
    string s; cin >> s;
    char dummy = '$';

    Manacher<string, char> man(s, dummy);
    man.dump();
}

void tiny_test_int() {
    int N; cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++) cin >> v[i];
    int dummy = 0;

    Manacher< vector<int>, int > man(v, dummy);
    man.dump(false);
}

void yuki_464() {
    string s; cin >> s;
    int N = s.size();
    Manacher<string, char> man(s, '$');

    long long int dp[5010][5] = {};
    dp[0][0] = 1;
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<=N; j++) {
            for(int k=0; k<4; k++) {
                if(k != 2) {
                    if(!man.is_palindrome(i, j)) continue;
                    dp[j][k+1] += dp[i][k];
                }
                else {
                    dp[j][k+1] += dp[i][k];
                }
            }
        }
    }
    cout << dp[N][4] << endl;
}

void WUPC2019_E() {
    int N, M; cin >> N >> M;
    vector<int> row(N), col(M);
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            char c; cin >> c;
            if(c == '1') row[i]++, col[j]++;
        }
    }

    int dummy = -1, ans = 0;
    Manacher< vector<int>, int > mr(row, dummy), mc(col, dummy);
    for(int i=0; i<N-1; i++) {
        for(int j=0; j<M-1; j++) {
            bool ok = true;
            ok &= mr.is_palindrome(0, i+1);
            ok &= mr.is_palindrome(i+1, N);
            ok &= mc.is_palindrome(0, j+1);
            ok &= mc.is_palindrome(j+1, M);
            if(ok) ans++;
        }
    }
    cout << ans << endl;
}

void ukuku09_D() {
    struct SegFunc {
        static int update(int a, int b) { return max(a, b); }
        static int combine(int a, int b) { return max(a, b); }
    };
    
    int N, Q; cin >> N >> Q;
    string s; cin >> s;
    Manacher< string, char > man(s, '$');
    SegmentTree< int, SegFunc > seg(N, -1);

    for(int i=0; i<N; i++) {
        int rad = man.get_rad(i);
        seg.update(i, rad);
    }
    
    while(Q--) {
        int ql, qr; cin >> ql >> qr; ql--;

        int ub = (N + 1) / 2 + 1, lb = -1;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            int l = ql + mid - 1;
            int r = qr - mid + 1;

            bool ok = true;
            if(l >= r) ok = false;
            else {
                int val = seg.query(l, r);
                ok = (val >= mid);
            }

            if(ok) lb = mid;
            else ub = mid;
        }
        int ans = lb * 2 - 1;
        cout << ans << endl;
    }
}

int main() {
    // tiny_test_str();
    // tiny_test_int();
    // yuki_464();
    // WUPC2019_E();
    ukuku09_D();
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

