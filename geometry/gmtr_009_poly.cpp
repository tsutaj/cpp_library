// (基本) 頂点の順序 (sortやmax_elementに必要)
namespace std {
    bool operator<(const P a, const P b) {
        return a.X != b.X ? a.X < b.X : a.Y < b.Y;
    }
}

// 凸包
// Verified: AOJ CGL_4_A: Convex Hull
// y座標優先でソート(必要があれば)
bool cmp_y(const P &a, const P& b) {
    return a.Y != b.Y ? a.Y < b.Y : a.X < b.X;
}

vector<P> convexHull(vector<P> ps) {
    int n = ps.size();
    // sort(ps.begin(),ps.end(), cmp_y);
    sort(ps.begin(),ps.end());
    int k = 0;
    vector<P> convex(n*2);
    for(int i=0; i<n; i++) {
        while (k >= 2 && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;
        convex[ k++ ] = ps[i];
    }
    for(int i=n-2, t=k; i>=0; i--) {
        while (k > t && ccw(convex[k-2], convex[k-1], ps[i]) == -1 ) k--;
        convex[ k++ ] = ps[i];
    }
    convex.resize(k-1);
    return convex;
}

/* これはバグるので使用禁止。後で直したい
vector<P> convexHull(vector<P> ps) { // 元の点集合がソートされていいなら vector<P> & に
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<P> ch(2 * n);
    for(int i=0; i<n; ch[k++] = ps[i++]) // lower-hull
        while(k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k; // 余計な点も含むなら-1とする
    for(int i=n-2, t=k+1; i>=0; ch[k++] = ps[i--]) //upper-hull
        while(k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
    ch.resize(k-1);
    return ch;
}
*/

// 凸判定。縮退を認めないなら ccw の判定部分を != 1 とする
// Verified: CGL_3_B: Is-Convex
bool isCcwConvex(const vector<P> &ps) {
    int n = ps.size();
    rep(i,0,n) if(ccw(ps[i], ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;
    return true;
}

// 凸多角形の内部判定 O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(P p, const vector<P> &ps) {
    int n = ps.size();
    int dir = ccw(ps[0], ps[1], p);
    rep(i,0,n) {
        int ccwc = ccw(ps[i], ps[(i+1) % n], p);
        if(!ccwc) return 2;
        if(ccwc != dir) return 0;
    }
    return 1;
}

// 凸多角形の内部判定 O(log n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inCcwConvex(P p, const vector<P> &ps) {
    int n = ps.size();
    P g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;
    if(g == p) return 1;
    P gp = p - g;

    int l = 0, r = n;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        P gl = ps[l] - g;
        P gm = ps[mid] - g;
        if(cross(gl,gm) > 0) {
            if(cross(gl,gp) >= 0 && cross(gm,gp) <= 0) r = mid;
            else l = mid;
        }
        else {
            if(cross(gl,gp) <= 0 && cross(gm,gp) >= 0) l = mid;
            else r = mid;
        }
    }
    r %= n;
    double cr = cross(ps[l] - p, ps[r] - p);
    return EQ(cr, 0) ? 2 : cr < 0 ? 0 : 1;
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
// Verified: AOJ CGL_3_C: Polygon-Point Containment
int inPolygon(P p, const vector<P> &ps) {
    int n = ps.size();
    bool in = false;
    rep(i,0,n) {
        P a = ps[i] - p;
        P b = ps[(i+1) % n] - p;
        if(EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
        if(a.Y > b.Y) swap(a,b);
        if((a.Y * b.Y < 0 || (a.Y * b.Y < EPS && b.Y > EPS)) && LE(cross(a,b), 0)) in = !in;
    }
    return in;
}

// 凸多角形クリッピング
// Verified: AOJ CGL_4_C: Convex Cut
vector<P> convexCut(P a1, P a2, const vector<P> &ps) {
    int n = ps.size();
    vector<P> ret;
    rep(i,0,n) {
        int ccwc = ccw(a1, a2, ps[i]);
        if(ccwc != -1) ret.push_back(ps[i]);
        int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
        if(ccwc * ccwn == -1) ret.push_back(crossp_ll(a1, a2, ps[i], ps[(i + 1) % n]));
    }
    return ret;
}

// 凸多角形の直径 (最遠点対)
// Verified: AOJ CGL_4_B: Diameter of a Convex Polygon
pair<int, int> convexDiameter(const vector<P> &ps) {
    int n = ps.size();
    int i = min_element(ps.begin(), ps.end()) - ps.begin();
    int j = max_element(ps.begin(), ps.end()) - ps.begin();
    int maxI, maxJ;
    double maxD = 0;
    rep(_, 0, 2*n) {
        if(maxD < norm(ps[i] - ps[j])) {
            maxD = norm(ps[i] - ps[j]);
            maxI = i;
            maxJ = j;
        }
        if(cross(ps[i] - ps[(i+1) % n], ps[(j+1) % n] - ps[j]) <= 0) j = (j+1) % n;
        else i = (i+1) % n;
    }
    return make_pair(maxI, maxJ);
}

// 多角形の符号付面積
// Verified: AOJ CGL_3_A: Area
double area(const vector<P> &ps) {
    double a = 0;
    rep(i,0,ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a / 2;
}

// 多角形の符号なし面積
double area_n(const vector<P> &v) {
    double ans = 0;
    double x, y, z;
    P init = v[0];
    rep(i,2,v.size()) {
        x = sqrt(norm(v[i] - init));
        y = sqrt(norm(v[i-1] - init));
        z = sqrt(norm(v[i] - v[i-1]));

        double s = (x + y + z) / 2;
        ans += sqrt(s * (s-x) * (s-y) * (s-z));
    }
    return ans;
}

// 多角形の幾何学的重心
P centroid(const vector<P> &ps) {
    int n = ps.size();
    double aSum = 0;
    P c;
    rep(i,0,n) {
        double a = cross(ps[i], ps[(i+1) % n]);
        aSum += a;
        c += (ps[i] + ps[(i+1) % n]) * a;
    }
    return 1 / aSum / 3 * c;
}

// ボロノイ領域
vector<P> voronoiCell(P p, const vector<P> &ps, const vector<P> &outer) {
    vector<P> cl = outer;
    rep(i,0,ps.size()) {
        if(EQ(norm(ps[i] - p), 0)) continue;
        P h = (p + ps[i]) * 0.5;
        cl = convexCut(cl, h, h + (ps[i] - h) * P(0,1));
    }
    return cl;
}