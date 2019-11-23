# tsutaj の競技プログラミング用 C++ ライブラリ置き場

[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* 自己責任で使ってね
* CI は試験運用中です

## ライブラリ一覧

### algorithm
* algo\_000\_sum.cpp
* algo\_001\_mo.cpp
* algo\_002\_accumulation.cpp
* algo\_003\_2D\_accumulation.cpp

### dp
* dp\_000\_lis\_dim2.cpp
* dp\_001\_maxSquare.cpp
* dp\_002\_maxRectangle.cpp
* dp\_003\_histogram.cpp
* dp\_004\_editDistance.cpp
* dp\_005\_limitKnapsack.cpp
* dp\_006\_TSP.cpp
* dp\_007\_CPP.cpp
* dp\_008\_digit.cpp
* dp\_008\_digit2.cpp

### etc
* etc\_000\_date.cpp
* etc\_001\_dice.cpp

### geometry
* geometry\_2D.cpp
* gmtr\_000\_basic.cpp
* gmtr\_001\_orthogonal\_parallel.cpp
* gmtr\_002\_intersection.cpp
* gmtr\_003\_distance.cpp
* gmtr\_004\_circle\_dist.cpp
* gmtr\_005\_circle\_crossp.cpp
* gmtr\_006\_circle\_tangent.cpp
* gmtr\_007\_circle\_intersection.cpp
* gmtr\_008\_circle\_points.cpp
* gmtr\_009\_poly.cpp
* gmtr\_010\_rotate.cpp
* gmtr\_100\_basic\_threedim.cpp

### graph
* graph\_000\_basic.cpp
* graph\_001\_bellman.cpp
* graph\_002\_dijkstra.cpp
* graph\_003\_warshall.cpp
* graph\_004\_prim.cpp
* graph\_005\_kruskal.cpp
* graph\_006\_bridge\_points.cpp
* graph\_007\_tree\_dfs.cpp
* graph\_008\_treeheight.cpp
* graph\_009\_tpsort.cpp
* graph\_010\_scc.cpp
* graph\_011\_lca.cpp
* graph\_012\_maxflow\_ford.cpp
* graph\_013\_rootedtreeiso.cpp
* graph\_014\_treecenters.cpp
* graph\_015\_forest2trees.cpp
* graph\_016\_SPFA.cpp
* graph\_017\_bipartite.cpp
* graph\_018\_dinic.cpp
* graph\_019\_eulertour.cpp
* graph\_020\_HLDecomposition.cpp
* graph\_021\_centroid.cpp
* graph\_022\_max\_independent\_set.cpp
* graph\_023\_offline\_lca.cpp
* graph\_024\_boruvka.cpp
* graph\_025\_2SAT.cpp

### marathon
* rand.cpp
* timer.cpp

### math
* math\_000\_limits.cpp
* math\_001\_mod.cpp
* math\_002\_prime.cpp
* math\_003\_digit.cpp
* math\_004\_matrix.cpp
* math\_005\_matrix\_mod2.cpp
* math\_006\_eulerphi.cpp
* math\_007\_fraction.cpp
* math\_008\_miller\_rabin\_rho.cpp
* math\_009\_kitamasa.cpp
* math\_010\_convexhulltrick.cpp
* math\_011\_fft.cpp
* math\_012\_garner.cpp
* math\_013\_ntt.cpp
* math\_014\_bsgs.cpp
* math\_015\_remainder\_sum.cpp
* math\_016\_mod\_sqrt.cpp
* math\_017\_modint.cpp
* math\_018\_ragrange\_polynomial.cpp
* math\_019\_specific\_ragrange\_polynomial.cpp
* math\_020\_combination.cpp
* math\_021\_crt.cpp
* math\_022\_matrix\_utils\_real.cpp
* math\_023\_matrix\_utils\_modp.cpp
* math\_024\_fixed\_matrix.cpp

### string
* str\_000\_split.cpp
* str\_001\_technique.cpp
* str\_002\_rollinghash.cpp
* str\_003\_replace.cpp
* str\_004\_trie.cpp
* str\_005\_ahocorasick.cpp
* str\_006\_suffixarray.cpp
* str\_007\_kmp.cpp
* str\_008\_shift\_and\_or.cpp
* str\_009\_manacher.cpp
* str\_010\_z\_algorithm.cpp

### structure
* strc\_002\_segment\_rmq.cpp
* strc\_003\_segment\_rmq\_sec.cpp
* strc\_007\_bit\_recursion.cpp
* strc\_011\_lazysegtree.cpp
* strc\_001\_unionfind.cpp
* strc\_002\_bit.cpp
* strc\_003\_twodimbit.cpp
* strc\_004\_bit\_sec.cpp
* strc\_005\_bit\_zero\_indexed.cpp
* strc\_006\_twodimbit\_zero\_indexed.cpp
* strc\_007\_sparsetable.cpp
* strc\_008\_abst\_segtree.cpp
* strc\_009\_abst\_lazy\_segtree.cpp
* strc\_010\_abst\_sqrtdecomp.cpp
* strc\_011\_weighted\_unionfind.cpp
* strc\_012\_kd\_tree.cpp
* strc\_013\_treap.cpp
* strc\_014\_rbst.cpp
* strc\_015\_partial\_persistent\_unionfind.cpp
* strc\_016\_persistent\_unionfind.cpp
* strc\_017\_persistent\_array.cpp
* strc\_018\_binarytrie.cpp
* strc\_019\_intervalset.cpp
* strc\_020\_dynamic\_segtree.cpp
* strc\_021\_dynamic\_lazy\_segtree.cpp
* strc\_022\_dual\_segtree.cpp
* strc\_023\_compact\_bitvector.cpp
* strc\_024\_static\_wavelet\_matrix.cpp

## Verify ファイル一覧

:heavy_check_mark: は Verify 正常終了、:x: は異常終了

* :heavy_check_mark: ./AOJ/1549/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1549
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/2426/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2426
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_less.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_more.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D&lang=ja
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/ALDS1\_6\_A/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_6_A
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/CGL\_1\_A/CGL\_1\_A.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_1_A&lang=ja
    - Dependencies
        + ../geometry/geometry\_2D.cpp
* :heavy_check_mark: ./AOJ/DSL\_3\_D/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D&lang=ja
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp
* :heavy_check_mark: ./AOJ/ITP1\_6\_A/static\_wavelet\_matrix.test.cpp
    - URL: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_6_A
    - Dependencies
        + ../structure/strc\_023\_compact\_bitvector.cpp
        + ../structure/strc\_024\_static\_wavelet\_matrix.cpp

