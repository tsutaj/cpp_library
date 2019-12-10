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


# :warning: structure/strc_010_abst_sqrtdecomp.cpp
<a href="../../index.html">Back to top page</a>

* category: structure
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_010_abst_sqrtdecomp.cpp">View this file on GitHub</a> (Last commit date: 2019-11-22 21:50:52 +0900)




## Code
{% raw %}
```cpp
#include <cstdio>
#include <vector>
#include <climits>
using namespace std;
using ll = long long int;

template<typename Type>
struct SqrtDecomp {
    int SIZE;
    vector<Type> node, bucket, lazy, need_upd;
    Type (*op1) (Type x, Type y, int sz);
    Type (*op2) (Type x, Type y);
    Type I_op1, I_op2;

    SqrtDecomp( vector<Type> vec,
                Type (*g_op1) (Type x, Type y, int sz),
                Type (*g_op2) (Type x, Type y),
                Type X_op1, Type X_op2) {
        int N = vec.size();
        SIZE = 1; while(SIZE * SIZE < N) SIZE++;
        op1 = g_op1, op2 = g_op2;
        I_op1 = X_op1, I_op2 = X_op2;

        node.resize(SIZE*SIZE, I_op2);
        bucket.resize(SIZE, I_op2);
        lazy.resize(SIZE, I_op1);
        need_upd.resize(SIZE, 0);

        for(int i=0; i<SIZE; i++) {
            Type rep_val = I_op2;
            for(int j=0; j<SIZE && i*SIZE+j<N; j++) {
                int idx = (i*SIZE + j);
                node[idx] = vec[idx];
                rep_val = op2(rep_val, node[idx]);
            }
            bucket[i] = rep_val;
        }
    }

    void lazy_eval(int k) {
        int l = SIZE*k, r = SIZE*(k+1);
        if(need_upd[k]) {
            Type seg_val = I_op2;

            // 該当する下のノードをまず更新
            for(int i=l; i<r; i++) {
                node[i] = op1(node[i], lazy[k], 1);
                seg_val = op2(seg_val, node[i]);
            }

            // 上のノードを更新
            bucket[k] = seg_val;
        }
        lazy[k] = I_op1;
        need_upd[k] = false;
    }

    void update(int l, int r, Type val) {
        int lidx = l / SIZE, ridx = r / SIZE;
        // 左端の更新
        lazy_eval(lidx);
        bucket[lidx] = I_op2;
        for(int k=SIZE*lidx; k<SIZE*(lidx+1); k++) {
            if(l <= k && k < r) node[k] = op1(node[k], val, 1);
            bucket[lidx] = op2(bucket[lidx], node[k]);
        }

        if(lidx != ridx) {
            // 真ん中 (lazy を更新)
            for(int k=lidx+1; k<ridx; k++) {
                lazy[k] = op1(lazy[k], val, 1);
                need_upd[k] = true;
            }

            if(ridx != SIZE) {
                lazy_eval(ridx);
                bucket[ridx] = I_op2;

                // 右端の更新
                for(int k=SIZE*ridx; k<SIZE*(ridx+1); k++) {
                    if(k < r) node[k] = op1(node[k], val, 1);
                    bucket[ridx] = op2(bucket[ridx], node[k]);
                }
            }
        }
    }

    Type query(int l, int r) {
        int lidx = l / SIZE, ridx = r / SIZE;
        Type ret = I_op2;
        
        // 左端の取得
        for(int k=l; k<min(r, SIZE*(lidx+1)); k++) {
            lazy_eval(lidx);
            ret = op2(ret, node[k]);
        }

        if(lidx != ridx) {
            for(int k=lidx+1; k<ridx; k++) {
                // 全体の値と lazy の値を考慮して値を計算
                Type val = (need_upd[k] ? op1(bucket[k], lazy[k], SIZE) : bucket[k]);
                ret = op2(ret, val);
            }

            for(int k=SIZE*ridx; k<r; k++) {
                lazy_eval(ridx);
                ret = op2(ret, node[k]);
            }
        }

        return ret;
    }

    /*
    void print_debug() {
        printf("<< node >>\n");
        printf("upper bucket:\n");
        for(int i=0; i<SIZE; i++) {
            int l = SIZE*i, r = SIZE*(i+1);
            printf("[%6d, %6d) -> %lld\n", l, r, bucket[i]);
        }
        printf("lower bucket:\n");
        for(int i=0; i<SIZE*SIZE; i++) {
            printf("[%6d, %6d) -> %lld\n", i, i+1, node[i]);
        }

        printf("<< lazy >>\n");
        printf("upper bucket:\n");
        for(int i=0; i<SIZE; i++) {
            int l = SIZE*i, r = SIZE*(i+1);
            printf("[%6d, %6d) -> %lld\n", l, r, lazy[i]);
        }
        printf("\n");
    }
    */
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

