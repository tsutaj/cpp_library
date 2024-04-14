/**
 * @brief ビームサーチ
 * @docs docs/marathon/beam_search.md
 */

template <class BeamSearchState, class LiteBeamSearchState> class BeamSearch {
  public:
    BeamSearch() = default;
    void set_beam_width(int beam_width) { beam_width_ = beam_width; }
    void register_state(const BeamSearchState &state) {
        states_.emplace_back(state);
    }
    void register_lite_state(const LiteBeamSearchState &state) {
        lite_states_.emplace_back(state);
        lite_states_.back().state_idx = current_state_idx_;
    }
    void search(const auto &add_next_lite_states, const auto &to_next_state) {
        lite_states_.clear();
        for(current_state_idx_ = 0; current_state_idx_ < states_.size();
            current_state_idx_++) {
            add_next_lite_states(states_[current_state_idx_]);
        }
        const int num_select = min((int)lite_states_.size(), beam_width_);
        nth_element(lite_states_.begin(), lite_states_.begin() + num_select,
                    lite_states_.end());
        vector<BeamSearchState> next_states(num_select);
        for(int i = 0; i < num_select; i++) {
            next_states[i] = to_next_state(lite_states_[i],
                                            states_[lite_states_[i].state_idx]);
        }
        states_ = move(next_states);
    }
    const BeamSearchState &get_best_state() const {
        return *min_element(states_.begin(), states_.end());
    }

  private:
    int beam_width_;
    size_t current_state_idx_;
    vector<BeamSearchState> states_;
    vector<LiteBeamSearchState> lite_states_;
};

struct LiteBeamSearchStateBase {
    int state_idx;
    LiteBeamSearchStateBase() : state_idx(-1) {}
};
