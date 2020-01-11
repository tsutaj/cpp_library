// @brief KMP 法 (Knuth-Morris-Pratt Algorithm)
template <typename Tp>
struct KMP {
    Tp p; int len;
    vector<int> fail;
    KMP() {}
    KMP(Tp p_) : p(p_), len(p_.size()) {
        // @brief 文字列 $p[0:i-1]$ の接頭辞と接尾辞は最大何文字一致する？ (ただし、$|p[0:i-1]|$ 文字未満のみ考慮)
        // @brief MP 法に比べ、失敗時の遷移が log 回に改善されている
        // @see http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
        fail.resize(len + 1, -1);
        for(int i=0, j=-1; i<len; i++) {
            // その時点で一致しなければ fail[j] 文字以下の一致となる
            // j を fail[j] に変更
            while(j >= 0 and p[j] != p[i]) j = fail[j];
            j++;
            fail[i+1] = (i+1 < len and p[i+1] == p[j] ? fail[j] : j);
        }
    }

    // @brief 文字列 $s$ における $p$ の出現位置 (開始位置) のリスト
    vector<int> match(Tp s) {
        int N = s.size();
        vector<int> occur;
        for(int i=0, k=0; i<N; i++) {
            while(k >= 0 and s[i] != p[k]) k = fail[k];
            if(++k == len) {
                occur.push_back(i-len+1);
                k = fail[k];
            }
        }
        return occur;
    }
};
