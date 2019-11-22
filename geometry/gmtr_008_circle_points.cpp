// 三角形の外心。点 a, b, c は同一線上にあってはならない
P circumcenter(P a, P b, P c) {
    a = (a-c) * 0.5;
    b = (b-c) * 0.5;
    return c + crossp_ll(a, a*P(1,1), b, b*P(1,1));
}

// 三角形の内心
P InnerCenter(P a, P b, P c) {
    double p = abs(b-c), q = abs(c-a), r = abs(a-b);
    return (p*a + q*b + r*c) / (p + q + r);
}

// 三角形の重心
P CenterOfGravity(P a, P b, P c) {
    return (a + b + c) / 3.0;
}

// 三角形の垂心
P Orthocenter(P a, P b, P c) {
    P x = circumcenter(a, b, c);
    P ret = (a-x) + (b-x) + (c-x);
    return ret-x;
}

// 点 a と 点 b を通り、半径が r の円の中心を返す
vector<P> circlesPointsRadius(P a, P b, double r) {
    vector<P> cs;
    P abH = (b-a) * 0.5;
    double d = abs(abH);

    if(d == 0 || d > r) return cs; // 必要なら !LE(d,r) として円1つになる側へ丸める
    double dN = sqrt(r*r - d*d);   // 必要なら max(r*r - d*d, 0) とする
    P n = abH * P(0,1) * (dN / d);
    cs.push_back(a + abH + n);
    if(dN > 0) cs.push_back(a + abH - n);
    return cs;
}

// 点 a と点 b を通り、直線 l に接する円の中心
vector<P> circlesPointsTangent(P a, P b, P l1, P l2) {
    P n = (l2-l1) * P(0,1);
    P m = (b-a) * P(0,0.5);
    double rC = dot((a+b)*0.5-l1, n);
    double qa = norm(n)*norm(m) - dot(n,m)*dot(n,m);
    double qb = -rC * dot(n,m);
    double qc = norm(n)*norm(m) - rC*rC;
    double qd = qb*qb - qa*qc;  // qa*k^2 + 2*qb*k + qc = 0

    vector<P> cs;
    if(qd < -EPS) return cs;
    if(EQ(qa, 0)) {
        if(!EQ(qb,0)) cs.push_back((a+b)*0.5 - m * (qc/qb/2));
        return cs;
    }
    double t = -1*qb/qa;
    cs.push_back( (a+b)*0.5 + m * (t + sqrt(max(qd, 0.0)) / qa ));
    if(qd > EPS) cs.push_back( (a+b)*0.5 + m * (t - sqrt(max(qd, 0.0)) / qa));
    return cs;
}

// 点集合を含む最小の円の中心
P minEnclosingCircle(const vector<P> &ps) {
    P c;
    double move = 0.5;
    rep(i,0,39) { // 2^(-39-1) \approx 0.9e-12
        rep(t,0,50) {
            double max = 0;
            int k = 0;
            rep(j,0,ps.size()) if(max < norm(ps[j] - c)) {
                max = norm(ps[j] - c);
                k = j;
            }
            c += (ps[k] - c) * move;
        }
        move /= 2;
    }
    return c;
}