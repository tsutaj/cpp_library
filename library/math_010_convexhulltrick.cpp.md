<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# math\_010\_convexhulltrick.cpp
---

## Code

```cpp
// Convex Hull Trick (Verified: COLOCON 2018 Final C)
// ・直線集合に直線を追加する
// ・直線集合に含まれている関数の中で、 f(x) の最大値を求める

// 直線を表現する型と、取得クエリの単位元 (最大値を返すので、大きい負の値とか)
template<typename Type, const Type id>
struct ConvexHullTrick {
private:
    using Response = pair<Type, int>;
    struct Line {
        Type a, b;
        Line (Type a_ = 0, Type b_ = 0) : a(a_), b(b_) {}
        Type get(Type x) { return a*x + b; }
    };

    struct Node {
        Line line;
        Node *lhs, *rhs;
        int index;
        Node(Line line_, int index_=-1) : line(line_), lhs(nullptr), rhs(nullptr), index(index_) {}
        ~Node() {
            if(lhs) delete lhs;
            if(rhs) delete rhs;
        }
    };

    int N;
    vector<Type> pos;
    Node *root;

public:
    // x の取りうる値を sort かつ unique にしたもの
    ConvexHullTrick(const vector<Type> &pos_) : N(pos_.size()), pos(pos_), root(nullptr) {}
    ~ConvexHullTrick() {
        if(root) delete root;
    }

    // 直線 f(x) = a*x + b を追加する (オプション: インデックスの情報も保持したいならする)
    void insert(Type a, Type b, int idx=-1) {
        Line line(a, b);
        root = update(root, 0, N, line, idx);
    }

    // 直線集合 F において、f(x) の最大値を返す
    Type get_value(Type x) const {
        int t = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
        assert(t < N && pos[t] == x);
        return query(root, 0, N, t).first;
    }

    // 直線集合 F において、f(x) の最大値を実現する直線のインデックスを返す
    // (複数ある場合はインデックスが最も小さいものを返す)
    int get_index(Type x) const {
        int t = lower_bound(pos.begin(), pos.end(), x) - pos.begin();
        assert(t < N && pos[t] == x);
        return query(root, 0, N, t).second;
    }

private:
    // クエリで処理する区間は閉区間なので注意！！！
    Node* update(Node* p, int lb, int ub, Line& l, int idx=-1) {
        if(!p) return new Node(l, idx);
        if(p -> line.get(pos[lb    ]) >= l.get(pos[lb    ]) &&
           p -> line.get(pos[ub - 1]) >= l.get(pos[ub - 1])) {
            return p;
        }

        if(p -> line.get(pos[lb    ]) <= l.get(pos[lb    ]) &&
           p -> line.get(pos[ub - 1]) <= l.get(pos[ub - 1])) {
            p -> line = l;
            p -> index = idx;
            return p;
        }

        int mid = (ub + lb) / 2;
        if(p -> line.get(pos[mid]) < l.get(pos[mid])) {
            swap(p -> line, l);
            swap(p -> index, idx);
        }
        if(p -> line.get(pos[lb]) <= l.get(pos[lb])) {
            p -> lhs = update(p -> lhs, lb, mid, l, idx);
        }
        else {
            p -> rhs = update(p -> rhs, mid, ub, l, idx);
        }
        return p;
    }

    Response comp(Response lhs, Response rhs) const {
        if(lhs.first != rhs.first) {
            return lhs.first > rhs.first ? lhs : rhs;
        }
        else {
            return lhs.second < rhs.second ? lhs : rhs;
        }
    }

    Response query(Node *p, int lb, int ub, int t) const {
        if(!p) return make_pair(id, -1);
        if(ub - lb == 1) return make_pair(p -> line.get(pos[t]), p -> index);

        int mid = (ub + lb) / 2;
        Response cur = make_pair(p -> line.get(pos[t]), p -> index);
        if(t < mid) {
            return comp(cur, query(p -> lhs, lb, mid, t));
        }
        else {
            return comp(cur, query(p -> rhs, mid, ub, t));
        }
    }
};

// 使用例
int main() {
    ll N; scanf("%lld", &N);
    vector<ll> points(N);
    iota(points.begin(), points.end(), 1);

    vector<ll> X(N+1), Y(N+1);

    ConvexHullTrick<ll, LLONG_MIN> cht(points);
    for(ll j=1; j<=N; j++) {
        ll A; scanf("%lld", &A);
        ll x = 2*j, y = -(A + j*j);
        X[j] = -2*j;
        Y[j] = A + j*j;
        cht.insert(x, y, j);
    }

    for(auto p : points) {
        int idx = cht.get_index(p);
        printf("%lld\n", X[idx]*p + Y[idx] + p*p);
    }
    return 0;
}
```

[トップページに戻る](../index.html)
