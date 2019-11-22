class Timer {
    chrono::high_resolution_clock::time_point start, end;
    double limit;

public:
    Timer() {
        start = chrono::high_resolution_clock::now();
    }
    Timer(double l) {
        start = chrono::high_resolution_clock::now();
        limit = l;
    }

    double getTime() {
        end = chrono::high_resolution_clock::now();
        return chrono::duration<double>(end - start).count();
    }

    bool isTimeOver() {
        if (getTime() > limit) {
            return true;
        }
        return false;
    }

    double getLimit() { return limit; }
    void setLimit(double l) {
        limit = l;
    }
    void setStart() { start = chrono::high_resolution_clock::now(); }
};
