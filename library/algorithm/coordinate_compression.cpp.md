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


# :heavy_check_mark: 座標圧縮 (Coordinate Compression) <small>(algorithm/coordinate_compression.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#ed469618898d75b149e5c7c4b6a1c415">algorithm</a>
* <a href="{{ site.github.repository_url }}/blob/master/algorithm/coordinate_compression.cpp">View this file on GitHub</a>
    - Last commit date: 2020-06-20 01:16:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp.html">verifying_test/yosupo/data_structure/associative_array/coordinate_compression.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once

// @brief 座標圧縮 (Coordinate Compression)

#include <vector>
#include <algorithm>
#include <cassert>

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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "algorithm/coordinate_compression.cpp"

// @brief 座標圧縮 (Coordinate Compression)

#include <vector>
#include <algorithm>
#include <cassert>

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

