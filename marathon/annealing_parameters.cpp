template <int ITER_PERIOD = 1 << 20>
struct AnnealingParameters {
    const double start_temp;
    const double end_temp;
    double cur_temp;
    double ln_p[ITER_PERIOD];
    AnnealingParameters(double start_temp, double end_temp, Rand& rnd)
        : start_temp(start_temp), end_temp(end_temp), cur_temp(start_temp) {
        for(int i=0; i<ITER_PERIOD; i++) {
            ln_p[i] = log(rnd.NextDouble());
        }
    }

    inline void update_temp_linear(double ratio) {
        cur_temp = start_temp + (end_temp - start_temp) * ratio;
    }

    inline void update_temp_pow(double ratio) {
        cur_temp = start_temp * pow(end_temp / start_temp, ratio);
    }

    // p < exp(diff / temp) を変形すると、diff > temp * ln_p
    // diff がこの値を超えていたら採用できる
    inline bool is_acceptable(int iter, int diff) const {
        return diff > cur_temp * ln_p[iter % ITER_PERIOD];
    }
};
