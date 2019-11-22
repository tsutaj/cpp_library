/***** 各種距離 *****/

// 点 p の直線 a1, a2 への射影点を返す
// Verified: AOJ CGL_1_A: Projection
P projection(P a1, P a2, P p) {
    return a1 + dot(a2-a1, p-a1) / norm(a2-a1) * (a2-a1);
}

// 点 p の直線 a への反射点を返す
// Verified: AOJ CGL_1_B: Reflection
P reflection(P a1, P a2, P p) {
    return 2.0 * projection(a1, a2, p) - p;
}

// 点 a1, a2 を通る直線と点 b との距離
double dist_lp(P a1, P a2, P b) {
    return abs( cross(a2-a1, b-a1) ) / abs(a2-a1);
}

// 直線 a1, a2 と 直線 b1, b2 との距離
double dist_ll(P a1, P a2, P b1, P b2) {
    return isec_ll(a1, a2, b1, b2) ? 0 : dist_lp(a1, a2, b1);
}

// 直線 a1, a2 と 線分 b1, b2 との距離
double dist_ls(P a1, P a2, P b1, P b2) {
    return isec_ls(a1, a2, b1, b2) ? 0 : min( dist_lp(a1, a2, b1), dist_lp(a1, a2, b2) );
}

// 点 a1, a2 を端点とする線分と点 b との距離
double dist_sp(P a1, P a2, P b) {
    if( dot(a2-a1, b-a1) < EPS ) return abs(b - a1);
    if( dot(a1-a2, b-a2) < EPS ) return abs(b - a2);
    return abs( cross(a2-a1, b-a1) ) / abs(a2 - a1);
}

// 線分 a1, a2 と 線分 b1, b2 との距離
// Verified: CGL_2_D: Distance
// isec_ssが必要なので再掲
bool isec_ss(P a1, P a2, P b1, P b2) {
    return ( ccw(a1,a2,b1) * ccw(a1,a2,b2) <= 0 ) &&
           ( ccw(b1,b2,a1) * ccw(b1,b2,a2) <= 0 );
}

double dist_ss(P a1, P a2, P b1, P b2) {
    if(isec_ss(a1, a2, b1, b2)) return 0;
    return min( min(dist_sp(a1, a2, b1), dist_sp(a1, a2, b2)),
                min(dist_sp(b1, b2, a1), dist_sp(b1, b2, a2)) );
}

// 直線 a1, a2 と直線b1, b2の交点を求める
// Verified: AOJ CGL_2_C.cpp
P crossp_ll(P a1, P a2, P b1, P b2) {
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if( EQ(d1,0) && EQ(d2,0) ) return a1; // same line
    if( EQ(d2,0) ) assert(false); // precondition not satisfied
    return a1 + d1 / d2 * (a2 - a1);
}