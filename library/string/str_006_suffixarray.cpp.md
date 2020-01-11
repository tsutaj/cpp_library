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


# :x: Suffix Array: $O(N \log N)$ <small>(string/str_006_suffixarray.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/str_006_suffixarray.cpp">View this file on GitHub</a>
    - Last commit date: 2020-01-11 16:25:32+09:00


* dummy は、t のどの要素よりも小さい
* get_SA2Str: SA 配列の idx 番目は元の文字列の何番目？
* get_Str2SA: 元の文字列の idx 番目は SA 配列の何番目？
* get_LCP: SA 配列上の idx, idx+1 番目の要素の LCP はいくらか？
* SA 配列上の、パターン文字列を超える最小インデックス: $O(|T| \log |S|)$
* SA 配列上の、パターン文字列未満最大インデックス: $O(|T| \log |S|)$
* LCP (SA 配列上の i 番目と i+1 番目の最長共通接頭辞): $O(|S|)$
* 文字列検索: $O(|T| \log |S|)$


## Verified with

* :x: <a href="../../verify/verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp.html">verifying_test/AOJ/ALDS1_14_B/SuffixArray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
// @brief Suffix Array: $O(N \log N)$
template <typename ArrayTp, typename ElemTp>
struct SuffixArray {
private:
    ArrayTp s;
    vector<int> cmp_s;
    ElemTp dummy;
    vector<int> rec, rev, lcp, cnt;
    int len, sigma;

public:
    // @brief dummy は、t のどの要素よりも小さい
    SuffixArray(ArrayTp s_, ElemTp dummy_ = '$') : s(s_), dummy(dummy_) {
        s.push_back(dummy);
        len = s.size();

        vector<ElemTp> seq;
        for(const auto& e : s) seq.emplace_back(e);
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        sigma = seq.size();

        for(const auto &e : s) cmp_s.emplace_back(lower_bound(seq.begin(), seq.end(), e) - seq.begin());

        rec = get_Array();
        rev.resize(len);
        for(int i=0; i<len; i++) rev[ rec[i] ] = i;
        lcp = get_LCPArray();
    }

    void dump_array(const vector<int> &indices,
                    const vector<int> &classes) const {
        fprintf(stderr, "# debug\n");
        fprintf(stderr, "# indices:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", indices[i]);
        fprintf(stderr, "\n");
        fprintf(stderr, "# classes:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", classes[i]);
        fprintf(stderr, "\n");
    }
    
