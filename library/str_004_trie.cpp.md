<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript"
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML">
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

# :warning: str\_004\_trie.cpp

## Code

```cpp
// トライ木
// Vefiried: 天下一プログラマーコンテスト 2016 本戦 C: たんごたくさん

template <int char_size>
struct trie_node {
    int nxt_node[char_size];
    size_t child;
    vector<int> accept;

    trie_node() : child(0), accept() {
        fill(nxt_node, nxt_node + char_size, -1);
    }
    size_t size() const { return child + accept.size(); }
};

template <int char_size, int margin>
struct trie {
    using node = trie_node<char_size>;
    vector<node> nodes;
    int root;

    void terminate(int node_idx, int id) {
        nodes[node_idx].accept.emplace_back(id);
    }

    void add(const string &s, int node_idx, size_t str_idx, int id) {
        if(str_idx == s.size()) {
            terminate(node_idx, id);
        }
        else {
            nodes[node_idx].child++;         
            const int c = s[str_idx] - margin;
            if(nodes[node_idx].nxt_node[c] == -1) {
                nodes[node_idx].nxt_node[c] = nodes.size();
                nodes.emplace_back(node());
            }
            add(s, nodes[node_idx].nxt_node[c], str_idx + 1, id);
        }
    }

    void query(const string &s, function< void(int) > &f,
               int node_idx, int str_idx, bool only_complete_match) {
        if(str_idx == s.size() or !only_complete_match) {
            for(auto k : nodes[node_idx].accept) f(k);
        }
        if(str_idx == s.size()) return;
        const int c = s[str_idx] - margin;
        if(nodes[node_idx].nxt[c] == -1) return;
        query(s, f, nodes[node_idx].nxt[c], str_idx + 1, only_complete_match);
    }
    
    trie() : root(0) {
        nodes.emplace_back(node());
    }

    // 文字列の追加 O(|S|)
    // 重複による特別扱いはしないので、複数回入れたら複数回反映される
    void add(const string &s, int id) {
        add(s, root, 0, id);
    }

    void add(const string &s) {
        add(s, nodes[root].child);
    }

    // 1-indexed, O(k 番目の文字列の長さ * \sigma) くらい
    string kth_string(size_t k) {
        assert(1 <= k and k <= nodes[root].child);
        int node_idx = root;
        string res = "";
        
        while(k > 0) {
            if(k <= nodes[node_idx].accept.size()) break;
            k -= nodes[node_idx].accept.size();
            for(size_t i=0; i<char_size; i++) {
                int c = nodes[node_idx].nxt_node[i];
                if(c < 0) continue;
                if(nodes[c].size() >= k) {
                    res += (char)(margin + i);
                    node_idx = c;
                    break;
                }
                else {
                    k -= nodes[c].size();
                }
            }
        }
        return res;
    }

    // 文字列 s の prefix に match する文字列それぞれについて、何か作用させる
    // 完全一致しか許さない場合は true も引数に与える
    void query(const string &s, const function< void(int) > &f,
               bool only_complete_match = false) {
        query(s, f, 0, 0, only_complete_match);
    }

    // 登録されている文字列がいくつか
    size_t count() const { return nodes[root].child; }
    // ノード数
    size_t size() const { return nodes.size(); }
};

```

[トップページに戻る](../index.html)
