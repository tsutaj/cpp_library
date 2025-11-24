#include <cstdint>

struct Rand {
 private:
  constexpr static double R = 1.0 / 0xffffffff;
  uint64_t x;

 public:
  Rand(uint64_t seed = 88172645463325252ull) : x(seed) {}

  inline uint64_t nextULong() {  // [0, 2^64)
    x ^= x << 7ull;
    x ^= x >> 9ull;
    return x;
  }

  inline uint32_t nextUInt(uint32_t r) {  // [0, r)
    return ((nextULong() >> 32ull) * r) >> 32ull;
  }

  inline uint32_t nextUInt(uint32_t l, uint32_t r) {  // [l, r)
    return l + nextUInt(r - l);
  }

  inline double nextDouble() {  // [0.0, 1.0]
    return ((uint32_t)nextULong()) * R;
  }
};
