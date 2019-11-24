<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: graph\_019\_eulertour.cpp

## Code

```cpp
// Euler-tour (Verified: Codeforces Round #225 Div.1: Propagating Tree)
// 頂点 i を根とした部分木の情報は [ etbegin[i], etend[i] ) を参照
constexpr int MAXN = 200010;
vector<int> G[MAXN];
int k=0, euler_tour[2*MAXN], etbegin[MAXN], etend[MAXN];

// usage: make_et(root)
void make_et(int v, int par=-1) {
    euler_tour[k] = v;
    etbegin[v] = k++;
    for(size_t i=0; i<G[v].size(); i++) {
        int to = G[v][i];
        if(to == par) continue;
        make_et(to, v);
        euler_tour[k++] = v;
    }
    etend[v] = k;
}
```

[トップページに戻る](../index.html)
