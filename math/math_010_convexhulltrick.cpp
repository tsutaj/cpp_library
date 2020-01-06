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

    void node_update(Line line) {
        int l = 0, r = N, k = 0;
        while(true) {
            if(node[k].empty()) {
                node[k] = line;
                break;
            }

            if(comp(line.f(X_pos[l]), node[k].f(X_pos[l])) and
               comp(line.f(X_pos[r-1]), node[k].f(X_pos[r-1]))) break;

            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l])) and
               comp(node[k].f(X_pos[r-1]), line.f(X_pos[r-1]))) {
                node[k] = line;
                break;
            }

            if(r - l == 1) break;            
            int mid = (l + r) / 2;
            if(comp(node[k].f(X_pos[mid]), line.f(X_pos[mid]))) {
                swap(line, node[k]);
            }

            if(comp(node[k].f(X_pos[l]), line.f(X_pos[l]))) {
                r = mid, k = 2*k + 1;
            }
            else {
                l = mid, k = 2*k + 2;
            }
        }
    }

    pair<Y_Tp, int> search_line(int t) const {
        pair<Y_Tp, int> result(E, -1);
        int l = 0, r = N, k = 0;
        while(true) {
            if(node[k].empty()) break;
            pair<Y_Tp, int> cand(node[k].f(X_pos[t]), node[k].index);
            if(comp(result.first, cand.first)) result = cand;

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
        node_update(line);
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