    vector<int> get_Array() {
        cnt.resize(len);
        vector<int> indices(len), prev_idx(len);
        vector<int> classes(len), prev_cls(len);
        vector<int> tmp_val(len);

        // k == 0 はカウントソートのみ
        for(int i=0; i<len; i++) {
            cnt[ cmp_s[i] ]++;
        }
        for(int i=1; i<len; i++) {
            cnt[i] += cnt[i-1];
        }
        for(int i=len-1; i>=0; i--) {
            indices[ --cnt[ cmp_s[i] ] ] = i;
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
            for(int i=1; i<len; i++) {
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

    int size() const {
        return rec.size();
    }
    // @brief get_SA2Str: SA 配列の idx 番目は元の文字列の何番目？
    int get_SA2Str(int idx) const {
        assert(0 <= idx and idx < size());
        return rec[idx];
    }
    // @brief get_Str2SA: 元の文字列の idx 番目は SA 配列の何番目？
    int get_Str2SA(int idx) const {
        assert(0 <= idx and idx < size());
        return rev[idx];
    }
    // @brief get_LCP: SA 配列上の idx, idx+1 番目の要素の LCP はいくらか？
    int get_LCP(int idx) const {
        assert(0 <= idx and idx < size());
        return lcp[idx];
    }
    
    // SA 配列上 idx 番目以降の接尾辞は、パターン文字列 p に比べて大きいか？
    bool is_greater(const ArrayTp &p, int idx) const {
        idx = get_SA2Str(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] > p[y]) return true;
            if(s[x] < p[y]) return false;
        }
        return y >= M and x < N;
    }

    // SA 配列上 idx 番目以降の接尾辞は、パターン文字列 p に比べて小さいか？
    bool is_less(const ArrayTp &p, int idx) const {
        idx = get_SA2Str(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] < p[y]) return true;
            if(s[x] > p[y]) return false;
        }
        return x >= N and y < M;
    }

    // @brief SA 配列上の、パターン文字列を超える最小インデックス: $O(|T| \log |S|)$
    // SA 配列上で、p より大きくなる要素であって最小のもの (存在しなければ -1)
    int binary_search_greater(const ArrayTp &p) const {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_greater(p, mid)) ub = mid;
            else lb = mid;
        }

        if(ub == len) return -1;
        return ub;
    }

    // @brief SA 配列上の、パターン文字列未満最大インデックス: $O(|T| \log |S|)$
    // SA 配列上で、p より小さくなる要素であって最大のもの (存在しなければ -1)
    int binary_search_less(const ArrayTp &p) const {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_less(p, mid)) lb = mid;
            else ub = mid;
        }
        if(lb == -1) return -1;
        return lb;
    }

    // @brief LCP (SA 配列上の i 番目と i+1 番目の最長共通接頭辞): $O(|S|)$
    vector<int> get_LCPArray() {
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

    // @brief 文字列検索: $O(|T| \log |S|)$
    // - パターン文字列未満になる場所を特定
    // - 境界についてパターン文字列と一致するか判定
    // - LCP が十分大きい限り順番に降りていく？
    vector<int> match(const ArrayTp &p) const {
        int t = binary_search_less(p) + 1;
        int k = (t < len ? get_SA2Str(t) : len + 1);

        int N = p.size();
        bool match_first = (k+N <= len);
        for(int i=0; i<N and match_first; i++) match_first &= (p[i] == s[k+i]);
        if(!match_first) return {};

        vector<int> res;
        while(t < len) {
            res.emplace_back(get_SA2Str(t));
            if(get_LCP(t) < static_cast<int>(p.size())) break;
            t++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "string/str_006_suffixarray.cpp"
// @brief Suffix Array: $O(N \log N)$
template <typename ArrayTp, typename ElemTp>
struct SuffixArray {
private:
    ArrayTp s;
    vector<int> cmp_s;
    ElemTp dummy;
    vector<int> rec, rev, lcp, cnt;
    int len, sigma;

public:
    // @brief dummy は、t のどの要素よりも小さい
    SuffixArray(ArrayTp s_, ElemTp dummy_ = '$') : s(s_), dummy(dummy_) {
        s.push_back(dummy);
        len = s.size();

        vector<ElemTp> seq;
        for(const auto& e : s) seq.emplace_back(e);
        sort(seq.begin(), seq.end());
        seq.erase(unique(seq.begin(), seq.end()), seq.end());
        sigma = seq.size();

        for(const auto &e : s) cmp_s.emplace_back(lower_bound(seq.begin(), seq.end(), e) - seq.begin());

        rec = get_Array();
        rev.resize(len);
        for(int i=0; i<len; i++) rev[ rec[i] ] = i;
        lcp = get_LCPArray();
    }

    void dump_array(const vector<int> &indices,
                    const vector<int> &classes) const {
        fprintf(stderr, "# debug\n");
        fprintf(stderr, "# indices:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", indices[i]);
        fprintf(stderr, "\n");
        fprintf(stderr, "# classes:");
        for(int i=0; i<len; i++) fprintf(stderr, " %d", classes[i]);
        fprintf(stderr, "\n");
    }
    
    vector<int> get_Array() {
        cnt.resize(len);
        vector<int> indices(len), prev_idx(len);
        vector<int> classes(len), prev_cls(len);
        vector<int> tmp_val(len);

        // k == 0 はカウントソートのみ
        for(int i=0; i<len; i++) {
            cnt[ cmp_s[i] ]++;
        }
        for(int i=1; i<len; i++) {
            cnt[i] += cnt[i-1];
        }
        for(int i=len-1; i>=0; i--) {
            indices[ --cnt[ cmp_s[i] ] ] = i;
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
            for(int i=1; i<len; i++) {
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

    int size() const {
        return rec.size();
    }
    // @brief get_SA2Str: SA 配列の idx 番目は元の文字列の何番目？
    int get_SA2Str(int idx) const {
        assert(0 <= idx and idx < size());
        return rec[idx];
    }
    // @brief get_Str2SA: 元の文字列の idx 番目は SA 配列の何番目？
    int get_Str2SA(int idx) const {
        assert(0 <= idx and idx < size());
        return rev[idx];
    }
    // @brief get_LCP: SA 配列上の idx, idx+1 番目の要素の LCP はいくらか？
    int get_LCP(int idx) const {
        assert(0 <= idx and idx < size());
        return lcp[idx];
    }
    
    // SA 配列上 idx 番目以降の接尾辞は、パターン文字列 p に比べて大きいか？
    bool is_greater(const ArrayTp &p, int idx) const {
        idx = get_SA2Str(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] > p[y]) return true;
            if(s[x] < p[y]) return false;
        }
        return y >= M and x < N;
    }

    // SA 配列上 idx 番目以降の接尾辞は、パターン文字列 p に比べて小さいか？
    bool is_less(const ArrayTp &p, int idx) const {
        idx = get_SA2Str(idx);
        int N = size(), M = p.size(), x, y;
        for(x=idx, y=0; x<N and y<M; x++, y++) {
            if(s[x] < p[y]) return true;
            if(s[x] > p[y]) return false;
        }
        return x >= N and y < M;
    }

    // @brief SA 配列上の、パターン文字列を超える最小インデックス: $O(|T| \log |S|)$
    // SA 配列上で、p より大きくなる要素であって最小のもの (存在しなければ -1)
    int binary_search_greater(const ArrayTp &p) const {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_greater(p, mid)) ub = mid;
            else lb = mid;
        }

        if(ub == len) return -1;
        return ub;
    }

    // @brief SA 配列上の、パターン文字列未満最大インデックス: $O(|T| \log |S|)$
    // SA 配列上で、p より小さくなる要素であって最大のもの (存在しなければ -1)
    int binary_search_less(const ArrayTp &p) const {
        int lb = -1, ub = len;
        while(ub - lb > 1) {
            int mid = (ub + lb) / 2;
            if(is_less(p, mid)) lb = mid;
            else ub = mid;
        }
        if(lb == -1) return -1;
        return lb;
    }

    // @brief LCP (SA 配列上の i 番目と i+1 番目の最長共通接頭辞): $O(|S|)$
    vector<int> get_LCPArray() {
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

    // @brief 文字列検索: $O(|T| \log |S|)$
    // - パターン文字列未満になる場所を特定
    // - 境界についてパターン文字列と一致するか判定
    // - LCP が十分大きい限り順番に降りていく？
    vector<int> match(const ArrayTp &p) const {
        int t = binary_search_less(p) + 1;
        int k = (t < len ? get_SA2Str(t) : len + 1);

        int N = p.size();
        bool match_first = (k+N <= len);
        for(int i=0; i<N and match_first; i++) match_first &= (p[i] == s[k+i]);
        if(!match_first) return {};

        vector<int> res;
        while(t < len) {
            res.emplace_back(get_SA2Str(t));
            if(get_LCP(t) < static_cast<int>(p.size())) break;
            t++;
        }
        sort(res.begin(), res.end());
        return res;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

