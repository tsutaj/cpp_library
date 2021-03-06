// F(i) := P (mod 1) + P (mod 2) + ... + P (mod i) を計算
// 答えは NumType 型で返ってくる
template <typename NumType, int K = 10000000>
struct RemainderSum {
    using lint = long long;
    lint P;
    vector<NumType> small_case;
    RemainderSum(lint P_) {
        P = P_;
        build();
    }

    // 小さいケースに対する答えを覚える
    void build() {
        small_case.resize(K + 1, NumType(0));
        for(lint i=1; i<=K; i++) {
            NumType mod(P % i);
            small_case[i] = small_case[i-1] + mod;
        }
    }

    // [1, x] (閉区間であることに注意！！)
    // F(x) を計算 
    NumType sum_func(lint x) {
        if(x <= K) return small_case[x];
        return small_case[K] + sum_func(K+1, x);
    }

    // [l, r] (閉区間であることに注意！！)
    // P (mod l) + P (mod l+1) + ... + P (mod r) を計算
    NumType sum_func(lint l, lint r) {
        if(r <= K) return small_case[r] - small_case[l-1];
        if(l <= K) return small_case[K] - small_case[l-1] + sum_func(K+1, r);

        NumType ans(0);
        // l も r も、 K を超える値である
        lint dmax = P / l, dmin = P / r, num = l;
        for(lint div=dmax; div>=dmin; div--) {
            if(div == 0) {
                // 商が div になるような要素のインデックス (閉区間)
                lint idx_l = max(l, P + 1);
                lint idx_r = r;
                NumType range(idx_r - idx_l + 1);

                // このときの剰余の値は全て P に等しい
                NumType sum = range * NumType(P);
                ans += sum;
            }
            else {
                // 商が div になるような要素のインデックス (閉区間)
                lint idx_l = max(l, P / (div + 1) + 1);
                lint idx_r = min(r, P / div);
                NumType range(idx_r - idx_l + 1);
                
                // 左端と右端について、その剰余の値
                NumType mod_l(P % idx_l);
                NumType mod_r(P % idx_r);
                
                // 等差数列の和
                NumType sum = range * (mod_l + mod_r) / NumType(2);
                ans += sum;
                
                // 次の div を求める (1 ずつ減らない場合がある)
                if(P / num != P / (num + 1)) {
                    div = P / (num + 1) + 1;
                    num++;
                }
            }
        }
        return ans;
    }
};
