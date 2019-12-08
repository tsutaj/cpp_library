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


# :warning: math/math_014_bsgs.cpp
* category: math


[Back to top page](../../index.html)



## Required
* :warning: [math/verify/verify_math_014_bsgs.cpp](verify/verify_math_014_bsgs.cpp.html)


## Code
```cpp
// 離散対数問題 (Discrete Logarithm Problem) を解く
// a^x = b (mod p, p は素数) を満たすような x (1 <= x <= p-1) を求める
template <typename NumType>
struct DiscreteLogarithm {
    unordered_map<NumType, NumType> pow_table_;

    // a と p をコンストラクタで指定すると、pow_table_ が作られる
    DiscreteLogarithm() : pow_table_() {}
    DiscreteLogarithm(NumType a, NumType p, double ratio=0.5) {
        set_rec_table(a, p, ratio);
    }
    
    NumType mod_pow(NumType x, NumType k, NumType p) {
        NumType res = 1;
        for(; k>0; k>>=1) {
            if(k & 1) (res *= x) %= p;
            (x *= x) %= p;
        }
        return res;
    }

    NumType mod_inv(NumType x, NumType p) {
        return mod_pow(x, p-2, p);
    }

    // a^{-s * sqrtp} => s が格納された map を返す
    unordered_map<NumType, NumType> get_rec_table(NumType a, NumType p, double ratio=0.5) {
        unordered_map<NumType, NumType> num_rec;
        NumType sp = pow(p, ratio) + 1;
        NumType tp = pow(p, 1.0 - ratio) + 1;

        // a^{-sqrtp}
        NumType inv_pow_a = mod_inv(mod_pow(a, sp, p), p);

        // a^{-s * sqrtp}
        NumType mul = 1;
        for(NumType s=0; s<=tp; s++) {
            NumType key = mul;
            if(num_rec.count(key)) break;
            num_rec[key] = s;
            (mul *= inv_pow_a) %= p;
        }
        return num_rec;
    }

    // pow_table_ に map をセットする
    void set_rec_table(NumType a, NumType p, double ratio) {
        pow_table_ = get_rec_table(a, p, ratio);
    }

    // Baby-step Giant-step Algorithm: O(sqrt(p)) だが ratio に依存
    // a^{-s * sp} の map は、直前のものを使いまわすこともできる
    // pow_table_ が空の場合、または use_same_table が指定されていない場合は自動的に map が作られ、それが pow_table_ に保存される
    NumType BSGS(NumType a, NumType b, NumType p, bool use_same_table=false, double ratio=0.5) {
        a %= p, b %= p;
        NumType sp = pow(p, ratio) + 1;
        
        // a^{-s * sp} => s
        unordered_map<NumType, NumType> &num_rec = pow_table_;
        if(num_rec.empty() or !use_same_table) {
            set_rec_table(a, p, ratio);
        }
        
        // a^t * b^{-1} = a^{-s * sp}
        // この時の答えは s * sp + t
        NumType mul = mod_inv(b, p);
        for(NumType t=0; t<=sp; t++) {
            if(num_rec.count(mul)) {
                NumType s = num_rec[mul];

                // 解の範囲は 1 以上 p-1 以下なのでそれはチェックが必要
                NumType ans = s * sp + t;
                if(1 <= ans and ans <= p-1) return ans;
            }
            (mul *= a) %= p;
        }

        // 解なし
        return NumType(-1);
    }
};

```

[Back to top page](../../index.html)

