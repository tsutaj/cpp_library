---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="assets/js/copy-button.js"></script>
<link rel="stylesheet" href="assets/css/copy-button.css" />


# ライブラリの HTML ビルドテスト

[![Actions Status]({{ site.github.repository_url }}/workflows/verify/badge.svg)]({{ site.github.repository_url }}/actions) <a href="{{ site.github.repository_url }}"><img src="https://img.shields.io/github/last-commit/{{ site.github.owner_name }}/{{ site.github.repository_name }}" /></a>

ここに書いた内容がトップページに足されます

* this unordered seed list will be replaced by toc as unordered list
{:toc}

## Library Files
### .
* :warning: <a href="library/basic_000_template.cpp.html">basic_000_template.cpp</a>


### algorithm
* :warning: <a href="library/algorithm/algo_000_sum.cpp.html">algorithm/algo_000_sum.cpp</a>
* :warning: <a href="library/algorithm/algo_001_mo.cpp.html">algorithm/algo_001_mo.cpp</a>
* :warning: <a href="library/algorithm/algo_002_accumulation.cpp.html">algorithm/algo_002_accumulation.cpp</a>
* :warning: <a href="library/algorithm/algo_003_2D_accumulation.cpp.html">algorithm/algo_003_2D_accumulation.cpp</a>


### algorithm/verify
* :warning: <a href="library/algorithm/verify/verify_algo_002_accumulation.cpp.html">algorithm/verify/verify_algo_002_accumulation.cpp</a>
* :warning: <a href="library/algorithm/verify/verify_algo_003_2D_accumulation.cpp.html">algorithm/verify/verify_algo_003_2D_accumulation.cpp</a>


### dp
* :warning: <a href="library/dp/dp_000_lis_dim2.cpp.html">dp/dp_000_lis_dim2.cpp</a>
* :warning: <a href="library/dp/dp_001_maxSquare.cpp.html">dp/dp_001_maxSquare.cpp</a>
* :warning: <a href="library/dp/dp_002_maxRectangle.cpp.html">dp/dp_002_maxRectangle.cpp</a>
* :warning: <a href="library/dp/dp_003_histogram.cpp.html">dp/dp_003_histogram.cpp</a>
* :warning: <a href="library/dp/dp_004_editDistance.cpp.html">dp/dp_004_editDistance.cpp</a>
* :warning: <a href="library/dp/dp_005_limitKnapsack.cpp.html">dp/dp_005_limitKnapsack.cpp</a>
* :warning: <a href="library/dp/dp_006_TSP.cpp.html">dp/dp_006_TSP.cpp</a>
* :warning: <a href="library/dp/dp_007_CPP.cpp.html">dp/dp_007_CPP.cpp</a>
* :warning: <a href="library/dp/dp_008_digit.cpp.html">dp/dp_008_digit.cpp</a>
* :warning: <a href="library/dp/dp_008_digit2.cpp.html">dp/dp_008_digit2.cpp</a>


### etc
* :warning: <a href="library/etc/etc_000_date.cpp.html">etc/etc_000_date.cpp</a>
* :warning: <a href="library/etc/etc_001_dice.cpp.html">etc/etc_001_dice.cpp</a>


### geometry
* :heavy_check_mark: <a href="library/geometry/geometry_2D.cpp.html">geometry/geometry_2D.cpp</a>


### geometry/old
* :warning: <a href="library/geometry/old/gmtr_000_basic.cpp.html">geometry/old/gmtr_000_basic.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_001_orthogonal_parallel.cpp.html">geometry/old/gmtr_001_orthogonal_parallel.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_002_intersection.cpp.html">geometry/old/gmtr_002_intersection.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_003_distance.cpp.html">geometry/old/gmtr_003_distance.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_004_circle_dist.cpp.html">geometry/old/gmtr_004_circle_dist.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_005_circle_crossp.cpp.html">geometry/old/gmtr_005_circle_crossp.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_006_circle_tangent.cpp.html">geometry/old/gmtr_006_circle_tangent.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_007_circle_intersection.cpp.html">geometry/old/gmtr_007_circle_intersection.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_008_circle_points.cpp.html">geometry/old/gmtr_008_circle_points.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_009_poly.cpp.html">geometry/old/gmtr_009_poly.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_010_rotate.cpp.html">geometry/old/gmtr_010_rotate.cpp</a>
* :warning: <a href="library/geometry/old/gmtr_100_basic_threedim.cpp.html">geometry/old/gmtr_100_basic_threedim.cpp</a>


