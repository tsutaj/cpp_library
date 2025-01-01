template <typename Tp>
class IntervalHeap {
   public:
    template <class Iterator>
    IntervalHeap(Iterator first, Iterator last) : data_(first, last) {
        make_heap();
    }
    IntervalHeap() = default;

    size_t size() const { return data_.size(); }
    void clear() { data_.clear(); }
    void emplace(const Tp& val) {
        data_.push_back(val);
        up(size() - 1);
    }
    void push(const Tp& val) { emplace(val); }
    const Tp& top_min() const { return data_[size() >= 2]; }
    const Tp& top_max() const { return data_[0]; }
    void pop_min() {
        if(size() <= 2) {
            data_.pop_back();
        } else {
            swap(data_[1], data_.back());
            data_.pop_back();
            const size_t k = down(1);
            up(k);
        }
    }
    void pop_max() {
        if(size() <= 1) {
            data_.pop_back();
        } else {
            swap(data_[0], data_.back());
            data_.pop_back();
            const size_t k = down(0);
            up(k);
        }
    }

   private:
    vector<Tp> data_;
    inline size_t to_k_max(size_t k) { return k & ~1; }
    inline size_t to_k_min(size_t k) { return k | 1; }
    inline size_t get_parent(size_t k, bool is_max) { return (((k >> 1) - 1) & ~1) | (is_max ? 0 : 1); }

    size_t down(size_t k) {
        const size_t s = size();
        if(k & 1) {
            // min heap
            while(true) {
                const size_t cl = (k << 1) + 1;
                const size_t cr = (k << 1) + 3;
                if(cl >= s) break;
                const size_t c = (cr >= s || data_[cl] < data_[cr]) ? cl : cr;
                if(data_[c] < data_[k]) {
                    swap(data_[k], data_[c]);
                    k = c;
                } else {
                    break;
                }
            }
        } else {
            // max heap
            while(true) {
                const size_t cl = (k << 1) + 2;
                const size_t cr = (k << 1) + 4;
                if(cl >= s) break;
                const size_t c = (cr >= s || data_[cr] < data_[cl]) ? cl : cr;
                if(data_[k] < data_[c]) {
                    swap(data_[k], data_[c]);
                    k = c;
                } else {
                    break;
                }
            }
        }
        return k;
    }
    void up(size_t k, size_t root = 1) {
        const size_t k_max = to_k_max(k);
        const size_t k_min = to_k_min(k);
        if(k_min < size() && data_[k_max] < data_[k_min]) {
            swap(data_[k_max], data_[k_min]);
            k ^= 1;
        }

        size_t p;
        // max heap
        while(root < k && data_[p = get_parent(k, true)] < data_[k]) {
            swap(data_[k], data_[p]);
            k = p;
        }
        // min heap
        while(root < k && data_[k] < data_[p = get_parent(k, false)]) {
            swap(data_[k], data_[p]);
            k = p;
        }
    }
    void make_heap() {
        for(size_t i = size(); i--;) {
            if((i & 1) && data_[i - 1] < data_[i]) {
                swap(data_[i - 1], data_[i]);
            }
            size_t k = down(i);
            up(k, i);
        }
    }
};
