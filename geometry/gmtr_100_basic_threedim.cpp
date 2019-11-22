// 3 次元の幾何テンプレ (最低限のもののみ)
// AOJ 2641 でちょっと必要になったので作りました

struct Point {
    double x, y, z;
};

Point operator+(Point a, Point b) {
    return Point{a.x+b.x, a.y+b.y, a.z+b.z};
}

Point operator-(Point a, Point b) {
    return Point{a.x-b.x, a.y-b.y, a.z-b.z};
}

Point operator*(double a, Point b) {
    return Point{a*b.x, a*b.y, a*b.z};
}

double abs(Point a) {
    return sqrt(a.x*a.x + a.y*a.y + a.z*a.z);
}

double cross(Point a, Point b) {
    double ra = a.y * b.z - a.z * b.y;
    double rb = a.z * b.x - a.x * b.z;
    double rc = a.x * b.y - a.y * b.x;
    return sqrt(ra*ra + rb*rb + rc*rc);
}

double dot(Point a, Point b) {
    return a.x*b.x + a.y*b.y + a.z*b.z;
}