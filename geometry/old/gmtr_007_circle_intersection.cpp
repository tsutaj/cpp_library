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
