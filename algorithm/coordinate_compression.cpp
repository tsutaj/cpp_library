#pragma once

// @brief 座標圧縮 (Coordinate Compression)

#include <vector>
#include <algorithm>
#include <cassert>

template <typename Tp>
struct coor_comp {
private:
    vector<Tp> vec;

public:
    coor_comp() : vec() {}
    coor_comp(int n) : vec() { vec.reserve(n); }
    coor_comp(const vector<Tp> &vec_) : vec(vec_) { build(); }

    size_t size() const {
        return vec.size();
    }
    
    void emplace_back(Tp value) {
        vec.emplace_back(value);
    }

    void build() {
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
    }
       
    int operator[](const Tp &value) const {
        auto itr = lower_bound(vec.begin(), vec.end(), value);
        assert(itr != vec.end() and *itr == value);
        return itr - vec.begin();
    }

    vector<int> compress(const vector<Tp> &A) {
        vector<int> comp_vec(A.size());
        for(size_t i=0; i<A.size(); i++) comp_vec[i] = (*this)[ A[i] ];
        return comp_vec;
    }
};
