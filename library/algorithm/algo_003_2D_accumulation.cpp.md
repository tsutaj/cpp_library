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


# :warning: algorithm/algo_003_2D_accumulation.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/algo_003_2D_accumulation.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Required by

* :warning: <a href="verify/verify_algo_003_2D_accumulation.cpp.html">algorithm/verify/verify_algo_003_2D_accumulation.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 二次元累積演算 (0-indexed)
// 単位元と二項演算・その逆演算を与える
// 二次元 imos にも対応

template <typename MonoidType>
struct Accumulation2D {
    // 持つ矩形領域のサイズ
    // 縦横とも、acc はこれより 2 大きくしておく
    int n, m;
    MonoidType E;
    vector< vector<MonoidType> > acc;
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void build() {
        for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                acc[i][j+1] = op(acc[i][j+1], acc[i][j]);
            }
        }
        for(int j=0; j<=m; j++) {
            for(int i=0; i<n; i++) {
                acc[i+1][j] = op(acc[i+1][j], acc[i][j]);
            }
        }
    }

    Accumulation2D() {}
    Accumulation2D(int n_, int m_, int E_, MMtoM op_, MMtoM rop_) :
        n(n_), m(m_), E(E_), acc(n_+2, vector<MonoidType>(m_+2, E_)),
        op(op_), rop(rop_) {}
    Accumulation2D(vector< vector<MonoidType> > mat, int E_,
                   MMtoM op_, MMtoM rop_,
                   bool need_build = true) :
        E(E_), op(op_), rop(rop_) {
        assert(mat.size() > 0);
        n = mat.size(), m = mat[0].size();
        acc = vector< vector<MonoidType> >(n+2, vector<MonoidType>(m+2, E_));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                acc[i+1][j+1] = mat[i][j];
            }
        }
        if(need_build) build();
    }

    // [lx, rx), [ly, ry) の矩形領域に val を適用
    void range_add(int lx, int ly, int rx, int ry, MonoidType val) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return;
        lx++, ly++; rx++; ry++;
        acc[lx][ly] = op(acc[lx][ly], val);
        acc[rx][ry] = op(acc[rx][ry], val);
        acc[lx][ry] = rop(acc[lx][ry], val);
        acc[rx][ly] = rop(acc[rx][ly], val);
    }

    // [lx, rx), [ly, ry) の矩形領域の値
    MonoidType range_val(int lx, int ly, int rx, int ry) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return E;
        MonoidType res = E;
        res = op(res, acc[lx][ly]);
        res = op(res, acc[rx][ry]);
        res = rop(res, acc[lx][ry]);
        res = rop(res, acc[rx][ly]);
        return res;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "algorithm/algo_003_2D_accumulation.cpp"
// 二次元累積演算 (0-indexed)
// 単位元と二項演算・その逆演算を与える
// 二次元 imos にも対応

template <typename MonoidType>
struct Accumulation2D {
    // 持つ矩形領域のサイズ
    // 縦横とも、acc はこれより 2 大きくしておく
    int n, m;
    MonoidType E;
    vector< vector<MonoidType> > acc;
    using MMtoM = function< MonoidType(MonoidType, MonoidType) >;
    MMtoM op, rop;

    void build() {
        for(int i=0; i<=n; i++) {
            for(int j=0; j<m; j++) {
                acc[i][j+1] = op(acc[i][j+1], acc[i][j]);
            }
        }
        for(int j=0; j<=m; j++) {
            for(int i=0; i<n; i++) {
                acc[i+1][j] = op(acc[i+1][j], acc[i][j]);
            }
        }
    }

    Accumulation2D() {}
    Accumulation2D(int n_, int m_, int E_, MMtoM op_, MMtoM rop_) :
        n(n_), m(m_), E(E_), acc(n_+2, vector<MonoidType>(m_+2, E_)),
        op(op_), rop(rop_) {}
    Accumulation2D(vector< vector<MonoidType> > mat, int E_,
                   MMtoM op_, MMtoM rop_,
                   bool need_build = true) :
        E(E_), op(op_), rop(rop_) {
        assert(mat.size() > 0);
        n = mat.size(), m = mat[0].size();
        acc = vector< vector<MonoidType> >(n+2, vector<MonoidType>(m+2, E_));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                acc[i+1][j+1] = mat[i][j];
            }
        }
        if(need_build) build();
    }

    // [lx, rx), [ly, ry) の矩形領域に val を適用
    void range_add(int lx, int ly, int rx, int ry, MonoidType val) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return;
        lx++, ly++; rx++; ry++;
        acc[lx][ly] = op(acc[lx][ly], val);
        acc[rx][ry] = op(acc[rx][ry], val);
        acc[lx][ry] = rop(acc[lx][ry], val);
        acc[rx][ly] = rop(acc[rx][ly], val);
    }

    // [lx, rx), [ly, ry) の矩形領域の値
    MonoidType range_val(int lx, int ly, int rx, int ry) {
        if(lx < 0 or ly < 0 or rx > n or ry > m) return E;
        MonoidType res = E;
        res = op(res, acc[lx][ly]);
        res = op(res, acc[rx][ry]);
        res = rop(res, acc[lx][ry]);
        res = rop(res, acc[rx][ly]);
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

