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


# :warning: structure/verify/verify_strc_023_compact_bitvector.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#8a42e2f360efd149dd1f7c64fba9767e">structure/verify</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/verify/verify_strc_023_compact_bitvector.cpp">View this file on GitHub</a>
    - Last commit date: 2020-04-07 00:18:26+09:00




## Depends on

* :heavy_check_mark: <a href="../strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../strc_023_compact_bitvector.cpp"

int main() {
    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];

    SuccinctBitVector<> sb(vec);
    for(int i=0; i<N; i++) {
        cout << sb.rank(i) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_nxt(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_pre(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;

    cout << "count: " << sb.count() << ", size = " << sb.size() << endl;
    
/*
    while(true) {
        int q; cin >> q;
        if(q == 1) {
            int k; cin >> k; k--;
            cout << sb.rank(k) << endl;
        }
        if(q == 2) {
            int k; cin >> k; k--;
            int a = sb.select_nxt(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 3) {
            int k; cin >> k; k--;
            int a = sb.select_pre(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 4) {
            int l, r; cin >> l >> r; l--;
            cout << sb.rank(l, r) << endl;
        }
    }
*/
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/verify/verify_strc_023_compact_bitvector.cpp"
#include <cinttypes>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#line 2 "structure/strc_023_compact_bitvector.cpp"

// @title 簡潔ビットベクトル (compact bit vector)
// 簡潔ビットベクトル (数列の長さを N とする)
// n_big <- log^2(N)   (N = 2^32 としたとき、n_big = 32^2 = 1024 = 2^10)
// n_sml <- log(N) / 2 (N = 2^32 としたとき、n_sml = 32/2 = 16 = 2^4)
// n_blk <- n_big を n_sml で割ったもの
// ln_big, ln_sml には、それぞれ log(n_big), log(n_sml) をいれる

template <typename value_type = int,
          uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct CompactBitVector {
private:
    size_t n, n_big, n_sml, n_blk, ln_blk;
    vector<value_type> big, sml, bit;
    
    int popcount(value_type b) const {
        return __builtin_popcountll(b); // GCC builtin function
    }
    void build(vector<value_type> vec);

public:
    // 構築: O(N)
    CompactBitVector();
    CompactBitVector(vector<value_type> vec);
    CompactBitVector(vector<value_type> vec, int k);
    // 数列のサイズ: O(1)
    size_t size() const;
    // 全体の 1 の個数: O(1)
    int count() const;
    // k 番目の値: O(1)
    int value(size_t k) const;
    // [0, k] に存在する 1 の個数: O(1)
    int rank(size_t k) const;
    // [l, r) に存在する 1 の個数: O(1)
    int rank(size_t l, size_t r) const;
    // 1 / 0 の個数 が r を超える、インデックス k 未満最小の要素を返す: O(log N)
    int select1(int r, int k) const;
    int select0(int r, int k) const;
    // k 番目の次に存在する 1 / 0 は何か: O(log N)
    int select1_nxt(size_t k) const;
    int select0_nxt(size_t k) const;
    // k 番目の前に存在する 1 / 0 は何か: O(log N)
    int select1_pre(size_t k) const;
    int select0_pre(size_t k) const;
    // ビットベクトルの k 番目にアクセス
    int at(size_t k) const;
    int operator[](size_t k) const;

    // 出力するだけ
    void show() const {
        cerr << "# big ";
        for(size_t i=0; i<big.size(); i++) {
            cerr << big[i] << " ";
        }
        cerr << endl;
        cerr << "# sml ";
        for(size_t i=0; i<sml.size(); i++) {
            cerr << sml[i] << " ";
        }
        cerr << endl;
        cerr << "# bit ";
        for(size_t i=0; i<bit.size(); i++) {
            cerr << bit[i] << " ";
        }
        cerr << endl;
    }
};

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
void CompactBitVector<value_type, ln_big, ln_sml>::build(vector<value_type> vec) {
    big.resize(((n + n_big - 1) >> ln_big) + 1); // O(N / log^2 N) memory
    sml.resize(big.size() << ln_blk); // O(N / log N) memory
    bit.resize(big.size() << ln_blk); // O(N / log N) memory
    for(size_t i=0; i<n; i++) {
        size_t b = i >> ln_big;
        big[b+1] += vec[i];
        size_t s = i >> ln_sml, m = i & (n_sml - 1);
        sml[s] += vec[i];
        bit[s] |= (static_cast<value_type>(vec[i]) << m);
    }

    // accumulate
    for(size_t i=1; i<big.size(); i++) big[i] += big[i-1];
    for(size_t i=0; i<big.size(); i++) {
        for(size_t j=1; j<n_blk; j++) {
            sml[(i << ln_blk) + j] += sml[(i << ln_blk) + j - 1];
        }
    }
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<value_type, ln_big, ln_sml>::CompactBitVector() {}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<value_type, ln_big, ln_sml>::CompactBitVector(vector<value_type> vec)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),
      n_blk(n_big >> ln_sml), ln_blk(ln_big - ln_sml) {
    build(vec);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
CompactBitVector<value_type, ln_big, ln_sml>::CompactBitVector(vector<value_type> vec, int k)
    : n(vec.size()), n_big(1ULL << ln_big), n_sml(1ULL << ln_sml),
      n_blk(n_big >> ln_sml), ln_blk(ln_big - ln_sml) {
    vector<value_type> n_vec;
    for(auto e : vec) n_vec.emplace_back(e >> k & 1);
    build(n_vec);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
size_t CompactBitVector<value_type, ln_big, ln_sml>::size() const {
    return n;
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::count() const {
    return rank(n-1);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::value(size_t k) const {
    if(k >= n) return 0;
    size_t m = k & (n_sml - 1);
    return bit[k >> ln_sml] >> m & 1;
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::rank(size_t k) const {
    if(k >= n) return 0; // for range query
    size_t m = k & (n_sml - 1), mask = (1ULL << n_sml) - (1ULL << (m+1));
    return big[k >> ln_big] + sml[k >> ln_sml] - popcount(bit[k >> ln_sml] & mask);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::rank(size_t l, size_t r) const {
    if(l >= r) return 0;
    return rank(r-1) - rank(l-1);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select1(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select0(int r, int k) const {
    int ub = n+1, lb = -1;
    while(ub - lb > 1) {
        int mid = (ub + lb) / 2;
        if(mid + 1 - rank(mid) > r) ub = mid;
        else lb = mid;
    }
    return (ub < k) ? ub : -1;
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select1_nxt(size_t k) const {
    return select1(rank(k), n);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select0_nxt(size_t k) const {
    return select0(rank(k), n);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select1_pre(size_t k) const {
    return select1(rank(k) - 1 - value(k), k);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::select0_pre(size_t k) const {
    return select0(rank(k) - 1 - value(k), k);
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::at(size_t k) const {
    return bit[k >> ln_sml] >> (k & (n_sml - 1)) & 1;
}

template <typename value_type, uint64_t ln_big, uint64_t ln_sml>
int CompactBitVector<value_type, ln_big, ln_sml>::operator[](size_t k) const {
    return at(k);
}
#line 8 "structure/verify/verify_strc_023_compact_bitvector.cpp"

int main() {
    int N; cin >> N;
    vector<int> vec(N);
    for(int i=0; i<N; i++) cin >> vec[i];

    SuccinctBitVector<> sb(vec);
    for(int i=0; i<N; i++) {
        cout << sb.rank(i) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_nxt(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;
    for(int i=0; i<N; i++) {
        int a = sb.select_pre(i);
        cout << (a < 0 ? -1 : a + 1) << " ";
    }
    cout << endl;

    cout << "count: " << sb.count() << ", size = " << sb.size() << endl;
    
/*
    while(true) {
        int q; cin >> q;
        if(q == 1) {
            int k; cin >> k; k--;
            cout << sb.rank(k) << endl;
        }
        if(q == 2) {
            int k; cin >> k; k--;
            int a = sb.select_nxt(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 3) {
            int k; cin >> k; k--;
            int a = sb.select_pre(k);
            cout << (a < 0 ? -1 : a + 1) << endl;
        }
        if(q == 4) {
            int l, r; cin >> l >> r; l--;
            cout << sb.rank(l, r) << endl;
        }
    }
*/
    return 0;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
