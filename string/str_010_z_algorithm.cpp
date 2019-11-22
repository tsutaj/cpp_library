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