### graph
* :warning: <a href="library/graph/graph_000_basic.cpp.html">graph/graph_000_basic.cpp</a>
* :warning: <a href="library/graph/graph_001_bellman.cpp.html">graph/graph_001_bellman.cpp</a>
* :warning: <a href="library/graph/graph_002_dijkstra.cpp.html">graph/graph_002_dijkstra.cpp</a>
* :warning: <a href="library/graph/graph_003_warshall.cpp.html">graph/graph_003_warshall.cpp</a>
* :warning: <a href="library/graph/graph_004_prim.cpp.html">graph/graph_004_prim.cpp</a>
* :warning: <a href="library/graph/graph_005_kruskal.cpp.html">graph/graph_005_kruskal.cpp</a>
* :warning: <a href="library/graph/graph_006_bridge_points.cpp.html">graph/graph_006_bridge_points.cpp</a>
* :warning: <a href="library/graph/graph_007_tree_dfs.cpp.html">graph/graph_007_tree_dfs.cpp</a>
* :warning: <a href="library/graph/graph_008_treeheight.cpp.html">graph/graph_008_treeheight.cpp</a>
* :warning: <a href="library/graph/graph_009_tpsort.cpp.html">graph/graph_009_tpsort.cpp</a>
* :warning: <a href="library/graph/graph_010_scc.cpp.html">graph/graph_010_scc.cpp</a>
* :warning: <a href="library/graph/graph_011_lca.cpp.html">graph/graph_011_lca.cpp</a>
* :warning: <a href="library/graph/graph_012_maxflow_ford.cpp.html">graph/graph_012_maxflow_ford.cpp</a>
* :warning: <a href="library/graph/graph_013_rootedtreeiso.cpp.html">graph/graph_013_rootedtreeiso.cpp</a>
* :warning: <a href="library/graph/graph_014_treecenters.cpp.html">graph/graph_014_treecenters.cpp</a>
* :warning: <a href="library/graph/graph_015_forest2trees.cpp.html">graph/graph_015_forest2trees.cpp</a>
* :warning: <a href="library/graph/graph_016_SPFA.cpp.html">graph/graph_016_SPFA.cpp</a>
* :warning: <a href="library/graph/graph_017_bipartite.cpp.html">graph/graph_017_bipartite.cpp</a>
* :warning: <a href="library/graph/graph_018_dinic.cpp.html">graph/graph_018_dinic.cpp</a>
* :warning: <a href="library/graph/graph_019_eulertour.cpp.html">graph/graph_019_eulertour.cpp</a>
* :warning: <a href="library/graph/graph_020_HLDecomposition.cpp.html">graph/graph_020_HLDecomposition.cpp</a>
* :warning: <a href="library/graph/graph_021_centroid.cpp.html">graph/graph_021_centroid.cpp</a>
* :warning: <a href="library/graph/graph_022_max_independent_set.cpp.html">graph/graph_022_max_independent_set.cpp</a>
* :warning: <a href="library/graph/graph_023_offline_lca.cpp.html">graph/graph_023_offline_lca.cpp</a>
* :warning: <a href="library/graph/graph_024_boruvka.cpp.html">graph/graph_024_boruvka.cpp</a>
* :warning: <a href="library/graph/graph_025_2SAT.cpp.html">graph/graph_025_2SAT.cpp</a>


### graph/verify
* :warning: <a href="library/graph/verify/verify_graph_012_maxflow_ford.cpp.html">graph/verify/verify_graph_012_maxflow_ford.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_018_dinic.cpp.html">graph/verify/verify_graph_018_dinic.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_020_HLDecomposition.cpp.html">graph/verify/verify_graph_020_HLDecomposition.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_022_max_independent_set.cpp.html">graph/verify/verify_graph_022_max_independent_set.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_023_offline_lca.cpp.html">graph/verify/verify_graph_023_offline_lca.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_024_boruvka.cpp.html">graph/verify/verify_graph_024_boruvka.cpp</a>
* :warning: <a href="library/graph/verify/verify_graph_025_2SAT.cpp.html">graph/verify/verify_graph_025_2SAT.cpp</a>


### marathon
* :warning: <a href="library/marathon/rand.cpp.html">marathon/rand.cpp</a>
* :warning: <a href="library/marathon/timer.cpp.html">marathon/timer.cpp</a>


