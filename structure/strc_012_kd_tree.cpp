// 領域探索 (kD 木・2 次元バージョン)
// Verified: AOJ DSL_2_C: Range Search (kD Tree)
struct Node {
    int loc, l, r;
};

struct Point {
    int id, x, y;
};

Node T[500010];
Point P[500010];
int np = 0, NIL = -1;

// [l, r) の範囲にある点について構築。その範囲における根を返す
int make(int l, int r, int depth=0) {
    if(l >= r) return NIL;
    int mid = (l + r) / 2, t = np++;
    if(depth % 2 == 0) {
        sort(P+l, P+r, [](const Point &a, const Point &b){return a.x < b.x;});
    }
    else {
        sort(P+l, P+r, [](const Point &a, const Point &b){return a.y < b.y;});
    }
    T[t].loc = mid;
    T[t].l = make(l, mid,   depth+1);
    T[t].r = make(mid+1, r, depth+1);
    return t;
}

// 左上 (sx, ty)、右下 (tx, sy) の長方形領域にある点を列挙
// v は kD-tree におけるインデックス
// find(root, sx, tx, sy, ty, ans) のように使おう
void find(int v, int sx, int tx, int sy, int ty, vector<int> &ans, int depth=0) {
    int x = P[T[v].loc].x, y = P[T[v].loc].y;
    if(sx <= x && x <= tx && sy <= y && y <= ty) {
        // ans.push_back(Point{x, y});
        ans.push_back(P[T[v].loc].id);
    }

    if(depth % 2 == 0) {
        if(T[v].l != NIL && sx <= x) find(T[v].l, sx, tx, sy, ty, ans, depth+1);
        if(T[v].r != NIL && x <= tx) find(T[v].r, sx, tx, sy, ty, ans, depth+1);
    }
    else {
        if(T[v].l != NIL && sy <= y) find(T[v].l, sx, tx, sy, ty, ans, depth+1);
        if(T[v].r != NIL && y <= ty) find(T[v].r, sx, tx, sy, ty, ans, depth+1);
    }
}

// kD-tree end
