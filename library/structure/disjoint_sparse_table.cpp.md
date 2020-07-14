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


# :question: Disjoint Sparse Table <small>(structure/disjoint_sparse_table.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/disjoint_sparse_table.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-15 08:51:51+09:00


* see: <a href="https://noshi91.hatenablog.com/entry/2018/05/08/183946">https://noshi91.hatenablog.com/entry/2018/05/08/183946</a>


- 構築: $O(N \log N)$
- クエリ: $O(1)$
  - 普通の Sparse Table とは違い、結合則を満たすものなら乗るため、和や xor, gcd などでも OK


## Verified with

* :x: <a href="../../verify/verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp.html">verifying_test/yosupo/data_structure/static_range_sum/disjoint_sparse_table.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verifying_test/yosupo/data_structure/static_rmq/disjoint_sparse_table.test.cpp.html">verifying_test/yosupo/data_structure/static_rmq/disjoint_sparse_table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// @brief Disjoint Sparse Table
// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946
// @docs ./docs/disjoint_sparse_table.md

#include <vector>
#include <functional>
#include <cassert>

template <typename Tp>
struct DisjointSparseTable {
    size_t N, LN;
    vector<Tp> A;
    vector< vector<Tp> > seg_l, seg_r;
    function<Tp(Tp, Tp)> cmb_f;
    
    DisjointSparseTable() = default;
    DisjointSparseTable(vector<Tp> A_,
                        function<Tp(Tp, Tp)> cmb_f_)
        : A(A_), cmb_f(cmb_f_) {
        N = A.size(), LN = 1;
        while((1<<LN) < N) LN++;
        seg_l.resize(LN, vector<Tp>(N));
        seg_r.resize(LN, vector<Tp>(N));
        build(A);
    }

    void build(const vector<Tp> &A) {
        for(int i=0; i<LN; i++) {
            // [j-(1<<i), j), [ j, j+(1<<i) )
            for(int j=(1<<i); j<=N; j+=(1<<(i+1))) {
                if(j < N) seg_r[i][j] = A[j];
                for(int k=j+1; k<j+(1<<i); k++) {
                    if(k >= N) break;
                    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);
                }
                if(j-1 >= 0) seg_l[i][j-1] = A[j-1];
                for(int k=j-2; k>=j-(1<<i); k--) {
                    if(k < 0) break;
                    seg_l[i][k] = cmb_f(seg_l[i][k+1], A[k]);
                }
            }
        }
    }

    Tp query(size_t l, size_t r) {
        assert(l < r and r <= N); r--;
        if(l == r) return A[l];
        int k = 31 - __builtin_clz((unsigned int)(l ^ r));
        return cmb_f(seg_l[k][l], seg_r[k][r]);
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "structure/disjoint_sparse_table.cpp"

// @brief Disjoint Sparse Table
// @see https://noshi91.hatenablog.com/entry/2018/05/08/183946
// @docs ./docs/disjoint_sparse_table.md

#include <vector>
#include <functional>
#include <cassert>

template <typename Tp>
struct DisjointSparseTable {
    size_t N, LN;
    vector<Tp> A;
    vector< vector<Tp> > seg_l, seg_r;
    function<Tp(Tp, Tp)> cmb_f;
    
    DisjointSparseTable() = default;
    DisjointSparseTable(vector<Tp> A_,
                        function<Tp(Tp, Tp)> cmb_f_)
        : A(A_), cmb_f(cmb_f_) {
        N = A.size(), LN = 1;
        while((1<<LN) < N) LN++;
        seg_l.resize(LN, vector<Tp>(N));
        seg_r.resize(LN, vector<Tp>(N));
        build(A);
    }

    void build(const vector<Tp> &A) {
        for(int i=0; i<LN; i++) {
            // [j-(1<<i), j), [ j, j+(1<<i) )
            for(int j=(1<<i); j<=N; j+=(1<<(i+1))) {
                if(j < N) seg_r[i][j] = A[j];
                for(int k=j+1; k<j+(1<<i); k++) {
                    if(k >= N) break;
                    seg_r[i][k] = cmb_f(seg_r[i][k-1], A[k]);
                }
                if(j-1 >= 0) seg_l[i][j-1] = A[j-1];
                for(int k=j-2; k>=j-(1<<i); k--) {
                    if(k < 0) break;
                    seg_l[i][k] = cmb_f(seg_l[i][k+1], A[k]);
                }
            }
        }
    }

    Tp query(size_t l, size_t r) {
        assert(l < r and r <= N); r--;
        if(l == r) return A[l];
        int k = 31 - __builtin_clz((unsigned int)(l ^ r));
        return cmb_f(seg_l[k][l], seg_r[k][r]);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