### math
* :warning: <a href="library/math/math_000_limits.cpp.html">math/math_000_limits.cpp</a>
* :warning: <a href="library/math/math_001_mod.cpp.html">math/math_001_mod.cpp</a>
* :warning: <a href="library/math/math_002_prime.cpp.html">math/math_002_prime.cpp</a>
* :warning: <a href="library/math/math_003_digit.cpp.html">math/math_003_digit.cpp</a>
* :warning: <a href="library/math/math_004_matrix.cpp.html">math/math_004_matrix.cpp</a>
* :warning: <a href="library/math/math_005_matrix_mod2.cpp.html">math/math_005_matrix_mod2.cpp</a>
* :warning: <a href="library/math/math_006_eulerphi.cpp.html">math/math_006_eulerphi.cpp</a>
* :warning: <a href="library/math/math_007_fraction.cpp.html">math/math_007_fraction.cpp</a>
* :warning: <a href="library/math/math_008_miller_rabin_rho.cpp.html">math/math_008_miller_rabin_rho.cpp</a>
* :warning: <a href="library/math/math_009_kitamasa.cpp.html">math/math_009_kitamasa.cpp</a>
* :warning: <a href="library/math/math_010_convexhulltrick.cpp.html">math/math_010_convexhulltrick.cpp</a>
* :warning: <a href="library/math/math_011_fft.cpp.html">math/math_011_fft.cpp</a>
* :warning: <a href="library/math/math_012_garner.cpp.html">math/math_012_garner.cpp</a>
* :warning: <a href="library/math/math_013_ntt.cpp.html">math/math_013_ntt.cpp</a>
* :warning: <a href="library/math/math_014_bsgs.cpp.html">math/math_014_bsgs.cpp</a>
* :warning: <a href="library/math/math_015_remainder_sum.cpp.html">math/math_015_remainder_sum.cpp</a>
* :warning: <a href="library/math/math_016_mod_sqrt.cpp.html">math/math_016_mod_sqrt.cpp</a>
* :warning: <a href="library/math/math_017_modint.cpp.html">math/math_017_modint.cpp</a>
* :warning: <a href="library/math/math_018_ragrange_polynomial.cpp.html">math/math_018_ragrange_polynomial.cpp</a>
* :warning: <a href="library/math/math_019_specific_ragrange_polynomial.cpp.html">math/math_019_specific_ragrange_polynomial.cpp</a>
* :warning: <a href="library/math/math_020_combination.cpp.html">math/math_020_combination.cpp</a>
* :warning: <a href="library/math/math_021_crt.cpp.html">math/math_021_crt.cpp</a>
* :warning: <a href="library/math/math_022_matrix_utils_real.cpp.html">math/math_022_matrix_utils_real.cpp</a>
* :warning: <a href="library/math/math_023_matrix_utils_modp.cpp.html">math/math_023_matrix_utils_modp.cpp</a>
* :warning: <a href="library/math/math_024_fixed_matrix.cpp.html">math/math_024_fixed_matrix.cpp</a>


### math/verify
* :warning: <a href="library/math/verify/verify_math_004_matrix.cpp.html">math/verify/verify_math_004_matrix.cpp</a>
* :warning: <a href="library/math/verify/verify_math_005_matrix_mod2.cpp.html">math/verify/verify_math_005_matrix_mod2.cpp</a>
* :warning: <a href="library/math/verify/verify_math_014_bsgs.cpp.html">math/verify/verify_math_014_bsgs.cpp</a>
* :warning: <a href="library/math/verify/verify_math_015_remainder_sum.cpp.html">math/verify/verify_math_015_remainder_sum.cpp</a>
* :warning: <a href="library/math/verify/verify_math_016_mod_sqrt.cpp.html">math/verify/verify_math_016_mod_sqrt.cpp</a>
* :warning: <a href="library/math/verify/verify_math_018_ragrange_polynomial.cpp.html">math/verify/verify_math_018_ragrange_polynomial.cpp</a>
* :warning: <a href="library/math/verify/verify_math_019_specific_ragrange_polynomial.cpp.html">math/verify/verify_math_019_specific_ragrange_polynomial.cpp</a>
* :warning: <a href="library/math/verify/verify_math_020_combination.cpp.html">math/verify/verify_math_020_combination.cpp</a>
* :warning: <a href="library/math/verify/verify_math_021_crt.cpp.html">math/verify/verify_math_021_crt.cpp</a>
* :warning: <a href="library/math/verify/verify_math_022_matrix_utils_real.cpp.html">math/verify/verify_math_022_matrix_utils_real.cpp</a>
* :warning: <a href="library/math/verify/verify_math_023_matrix_utils_modp.cpp.html">math/verify/verify_math_023_matrix_utils_modp.cpp</a>
* :warning: <a href="library/math/verify/verify_math_024_fixed_matrix.cpp.html">math/verify/verify_math_024_fixed_matrix.cpp</a>


