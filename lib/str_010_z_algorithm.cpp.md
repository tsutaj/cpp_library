[トップページに戻る](../index.html)

# str\_010\_z\_algorithm.cpp
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
// Z-algorithm
// 各 Suffix と元の文字列との LCP を求める
template <typename ArrayType>
struct Z_algorithm {
    ArrayType v;
    vector<int> Z;

    void build() {
        int N = v.size(), i, j;
        Z = vector<int>(N);

        for(i=1,j=0; i<N; i++) {
            int l = i - j;
            if(i + Z[l] < j + Z[j]) {
                Z[i] = Z[l];
            }
            else {
                int k = max(0, j + Z[j] - i);
                while(i + k < N and v[k] == v[i+k]) k++;
                Z[i] = k;
                j = i;
            }
        }
        Z[0] = N;
    }

    Z_algorithm(ArrayType v_) : v(v_) {
        build();
    }

    // idx から切り出した Suffix と文字列全体との LCP
    int get_lcp(int idx) {
        return Z[idx];
    }
};
```

[トップページに戻る](../index.html)
