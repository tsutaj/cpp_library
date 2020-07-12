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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: graph/graph_009_tpsort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph_009_tpsort.cpp">View this file on GitHub</a>
    - Last commit date: 2019-11-22 21:50:52+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// トポロジカルソート 各種

// 2016/12/27 追記: 有向グラフの閉路検査はトポロジカルソートで容易に行える。
// → 閉路があれば入次数 0 になりえない頂点が存在する
// → トポロジカルソートした結果の vector の size が頂点数と等しくなければ閉路が存在

// Kahnのトポロジカルソートアルゴリズム (Verified: AOJ GRL_4_B: Topological Sort)
template <typename T>
vector<int> tpsort_Kahn(const vector< vector< Edge<T> > > &g) {
    const int V = g.size();
    vector<int> indeg(V, 0);
    stack<int> S;

    for(size_t i=0; i<V; i++) {
        for(size_t j=0; j<g[i].size(); j++) {
            indeg[ g[i][j].to ]++;
        }
    }
    for(int i=0; i<V; i++) {
        if(indeg[i] == 0) S.push(i);
    }
    
    vector<int> ans;
    while(S.size() > 0) {
        int u = S.top(); S.pop();
        ans.push_back(u);
        for(size_t i=0; i<g[u].size(); i++) {
            indeg[ g[u][i].to ]--;
            if(indeg[ g[u][i].to ] ==  0)
                S.push( g[u][i].to );
        }
    }
    return ans;
}

// Tarjanのトポロジカルソートアルゴリズム (Verified: AOJ GRL_4_B: Topological Sort)
template <typename T>
void tpTarjanVisit(const vector< vector< Edge<T> > > &g, int u, vector<bool> &used, vector<int> &ans) {
    if(used[u] == false) {
        used[u] = true;
        for(size_t i=0; i<g[u].size(); i++) 
            tpTarjanVisit(g, g[u][i].to, used, ans);
        ans.push_back(u);
    }
}

template <typename T>
vector<int> tpsort_Tarjan(const vector< vector< Edge<T> > > &g) {
    const int V = g.size();
    vector<bool> used(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++) tpTarjanVisit(g, i, used, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

// bit DP によるトポロジカルソートの組み合わせ列挙 (ABC041 D)

int const MAX_N = 16;
vector<int> p[MAX_N];
ll dp[1 << MAX_N];
int N, M;

// 前から頂点のパターンを決定していき、組み合わせの数を返す
ll dfs(int x) {
    ll &ret = dp[x];
    // すでに値が書き込んであればそれを返す
    if(ret >= 0) return ret;
    // 最後までいったら1通りしかない
    if(x == (1 << N) - 1) return ret = 1;

    ret = 0;
    for(int i=0; i<N; i++) {
        // まだ使ってない頂点を使う
        if(((x >> i) & 1) == 0) {
            bool ng = false;

            // j は p[i] の中の要素
            for(int j : p[i]) {
                // 頂点集合の中に行先がすでにあるということは、
                // トポロジカルソートの一番右になりえない → NG
                if(((x >> j) & 1) == 0) {
                    ng = true;
                    break;
                }
            }
            if(ng) continue;

            // 頂点 i を使ったので、それを含めた集合で dfs する
            ret += dfs(x | (1 << i));
        }
    }
    return ret;
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/graph_009_tpsort.cpp"
// トポロジカルソート 各種

// 2016/12/27 追記: 有向グラフの閉路検査はトポロジカルソートで容易に行える。
// → 閉路があれば入次数 0 になりえない頂点が存在する
// → トポロジカルソートした結果の vector の size が頂点数と等しくなければ閉路が存在

// Kahnのトポロジカルソートアルゴリズム (Verified: AOJ GRL_4_B: Topological Sort)
template <typename T>
vector<int> tpsort_Kahn(const vector< vector< Edge<T> > > &g) {
    const int V = g.size();
    vector<int> indeg(V, 0);
    stack<int> S;

    for(size_t i=0; i<V; i++) {
        for(size_t j=0; j<g[i].size(); j++) {
            indeg[ g[i][j].to ]++;
        }
    }
    for(int i=0; i<V; i++) {
        if(indeg[i] == 0) S.push(i);
    }
    
    vector<int> ans;
    while(S.size() > 0) {
        int u = S.top(); S.pop();
        ans.push_back(u);
        for(size_t i=0; i<g[u].size(); i++) {
            indeg[ g[u][i].to ]--;
            if(indeg[ g[u][i].to ] ==  0)
                S.push( g[u][i].to );
        }
    }
    return ans;
}

// Tarjanのトポロジカルソートアルゴリズム (Verified: AOJ GRL_4_B: Topological Sort)
template <typename T>
void tpTarjanVisit(const vector< vector< Edge<T> > > &g, int u, vector<bool> &used, vector<int> &ans) {
    if(used[u] == false) {
        used[u] = true;
        for(size_t i=0; i<g[u].size(); i++) 
            tpTarjanVisit(g, g[u][i].to, used, ans);
        ans.push_back(u);
    }
}

template <typename T>
vector<int> tpsort_Tarjan(const vector< vector< Edge<T> > > &g) {
    const int V = g.size();
    vector<bool> used(V, false);
    vector<int> ans;
    for(int i=0; i<V; i++) tpTarjanVisit(g, i, used, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}

// bit DP によるトポロジカルソートの組み合わせ列挙 (ABC041 D)

int const MAX_N = 16;
vector<int> p[MAX_N];
ll dp[1 << MAX_N];
int N, M;

// 前から頂点のパターンを決定していき、組み合わせの数を返す
ll dfs(int x) {
    ll &ret = dp[x];
    // すでに値が書き込んであればそれを返す
    if(ret >= 0) return ret;
    // 最後までいったら1通りしかない
    if(x == (1 << N) - 1) return ret = 1;

    ret = 0;
    for(int i=0; i<N; i++) {
        // まだ使ってない頂点を使う
        if(((x >> i) & 1) == 0) {
            bool ng = false;

            // j は p[i] の中の要素
            for(int j : p[i]) {
                // 頂点集合の中に行先がすでにあるということは、
                // トポロジカルソートの一番右になりえない → NG
                if(((x >> j) & 1) == 0) {
                    ng = true;
                    break;
                }
            }
            if(ng) continue;

            // 頂点 i を使ったので、それを含めた集合で dfs する
            ret += dfs(x | (1 << i));
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
