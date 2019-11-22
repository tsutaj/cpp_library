// 直線 a1, a2 と円 C との交点
// Verified: AOJ CGL_7_D: Cross Points of a Circle and a Line
vector<P> crossp_lc(P a1, P a2, C c) {
    vector<P> ps;
    double r = c.second;
    P ft = projection(a1, a2, c.first);
    if(!GEQ(r*r, norm(ft-c.first))) return ps;

    P dir = sqrt(max(r*r - norm(ft-c.first), 0.0)) / abs(a2-a1) * (a2-a1);
    ps.push_back(ft + dir);
    if(!EQ(r*r, norm(ft-c.first))) ps.push_back(ft - dir);
    return ps;
}

// 円 x と円 y の交点
// Verified: AOJ CGL_7_E: Cross Points of Circles
vector<P> crossp_cc(C x, C y) {
    vector<P> ps;
    P a = x.first, b = y.first;
    double ar = x.second, br = y.second;

    P ab = b-a;
    double d = abs(ab);
    double crL = (norm(ab) + ar * ar - br * br) / (2 * d);
    if(EQ(d,0) || ar < abs(crL)) return ps;

    P abN = ab * P(0, sqrt(ar*ar - crL*crL) / d);
    P cp = a + crL/d * ab;
    ps.push_back(cp + abN);
    if(!EQ(norm(abN), 0)) ps.push_back(cp - abN);
    return ps;
}