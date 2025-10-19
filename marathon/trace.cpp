template <typename Tp>
class Trace {
public:
    Trace() = default;

    int add(const Tp& value, int parent) {
        log_.emplace_back(value, parent);
        return (int)log_.size() - 1;
    }

    vector<Tp> get(int index) const {
        vector<Tp> result;
        while (index >= 0) {
            result.emplace_back(log_[index].first);
            index = log_[index].second;
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    vector<pair<Tp, int>> log_;
};
