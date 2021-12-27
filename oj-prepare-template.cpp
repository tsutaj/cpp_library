<%!
    import json
    import os
    import platform
    import shutil
    from logging import getLogger

    import onlinejudge_template.generator.cplusplus as cplusplus
    import onlinejudge_template.generator.topcoder as topcoder
    import onlinejudge_template.generator.about as about
    import onlinejudge_template.generator.hook as hook
%>\
<%
    data['config']['scanner'] = 'scanf'
    data['config']['printer'] = 'printf'

    logger = getLogger(__name__)
    # if not shutil.which("clang-format"):
    #     logger.warning("clang-format is not installed. If you want to generate well-formatted code, please install it. If you use Ubuntu, you can run $ sudo apt install clang-format")
    # else:
    #     format_config = {
    #         "BasedOnStyle": "Google",
    #         "IndentWidth": 4,
    #         "ColumnLimit": 9999,
    #         "ForEachMacros": ["ALL"],
    #     }
    #     hook.register_filter_command(["clang-format", "--style", json.dumps(format_config)], data=data)
%>\
// #define _GLIBCXX_DEBUG // for STL debug (optional)
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <fstream>
#include <functional>
#include <bitset>

using namespace std;
using ll = long long int;
using int64 = long long int;

#define ALL(v) (v).begin(), (v).end()
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const int INF = 1LL << 29;
const ll LONGINF = 1LL << 60;
const ll MOD_1000000007 = 1000000007LL;
const ll MOD_998244353 = 998244353LL;

// generated by ${about.title} ${about.version} (${about.url})
${cplusplus.declare_constants(data)}
% if topcoder.is_topcoder(data):
<% solve_function = topcoder.class_name(data) + "()." + topcoder.method_name(data) %>\
class ${topcoder.class_name(data)} {
public:

};
% else:
int main() {

    return 0;
}
% endif