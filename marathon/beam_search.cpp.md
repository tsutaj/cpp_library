---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"marathon/beam_search.cpp\"\ntemplate <typename BeamSearchState,\
    \ typename LiteBeamSearchState>\nclass BeamSearchBase {\n   public:\n    BeamSearchBase()\
    \ = default;\n    BeamSearchBase(int beam_width) : beam_width_(beam_width) {}\n\
    \    void set_beam_width(int beam_width) { beam_width_ = beam_width; }\n    void\
    \ register_state(const BeamSearchState &state) { states_.emplace_back(state);\
    \ }\n    virtual void register_lite_state(LiteBeamSearchState &state) = 0;\n \
    \   virtual void search(\n        const function<void(BeamSearchState &)> &add_next_lite_states,\n\
    \        const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)>\
    \ &to_next_state) = 0;\n    const BeamSearchState &get_best_state() const {\n\
    \        if (states_.empty()) {\n            throw runtime_error(\"No states are\
    \ registered.\");\n        }\n        return *min_element(states_.begin(), states_.end());\n\
    \    }\n    const vector<BeamSearchState> &get_states() {\n        sort(states_.begin(),\
    \ states_.end());\n        return states_;\n    }\n    int num_states() const\
    \ { return states_.size(); }\n    virtual int num_lite_states() const = 0;\n\n\
    \   protected:\n    int beam_width_;\n    vector<BeamSearchState> states_;\n \
    \   size_t current_state_idx_;\n};\n\ntemplate <class BeamSearchState, class LiteBeamSearchState>\n\
    class BeamSearch : public BeamSearchBase<BeamSearchState, LiteBeamSearchState>\
    \ {\n   public:\n    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;\n\
    \    void register_lite_state(LiteBeamSearchState &state) override {\n       \
    \ state.state_idx = this->current_state_idx_;\n        lite_states_.emplace_back(state);\n\
    \    }\n    void search(\n        const function<void(BeamSearchState &)> &add_next_lite_states,\n\
    \        const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)>\
    \ &to_next_state) override {\n        lite_states_.clear();\n        for (this->current_state_idx_\
    \ = 0; this->current_state_idx_ < this->states_.size();\n             this->current_state_idx_++)\
    \ {\n            add_next_lite_states(this->states_[this->current_state_idx_]);\n\
    \        }\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        nth_element(lite_states_.begin(), lite_states_.begin() + num_select,\
    \ lite_states_.end());\n        vector<BeamSearchState> next_states(num_select);\n\
    \        for (int i = 0; i < num_select; i++) {\n            next_states[i] =\
    \ to_next_state(lite_states_[i], this->states_[lite_states_[i].state_idx]);\n\
    \        }\n        this->states_ = move(next_states);\n    }\n    int num_lite_states()\
    \ const override { return lite_states_.size(); }\n\n   private:\n    vector<LiteBeamSearchState>\
    \ lite_states_;\n};\n\ntemplate <class BeamSearchState, class LiteBeamSearchState>\n\
    class BeamSearchWithHash : public BeamSearchBase<BeamSearchState, LiteBeamSearchState>\
    \ {\n   public:\n    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;\n\
    \    void register_lite_state(LiteBeamSearchState &state) override {\n       \
    \ state.state_idx = this->current_state_idx_;\n        lite_states_.emplace(state);\n\
    \        // remove the worst (biggest) state.\n        while ((int)lite_states_.size()\
    \ > this->beam_width_) {\n            lite_states_.pop();\n        }\n    }\n\n\
    \    void search(\n        const function<void(BeamSearchState &)> &add_next_lite_states,\n\
    \        const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)>\
    \ &to_next_state) override {\n        // NOTE: alternative of clear() because\
    \ STL doesn't have priority_queue::clear().\n        lite_states_ = priority_queue<LiteBeamSearchState>();\n\
    \        hash_values_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        vector<LiteBeamSearchState> lite_states_vec(lite_states_.size());\n \
    \       for (int i = (int)lite_states_vec.size() - 1; i >= 0; i--) {\n       \
    \     lite_states_vec[i] = lite_states_.top();\n            lite_states_.pop();\n\
    \        }\n        vector<BeamSearchState> next_states(num_select);\n       \
    \ int num_next_states = 0;\n        for (int i = 0; i < (int)lite_states_vec.size();\
    \ i++) {\n            auto &lite_state = lite_states_vec[i];\n            if (hash_values_.count(lite_state.hash_value))\
    \ {\n                continue;\n            }\n            hash_values_.insert(lite_state.hash_value);\n\
    \            next_states[num_next_states++] = to_next_state(lite_state, this->states_[lite_state.state_idx]);\n\
    \        }\n        next_states.resize(num_next_states);\n        this->states_\
    \ = move(next_states);\n    }\n    int num_lite_states() const override { return\
    \ lite_states_.size(); }\n\n   private:\n    priority_queue<LiteBeamSearchState>\
    \ lite_states_;\n    set<ll> hash_values_;\n};\n\ntemplate <typename score_t>\n\
    struct BeamSearchStateBase {\n    score_t score;\n    ll hash_value;\n    BeamSearchStateBase()\
    \ : score(0) {}\n    virtual bool operator<(const BeamSearchStateBase &state)\
    \ const = 0;\n};\n\ntemplate <typename score_t>\nstruct LiteBeamSearchStateBase\
    \ {\n    int state_idx;\n    score_t score;\n    ll hash_value;\n    LiteBeamSearchStateBase()\
    \ : state_idx(-1), score(0), hash_value(0) {}\n    virtual bool operator<(const\
    \ LiteBeamSearchStateBase &state) const = 0;\n};\n"
  code: "template <typename BeamSearchState, typename LiteBeamSearchState>\nclass\
    \ BeamSearchBase {\n   public:\n    BeamSearchBase() = default;\n    BeamSearchBase(int\
    \ beam_width) : beam_width_(beam_width) {}\n    void set_beam_width(int beam_width)\
    \ { beam_width_ = beam_width; }\n    void register_state(const BeamSearchState\
    \ &state) { states_.emplace_back(state); }\n    virtual void register_lite_state(LiteBeamSearchState\
    \ &state) = 0;\n    virtual void search(\n        const function<void(BeamSearchState\
    \ &)> &add_next_lite_states,\n        const function<BeamSearchState(LiteBeamSearchState\
    \ &, BeamSearchState)> &to_next_state) = 0;\n    const BeamSearchState &get_best_state()\
    \ const {\n        if (states_.empty()) {\n            throw runtime_error(\"\
    No states are registered.\");\n        }\n        return *min_element(states_.begin(),\
    \ states_.end());\n    }\n    const vector<BeamSearchState> &get_states() {\n\
    \        sort(states_.begin(), states_.end());\n        return states_;\n    }\n\
    \    int num_states() const { return states_.size(); }\n    virtual int num_lite_states()\
    \ const = 0;\n\n   protected:\n    int beam_width_;\n    vector<BeamSearchState>\
    \ states_;\n    size_t current_state_idx_;\n};\n\ntemplate <class BeamSearchState,\
    \ class LiteBeamSearchState>\nclass BeamSearch : public BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState> {\n   public:\n    using BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState>::BeamSearchBase;\n    void register_lite_state(LiteBeamSearchState\
    \ &state) override {\n        state.state_idx = this->current_state_idx_;\n  \
    \      lite_states_.emplace_back(state);\n    }\n    void search(\n        const\
    \ function<void(BeamSearchState &)> &add_next_lite_states,\n        const function<BeamSearchState(LiteBeamSearchState\
    \ &, BeamSearchState)> &to_next_state) override {\n        lite_states_.clear();\n\
    \        for (this->current_state_idx_ = 0; this->current_state_idx_ < this->states_.size();\n\
    \             this->current_state_idx_++) {\n            add_next_lite_states(this->states_[this->current_state_idx_]);\n\
    \        }\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        nth_element(lite_states_.begin(), lite_states_.begin() + num_select,\
    \ lite_states_.end());\n        vector<BeamSearchState> next_states(num_select);\n\
    \        for (int i = 0; i < num_select; i++) {\n            next_states[i] =\
    \ to_next_state(lite_states_[i], this->states_[lite_states_[i].state_idx]);\n\
    \        }\n        this->states_ = move(next_states);\n    }\n    int num_lite_states()\
    \ const override { return lite_states_.size(); }\n\n   private:\n    vector<LiteBeamSearchState>\
    \ lite_states_;\n};\n\ntemplate <class BeamSearchState, class LiteBeamSearchState>\n\
    class BeamSearchWithHash : public BeamSearchBase<BeamSearchState, LiteBeamSearchState>\
    \ {\n   public:\n    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;\n\
    \    void register_lite_state(LiteBeamSearchState &state) override {\n       \
    \ state.state_idx = this->current_state_idx_;\n        lite_states_.emplace(state);\n\
    \        // remove the worst (biggest) state.\n        while ((int)lite_states_.size()\
    \ > this->beam_width_) {\n            lite_states_.pop();\n        }\n    }\n\n\
    \    void search(\n        const function<void(BeamSearchState &)> &add_next_lite_states,\n\
    \        const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)>\
    \ &to_next_state) override {\n        // NOTE: alternative of clear() because\
    \ STL doesn't have priority_queue::clear().\n        lite_states_ = priority_queue<LiteBeamSearchState>();\n\
    \        hash_values_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        vector<LiteBeamSearchState> lite_states_vec(lite_states_.size());\n \
    \       for (int i = (int)lite_states_vec.size() - 1; i >= 0; i--) {\n       \
    \     lite_states_vec[i] = lite_states_.top();\n            lite_states_.pop();\n\
    \        }\n        vector<BeamSearchState> next_states(num_select);\n       \
    \ int num_next_states = 0;\n        for (int i = 0; i < (int)lite_states_vec.size();\
    \ i++) {\n            auto &lite_state = lite_states_vec[i];\n            if (hash_values_.count(lite_state.hash_value))\
    \ {\n                continue;\n            }\n            hash_values_.insert(lite_state.hash_value);\n\
    \            next_states[num_next_states++] = to_next_state(lite_state, this->states_[lite_state.state_idx]);\n\
    \        }\n        next_states.resize(num_next_states);\n        this->states_\
    \ = move(next_states);\n    }\n    int num_lite_states() const override { return\
    \ lite_states_.size(); }\n\n   private:\n    priority_queue<LiteBeamSearchState>\
    \ lite_states_;\n    set<ll> hash_values_;\n};\n\ntemplate <typename score_t>\n\
    struct BeamSearchStateBase {\n    score_t score;\n    ll hash_value;\n    BeamSearchStateBase()\
    \ : score(0) {}\n    virtual bool operator<(const BeamSearchStateBase &state)\
    \ const = 0;\n};\n\ntemplate <typename score_t>\nstruct LiteBeamSearchStateBase\
    \ {\n    int state_idx;\n    score_t score;\n    ll hash_value;\n    LiteBeamSearchStateBase()\
    \ : state_idx(-1), score(0), hash_value(0) {}\n    virtual bool operator<(const\
    \ LiteBeamSearchStateBase &state) const = 0;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/beam_search.cpp
  requiredBy: []
  timestamp: '2025-03-04 18:54:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/beam_search.cpp
layout: document
title: "\u30D3\u30FC\u30E0\u30B5\u30FC\u30C1"
---

- `BeamSearch` と `BeamSearchWithHash` の 2 種類が利用可能
    - 重複した状態を除去したいときは `BeamSearchWithHash` を使う。そうでないときは `BeamSearch` を使う。
    - `BeamSearch` だと $\log$ が落ちるはずなので、こっちのほうがイテレーションは回る
- 状態 `BeamSearchState` と、軽量化した状態 `LiteBeamSearchState` の両方を定義して使う
    - 軽量化した状態は、参照する `BeamSearchState` のインデックス +α の情報を持たせる
    - 両方ともスコア計算の実装が必須
- 以下の 2 つの関数を定義してビームサーチを実行する
    - `add_next_lite_states`: 状態を受けとり、次の状態を軽量化したものを返す関数
    - `to_next_state`: 軽量化した状態を受けとり、それを元の (軽量化していない) 状態に変換する関数

AHC040 で使用実績あり。  
[https://atcoder.jp/contests/ahc040/submissions/61300845](https://atcoder.jp/contests/ahc040/submissions/61300845)
