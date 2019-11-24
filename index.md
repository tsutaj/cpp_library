# tsutaj の競技プログラミング用 C++ ライブラリ置き場

[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* 自己責任で使ってね
* CI は試験運用中です

## ライブラリ一覧

## Verify ファイル一覧

:heavy_check_mark: は Verify 正常終了、:x: は異常終了

* :x: ./AOJ/1549/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
        + "閉区間" $\left[ l, r \right]$ にある整数の中で $D$ に最も近いものを求める
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/2426/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426
        + 矩形 $x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$ 内に属する点の個数を求める
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_less.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
        + 転倒数を求める (自分より小さいものを数えるアプローチ)
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_more.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
        + 転倒数を求める (自分より大きいものを数えるアプローチ)
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/ALDS1\_6\_A/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A
        + ソートを行う (小さいものから $k$ 番目を求められることを利用)
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/CGL\_1\_A/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A&lang=ja
        + 直線 $p_1 p_2$ に対する点 $p$ の射影を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_1\_B/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_B&lang=ja
        + 直線 $p_1 p_2$ に対する点 $p$ の反射を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_1\_C/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_C&lang=ja
        + $3$ 点 $p_0, p_1, p_2$ の位置関係 (ccw) を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_2\_A/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_A&lang=ja
        + 直線 $s_1, s_2$ について平行・直交を判定
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_2\_B/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_B&lang=ja
        + 線分 $s_1, s_2$ について、交差を判定
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_2\_C/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_C&lang=ja
        + 線分 $s_1, s_2$ の交点の座標を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_2\_D/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_2_D&lang=ja
        + 線分 $s_1, s_2$ についてそれらの距離を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_3\_A/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_A&lang=ja
        + 凸とは限らない多角形の面積を計算する
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_3\_C/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_3_C&lang=ja
        + 多角形 $g$ と点 $p$ について、$p$ が $g$ に含まれるか・辺上にあるかを判定
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_4\_A/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A&lang=ja
        + 二次元平面における点集合 $P$ の凸包を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_4\_B/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B&lang=ja
        + 凸多角形 $g$ の直径を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_4\_C/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_C&lang=ja
        + 凸多角形 $g$ を直線 $p_1 p_2$ で切断したときの、その左側にできる凸多角形の面積 (Convex Cut) を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_7\_A/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A&lang=ja
        + $2$ つの円 $c_1, c_2$ の位置関係を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_7\_D/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_D&lang=ja
        + 円 $c$ と直線 $l$ の交点を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_7\_E/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_E&lang=ja
        + $2$ つの円 $c_1, c_2$ の交点を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_7\_F/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_F&lang=ja
        + 点 $p$ を通る円 $c$ の接線を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/CGL\_7\_G/geometry.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_G&lang=ja
        + $2$ つの円 $c_1, c_2$ の共通接線を求める
    - Dependencies
        + ../../../geometry/geometry\_2D.cpp
* :x: ./AOJ/DSL\_3\_D/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja
        + 連続部分列中の最小の要素を答える
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :x: ./AOJ/ITP1\_6\_A/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A&lang=ja
        + 与えられた数列を逆順に出力
    - Dependencies
        + ../../../structure/strc\_023\_compact\_bitvector.cpp
        + ../../../structure/strc\_024\_static\_wavelet\_matrix.cpp

