経路圧縮とサイズ比較をどちらも行っているため、クエリあたりの計算量は $O(\alpha(N))$ になっているはず。

- `find(x)`: $x$ が属する集合の代表元を返す
- `same(x, y)`: $x$ と $y$ が同じ集合に属するかどうかの bool 値を返す
- `size(x)`: $x$ が属する集合の濃度 (要素数) を返す
- `size()`: 素集合がいくつ存在するかを返す
- `unite(x, y)`: $x$ と $y$ が同じ集合に属するなら `false` を返す。そうでなければ `true` を返すとともに、$x$ が属する集合と $y$ が属する集合を併合する