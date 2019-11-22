/***** 直交・平行判定 *****/
// Verified: AOJ CGL_2_A: Parallel/Orthogonal

// 2直線の直交判定 (内積が0であること)
bool is_orthogonal(P a1, P a2, P b1, P b2) {
    return EQ( dot(a1-a2, b1-b2), 0.0 );
}

// 2直線の平行判定 (外積が0であること)
bool is_parallel(P a1, P a2, P b1, P b2) {
    return EQ( cross(a1-a2, b1-b2), 0.0);
}