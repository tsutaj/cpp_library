#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

// Mo のアルゴリズム (以下の条件を満たすときにクエリを高速に処理可能)
// ・オフラインクエリ
// ・クエリの対象となる数列が不変
// ・区間の伸縮にかかる計算量が小さい
struct Mo {
    enum DIRECTION {
        LEFT = 1,
        RIGHT = 2
    };

    int bucket, nl, nr, ptr;
    vector<int> left, right, query_idx;
    vector<bool> state;

    Mo(int N) : bucket(sqrt(N) + 1), nl(0), nr(0), ptr(0), state(N) {
        left = right = vector<int>();
    }

    // 区間 [l, r) を追加
    void insert(int l, int r) {
        left.push_back(l);
        right.push_back(r);
    }

    // ソートする (バケットごとに、バケット同じなら右端小さい順)
    void build() {
        query_idx = vector<int>(left.size());
        iota(query_idx.begin(), query_idx.end(), 0);
        sort(query_idx.begin(), query_idx.end(), [&](int a, int b) {
                if(left[a] / bucket != left[b] / bucket) return left[a] < left[b];
                return right[a] < right[b];
            });
    }
    
    // クエリを一つすすめて、そのクエリ id を返す
    int proceed() {
        if(ptr == query_idx.size()) return -1;
        int id = query_idx[ptr];
        while(nl > left[id] ) operate(--nl, nr, LEFT);
        while(nr < right[id]) operate(nl, nr++, RIGHT);
        while(nl < left[id] ) operate(nl++, nr, LEFT);
        while(nr > right[id]) operate(nl, --nr, RIGHT);
        return query_idx[ptr++];
    }

    // [l, r)
    void operate(int l, int r, DIRECTION dir) {
        int idx = (dir == LEFT ? l : r);
        state[idx].flip();
        if(state[idx]) add(l, r, dir);
        else del(l, r, dir);
    }

    // [l, r)
    void add(int l, int r, DIRECTION dir);
    void del(int l, int r, DIRECTION dir);
};

/*
int A[200010], cnt[1000010];
long long int res = 0;
void Mo::add(int idx, Mo::DIRECTION dir) {
    long long int pre = cnt[ A[idx] ];
    long long int nxt = pre + 1;
    res -= pre * pre * A[idx];
    res += nxt * nxt * A[idx];
    cnt[ A[idx] ]++;
}

void Mo::del(int idx, Mo::DIRECTION dir) {
    long long int pre = cnt[ A[idx] ];
    long long int nxt = pre - 1;
    res -= pre * pre * A[idx];
    res += nxt * nxt * A[idx];
    cnt[ A[idx] ]--;
}

int main() {
    int N, Q; scanf("%d%d", &N, &Q);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }

    Mo mo(N);
    for(int i=0; i<Q; i++) {
        int l, r; scanf("%d%d", &l, &r);
        mo.insert(--l, r);
    }

    mo.build();
    vector<long long int> ans(Q);
    for(int i=0; i<Q; i++) {
        int idx = mo.proceed();
        // fprintf(stderr, "idx = %lld\n", idx);
        ans[idx] = res;
    }

    for(int i=0; i<Q; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}
*/
