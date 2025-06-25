---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: marathon/interval_heap.cpp
    title: Interval Heap
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \ up(k, i);\n        }\n    }\n};\n#line 2 \"marathon/chokudai_search.cpp\"\n\n\
    template <class State, class Timer>\nclass ChokudaiSearch {\n   public:\n    ChokudaiSearch()\
    \ : num_iter_(-1) {}\n    void init(int max_turns, double search_time, int time_check_iter)\
    \ {\n        states_.resize(max_turns + 1);\n        search_time_ = search_time;\n\
    \        num_iter_ = 0;\n        time_check_iter_ = time_check_iter;\n       \
    \ max_num_states_.resize(max_turns + 1, 1 << 30);\n    }\n    void set_max_num_states(int\
    \ max_num_state) {\n        fill(max_num_states_.begin(), max_num_states_.end(),\
    \ max_num_state);\n    }\n    void set_max_num_states(const vector<int> &max_num_states)\
    \ {\n        assert(max_num_states.size() == max_num_states_.size());\n      \
    \  max_num_states_ = max_num_states;\n    }\n    void register_state(int turns,\
    \ const State &state) {\n        states_[turns].emplace(state);\n        while(states_[turns].size()\
    \ > max_num_states_[turns]) {\n            states_[turns].pop_max();\n       \
    \ }\n    }\n    size_t size(int turns) const {\n        return states_[turns].size();\n\
    \    }\n    const State& worst_state(int turns) const {\n        assert(states_[turns].size()\
    \ > 0);\n        return states_[turns].top_max();\n    }\n    void search(Timer\
    \ &timer, const auto &add_next_states) {\n        assert(num_iter_ >= 0);\n  \
    \      const double start_time = timer.getTime();\n        for(num_iter_ = 0;;\
    \ num_iter_++) {\n            for(int turns = 0; turns + 1 < (int)states_.size();\
    \ turns++) {\n                if(timer.getTime() - start_time > search_time_)\
    \ {\n                    goto TIME_OVER;\n                }\n                if(states_[turns].size()\
    \ == 0) continue;\n                State state = states_[turns].top_min();\n \
    \               states_[turns].pop_min();\n                add_next_states(turns,\
    \ state);\n            }\n        }\n    TIME_OVER:;\n        fprintf(stderr,\
    \ \"chokudai search: num_iter = %d\\n\", num_iter_);\n    }\n    const State &get_best_state()\
    \ const {\n        if (states_.back().empty()) {\n            throw runtime_error(\"\
    No states are registered.\");\n        }\n        return states_.back().top_min();\n\
    \    }\n\n   private:\n    double search_time_;\n    int num_iter_;\n    int time_check_iter_;\n\
    \    vector<IntervalHeap<State>> states_;\n    vector<int> max_num_states_;\n\
    };\n"
  code: "#include \"interval_heap.cpp\"\n\ntemplate <class State, class Timer>\nclass\
    \ ChokudaiSearch {\n   public:\n    ChokudaiSearch() : num_iter_(-1) {}\n    void\
    \ init(int max_turns, double search_time, int time_check_iter) {\n        states_.resize(max_turns\
    \ + 1);\n        search_time_ = search_time;\n        num_iter_ = 0;\n       \
    \ time_check_iter_ = time_check_iter;\n        max_num_states_.resize(max_turns\
    \ + 1, 1 << 30);\n    }\n    void set_max_num_states(int max_num_state) {\n  \
    \      fill(max_num_states_.begin(), max_num_states_.end(), max_num_state);\n\
    \    }\n    void set_max_num_states(const vector<int> &max_num_states) {\n   \
    \     assert(max_num_states.size() == max_num_states_.size());\n        max_num_states_\
    \ = max_num_states;\n    }\n    void register_state(int turns, const State &state)\
    \ {\n        states_[turns].emplace(state);\n        while(states_[turns].size()\
    \ > max_num_states_[turns]) {\n            states_[turns].pop_max();\n       \
    \ }\n    }\n    size_t size(int turns) const {\n        return states_[turns].size();\n\
    \    }\n    const State& worst_state(int turns) const {\n        assert(states_[turns].size()\
    \ > 0);\n        return states_[turns].top_max();\n    }\n    void search(Timer\
    \ &timer, const auto &add_next_states) {\n        assert(num_iter_ >= 0);\n  \
    \      const double start_time = timer.getTime();\n        for(num_iter_ = 0;;\
    \ num_iter_++) {\n            for(int turns = 0; turns + 1 < (int)states_.size();\
    \ turns++) {\n                if(timer.getTime() - start_time > search_time_)\
    \ {\n                    goto TIME_OVER;\n                }\n                if(states_[turns].size()\
    \ == 0) continue;\n                State state = states_[turns].top_min();\n \
    \               states_[turns].pop_min();\n                add_next_states(turns,\
    \ state);\n            }\n        }\n    TIME_OVER:;\n        fprintf(stderr,\
    \ \"chokudai search: num_iter = %d\\n\", num_iter_);\n    }\n    const State &get_best_state()\
    \ const {\n        if (states_.back().empty()) {\n            throw runtime_error(\"\
    No states are registered.\");\n        }\n        return states_.back().top_min();\n\
    \    }\n\n   private:\n    double search_time_;\n    int num_iter_;\n    int time_check_iter_;\n\
    \    vector<IntervalHeap<State>> states_;\n    vector<int> max_num_states_;\n\
    };\n"
  dependsOn:
  - marathon/interval_heap.cpp
  isVerificationFile: false
  path: marathon/chokudai_search.cpp
  requiredBy: []
  timestamp: '2025-06-25 11:24:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/chokudai_search.cpp
layout: document
title: "chokudai \u30B5\u30FC\u30C1"
---

- `add_next_states` で状態遷移を定義する
    - 状態およびそのターン数が与えられるので、次の状態およびそのターン数を決定し、 `register_state` を使って状態を登録
- メモリ制約に引っかからないように、各ターンで持つ状態数に上限を設けることが可能
    - `set_max_num_states` で設定する
    - Interval Heap を使って、あふれた状態を消している

AHC032 で利用実績あり。  
[https://atcoder.jp/contests/ahc032/submissions/61302590](https://atcoder.jp/contests/ahc032/submissions/61302590)