### string
* :warning: <a href="library/string/str_000_split.cpp.html">string/str_000_split.cpp</a>
* :warning: <a href="library/string/str_001_technique.cpp.html">string/str_001_technique.cpp</a>
* :warning: <a href="library/string/str_002_rollinghash.cpp.html">string/str_002_rollinghash.cpp</a>
* :warning: <a href="library/string/str_003_replace.cpp.html">string/str_003_replace.cpp</a>
* :warning: <a href="library/string/str_004_trie.cpp.html">string/str_004_trie.cpp</a>
* :warning: <a href="library/string/str_005_ahocorasick.cpp.html">string/str_005_ahocorasick.cpp</a>
* :warning: <a href="library/string/str_006_suffixarray.cpp.html">string/str_006_suffixarray.cpp</a>
* :warning: <a href="library/string/str_007_kmp.cpp.html">string/str_007_kmp.cpp</a>
* :warning: <a href="library/string/str_008_shift_and_or.cpp.html">string/str_008_shift_and_or.cpp</a>
* :warning: <a href="library/string/str_009_manacher.cpp.html">string/str_009_manacher.cpp</a>
* :warning: <a href="library/string/str_010_z_algorithm.cpp.html">string/str_010_z_algorithm.cpp</a>


### string/verify
* :warning: <a href="library/string/verify/verify_str_004_trie.cpp.html">string/verify/verify_str_004_trie.cpp</a>
* :warning: <a href="library/string/verify/verify_str_009_manacher.cpp.html">string/verify/verify_str_009_manacher.cpp</a>
* :warning: <a href="library/string/verify/verify_str_010_z_algorithm.cpp.html">string/verify/verify_str_010_z_algorithm.cpp</a>


### structure
* :warning: <a href="library/structure/strc_001_unionfind.cpp.html">structure/strc_001_unionfind.cpp</a>
* :warning: <a href="library/structure/strc_002_bit.cpp.html">structure/strc_002_bit.cpp</a>
* :warning: <a href="library/structure/strc_003_twodimbit.cpp.html">structure/strc_003_twodimbit.cpp</a>
* :warning: <a href="library/structure/strc_004_bit_sec.cpp.html">structure/strc_004_bit_sec.cpp</a>
* :warning: <a href="library/structure/strc_005_bit_zero_indexed.cpp.html">structure/strc_005_bit_zero_indexed.cpp</a>
* :warning: <a href="library/structure/strc_006_twodimbit_zero_indexed.cpp.html">structure/strc_006_twodimbit_zero_indexed.cpp</a>
* :warning: <a href="library/structure/strc_007_sparsetable.cpp.html">structure/strc_007_sparsetable.cpp</a>
* :warning: <a href="library/structure/strc_010_abst_sqrtdecomp.cpp.html">structure/strc_010_abst_sqrtdecomp.cpp</a>
* :warning: <a href="library/structure/strc_011_weighted_unionfind.cpp.html">structure/strc_011_weighted_unionfind.cpp</a>
* :warning: <a href="library/structure/strc_012_kd_tree.cpp.html">structure/strc_012_kd_tree.cpp</a>
* :warning: <a href="library/structure/strc_013_treap.cpp.html">structure/strc_013_treap.cpp</a>
* :warning: <a href="library/structure/strc_014_rbst.cpp.html">structure/strc_014_rbst.cpp</a>
* :warning: <a href="library/structure/strc_015_partial_persistent_unionfind.cpp.html">structure/strc_015_partial_persistent_unionfind.cpp</a>
* :warning: <a href="library/structure/strc_016_persistent_unionfind.cpp.html">structure/strc_016_persistent_unionfind.cpp</a>
* :warning: <a href="library/structure/strc_017_persistent_array.cpp.html">structure/strc_017_persistent_array.cpp</a>
* :warning: <a href="library/structure/strc_018_binarytrie.cpp.html">structure/strc_018_binarytrie.cpp</a>
* :warning: <a href="library/structure/strc_019_intervalset.cpp.html">structure/strc_019_intervalset.cpp</a>
* :heavy_check_mark: <a href="library/structure/strc_023_compact_bitvector.cpp.html">簡潔ビットベクトル (compact bit vector)</a>
* :heavy_check_mark: <a href="library/structure/strc_024_static_wavelet_matrix.cpp.html">Wavelet 行列 (wavelet matrix)</a>


### structure/old
* :warning: <a href="library/structure/old/strc_002_segment_rmq.cpp.html">structure/old/strc_002_segment_rmq.cpp</a>
* :warning: <a href="library/structure/old/strc_003_segment_rmq_sec.cpp.html">structure/old/strc_003_segment_rmq_sec.cpp</a>
* :warning: <a href="library/structure/old/strc_007_bit_recursion.cpp.html">structure/old/strc_007_bit_recursion.cpp</a>
* :warning: <a href="library/structure/old/strc_011_lazysegtree.cpp.html">structure/old/strc_011_lazysegtree.cpp</a>


