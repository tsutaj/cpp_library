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
<script type="text/javascript" src="../../assets/js/balloons.js"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: ../../algorithm/algo_001_mo.cpp
* category: ../../algorithm


[Back to top page](../../index.html)



## Code
```cpp
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

// Mo のアルゴリズム (以下の条件を満たすときにクエリを高速に処理可能)
// ・オフラインクエリ
// ・クエリの対象となる数列が不変
// ・区間の伸縮にかかる計算量が小さい
struct Mo {
    int bucket, nl, nr, ptr;
    vector<int> left, right, query_idx;
    vector<bool> state;

    Mo(int N) : bucket(sqrt(N) + 1), nl(0), nr(0), ptr(0), state(N) {
        left = right = vector<int>();
    }

    // 区間 [l, r) を追加
    void insert(int l, int r) {
        left.push_back(l);
        right.push_back(r);
    }

    // ソートする (バケットごとに、バケット同じなら右端小さい順)
    void build() {
        query_idx = vector<int>(left.size());
        iota(query_idx.begin(), query_idx.end(), 0);
        sort(query_idx.begin(), query_idx.end(), [&](int a, int b) {
                if(left[a] / bucket != left[b] / bucket) return left[a] < left[b];
                return right[a] < right[b];
            });
    }
    
    // クエリを一つすすめて、そのクエリ id を返す
    int proceed() {
        if(ptr == query_idx.size()) return -1;
        int id = query_idx[ptr];
        while(nl > left[id] ) operate(--nl);
        while(nr < right[id]) operate(nr++);
        while(nl < left[id] ) operate(nl++);
        while(nr > right[id]) operate(--nr);
        return query_idx[ptr++];
    }

    void operate(int idx) {
        state[idx].flip();
        if(state[idx]) add(idx);
        else del(idx);
    }

    void add(int idx);
    void del(int idx);
};

int A[200010], cnt[1000010];
long long int res = 0;
void Mo::add(int idx) {
    long long int pre = cnt[ A[idx] ];
    long long int nxt = pre + 1;
    res -= pre * pre * A[idx];
    res += nxt * nxt * A[idx];
    cnt[ A[idx] ]++;
}

void Mo::del(int idx) {
    long long int pre = cnt[ A[idx] ];
    long long int nxt = pre - 1;
    res -= pre * pre * A[idx];
    res += nxt * nxt * A[idx];
    cnt[ A[idx] ]--;
}

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    Mo mo(N);
    for(int i=0; i<Q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mo.insert(--l, r);
    }

    mo.build();
    vector<long long int> ans(Q);
    for(int i=0; i<Q; i++) {
        int idx = mo.proceed();
        // fprintf(stderr, "idx = %lld\n", idx);
        ans[idx] = res;
    }

    for(int i=0; i<Q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}

```

[Back to top page](../../index.html)

