---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: marathon/chokudai_search.cpp
    title: "chokudai \u30B5\u30FC\u30C1"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/interval_heap/0001_init.test.cpp
    title: verifying_test/AOJ/interval_heap/0001_init.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/interval_heap/0001_init_rev.test.cpp
    title: verifying_test/AOJ/interval_heap/0001_init_rev.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/interval_heap/0001_push.test.cpp
    title: verifying_test/AOJ/interval_heap/0001_push.test.cpp
  - icon: ':heavy_check_mark:'
    path: verifying_test/AOJ/interval_heap/0001_push_rev.test.cpp
    title: verifying_test/AOJ/interval_heap/0001_push_rev.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"marathon/interval_heap.cpp\"\ntemplate <typename Tp>\nclass\
    \ IntervalHeap {\n   public:\n    template <class Iterator>\n    IntervalHeap(Iterator\
    \ first, Iterator last) : data_(first, last) {\n        make_heap();\n    }\n\
    \    IntervalHeap() = default;\n\n    size_t size() const { return data_.size();\
    \ }\n    void clear() { data_.clear(); }\n    void emplace(const Tp& val) {\n\
    \        data_.push_back(val);\n        up(size() - 1);\n    }\n    void push(const\
    \ Tp& val) { emplace(val); }\n    const Tp& top_min() const { return data_[size()\
    \ >= 2]; }\n    const Tp& top_max() const { return data_[0]; }\n    void pop_min()\
    \ {\n        if(size() <= 2) {\n            data_.pop_back();\n        } else\
    \ {\n            swap(data_[1], data_.back());\n            data_.pop_back();\n\
    \            const size_t k = down(1);\n            up(k);\n        }\n    }\n\
    \    void pop_max() {\n        if(size() <= 1) {\n            data_.pop_back();\n\
    \        } else {\n            swap(data_[0], data_.back());\n            data_.pop_back();\n\
    \            const size_t k = down(0);\n            up(k);\n        }\n    }\n\
    \n   private:\n    vector<Tp> data_;\n    inline size_t to_k_max(size_t k) { return\
    \ k & ~1; }\n    inline size_t to_k_min(size_t k) { return k | 1; }\n    inline\
    \ size_t get_parent(size_t k, bool is_max) { return (((k >> 1) - 1) & ~1) | (is_max\
    \ ? 0 : 1); }\n\n    size_t down(size_t k) {\n        const size_t s = size();\n\
    \        if(k & 1) {\n            // min heap\n            while(true) {\n   \
    \             const size_t cl = (k << 1) + 1;\n                const size_t cr\
    \ = (k << 1) + 3;\n                if(cl >= s) break;\n                const size_t\
    \ c = (cr >= s || data_[cl] < data_[cr]) ? cl : cr;\n                if(data_[c]\
    \ < data_[k]) {\n                    swap(data_[k], data_[c]);\n             \
    \       k = c;\n                } else {\n                    break;\n       \
    \         }\n            }\n        } else {\n            // max heap\n      \
    \      while(true) {\n                const size_t cl = (k << 1) + 2;\n      \
    \          const size_t cr = (k << 1) + 4;\n                if(cl >= s) break;\n\
    \                const size_t c = (cr >= s || data_[cr] < data_[cl]) ? cl : cr;\n\
    \                if(data_[k] < data_[c]) {\n                    swap(data_[k],\
    \ data_[c]);\n                    k = c;\n                } else {\n         \
    \           break;\n                }\n            }\n        }\n        return\
    \ k;\n    }\n    void up(size_t k, size_t root = 1) {\n        const size_t k_max\
    \ = to_k_max(k);\n        const size_t k_min = to_k_min(k);\n        if(k_min\
    \ < size() && data_[k_max] < data_[k_min]) {\n            swap(data_[k_max], data_[k_min]);\n\
    \            k ^= 1;\n        }\n\n        size_t p;\n        // max heap\n  \
    \      while(root < k && data_[p = get_parent(k, true)] < data_[k]) {\n      \
    \      swap(data_[k], data_[p]);\n            k = p;\n        }\n        // min\
    \ heap\n        while(root < k && data_[k] < data_[p = get_parent(k, false)])\
    \ {\n            swap(data_[k], data_[p]);\n            k = p;\n        }\n  \
    \  }\n    void make_heap() {\n        for(size_t i = size(); i--;) {\n       \
    \     if((i & 1) && data_[i - 1] < data_[i]) {\n                swap(data_[i -\
    \ 1], data_[i]);\n            }\n            size_t k = down(i);\n           \
    \ up(k, i);\n        }\n    }\n};\n"
  code: "template <typename Tp>\nclass IntervalHeap {\n   public:\n    template <class\
    \ Iterator>\n    IntervalHeap(Iterator first, Iterator last) : data_(first, last)\
    \ {\n        make_heap();\n    }\n    IntervalHeap() = default;\n\n    size_t\
    \ size() const { return data_.size(); }\n    void clear() { data_.clear(); }\n\
    \    void emplace(const Tp& val) {\n        data_.push_back(val);\n        up(size()\
    \ - 1);\n    }\n    void push(const Tp& val) { emplace(val); }\n    const Tp&\
    \ top_min() const { return data_[size() >= 2]; }\n    const Tp& top_max() const\
    \ { return data_[0]; }\n    void pop_min() {\n        if(size() <= 2) {\n    \
    \        data_.pop_back();\n        } else {\n            swap(data_[1], data_.back());\n\
    \            data_.pop_back();\n            const size_t k = down(1);\n      \
    \      up(k);\n        }\n    }\n    void pop_max() {\n        if(size() <= 1)\
    \ {\n            data_.pop_back();\n        } else {\n            swap(data_[0],\
    \ data_.back());\n            data_.pop_back();\n            const size_t k =\
    \ down(0);\n            up(k);\n        }\n    }\n\n   private:\n    vector<Tp>\
    \ data_;\n    inline size_t to_k_max(size_t k) { return k & ~1; }\n    inline\
    \ size_t to_k_min(size_t k) { return k | 1; }\n    inline size_t get_parent(size_t\
    \ k, bool is_max) { return (((k >> 1) - 1) & ~1) | (is_max ? 0 : 1); }\n\n   \
    \ size_t down(size_t k) {\n        const size_t s = size();\n        if(k & 1)\
    \ {\n            // min heap\n            while(true) {\n                const\
    \ size_t cl = (k << 1) + 1;\n                const size_t cr = (k << 1) + 3;\n\
    \                if(cl >= s) break;\n                const size_t c = (cr >= s\
    \ || data_[cl] < data_[cr]) ? cl : cr;\n                if(data_[c] < data_[k])\
    \ {\n                    swap(data_[k], data_[c]);\n                    k = c;\n\
    \                } else {\n                    break;\n                }\n   \
    \         }\n        } else {\n            // max heap\n            while(true)\
    \ {\n                const size_t cl = (k << 1) + 2;\n                const size_t\
    \ cr = (k << 1) + 4;\n                if(cl >= s) break;\n                const\
    \ size_t c = (cr >= s || data_[cr] < data_[cl]) ? cl : cr;\n                if(data_[k]\
    \ < data_[c]) {\n                    swap(data_[k], data_[c]);\n             \
    \       k = c;\n                } else {\n                    break;\n       \
    \         }\n            }\n        }\n        return k;\n    }\n    void up(size_t\
    \ k, size_t root = 1) {\n        const size_t k_max = to_k_max(k);\n        const\
    \ size_t k_min = to_k_min(k);\n        if(k_min < size() && data_[k_max] < data_[k_min])\
    \ {\n            swap(data_[k_max], data_[k_min]);\n            k ^= 1;\n    \
    \    }\n\n        size_t p;\n        // max heap\n        while(root < k && data_[p\
    \ = get_parent(k, true)] < data_[k]) {\n            swap(data_[k], data_[p]);\n\
    \            k = p;\n        }\n        // min heap\n        while(root < k &&\
    \ data_[k] < data_[p = get_parent(k, false)]) {\n            swap(data_[k], data_[p]);\n\
    \            k = p;\n        }\n    }\n    void make_heap() {\n        for(size_t\
    \ i = size(); i--;) {\n            if((i & 1) && data_[i - 1] < data_[i]) {\n\
    \                swap(data_[i - 1], data_[i]);\n            }\n            size_t\
    \ k = down(i);\n            up(k, i);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/interval_heap.cpp
  requiredBy:
  - marathon/chokudai_search.cpp
  timestamp: '2025-01-01 22:44:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verifying_test/AOJ/interval_heap/0001_init_rev.test.cpp
  - verifying_test/AOJ/interval_heap/0001_push_rev.test.cpp
  - verifying_test/AOJ/interval_heap/0001_init.test.cpp
  - verifying_test/AOJ/interval_heap/0001_push.test.cpp
documentation_of: marathon/interval_heap.cpp
layout: document
title: Interval Heap
---

ビームサーチや Chokudai Search で使う想定。

偶数インデックスで max-heap を作り、奇数インデックスで min-heap を作る方針で実装している
