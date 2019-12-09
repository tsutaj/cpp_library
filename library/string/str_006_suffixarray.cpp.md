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


# :warning: string/str_006_suffixarray.cpp
* category: string


[Back to top page](../../index.html)



## Code
{% raw %}
```cpp
// O(n log n) で構築するやつ
// ・getIdx(i) := Suffix を辞書順に並べたときに i 番目に来るものは、元の文字列で何番目のインデックスからはじめた Suffix か？
// ・getLCP(i) := SuffixArray 上で i 番目と i+1 番目の要素の最長共通接頭辞はいくらか？
// ・is_greater: 辞書順 i 番目の Suffix がパターン文字列より大きいか見る
// ・is_less: 辞書順 i 番目の Suffix がパターン文字列より小さいか見る
// ・binary_search_greater: パターン文字列より大きい Suffix でインデックス最小のもの
// ・binary_search_less: パターン文字列より小さい Suffix でインデックス最小のもの
const int ALPH = 256;
struct SuffixArray {
private:
    string s;
    vector<int> rec, lcp, cnt;
    int len, cnt_size;
public:
    SuffixArray(string s_) : s(s_) {
        s += "$"; // 辞書順で最も小さいダミー文字
        len = s.length();
        cnt_size = max(ALPH, len); cnt.resize(cnt_size);
        rec = getArray();
        lcp = getLCPArray();
    }

    void dump_array(vector<int> &indices, vector<int> &classes) {
        fprintf(stderr, "# debug\n");
        fprintf(stderr, "# indices:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", indices[i]);
        fprintf(stderr, "\n");
        fprintf(stderr, "# classes:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", classes[i]);
        fprintf(stderr, "\n");
    }
    
    vector<int> getArray() {
        vector<int> indices(len), prev_idx(len);
        vector<int> classes(len), prev_cls(len);
        vector<int> tmp_val(len);

        // k == 0 はカウントソートのみ
        for(int i=0; i<len; i++) {
            cnt[ s[i] ]++;
        }
        for(int i=1; i<cnt_size; i++) {
            cnt[i] += cnt[i-1];
        }
        for(int i=len-1; i>=0; i--) {
            indices[ --cnt[ s[i] ] ] = i;
        }
        for(int i=1; i<len; i++) {
            int pena = (s[ indices[i] ] != s[ indices[i-1] ]);
            classes[ indices[i] ] = classes[ indices[i-1] ] + pena;
        }
        
        for(int k=0; (1 << k) < len; k++) {
            swap(indices, prev_idx);
            swap(classes, prev_cls);
            for(int i=0; i<len; i++) {
                // 後半だけソート済みにしたものを indices に代入
                prev_idx[i] = prev_idx[i] - (1 << k);
                if(prev_idx[i] < 0) prev_idx[i] += len;
                tmp_val[i] = prev_cls[ prev_idx[i] ];
            }

            // 前半についてカウントソート
            fill(cnt.begin(), cnt.end(), (int)0);
            for(int i=0; i<len; i++) {
                cnt[ tmp_val[i] ]++;
            }
            for(int i=1; i<cnt_size; i++) {
                cnt[i] += cnt[i-1];
            }
            for(int i=len-1; i>=0; i--) {
                indices[ --cnt[ tmp_val[i] ] ] = prev_idx[i];
            }
            classes[ indices[0] ] = 0;
            for(int i=1; i<len; i++) {
                int shift = (1 << k);
                pair<int, int> pre(prev_cls[ indices[i-1] ], prev_cls[ (indices[i-1] + shift) % len ]);
                pair<int, int> cur(prev_cls[ indices[i  ] ], prev_cls[ (indices[i  ] + shift) % len ]);
                int pena = (pre != cur);
                classes[ indices[i] ] = classes[ indices[i-1] ] + pena;
            }
        }
        return indices;
    }

    int size() {
        return rec.size();
    }
    // Suffix を辞書順に並べたときに idx 番目に来るものは、元の文字列で何番目のインデックスからはじめた Suffix か？
    int getIdx(int idx) {
        assert(0 <= idx and idx < size());
        return rec[idx];
    }
    // SuffixArray 上で idx 番目と idx+1 番目の要素の最長共通接頭辞はいくらか？
    int getLCP(int idx) {
        assert(0 <= idx and idx < size());
        return lcp[idx];
    }
    
    // 元の文字列の idx 番目以降の接尾辞は、パターン文字列 p に比べて大きいか？
    bool is_greater(string &p, int idx) {
        idx = getIdx(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] > p[y]) return true;
            if(s[x] < p[y]) return false;
        }
        return y >= M and x < N;
    }

    // 元の文字列の idx 番目以降の接尾辞は、パターン文字列 p に比べて小さいか？
    bool is_less(string &p, int idx) {
        idx = getIdx(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] < p[y]) return true;
            if(s[x] > p[y]) return false;
        }
        return x >= N and y < M;
    }
    
    // SA 配列上で、p より大きくなる要素であって最小のもの
    // そのような要素が存在しなければ -1
    int binary_search_greater(string &p) {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_greater(p, mid)) ub = mid;
            else lb = mid;
        }

        if(ub == len) return -1;
        return ub;
    }

    // SA 配列上で、p より小さくなる要素であって最大のもの
    // そのような要素が存在しなければ -1
    int binary_search_less(string &p) {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_less(p, mid)) lb = mid;
            else ub = mid;
        }
        if(lb == -1) return -1;
        return lb;
    }

    // LCP[i] := SA 配列上の i 番目と i+1 番目の最長共通接頭辞
    vector<int> getLCPArray() {
        vector<int> rank(len);
        for(int i=0; i<len; i++) {
            rank[ rec[i] ] = i;
        }

        vector<int> res(len, -1);
        int cons = 0;
        // 空文字列に関しては探索しない！
        for(int i=0; i+1<len; i++) {
            // i 文字目から始まる接尾辞に対して
            // SA 配列上で直前の要素をもってくる
            int pre = rec[ rank[i] - 1 ], cur = i;

            while(s[cur + cons] == s[pre + cons]) cons++;
            res[ rank[i] - 1 ] = cons;
            cons = max<int>(0, cons - 1);
        }
        return res;
    }
};

/*
// Suffix Array: 構築 O(|S| log^2 |S|)
// 蟻本の実装と多分同じ
struct SuffixArray {
    int N, k;
    vector<int> rank, sa;
    string s;

    SuffixArray(string t) {
        s = t, k = 1, N = t.length();
        rank = sa = vector<int>(N+1);
        build();
    }

    bool compare_sa(int i, int j) {
        if(rank[i] != rank[j]) return rank[i] < rank[j];
        else {
            int vi = (i+k <= N ? rank[i+k] : -1);
            int vj = (j+k <= N ? rank[j+k] : -1);
            return vi < vj;
        }
    }

    void build() {
        for(int i=0; i<=N; i++) {
            sa[i] = i;
            rank[i] = (i < N ? s[i] : -1);
        }

        for(k=1; k<=N; k*=2) {
            sort(sa.begin(), sa.end(), [&](int i, int j) {
                return compare_sa(i, j);
            });

            vector<int> tmp(N+1, 0);
            tmp[ sa[0] ] = 0;
            for(int i=1; i<=N; i++) {
                tmp[ sa[i] ] = tmp[ sa[i-1] ] + (compare_sa(sa[i-1], sa[i]) ? 1 : 0);
            }

            swap(rank, tmp);
        }
    }

    string get_substr(int idx) {
        return s.substr(sa[idx]);
    }

    void output() {
        for(int i=0; i<=N; i++) {
            fprintf(stderr, "idx = %3d, str = %s\n", i, get_substr(i).c_str());
        }
    }

    int operator[](int idx) const {
        return sa[idx];
    }
};
*/

```
{% endraw %}

[Back to top page](../../index.html)

