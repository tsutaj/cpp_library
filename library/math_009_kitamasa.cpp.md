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
<link rel="stylesheet" href="../css/copy-button.css" />
<script type="text/javascript" src="../js/balloons.js"></script>
<script type="text/javascript" src="../js/copy-button.js"></script>



[トップページに戻る](../index.html)

# :warning: math\_009\_kitamasa.cpp

## Code

```cpp
// Kitamasa 法 (M 項漸化式の K 項目を O(M^2 log K) で求める)
const int LOG_K = 60;
template <typename Type>
struct Kitamasa{
    int M; // 初項の数
    vector<Type> coefficient, first_term; // 係数・初項
    vector< vector<Type> > log_table;
    Type zero, one;

    // 初項とその係数、0 (和の単位元) と 1 (積の単位元) の定義
    Kitamasa(vector<Type> given_co, vector<Type> given_ft, Type given_z, Type given_o) {
        assert(given_co.size() == given_ft.size());
        coefficient = first_term = vector<Type>(1);
        M = (int)given_ft.size();
        copy(given_co.begin(), given_co.end(), back_inserter(coefficient));
        copy(given_ft.begin(), given_ft.end(), back_inserter(first_term));
        zero = given_z, one = given_o;

        log_table = vector< vector<Type> >(LOG_K, vector<Type>(M+1, zero));
        log_table[0][1] = one;
        for(int i=1; i<LOG_K; i++) {
            log_table[i] = add(log_table[i-1], log_table[i-1]);
        }
    }

    vector<Type> shrink(vector<Type> vec) {
        vector<Type> ret_vec(M+1);
        for(int i=2*M; i>=M+1; i--) {
            for(int k=1; k<=M; k++) {
                vec[i-k] = vec[i-k] + (coefficient[k] * vec[i]);
            }
        }
        for(int i=1; i<=M; i++) {
            ret_vec[i] = vec[i];
        }
        return ret_vec;
    }

    vector<Type> add(const vector<Type> &a, const vector<Type> &b) {
        assert(a.size() == M+1 && b.size() == M+1);
        vector<Type> ret_vec(2*M+1);
        for(int i=1; i<=M; i++) {
            for(int j=1; j<=M; j++) {
                ret_vec[i+j] = ret_vec[i+j] + (a[i] * b[j]);
            }
        }
        return shrink(ret_vec);
    }

    // K 項目 (1-indexed) を求める
    Type get_value(ll K) {
        K--; // K 乗を、1 乗と (K-1) 乗に分けて処理
        vector<Type> vec = log_table[0];
        for(int i=0; K>0; i++, K>>=1) {
            if(K & 1) {
                vec = add(vec, log_table[i]);
            }
        }

        Type ret_val = zero;
        for(int i=1; i<=M; i++) {
            ret_val = ret_val + (vec[i] * first_term[i]);
        }
        return ret_val;
    }
};

// 突っ込む構造体の例
// =, +, * を定義し、なおかつデフォルト値を必要とする
struct Number {
    ll num;
    Number() {num = 0;}
    Number(ll a) : num(a) {}
    ll operator=(const Number &b) {
        return num = b.num;
    }
    ll operator+(const Number &b) const {
        return (num + b.num) % MOD;
    }
    ll operator*(const Number &b) const {
        return (num * b.num) % MOD;
    }
};

signed main() {
    int K, N; cin >> K >> N;
    vector<Number> co(K, Number(1)), val(K, Number(1));
    Kitamasa<Number> kt(co, val, Number(0), Number(1));
    cout << kt.get_value(N).num << endl;
    return 0;
}

```

[トップページに戻る](../index.html)
