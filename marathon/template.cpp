
#ifndef DEBUG
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#include <cstdio>
#include <cassert>
#include <cmath>
#include <cstring>
#include <string>
#include <functional>
#include <stack>
#include <utility>
#include <queue>
#include <algorithm>
#include <execinfo.h>
#include <iostream>
#include <set>
#include <numeric>
#include <map>
using namespace std;
using ll = long long int;

#ifdef DEBUG
#define STDERR(...) fprintf(stderr, __VA_ARGS__);
#define ASSERT_OVERLOAD(e1,e2,NAME,...) NAME
#define ASSERT_1(x) assert_with_backtrace((x))
#define ASSERT_2(x, y) assert_with_backtrace((x), (y))
#define ASSERT(...) ASSERT_OVERLOAD(__VA_ARGS__, ASSERT_2, ASSERT_1)(__VA_ARGS__)
#define DEBUG_PRINT(...) fprintf(stderr, __VA_ARGS__), printf(__VA_ARGS__)
#else
#define STDERR(...)
#define ASSERT(...)
#define DEBUG_PRINT(...)
#endif

// assert で落ちたときにバックトレースする (`-g -rdynamic` が必要)
// デバッグモードでのみ有効
void assert_with_backtrace(bool condition, std::string error_msg="") {
    if(!condition) {
        void* callstack[256];
        int i, frames = backtrace(callstack, 256);
        char** strs = backtrace_symbols(callstack, frames);
        for (i = 0; i < frames; ++i) {
            fprintf(stderr, "%s\n", strs[i]);
        }
        free(strs);
        fprintf(stderr, "%s\n", error_msg.c_str());
        ASSERT(false);
    }
}

template <typename Tp>
bool chmin(Tp& a, const Tp& b) {
    if(a > b) {
        a = b;
        return true;
    } else {
        return false;
    }
}
template <typename Tp>
bool chmax(Tp& a, const Tp& b) {
    if(a < b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

#include "/home/tsutaj/Documents/compro/cpp_library/marathon/timer.cpp"
#include "/home/tsutaj/Documents/compro/cpp_library/marathon/rand.cpp"
Rand rnd(35023503980LL);
Timer timer;

int main() {
    timer.setStart();

    return 0;
}
