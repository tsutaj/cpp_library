// 点 p から円 x への接線の接点
// Verified: AOJ CGL_7_F: Tangent to a Circle
vector<P> tangentPoints(P p, C x) {
    vector<P> ps;
    P a = x.first; double ar = x.second;
    double sin = ar / abs(p-a);
    if(!LE(sin, 1)) return ps; // ここで NaN もはじかれる

    double t = M_PI_2 - asin(min(sin, 1.0));
    ps.push_back(a + (p-a) * polar(sin, t));
    if(!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
    return ps;
}

// 円 x と円 y の共通接線。返される各直線に含まれる頂点は円との接点となる
// Verified: AOJ CGL_7_G: Common Tangent
// ※ やること: -0.0000000になる問題を直したい・・・
vector<L> tangentLines(C x, C y) {
    P a = x.first, b = y.first;
    double ar = x.second, br = y.second;
    vector<L> ls;
    double d = abs(b-a);

    rep(i,0,2) {
        double sin = (ar - (1-i*2)*br) / d;
        if(!LE(sin*sin, 1)) break;

        double cos = sqrt(max(1 - sin*sin, 0.0));
        rep(j,0,2) {
            P n = (b-a) * P(sin, (1-j*2)*cos) / d;
            ls.push_back(L(a + ar*n, b + (1-i+2)*br*n));
            if(cos < EPS) break; // 重複する接線を無視 (重複してよいならこの行は不要)
        }
    }
    return ls;
}