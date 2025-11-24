
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
#include <unistd.h>
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
        int frames = backtrace(callstack, 256);

        // get executable path
        char exec_path[1024] = {0};
        ssize_t len = readlink("/proc/self/exe", exec_path, sizeof(exec_path) - 1);
        if (len == -1) {
            strcpy(exec_path, "./a.out");
        } else {
            exec_path[len] = '\0';
        }

        // build addr2line command
        std::string cmd = "addr2line -e ";
        cmd += exec_path;
        cmd += " -f -C"; // -f for function names, -C for demangling

        for (int i = 0; i < frames; ++i) {
            char addr_str[32];
            sprintf(addr_str, " %p", callstack[i]);
            cmd += addr_str;
        }

        fprintf(stderr, "Assertion failed. Stack trace:\n");
        FILE* pipe = popen(cmd.c_str(), "r");
        if (!pipe) {
            fprintf(stderr, "Failed to run addr2line. Falling back to backtrace_symbols.\n");
            char** strs = backtrace_symbols(callstack, frames);
            for (int i = 0; i < frames; ++i) {
                fprintf(stderr, "%s\n", strs[i]);
            }
            free(strs);
        } else {
            char buffer[512];
            while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
                fprintf(stderr, "%s", buffer);
            }
            pclose(pipe);
        }

        if (!error_msg.empty()) {
            fprintf(stderr, "\nError: %s\n", error_msg.c_str());
        }
        exit(1);
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
#include "/home/tsutaj/Documents/compro/cpp_library/marathon/rand_xorshift.cpp"
Rand rnd(35023503980LL);
Timer timer;
using Answer = vector<int>; // TODO

enum Dir { U, R, D, L };
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void input() {

}

void output(const Answer& answer, bool is_final = false) {

}

void solve() {
    // auto ans = get_answer();
    // output(ans, true);
}

int main() {
    timer.setStart();
    input();
    solve();
    fprintf(stderr, "end time = %.3f\n", timer.getTime());
    return 0;
}
