[トップページに戻る](../index.html)

# graph\_021\_centroid.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

```cpp
// 木の重心列挙 O(N)
// 重心を一つ求める O(N) (列挙よりも高速)
// 重心分解する

#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
using Graph = vector< vector<int> >;
const long long int MOD = 1000000007;

// 木の重心を列挙する
// 重心 v → v を根とした時に、 v の子を根とする部分木のサイズが全て N/2 以下である
// DFS をすることで容易に判定可能 O(N)
vector<int> treeCentroid(Graph &G) {
    int N = G.size();
    vector<int> centroid, val(N);
    function<void (int, int)> dfs = [&](int cur, int par) {
        bool is_centroid = true;
        val[cur] = 1;
        for(auto to : G[cur]) {
            if(to == par) continue;
            dfs(to, cur);
            val[cur] += val[to];
            if(val[to] > N / 2) is_centroid = false;
        }
        if(N - val[cur] > N / 2) is_centroid = false;
        if(is_centroid) centroid.push_back(cur);
    };

    dfs(0, -1);
    return centroid;
}

// 部分木の重心をひとつ求める (通行できない頂点は dead で管理)
// 子を根としたときの部分木のサイズが N/2 を超えていれば、その子を新たに根として探索
int oneCentroid(Graph &G, int root, vector<bool> &dead) {
    // 毎回確保すると遅いので必ず static にしよう
    static vector<int> val((int)G.size());
    function<void (int, int)> get_size = [&](int cur, int par) {
        val[cur] = 1;
        for(auto to : G[cur]) {
            if(to == par || dead[to]) continue;
            get_size(to, cur);
            val[cur] += val[to];
        }
    };

    get_size(root, -1);
    int N = val[root];
    function<int (int, int)> dfs = [&](int cur, int par) {
        for(auto to : G[cur]) {
            if(to == par || dead[to]) continue;
            if(val[to] > N / 2) return dfs(to, cur);
        }
        return cur;
    };
    return dfs(root, -1);
}

int calc_pairs(vector<int> &paths, int k) {
    sort(paths.begin(), paths.end());

    int N = paths.size(), idx = N - 1, ans = 0;
    for(int i=0; i<N; i++) {
        while(idx >= 0 && paths[i] + paths[idx] > k) idx--;
        ans += (idx + 1) - (idx >= i ? 1 : 0);
    }
    return ans / 2;
}

// 重心分解テンプレート
int centroidDecomposition(Graph &G, int k) {
    int N = G.size();

    // 切られた場所
    vector<bool> dead(N, false);

    int ans = 0;
    function<void (int)> rec = [&](int root) {
        int c = oneCentroid(G, root, dead);
        dead[c] = true; // 重心となる頂点で木を分割する

        // 重心で切ったときにできる部分木に対して値を求める
        for(auto to : G[c]) {
            if(dead[to]) continue;
            rec(to);
        }

        // 重心と部分木を使ってマージ
        // 下では、長さ k 以下のパスの数を求めている

        /*
        vector<int> whole_paths;
        whole_paths.push_back(0);
        for(auto to : G[c]) {
            if(dead[to]) continue;
            vector<int> paths;
            function<void (int, int, int)> enumerate_paths = [&](int cur, int pre, int dist) {
                paths.push_back(dist);
                for(auto nxt : G[cur]) {
                    if(nxt == pre || dead[nxt]) continue;
                    enumerate_paths(nxt, cur, dist + 1);
                }
            };
            enumerate_paths(to, c, 1);
            ans -= calc_pairs(paths, k);
            ans += calc_pairs(paths, k-1);
            whole_paths.insert(whole_paths.end(), paths.begin(), paths.end());
        }
        ans += calc_pairs(whole_paths, k);
        ans -= calc_pairs(whole_paths, k-1);
        */

        dead[c] = false; // 再帰なので抜けるときはもとに戻す
    };
    rec(0);
    return ans;
}

int main() {
    int N, K; scanf("%d%d", &N, &K);

    Graph G(N);
    for(int i=0; i<N-1; i++) {
        int u, v; scanf("%d%d", &u, &v);
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    long long int val = centroidDecomposition(G, K);
    // cout << "val: " << val << endl;
    long long int mul = ((long long int)K * (K+1) / 2) % MOD;
    printf("%lld\n", (val * mul) % MOD);
    return 0;
}```

[トップページに戻る](../index.html)
