<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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

<link rel="stylesheet" href="css/copy-button.css" />
<script type="text/javascript" src="js/balloons.js"></script>
<script type="text/javascript" src="js/copy-button.js"></script>


[![Build Status](https://travis-ci.com/Tsutajiro/cpp_library.svg?branch=master)](https://travis-ci.com/Tsutajiro/cpp_library)

* [リポジトリへのリンク](https://github.com/Tsutajiro/cpp_library)
* tsutaj が使用している競技プログラミング用ライブラリです。自己責任で使ってね
* CI は試験運用中です

# 目次

* this unordered seed list will be replaced by toc as unordered list
{:toc}

# ライブラリ一覧

## algorithm
* :warning: [algo\_000\_sum.cpp](./library/algo_000_sum.cpp.html)
* :warning: [algo\_001\_mo.cpp](./library/algo_001_mo.cpp.html)
* :warning: [algo\_002\_accumulation.cpp](./library/algo_002_accumulation.cpp.html)
* :warning: [algo\_003\_2D\_accumulation.cpp](./library/algo_003_2D_accumulation.cpp.html)

## dp
* :warning: [dp\_000\_lis\_dim2.cpp](./library/dp_000_lis_dim2.cpp.html)
* :warning: [dp\_001\_maxSquare.cpp](./library/dp_001_maxSquare.cpp.html)
* :warning: [dp\_002\_maxRectangle.cpp](./library/dp_002_maxRectangle.cpp.html)
* :warning: [dp\_003\_histogram.cpp](./library/dp_003_histogram.cpp.html)
* :warning: [dp\_004\_editDistance.cpp](./library/dp_004_editDistance.cpp.html)
* :warning: [dp\_005\_limitKnapsack.cpp](./library/dp_005_limitKnapsack.cpp.html)
* :warning: [dp\_006\_TSP.cpp](./library/dp_006_TSP.cpp.html)
* :warning: [dp\_007\_CPP.cpp](./library/dp_007_CPP.cpp.html)
* :warning: [dp\_008\_digit.cpp](./library/dp_008_digit.cpp.html)
* :warning: [dp\_008\_digit2.cpp](./library/dp_008_digit2.cpp.html)

## etc
* :warning: [etc\_000\_date.cpp](./library/etc_000_date.cpp.html)
* :warning: [etc\_001\_dice.cpp](./library/etc_001_dice.cpp.html)

## geometry
* :heavy_check_mark: [geometry\_2D.cpp](./library/geometry_2D.cpp.html)
* :warning: [gmtr\_000\_basic.cpp](./library/gmtr_000_basic.cpp.html)
* :warning: [gmtr\_001\_orthogonal\_parallel.cpp](./library/gmtr_001_orthogonal_parallel.cpp.html)
* :warning: [gmtr\_002\_intersection.cpp](./library/gmtr_002_intersection.cpp.html)
* :warning: [gmtr\_003\_distance.cpp](./library/gmtr_003_distance.cpp.html)
* :warning: [gmtr\_004\_circle\_dist.cpp](./library/gmtr_004_circle_dist.cpp.html)
* :warning: [gmtr\_005\_circle\_crossp.cpp](./library/gmtr_005_circle_crossp.cpp.html)
* :warning: [gmtr\_006\_circle\_tangent.cpp](./library/gmtr_006_circle_tangent.cpp.html)
* :warning: [gmtr\_007\_circle\_intersection.cpp](./library/gmtr_007_circle_intersection.cpp.html)
* :warning: [gmtr\_008\_circle\_points.cpp](./library/gmtr_008_circle_points.cpp.html)
* :warning: [gmtr\_009\_poly.cpp](./library/gmtr_009_poly.cpp.html)
* :warning: [gmtr\_010\_rotate.cpp](./library/gmtr_010_rotate.cpp.html)
* :warning: [gmtr\_100\_basic\_threedim.cpp](./library/gmtr_100_basic_threedim.cpp.html)

## graph
* :warning: [graph\_000\_basic.cpp](./library/graph_000_basic.cpp.html)
* :warning: [graph\_001\_bellman.cpp](./library/graph_001_bellman.cpp.html)
* :warning: [graph\_002\_dijkstra.cpp](./library/graph_002_dijkstra.cpp.html)
* :warning: [graph\_003\_warshall.cpp](./library/graph_003_warshall.cpp.html)
* :warning: [graph\_004\_prim.cpp](./library/graph_004_prim.cpp.html)
* :warning: [graph\_005\_kruskal.cpp](./library/graph_005_kruskal.cpp.html)
* :warning: [graph\_006\_bridge\_points.cpp](./library/graph_006_bridge_points.cpp.html)
* :warning: [graph\_007\_tree\_dfs.cpp](./library/graph_007_tree_dfs.cpp.html)
* :warning: [graph\_008\_treeheight.cpp](./library/graph_008_treeheight.cpp.html)
* :warning: [graph\_009\_tpsort.cpp](./library/graph_009_tpsort.cpp.html)
* :warning: [graph\_010\_scc.cpp](./library/graph_010_scc.cpp.html)
* :warning: [graph\_011\_lca.cpp](./library/graph_011_lca.cpp.html)
* :warning: [graph\_012\_maxflow\_ford.cpp](./library/graph_012_maxflow_ford.cpp.html)
* :warning: [graph\_013\_rootedtreeiso.cpp](./library/graph_013_rootedtreeiso.cpp.html)
* :warning: [graph\_014\_treecenters.cpp](./library/graph_014_treecenters.cpp.html)
* :warning: [graph\_015\_forest2trees.cpp](./library/graph_015_forest2trees.cpp.html)
* :warning: [graph\_016\_SPFA.cpp](./library/graph_016_SPFA.cpp.html)
* :warning: [graph\_017\_bipartite.cpp](./library/graph_017_bipartite.cpp.html)
* :warning: [graph\_018\_dinic.cpp](./library/graph_018_dinic.cpp.html)
* :warning: [graph\_019\_eulertour.cpp](./library/graph_019_eulertour.cpp.html)
* :warning: [graph\_020\_HLDecomposition.cpp](./library/graph_020_HLDecomposition.cpp.html)
* :warning: [graph\_021\_centroid.cpp](./library/graph_021_centroid.cpp.html)
* :warning: [graph\_022\_max\_independent\_set.cpp](./library/graph_022_max_independent_set.cpp.html)
* :warning: [graph\_023\_offline\_lca.cpp](./library/graph_023_offline_lca.cpp.html)
* :warning: [graph\_024\_boruvka.cpp](./library/graph_024_boruvka.cpp.html)
* :warning: [graph\_025\_2SAT.cpp](./library/graph_025_2SAT.cpp.html)

## marathon
* :warning: [rand.cpp](./library/rand.cpp.html)
* :warning: [timer.cpp](./library/timer.cpp.html)

## math
* :warning: [math\_000\_limits.cpp](./library/math_000_limits.cpp.html)
* :warning: [math\_001\_mod.cpp](./library/math_001_mod.cpp.html)
* :warning: [math\_002\_prime.cpp](./library/math_002_prime.cpp.html)
* :warning: [math\_003\_digit.cpp](./library/math_003_digit.cpp.html)
* :warning: [math\_004\_matrix.cpp](./library/math_004_matrix.cpp.html)
* :warning: [math\_005\_matrix\_mod2.cpp](./library/math_005_matrix_mod2.cpp.html)
* :warning: [math\_006\_eulerphi.cpp](./library/math_006_eulerphi.cpp.html)
* :warning: [math\_007\_fraction.cpp](./library/math_007_fraction.cpp.html)
* :warning: [math\_008\_miller\_rabin\_rho.cpp](./library/math_008_miller_rabin_rho.cpp.html)
* :warning: [math\_009\_kitamasa.cpp](./library/math_009_kitamasa.cpp.html)
* :warning: [math\_010\_convexhulltrick.cpp](./library/math_010_convexhulltrick.cpp.html)
* :warning: [math\_011\_fft.cpp](./library/math_011_fft.cpp.html)
* :warning: [math\_012\_garner.cpp](./library/math_012_garner.cpp.html)
* :warning: [math\_013\_ntt.cpp](./library/math_013_ntt.cpp.html)
* :warning: [math\_014\_bsgs.cpp](./library/math_014_bsgs.cpp.html)
* :warning: [math\_015\_remainder\_sum.cpp](./library/math_015_remainder_sum.cpp.html)
* :warning: [math\_016\_mod\_sqrt.cpp](./library/math_016_mod_sqrt.cpp.html)
* :warning: [math\_017\_modint.cpp](./library/math_017_modint.cpp.html)
* :warning: [math\_018\_ragrange\_polynomial.cpp](./library/math_018_ragrange_polynomial.cpp.html)
* :warning: [math\_019\_specific\_ragrange\_polynomial.cpp](./library/math_019_specific_ragrange_polynomial.cpp.html)
* :warning: [math\_020\_combination.cpp](./library/math_020_combination.cpp.html)
* :warning: [math\_021\_crt.cpp](./library/math_021_crt.cpp.html)
* :warning: [math\_022\_matrix\_utils\_real.cpp](./library/math_022_matrix_utils_real.cpp.html)
* :warning: [math\_023\_matrix\_utils\_modp.cpp](./library/math_023_matrix_utils_modp.cpp.html)
* :warning: [math\_024\_fixed\_matrix.cpp](./library/math_024_fixed_matrix.cpp.html)

## string
* :warning: [str\_000\_split.cpp](./library/str_000_split.cpp.html)
* :warning: [str\_001\_technique.cpp](./library/str_001_technique.cpp.html)
* :warning: [str\_002\_rollinghash.cpp](./library/str_002_rollinghash.cpp.html)
* :warning: [str\_003\_replace.cpp](./library/str_003_replace.cpp.html)
* :warning: [str\_004\_trie.cpp](./library/str_004_trie.cpp.html)
* :warning: [str\_005\_ahocorasick.cpp](./library/str_005_ahocorasick.cpp.html)
* :warning: [str\_006\_suffixarray.cpp](./library/str_006_suffixarray.cpp.html)
* :warning: [str\_007\_kmp.cpp](./library/str_007_kmp.cpp.html)
* :warning: [str\_008\_shift\_and\_or.cpp](./library/str_008_shift_and_or.cpp.html)
* :warning: [str\_009\_manacher.cpp](./library/str_009_manacher.cpp.html)
* :warning: [str\_010\_z\_algorithm.cpp](./library/str_010_z_algorithm.cpp.html)

## structure
* :warning: [strc\_002\_segment\_rmq.cpp](./library/strc_002_segment_rmq.cpp.html)
* :warning: [strc\_003\_segment\_rmq\_sec.cpp](./library/strc_003_segment_rmq_sec.cpp.html)
* :warning: [strc\_007\_bit\_recursion.cpp](./library/strc_007_bit_recursion.cpp.html)
* :warning: [strc\_011\_lazysegtree.cpp](./library/strc_011_lazysegtree.cpp.html)
* :warning: [strc\_001\_unionfind.cpp](./library/strc_001_unionfind.cpp.html)
* :warning: [strc\_002\_bit.cpp](./library/strc_002_bit.cpp.html)
* :warning: [strc\_003\_twodimbit.cpp](./library/strc_003_twodimbit.cpp.html)
* :warning: [strc\_004\_bit\_sec.cpp](./library/strc_004_bit_sec.cpp.html)
* :warning: [strc\_005\_bit\_zero\_indexed.cpp](./library/strc_005_bit_zero_indexed.cpp.html)
* :warning: [strc\_006\_twodimbit\_zero\_indexed.cpp](./library/strc_006_twodimbit_zero_indexed.cpp.html)
* :warning: [strc\_007\_sparsetable.cpp](./library/strc_007_sparsetable.cpp.html)
* :warning: [strc\_008\_abst\_segtree.cpp](./library/strc_008_abst_segtree.cpp.html)
* :warning: [strc\_009\_abst\_lazy\_segtree.cpp](./library/strc_009_abst_lazy_segtree.cpp.html)
* :warning: [strc\_010\_abst\_sqrtdecomp.cpp](./library/strc_010_abst_sqrtdecomp.cpp.html)
* :warning: [strc\_011\_weighted\_unionfind.cpp](./library/strc_011_weighted_unionfind.cpp.html)
* :warning: [strc\_012\_kd\_tree.cpp](./library/strc_012_kd_tree.cpp.html)
* :warning: [strc\_013\_treap.cpp](./library/strc_013_treap.cpp.html)
* :warning: [strc\_014\_rbst.cpp](./library/strc_014_rbst.cpp.html)
* :warning: [strc\_015\_partial\_persistent\_unionfind.cpp](./library/strc_015_partial_persistent_unionfind.cpp.html)
* :warning: [strc\_016\_persistent\_unionfind.cpp](./library/strc_016_persistent_unionfind.cpp.html)
* :warning: [strc\_017\_persistent\_array.cpp](./library/strc_017_persistent_array.cpp.html)
* :warning: [strc\_018\_binarytrie.cpp](./library/strc_018_binarytrie.cpp.html)
* :warning: [strc\_019\_intervalset.cpp](./library/strc_019_intervalset.cpp.html)
* :warning: [strc\_020\_dynamic\_segtree.cpp](./library/strc_020_dynamic_segtree.cpp.html)
* :warning: [strc\_021\_dynamic\_lazy\_segtree.cpp](./library/strc_021_dynamic_lazy_segtree.cpp.html)
* :warning: [strc\_022\_dual\_segtree.cpp](./library/strc_022_dual_segtree.cpp.html)
* :heavy_check_mark: [strc\_023\_compact\_bitvector.cpp](./library/strc_023_compact_bitvector.cpp.html)
* :heavy_check_mark: [strc\_024\_static\_wavelet\_matrix.cpp](./library/strc_024_static_wavelet_matrix.cpp.html)

# Verify ファイル一覧

* :heavy_check_mark: [./AOJ/1549/static\_wavelet\_matrix.test.cpp](verified/AOJ/1549/static_wavelet_matrix.test.cpp.html)
* :heavy_check_mark: [./AOJ/2426/static\_wavelet\_matrix.test.cpp](verified/AOJ/2426/static_wavelet_matrix.test.cpp.html)
* :heavy_check_mark: [./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_less.test.cpp](verified/AOJ/ALDS1_5_D/static_wavelet_matrix_less.test.cpp.html)
* :heavy_check_mark: [./AOJ/ALDS1\_5\_D/static\_wavelet\_matrix\_more.test.cpp](verified/AOJ/ALDS1_5_D/static_wavelet_matrix_more.test.cpp.html)
* :heavy_check_mark: [./AOJ/ALDS1\_6\_A/static\_wavelet\_matrix.test.cpp](verified/AOJ/ALDS1_6_A/static_wavelet_matrix.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_1\_A/geometry.test.cpp](verified/AOJ/CGL_1_A/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_1\_B/geometry.test.cpp](verified/AOJ/CGL_1_B/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_1\_C/geometry.test.cpp](verified/AOJ/CGL_1_C/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_2\_A/geometry.test.cpp](verified/AOJ/CGL_2_A/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_2\_B/geometry.test.cpp](verified/AOJ/CGL_2_B/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_2\_C/geometry.test.cpp](verified/AOJ/CGL_2_C/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_2\_D/geometry.test.cpp](verified/AOJ/CGL_2_D/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_3\_A/geometry.test.cpp](verified/AOJ/CGL_3_A/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_3\_C/geometry.test.cpp](verified/AOJ/CGL_3_C/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_4\_A/geometry.test.cpp](verified/AOJ/CGL_4_A/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_4\_B/geometry.test.cpp](verified/AOJ/CGL_4_B/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_4\_C/geometry.test.cpp](verified/AOJ/CGL_4_C/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_7\_A/geometry.test.cpp](verified/AOJ/CGL_7_A/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_7\_D/geometry.test.cpp](verified/AOJ/CGL_7_D/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_7\_E/geometry.test.cpp](verified/AOJ/CGL_7_E/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_7\_F/geometry.test.cpp](verified/AOJ/CGL_7_F/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/CGL\_7\_G/geometry.test.cpp](verified/AOJ/CGL_7_G/geometry.test.cpp.html)
* :heavy_check_mark: [./AOJ/DSL\_3\_D/static\_wavelet\_matrix.test.cpp](verified/AOJ/DSL_3_D/static_wavelet_matrix.test.cpp.html)
* :heavy_check_mark: [./AOJ/ITP1\_6\_A/static\_wavelet\_matrix.test.cpp](verified/AOJ/ITP1_6_A/static_wavelet_matrix.test.cpp.html)
