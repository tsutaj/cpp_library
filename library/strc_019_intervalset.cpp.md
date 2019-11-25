<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_019\_intervalset.cpp

## Code

```cpp
// 区間を set で管理するやつ
// 閉区間 [l, r] を扱うことに注意
template <typename numericType, numericType infty = numeric_limits<numericType>::max() >
struct IntervalSet : set< pair<numericType, numericType> > {
    // x を含む閉区間 [l, r] を取得
    // イテレータを返す
    auto get(numericType x) {
        // x より始点が大きい区間の中で最小のもの
        auto itr = this->upper_bound(make_pair(x, infty));
        if(itr == this->begin() or (--itr)->second < x) return this->end();
        return itr;
    }

    // [l, r] と overlap する区間の集合を取得
    // vector を返す
    vector< pair<numericType, numericType> > get(numericType l, numericType r) {
        auto itr = this->upper_bound(make_pair(l, l));
        if(itr != this->begin()) itr--;

        vector< pair<numericType, numericType> > res;
        for(; itr != this->end(); itr++) {
            numericType il, ir; tie(il, ir) = *itr;
            if(r < il) break; // 対称区間に対して右に飛び出た
            // 対称区間に対して左に飛び出るか、含まれているかしかない
            if(ir >= l) res.push_back(make_pair(il, ir));
        }
        return res;
    }
    
    void insert(numericType l, numericType r) {
        auto vec = this->get(l, r);
        numericType il = l, ir = r;
        for(auto e : vec) {
            this->erase(e);
            il = min(il, e.first);
            ir = max(ir, e.second);
        }
        this->emplace(il, ir);
    }
    
    void remove(numericType l, numericType r) {
        auto vec = this->get(l, r);
        for(auto e : vec) this->erase(e);
    }

    // p と q は同じ区間上にあるか？
    bool same(numericType p, numericType q) {
        auto itr = get(p);
        return itr != this->end() and itr->first <= q and q <= itr.second;
    }

    void dump() {
        for(auto e : *this) {
            numericType l, r; tie(l, r) = e;
            fprintf(stderr, "# debug: [%g, %g]\n", l, r);
        }
    }
};

```

[トップページに戻る](../index.html)
