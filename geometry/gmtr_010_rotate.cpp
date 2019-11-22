// 頂点を回転させる系

// 度数法 → 弧度法
double deg2rad(double x) {return x * M_PI / 180.0;}

// 点 a を中心として、点 b を z 度回転させたときの位置
P rotatePoint(P a, P b, double z) {
    // 度数法の場合は変換
    z = deg2rad(z);

    b -= a;
    double rx = b.X * cos(z) - b.Y * sin(z);
    double ry = b.X * sin(z) + b.Y * cos(z);
    P ret(rx, ry); ret += a;
    return ret;
}