[トップページに戻る](../index.html)

# geometry\_2D.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

```cpp
/***** 基本的準備 *****/

// xy平面上の点(ベクトル)を表現するには、complex型を利用するとよい
typedef complex<double> Point;

// 辺の表現 (座標を2つ pair でもつ)
typedef pair<Point, Point> Line;

// 円の表現 (座標 P と 半径 d で表現する)
typedef pair<Point, double> Circle;

// 誤差(epsilon)の定義
const double EPS = 1e-10;

// 2つの要素が等しいかどうか
template <typename float_type>
bool EQ(float_type a, float_type b) { return abs(a - b) < EPS; }

// 2つのベクトルが等しいかどうか
template <typename complex_type>
bool EQV(complex_type a, complex_type b) { return EQ(a.real(), b.real()) && EQ(a.imag(), b.imag()); }

// m は n より大きい(以上)かどうか
template <typename float_type>
bool LE(float_type n, float_type m) { return n < m + EPS; }
template <typename float_type>
bool LEQ(float_type n, float_type m) { return n <= m + EPS; }

// m は n より小さい(以下)かどうか
template <typename float_type>
bool GE(float_type n, float_type m) { return n + EPS > m; }
template <typename float_type>
bool GEQ(float_type n, float_type m) { return n + EPS >= m; }

// 2つのベクトルの内積を求める
double dot(Point a, Point b) {
    return (a.real() * b.real() + a.imag() * b.imag());
}

// 2つのベクトルの外積を求める
double cross(Point a, Point b) {
    return (a.real() * b.imag() - a.imag() * b.real());
}

// ccw (c が直線(線分) ab に対してどのような位置関係か？)
// Verified: AOJ CGL_1_C: Counter-Clockwise
// +1 ... a → b で半時計方向に折れて b → c (COUNTER_CLOCKWISE)
// -1 ... a → b で時計方向に折れて b → c (CLOCKWISE)
// +2 ... c, a, b がこの順で同一直線状にある場合 (ONLINE_BACK)
// -2 ... a, b, c がこの順で同一直線状にある場合 ( or a == b ) (ONLINE_FRONT)
//  0 ... c が線分 ab 上にある場合 (点 a, b 上を含む) (ON_SEGMENT)
int ccw(Point a, Point b, Point c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

/***** テクニック編 *****/

/*
// ベクトル a の絶対値を求める (complex型)
double len = abs(a);

// 2点 a,b 間の距離を求める (complex型)
double dist = abs(a-b);

// 2点が等しいかどうかの判定
if(abs(a-b) < EPS)

// ベクトル a の単位ベクトル b を求める
Point b = a / abs(a);

// ベクトル a の法線ベクトル n1, n2 を求める
Point n1 = a * Point(0, 1);
Point n2 = a * Point(0, -1);

// ベクトル a の単位法線ベクトル un1, un2 を求める
Point un1 = (a * Point(0, 1)) / abs(a);
Point un2 = (a * Point(0, -1)) / abs(a);
*/

/***** 直交・平行判定 *****/
// Verified: AOJ CGL_2_A: Parallel/Orthogonal

// 2直線の直交判定 (内積が0であること)
bool is_orthogonal(Point a1, Point a2, Point b1, Point b2) {
    return EQ( dot(a1-a2, b1-b2), 0.0 );
}

// 2直線の平行判定 (外積が0であること)
bool is_parallel(Point a1, Point a2, Point b1, Point b2) {
    return EQ( cross(a1-a2, b1-b2), 0.0 );
}

/***** 各種交差判定 (intersection) *****/
// 豆知識: 線分 ... line segment (英)

// 直線 a1, a2 と点 b の交差判定 (直線上に点があるかの判定)
// ccwで絶対値が1 (一直線で線分上にない) でなければ交差している
bool isec_lp(Point a1, Point a2, Point b) {
    return abs( ccw(a1, a2, b) ) != 1;
}

// 直線 a1, a2 と直線 b1, b2 の交差判定
bool isec_ll(Point a1, Point a2, Point b1, Point b2) {
    return !isec_lp(a2-a1, b2-b1, 0) || isec_lp(a1, b1, b2);
}

// 直線 a1, a2 と線分 b1, b2 の交差判定
bool isec_ls(Point a1, Point a2, Point b1, Point b2) {
    return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 線分 a1, a2 と線分 b1, b2 の交差判定
// Verified: CGL_2_B: Intersection
bool isec_ss(Point a1, Point a2, Point b1, Point b2) {
    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

// 線分 a1, a2 と点 b の交差判定 (線分上に点があるかの判定)
bool isec_sp(Point a1, Point a2, Point b) {
    return !ccw(a1, a2, b);
}

/***** 各種距離 *****/

// 点 p の直線 a1, a2 への射影点を返す
// Verified: AOJ CGL_1_A: Projection
Point projection(Point a1, Point a2, Point p) {
    return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);
}

// 点 p の直線 a への反射点を返す
// Verified: AOJ CGL_1_B: Reflection
Point reflection(Point a1, Point a2, Point p) {
    return 2.0 * projection(a1, a2, p) - p;
}

// 点 a1, a2 を通る直線と点 b との距離
double dist_lp(Point a1, Point a2, Point b) {
    return abs( cross(a2-a1, b-a1) ) / abs(a2-a1);
}

// 直線 a1, a2 と 直線 b1, b2 との距離
double dist_ll(Point a1, Point a2, Point b1, Point b2) {
    return isec_ll(a1, a2, b1, b2) ? 0 : dist_lp(a1, a2, b1);
}

// 直線 a1, a2 と 線分 b1, b2 との距離
double dist_ls(Point a1, Point a2, Point b1, Point b2) {
    return isec_ls(a1, a2, b1, b2) ? 0 : min( dist_lp(a1, a2, b1), dist_lp(a1, a2, b2) );
}

// 点 a1, a2 を端点とする線分と点 b との距離
double dist_sp(Point a1, Point a2, Point b) {
    if( dot(a2-a1, b-a1) < EPS ) return abs(b - a1);
    if( dot(a1-a2, b-a2) < EPS ) return abs(b - a2);
    return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);
}

// 線分 a1, a2 と 線分 b1, b2 との距離
// Verified: CGL_2_D: Distance
double dist_ss(Point a1, Point a2, Point b1, Point b2) {
    if(isec_ss(a1, a2, b1, b2)) return 0;
    return min( min(dist_sp(a1, a2, b1), dist_sp(a1, a2, b2)),
                min(dist_sp(b1, b2, a1), dist_sp(b1, b2, a2)) );
}

// 直線 a1, a2 と直線b1, b2の交点を求める
// Verified: AOJ CGL_2_C.cpp
Point crossp_ll(Point a1, Point a2, Point b1, Point b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if( EQ(d1,0.0) && EQ(d2,0.0) ) return a1; // same line
    if( EQ(d2,0.0) ) assert(false); // precondition not satisfied
    return a1 + d1 / d2 * (a2 - a1);
}

/***** 円に関する問題 *****/

// 直線 a1, a2 と 円 C との距離
double dist_lc(Point a1, Point a2, Circle c) {
    return max(dist_lp(a1, a2, c.first) - c.second, 0.0);
}

// 線分 a1, a2 と 円 C との距離
double dist_sc(Point a1, Point a2, Circle c) {
    double dSqr1 = norm(c.first - a1), dSqr2 = norm(c.first - a2);
    double r = c.second;
    if((dSqr1 < r*r) ^ (dSqr2 < r*r)) return 0; //円が線分を包含するとき距離0ならばここをORに変える
    if((dSqr1 < r*r) & (dSqr2 < r*r)) return r - sqrt(max(dSqr1, dSqr2));
    return max(dist_sp(a1, a2, c.first) - r, 0.0);
}

// 円 x と円 y との距離
double dist_cc(Circle x, Circle y) {
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    double d = abs(a-b);
    return GE(d, abs(ar-br)) ? max(d-ar-br, 0.0) : abs(ar-br) - d;
}

// 直線 a1, a2 と円 C との交点
// Verified: AOJ CGL_7_D: Cross Points of a Circle and a Line
vector<Point> crossp_lc(Point a1, Point a2, Circle c) {
    vector<Point> ps;
    double r = c.second;
    Point ft = projection(a1, a2, c.first);
    if(!GEQ(r*r, norm(ft-c.first))) return ps;

    Point dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);
    return ps;
}

// 円 x と円 y の交点
// Verified: AOJ CGL_7_E: Cross Points of Circles
vector<Point> crossp_cc(Circle x, Circle y) {
    vector<Point> ps;
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    Point ab = b-a;
    double d = abs(ab);
    double crL = (norm(ab) + ar * ar - br * br) / (2 * d);
    if(EQ(d,0.0) || ar < abs(crL)) return ps;

    Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);
    Point cp = a + crL/d * ab;
    ps.push_back(cp + abN);
    if(!EQ(norm(abN), 0.0)) ps.push_back(cp - abN);
    return ps;
}

// 点 p から円 x への接線の接点
// Verified: AOJ CGL_7_F: Tangent to a Circle
vector<Point> tangentPoints(Point p, Circle x) {
    vector<Point> ps;
    Point a = x.first; double ar = x.second;
    double sin = ar / abs(p-a);
    if(!LE(sin, 1.0)) return ps; // ここで NaN もはじかれる

    double t = M_PI_2 - asin(min(sin, 1.0));
    ps.push_back(a + (p-a) * polar(sin, t));
    if(!EQ(sin, 1.0)) ps.push_back(a + (p-a)*polar(sin, -t));
    return ps;
}

// 円 x と円 y の共通接線。返される各直線に含まれる頂点は円との接点となる
// Verified: AOJ CGL_7_G: Common Tangent
// ※ やること: -0.0000000になる問題を直したい・・・
vector<Line> tangentLines(Circle x, Circle y) {
    Point a = x.first, b = y.first;
    double ar = x.second, br = y.second;
    vector<Line> ls;
    double d = abs(b-a);

    for(int i=0; i<2; i++) {
        double sin = (ar - (1-i*2)*br) / d;
        if(!LE(sin*sin, 1.0)) break;

        double cos = sqrt(max(1 - sin*sin, 0.0));
        for(int j=0; j<2; j++) {
            Point n = (b-a) * Point(sin, (1-j*2)*cos) / d;
            ls.push_back(Line(a + ar*n, b + (1-i+2)*br*n));
            if(cos < EPS) break; // 重複する接線を無視 (重複してよいならこの行は不要)
        }
    }
    return ls;
}

// 円 c1 と円 c2 の位置関係
// Verified: AOJ CGL_7_A: Intersection
int intersectCC(Circle c1, Circle c2){
    Point c1p = c1.first, c2p = c2.first;
    double c1r = c1.second, c2r = c2.second;
    long double d = abs(c1p - c2p), r1 = c1r, r2 = c2r;
    if(r1 + r2 < d)            return  0; // 離れている
    if(abs(r1 + r2 - d) < EPS) return -2; // 外接
    if(abs(d + r1 - r2) < EPS) return +1; // c1 が c2 の中で内接
    if(abs(d + r2 - r1) < EPS) return -1; // c2 が c1 の中で内接
    if(d + r1 < r2)            return +3; // c1 が c2 の中
    if(d + r2 < r1)            return -3; // c2 が c1 の中
    return 2; // 2つの交点を持つ
}

// 三角形の外心。点 a, b, c は同一線上にあってはならない
Point circumcenter(Point a, Point b, Point c) {
    a = (a-c) * 0.5;
    b = (b-c) * 0.5;
    return c + crossp_ll(a, a*Point(1,1), b, b*Point(1,1));
}

// 三角形の内心
Point InnerCenter(Point a, Point b, Point c) {
    double p = abs(b-c), q = abs(c-a), r = abs(a-b);
    return (p*a + q*b + r*c) / (p + q + r);
}

// 三角形の重心
Point CenterOfGravity(Point a, Point b, Point c) {
    return (a + b + c) / 3.0;
}

// 三角形の垂心
Point Orthocenter(Point a, Point b, Point c) {
    Point x = circumcenter(a, b, c);
    Point ret = (a-x) + (b-x) + (c-x);
    return ret-x;
}

// 点 a と 点 b を通り、半径が r の円の中心を返す
vector<Point> circlesPointsRadius(Point a, Point b, double r) {
    vector<Point> cs;
    Point abH = (b-a) * 0.5;
    double d = abs(abH);

    if(d == 0 || d > r) return cs; // 必要なら !LE(d,r) として円1つになる側へ丸める
    double dN = sqrt(r*r - d*d);   // 必要なら max(r*r - d*d, 0) とする
    Point n = abH * Point(0,1) * (dN / d);
    cs.push_back(a + abH + n);
    if(dN > 0) cs.push_back(a + abH - n);
    return cs;
}

// 点 a と点 b を通り、直線 l に接する円の中心
vector<Point> circlesPointsTangent(Point a, Point b, Point l1, Point l2) {
    Point n = (l2-l1) * Point(0,1);
    Point m = (b-a) * Point(0,0.5);
    double rC = dot((a+b)*0.5-l1, n);
    double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);
    double qb = -rC * dot(n,m);
    double qc = norm(n)*norm(m) - rC*rC;
    double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0

    vector<Point> cs;
    if(qd < -EPS) return cs;
    if(EQ(qa, 0.0)) {
        if(!EQ(qb,0.0)) cs.push_back((a+b)*0.5 - m * (qc/qb/2));
        return cs;
    }
    double t = -1*qb/qa;
    cs.push_back( (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0)) / qa ));
    if(qd > EPS) cs.push_back( (a+b)*0.5 + m * (t - sqrt(max(qd, 0.0)) / qa));
    return cs;
}

// 点集合を含む最小の円の中心
Point minEnclosingCircle(const vector<Point> &ps) {
    Point c;
    double move = 0.5;
    for(int i=0; i<39; i++) { // 2^(-39-1) \approx 0.9e-12
        for(int t=0; t<50; t++) {
            double max = 0;
            int k = 0;
            for(size_t j=0; j<ps.size(); j++) if(max < norm(ps[j] - c)) {
                max = norm(ps[j] - c);
                k = j;
            }
            c += (ps[k] - c) * move;
        }
        move /= 2;
    }
    return c;
}

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
    sort(ps.begin(), ps.end(), cmp_y);

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
    return EQ(cr, 0.0) ? 2 : cr < 0 ? 0 : 1;
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
        if(EQ(cross(a,b), 0.0) && LE(dot(a,b), 0.0)) return 2;
        if(a.imag() > b.imag()) swap(a,b);
        if((a.imag() * b.imag() < 0 || (a.imag() * b.imag() < EPS && b.imag() > EPS)) && LE(cross(a,b), 0.0)) in = !in;
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
/*
vector<Point> voronoiCell(Point p, const vector<Point> &ps, const vector<Point> &outer) {
    vector<Point> cl = outer;
    for(size_t i=0; i<ps.size(); i++) {
        if(EQ(norm(ps[i] - p), 0.0)) continue;
        Point h = (p + ps[i]) * 0.5;
        cl = convexCut(cl, h, h + (ps[i] - h) * Point(0,1));
    }
    return cl;
}
*/

// 頂点を回転させる系

// 度数法 → 弧度法
double deg2rad(double x) {return x * M_PI / 180.0;}

// 点 a を中心として、点 b を z 度回転させたときの位置
Point rotatePoint(Point a, Point b, double z) {
    // 度数法の場合は変換
    z = deg2rad(z);

    b -= a;
    double rx = b.real() * cos(z) - b.imag() * sin(z);
    double ry = b.real() * sin(z) + b.imag() * cos(z);
    Point ret(rx, ry); ret += a;
    return ret;
}
```

[トップページに戻る](../index.html)
