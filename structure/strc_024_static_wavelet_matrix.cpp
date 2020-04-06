#pragma once

// @title Wavelet 行列 (wavelet matrix)
#define DOCS "./docs/strc_024_static_wavelet_matrix.md"
#include "./strc_023_compact_bitvector.cpp"

// ウェーブレット行列 (Wavelet Matrix)
// w は ビット幅, 30 bit で表現できる整数なら 30
template <uint64_t word_size = 30, typename value_type = int,
          uint64_t ln_big = 10, uint64_t ln_sml = 4>
struct WaveletMatrix {
private:
    using BitVector = CompactBitVector<value_type, ln_big, ln_sml>;
    array<BitVector, word_size> vecs;

    // 要素数
    int n;
    // k ビット目を基準に安定ソート
    vector<value_type> sort_kth_bit(const vector<value_type>& vec, int k) const;

    // [l, r) の範囲内にある x と等しい要素は最下段のどの範囲に相当？
    // select するときに利用
    pair<int, int> rank_range(int l, int r, value_type x) const;    

public:
    // クエリは特に注釈がない限り 0-indexed
    // 構築: O(N w)
    WaveletMatrix(vector<value_type> vec);

    // k 番目の値を復元: O(w)
    // <verified> ITP1_6_A (Reversing Numbers)
    value_type at(int k) const;
    value_type operator[](int k) const;

    // [l, r) の範囲内に以下が何個存在するか: O(w)
    // ・x より小さい要素
    // ・x と等しい要素
    // ・x より大きい要素
    tuple<int, int, int> rank_tuple(int l, int r, value_type x) const;
    tuple<int, int, int> rank_tuple(value_type x) const;
    
    // [l, r) の範囲内で k 番目 (1-indexed) に小さい要素が何か: O(w)
    // <verified> AOJ ALDS1_6_A (Count Sort)
    value_type quantile(int l, int r, value_type mi, value_type ma, int k) const;
    value_type quantile(int l, int r, int k) const;
    value_type quantile(int k) const;

    // [l, r) の範囲内の m 未満 / m を超える 要素はいくつか: O(w)
    // <verified> AOJ ALDS1_5_D (The Number of Inversions)
    int freq_less(int l, int r, value_type m) const;
    int freq_less(value_type m) const;
    int freq_greater(int l, int r, value_type m) const;
    int freq_greater(value_type m) const;
    
    // [l, r) の範囲内に x \in [mi, ma] を満たす x がいくつ出てきたか: O(w)
    // [mi, ma] は閉区間！！
    // <verified> AOJ 1549 (Hard Beans)
    // <verified> AOJ 2426 (Treasure Hunt)
    int freq(int l, int r, value_type mi, value_type ma) const;
    int freq(int l, int r, value_type x) const;
    int freq(value_type mi, value_type ma) const;
    
    // [l, r) の範囲内にある要素の最小値 (quantile 再利用): O(w)
    // <verified> AOJ DSL_3_D (Sliding Minimum Elements)
    value_type min_value(int l, int r, value_type mi, value_type ma) const;
    value_type min_value(int l, int r) const;
    value_type min_value() const;

    // [l, r) の範囲内にある要素の最大値 (quantile 再利用): O(w)
    value_type max_value(int l, int r, value_type mi, value_type ma) const;
    value_type max_value(int l, int r) const;
    value_type max_value() const;

    // [l, r) の範囲内にある k 番目 (1-indexed) の x の位置: O(w log N)
    int select(int l, int r, int k, value_type x) const;
    int select(int k, value_type x) const;

    // k 番目の要素と値が等しいもので、k 番目の直後 / 直前の要素 idx: O(w log N)
    int next_idx(int k) const;
    int prev_idx(int k) const;

