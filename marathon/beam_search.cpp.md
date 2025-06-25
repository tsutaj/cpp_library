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
  bundledCode: "#line 1 \"marathon/beam_search.cpp\"\n#include <memory>\n\ntemplate\
    \ <typename BeamSearchState, typename LiteBeamSearchState>\nclass BeamSearchBase\
    \ {\n   public:\n    BeamSearchBase() = default;\n    BeamSearchBase(int beam_width)\
    \ : beam_width_(beam_width) {}\n    void set_beam_width(int beam_width) { beam_width_\
    \ = beam_width; }\n    void register_state(const BeamSearchState &state) { states_.emplace_back(state);\
    \ }\n    virtual void register_lite_state(LiteBeamSearchState &lite_state, const\
    \ BeamSearchState& state) = 0;\n    virtual void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState\
    \ &, BeamSearchState)> &to_next_state) = 0;\n    virtual void add_lite_states(const\
    \ function<void(BeamSearchState &)> &add_next_lite_states) = 0;\n    const BeamSearchState\
    \ &get_best_state() const {\n        if (states_.empty()) {\n            throw\
    \ runtime_error(\"No states are registered.\");\n        }\n        return *min_element(states_.begin(),\
    \ states_.end());\n    }\n    const vector<BeamSearchState> &get_states() {\n\
    \        sort(states_.begin(), states_.end());\n        return states_;\n    }\n\
    \    int num_states() const { return states_.size(); }\n    virtual int num_lite_states()\
    \ const = 0;\n\n   protected:\n    int beam_width_;\n    vector<BeamSearchState>\
    \ states_;\n    size_t current_state_idx_;\n};\n\ntemplate <class BeamSearchState,\
    \ class LiteBeamSearchState>\nclass BeamSearch : public BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState> {\n   public:\n    using BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState>::BeamSearchBase;\n    void register_lite_state(LiteBeamSearchState\
    \ &lite_state, const BeamSearchState& state) override {\n        lite_state.state_ref\
    \ = make_shared<BeamSearchState>(state);\n        lite_states_.emplace_back(lite_state);\n\
    \    }\n\n    void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState\
    \ &, BeamSearchState)> &to_next_state) override {\n        const int num_select\
    \ = min((int)lite_states_.size(), this->beam_width_);\n        nth_element(lite_states_.begin(),\
    \ lite_states_.begin() + num_select, lite_states_.end());\n        vector<BeamSearchState>\
    \ next_states(num_select);\n        for (int i = 0; i < num_select; i++) {\n \
    \           next_states[i] = to_next_state(lite_states_[i], *lite_states_[i].state_ref);\n\
    \        }\n        this->states_ = move(next_states);\n    }\n\n    void add_lite_states(const\
    \ function<void(BeamSearchState &)> &add_next_lite_states) override {\n      \
    \  lite_states_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n    }\n\n    int num_lite_states() const override { return lite_states_.size();\
    \ }\n\n   private:\n    vector<LiteBeamSearchState> lite_states_;\n};\n\ntemplate\
    \ <class BeamSearchState, class LiteBeamSearchState>\nclass BeamSearchWithHash\
    \ : public BeamSearchBase<BeamSearchState, LiteBeamSearchState> {\n   public:\n\
    \    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;\n\
    \    void register_lite_state(LiteBeamSearchState &lite_state, const BeamSearchState&\
    \ state) override {\n        lite_state.state_ref = make_shared<BeamSearchState>(state);\n\
    \        lite_states_.emplace(lite_state);\n    }\n\n    void reconstruct_states(const\
    \ function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state)\
    \ override {\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        vector<LiteBeamSearchState> lite_states_vec(lite_states_.size());\n \
    \       for (int i = (int)lite_states_vec.size() - 1; i >= 0; i--) {\n       \
    \     lite_states_vec[i] = lite_states_.top();\n            lite_states_.pop();\n\
    \        }\n        vector<BeamSearchState> next_states(num_select);\n       \
    \ int num_next_states = 0;\n        for (int i = 0; i < num_select; i++) {\n \
    \           auto &lite_state = lite_states_vec[i];\n            if (hash_values_.count(lite_state.hash_value))\
    \ {\n                continue;\n            }\n            hash_values_.insert(lite_state.hash_value);\n\
    \            next_states[num_next_states++] = to_next_state(lite_state, *lite_state.state_ref);\n\
    \        }\n        next_states.resize(num_next_states);\n        this->states_\
    \ = move(next_states);\n    }\n\n    void add_lite_states(const function<void(BeamSearchState\
    \ &)> &add_next_lite_states) override {\n        // NOTE: alternative of clear()\
    \ because STL doesn't have priority_queue::clear().\n        lite_states_ = priority_queue<LiteBeamSearchState>();\n\
    \        hash_values_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n    }\n\n    int num_lite_states() const override { return lite_states_.size();\
    \ }\n\n   private:\n    priority_queue<LiteBeamSearchState> lite_states_;\n  \
    \  set<ll> hash_values_;\n};\n\n// template <typename score_t>\n// struct BeamSearchState\
    \ {\n//     score_t score;\n//     ll hash_value;\n//     BeamSearchStateBase()\
    \ : score(0), hash_value(0) {}\n//     ~BeamSearchStateBase() = default;\n// };\n\
    \n// template <typename score_t>\n// struct LiteBeamSearchState {\n//     shared_ptr<BeamSearchState<score_t>>\
    \ state_ref;\n//     score_t score;\n//     ll hash_value;\n//     LiteBeamSearchState()\
    \ : state_ref(nullptr), score(0), hash_value(0) {}\n//     ~LiteBeamSearchState()\
    \ = default;\n// };\n"
  code: "#include <memory>\n\ntemplate <typename BeamSearchState, typename LiteBeamSearchState>\n\
    class BeamSearchBase {\n   public:\n    BeamSearchBase() = default;\n    BeamSearchBase(int\
    \ beam_width) : beam_width_(beam_width) {}\n    void set_beam_width(int beam_width)\
    \ { beam_width_ = beam_width; }\n    void register_state(const BeamSearchState\
    \ &state) { states_.emplace_back(state); }\n    virtual void register_lite_state(LiteBeamSearchState\
    \ &lite_state, const BeamSearchState& state) = 0;\n    virtual void reconstruct_states(const\
    \ function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state)\
    \ = 0;\n    virtual void add_lite_states(const function<void(BeamSearchState &)>\
    \ &add_next_lite_states) = 0;\n    const BeamSearchState &get_best_state() const\
    \ {\n        if (states_.empty()) {\n            throw runtime_error(\"No states\
    \ are registered.\");\n        }\n        return *min_element(states_.begin(),\
    \ states_.end());\n    }\n    const vector<BeamSearchState> &get_states() {\n\
    \        sort(states_.begin(), states_.end());\n        return states_;\n    }\n\
    \    int num_states() const { return states_.size(); }\n    virtual int num_lite_states()\
    \ const = 0;\n\n   protected:\n    int beam_width_;\n    vector<BeamSearchState>\
    \ states_;\n    size_t current_state_idx_;\n};\n\ntemplate <class BeamSearchState,\
    \ class LiteBeamSearchState>\nclass BeamSearch : public BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState> {\n   public:\n    using BeamSearchBase<BeamSearchState,\
    \ LiteBeamSearchState>::BeamSearchBase;\n    void register_lite_state(LiteBeamSearchState\
    \ &lite_state, const BeamSearchState& state) override {\n        lite_state.state_ref\
    \ = make_shared<BeamSearchState>(state);\n        lite_states_.emplace_back(lite_state);\n\
    \    }\n\n    void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState\
    \ &, BeamSearchState)> &to_next_state) override {\n        const int num_select\
    \ = min((int)lite_states_.size(), this->beam_width_);\n        nth_element(lite_states_.begin(),\
    \ lite_states_.begin() + num_select, lite_states_.end());\n        vector<BeamSearchState>\
    \ next_states(num_select);\n        for (int i = 0; i < num_select; i++) {\n \
    \           next_states[i] = to_next_state(lite_states_[i], *lite_states_[i].state_ref);\n\
    \        }\n        this->states_ = move(next_states);\n    }\n\n    void add_lite_states(const\
    \ function<void(BeamSearchState &)> &add_next_lite_states) override {\n      \
    \  lite_states_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n    }\n\n    int num_lite_states() const override { return lite_states_.size();\
    \ }\n\n   private:\n    vector<LiteBeamSearchState> lite_states_;\n};\n\ntemplate\
    \ <class BeamSearchState, class LiteBeamSearchState>\nclass BeamSearchWithHash\
    \ : public BeamSearchBase<BeamSearchState, LiteBeamSearchState> {\n   public:\n\
    \    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;\n\
    \    void register_lite_state(LiteBeamSearchState &lite_state, const BeamSearchState&\
    \ state) override {\n        lite_state.state_ref = make_shared<BeamSearchState>(state);\n\
    \        lite_states_.emplace(lite_state);\n    }\n\n    void reconstruct_states(const\
    \ function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state)\
    \ override {\n        const int num_select = min((int)lite_states_.size(), this->beam_width_);\n\
    \        vector<LiteBeamSearchState> lite_states_vec(lite_states_.size());\n \
    \       for (int i = (int)lite_states_vec.size() - 1; i >= 0; i--) {\n       \
    \     lite_states_vec[i] = lite_states_.top();\n            lite_states_.pop();\n\
    \        }\n        vector<BeamSearchState> next_states(num_select);\n       \
    \ int num_next_states = 0;\n        for (int i = 0; i < num_select; i++) {\n \
    \           auto &lite_state = lite_states_vec[i];\n            if (hash_values_.count(lite_state.hash_value))\
    \ {\n                continue;\n            }\n            hash_values_.insert(lite_state.hash_value);\n\
    \            next_states[num_next_states++] = to_next_state(lite_state, *lite_state.state_ref);\n\
    \        }\n        next_states.resize(num_next_states);\n        this->states_\
    \ = move(next_states);\n    }\n\n    void add_lite_states(const function<void(BeamSearchState\
    \ &)> &add_next_lite_states) override {\n        // NOTE: alternative of clear()\
    \ because STL doesn't have priority_queue::clear().\n        lite_states_ = priority_queue<LiteBeamSearchState>();\n\
    \        hash_values_.clear();\n        for (this->current_state_idx_ = 0; this->current_state_idx_\
    \ < this->states_.size();\n             this->current_state_idx_++) {\n      \
    \      add_next_lite_states(this->states_[this->current_state_idx_]);\n      \
    \  }\n    }\n\n    int num_lite_states() const override { return lite_states_.size();\
    \ }\n\n   private:\n    priority_queue<LiteBeamSearchState> lite_states_;\n  \
    \  set<ll> hash_values_;\n};\n\n// template <typename score_t>\n// struct BeamSearchState\
    \ {\n//     score_t score;\n//     ll hash_value;\n//     BeamSearchStateBase()\
    \ : score(0), hash_value(0) {}\n//     ~BeamSearchStateBase() = default;\n// };\n\
    \n// template <typename score_t>\n// struct LiteBeamSearchState {\n//     shared_ptr<BeamSearchState<score_t>>\
    \ state_ref;\n//     score_t score;\n//     ll hash_value;\n//     LiteBeamSearchState()\
    \ : state_ref(nullptr), score(0), hash_value(0) {}\n//     ~LiteBeamSearchState()\
    \ = default;\n// };\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/beam_search.cpp
  requiredBy: []
  timestamp: '2025-06-25 11:24:55+09:00'
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
- 以下の関数を定義する
    - `add_next_lite_states`: 状態を受けとり、次の状態を軽量化したものを返す関数
    - `to_next_state`: 軽量化した状態を受けとり、それを元の (軽量化していない) 状態に変換する関数
- 概ね次のようにしてビームサーチをする
  - 初期状態を登録
  - ターン数だけ次を繰り返す
    - 最初のターン以外: `reconstruct_states` で、軽量化した状態を元の状態に変換
    - `add_lite_states` で、軽量化した状態を登録
      - どのターンに対しても登録可能

AHC049 で使用実績あり。  
[https://atcoder.jp/contests/ahc049/submissions/67053066](https://atcoder.jp/contests/ahc049/submissions/67053066)
