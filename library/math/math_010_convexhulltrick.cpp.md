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


# :heavy_check_mark: Convex Hull Trick (Li-Chao Tree) <small>(math/math_010_convexhulltrick.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/math_010_convexhulltrick.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-07 01:10:06+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verifying_test/yosupo/SegmentAddGetMin.test.cpp.html">verifying_test/yosupo/SegmentAddGetMin.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// @brief Convex Hull Trick (Li-Chao Tree) 
template <typename X_Tp, typename Y_Tp>
struct LiChaoTree {
private:
    vector<X_Tp> X_pos;
    Y_Tp E;
    function<bool(Y_Tp, Y_Tp)> comp;
    int N;

    // @brief Line: 直線のクラス
    struct Line {
        bool is_empty;
        Y_Tp a, b; int index;

        Line() { is_empty = true; }
        Line(Y_Tp a_, Y_Tp b_, int index_)
            : a(a_), b(b_), index(index_) { is_empty = false; }
        
        bool empty() const { return is_empty; }
        Y_Tp f(X_Tp x) const { return a*x + b; }
    };

    vector<Line> node;

    void node_update(Line line, int t1, int t2, int l, int r, int k) {
        int mid = (l + r) / 2;
        if(t2 <= l or r <= t1) return;
        if(t1 <= l and r <= t2) {
            if(node[k].empty()) {
                node[k] = line;
                return;
            }

            if(comp(line.f(X_pos[l]), node[k].f(X_pos[l])) and
               comp(line.f(X_pos[r-1]), node[k].f(X_pos[r-1]))) return;

            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l])) and
               comp(node[k].f(X_pos[r-1]), line.f(X_pos[r-1]))) {
                node[k] = line;
                return;
            }

            if(r - l == 1) return;
            if(comp(node[k].f(X_pos[mid]), line.f(X_pos[mid]))) {
                swap(line, node[k]);
            }
                
            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l]))) {
                node_update(line, t1, t2, l, mid, 2*k+1);
            }
            else {
                node_update(line, t1, t2, mid, r, 2*k+2);
            }
        }
        else {
            node_update(line, t1, t2, l, mid, 2*k+1);
            node_update(line, t1, t2, mid, r, 2*k+2);
        }
    }

    pair<Y_Tp, int> search_line(int t) const {
        pair<Y_Tp, int> result(E, -1);
        int l = 0, r = N, k = 0;
        while(true) {
            if(!node[k].empty()) {
                pair<Y_Tp, int> cand(node[k].f(X_pos[t]), node[k].index);
                if(comp(result.first, cand.first)) result = cand;
            }

            if(r - l == 1) break;
            int mid = (l + r) / 2;
            if(t < mid) r = mid, k = 2*k + 1;
            else l = mid, k = 2*k + 2;
        }
        return result;
    }
    
