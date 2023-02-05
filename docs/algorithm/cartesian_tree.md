see: https://kmyk.github.io/blog/blog/2020/07/27/recursion-on-cartesian-tree/

### Usage

- `getCartesianTree(A, cmp)`: $O(N)$
    - [Input] 数列 $A = (a_1, a_2, \ldots, a_N)$ と比較関数 $\mathrm{cmp}(x, y)$ を与える
        - 比較関数は省略可能。デフォルトでは $\min$ になっている ($x < y$ ならば `true`)
        - 以降、比較関数が $\min$ に設定されていると仮定して説明する
    - [Output] 以下によって生成される $N$ 頂点の根付き木と、その根を pair にして返す
      - $f(l, r)$ を、「$l \leq m < r, a_m = \min_{j=l}^{r-1} a_j$ を満たすインデックス $m$ を返す関数」と定義する
        - 最小値を取る要素が複数存在する場合は、それらのうち最左の要素に対応するインデックスを返す
      - 頂点 $u = f(l, r)$ から、頂点 $c_l = f(l, m)$ と頂点 $c_r = f(m+1, r)$ の両方に向けて辺を張る
        - 「部分配列から最小値を取り除いて列を分割する」のを再帰的に行うことに対応する木となっている
