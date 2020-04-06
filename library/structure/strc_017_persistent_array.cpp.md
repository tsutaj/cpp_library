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


# :warning: structure/strc_017_persistent_array.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#07414f4e15ca943e6cde032dec85d92f">structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/structure/strc_017_persistent_array.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// 永続配列 (2^{LOG} 分木による実装)
// パスコピーは mutable_get で行おう！値を持ってくるだけなら get を使おう

template <typename Type, int LOG>
struct PersistentArray {
    struct Node {
        Type data;
        Node* child[1 << LOG] = {};
        Node() {}
        Node(const Type& data_) : data(data_) {}
    };
    Node* root;

    PersistentArray() : root(nullptr) {}
    Type get(Node* t, int k) {
        if(k == 0) return t->data;
        return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
    }

    Type get(const int& k) {
        return get(root, k);
    }

    pair<Node*, Type*> mutable_get(Node* t, int k) {
        t = t ? new Node(*t) : new Node();
        if(k == 0) return {t, &t->data};
        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p.first;
        return {t, p.second};
    }

    Type* mutable_get(const int& k) {
        auto ret = mutable_get(root, k);
        root = ret.first;
        return ret.second;
    }

    Node* build(Node* t, const Type& data, int k) {
        if(!t) t = new Node();
        if(k == 0) {
            t->data = data;
            return t;
        }
        auto p = build(t->child[k & ((1 << LOG) - 1)], data, k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p;
        return t;
    }

    void build(const vector<Type>& vec) {
        root = nullptr;
        for(size_t i=0; i<vec.size(); i++) {
            root = build(root, vec[i], i);
        }
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "structure/strc_017_persistent_array.cpp"
// 永続配列 (2^{LOG} 分木による実装)
// パスコピーは mutable_get で行おう！値を持ってくるだけなら get を使おう

template <typename Type, int LOG>
struct PersistentArray {
    struct Node {
        Type data;
        Node* child[1 << LOG] = {};
        Node() {}
        Node(const Type& data_) : data(data_) {}
    };
    Node* root;

    PersistentArray() : root(nullptr) {}
    Type get(Node* t, int k) {
        if(k == 0) return t->data;
        return get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
    }

    Type get(const int& k) {
        return get(root, k);
    }

    pair<Node*, Type*> mutable_get(Node* t, int k) {
        t = t ? new Node(*t) : new Node();
        if(k == 0) return {t, &t->data};
        auto p = mutable_get(t->child[k & ((1 << LOG) - 1)], k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p.first;
        return {t, p.second};
    }

    Type* mutable_get(const int& k) {
        auto ret = mutable_get(root, k);
        root = ret.first;
        return ret.second;
    }

    Node* build(Node* t, const Type& data, int k) {
        if(!t) t = new Node();
        if(k == 0) {
            t->data = data;
            return t;
        }
        auto p = build(t->child[k & ((1 << LOG) - 1)], data, k >> LOG);
        t->child[k & ((1 << LOG) - 1)] = p;
        return t;
    }

    void build(const vector<Type>& vec) {
        root = nullptr;
        for(size_t i=0; i<vec.size(); i++) {
            root = build(root, vec[i], i);
        }
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

