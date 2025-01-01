#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0001"

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#include "../../../marathon/interval_heap.cpp"

int main() {
    IntervalHeap<int> heap;
    for(int i=0; i<10; i++) {
        int height; scanf("%d", &height);
        heap.push(-height);
    }

    for(int i=0; i<3; i++) {
        printf("%d\n", -heap.top_min());
        heap.pop_min();
    }
    return 0;
}
