#include "interval_heap.cpp"

template <class State, class Timer>
class ChokudaiSearch {
   public:
    ChokudaiSearch() : num_iter_(-1) {}
    void init(int max_turns, double search_time, int time_check_iter) {
        states_.resize(max_turns + 1);
        search_time_ = search_time;
        num_iter_ = 0;
        time_check_iter_ = time_check_iter;
        max_num_states_.resize(max_turns + 1, 1 << 30);
    }
    void set_max_num_states(int max_num_state) {
        fill(max_num_states_.begin(), max_num_states_.end(), max_num_state);
    }
    void set_max_num_states(const vector<int> &max_num_states) {
        assert(max_num_states.size() == max_num_states_.size());
        max_num_states_ = max_num_states;
    }
    void register_state(int turns, const State &state) {
        states_[turns].emplace(state);
        while(states_[turns].size() > max_num_states_[turns]) {
            states_[turns].pop_max();
        }
    }
    size_t size(int turns) const {
        return states_[turns].size();
    }
    const State& worst_state(int turns) const {
        assert(states_[turns].size() > 0);
        return states_[turns].top_max();
    }
    void search(Timer &timer, const auto &add_next_states) {
        assert(num_iter_ >= 0);
        const double start_time = timer.getTime();
        for(num_iter_ = 0;; num_iter_++) {
            for(int turns = 0; turns + 1 < (int)states_.size(); turns++) {
                if(timer.getTime() - start_time > search_time_) {
                    goto TIME_OVER;
                }
                if(states_[turns].size() == 0) continue;
                State state = states_[turns].top_min();
                states_[turns].pop_min();
                add_next_states(turns, state);
            }
        }
    TIME_OVER:;
        fprintf(stderr, "chokudai search: num_iter = %d\n", num_iter_);
    }
    const State &get_best_state() const {
        if (states_.back().empty()) {
            throw runtime_error("No states are registered.");
        }
        return states_.back().top_min();
    }

   private:
    double search_time_;
    int num_iter_;
    int time_check_iter_;
    vector<IntervalHeap<State>> states_;
    vector<int> max_num_states_;
};
