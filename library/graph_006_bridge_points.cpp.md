<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# graph\_006\_bridge\_points.cpp
---

## Code

```cpp
// 関節点を求める (artPoints)
// 橋を求める (bridges)
// 二重辺連結成分分解をする (BICC)

// 関節点は、取り除いたときに連結でなくなってしまうような頂点のこと
// 橋は、取り除いた時に連結でなくなってしまうような辺のこと

template <typename T>
struct graphLink {
    vector<int> ord, low, parent, cmp;
    vector< vector< Edge<T> > > G, H;

    // 橋の情報 (first < second となるように格納)
    vector< pair<int, int> > bridges;
    int cnt, v;

    // init
    graphLink(vector< vector< Edge<T> > > &S, int root=0) {
        int n = S.size();
        ord.resize(n, -1), low.resize(n, 0),
        parent.resize(n, -1), cmp.resize(n, -1);
        cnt = 0, v = n;
        G = S;
        dfs(root);
    }

    // 橋であるかの判定
    bool is_bridge(int x, int y) {
        if(ord[x] > ord[y]) swap(x, y);
        return ord[x] < low[y];
    }

    // dfs 木の作成と橋の列挙 (初期化と同時にやる)
    // usage: dfs(root);
    void dfs(int cur, int prev=-1) {
        low[cur] = cnt;
        ord[cur] = cnt++;

        for(auto x : G[cur]) {
            if(x.to == prev) continue;
            if(ord[x.to] < 0) {
                parent[x.to] = cur;
                dfs(x.to, cur);

                low[cur] = min(low[cur], low[x.to]);
            }
            else {
                low[cur] = min(low[cur], ord[x.to]);
            }
            if(is_bridge(cur, x.to)) {
                int a = min(cur, x.to);
                int b = max(cur, x.to);
                bridges.emplace_back(make_pair(a, b));
            }
        }
    }

    // 関節点を求める (root は dfs 木の root と一致させる)
    // root は子を 2 つ持っていれば関節点になる
    // それ以外の頂点に関しては ord[parent] <= low[i] のとき関節点になる
    // (lowlink でも親より深さが低い頂点にたどり着けないため)
    set<int> artPoints(int root) {
        set<int> se;
        int num = 0;
        for(int i=0; i<v; i++) {
            if(parent[i] < 0) continue;
            if(parent[i] == root) num++;
            else if(ord[parent[i]] <= low[i]) se.insert(parent[i]);
        }
        if(num >= 2) se.insert(0);
        return se;
    }

    // 二重辺連結成分分解 (橋となる辺を使わないように DFS)
    // Verified: AtCoder Regular Contest D: 旅行会社高橋君
    void BICC() {
        int k = 0;
        // point, number
        stack<pii> S;
        for(int i=0; i<v; i++) {
            if(cmp[i] >= 0) continue;
            cmp[i] = k;
            S.push(make_pair(i, k++));
            while(!S.empty()) {
                pii cur = S.top(); S.pop();
                for(auto x : G[cur.first]) {
                    if(cmp[x.to] >= 0) continue;
                    if(is_bridge(cur.first, x.to)) continue;
                    cmp[x.to] = cur.second;
                    S.push(make_pair(x.to, cmp[x.to]));
                }
            }
        }

        set< pair<int, int> > edge_set;
        H.resize(k);
        for(int i=0; i<v; i++) {
            for(auto x : G[i]) {
                int ca = cmp[i], cb = cmp[x.to];
                if(ca == cb) continue;
                if(ca > cb) swap(ca, cb);
                if(edge_set.count(make_pair(ca, cb))) continue;
                edge_set.insert(make_pair(ca, cb));
                H[ca].push_back(Edge<T>(cb, 1));
                H[cb].push_back(Edge<T>(ca, 1));
            }
        }
    }
};
```

[トップページに戻る](../index.html)
