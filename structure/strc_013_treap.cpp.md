---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"structure/strc_013_treap.cpp\"\n// Treap (\u5E73\u8861\u4E8C\
    \u5206\u63A2\u7D22\u6728)\n// \u30C7\u30FC\u30BF\u578B\u30FB\u6700\u5927\u5024\
    \u7528\u306E\u5358\u4F4D\u5143\u3092\u6307\u5B9A\u3057\u3066\u4F7F\u3046\n// TODO:\
    \ \u4F7F\u3044\u65B9\u3092\u307E\u3068\u3081\u308B (\u308F\u3059\u308C\u308B\u306E\
    \u3067)\n\ninline int xor128() {\n    static int x = 123456789;\n    static int\
    \ y = 362436069;\n    static int z = 521288629;\n    static int w = 88675123;\n\
    \    int t;\n\n    t = x ^ (x << 11);\n    x = y;\n    y = z;\n    z = w;\n  \
    \  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\n\nnamespace trp {\n    template\
    \ <typename Type>\n    struct node_t {\n        Type val, sum, max_val, min_val;\n\
    \        node_t<Type> *lch, *rch, *par;\n        int cap, pri;\n        node_t(int\
    \ val_, int pri_) : \n            val(val_), sum(val_), max_val(val_), min_val(val_),\
    \ cap(1), pri(pri_) {\n                lch = rch = par = nullptr;\n        }\n\
    \    };\n\n    // \u6271\u3046\u8981\u7D20\u306E\u578B\u3068\u3001max, min \u306B\
    \u7528\u3044\u308B\u5358\u4F4D\u5143\n    // (\u3069\u308C\u3068 max, min \u3068\
    \u3063\u3066\u3082\u5909\u308F\u3089\u306A\u3044\u3084\u3064)\n    template <typename\
    \ Type, Type max_identity, Type min_identity>\n    struct treap {\n        using\
    \ Treap = treap<Type, max_identity, min_identity>;\n    private:\n        size_t\
    \ size_;\n        node_t<Type>* root;\n\n        // \u6839\u306E\u60C5\u5831\n\
    \        void eval(node_t<Type> *t) { root = t, size_ = t ? count( update(t) )\
    \ : 0; }\n\n        // \u90E8\u5206\u6728\u306E\u60C5\u5831\n        int  count\
    \  (node_t<Type>* t) { return t ? t->cap     : 0; }\n        Type sum    (node_t<Type>*\
    \ t) { return t ? t->sum     : 0; }\n        Type max_val(node_t<Type>* t) { return\
    \ t ? t->max_val : max_identity; }\n        Type min_val(node_t<Type>* t) { return\
    \ t ? t->min_val : min_identity; }\n\n        // \u90E8\u5206\u6728\u306B\u95A2\
    \u3059\u308B\u60C5\u5831\u306E\u518D\u8A08\u7B97\n        node_t<Type>* update(node_t<Type>*\
    \ t, Type val=max_identity) {\n            if(val != max_identity) t->val = val;\n\
    \            t->cap     = count(t->lch) + count(t->rch) + 1;\n            t->sum\
    \     = sum  (t->lch) + sum  (t->rch) + t->val;\n            t->max_val = max({max_val(t->lch),\
    \ max_val(t->rch), t->val});\n            t->min_val = min({min_val(t->lch), min_val(t->rch),\
    \ t->val});\n            if(t->par) update(t->par);\n            return t;   \
    \     \n        }\n    public:\n        node_t<Type>* merge(node_t<Type>* l, node_t<Type>*\
    \ r) {\n            if(!l || !r) return !l ? r : l;\n\n            if(l->pri >\
    \ r->pri) {\n                if(l->rch) l->rch->par = nullptr;\n             \
    \   node_t<Type>* child = merge(l->rch, r);\n                l->rch = child;\n\
    \                if(child) child->par = l;\n                return update(l);\n\
    \            }\n            else {\n                if(r->lch) r->lch->par = nullptr;\n\
    \                node_t<Type>* child = merge(l, r->lch);\n                r->lch\
    \ = child;\n                if(child) child->par = r;\n                return\
    \ update(r);\n            }\n        }\n\n        // \u5834\u6240 k \u3067 split\
    \  [0, k), [k, n)\n        pair<node_t<Type>*, node_t<Type>*> split(node_t<Type>*\
    \ t, int k) {\n            if(t == nullptr) return make_pair(nullptr, nullptr);\n\
    \n            if(k <= count(t->lch)) {\n                if(t->lch) t->lch->par\
    \ = nullptr;\n                pair<node_t<Type>*, node_t<Type>*> s = split(t->lch,\
    \ k);\n                t->lch = s.second;\n                if(s.second) s.second->par\
    \ = t;\n                return make_pair(s.first, update(t));\n            }\n\
    \            else {\n                if(t->rch) t->rch->par = nullptr;\n     \
    \           pair<node_t<Type>*, node_t<Type>*> s = split(t->rch, k - count(t->lch)\
    \ - 1);\n                t->rch = s.first;\n                if(s.first) s.first->par\
    \ = t;\n                return make_pair(update(t), s.second);\n            }\n\
    \        }\n\n        node_t<Type>* insert(node_t<Type>* t, int k, Type val, int\
    \ pri) {\n            pair<node_t<Type>*, node_t<Type>*> lr = split(t, k);\n \
    \           node_t<Type>* newElem = new node_t<Type>(val, pri);\n\n          \
    \  node_t<Type>* res = merge(lr.first, newElem);\n            res = merge(res,\
    \ lr.second);\n            return res;\n        }\n\n        node_t<Type>* erase(node_t<Type>*\
    \ t, int k) {\n            pair<node_t<Type>*, node_t<Type>*> lr2 = split(t, k+1);\n\
    \n            t = lr2.first;\n            pair<node_t<Type>*, node_t<Type>*> lr1\
    \ = split(t, k  );\n\n            node_t<Type>* res = merge(lr1.first, lr2.second);\n\
    \            return res;\n        }\n\n        // k \u756A\u76EE\u306E\u8981\u7D20\
    \ (0-indexed)\n        node_t<Type>* kth_node(node_t<Type>* t, int k) {\n    \
    \        assert(k < count(t));\n\n            if(count(t->lch) >= k + 1) {\n \
    \               return kth_node(t->lch, k);\n            }\n            else if(count(t->lch)\
    \ + 1 == k + 1) {\n                return t;\n            }\n            else\
    \ {\n                return kth_node(t->rch, k - count(t->lch) - 1);\n       \
    \     }\n        }\n\n        Type kth_number(node_t<Type>* t, int k) {\n    \
    \        assert(k < size());\n            return kth_node(t, k)->val;\n      \
    \  }\n\n        // lower bound (0-indexed)\n        int lower_bound(node_t<Type>*\
    \ t, Type val, int idx=0) {\n            if(t == nullptr) return idx;\n\n    \
    \        if(t->lch && t->lch->max_val >= val) {\n                return lower_bound(t->lch,\
    \ val, idx);\n            }\n            if(t->val >= val) {\n               \
    \ return idx + (count(t) - count(t->rch)) - 1;\n            }\n            if(t->rch\
    \ && t->rch->max_val >= val) {\n                return lower_bound(t->rch, val,\
    \ idx + count(t->lch) + 1);\n            }\n            return idx + count(t);\n\
    \        }\n\n        // upper bound (0-indexed)\n        int upper_bound(node_t<Type>*\
    \ t, Type val, int idx=0) {\n            if(t == nullptr) return idx;\n      \
    \      if(t->lch && t->lch->max_val > val) {\n                return upper_bound(t->lch,\
    \ val, idx);\n            }\n            if(t->val > val) {\n                return\
    \ idx + (count(t) - count(t->rch)) - 1;\n            }\n            if(t->rch\
    \ && t->rch->max_val > val) {\n                return lower_bound(t->rch, val,\
    \ idx + count(t->lch) + 1);\n            }\n            return idx + count(t);\n\
    \        }\n\n        int get_idx(node_t<Type>* t) {\n            if(t->par ==\
    \ nullptr) return count(t->lch);\n            else if(t->par->lch == t) {\n  \
    \              return get_idx(t->par) - count(t->rch) - 1;\n            }\n  \
    \          else {\n                return get_idx(t->par) + count(t->lch) + 1;\n\
    \            }\n        }\n\n        // rmq \u3092\u89E3\u304F (minmax: 0 \u3067\
    \u6700\u5927\u30011 \u3067\u6700\u5C0F)\n        Type rmq_query(int a, int b,\
    \ int l, int r, node_t<Type>* cur, int minmax) {\n            Type identity =\
    \ (minmax ? min_identity : max_identity);\n            if(r <= a || b <= l ||\
    \ !cur) return identity;\n            if(a <= l && r <= b) return (minmax ? cur->min_val\
    \ : cur->max_val);\n            // \u7B54\u3048 (\u73FE\u5728\u306E\u9802\u70B9\
    \u3092\u5165\u308C\u308B\u3053\u3068\u3082)\n            int idx = get_idx(cur),\
    \ nl, nr;\n            Type ans = (a <= idx && idx < b) ? cur->val : identity;\n\
    \n            auto get = [&](Type A, Type B) {\n                return minmax\
    \ ? min(A, B) : max(A, B);\n            };\n\n            // \u5DE6\u306E\u5B50\
    \u3078 (\u53F3\u7AEF\u304C\u7E2E\u3080)\n            if(cur->lch) {\n        \
    \        nl = l, nr = r - 1 - count(cur->rch);\n                ans = get(ans,\
    \ rmq_query(a, b, nl, nr, cur->lch, minmax));\n            }\n\n            //\
    \ \u53F3\u306E\u5B50\u3078 (\u5DE6\u7AEF\u304C\u7E2E\u3080)\n            if(cur->rch)\
    \ {\n                nl = l + 1 + count(cur->lch), nr = r;\n                ans\
    \ = get(ans, rmq_query(a, b, nl, nr, cur->rch, minmax));\n            }\n    \
    \        return ans;\n        }\n\n        treap()                  { size_ =\
    \ 0, root = nullptr; }\n        treap(node_t<Type>* r)   { eval(r); }\n      \
    \  node_t<Type>* get_root() { return root; }\n        size_t  size () { return\
    \ size_; }\n        bool    empty() { return size_ == 0; }\n\n        void insert(Type\
    \ val, int k) {\n            int pri = xor128();\n            eval( insert(root,\
    \ k, val, pri) );\n        }\n        void erase(int k) {\n            eval( erase(root,\
    \ k) );\n        }\n\n        pair< Treap, Treap > split(int k) {\n          \
    \  pair<node_t<Type>*, node_t<Type>*> lr = split(root, k);\n            return\
    \ make_pair(Treap(lr.first), Treap(lr.second));\n        }\n        Treap merge(Treap\
    \ l, Treap r) {\n            eval( merge(l.get_root(), r.get_root()) );\n    \
    \        return Treap(root);\n        }\n        node_t<Type>* kth_node(int k)\
    \ {\n            return kth_node(root, k);\n        }\n        Type kth_number(int\
    \ k) {\n            return kth_number(root, k);\n        }\n        int lower_bound(Type\
    \ val) {\n            return lower_bound(root, val);\n        }\n        int upper_bound(Type\
    \ val) {\n            return upper_bound(root, val);\n        }\n        void\
    \ update(Type val, int k) {\n            node_t<Type>* node = kth_node(k);\n \
    \           update(node, val);\n        }\n        bool find(Type val) {\n   \
    \         int idx = lower_bound(val);\n            if(idx >= size_) return false;\n\
    \            return kth_number(idx) == val;\n        }\n\n        Type find_min(int\
    \ l, int r) {\n            return rmq_query(l, r, 0, size(), root, 1);\n     \
    \   }\n        Type find_max(int l, int r) {\n            return rmq_query(l,\
    \ r, 0, size(), root, 0);\n        }\n\n        void dump_array() {\n        \
    \    for(int i=0; i<size(); i++) {\n                fprintf(stderr, \"%d \", kth_number(i));\n\
    \            }\n            fprintf(stderr, \"\\n\");\n        }\n\n        //\
    \ \u307F\u3055\u308F\u3055\u3093\u306E\u6839\u4ED8\u304D\u6728\u3068\u591A\u5206\
    \u540C\u3058\u30D5\u30A9\u30FC\u30DE\u30C3\u30C8\uFF1F\n        void dump_tree(node_t<Type>*\
    \ t) {\n            if(t == nullptr) return;\n            if(t->lch) {\n     \
    \           fprintf(stderr, \"(\");\n                dump_tree(t->lch);\n    \
    \            fprintf(stderr, \")\");\n            }\n            fprintf(stderr,\
    \ \"[%d\", t->val);\n            if(t->par) {\n                fprintf(stderr,\
    \ \"<%d>\", t->par->val);\n            }\n            else {\n               \
    \ fprintf(stderr, \"<NA>\");\n            }\n            fprintf(stderr, \"]\"\
    );\n            if(t->rch) {\n                fprintf(stderr, \"(\");\n      \
    \          dump_tree(t->rch);\n                fprintf(stderr, \")\");\n     \
    \       }\n        }\n    };\n\n    // \u91CD\u8907\u3092\u8A31\u3055\u306A\u3044\
    \u5168\u9806\u5E8F\u96C6\u5408\n    template <typename Type, Type max_identity,\
    \ Type min_identity>\n    struct Set : public treap<Type, max_identity, min_identity>\
    \ {\n    public:\n        using PTreap = treap<Type, max_identity, min_identity>;\n\
    \        bool empty() { return PTreap::size() == 0; }\n        void insert(Type\
    \ val) {\n            if(PTreap::find(val)) return;\n            int idx = PTreap::lower_bound(val);\n\
    \            PTreap::insert(val, idx);\n        }\n\n        void erase(Type val)\
    \ {\n            if(empty() || !PTreap::find(val)) return;\n            int idx\
    \ = PTreap::lower_bound(val);\n            PTreap::erase(idx);\n        }\n  \
    \  };\n\n    // TODO: multiset \u3082\u66F8\u304F\n}\n"
  code: "// Treap (\u5E73\u8861\u4E8C\u5206\u63A2\u7D22\u6728)\n// \u30C7\u30FC\u30BF\
    \u578B\u30FB\u6700\u5927\u5024\u7528\u306E\u5358\u4F4D\u5143\u3092\u6307\u5B9A\
    \u3057\u3066\u4F7F\u3046\n// TODO: \u4F7F\u3044\u65B9\u3092\u307E\u3068\u3081\u308B\
    \ (\u308F\u3059\u308C\u308B\u306E\u3067)\n\ninline int xor128() {\n    static\
    \ int x = 123456789;\n    static int y = 362436069;\n    static int z = 521288629;\n\
    \    static int w = 88675123;\n    int t;\n\n    t = x ^ (x << 11);\n    x = y;\n\
    \    y = z;\n    z = w;\n    return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));\n}\n\
    \nnamespace trp {\n    template <typename Type>\n    struct node_t {\n       \
    \ Type val, sum, max_val, min_val;\n        node_t<Type> *lch, *rch, *par;\n \
    \       int cap, pri;\n        node_t(int val_, int pri_) : \n            val(val_),\
    \ sum(val_), max_val(val_), min_val(val_), cap(1), pri(pri_) {\n             \
    \   lch = rch = par = nullptr;\n        }\n    };\n\n    // \u6271\u3046\u8981\
    \u7D20\u306E\u578B\u3068\u3001max, min \u306B\u7528\u3044\u308B\u5358\u4F4D\u5143\
    \n    // (\u3069\u308C\u3068 max, min \u3068\u3063\u3066\u3082\u5909\u308F\u3089\
    \u306A\u3044\u3084\u3064)\n    template <typename Type, Type max_identity, Type\
    \ min_identity>\n    struct treap {\n        using Treap = treap<Type, max_identity,\
    \ min_identity>;\n    private:\n        size_t size_;\n        node_t<Type>* root;\n\
    \n        // \u6839\u306E\u60C5\u5831\n        void eval(node_t<Type> *t) { root\
    \ = t, size_ = t ? count( update(t) ) : 0; }\n\n        // \u90E8\u5206\u6728\u306E\
    \u60C5\u5831\n        int  count  (node_t<Type>* t) { return t ? t->cap     :\
    \ 0; }\n        Type sum    (node_t<Type>* t) { return t ? t->sum     : 0; }\n\
    \        Type max_val(node_t<Type>* t) { return t ? t->max_val : max_identity;\
    \ }\n        Type min_val(node_t<Type>* t) { return t ? t->min_val : min_identity;\
    \ }\n\n        // \u90E8\u5206\u6728\u306B\u95A2\u3059\u308B\u60C5\u5831\u306E\
    \u518D\u8A08\u7B97\n        node_t<Type>* update(node_t<Type>* t, Type val=max_identity)\
    \ {\n            if(val != max_identity) t->val = val;\n            t->cap   \
    \  = count(t->lch) + count(t->rch) + 1;\n            t->sum     = sum  (t->lch)\
    \ + sum  (t->rch) + t->val;\n            t->max_val = max({max_val(t->lch), max_val(t->rch),\
    \ t->val});\n            t->min_val = min({min_val(t->lch), min_val(t->rch), t->val});\n\
    \            if(t->par) update(t->par);\n            return t;        \n     \
    \   }\n    public:\n        node_t<Type>* merge(node_t<Type>* l, node_t<Type>*\
    \ r) {\n            if(!l || !r) return !l ? r : l;\n\n            if(l->pri >\
    \ r->pri) {\n                if(l->rch) l->rch->par = nullptr;\n             \
    \   node_t<Type>* child = merge(l->rch, r);\n                l->rch = child;\n\
    \                if(child) child->par = l;\n                return update(l);\n\
    \            }\n            else {\n                if(r->lch) r->lch->par = nullptr;\n\
    \                node_t<Type>* child = merge(l, r->lch);\n                r->lch\
    \ = child;\n                if(child) child->par = r;\n                return\
    \ update(r);\n            }\n        }\n\n        // \u5834\u6240 k \u3067 split\
    \  [0, k), [k, n)\n        pair<node_t<Type>*, node_t<Type>*> split(node_t<Type>*\
    \ t, int k) {\n            if(t == nullptr) return make_pair(nullptr, nullptr);\n\
    \n            if(k <= count(t->lch)) {\n                if(t->lch) t->lch->par\
    \ = nullptr;\n                pair<node_t<Type>*, node_t<Type>*> s = split(t->lch,\
    \ k);\n                t->lch = s.second;\n                if(s.second) s.second->par\
    \ = t;\n                return make_pair(s.first, update(t));\n            }\n\
    \            else {\n                if(t->rch) t->rch->par = nullptr;\n     \
    \           pair<node_t<Type>*, node_t<Type>*> s = split(t->rch, k - count(t->lch)\
    \ - 1);\n                t->rch = s.first;\n                if(s.first) s.first->par\
    \ = t;\n                return make_pair(update(t), s.second);\n            }\n\
    \        }\n\n        node_t<Type>* insert(node_t<Type>* t, int k, Type val, int\
    \ pri) {\n            pair<node_t<Type>*, node_t<Type>*> lr = split(t, k);\n \
    \           node_t<Type>* newElem = new node_t<Type>(val, pri);\n\n          \
    \  node_t<Type>* res = merge(lr.first, newElem);\n            res = merge(res,\
    \ lr.second);\n            return res;\n        }\n\n        node_t<Type>* erase(node_t<Type>*\
    \ t, int k) {\n            pair<node_t<Type>*, node_t<Type>*> lr2 = split(t, k+1);\n\
    \n            t = lr2.first;\n            pair<node_t<Type>*, node_t<Type>*> lr1\
    \ = split(t, k  );\n\n            node_t<Type>* res = merge(lr1.first, lr2.second);\n\
    \            return res;\n        }\n\n        // k \u756A\u76EE\u306E\u8981\u7D20\
    \ (0-indexed)\n        node_t<Type>* kth_node(node_t<Type>* t, int k) {\n    \
    \        assert(k < count(t));\n\n            if(count(t->lch) >= k + 1) {\n \
    \               return kth_node(t->lch, k);\n            }\n            else if(count(t->lch)\
    \ + 1 == k + 1) {\n                return t;\n            }\n            else\
    \ {\n                return kth_node(t->rch, k - count(t->lch) - 1);\n       \
    \     }\n        }\n\n        Type kth_number(node_t<Type>* t, int k) {\n    \
    \        assert(k < size());\n            return kth_node(t, k)->val;\n      \
    \  }\n\n        // lower bound (0-indexed)\n        int lower_bound(node_t<Type>*\
    \ t, Type val, int idx=0) {\n            if(t == nullptr) return idx;\n\n    \
    \        if(t->lch && t->lch->max_val >= val) {\n                return lower_bound(t->lch,\
    \ val, idx);\n            }\n            if(t->val >= val) {\n               \
    \ return idx + (count(t) - count(t->rch)) - 1;\n            }\n            if(t->rch\
    \ && t->rch->max_val >= val) {\n                return lower_bound(t->rch, val,\
    \ idx + count(t->lch) + 1);\n            }\n            return idx + count(t);\n\
    \        }\n\n        // upper bound (0-indexed)\n        int upper_bound(node_t<Type>*\
    \ t, Type val, int idx=0) {\n            if(t == nullptr) return idx;\n      \
    \      if(t->lch && t->lch->max_val > val) {\n                return upper_bound(t->lch,\
    \ val, idx);\n            }\n            if(t->val > val) {\n                return\
    \ idx + (count(t) - count(t->rch)) - 1;\n            }\n            if(t->rch\
    \ && t->rch->max_val > val) {\n                return lower_bound(t->rch, val,\
    \ idx + count(t->lch) + 1);\n            }\n            return idx + count(t);\n\
    \        }\n\n        int get_idx(node_t<Type>* t) {\n            if(t->par ==\
    \ nullptr) return count(t->lch);\n            else if(t->par->lch == t) {\n  \
    \              return get_idx(t->par) - count(t->rch) - 1;\n            }\n  \
    \          else {\n                return get_idx(t->par) + count(t->lch) + 1;\n\
    \            }\n        }\n\n        // rmq \u3092\u89E3\u304F (minmax: 0 \u3067\
    \u6700\u5927\u30011 \u3067\u6700\u5C0F)\n        Type rmq_query(int a, int b,\
    \ int l, int r, node_t<Type>* cur, int minmax) {\n            Type identity =\
    \ (minmax ? min_identity : max_identity);\n            if(r <= a || b <= l ||\
    \ !cur) return identity;\n            if(a <= l && r <= b) return (minmax ? cur->min_val\
    \ : cur->max_val);\n            // \u7B54\u3048 (\u73FE\u5728\u306E\u9802\u70B9\
    \u3092\u5165\u308C\u308B\u3053\u3068\u3082)\n            int idx = get_idx(cur),\
    \ nl, nr;\n            Type ans = (a <= idx && idx < b) ? cur->val : identity;\n\
    \n            auto get = [&](Type A, Type B) {\n                return minmax\
    \ ? min(A, B) : max(A, B);\n            };\n\n            // \u5DE6\u306E\u5B50\
    \u3078 (\u53F3\u7AEF\u304C\u7E2E\u3080)\n            if(cur->lch) {\n        \
    \        nl = l, nr = r - 1 - count(cur->rch);\n                ans = get(ans,\
    \ rmq_query(a, b, nl, nr, cur->lch, minmax));\n            }\n\n            //\
    \ \u53F3\u306E\u5B50\u3078 (\u5DE6\u7AEF\u304C\u7E2E\u3080)\n            if(cur->rch)\
    \ {\n                nl = l + 1 + count(cur->lch), nr = r;\n                ans\
    \ = get(ans, rmq_query(a, b, nl, nr, cur->rch, minmax));\n            }\n    \
    \        return ans;\n        }\n\n        treap()                  { size_ =\
    \ 0, root = nullptr; }\n        treap(node_t<Type>* r)   { eval(r); }\n      \
    \  node_t<Type>* get_root() { return root; }\n        size_t  size () { return\
    \ size_; }\n        bool    empty() { return size_ == 0; }\n\n        void insert(Type\
    \ val, int k) {\n            int pri = xor128();\n            eval( insert(root,\
    \ k, val, pri) );\n        }\n        void erase(int k) {\n            eval( erase(root,\
    \ k) );\n        }\n\n        pair< Treap, Treap > split(int k) {\n          \
    \  pair<node_t<Type>*, node_t<Type>*> lr = split(root, k);\n            return\
    \ make_pair(Treap(lr.first), Treap(lr.second));\n        }\n        Treap merge(Treap\
    \ l, Treap r) {\n            eval( merge(l.get_root(), r.get_root()) );\n    \
    \        return Treap(root);\n        }\n        node_t<Type>* kth_node(int k)\
    \ {\n            return kth_node(root, k);\n        }\n        Type kth_number(int\
    \ k) {\n            return kth_number(root, k);\n        }\n        int lower_bound(Type\
    \ val) {\n            return lower_bound(root, val);\n        }\n        int upper_bound(Type\
    \ val) {\n            return upper_bound(root, val);\n        }\n        void\
    \ update(Type val, int k) {\n            node_t<Type>* node = kth_node(k);\n \
    \           update(node, val);\n        }\n        bool find(Type val) {\n   \
    \         int idx = lower_bound(val);\n            if(idx >= size_) return false;\n\
    \            return kth_number(idx) == val;\n        }\n\n        Type find_min(int\
    \ l, int r) {\n            return rmq_query(l, r, 0, size(), root, 1);\n     \
    \   }\n        Type find_max(int l, int r) {\n            return rmq_query(l,\
    \ r, 0, size(), root, 0);\n        }\n\n        void dump_array() {\n        \
    \    for(int i=0; i<size(); i++) {\n                fprintf(stderr, \"%d \", kth_number(i));\n\
    \            }\n            fprintf(stderr, \"\\n\");\n        }\n\n        //\
    \ \u307F\u3055\u308F\u3055\u3093\u306E\u6839\u4ED8\u304D\u6728\u3068\u591A\u5206\
    \u540C\u3058\u30D5\u30A9\u30FC\u30DE\u30C3\u30C8\uFF1F\n        void dump_tree(node_t<Type>*\
    \ t) {\n            if(t == nullptr) return;\n            if(t->lch) {\n     \
    \           fprintf(stderr, \"(\");\n                dump_tree(t->lch);\n    \
    \            fprintf(stderr, \")\");\n            }\n            fprintf(stderr,\
    \ \"[%d\", t->val);\n            if(t->par) {\n                fprintf(stderr,\
    \ \"<%d>\", t->par->val);\n            }\n            else {\n               \
    \ fprintf(stderr, \"<NA>\");\n            }\n            fprintf(stderr, \"]\"\
    );\n            if(t->rch) {\n                fprintf(stderr, \"(\");\n      \
    \          dump_tree(t->rch);\n                fprintf(stderr, \")\");\n     \
    \       }\n        }\n    };\n\n    // \u91CD\u8907\u3092\u8A31\u3055\u306A\u3044\
    \u5168\u9806\u5E8F\u96C6\u5408\n    template <typename Type, Type max_identity,\
    \ Type min_identity>\n    struct Set : public treap<Type, max_identity, min_identity>\
    \ {\n    public:\n        using PTreap = treap<Type, max_identity, min_identity>;\n\
    \        bool empty() { return PTreap::size() == 0; }\n        void insert(Type\
    \ val) {\n            if(PTreap::find(val)) return;\n            int idx = PTreap::lower_bound(val);\n\
    \            PTreap::insert(val, idx);\n        }\n\n        void erase(Type val)\
    \ {\n            if(empty() || !PTreap::find(val)) return;\n            int idx\
    \ = PTreap::lower_bound(val);\n            PTreap::erase(idx);\n        }\n  \
    \  };\n\n    // TODO: multiset \u3082\u66F8\u304F\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: structure/strc_013_treap.cpp
  requiredBy: []
  timestamp: '2019-11-22 21:50:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: structure/strc_013_treap.cpp
layout: document
redirect_from:
- /library/structure/strc_013_treap.cpp
- /library/structure/strc_013_treap.cpp.html
title: structure/strc_013_treap.cpp
---
