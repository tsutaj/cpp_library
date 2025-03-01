class IndexSet {
public:
    IndexSet(int n) : pos_(n, -1) {}

    void insert(int x) {
        if (contains(x)) return;
        que_.push_back(x);
        pos_[x] = que_.size() - 1;
    }

    void erase(int x) {
        if (!contains(x)) return;
        int idx = pos_[x];
        if (idx == -1) return;
        int last = que_.back();
        que_[idx] = last;
        pos_[last] = idx;
        que_.pop_back();
        pos_[x] = -1;
    }

    int size() const {
        return que_.size();
    }

    bool contains(int x) const {
        return pos_[x] != -1;
    }

    int operator[](int idx) const {
        return que_[idx];
    }

    const vector<int>& get_elements() const {
        return que_;
    }

private:
    vector<int> que_;
    vector<int> pos_;
};
