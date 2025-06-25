#include <memory>

template <typename BeamSearchState, typename LiteBeamSearchState>
class BeamSearchBase {
   public:
    BeamSearchBase() = default;
    BeamSearchBase(int beam_width) : beam_width_(beam_width) {}
    void set_beam_width(int beam_width) { beam_width_ = beam_width; }
    void register_state(const BeamSearchState &state) { states_.emplace_back(state); }
    virtual void register_lite_state(LiteBeamSearchState &lite_state, const BeamSearchState& state) = 0;
    virtual void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state) = 0;
    virtual void add_lite_states(const function<void(BeamSearchState &)> &add_next_lite_states) = 0;
    const BeamSearchState &get_best_state() const {
        if (states_.empty()) {
            throw runtime_error("No states are registered.");
        }
        return *min_element(states_.begin(), states_.end());
    }
    const vector<BeamSearchState> &get_states() {
        sort(states_.begin(), states_.end());
        return states_;
    }
    int num_states() const { return states_.size(); }
    virtual int num_lite_states() const = 0;

   protected:
    int beam_width_;
    vector<BeamSearchState> states_;
    size_t current_state_idx_;
};

template <class BeamSearchState, class LiteBeamSearchState>
class BeamSearch : public BeamSearchBase<BeamSearchState, LiteBeamSearchState> {
   public:
    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;
    void register_lite_state(LiteBeamSearchState &lite_state, const BeamSearchState& state) override {
        lite_state.state_ref = make_shared<BeamSearchState>(state);
        lite_states_.emplace_back(lite_state);
    }

    void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state) override {
        const int num_select = min((int)lite_states_.size(), this->beam_width_);
        nth_element(lite_states_.begin(), lite_states_.begin() + num_select, lite_states_.end());
        vector<BeamSearchState> next_states(num_select);
        for (int i = 0; i < num_select; i++) {
            next_states[i] = to_next_state(lite_states_[i], *lite_states_[i].state_ref);
        }
        this->states_ = move(next_states);
    }

    void add_lite_states(const function<void(BeamSearchState &)> &add_next_lite_states) override {
        lite_states_.clear();
        for (this->current_state_idx_ = 0; this->current_state_idx_ < this->states_.size();
             this->current_state_idx_++) {
            add_next_lite_states(this->states_[this->current_state_idx_]);
        }
    }

    int num_lite_states() const override { return lite_states_.size(); }

   private:
    vector<LiteBeamSearchState> lite_states_;
};

template <class BeamSearchState, class LiteBeamSearchState>
class BeamSearchWithHash : public BeamSearchBase<BeamSearchState, LiteBeamSearchState> {
   public:
    using BeamSearchBase<BeamSearchState, LiteBeamSearchState>::BeamSearchBase;
    void register_lite_state(LiteBeamSearchState &lite_state, const BeamSearchState& state) override {
        lite_state.state_ref = make_shared<BeamSearchState>(state);
        lite_states_.emplace(lite_state);
    }

    void reconstruct_states(const function<BeamSearchState(LiteBeamSearchState &, BeamSearchState)> &to_next_state) override {
        const int num_select = min((int)lite_states_.size(), this->beam_width_);
        vector<LiteBeamSearchState> lite_states_vec(lite_states_.size());
        for (int i = (int)lite_states_vec.size() - 1; i >= 0; i--) {
            lite_states_vec[i] = lite_states_.top();
            lite_states_.pop();
        }
        vector<BeamSearchState> next_states(num_select);
        int num_next_states = 0;
        for (int i = 0; i < num_select; i++) {
            auto &lite_state = lite_states_vec[i];
            if (hash_values_.count(lite_state.hash_value)) {
                continue;
            }
            hash_values_.insert(lite_state.hash_value);
            next_states[num_next_states++] = to_next_state(lite_state, *lite_state.state_ref);
        }
        next_states.resize(num_next_states);
        this->states_ = move(next_states);
    }

    void add_lite_states(const function<void(BeamSearchState &)> &add_next_lite_states) override {
        // NOTE: alternative of clear() because STL doesn't have priority_queue::clear().
        lite_states_ = priority_queue<LiteBeamSearchState>();
        hash_values_.clear();
        for (this->current_state_idx_ = 0; this->current_state_idx_ < this->states_.size();
             this->current_state_idx_++) {
            add_next_lite_states(this->states_[this->current_state_idx_]);
        }
    }

    int num_lite_states() const override { return lite_states_.size(); }

   private:
    priority_queue<LiteBeamSearchState> lite_states_;
    set<ll> hash_values_;
};

// template <typename score_t>
// struct BeamSearchState {
//     score_t score;
//     ll hash_value;
//     BeamSearchStateBase() : score(0), hash_value(0) {}
//     ~BeamSearchStateBase() = default;
// };

// template <typename score_t>
// struct LiteBeamSearchState {
//     shared_ptr<BeamSearchState<score_t>> state_ref;
//     score_t score;
//     ll hash_value;
//     LiteBeamSearchState() : state_ref(nullptr), score(0), hash_value(0) {}
//     ~LiteBeamSearchState() = default;
// };
