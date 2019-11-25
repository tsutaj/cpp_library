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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: strc\_013\_treap.cpp

## Code

```cpp
// Treap (平衡二分探索木)
// データ型・最大値用の単位元を指定して使う
// TODO: 使い方をまとめる (わすれるので)

inline int xor128() {
    static int x = 123456789;
    static int y = 362436069;
    static int z = 521288629;
    static int w = 88675123;
    int t;

    t = x ^ (x << 11);
    x = y;
    y = z;
    z = w;
    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

namespace trp {
    template <typename Type>
    struct node_t {
        Type val, sum, max_val, min_val;
        node_t<Type> *lch, *rch, *par;
        int cap, pri;
        node_t(int val_, int pri_) : 
            val(val_), sum(val_), max_val(val_), min_val(val_), cap(1), pri(pri_) {
                lch = rch = par = nullptr;
        }
    };

    // 扱う要素の型と、max, min に用いる単位元
    // (どれと max, min とっても変わらないやつ)
    template <typename Type, Type max_identity, Type min_identity>
    struct treap {
        using Treap = treap<Type, max_identity, min_identity>;
    private:
        size_t size_;
        node_t<Type>* root;

        // 根の情報
        void eval(node_t<Type> *t) { root = t, size_ = t ? count( update(t) ) : 0; }

        // 部分木の情報
        int  count  (node_t<Type>* t) { return t ? t->cap     : 0; }
        Type sum    (node_t<Type>* t) { return t ? t->sum     : 0; }
        Type max_val(node_t<Type>* t) { return t ? t->max_val : max_identity; }
        Type min_val(node_t<Type>* t) { return t ? t->min_val : min_identity; }

        // 部分木に関する情報の再計算
        node_t<Type>* update(node_t<Type>* t, Type val=max_identity) {
            if(val != max_identity) t->val = val;
            t->cap     = count(t->lch) + count(t->rch) + 1;
            t->sum     = sum  (t->lch) + sum  (t->rch) + t->val;
            t->max_val = max({max_val(t->lch), max_val(t->rch), t->val});
            t->min_val = min({min_val(t->lch), min_val(t->rch), t->val});
            if(t->par) update(t->par);
            return t;        
        }
    public:
        node_t<Type>* merge(node_t<Type>* l, node_t<Type>* r) {
            if(!l || !r) return !l ? r : l;

            if(l->pri > r->pri) {
                if(l->rch) l->rch->par = nullptr;
                node_t<Type>* child = merge(l->rch, r);
                l->rch = child;
                if(child) child->par = l;
                return update(l);
            }
            else {
                if(r->lch) r->lch->par = nullptr;
                node_t<Type>* child = merge(l, r->lch);
                r->lch = child;
                if(child) child->par = r;
                return update(r);
            }
        }

        // 場所 k で split  [0, k), [k, n)
        pair<node_t<Type>*, node_t<Type>*> split(node_t<Type>* t, int k) {
            if(t == nullptr) return make_pair(nullptr, nullptr);

            if(k <= count(t->lch)) {
                if(t->lch) t->lch->par = nullptr;
                pair<node_t<Type>*, node_t<Type>*> s = split(t->lch, k);
                t->lch = s.second;
                if(s.second) s.second->par = t;
                return make_pair(s.first, update(t));
            }
            else {
                if(t->rch) t->rch->par = nullptr;
                pair<node_t<Type>*, node_t<Type>*> s = split(t->rch, k - count(t->lch) - 1);
                t->rch = s.first;
                if(s.first) s.first->par = t;
                return make_pair(update(t), s.second);
            }
        }

        node_t<Type>* insert(node_t<Type>* t, int k, Type val, int pri) {
            pair<node_t<Type>*, node_t<Type>*> lr = split(t, k);
            node_t<Type>* newElem = new node_t<Type>(val, pri);

            node_t<Type>* res = merge(lr.first, newElem);
            res = merge(res, lr.second);
            return res;
        }

        node_t<Type>* erase(node_t<Type>* t, int k) {
            pair<node_t<Type>*, node_t<Type>*> lr2 = split(t, k+1);

            t = lr2.first;
            pair<node_t<Type>*, node_t<Type>*> lr1 = split(t, k  );

            node_t<Type>* res = merge(lr1.first, lr2.second);
            return res;
        }

        // k 番目の要素 (0-indexed)
        node_t<Type>* kth_node(node_t<Type>* t, int k) {
            assert(k < count(t));

            if(count(t->lch) >= k + 1) {
                return kth_node(t->lch, k);
            }
            else if(count(t->lch) + 1 == k + 1) {
                return t;
            }
            else {
                return kth_node(t->rch, k - count(t->lch) - 1);
            }
        }

        Type kth_number(node_t<Type>* t, int k) {
            assert(k < size());
            return kth_node(t, k)->val;
        }

        // lower bound (0-indexed)
        int lower_bound(node_t<Type>* t, Type val, int idx=0) {
            if(t == nullptr) return idx;

            if(t->lch && t->lch->max_val >= val) {
                return lower_bound(t->lch, val, idx);
            }
            if(t->val >= val) {
                return idx + (count(t) - count(t->rch)) - 1;
            }
            if(t->rch && t->rch->max_val >= val) {
                return lower_bound(t->rch, val, idx + count(t->lch) + 1);
            }
            return idx + count(t);
        }

        // upper bound (0-indexed)
        int upper_bound(node_t<Type>* t, Type val, int idx=0) {
            if(t == nullptr) return idx;
            if(t->lch && t->lch->max_val > val) {
                return upper_bound(t->lch, val, idx);
            }
            if(t->val > val) {
                return idx + (count(t) - count(t->rch)) - 1;
            }
            if(t->rch && t->rch->max_val > val) {
                return lower_bound(t->rch, val, idx + count(t->lch) + 1);
            }
            return idx + count(t);
        }

        int get_idx(node_t<Type>* t) {
            if(t->par == nullptr) return count(t->lch);
            else if(t->par->lch == t) {
                return get_idx(t->par) - count(t->rch) - 1;
            }
            else {
                return get_idx(t->par) + count(t->lch) + 1;
            }
        }

        // rmq を解く (minmax: 0 で最大、1 で最小)
        Type rmq_query(int a, int b, int l, int r, node_t<Type>* cur, int minmax) {
            Type identity = (minmax ? min_identity : max_identity);
            if(r <= a || b <= l || !cur) return identity;
            if(a <= l && r <= b) return (minmax ? cur->min_val : cur->max_val);
            // 答え (現在の頂点を入れることも)
            int idx = get_idx(cur), nl, nr;
            Type ans = (a <= idx && idx < b) ? cur->val : identity;

            auto get = [&](Type A, Type B) {
                return minmax ? min(A, B) : max(A, B);
            };

            // 左の子へ (右端が縮む)
            if(cur->lch) {
                nl = l, nr = r - 1 - count(cur->rch);
                ans = get(ans, rmq_query(a, b, nl, nr, cur->lch, minmax));
            }

            // 右の子へ (左端が縮む)
            if(cur->rch) {
                nl = l + 1 + count(cur->lch), nr = r;
                ans = get(ans, rmq_query(a, b, nl, nr, cur->rch, minmax));
            }
            return ans;
        }

        treap()                  { size_ = 0, root = nullptr; }
        treap(node_t<Type>* r)   { eval(r); }
        node_t<Type>* get_root() { return root; }
        size_t  size () { return size_; }
        bool    empty() { return size_ == 0; }

        void insert(Type val, int k) {
            int pri = xor128();
            eval( insert(root, k, val, pri) );
        }
        void erase(int k) {
            eval( erase(root, k) );
        }

        pair< Treap, Treap > split(int k) {
            pair<node_t<Type>*, node_t<Type>*> lr = split(root, k);
            return make_pair(Treap(lr.first), Treap(lr.second));
        }
        Treap merge(Treap l, Treap r) {
            eval( merge(l.get_root(), r.get_root()) );
            return Treap(root);
        }
        node_t<Type>* kth_node(int k) {
            return kth_node(root, k);
        }
        Type kth_number(int k) {
            return kth_number(root, k);
        }
        int lower_bound(Type val) {
            return lower_bound(root, val);
        }
        int upper_bound(Type val) {
            return upper_bound(root, val);
        }
        void update(Type val, int k) {
            node_t<Type>* node = kth_node(k);
            update(node, val);
        }
        bool find(Type val) {
            int idx = lower_bound(val);
            if(idx >= size_) return false;
            return kth_number(idx) == val;
        }

        Type find_min(int l, int r) {
            return rmq_query(l, r, 0, size(), root, 1);
        }
        Type find_max(int l, int r) {
            return rmq_query(l, r, 0, size(), root, 0);
        }

        void dump_array() {
            for(int i=0; i<size(); i++) {
                fprintf(stderr, "%d ", kth_number(i));
            }
            fprintf(stderr, "\n");
        }

        // みさわさんの根付き木と多分同じフォーマット？
        void dump_tree(node_t<Type>* t) {
            if(t == nullptr) return;
            if(t->lch) {
                fprintf(stderr, "(");
                dump_tree(t->lch);
                fprintf(stderr, ")");
            }
            fprintf(stderr, "[%d", t->val);
            if(t->par) {
                fprintf(stderr, "<%d>", t->par->val);
            }
            else {
                fprintf(stderr, "<NA>");
            }
            fprintf(stderr, "]");
            if(t->rch) {
                fprintf(stderr, "(");
                dump_tree(t->rch);
                fprintf(stderr, ")");
            }
        }
    };

    // 重複を許さない全順序集合
    template <typename Type, Type max_identity, Type min_identity>
    struct Set : public treap<Type, max_identity, min_identity> {
    public:
        using PTreap = treap<Type, max_identity, min_identity>;
        bool empty() { return PTreap::size() == 0; }
        void insert(Type val) {
            if(PTreap::find(val)) return;
            int idx = PTreap::lower_bound(val);
            PTreap::insert(val, idx);
        }

        void erase(Type val) {
            if(empty() || !PTreap::find(val)) return;
            int idx = PTreap::lower_bound(val);
            PTreap::erase(idx);
        }
    };

    // TODO: multiset も書く
}

```

[トップページに戻る](../index.html)