public:
    // @brief クエリが与えられる座標・単位元・比較関数を渡す
    LiChaoTree(vector<X_Tp> X_pos_, Y_Tp E_,
               function<bool(Y_Tp, Y_Tp)> comp_)
        : X_pos(X_pos_), E(E_), comp(comp_) {
        sort(X_pos.begin(), X_pos.end());
        X_pos.erase(unique(X_pos.begin(), X_pos.end()), X_pos.end());
        N = 1; while(N < X_pos.size()) N <<= 1;
        while(X_pos.size() < N) X_pos.emplace_back(X_pos.back());
        node.resize(2*N-1, Line());
    }

    // @brief 直線 $y = ax + b$ を集合に加える (直線のインデックス番号を与えてもよい)
    void insert(Y_Tp a, Y_Tp b, int k=-1) {
        Line line(a, b, k);
        node_update(line, 0, N, 0, N, 0);
    }

    // @brief 線分 $y = ax + b$ ($x_1 \leq x \leq x_2$) を集合に加える (線分のインデックス番号を与えてもよい)
    void insert(Y_Tp a, Y_Tp b, X_Tp x1, X_Tp x2, int k=-1) {
        Line line(a, b, k);
        int t1 = lower_bound(X_pos.begin(), X_pos.end(), x1) - X_pos.begin();
        int t2 = lower_bound(X_pos.begin(), X_pos.end(), x2) - X_pos.begin();
        assert(t1 < X_pos.size() and X_pos[t1] == x1);
        assert(t2 < X_pos.size() and X_pos[t2] == x2); t2++;
        node_update(line, t1, t2, 0, N, 0);
    }

    // @brief $x$ を引数に与え、比較関数 comp により順序が最上となる直線 $f$ における値 $f(x)$ と、その直線のインデックスを返す
    pair<Y_Tp, int> query_pair(X_Tp x) const {
        int t = lower_bound(X_pos.begin(), X_pos.end(), x) - X_pos.begin();
        assert(t < X_pos.size() and X_pos[t] == x);
        return search_line(t);
    }

    // @brief `query_pair` で値だけ取ってくるバージョン
    Y_Tp query(X_Tp x) const {
        return query_pair(x).first;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/math_010_convexhulltrick.cpp"
// @brief Convex Hull Trick (Li-Chao Tree) 
template <typename X_Tp, typename Y_Tp>
struct LiChaoTree {
private:
    vector<X_Tp> X_pos;
    Y_Tp E;
    function<bool(Y_Tp, Y_Tp)> comp;
    int N;

    // @brief Line: 直線のクラス
    struct Line {
        bool is_empty;
        Y_Tp a, b; int index;

        Line() { is_empty = true; }
        Line(Y_Tp a_, Y_Tp b_, int index_)
            : a(a_), b(b_), index(index_) { is_empty = false; }
        
        bool empty() const { return is_empty; }
        Y_Tp f(X_Tp x) const { return a*x + b; }
    };

    vector<Line> node;

    void node_update(Line line, int t1, int t2, int l, int r, int k) {
        int mid = (l + r) / 2;
        if(t2 <= l or r <= t1) return;
        if(t1 <= l and r <= t2) {
            if(node[k].empty()) {
                node[k] = line;
                return;
            }

            if(comp(line.f(X_pos[l]), node[k].f(X_pos[l])) and
               comp(line.f(X_pos[r-1]), node[k].f(X_pos[r-1]))) return;

            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l])) and
               comp(node[k].f(X_pos[r-1]), line.f(X_pos[r-1]))) {
                node[k] = line;
                return;
            }

            if(r - l == 1) return;
            if(comp(node[k].f(X_pos[mid]), line.f(X_pos[mid]))) {
                swap(line, node[k]);
            }
                
            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l]))) {
                node_update(line, t1, t2, l, mid, 2*k+1);
            }
            else {
                node_update(line, t1, t2, mid, r, 2*k+2);
            }
        }
        else {
            node_update(line, t1, t2, l, mid, 2*k+1);
            node_update(line, t1, t2, mid, r, 2*k+2);
        }
    }

    pair<Y_Tp, int> search_line(int t) const {
        pair<Y_Tp, int> result(E, -1);
        int l = 0, r = N, k = 0;
        while(true) {
            if(!node[k].empty()) {
                pair<Y_Tp, int> cand(node[k].f(X_pos[t]), node[k].index);
                if(comp(result.first, cand.first)) result = cand;
            }

            if(r - l == 1) break;
            int mid = (l + r) / 2;
            if(t < mid) r = mid, k = 2*k + 1;
            else l = mid, k = 2*k + 2;
        }
        return result;
    }
    
public:
    // @brief クエリが与えられる座標・単位元・比較関数を渡す
    LiChaoTree(vector<X_Tp> X_pos_, Y_Tp E_,
               function<bool(Y_Tp, Y_Tp)> comp_)
        : X_pos(X_pos_), E(E_), comp(comp_) {
        sort(X_pos.begin(), X_pos.end());
        X_pos.erase(unique(X_pos.begin(), X_pos.end()), X_pos.end());
        N = 1; while(N < X_pos.size()) N <<= 1;
        while(X_pos.size() < N) X_pos.emplace_back(X_pos.back());
        node.resize(2*N-1, Line());
    }

    // @brief 直線 $y = ax + b$ を集合に加える (直線のインデックス番号を与えてもよい)
    void insert(Y_Tp a, Y_Tp b, int k=-1) {
        Line line(a, b, k);
        node_update(line, 0, N, 0, N, 0);
    }

    // @brief 線分 $y = ax + b$ ($x_1 \leq x \leq x_2$) を集合に加える (線分のインデックス番号を与えてもよい)
    void insert(Y_Tp a, Y_Tp b, X_Tp x1, X_Tp x2, int k=-1) {
        Line line(a, b, k);
        int t1 = lower_bound(X_pos.begin(), X_pos.end(), x1) - X_pos.begin();
        int t2 = lower_bound(X_pos.begin(), X_pos.end(), x2) - X_pos.begin();
        assert(t1 < X_pos.size() and X_pos[t1] == x1);
        assert(t2 < X_pos.size() and X_pos[t2] == x2); t2++;
        node_update(line, t1, t2, 0, N, 0);
    }

    // @brief $x$ を引数に与え、比較関数 comp により順序が最上となる直線 $f$ における値 $f(x)$ と、その直線のインデックスを返す
    pair<Y_Tp, int> query_pair(X_Tp x) const {
        int t = lower_bound(X_pos.begin(), X_pos.end(), x) - X_pos.begin();
        assert(t < X_pos.size() and X_pos[t] == x);
        return search_line(t);
    }

    // @brief `query_pair` で値だけ取ってくるバージョン
    Y_Tp query(X_Tp x) const {
        return query_pair(x).first;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

