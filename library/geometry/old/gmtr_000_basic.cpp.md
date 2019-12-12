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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :warning: geometry/old/gmtr_000_basic.cpp
<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#ee276eb56ad4bc3f1e3c8191a9303fa9">geometry/old</a>
* <a href="{{ site.github.repository_url }}/blob/master/geometry/old/gmtr_000_basic.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-24 02:02:41 +0900




## Code
{% raw %}
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

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

