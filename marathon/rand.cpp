// [lb, ub] の閉区間内の値をランダムに返す構造体
#include <random>
#include <limits>

struct Rand {
public:
    Rand() = default;
    Rand(std::mt19937::result_type seed) : eng(seed) {}

    uint32_t NextUInt(uint32_t lb, uint32_t ub) {
        return std::uniform_int_distribution<uint32_t>{lb, ub}(eng);
    }
    uint32_t NextUInt() {
        return std::uniform_int_distribution<uint32_t>{0, std::numeric_limits<uint32_t>::max()}(eng);
    }

    int32_t NextInt(int32_t lb, int32_t ub) {
        return std::uniform_int_distribution<int32_t>{lb, ub}(eng);
    }
    int32_t NextInt() {
        return std::uniform_int_distribution<int32_t>{0, std::numeric_limits<int32_t>::max()}(eng);
    }

    uint64_t NextULong(uint64_t lb, uint64_t ub) {
        return std::uniform_int_distribution<uint64_t>{lb, ub}(eng);
    }
    uint64_t NextULong() {
        return std::uniform_int_distribution<uint64_t>{0, std::numeric_limits<uint64_t>::max()}(eng);
    }

    int64_t NextLong(int64_t lb, int64_t ub) {
        return std::uniform_int_distribution<int64_t>{lb, ub}(eng);
    }
    int64_t NextLong() {
        return std::uniform_int_distribution<int64_t>{0, std::numeric_limits<int64_t>::max()}(eng);
    }

    double NextDouble(double lb, double ub) {
        return std::uniform_real_distribution<double>{lb, ub}(eng);
    }
private:
    std::mt19937 eng{std::random_device{}()};
};
