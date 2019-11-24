<!-- Mathjax Support -->
<script type="text/javascript" async
  src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML">
</script>


[トップページに戻る](../index.html)

# :warning: math\_020\_combination.cpp
---

## Code

```cpp
// 各種組み合わせを求めるライブラリ
template <typename NumType>
struct Combination {
    int LIMIT;
    vector<NumType> fact_, finv_;

    Combination() {}
    Combination(int LIMIT_) : LIMIT(LIMIT_), fact_(LIMIT+1), finv_(LIMIT+1) {
        fact_[0] = finv_[LIMIT] = NumType(1);
        for(int i=1; i<=LIMIT; i++) {
            fact_[i] = fact_[i-1] * NumType(i);
        }
        
        finv_[LIMIT] /= fact_[LIMIT];
        for(int i=LIMIT-1; i>=0; i--) {
            finv_[i] = finv_[i+1] * NumType(i+1);
        }
    }

    inline NumType fact(int k) const { return fact_[k]; }
    inline NumType finv(int k) const { return finv_[k]; }
    NumType P(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r];
    }
    NumType C(int n, int r) const {
        if(r < 0 or n < r) return NumType(0);
        return fact_[n] * finv_[n-r] * finv_[r];
    }
    // 重複組み合わせ
    NumType H(int n, int r) const {
        if(n < 0 or r < 0) return NumType(0);
        return r == 0 ? NumType(1) : C(n + r - 1, r);
    }
    // ベル数 (区別できる n 個のボールを区別できない k 個以下の箱に分割)
    // B(n, n) := n 個のボールを任意個のグループに分割する場合の数
    NumType B(int n, int k) const {
        if(n == 0) return NumType(1);
        k = min(n, k);
        NumType ret(0);
        vector<NumType> pref(k + 1); pref[0] = NumType(1);
        for(int i=1; i<=k; i++) {
            if(i & 1) pref[i] = pref[i-1] - finv_[i];
            else pref[i] = pref[i-1] + finv_[i];
        }
        for(int i=1; i<=k; i++) {
            // 累乗が必要なので適宜書き換える？
            // ModInt 使うならこれでいい
            ret += NumType(i).pow(n) * finv_[i] * pref[k-i];
        }
        return ret;
    }
    // スターリング数 (区別できる n 個のボールを区別できない k 個の箱に分割)
    NumType S(int n, int k) const {
        if(n < k) return NumType(0);
        NumType ans(0);
        for(int i=0; i<=k; i++) {
            NumType val = C(k, i) * NumType(i).pow(n);
            if((k - i) % 2) ans -= val;
            else ans += val;
        }
        return ans * finv_[k];
    }

    // ランダムウォーク: 左に X 回、右に Y 回進むとき、
    // 移動途中・終了時に座標 K を超えないものを数える
    // K が非負なら左側、負なら右側領域 (？) のランダムウォーク
    NumType walk(int X, int Y, int K) {
        if(K < 0) return walk(Y, X, -K);
        if(Y <= K) return C(X+Y, X); // 引っかからない
        if(Y - X > K) return NumType(0); // そもそも合計が超える
        
        int A = Y - K - 1, B = X + K + 1;
        return C(X+Y, X) - C(A+B, A);
    }
};

// P(n, k) := n の k 分割 (k 個の 0 以上の整数の和)
template <typename NumType, int LIMIT = 3010>
struct Partition {
    vector< vector<NumType> > dp;
    Partition() : dp(LIMIT, vector<NumType>(LIMIT)) {
        for(int k=0; k<LIMIT; k++) dp[0][k] = NumType(1);
        for(int i=1; i<LIMIT; i++) {
            for(int j=1; j<LIMIT; j++) {
                dp[i][j] += dp[i][j-1];
                if(i-j >= 0) dp[i][j] += dp[i-j][j];
            }
        }
    }
    inline NumType get(int n, int k) {
        if(n < 0 or k < 0) return NumType(0);
        return dp[n][k];
    }
};

```

[トップページに戻る](../index.html)
