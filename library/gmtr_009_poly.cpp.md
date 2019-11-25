<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<link rel="stylesheet" href="../css/copy-button.css" />
<script src="../js/balloons.js"></script>
<script src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: gmtr\_009\_poly.cpp

## Code

```cpp
// (基本) 頂点の順序 (sortやmax_elementに必要)
namespace std {
    bool operator<(const Point a, const Point b) {
        return a.real() != b.real() ? a.real() < b.real() : a.imag() < b.imag();
    }
}

// 凸包
// Verified: AOJ CGL_4_A: Convex Hull
// y座標優先でソート(必要があれば)
bool cmp_y(const Point &a, const Point& b) {
    return a.imag() != b.imag() ? a.imag() < b.imag() : a.real() < b.real();
}

vector<Point> convexHull(vector<Point> ps) {
    int n = ps.size();
    // sort(ps.begin(),ps.end(), cmp_y);
    sort(ps.begin(),ps.end());
    int k = 0;
    vector<Point> convex(n*2);
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
vector<Point> convexHull(vector<Point> ps) { // 元の点集合がソートされていいなら vector<Point> & に
    int n = ps.size(), k = 0;
    sort(ps.begin(), ps.end());
    vector<Point> ch(2 * n);
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
bool isCcwConvex(const vector<Point> &ps) {
    int n = ps.size();
    for(int i=0; i<n; i++) if(ccw(ps[i], ps[(i+1) % n], ps[(i+2) % n]) == -1) return false;
    return true;
}

// 凸多角形の内部判定 O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const vector<Point> &ps) {
    int n = ps.size();
    int dir = ccw(ps[0], ps[1], p);
    for(int i=0; i<n; i++) {
        int ccwc = ccw(ps[i], ps[(i+1) % n], p);
        if(!ccwc) return 2;
        if(ccwc != dir) return 0;
    }
    return 1;
}

// 凸多角形の内部判定 O(log n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inCcwConvex(Point p, const vector<Point> &ps) {
    int n = ps.size();
    Point g = (ps[0] + ps[n / 3] + ps[n*2 / 3]) / 3.0;
    if(g == p) return 1;
    Point gp = p - g;

    int l = 0, r = n;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        Point gl = ps[l] - g;
        Point gm = ps[mid] - g;
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
int inPolygon(Point p, const vector<Point> &ps) {
    int n = ps.size();
    bool in = false;
    for(int i=0; i<n; i++) {
        Point a = ps[i] - p;
        Point b = ps[(i+1) % n] - p;
        if(EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
        if(a.imag() > b.imag()) swap(a,b);
        if((a.imag() * b.imag() < 0 || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0)) in = !in;
    }
    return in;
}

// 凸多角形クリッピング
// Verified: AOJ CGL_4_C: Convex Cut
vector<Point> convexCut(Point a1, Point a2, const vector<Point> &ps) {
    int n = ps.size();
    vector<Point> ret;
    for(int i=0; i<n; i++) {
        int ccwc = ccw(a1, a2, ps[i]);
        if(ccwc != -1) ret.push_back(ps[i]);
        int ccwn = ccw(a1, a2, ps[(i + 1) % n]);
        if(ccwc * ccwn == -1) ret.push_back(crossp_ll(a1, a2, ps[i], ps[(i + 1) % n]));
    }
    return ret;
}

// 凸多角形の直径 (最遠点対)
// Verified: AOJ CGL_4_B: Diameter of a Convex Polygon
pair<int, int> convexDiameter(const vector<Point> &ps) {
    int n = ps.size();
    int i = min_element(ps.begin(), ps.end()) - ps.begin();
    int j = max_element(ps.begin(), ps.end()) - ps.begin();
    int maxI, maxJ;
    double maxD = 0;
    for(int _=0; _<2*n; _++) {
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
double area(const vector<Point> &ps) {
    double a = 0;
    for(size_t i=0; i<ps.size(); i++) a += cross(ps[i], ps[(i+1) % ps.size()]);
    return a / 2;
}

// 多角形の符号なし面積
double area_n(const vector<Point> &v) {
    double ans = 0;
    double x, y, z;
    Point init = v[0];
    for(size_t i=2; i<v.size(); i++) {
        x = sqrt(norm(v[i] - init));
        y = sqrt(norm(v[i-1] - init));
        z = sqrt(norm(v[i] - v[i-1]));

        double s = (x + y + z) / 2;
        ans += sqrt(s * (s-x) * (s-y) * (s-z));
    }
    return ans;
}

// 多角形の幾何学的重心
Point centroid(const vector<Point> &ps) {
    int n = ps.size();
    double aSum = 0;
    Point c;
    for(int i=0; i<n; i++) {
        double a = cross(ps[i], ps[(i+1) % n]);
        aSum += a;
        c += (ps[i] + ps[(i+1) % n]) * a;
    }
    return 1 / aSum / 3 * c;
}

// ボロノイ領域
vector<Point> voronoiCell(Point p, const vector<Point> &ps, const vector<Point> &outer) {
    vector<Point> cl = outer;
    for(size_t i=0; i<ps.size(); i++) {
        if(EQ(norm(ps[i] - p), 0)) continue;
        Point h = (p + ps[i]) * 0.5;
        cl = convexCut(cl, h, h + (ps[i] - h) * Point(0,1));
    }
    return cl;
}

```

[トップページに戻る](../index.html)
