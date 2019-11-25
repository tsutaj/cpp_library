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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: graph\_013\_rootedtreeiso.cpp

## Code

```cpp
// 根付き木の同型性判定アルゴリズム O(|V|)
// ・葉の値を 1 とする
// ・親は子のハッシュの結果をソートして足しあわせたものをハッシュに入れた値である
// ・根のハッシュ値が一致していれば、木は同型である
// ・根なし木で同型性判定を行うには、木の中心を根にして同型性判定を行えば良い
//   -> 同型な木であれば、中心を根として判定しても結果が同じなのは自明
//   -> 木の中心は高々 2 個 (直径が奇数長なら 1 個、偶数長なら 2 個)
//   -> ハッシュの計算を高々 2 * 2 = 4 回やるだけで済むため、十分高速である
// ・注意: 木の中心の個数が一致しなければ同型でないことは明らかなので、
//   ハッシュに突っ込む前に中心の個数を先にチェックすべき (かもしれない)

map<string, ll> HASHMAP;
ll cntPattern = 1; // you must write in main: cntPattern = 1;

template <typename T>
ll getHash(vector< vector< Edge<T> > > &G, int point, int parent = -1) {
    // leaf
    if(G[point].size() == 1 && parent != -1)
        return HASHMAP["0"] = 1;

    vector<string> rec;
    for(size_t i=0; i<G[point].size(); i++) {
        int to = G[point][i].to;
        if(to == parent) continue;
        ll temp = getHash(G, to, point);
        rec.push_back(to_string(temp));
    }
    sort(rec.begin(), rec.end());
    string pat = "";
    for(size_t i=0; i<rec.size(); i++) pat += rec[i];
    if(!HASHMAP.count(pat)) HASHMAP[pat] = ++cntPattern;
    return HASHMAP[pat];
}

```

[トップページに戻る](../index.html)
