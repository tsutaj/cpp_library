---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/marathon/beam_search.md
    document_title: "\u30D3\u30FC\u30E0\u30B5\u30FC\u30C1"
    links: []
  bundledCode: "#line 1 \"marathon/beam_search.cpp\"\n/**\n * @brief \u30D3\u30FC\u30E0\
    \u30B5\u30FC\u30C1\n * @docs docs/marathon/beam_search.md\n */\n\ntemplate <class\
    \ BeamSearchState, class LiteBeamSearchState> class BeamSearch {\n  public:\n\
    \    BeamSearch() = default;\n    void set_beam_width(int beam_width) { beam_width_\
    \ = beam_width; }\n    void register_state(const BeamSearchState &state) {\n \
    \       states_.emplace_back(state);\n    }\n    void register_lite_state(const\
    \ LiteBeamSearchState &state) {\n        lite_states_.emplace_back(state);\n \
    \       lite_states_.back().state_idx = current_state_idx_;\n    }\n    void search(const\
    \ auto &add_next_lite_states, const auto &to_next_state) {\n        lite_states_.clear();\n\
    \        for(current_state_idx_ = 0; current_state_idx_ < states_.size();\n  \
    \          current_state_idx_++) {\n            add_next_lite_states(states_[current_state_idx_]);\n\
    \        }\n        const int num_select = min((int)lite_states_.size(), beam_width_);\n\
    \        nth_element(lite_states_.begin(), lite_states_.begin() + num_select,\n\
    \                    lite_states_.end());\n        vector<BeamSearchState> next_states(num_select);\n\
    \        for(int i = 0; i < num_select; i++) {\n            next_states[i] = to_next_state(lite_states_[i],\n\
    \                                            states_[lite_states_[i].state_idx]);\n\
    \        }\n        states_ = move(next_states);\n    }\n    const BeamSearchState\
    \ &get_best_state() const {\n        return *min_element(states_.begin(), states_.end());\n\
    \    }\n\n  private:\n    int beam_width_;\n    size_t current_state_idx_;\n \
    \   vector<BeamSearchState> states_;\n    vector<LiteBeamSearchState> lite_states_;\n\
    };\n\nstruct LiteBeamSearchStateBase {\n    int state_idx;\n    LiteBeamSearchStateBase()\
    \ : state_idx(-1) {}\n};\n"
  code: "/**\n * @brief \u30D3\u30FC\u30E0\u30B5\u30FC\u30C1\n * @docs docs/marathon/beam_search.md\n\
    \ */\n\ntemplate <class BeamSearchState, class LiteBeamSearchState> class BeamSearch\
    \ {\n  public:\n    BeamSearch() = default;\n    void set_beam_width(int beam_width)\
    \ { beam_width_ = beam_width; }\n    void register_state(const BeamSearchState\
    \ &state) {\n        states_.emplace_back(state);\n    }\n    void register_lite_state(const\
    \ LiteBeamSearchState &state) {\n        lite_states_.emplace_back(state);\n \
    \       lite_states_.back().state_idx = current_state_idx_;\n    }\n    void search(const\
    \ auto &add_next_lite_states, const auto &to_next_state) {\n        lite_states_.clear();\n\
    \        for(current_state_idx_ = 0; current_state_idx_ < states_.size();\n  \
    \          current_state_idx_++) {\n            add_next_lite_states(states_[current_state_idx_]);\n\
    \        }\n        const int num_select = min((int)lite_states_.size(), beam_width_);\n\
    \        nth_element(lite_states_.begin(), lite_states_.begin() + num_select,\n\
    \                    lite_states_.end());\n        vector<BeamSearchState> next_states(num_select);\n\
    \        for(int i = 0; i < num_select; i++) {\n            next_states[i] = to_next_state(lite_states_[i],\n\
    \                                            states_[lite_states_[i].state_idx]);\n\
    \        }\n        states_ = move(next_states);\n    }\n    const BeamSearchState\
    \ &get_best_state() const {\n        return *min_element(states_.begin(), states_.end());\n\
    \    }\n\n  private:\n    int beam_width_;\n    size_t current_state_idx_;\n \
    \   vector<BeamSearchState> states_;\n    vector<LiteBeamSearchState> lite_states_;\n\
    };\n\nstruct LiteBeamSearchStateBase {\n    int state_idx;\n    LiteBeamSearchStateBase()\
    \ : state_idx(-1) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: marathon/beam_search.cpp
  requiredBy: []
  timestamp: '2024-04-14 15:54:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: marathon/beam_search.cpp
layout: document
redirect_from:
- /library/marathon/beam_search.cpp
- /library/marathon/beam_search.cpp.html
title: "\u30D3\u30FC\u30E0\u30B5\u30FC\u30C1"
---
- 状態 `BeamSearchState` と、軽量化した状態 `LiteBeamSearchState` の両方を定義して使う
    - 軽量化した状態は、参照する `BeamSearchState` のインデックス +α の情報を持たせる
- 以下の 2 つの関数を定義してビームサーチを実行する
    - `add_next_lite_states`: 状態を受けとり、次の状態を軽量化したものを返す関数
    - `to_next_state`: 軽量化した状態を受けとり、それを元の (軽量化していない) 状態に変換する関数
