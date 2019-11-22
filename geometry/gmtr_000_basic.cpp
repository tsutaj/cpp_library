/***** 基本的準備 *****/

// xy平面上の点(ベクトル)を表現するには、complex型を利用するとよい
typedef complex<double> P;

// 辺の表現 (座標を2つ pair でもつ)
typedef pair<P, P> L;

// 円の表現 (座標 P と 半径 d で表現する)
typedef pair<P, double> C;

// 成分を取り出すのを簡単にする
#define X real()
#define Y imag()

// 誤差(epsilon)の定義
#define EPS (1e-10)

// 2つの要素が等しいかどうか
#define EQ(a,b) (abs((a) - (b)) < EPS)

// 2つのベクトルが等しいかどうか
#define EQV(a,b) ( EQ((a).X, (b).X) && EQ((a).Y, (b).Y) )

// m は n より大きい(以上)かどうか
#define LE(n, m) ((n) < (m) + EPS)
#define LEQ(n, m) ((n) <= (m) + EPS)

// m は n より小さい(以下)かどうか
#define GE(n, m) ((n) + EPS > (m))
#define GEQ(n, m) ((n) + EPS >= (m))

// 2つのベクトルの内積を求める
double dot(P a, P b) {
    return (a.X * b.X + a.Y * b.Y);
}

// 2つのベクトルの外積を求める
double cross(P a, P b) {
    return (a.X * b.Y - a.Y * b.X);
}

// ccw (c が直線(線分) ab に対してどのような位置関係か？)
// Verified: AOJ CGL_1_C: Counter-Clockwise
// +1 ... a → b で半時計方向に折れて b → c (COUNTER_CLOCKWISE)
// -1 ... a → b で時計方向に折れて b → c (CLOCKWISE)
// +2 ... c, a, b がこの順で同一直線状にある場合 (ONLINE_BACK)
// -2 ... a, b, c がこの順で同一直線状にある場合 ( or a == b ) (ONLINE_FRONT)
//  0 ... c が線分 ab 上にある場合 (点 a, b 上を含む) (ON_SEGMENT)
int ccw(P a, P b, P c) {
    b -= a; c -= a;
    if( cross(b,c) > EPS ) return +1;
    if( cross(b,c) < -EPS ) return -1;
    if( dot(b,c) < 0 ) return +2;
    if( norm(b) < norm(c) ) return -2;
    return 0;
}

/***** テクニック編 *****/

// ベクトル a の絶対値を求める (complex型)
double len = abs(a);

// 2点 a,b 間の距離を求める (complex型)
double dist = abs(a-b);

// 2点が等しいかどうかの判定
if(abs(a-b) < EPS)

// ベクトル a の単位ベクトル b を求める
P b = a / abs(a);

// ベクトル a の法線ベクトル n1, n2 を求める
P n1 = a * P(0, 1);
P n2 = a * P(0, -1);

// ベクトル a の単位法線ベクトル un1, un2 を求める
P un1 = (a * P(0, 1)) / abs(a);
P un2 = (a * P(0, -1)) / abs(a);