[トップページに戻る](../index.html)

# timer.cpp
---

## Verify Files
* [static\_wavelet\_matrix.test.cpp](../verified/static_wavelet_matrix.test.cpp)
* [strc\_023\_compact\_bitvector.cpp](../verified/strc_023_compact_bitvector.cpp)
* [strc\_024\_static\_wavelet\_matrix.cpp](../verified/strc_024_static_wavelet_matrix.cpp)
* [static\_wavelet\_matrix\_less.test.cpp](../verified/static_wavelet_matrix_less.test.cpp)
* [static\_wavelet\_matrix\_more.test.cpp](../verified/static_wavelet_matrix_more.test.cpp)
* [geometry.test.cpp](../verified/geometry.test.cpp)
* [geometry\_2D.cpp](../verified/geometry_2D.cpp)

## Code

```cpp
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
```

[トップページに戻る](../index.html)
