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


# :warning: structure/strc_018_binarytrie.cpp
* category: structure


[Back to top page](../../index.html)



## Code
```cpp
// Binary Trie
// ・色々 verify たりない。特に遅延評価はまだ何も verify してない！要注意！！

// Verify 済み
// ・insert, erase
// ・min_element
// ・count_less
// ・get_kth

// 通した問題一覧
// ・ARC033-C データ構造 (insert, erase, get_kth)
// ・Codeforces Round #470 C Perfect Security (insert, erase, min_element)
// ・SPOJ SubXor (insert, erase, count_less)

template <typename Type = unsigned int, int B = 32>
struct BinaryTrie {
private:
    struct Node {
        int cnt;
        Type lazy;
        Node* child[2];
        Node() : cnt(0), lazy(0), child{ nullptr, nullptr } {}
    };

    int get_size(Node *t) const { return t ? t->cnt : 0; }
    void lazy_eval(Node* t, int b) const {
        if((t->lazy >> (Type)b) & (Type)1) swap(t->child[0], t->child[1]);
        if(t->child[0]) t->child[0]->lazy ^= t->lazy;
        if(t->child[1]) t->child[1]->lazy ^= t->lazy;
        t->lazy = 0;
    }

    Node* add(Node* t, Type val, int b = B - 1) {
        if(!t) t = new Node;
        t->cnt++;
        if(b < 0) return t;
        lazy_eval(t, b);
        int bin = (val >> (Type)b) & (Type)1;
        t->child[bin] = add(t->child[bin], val, b-1);
        return t;
    }

    Node* sub(Node* t, Type val, int b = B - 1) {
        assert(t);
        t->cnt--;
        if(t->cnt == 0) return nullptr;
        if(b < 0) return t;
        lazy_eval(t, b);
        int bin = (val >> (Type)b) & (Type)1;
        t->child[bin] = sub(t->child[bin], val, b-1);
        return t;
    }

    // 全体を val で XOR 取った時の最小値
    Type get_min(Node* t, Type val, int b = B - 1) const {
        assert(t);
        if(b < 0) return 0;
        lazy_eval(t, b);
        int bin = (val >> (Type)b) & (Type)1; bin ^= !t->child[bin];
        return get_min(t->child[bin], val, b-1) | ((Type)bin << (Type)b);
    }

    // 全体を val で XOR 取ったときに k 番目 (1-indexed) に小さい値
    Type get_kth(Node* t, Type val, int k, int b = B - 1) const {
        assert(t);
        if(b < 0) return 0;
        lazy_eval(t, b);
        int bin = (val >> (Type)b) & (Type)1;
        if(get_size(t->child[bin]) < k) k -= get_size(t->child[bin]), bin ^= 1;

        // fprintf(stderr, "bin = %d\n", bin);
        return get_kth(t->child[bin], val, k, b-1) | ((Type)bin << (Type)b);
    }

    // 集合内にある val 以上の要素の中で最小のものの id (1-indexed? (TODO: verify))
    int get_lower(Node* t, Type val, int b = B - 1) {
        if(!t || b < 0) return 0;
        lazy_eval(t, b);
        bool bin = (val >> (Type)b) & (Type)1;
        return (bin && t->child[0] ? t->child[0]->cnt : 0) + get_lower(t->child[bin], val, b-1);
    }

    // 全体を val で XOR 取ったときに x 未満になる要素の数
    int count_less(Node* t, Type val, Type x, int b = B - 1) {
        if(!t || b < 0) return 0;
        lazy_eval(t, b);
        bool bin = (val >> (Type)b) & (Type)1;
        int add = 0;
        if(x >> (Type)b & 1) add += get_size(t->child[bin]), bin ^= 1;
        return add + count_less(t->child[bin], val, x, b-1);
    }

    Node* root;

public:
    BinaryTrie() : root(nullptr) {}
    int size() const {
        return get_size(root);
    }
    bool empty() const {
        return !root;
    }
    void insert(Type val) {
        root = add(root, val);
    }
    void erase(Type val) {
        root = sub(root, val);
    }

    // XOR とった後の値ではなく、集合内にある値がそのまま返る
    Type max_element(Type XOR = 0) const {
        return get_min(root, ~XOR);
    }
    Type min_element(Type XOR = 0) const {
        return get_min(root,  XOR);
    }

    // 要素全体を XOR
    void xor_all(Type val) {
        if(root) root->lazy ^= val;
    }

    // 要素のインデックスが返ってくることに注意
    int lower_bound(Type val) {
        return get_lower(root, val);
    }
    int upper_bound(Type val) {
        return get_lower(root, val + 1);
    }

    // 全体に XOR したときの val 未満の値の数
    int count_less(Type val, Type XOR = 0) {
        return count_less(root, XOR, val);
    }

    // 全体に XOR したときの val を超える値の数
    int count_upper(Type val, Type XOR = 0) {
        return size() - count_less(root, XOR, val + 1);
    }

    // 0-indexed
    Type get_kth(int k, Type XOR = 0) const {
        assert(0 <= k and k < size());
        return get_kth(root, XOR, k+1);
    }

    // 0-indexed
    Type operator[](int k) {
        return get_kth(k);
    }
};

```

[Back to top page](../../index.html)