### structure/verify
* :warning: <a href="library/structure/verify/verify_strc_004_bit_sec.cpp.html">structure/verify/verify_strc_004_bit_sec.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_008_abst_segtree.cpp.html">structure/verify/verify_strc_008_abst_segtree.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_009_abst_lazy_segtree.cpp.html">structure/verify/verify_strc_009_abst_lazy_segtree.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_020_dynamic_segtree.cpp.html">structure/verify/verify_strc_020_dynamic_segtree.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp.html">structure/verify/verify_strc_021_dynamic_lazy_segtree.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_022_dual_segtree.cpp.html">structure/verify/verify_strc_022_dual_segtree.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_023_compact_bitvector.cpp.html">structure/verify/verify_strc_023_compact_bitvector.cpp</a>
* :warning: <a href="library/structure/verify/verify_strc_024_static_wavelet_matrix.cpp.html">structure/verify/verify_strc_024_static_wavelet_matrix.cpp</a>


### セグメント木 (Segment Tree)
* :warning: <a href="library/structure/strc_008_abst_segtree.cpp.html">セグメント木 (Segment Tree)</a>
* :warning: <a href="library/structure/strc_009_abst_lazy_segtree.cpp.html">遅延伝播セグメント木 (Lazy Segment Tree)</a>
* :warning: <a href="library/structure/strc_020_dynamic_segtree.cpp.html">動的セグメント木 (Dynamic Segment Tree)</a>
* :warning: <a href="library/structure/strc_021_dynamic_lazy_segtree.cpp.html">動的遅延セグメント木 (Dynamic Lazy Segment Tree)</a>
* :warning: <a href="library/structure/strc_022_dual_segtree.cpp.html">双対セグメント木 (Dual Segment Tree)</a>


## Verify Files
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/1549/static_wavelet_matrix.test.cpp.html">$\left\[ l, r \right\]$ にある整数の中で $D$ に最も近いものを求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/2426/static_wavelet_matrix.test.cpp.html">矩形 $x_{i1} \leq x \leq x_{i2}, y_{i1} \leq y \leq y_{i2}$ 内に属する点の個数を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_less.test.cpp.html">AOJ ALDS_1_5_D: 反転数 (01)</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/ALDS1_5_D/static_wavelet_matrix_more.test.cpp.html">AOJ ALDS_1_5_D: 反転数 (02)</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp.html">ソートを行う (小さいものから $k$ 番目を求められることを利用)</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_1_A/geometry.test.cpp.html">直線 $p_1 p_2$ に対する点 $p$ の射影を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_1_B/geometry.test.cpp.html">直線 $p_1 p_2$ に対する点 $p$ の反射を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_1_C/geometry.test.cpp.html">$3$ 点 $p_0, p_1, p_2$ の位置関係 (ccw) を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_2_A/geometry.test.cpp.html">直線 $s_1, s_2$ について平行・直交を判定</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_2_B/geometry.test.cpp.html">線分 $s_1, s_2$ について、交差を判定</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_2_C/geometry.test.cpp.html">線分 $s_1, s_2$ の交点の座標を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_2_D/geometry.test.cpp.html">線分 $s_1, s_2$ についてそれらの距離を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_3_A/geometry.test.cpp.html">凸とは限らない多角形の面積を計算する</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_3_C/geometry.test.cpp.html">多角形 $g$ と点 $p$ について、$p$ が $g$ に含まれるか・辺上にあるかを判定</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_4_A/geometry.test.cpp.html">二次元平面における点集合 $P$ の凸包を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_4_B/geometry.test.cpp.html">凸多角形 $g$ の直径を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_4_C/geometry.test.cpp.html">凸多角形 $g$ を直線 $p_1 p_2$ で切断したときの、その左側にできる凸多角形の面積 (Convex Cut) を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_7_A/geometry.test.cpp.html">$2$ つの円 $c_1, c_2$ の位置関係を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_7_D/geometry.test.cpp.html">円 $c$ と直線 $l$ の交点を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_7_E/geometry.test.cpp.html">$2$ つの円 $c_1, c_2$ の交点を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_7_F/geometry.test.cpp.html">点 $p$ を通る円 $c$ の接線を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/CGL_7_G/geometry.test.cpp.html">$2$ つの円 $c_1, c_2$ の共通接線を求める</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp.html">連続部分列中の最小の要素を答える</a>
* :heavy_check_mark: <a href="verify/verifying_test/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp.html">与えられた数列を逆順に出力</a>