    // [l, r) の範囲内にある、x 未満 / x を超える要素のうち 最大 / 最小 であるもの: O(w)
    // <verified> AOJ 1549 (Hard Beans)
    value_type next_val(int l, int r, value_type x) const;
    value_type prev_val(int l, int r, value_type x) const;
};

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
vector<value_type> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::sort_kth_bit(const vector<value_type>& vec, int k) const {
    vector<value_type> v0, v1;
    v0.reserve(vec.size()), v1.reserve(vec.size());
    for(size_t i=0; i<vec.size(); i++) {
        ((vec[i] >> k & 1) ? v1 : v0).emplace_back(vec[i]);
    }
    v0.insert(v0.end(), v1.begin(), v1.end());
    return v0;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
pair<int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_range(int l, int r, value_type x) const {
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return make_pair(l, r);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
WaveletMatrix<word_size, value_type, ln_big, ln_sml>::WaveletMatrix(vector<value_type> vec) : n(vec.size()) {
    vecs[0] = BitVector(vec, word_size - 1);
    for(size_t i=1; i<word_size; i++) {
        vec = sort_kth_bit(vec, word_size - i);
        vecs[i] = BitVector(vec, word_size - i - 1);
    }
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::at(int k) const {
    int b = k; value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(b), cnt0 = b + 1 - cnt1;
        if(vecs[i][b] == 1) {
            res |= (1ULL << (word_size - 1 - i));
            b = all0 + cnt1 - 1;
        }
        else {
            b = cnt0 - 1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::operator[](int k) const {
    return at(k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(int l, int r, value_type x) const {
    int small = 0, equal = 0, big = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(x >> (word_size - i - 1) & 1) {
            small += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            big += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    equal = r - l;
    return make_tuple(small, equal, big);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
tuple<int, int, int> WaveletMatrix<word_size, value_type, ln_big, ln_sml>::rank_tuple(value_type x) const {
    return rank_tuple(0, n, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, value_type mi, value_type ma, int k) const {
    int cnt_less = freq_less(l, r, mi), cnt_greater = freq_greater(l, r, ma);
    if(r - l - cnt_less - cnt_greater < k) return -1;
    return quantile(l, r, k + cnt_less);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int l, int r, int k) const {
    if(r - l < k) return -1;
    value_type res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(cnt0 >= k) {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
        else {
            k -= cnt0;
            res |= 1ULL << (word_size - 1 - i);
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::quantile(int k) const {
    return quantile(0, n, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            res += cnt0;
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_less(value_type m) const {
    return freq_less(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(int l, int r, value_type m) const {
    int res = 0;
    for(size_t i=0; i<word_size; i++) {
        int all1 = vecs[i].rank(n-1), all0 = n - all1;
        int cnt1 = vecs[i].rank(r-1) - vecs[i].rank(l-1), cnt0 = r - l - cnt1;
        if(m >> (word_size - 1 - i) & 1) {
            l = all0 + vecs[i].rank(l-1), r = l + cnt1;
        }
        else {
            res += cnt1;
            l = l - vecs[i].rank(l-1), r = l + cnt0;
        }
    }
    return res;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq_greater(value_type m) const {
    return freq_greater(0, n, m);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type mi, value_type ma) const {
    return r - l - freq_less(l, r, mi) - freq_greater(l, r, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(int l, int r, value_type x) const {
    return freq(l, r, x, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::freq(value_type mi, value_type ma) const {
    return freq(0, n, mi, ma);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value(int l, int r) const {
    return quantile(l, r, 1);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::min_value() const {
    return min_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r, value_type mi, value_type ma) const {
    return quantile(l, r, mi, ma, freq(l, r, mi, ma));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value(int l, int r) const {
    return quantile(l, r, r - l);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::max_value() const {
    return max_value(0, n);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int l, int r, int k, value_type x) const {
    if(k <= 0) return -1;
    tie(l, r) = rank_range(l, r, x);
    if(r - l < k) return -1;

    int pos = l + k - 1;
    for(size_t i=0; i<word_size; i++) {
        int b = x >> i & 1;
        int cnt1 = vecs[word_size - 1 - i].rank(n-1), cnt0 = n - cnt1;
        if(b == 0) {
            int m = pos;
            pos = vecs[word_size - 1 - i].select0(m, n);
        }
        else {
            int m = pos - cnt0;
            pos = vecs[word_size - 1 - i].select1(m, n);
        }
    }
    return pos;
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::select(int k, value_type x) const {
    return select(0, n, k, x);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m+1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
int WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_idx(int k) const {
    int m = freq(0, k+1, at(k));
    return select(m-1, at(k));
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::next_val(int l, int r, value_type x) const {
    int k = r - l - freq_greater(l, r, x) + 1;
    return quantile(l, r, k);
}

template <uint64_t word_size, typename value_type,
          uint64_t ln_big, uint64_t ln_sml>
value_type WaveletMatrix<word_size, value_type, ln_big, ln_sml>::prev_val(int l, int r, value_type x) const {
    return quantile(l, r, freq_less(l, r, x));
}
