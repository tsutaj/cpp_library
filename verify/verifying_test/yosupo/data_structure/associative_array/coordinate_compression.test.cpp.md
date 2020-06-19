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
<script type="text/javascript" src="../../../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../../../assets/css/copy-button.css" />


# :heavy_check_mark: verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp

<a href="../../../../../index.html">Back to top page</a>

* category: <a href="../../../../../index.html#47791248b3f68d6af5a6a97e7867d7fd">verifying_test/yosupo/data_structure/associative_array</a>
* <a href="{{ site.github.repository_url }}/blob/master/verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-20 01:16:29+09:00


* see: <a href="https://judge.yosupo.jp/problem/associative_array">https://judge.yosupo.jp/problem/associative_array</a>


## Depends on

* :heavy_check_mark: <a href="../../../../../library/algorithm/coordinate_compression.cpp.html">座標圧縮 (Coordinate Compression) <small>(algorithm/coordinate_compression.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <tuple>
#include <utility>
using ll = long long int;
using namespace std;

#define call_from_test
#include "../../../../algorithm/coordinate_compression.cpp"
#undef call_from_test

int main() {
    int Q; scanf("%d", &Q);
    vector< tuple<ll, ll, ll> > queries(Q);
    vector<ll> indices(Q);
    for(int i=0; i<Q; i++) {
        ll t, k, v=-1; scanf("%lld", &t);
        if(t == 0) {
            scanf("%lld%lld", &k, &v);
        }
        if(t == 1) {
            scanf("%lld", &k);
        }
        queries[i] = make_tuple(t, k, v);
        indices[i] = k;
    }

    coor_comp<ll> comp(indices);
    vector<ll> rec(comp.size());
    for(int i=0; i<Q; i++) {
        ll t, k, v; tie(t, k, v) = queries[i];
        if(t == 0) {
            rec[ comp[k] ] = v;
        }
        if(t == 1) {
            printf("%lld\n", rec[ comp[k] ]);
        }
    }
    return 0;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/associative_array"
#include <vector>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <tuple>
#include <utility>
using ll = long long int;
using namespace std;

#define call_from_test
#line 2 "algorithm/coordinate_compression.cpp"

// @brief 座標圧縮 (Coordinate Compression)

#line 8 "algorithm/coordinate_compression.cpp"

template <typename Tp>
struct coor_comp {
private:
    vector<Tp> vec;

public:
    coor_comp() : vec() {}
    coor_comp(int n) : vec() { vec.reserve(n); }
    coor_comp(const vector<Tp> &vec_) : vec(vec_) { build(); }

    size_t size() const {
        return vec.size();
    }
    
    void emplace_back(Tp value) {
        vec.emplace_back(value);
    }

    void build() {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
       
    int operator[](const Tp &value) const {
        auto itr = lower_bound(vec.begin(), vec.end(), value);
        assert(itr != vec.end() and *itr == value);
        return itr - vec.begin();
    }

    vector<int> compress(const vector<Tp> &A) {
        vector<int> comp_vec(A.size());
        for(size_t i=0; i<A.size(); i++) comp_vec[i] = (*this)[ A[i] ];
        return comp_vec;
    }
};
#line 13 "verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp"
#undef call_from_test

int main() {
    int Q; scanf("%d", &Q);
    vector< tuple<ll, ll, ll> > queries(Q);
    vector<ll> indices(Q);
    for(int i=0; i<Q; i++) {
        ll t, k, v=-1; scanf("%lld", &t);
        if(t == 0) {
            scanf("%lld%lld", &k, &v);
        }
        if(t == 1) {
            scanf("%lld", &k);
        }
        queries[i] = make_tuple(t, k, v);
        indices[i] = k;
    }

    coor_comp<ll> comp(indices);
    vector<ll> rec(comp.size());
    for(int i=0; i<Q; i++) {
        ll t, k, v; tie(t, k, v) = queries[i];
        if(t == 0) {
            rec[ comp[k] ] = v;
        }
        if(t == 1) {
            printf("%lld\n", rec[ comp[k] ]);
        }
    }
    return 0;
}

```
{% endraw %}

<a href="../../../../../index.html">Back to top page</a>

